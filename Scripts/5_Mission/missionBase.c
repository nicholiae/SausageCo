modded class MissionBase 
{
    override UIScriptedMenu CreateScriptedMenu(int id) 
    {
        UIScriptedMenu menu = NULL;
        menu = super.CreateScriptedMenu(id);
        if (!menu && id == SC_Constants.SC_NOTICE_UI) 
        {
            menu = new SC_ItemDropWarningMenu;
            if (menu) 
            {
                menu.SetID(id);
            }
        }
        return menu;
    }
	override void OnInit()
    {
        super.OnInit();
        
        // Only initialize on server
        if (GetGame().IsServer())
        {
            // Initialize the skills system
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SkillsSystemInit.OnGameInit, 1000, false);
        }
    }
};