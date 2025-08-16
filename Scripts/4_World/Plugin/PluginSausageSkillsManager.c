/**
 * SausageCo Skills System
 * Skills Manager Plugin
 */

class PluginSausageSkillsManager extends PluginBase
{
    // Constants
    private const static string SKILLS_FOLDER = "$profile:Sausage\\Skills\\";
    private const static string PLAYERS_FOLDER = "$profile:Sausage\\Skills\\players\\";
    
    // Player skills data cache
    private ref map<string, ref PlayerSkillsData> m_PlayerSkillsCache;
    
    // Config reference
    private ref PluginSausageSkillsConfig m_Config;
    
    // Recipe manager reference
    private ref SausageSkillsRecipeManager m_RecipeManager;
    
    override void OnInit()
    {
        Print("[SausageSkills] PluginSausageSkillsManager::OnInit()");
        
        // Initialize folders
        CheckFolders();
        
        // Initialize cache
        m_PlayerSkillsCache = new map<string, ref PlayerSkillsData>();
        
        // Get config
        m_Config = PluginSausageSkillsConfig.Cast(GetPlugin(PluginSausageSkillsConfig));
        
        // Initialize recipe manager
        m_RecipeManager = new SausageSkillsRecipeManager();
        m_RecipeManager.Init();
        
        // Auto-save timer (every 5 minutes)
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(AutoSavePlayerData, 300000, true);
        
        // Register RPC handlers
        if (GetGame().IsServer())
        {
            GetRPCManager().AddRPC("SausageSkills", "RequestSkillsData", this, SingleplayerExecutionType.Server);
            GetRPCManager().AddRPC("SausageSkills", "CraftRecipe", this, SingleplayerExecutionType.Server);
        }
    }
    
    void OnPlayerConnect(PlayerBase player, PlayerIdentity identity)
    {
        if (!player || !identity)
            return;
            
        string steamId = identity.GetPlainId();
        if (steamId != "")
        {
            // Load or create player skills data
            LoadPlayerSkills(steamId, player);
            
            // Send skills data to client
            SyncSkillsToClient(player);
        }
    }
    
    void OnPlayerDisconnect(PlayerBase player)
    {
        if (!player)
            return;
            
        PlayerIdentity identity = player.GetIdentity();
        if (identity)
        {
            string steamId = identity.GetPlainId();
            if (steamId != "")
            {
                // Save player skills data
                SavePlayerSkills(steamId);
                
                // Remove from cache
                m_PlayerSkillsCache.Remove(steamId);
            }
        }
    }
    
    void LoadPlayerSkills(string steamId, PlayerBase player)
    {
        string filePath = PLAYERS_FOLDER + steamId + ".json";
        
        // Check if player data exists
        if (FileExist(filePath))
        {
            // Load existing data
            ref PlayerSkillsData skillsData = new PlayerSkillsData();
            JsonFileLoader<PlayerSkillsData>.JsonLoadFile(filePath, skillsData);
            
            // Update player name if changed
            if (player.GetIdentity())
            {
                skillsData.playerInfo.playerName = player.GetIdentity().GetName();
            }
            
            // Update last login time
            skillsData.playerInfo.lastUpdate = GetDateTimeStr();
            
            // Cache data
            m_PlayerSkillsCache.Set(steamId, skillsData);
            
            Print("[SausageSkills] Loaded skills data for player: " + steamId);
        }
        else
        {
            // Create new player data
            ref PlayerSkillsData skillsData = CreateNewPlayerData(steamId, player);
            m_PlayerSkillsCache.Set(steamId, skillsData);
            
            // Save immediately
            SavePlayerSkills(steamId);
            
            Print("[SausageSkills] Created new skills data for player: " + steamId);
        }
    }
    
