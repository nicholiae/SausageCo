

/**
 * SausageCo Skills System
 * RPC Handlers - Updated Version with New Notification System
 */

class SausageSkillsRPC
{
    // Server-side RPC handlers
    static void RegisterServerRPCs()
    {
        // Use GetGame().GetRPCManager() to avoid syntax errors
        // We need to use "this" as the instance for RPC handlers
        ref SausageSkillsRPC rpcInstance = new SausageSkillsRPC();
        GetGame().GetRPCManager().AddRPC("SausageSkills", "RequestSkillsData", rpcInstance, SingleplayerExecutionType.Server);
        GetGame().GetRPCManager().AddRPC("SausageSkills", "CraftRecipe", rpcInstance, SingleplayerExecutionType.Server);
    }
    
    // Client-side RPC handlers
    static void RegisterClientRPCs()
    {
        // Use GetGame().GetRPCManager() to avoid syntax errors
        // We need to use "this" as the instance for RPC handlers
        ref SausageSkillsRPC rpcInstance = new SausageSkillsRPC();
        GetGame().GetRPCManager().AddRPC("SausageSkills", "SyncPlayerSkills", rpcInstance, SingleplayerExecutionType.Client);
        GetGame().GetRPCManager().AddRPC("SausageSkills", "UpdateSkill", rpcInstance, SingleplayerExecutionType.Client);
        GetGame().GetRPCManager().AddRPC("SausageSkills", "DisplayMessage", rpcInstance, SingleplayerExecutionType.Client);
        
        // Add direct registration for the OPEN_SKILLBOOK_MENU RPC
        Print("[SausageCo] Registering OPEN_SKILLBOOK_MENU RPC");
        GetGame().GetRPCManager().AddRPC("SausageSkills", "OPEN_SKILLBOOK_MENU", rpcInstance, SingleplayerExecutionType.Client);
    }
    
    // Server RPC Handlers
    
