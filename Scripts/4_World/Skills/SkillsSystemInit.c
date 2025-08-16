/**
 * SausageCo Skills System
 * Initialization
 */

// Class to handle initialization of the skills system
class SkillsSystemInit
{
    // Called when the game is initialized
    static void OnGameInit()
    {
        Print("[SausageSkills] Initializing Skills System");
        
        // Initialize folders
        CheckFolders();
        
        // Initialize plugins first
        GetPlugin(PluginSausageSkillsConfig);
        GetPlugin(PluginSausageSkillsManager);
        
        // Initialize RPC manager
        RPCManagerHelper.GetRPCManager();
        
        Print("[SausageSkills] Skills System Initialized");
    }
    
    // Create necessary folders
    static void CheckFolders()
    {
        string skillsFolder = "$profile:Sausage\\Skills\\";
        string playersFolder = "$profile:Sausage\\Skills\\players\\";
        
        if (!FileExist(skillsFolder))
        {
            if (!FileExist("$profile:Sausage\\"))
            {
                MakeDirectory("$profile:Sausage\\");
            }
            MakeDirectory(skillsFolder);
        }
        
        if (!FileExist(playersFolder))
        {
            MakeDirectory(playersFolder);
        }
        
        Print("[SausageSkills] Folders checked and created if needed");
    }
}

// Hook into the mission initialization instead of DayZGame  --- THIS IS NOW DONE IN MISSIONGAMEPLAY.c
// modded class MissionGameplay
// {
    // override void OnInit()
    // {
        // super.OnInit();
        
        // Initialize the skills system
        // GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SkillsSystemInit.OnGameInit, 1000, false);
    // }
// }

// Server-side initialization  --- THIS IS NOW DONE IN MISSIONBASE.c
// modded class MissionBase
// {
    // override void OnInit()
    // {
        // super.OnInit();
        
        // Only initialize on server
        // if (GetGame().IsServer())
        // {
            // Initialize the skills system
            // GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SkillsSystemInit.OnGameInit, 1000, false);
        // }
    // }
// }