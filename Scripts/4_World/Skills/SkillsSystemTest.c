/**
 * SausageCo Skills System
 * Testing Script
 */

// Class for testing the skills system
class SkillsSystemTest
{
    // Test adding XP to a player's skill
    static void TestAddXP(PlayerBase player, string skillType, int amount)
    {
        if (!player)
            return;
            
        Print("[SausageSkills] Testing AddXP: " + skillType + " +" + amount + " XP");
        
        // Get skills manager
        PluginSausageSkillsManager skillsManager = PluginSausageSkillsManager.Cast(GetPlugin(PluginSausageSkillsManager));
        if (skillsManager)
        {
            // Add XP to player's skill
            skillsManager.AddSkillXP(player, skillType, amount);
            
            // Log result
            Print("[SausageSkills] XP added successfully");
        }
        else
        {
            Print("[SausageSkills] ERROR: Skills manager not found");
        }
    }
    
    // Test checking a player's skill level
    static void TestCheckSkillLevel(PlayerBase player, string skillType, int requiredLevel)
    {
        if (!player)
            return;
            
        Print("[SausageSkills] Testing CheckSkillLevel: " + skillType + " >= " + requiredLevel);
        
        // Check if player has required skill level
        bool hasLevel = player.HasSkillLevel(skillType, requiredLevel);
        
        // Log result
        Print("[SausageSkills] Has required level: " + hasLevel);
    }
    
    // Test crafting a recipe
    static void TestCraftRecipe(PlayerBase player, string skillType, string recipeName)
    {
        if (!player)
            return;
            
        Print("[SausageSkills] Testing CraftRecipe: " + skillType + " - " + recipeName);
        
        // Send craft request to server
        GetRPCManager().SendRPC("SausageSkills", "CraftRecipe", new Param2<string, string>(skillType, recipeName), true);
        
        // Log result
        Print("[SausageSkills] Craft request sent");
    }
    
    // Test opening the skills menu
    static void TestOpenSkillsMenu(PlayerBase player)
    {
        if (!player)
            return;
            
        Print("[SausageSkills] Testing OpenSkillsMenu");
        
        // Open skills menu
        player.OpenSkillsMenu();
        
        // Log result
        Print("[SausageSkills] Skills menu opened");
    }
    
    // Test recipe-based XP gain
    static void TestRecipeXPGain(PlayerBase player, string recipeName)
    {
        if (!player)
            return;
            
        Print("[SausageSkills] Testing Recipe XP Gain for: " + recipeName);
        
        // Get recipe manager
        ref SausageSkillsRecipeManager recipeManager = new SausageSkillsRecipeManager();
        recipeManager.Init();
        
        // Get recipe data
        ref SkillRecipeData recipe = recipeManager.GetRecipe(recipeName);
        if (!recipe)
        {
            Print("[SausageSkills] ERROR: Recipe not found: " + recipeName);
            return;
        }
        
        // Get skills manager
        PluginSausageSkillsManager skillsManager = PluginSausageSkillsManager.Cast(GetPlugin(PluginSausageSkillsManager));
        if (!skillsManager)
        {
            Print("[SausageSkills] ERROR: Skills manager not found");
            return;
        }
        
        // Create required ingredients in player's inventory
        Print("[SausageSkills] Creating ingredients for recipe...");
        foreach (ref Param2<string, int> ingredient : recipe.ingredients)
        {
            string itemClassName = ingredient.param1;
            int quantity = ingredient.param2;
            
            for (int i = 0; i < quantity; i++)
            {
                ItemBase item = ItemBase.Cast(player.GetInventory().CreateInInventory(itemClassName));
                if (!item)
                {
                    Print("[SausageSkills] ERROR: Failed to create ingredient: " + itemClassName);
                }
            }
        }
        
        // Craft the recipe
        Print("[SausageSkills] Crafting recipe...");
        TestCraftRecipe(player, recipe.skillType, recipeName);
        
        // Log XP reward
        Print("[SausageSkills] Recipe XP reward: " + recipe.xpReward);
    }
    
    // Test level-up functionality
    static void TestLevelUp(PlayerBase player, string skillType, int targetLevel)
    {
        if (!player)
            return;
            
        Print("[SausageSkills] Testing Level Up for skill: " + skillType + " to level " + targetLevel);
        
        // Get skills manager
        PluginSausageSkillsManager skillsManager = PluginSausageSkillsManager.Cast(GetPlugin(PluginSausageSkillsManager));
        if (!skillsManager)
        {
            Print("[SausageSkills] ERROR: Skills manager not found");
            return;
        }
        
        // Get config
        PluginSausageSkillsConfig config = PluginSausageSkillsConfig.Cast(GetPlugin(PluginSausageSkillsConfig));
        if (!config)
        {
            Print("[SausageSkills] ERROR: Skills config not found");
            return;
        }
        
        // Calculate XP needed to reach target level
        int xpNeeded = 10000 * targetLevel; // Approximate XP needed
        
        Print("[SausageSkills] Adding " + xpNeeded + " XP to reach level " + targetLevel);
        
        // Add XP
        TestAddXP(player, skillType, xpNeeded);
        
        // Check if level up occurred
        TestCheckSkillLevel(player, skillType, targetLevel);
        
        // Check unlocked recipes
        Print("[SausageSkills] Checking unlocked recipes for level " + targetLevel);
        array<string> recipes = config.GetRecipesForLevel(skillType, targetLevel);
        
        foreach (string recipe : recipes)
        {
            Print("[SausageSkills] Recipe unlocked at level " + targetLevel + ": " + recipe);
        }
    }
    
