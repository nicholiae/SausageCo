/**
 * SausageCo Skills System
 * Skills Menu Handler
 */

// Register the skills menu with the game
modded class MissionGameplay
{
    // Reference to our menu
    private ref SausageSkillsMenu m_SausageSkillsMenu;
    
    override void OnInit()
    {
        super.OnInit();
        
        // Register our menu
        GetUIManager().RegisterMenu(MENU_SAUSAGE_SKILLS, SausageSkillsMenu);
        
        // Register client RPCs
        SausageSkillsRPC.RegisterClientRPCs();
    }
    
    override void OnMissionFinish()
    {
        // Unregister our menu
        GetUIManager().UnregisterMenu(MENU_SAUSAGE_SKILLS);
        
        super.OnMissionFinish();
    }
    
    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);
        
        // Check for key press to open skills menu
        Input input = GetGame().GetInput();
        if (input.LocalPress("UASkillsMenu", false))
        {
            // Open skills menu
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            if (player)
            {
                player.OpenSkillsMenu();
            }
        }
    }
}

// Register the skills menu with the server
modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        
        // Register server RPCs
        SausageSkillsRPC.RegisterServerRPCs();
    }
}

// Register the key binding for the skills menu
modded class DayZPlayerImplement
{
    override void Init()
    {
        super.Init();
        
        // Register the key binding
        GetDayZGame().GetUserManager().GetUserActionManager().RegisterAction(SausageSkillsInputActions.OPEN_SKILLS_MENU, "UASkillsMenu", "Open Skills Menu", "K");
    }
}