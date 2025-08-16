/*
 * SausageCo Skills System
 * XP Gain Events
 */

// Class to handle XP gain events throughout gameplay
class SkillXPEvents
{
    // Reference to skills manager
    private static ref PluginSausageSkillsManager m_SkillsManager;
    
    // Initialize the XP events system
    static void Init()
    {
        Print("[SausageSkills] Initializing XP Events System");
        
        // Register event handlers
        RegisterCraftingEvents();
        RegisterBuildingEvents();
        RegisterMedicalEvents();
        RegisterHuntingEvents();
        RegisterFarmingEvents();
        RegisterFirearmEvents();
        RegisterMechanicEvents();
        RegisterLeatherEvents();
        RegisterCookingEvents();
    }
    
    // Get skills manager reference
    private static PluginSausageSkillsManager GetSkillsManager()
    {
        if (!m_SkillsManager)
        {
            m_SkillsManager = PluginSausageSkillsManager.Cast(GetPlugin(PluginSausageSkillsManager));
        }
        
        return m_SkillsManager;
    }
    
    // Register crafting-related events
    private static void RegisterCraftingEvents()
    {
        // Hook into the recipe system to award XP when crafting
        GetDayZGame().Event_OnRecipePerformed.Insert(OnRecipePerformed);
    }
    
    // Register building-related events
    private static void RegisterBuildingEvents()
    {
        // Hook into building actions
        GetDayZGame().Event_OnBuildPartPlaced.Insert(OnBuildPartPlaced);
        GetDayZGame().Event_OnDismantleFinished.Insert(OnDismantleFinished);
    }
    
    // Register medical-related events
    private static void RegisterMedicalEvents()
    {
        // Hook into medical actions
        GetDayZGame().Event_OnMedicalActionPerformed.Insert(OnMedicalActionPerformed);
    }
    
    // Register hunting-related events
    private static void RegisterHuntingEvents()
    {
        // Hook into hunting actions
        GetDayZGame().Event_OnEntityKilled.Insert(OnEntityKilled);
        GetDayZGame().Event_OnItemButchered.Insert(OnItemButchered);
    }
    
    // Register farming-related events
    private static void RegisterFarmingEvents()
    {
        // Hook into farming actions
        GetDayZGame().Event_OnPlantSeed.Insert(OnPlantSeed);
        GetDayZGame().Event_OnHarvestPlant.Insert(OnHarvestPlant);
    }
    
    // Register firearm-related events
    private static void RegisterFirearmEvents()
    {
        // Hook into firearm actions
        GetDayZGame().Event_OnWeaponFired.Insert(OnWeaponFired);
        GetDayZGame().Event_OnWeaponCleaned.Insert(OnWeaponCleaned);
    }
    
    // Register mechanic-related events
    private static void RegisterMechanicEvents()
    {
        // Hook into mechanic actions
        GetDayZGame().Event_OnVehicleRepaired.Insert(OnVehicleRepaired);
        GetDayZGame().Event_OnVehiclePartAttached.Insert(OnVehiclePartAttached);
    }
    
    // Register leather-related events
    private static void RegisterLeatherEvents()
    {
        // Hook into leather actions
        GetDayZGame().Event_OnItemTanned.Insert(OnItemTanned);
    }
    
    // Register cooking-related events
    private static void RegisterCookingEvents()
    {
        // Hook into cooking actions
        GetDayZGame().Event_OnItemCooked.Insert(OnItemCooked);
    }
    
    // Event handlers
    
