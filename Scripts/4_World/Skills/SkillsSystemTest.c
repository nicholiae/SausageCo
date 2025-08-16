/*
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
        
        // Test opening the skills menu
        TestOpenSkillsMenu(player);
        
        Print("[SausageSkills] All tests completed");
    }
}

// Admin command for testing the skills system
class AdminCommandSkillsTest: ModCommand
{
    void AdminCommandSkillsTest()
    {
        SetName("skillstest");
        SetDescription("Test the skills system");
        SetSyntax("skillstest <action> [params...]");
        SetPermission(1); // Admin only
    }
    
    override bool Execute(array<string> args, PlayerBase sender)
    {
        if (!sender)
            return false;
            
        if (args.Count() == 0)
        {
            // Run all tests
            SkillsSystemTest.RunAllTests(sender);
            return true;
        }
        
        string action = args[0];
        
        if (action == "addxp" && args.Count() >= 3)
        {
            // Test adding XP
            string skillType = args[1];
            int amount = args[2].ToInt();
            SkillsSystemTest.TestAddXP(sender, skillType, amount);
            return true;
        }
        else if (action == "checklevel" && args.Count() >= 3)
        {
            // Test checking skill level
            string skillType = args[1];
            int requiredLevel = args[2].ToInt();
            SkillsSystemTest.TestCheckSkillLevel(sender, skillType, requiredLevel);
            return true;
        }
        else if (action == "craft" && args.Count() >= 3)
        {
            // Test crafting a recipe
            string skillType = args[1];
            string recipeName = args[2];
            SkillsSystemTest.TestCraftRecipe(sender, skillType, recipeName);
            return true;
        }
        else if (action == "openmenu")
        {
            // Test opening the skills menu
            SkillsSystemTest.TestOpenSkillsMenu(sender);
            return true;
        }
        
        // Invalid command
        SendReply(sender, "Invalid command. Syntax: skillstest <action> [params...]");
        return false;
    }
    
    private void SendReply(PlayerBase player, string message)
    {
        if (player)
        {
            player.MessageStatus(message);
        }
    }
}