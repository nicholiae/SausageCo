/**
 * SausageCo Skills System
 * Skill Book Testing Script
 */

class SkillBookTest
{
    // Test spawning skill books
    static void SpawnSkillBooks(PlayerBase player)
    {
        if (!player || !GetGame().IsServer())
            return;
            
        Print("[SausageSkills] Spawning skill books for testing");
        
        // Spawn one of each skill book type
        player.GetInventory().CreateInInventory("SausageCo_SkillBook_Engineering");
        player.GetInventory().CreateInInventory("SausageCo_SkillBook_Farming");
        player.GetInventory().CreateInInventory("SausageCo_SkillBook_Firearm");
        player.GetInventory().CreateInInventory("SausageCo_SkillBook_Leather");
        player.GetInventory().CreateInInventory("SausageCo_SkillBook_Mechanic");
        player.GetInventory().CreateInInventory("SausageCo_SkillBook_Medic");
        player.GetInventory().CreateInInventory("SausageCo_SkillBook_Hunter");
        player.GetInventory().CreateInInventory("SausageCo_SkillBook_Cook");
        
        Print("[SausageSkills] Skill books spawned successfully");
    }
    
    // Process admin command
    static bool ProcessAdminCommand(PlayerBase player, array<string> args)
    {
        if (!player)
            return false;
            
        if (args.Count() == 0)
        {
            // Spawn all skill books
            SpawnSkillBooks(player);
            SendReply(player, "Spawned all skill books in your inventory.");
            return true;
        }
        
        string action = args[0];
        
        if (action == "spawn" && args.Count() >= 2)
        {
            // Spawn a specific skill book
            string skillType = args[1];
            string bookClassName = "SausageCo_SkillBook_" + skillType;
            
            ItemBase book = ItemBase.Cast(player.GetInventory().CreateInInventory(bookClassName));
            if (book)
            {
                SendReply(player, "Spawned " + bookClassName + " in your inventory.");
            }
            else
            {
                SendReply(player, "Failed to spawn " + bookClassName + ".");
            }
            
            return true;
        }
        
        // Invalid command
        SendReply(player, "Invalid command. Syntax: skillbook [spawn <skillType>]");
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
class SkillBookCommandRegistration
{
    // This will be called when the game starts
    static void RegisterCommand()
    {
        // Register the command with the existing command system
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(RegisterSkillBookCommand, 1000, false);
    }
    
    static void RegisterSkillBookCommand()
    {
        // Register the command with the existing command system
        Print("[SausageSkills] Registering skillbook command");
        
        // Use the appropriate method to register the command based on the game's command system
        GetGame().GetMission().RegisterCommand("skillbook", "Test the skill book system", "SkillBookTest.ProcessAdminCommand");
    }
}

// Initialize the command registration when the script is loaded
void InitSkillBookCommand()
{
    SkillBookCommandRegistration.RegisterCommand();
}