    ref PlayerSkillsData CreateNewPlayerData(string steamId, PlayerBase player)
    {
        ref PlayerSkillsData skillsData = new PlayerSkillsData();
        
        // Set player info
        skillsData.playerInfo = new PlayerInfo(steamId);
        if (player.GetIdentity())
        {
            skillsData.playerInfo.playerName = player.GetIdentity().GetName();
        }
        skillsData.playerInfo.lastUpdate = GetDateTimeStr();
        
        // Initialize skills with default values
        skillsData.skills = new map<string, ref SkillData>();
        
        // Add all skill types from config
        array<string> skillTypes = SkillTypes.GetAllTypes();
        foreach (string skillType : skillTypes)
        {
            ref SkillData newSkill = new SkillData();
            newSkill.level = 0;
            newSkill.experience = 0;
            newSkill.nextLevelAt = m_Config.GetXpForLevel(skillType, 1);
            newSkill.unlockedRecipes = new array<string>();
            
            skillsData.skills.Set(skillType, newSkill);
        }
        
        return skillsData;
    }
    
    void SavePlayerSkills(string steamId)
    {
        ref PlayerSkillsData skillsData = m_PlayerSkillsCache.Get(steamId);
        if (skillsData)
        {
            // Update timestamp
            skillsData.playerInfo.lastUpdate = GetDateTimeStr();
            
            // Save to file
            string filePath = PLAYERS_FOLDER + steamId + ".json";
            JsonFileLoader<PlayerSkillsData>.JsonSaveFile(filePath, skillsData);
            
            Print("[SausageSkills] Saved skills data for player: " + steamId);
        }
    }
    
    void AutoSavePlayerData()
    {
        Print("[SausageSkills] Auto-saving player skills data...");
        
        foreach (string steamId, PlayerSkillsData data : m_PlayerSkillsCache)
        {
            SavePlayerSkills(steamId);
        }
    }
    
    void SyncSkillsToClient(PlayerBase player)
    {
        if (!player || !player.GetIdentity())
            return;
            
        string steamId = player.GetIdentity().GetPlainId();
        ref PlayerSkillsData skillsData = m_PlayerSkillsCache.Get(steamId);
        
        if (skillsData)
        {
            // Convert skills data to serializable format
            ref array<ref Param3<string, int, int>> skillsArray = new array<ref Param3<string, int, int>>();
            
            foreach (string skillType, SkillData data : skillsData.skills)
            {
                skillsArray.Insert(new Param3<string, int, int>(skillType, data.level, data.experience));
            }
            
            // Send to client
            GetRPCManager().SendRPC("SausageSkills", "SyncPlayerSkills", new Param1<ref array<ref Param3<string, int, int>>>(skillsArray), true, player.GetIdentity());
            
            Print("[SausageSkills] Sent skills data to client: " + steamId);
        }
    }
    
    // Add experience to a player's skill
    bool AddSkillXP(PlayerBase player, string skillType, int amount)
    {
        if (!player || !player.GetIdentity())
            return false;
            
        string steamId = player.GetIdentity().GetPlainId();
        ref PlayerSkillsData skillsData = m_PlayerSkillsCache.Get(steamId);
        
        if (skillsData && skillsData.skills.Contains(skillType))
        {
            ref SkillData skill = skillsData.skills.Get(skillType);
            
            // Add experience
            skill.experience += amount;
            
            // Check for level up
            bool leveledUp = CheckLevelUp(steamId, skillType);
            
            // Sync to client
            SyncSkillToClient(player, skillType, skill.level, skill.experience);
            
            return true;
        }
        
        return false;
    }
    
    bool CheckLevelUp(string steamId, string skillType)
    {
        ref PlayerSkillsData skillsData = m_PlayerSkillsCache.Get(steamId);
        if (!skillsData || !skillsData.skills.Contains(skillType))
            return false;
            
        ref SkillData skill = skillsData.skills.Get(skillType);
        
        // Check if we have enough XP for next level
        if (skill.experience >= skill.nextLevelAt)
        {
            // Level up
            skill.level++;
            
            // Set new threshold for next level
            skill.nextLevelAt = m_Config.GetXpForLevel(skillType, skill.level + 1);
            
            // Update unlocked recipes
            UpdateUnlockedRecipes(steamId, skillType, skill.level);
            
            Print("[SausageSkills] Player " + steamId + " leveled up " + skillType + " to level " + skill.level);
            
            return true;
        }
        
        return false;
    }
    
