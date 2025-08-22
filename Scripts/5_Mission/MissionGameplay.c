modded class MissionGameplay {
    void MissionGameplay() {
        GetRPCManager().AddRPC("SausageMiningRPC", "SausageMiningRPCPopulateConfig", this, SingleplayerExecutionType.Client);
        Print("[MissionGameplay] RPC Manager for SausageMining initialized.");
        
        // Register the SkillBookMenu
        GetUIManager().RegisterMenu(MENU_SAUSAGE_SKILLBOOK, SkillBookMenu);
        Print("[MissionGameplay] SkillBookMenu registered.");
    }

    void SausageMiningRPCPopulateConfig(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) {
        if (type == CallType.Client) {
            Param1<ref array<ref Param2<string, string>>> data;
            if (!ctx.Read(data)) return;

            ref array<ref Param2<string, string>> configDataArray = data.param1;
            foreach (auto item : configDataArray) {
                string enabledType = item.param1;
                string actionText = item.param2;
                g_SausageMiningClientConfig.Set(enabledType, actionText);
                Print("[MissionGameplay] Updated client config for node type " + enabledType + " with action text: " + actionText);
            }
        }
    }
	
	override void OnInit()
    {
        super.OnInit();
        
        // Initialize the skills system
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SkillsSystemInit.OnGameInit, 1000, false);
    }
}