    // Handle request for skills data
    void RequestSkillsData(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type == CallType.Server && sender)
        {
            // Find the player
            PlayerBase player = PlayerBase.Cast(GetPlayerByIdentity(sender));
            if (player)
            {
                // Get skills manager
                PluginSausageSkillsManager skillsManager = PluginSausageSkillsManager.Cast(GetPlugin(PluginSausageSkillsManager));
                if (skillsManager)
                {
                    // Sync skills to client
                    skillsManager.SyncSkillsToClient(player);
                }
            }
        }
    }
    
    // Handle recipe crafting request
    void CraftRecipe(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param2<string, string> data;
        if (!ctx.Read(data))
            return;
            
        if (type == CallType.Server && sender)
        {
            string skillType = data.param1;
            string recipeName = data.param2;
            
            // Find the player
            PlayerBase player = PlayerBase.Cast(GetPlayerByIdentity(sender));
            if (player)
            {
                // Get skills manager
                PluginSausageSkillsManager skillsManager = PluginSausageSkillsManager.Cast(GetPlugin(PluginSausageSkillsManager));
                if (skillsManager)
                {
                    // Process crafting request
                    // This is handled in the skills manager
                }
            }
        }
    }
    
    // Client RPC Handlers
    
    // Handle sync of all player skills
    void SyncPlayerSkills(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param1<ref array<ref Param3<string, int, int>>> data;
        if (!ctx.Read(data))
            return;
            
        if (type == CallType.Client)
        {
            // Store skills data in player first
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            if (player)
            {
                player.UpdateSkillsData(data.param1);
            }
            
            // Update UI if menu is open - using a simpler approach
            // Instead of trying to call methods directly, we'll use the PlayerBase to update the UI
            // This avoids any direct references to the SausageSkillsMenu class
            if (player)
            {
                // The player class will handle updating the UI if the menu is open
                player.RefreshSkillsUI();
            }
        }
    }
    
    // Handle update of a single skill
    void UpdateSkill(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param3<string, int, int> data;
        if (!ctx.Read(data))
            return;
            
        if (type == CallType.Client)
        {
            string skillType = data.param1;
            int level = data.param2;
            int experience = data.param3;
            
            // Store skill data in player
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            if (player)
            {
                player.UpdateSkillData(skillType, level, experience);
                
                // The player class will handle updating the UI if the menu is open
                player.RefreshSkillsUI();
                
                // Show notification if level increased
                int oldLevel = player.GetSkillLevel(skillType);
                if (level > oldLevel)
                {
                    // Get skill display name
                    PluginSausageSkillsConfig config = PluginSausageSkillsConfig.Cast(GetPlugin(PluginSausageSkillsConfig));
                    if (config)
                    {
                        string skillDisplayName = config.GetSkillDisplayName(skillType);
                        
                        // Use our new notification system
                        // Check if skill book menu is open first
                        if (!SkillBookMenu.AreNotificationsSuppressed())
                        {
                            // Show a success notification with our new system
                            ShowNotification("Skill Level Up: " + skillDisplayName + " reached level " + level + "!", SausageNotificationType.SUCCESS);
                        }
                        else
                        {
                            // Just log it if notifications are suppressed
                            Print("[SausageCo] Skill Level Up (suppressed): " + skillDisplayName + " reached level " + level);
                        }
                    }
                }
            }
        }
    }
    
    // Handle display message
    void DisplayMessage(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param1<string> data;
        if (!ctx.Read(data))
            return;
            
        if (type == CallType.Client)
        {
            string message = data.param1;
            
            // Use our new notification system
            // Check if skill book menu is open first
            if (!SkillBookMenu.AreNotificationsSuppressed())
            {
                // Show an info notification with our new system
                ShowNotification(message, SausageNotificationType.INFO);
            }
            else
            {
                // Just log it if notifications are suppressed
                Print("[SausageCo] Message (suppressed): " + message);
            }
        }
    }
    
    // Handle OPEN_SKILLBOOK_MENU RPC
    void OPEN_SKILLBOOK_MENU(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Print("[SausageCo] OPEN_SKILLBOOK_MENU RPC handler called");
        
        if (type == CallType.Client)
        {
            // Try to read the parameters as Param4 first (new format)
            Param4<string, string, string, string> bookData4;
            if (ctx.Read(bookData4))
            {
                string bookSkillType = bookData4.param1;
                string bookTitle = bookData4.param2;
                string bookDescription = bookData4.param3;
                string skillBookType = bookData4.param4;
                
                Print("[SausageCo] Read Param4 data: " + bookSkillType + ", " + bookTitle + ", " + skillBookType);
                
                // Open the skill book menu
                PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
                if (player)
                {
                    player.OpenSkillBookMenu(bookSkillType, bookTitle, bookDescription, skillBookType);
                }
                return;
            }
            
            // If Param4 failed, try Param3 (old format)
            Param3<string, string, string> bookData3;
            if (ctx.Read(bookData3))
            {
                string bookSkillType = bookData3.param1;
                string bookTitle = bookData3.param2;
                string bookDescription = bookData3.param3;
                
                Print("[SausageCo] Read Param3 data: " + bookSkillType + ", " + bookTitle);
                
                // Open the skill book menu
                PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
                if (player)
                {
                    player.OpenSkillBookMenu(bookSkillType, bookTitle, bookDescription);
                }
            }
            else
            {
                Print("[SausageSkills] ERROR: Failed to read book data from RPC");
            }
        }
    }
    
    // Helper function to find player by identity
    static PlayerBase GetPlayerByIdentity(PlayerIdentity identity)
    {
        if (!identity)
            return null;
            
        int playerId = identity.GetPlayerId();
        
        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);
        
        foreach (Man man : players)
        {
            PlayerBase player = PlayerBase.Cast(man);
            if (player && player.GetIdentity() && player.GetIdentity().GetPlayerId() == playerId)
            {
                return player;
            }
        }
        
        return null;
    }
}