    // Test all recipes for a skill type
    static void TestAllRecipesForSkill(PlayerBase player, string skillType)
    {
        if (!player)
            return;
            
        Print("[SausageSkills] Testing All Recipes for skill: " + skillType);
        
        // Get recipe manager
        ref SausageSkillsRecipeManager recipeManager = new SausageSkillsRecipeManager();
        recipeManager.Init();
        
        // Get all recipes for this skill
        array<ref SkillRecipeData> recipes = recipeManager.GetRecipesForSkill(skillType);
        
        Print("[SausageSkills] Found " + recipes.Count() + " recipes for " + skillType);
        
        // Test each recipe
        foreach (SkillRecipeData recipe : recipes)
        {
            Print("[SausageSkills] Recipe: " + recipe.displayName);
            Print("[SausageSkills] - Required Level: " + recipe.requiredLevel);
            Print("[SausageSkills] - XP Reward: " + recipe.xpReward);
            
            // Ensure player has required level
            TestAddXP(player, skillType, 10000 * recipe.requiredLevel);
            
            // Test crafting the recipe
            TestRecipeXPGain(player, recipe.recipeName);
        }
    }
    
    // Run all tests
    static void RunAllTests(PlayerBase player)
    {
        if (!player)
            return;
            
        Print("[SausageSkills] Running all tests");
        
        // Test adding XP to each skill type
        TestAddXP(player, SkillTypes.ENGINEERING, 100);
        TestAddXP(player, SkillTypes.FARMING, 100);
        TestAddXP(player, SkillTypes.FIREARM, 100);
        TestAddXP(player, SkillTypes.LEATHER, 100);
        TestAddXP(player, SkillTypes.MECHANIC, 100);
        TestAddXP(player, SkillTypes.MEDIC, 100);
        TestAddXP(player, SkillTypes.HUNTER, 100);
        TestAddXP(player, SkillTypes.COOK, 100);
        
        // Test checking skill levels
        TestCheckSkillLevel(player, SkillTypes.ENGINEERING, 1);
        
        // Test crafting a recipe
        TestCraftRecipe(player, SkillTypes.ENGINEERING, "WoodenPlank");
        
        // Test recipe XP gain
        TestRecipeXPGain(player, "WoodenPlank");
        
        // Test level up
        TestLevelUp(player, SkillTypes.ENGINEERING, 2);
        
        // Test opening the skills menu
        TestOpenSkillsMenu(player);
        
        Print("[SausageSkills] All tests completed");
    }
    
    // Process admin command
    static bool ProcessAdminCommand(PlayerBase player, array<string> args)
    {
        if (!player)
            return false;
            
        if (args.Count() == 0)
        {
            // Run all tests
            RunAllTests(player);
            return true;
        }
        
        string action = args[0];
        
        if (action == "addxp" && args.Count() >= 3)
        {
            // Test adding XP
            string skillType = args[1];
            int amount = args[2].ToInt();
            TestAddXP(player, skillType, amount);
            return true;
        }
        else if (action == "checklevel" && args.Count() >= 3)
        {
            // Test checking skill level
            string skillType = args[1];
            int requiredLevel = args[2].ToInt();
            TestCheckSkillLevel(player, skillType, requiredLevel);
            return true;
        }
        else if (action == "craft" && args.Count() >= 3)
        {
            // Test crafting a recipe
            string skillType = args[1];
            string recipeName = args[2];
            TestCraftRecipe(player, skillType, recipeName);
            return true;
        }
        else if (action == "openmenu")
        {
            // Test opening the skills menu
            TestOpenSkillsMenu(player);
            return true;
        }
        else if (action == "recipexp" && args.Count() >= 2)
        {
            // Test recipe XP gain
            string recipeName = args[1];
            TestRecipeXPGain(player, recipeName);
            return true;
        }
        else if (action == "levelup" && args.Count() >= 3)
        {
            // Test level up
            string skillType = args[1];
            int targetLevel = args[2].ToInt();
            TestLevelUp(player, skillType, targetLevel);
            return true;
        }
        else if (action == "allrecipes" && args.Count() >= 2)
        {
            // Test all recipes for a skill
            string skillType = args[1];
            TestAllRecipesForSkill(player, skillType);
            return true;
        }
        
        // Invalid command
        SendReply(player, "Invalid command. Syntax: skillstest <action> [params...]");
        return false;
    }
    
    static void SendReply(PlayerBase player, string message)
    {
        if (player)
        {
            player.MessageStatus(message);
        }
    }
}

// Register the admin command through a plugin
modded class PluginManager
{
    override void OnInit()
    {
        super.OnInit();
        
        // Register the skillstest command
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(RegisterSkillsTestCommand, 1000, false);
    }
    
    void RegisterSkillsTestCommand()
    {
        // Register the command with the existing command system
        GetGame().GetMission().RegisterCommand("skillstest", "Test the skills system", "SkillsSystemTest.ProcessAdminCommand");
    }
}
