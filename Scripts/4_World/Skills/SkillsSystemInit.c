/*
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
        
        // Initialize XP events system
        SkillXPEvents.Init();
        
        Print("[SausageSkills] Skills System Initialized");
    }
}

// Hook into the game initialization
modded class DayZGame
{
    // Events for XP gain
    ref ScriptInvoker Event_OnRecipePerformed = new ScriptInvoker();
    ref ScriptInvoker Event_OnBuildPartPlaced = new ScriptInvoker();
    ref ScriptInvoker Event_OnDismantleFinished = new ScriptInvoker();
    ref ScriptInvoker Event_OnMedicalActionPerformed = new ScriptInvoker();
    ref ScriptInvoker Event_OnEntityKilled = new ScriptInvoker();
    ref ScriptInvoker Event_OnItemButchered = new ScriptInvoker();
    ref ScriptInvoker Event_OnPlantSeed = new ScriptInvoker();
    ref ScriptInvoker Event_OnHarvestPlant = new ScriptInvoker();
    ref ScriptInvoker Event_OnWeaponFired = new ScriptInvoker();
    ref ScriptInvoker Event_OnWeaponCleaned = new ScriptInvoker();
    ref ScriptInvoker Event_OnVehicleRepaired = new ScriptInvoker();
    ref ScriptInvoker Event_OnVehiclePartAttached = new ScriptInvoker();
    ref ScriptInvoker Event_OnItemTanned = new ScriptInvoker();
    ref ScriptInvoker Event_OnItemCooked = new ScriptInvoker();
    
    override void OnInit()
    {
        super.OnInit();
        
        // Initialize the skills system
        GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SkillsSystemInit.OnGameInit, 1000, false);
    }
}