    void UpdateUnlockedRecipes(string steamId, string skillType, int level)
    {
        ref PlayerSkillsData skillsData = m_PlayerSkillsCache.Get(steamId);
        if (!skillsData || !skillsData.skills.Contains(skillType))
            return;
            
        ref SkillData skill = skillsData.skills.Get(skillType);
        
        // Get recipes for this level
        array<string> newRecipes = m_Config.GetRecipesForLevel(skillType, level);
        
        // Add new recipes
        foreach (string recipe : newRecipes)
        {
            if (skill.unlockedRecipes.Find(recipe) == -1)
            {
                skill.unlockedRecipes.Insert(recipe);
            }
        }
    }
    
    void SyncSkillToClient(PlayerBase player, string skillType, int level, int experience)
    {
        if (!player || !player.GetIdentity())
            return;
            
        // Send updated skill to client
        GetRPCManager().SendRPC("SausageSkills", "UpdateSkill", new Param3<string, int, int>(skillType, level, experience), true, player.GetIdentity());
    }
    
    // Check if player has required skill level
    bool HasSkillLevel(string steamId, string skillType, int requiredLevel)
    {
        ref PlayerSkillsData skillsData = m_PlayerSkillsCache.Get(steamId);
        if (skillsData && skillsData.skills.Contains(skillType))
        {
            return skillsData.skills.Get(skillType).level >= requiredLevel;
        }
        
        return false;
    }
    
