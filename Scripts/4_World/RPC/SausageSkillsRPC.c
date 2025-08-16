
/**
 * SausageCo Skills System
 * RPC Handlers
 */

class SausageSkillsRPC
{
    // Server-side RPC handlers
    static void RegisterServerRPCs()
    {
        // Use the global GetRPCManager() function to avoid conflicts
        ::GetRPCManager().AddRPC("SausageSkills", "RequestSkillsData", RequestSkillsDataServer);
        ::GetRPCManager().AddRPC("SausageSkills", "CraftRecipe", CraftRecipeServer);
    }
    
    // Client-side RPC handlers
    static void RegisterClientRPCs()
    {
        // Use the global GetRPCManager() function to avoid conflicts
        ::GetRPCManager().AddRPC("SausageSkills", "SyncPlayerSkills", SyncPlayerSkillsClient);
        ::GetRPCManager().AddRPC("SausageSkills", "UpdateSkill", UpdateSkillClient);
        ::GetRPCManager().AddRPC("SausageSkills", "DisplayMessage", DisplayMessageClient);
    }
    
    // Server RPC Handlers
    
    // Handle request for skills data
    static void RequestSkillsDataServer(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
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
    static void CraftRecipeServer(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
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
    static void SyncPlayerSkillsClient(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param1<ref array<ref Param3<string, int, int>>> data;
        if (!ctx.Read(data))
            return;
            
        if (type == CallType.Client)
        {
            // Update skills in UI
            SausageSkillsMenu menu = SausageSkillsMenu.Cast(GetGame().GetUIManager().FindMenu(MENU_SAUSAGE_SKILLS));
            if (menu)
            {
                menu.UpdateAllSkills(data.param1);
            }
            
            // Store skills data in player
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            if (player)
            {
                player.UpdateSkillsData(data.param1);
            }
        }
    }
    
    // Handle update of a single skill
    static void UpdateSkillClient(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param3<string, int, int> data;
        if (!ctx.Read(data))
            return;
            
        if (type == CallType.Client)
        {
            string skillType = data.param1;
            int level = data.param2;
            int experience = data.param3;
            
            // Update skill in UI
            SausageSkillsMenu menu = SausageSkillsMenu.Cast(GetGame().GetUIManager().FindMenu(MENU_SAUSAGE_SKILLS));
            if (menu)
            {
                menu.UpdateSkillData(skillType, level, experience);
            }
            
            // Store skill data in player
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            if (player)
            {
                player.UpdateSkillData(skillType, level, experience);
            }
            
            // Show notification if level increased
            PlayerBase playerBase = PlayerBase.Cast(GetGame().GetPlayer());
            if (playerBase)
            {
                int oldLevel = playerBase.GetSkillLevel(skillType);
                if (level > oldLevel)
                {
                    // Get skill display name
                    PluginSausageSkillsConfig config = PluginSausageSkillsConfig.Cast(GetPlugin(PluginSausageSkillsConfig));
                    string skillDisplayName = config.GetSkillDisplayName(skillType);
                    
                    // Show level up notification
                    SausageSkillsNotification.AddNotification(SausageSkillsNotification.NOTIFICATION_PLAIN, 5, "Skill Level Up: " + skillDisplayName + " reached level " + level + "!");
                }
            }
        }
    }
    
    // Handle display message
    static void DisplayMessageClient(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param1<string> data;
        if (!ctx.Read(data))
            return;
            
        if (type == CallType.Client)
        {
            string message = data.param1;
            
            // Show notification
            SausageSkillsNotification.AddNotification(SausageSkillsNotification.NOTIFICATION_PLAIN, 5, message);
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

// Notification system for client messages - renamed to avoid conflicts
class SausageSkillsNotification
{
    // Constants instead of enum to avoid conflicts
    const static int NOTIFICATION_PLAIN = 0;
    const static int NOTIFICATION_SUCCESS = 1;
    const static int NOTIFICATION_WARNING = 2;
    const static int NOTIFICATION_ERROR = 3;
    
    static void AddNotification(int type, float duration, string message)
    {
        // In a real implementation, this would show a UI notification
        // For now, we'll just print to the screen
        Print("[SausageSkills] " + message);
        
        // TODO: Implement actual UI notifications
    }
}
