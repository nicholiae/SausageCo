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
};