    // RPC handler for requesting skills data
    void RequestSkillsData(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type == CallType.Server && sender)
        {
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            if (player)
            {
                SyncSkillsToClient(player);
            }
        }
    }
    
    // RPC handler for crafting a recipe
    void CraftRecipe(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param2<string, string> data;
        if (!ctx.Read(data))
            return;
            
        if (type == CallType.Server && sender)
        {
            string skillType = data.param1;
            string recipeName = data.param2;
            
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            if (player)
            {
                // Check if player has the recipe unlocked
                string steamId = sender.GetPlainId();
                ref PlayerSkillsData skillsData = m_PlayerSkillsCache.Get(steamId);
                
                if (skillsData && skillsData.HasUnlockedRecipe(skillType, recipeName))
                {
                    // Get recipe data
                    ref SkillRecipeData recipe = m_RecipeManager.GetRecipe(recipeName);
                    if (recipe)
                    {
                        // Check if player has required ingredients
                        if (HasRequiredIngredients(player, recipe))
                        {
                            // Craft the recipe
                            CraftRecipeForPlayer(player, recipe);
                            
                            // Award XP for crafting using the recipe manager
                            m_RecipeManager.AwardRecipeXP(player, recipeName);
                        }
                        else
                        {
                            // Send message to player that they don't have required ingredients
                            SendMessageToClient(player, "You don't have the required ingredients for this recipe.");
                        }
                    }
                }
                else
                {
                    // Send message to player that they don't have this recipe unlocked
                    SendMessageToClient(player, "You haven't unlocked this recipe yet.");
                }
            }
        }
    }
    
    bool HasRequiredIngredients(PlayerBase player, ref SkillRecipeData recipe)
    {
        // Check if player has all required ingredients
        foreach (ref Param2<string, int> ingredient : recipe.ingredients)
        {
            string itemClassName = ingredient.param1;
            int requiredQuantity = ingredient.param2;
            
            // Count how many of this item the player has
            int foundQuantity = CountItemsInInventory(player, itemClassName);
            
            if (foundQuantity < requiredQuantity)
            {
                return false;
            }
        }
        
        return true;
    }
    
    int CountItemsInInventory(PlayerBase player, string itemClassName)
    {
        int count = 0;
        
        array<EntityAI> items = new array<EntityAI>();
        player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, items);
        
        foreach (EntityAI item : items)
        {
            if (item.GetType() == itemClassName)
            {
                ItemBase itemBase = ItemBase.Cast(item);
                if (itemBase)
                {
                    if (itemBase.HasQuantity())
                    {
                        count += itemBase.GetQuantity();
                    }
                    else
                    {
                        count++;
                    }
                }
                else
                {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    void CraftRecipeForPlayer(PlayerBase player, ref SkillRecipeData recipe)
    {
        // Remove ingredients
        foreach (ref Param2<string, int> ingredient : recipe.ingredients)
        {
            string itemClassName = ingredient.param1;
            int requiredQuantity = ingredient.param2;
            
            RemoveItemsFromInventory(player, itemClassName, requiredQuantity);
        }
        
        // Add results
        foreach (ref Param2<string, int> result : recipe.results)
        {
            string itemClassName = result.param1;
            int quantity = result.param2;
            
            CreateItemInInventory(player, itemClassName, quantity);
        }
        
        // Send success message
        SendMessageToClient(player, "Successfully crafted " + recipe.displayName);
    }
    
    void RemoveItemsFromInventory(PlayerBase player, string itemClassName, int quantity)
    {
        int remainingToRemove = quantity;
        
        array<EntityAI> items = new array<EntityAI>();
        player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, items);
        
        for (int i = 0; i < items.Count(); i++)
        {
            EntityAI item = items[i];
            
            if (item.GetType() == itemClassName && remainingToRemove > 0)
            {
                ItemBase itemBase = ItemBase.Cast(item);
                if (itemBase)
                {
                    if (itemBase.HasQuantity())
                    {
                        int itemQuantity = itemBase.GetQuantity();
                        
                        if (itemQuantity <= remainingToRemove)
                        {
                            // Remove entire item
                            remainingToRemove -= itemQuantity;
                            GetGame().ObjectDelete(item);
                        }
                        else
                        {
                            // Remove partial quantity
                            itemBase.AddQuantity(-remainingToRemove);
                            remainingToRemove = 0;
                        }
                    }
                    else
                    {
                        // Remove entire item
                        remainingToRemove--;
                        GetGame().ObjectDelete(item);
                    }
                }
                else
                {
                    // Remove entire item
                    remainingToRemove--;
                    GetGame().ObjectDelete(item);
                }
            }
            
            if (remainingToRemove <= 0)
                break;
        }
    }
    
    void CreateItemInInventory(PlayerBase player, string itemClassName, int quantity)
    {
        ItemBase item = ItemBase.Cast(player.GetInventory().CreateInInventory(itemClassName));
        if (item)
        {
            if (item.HasQuantity())
            {
                item.SetQuantity(quantity);
            }
        }
    }
    
    void SendMessageToClient(PlayerBase player, string message)
    {
        if (player && player.GetIdentity())
        {
            GetRPCManager().SendRPC("SausageSkills", "DisplayMessage", new Param1<string>(message), true, player.GetIdentity());
        }
    }
    
    void CheckFolders()
    {
        if (!FileExist(SKILLS_FOLDER))
        {
            MakeDirectory(SKILLS_FOLDER);
        }
        
        if (!FileExist(PLAYERS_FOLDER))
        {
            MakeDirectory(PLAYERS_FOLDER);
        }
    }
    
    string GetDateTimeStr()
    {
        int year, month, day, hour, minute, second;
        GetYearMonthDay(year, month, day);
        GetHourMinuteSecond(hour, minute, second);
        
        string dateTime = year.ToString() + "-";
        dateTime += month.ToString().PadLeft(2, "0") + "-";
        dateTime += day.ToString().PadLeft(2, "0") + "T";
        dateTime += hour.ToString().PadLeft(2, "0") + ":";
        dateTime += minute.ToString().PadLeft(2, "0") + ":";
        dateTime += second.ToString().PadLeft(2, "0") + "Z";
        
        return dateTime;
    }
}