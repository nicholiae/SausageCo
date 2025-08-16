/**
 * SausageCo Skills System
 * XP Gain Events - Recipe-Based Approach
 */

// Class to handle XP gain events through recipes
class SkillXPEvents
{
    // Reference to skills manager
    private static ref PluginSausageSkillsManager m_SkillsManager;
    
    // Initialize the XP events system
    static void Init()
    {
        Print("[SausageSkills] Initializing Recipe-Based XP System");
        
        // Get skills manager reference
        GetSkillsManager();
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
    
    // Award XP for crafting a recipe
    static void AwardRecipeXP(PlayerBase player, string recipeName, int xpAmount, string skillType)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        PluginSausageSkillsManager skillsManager = GetSkillsManager();
        if (skillsManager)
        {
            skillsManager.AddSkillXP(player, skillType, xpAmount);
            Print("[SausageSkills] Player " + player.GetIdentity().GetName() + " gained " + xpAmount + " XP in " + skillType + " from crafting " + recipeName);
        }
    }
    
    // Determine which skill type a recipe belongs to based on name
    static string GetSkillTypeForRecipeName(string recipeName)
    {
        // Engineering items
        if (recipeName.Contains("Wooden") || recipeName.Contains("Metal") || recipeName.Contains("Shelter") || recipeName.Contains("Fence") || recipeName.Contains("Workbench") || recipeName.Contains("Furnace"))
        {
            return SkillTypes.ENGINEERING;
        }
        
        // Farming items
        if (recipeName.Contains("Seed") || recipeName.Contains("Fertilizer") || recipeName.Contains("Compost") || recipeName.Contains("Plant") || recipeName.Contains("Garden"))
        {
            return SkillTypes.FARMING;
        }
        
        // Firearm items
        if (recipeName.Contains("Ammo") || recipeName.Contains("Magazine") || recipeName.Contains("Weapon") || recipeName.Contains("Gun") || recipeName.Contains("Pistol") || recipeName.Contains("Rifle"))
        {
            return SkillTypes.FIREARM;
        }
        
        // Leather items
        if (recipeName.Contains("Leather") || recipeName.Contains("Hide") || recipeName.Contains("Pelt") || recipeName.Contains("Tanned"))
        {
            return SkillTypes.LEATHER;
        }
        
        // Mechanic items
        if (recipeName.Contains("Engine") || recipeName.Contains("Wheel") || recipeName.Contains("Battery") || recipeName.Contains("Spark") || recipeName.Contains("Vehicle") || recipeName.Contains("Car"))
        {
            return SkillTypes.MECHANIC;
        }
        
        // Medic items
        if (recipeName.Contains("Bandage") || recipeName.Contains("Medical") || recipeName.Contains("Medicine") || recipeName.Contains("First") || recipeName.Contains("Health") || recipeName.Contains("Blood"))
        {
            return SkillTypes.MEDIC;
        }
        
        // Hunter items
        if (recipeName.Contains("Trap") || recipeName.Contains("Snare") || recipeName.Contains("Bait") || recipeName.Contains("Arrow") || recipeName.Contains("Bow") || recipeName.Contains("Hunt"))
        {
            return SkillTypes.HUNTER;
        }
        
        // Cook items
        if (recipeName.Contains("Food") || recipeName.Contains("Meal") || recipeName.Contains("Stew") || recipeName.Contains("Cooked") || recipeName.Contains("Baked") || recipeName.Contains("Preserved"))
        {
            return SkillTypes.COOK;
        }
        
        // Default to empty string if no match found
        return "";
    }
    
    // Calculate XP amount based on recipe complexity
    static int CalculateRecipeXP(array<ref Param2<string, int>> ingredients, array<ref Param2<string, int>> results)
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