    // Handle recipe crafting
    static void OnRecipePerformed(PlayerBase player, int recipeID, array<ItemBase> ingredients, array<ItemBase> results)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Determine which skill category this recipe belongs to
        string skillType = GetSkillTypeForRecipe(recipeID, ingredients, results);
        if (skillType != "")
        {
            // Award XP based on recipe complexity
            int xpAmount = GetXPForRecipe(recipeID, ingredients, results);
            
            // Add XP to player's skill
            PluginSausageSkillsManager skillsManager = GetSkillsManager();
            if (skillsManager)
            {
                skillsManager.AddSkillXP(player, skillType, xpAmount);
                Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained " + xpAmount + " XP in " + skillType + " from crafting");
            }
        }
    }
    
    // Handle building part placement
    static void OnBuildPartPlaced(PlayerBase player, string partName)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Building parts give Engineering XP
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            skillsManager.AddSkillXP(player, SkillTypes.ENGINEERING, 20);
            Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained 20 XP in Engineering from building");
        }
    }
    
    // Handle dismantling
    static void OnDismantleFinished(PlayerBase player, string partName)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Dismantling gives Engineering XP
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            skillsManager.AddSkillXP(player, SkillTypes.ENGINEERING, 10);
            Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained 10 XP in Engineering from dismantling");
        }
    }
    
    // Handle medical actions
    static void OnMedicalActionPerformed(PlayerBase player, PlayerBase target, string actionName)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Medical actions give Medic XP
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            int xpAmount = 15;
            
            // More XP for treating others than self
            if (player != target)
            {
                xpAmount = 25;
            }
            
            skillsManager.AddSkillXP(player, SkillTypes.MEDIC, xpAmount);
            Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained " + xpAmount + " XP in Medicine from medical action");
        }
    }
    
    // Handle entity killed (hunting)
    static void OnEntityKilled(EntityAI entity, EntityAI killer)
    {
        if (!GetGame().IsServer())
            return;
            
        // Check if killer is a player
        PlayerBase player = PlayerBase.Cast(killer);
        if (!player)
        {
            // Check if killed by a player's projectile
            if (killer && killer.IsInherited(Projectile))
            {
                Projectile projectile = Projectile.Cast(killer);
                if (projectile && projectile.GetOwnerPlayer())
                {
                    player = PlayerBase.Cast(projectile.GetOwnerPlayer());
                }
            }
        }
        
        if (player && entity.IsInherited(Animal))
        {
            // Killing animals gives Hunter XP
            PluginSausageSkillsManager skillsManager = GetSkillsManager();
            if (skillsManager)
            {
                // XP based on animal size
                int xpAmount = 15;
                
                // More XP for larger animals
                if (entity.IsInherited(DeerBase) || entity.IsInherited(WolfBase) || entity.IsInherited(BoarBase))
                {
                    xpAmount = 25;
                }
                else if (entity.IsInherited(BearBase))
                {
                    xpAmount = 50;
                }
                
                skillsManager.AddSkillXP(player, SkillTypes.HUNTER, xpAmount);
                Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained " + xpAmount + " XP in Hunting from killing animal");
                
                // Also give Firearm XP if using a gun
                if (player.GetHumanInventory().GetEntityInHands() && player.GetHumanInventory().GetEntityInHands().IsWeapon())
                {
                    skillsManager.AddSkillXP(player, SkillTypes.FIREARM, 10);
                    Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained 10 XP in Firearms from hunting");
                }
            }
        }
    }
    
    // Handle butchering
    static void OnItemButchered(PlayerBase player, EntityAI entity)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Butchering gives Hunter XP
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            skillsManager.AddSkillXP(player, SkillTypes.HUNTER, 20);
            Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained 20 XP in Hunting from butchering");
        }
    }
    
    // Handle planting seeds
    static void OnPlantSeed(PlayerBase player, ItemBase seed, ItemBase garden)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Planting gives Farming XP
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            skillsManager.AddSkillXP(player, SkillTypes.FARMING, 10);
            Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained 10 XP in Farming from planting");
        }
    }
    
    // Handle harvesting plants
    static void OnHarvestPlant(PlayerBase player, ItemBase plant)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Harvesting gives Farming XP
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            skillsManager.AddSkillXP(player, SkillTypes.FARMING, 15);
            Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained 15 XP in Farming from harvesting");
        }
    }
    
    // Handle weapon firing
    static void OnWeaponFired(PlayerBase player, Weapon_Base weapon)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Firing weapons gives Firearm XP (small amount per shot)
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            skillsManager.AddSkillXP(player, SkillTypes.FIREARM, 1);
            // No print to avoid spam
        }
    }
    
    // Handle weapon cleaning
    static void OnWeaponCleaned(PlayerBase player, Weapon_Base weapon)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Cleaning weapons gives Firearm XP
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            skillsManager.AddSkillXP(player, SkillTypes.FIREARM, 15);
            Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained 15 XP in Firearms from cleaning weapon");
        }
    }
    
    // Handle vehicle repair
    static void OnVehicleRepaired(PlayerBase player, Transport vehicle)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Repairing vehicles gives Mechanic XP
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            skillsManager.AddSkillXP(player, SkillTypes.MECHANIC, 25);
            Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained 25 XP in Mechanics from repairing vehicle");
        }
    }
    
    // Handle vehicle part attachment
    static void OnVehiclePartAttached(PlayerBase player, Transport vehicle, string partName)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Attaching vehicle parts gives Mechanic XP
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            skillsManager.AddSkillXP(player, SkillTypes.MECHANIC, 15);
            Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained 15 XP in Mechanics from attaching vehicle part");
        }
    }
    
    // Handle tanning
    static void OnItemTanned(PlayerBase player, ItemBase hide, ItemBase leather)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Tanning gives Leather XP
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            skillsManager.AddSkillXP(player, SkillTypes.LEATHER, 20);
            Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained 20 XP in Leatherworking from tanning");
        }
    }
    
    // Handle cooking
    static void OnItemCooked(PlayerBase player, ItemBase food)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        // Cooking gives Cook XP
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            skillsManager.AddSkillXP(player, SkillTypes.COOK, 15);
            Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained 15 XP in Cooking from cooking food");
        }
    }
    
    // Helper functions
    
    // Determine which skill type a recipe belongs to
    static string GetSkillTypeForRecipe(int recipeID, array<ItemBase> ingredients, array<ItemBase> results)
    {
        // Check results to determine skill type
        foreach (ItemBase result : results)
        {
            string resultType = result.GetType();
            
            // Engineering items
            if (resultType.Contains("Wooden") || resultType.Contains("Metal") || resultType.Contains("Shelter") || 
                resultType.Contains("Fence") || resultType.Contains("Workbench") || resultType.Contains("Furnace"))
            {
                return SkillTypes.ENGINEERING;
            }
            
            // Farming items
            if (resultType.Contains("Seed") || resultType.Contains("Fertilizer") || resultType.Contains("Compost") ||
                resultType.Contains("Plant") || resultType.Contains("Garden"))
            {
                return SkillTypes.FARMING;
            }
            
            // Firearm items
            if (resultType.Contains("Ammo") || resultType.Contains("Magazine") || resultType.Contains("Weapon") ||
                resultType.Contains("Gun") || resultType.Contains("Pistol") || resultType.Contains("Rifle"))
            {
                return SkillTypes.FIREARM;
            }
            
            // Leather items
            if (resultType.Contains("Leather") || resultType.Contains("Hide") || resultType.Contains("Pelt") ||
                resultType.Contains("Tanned"))
            {
                return SkillTypes.LEATHER;
            }
            
            // Mechanic items
            if (resultType.Contains("Engine") || resultType.Contains("Wheel") || resultType.Contains("Battery") ||
                resultType.Contains("Spark") || resultType.Contains("Vehicle") || resultType.Contains("Car"))
            {
                return SkillTypes.MECHANIC;
            }
            
            // Medic items
            if (resultType.Contains("Bandage") || resultType.Contains("Medical") || resultType.Contains("Medicine") ||
                resultType.Contains("First") || resultType.Contains("Health") || resultType.Contains("Blood"))
            {
                return SkillTypes.MEDIC;
            }
            
            // Hunter items
            if (resultType.Contains("Trap") || resultType.Contains("Snare") || resultType.Contains("Bait") ||
                resultType.Contains("Arrow") || resultType.Contains("Bow") || resultType.Contains("Hunt"))
            {
                return SkillTypes.HUNTER;
            }
            
            // Cook items
            if (resultType.Contains("Food") || resultType.Contains("Meal") || resultType.Contains("Stew") ||
                resultType.Contains("Cooked") || resultType.Contains("Baked") || resultType.Contains("Preserved"))
            {
                return SkillTypes.COOK;
            }
        }
        
        // Default to empty string if no match found
        return "";
    }
    
    // Determine XP amount for a recipe
    static int GetXPForRecipe(int recipeID, array<ItemBase> ingredients, array<ItemBase> results)
    {
        // Base XP amount
        int xpAmount = 10;
        
        // More ingredients = more XP
        xpAmount += ingredients.Count() * 2;
        
        // More results = more XP
        xpAmount += results.Count() * 3;
        
        // Cap XP amount
        if (xpAmount > 50)
        {
            xpAmount = 50;
        }
        
        return xpAmount;
    }
}