modded class PlayerBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

        switch (rpc_type)
        {
        case SausageCompany_RPC.RPC_CLIENT_SETPROXIESCONFIG:
            PluginSausageCompanyProxiesConfig SC_config = PluginSausageCompanyProxiesConfig.Cast(GetPlugin(PluginSausageCompanyProxiesConfig));
            if(SC_config)
            {
                SC_config.OnRPC(sender, this, rpc_type, ctx);
            }
            break;
        case SausageCompany_RPC.RPC_CLIENT_CODELOCK_SETCONFIG:
            PluginSausageCompanyCodelockConfig codelock_config = GetSausageCompanyCodelockConfig();
            if(codelock_config)
            {
                codelock_config.OnRPC(sender, this, rpc_type, ctx);
            }
            break;
        case SausageCompany_RPC.RPC_CLIENT_SETSETTINGSCONFIG:
            PluginSCSettingsConfig settings_config = PluginSCSettingsConfig.Cast(GetPlugin(PluginSCSettingsConfig));
            if(settings_config)
            {
                settings_config.OnRPC(sender, this, rpc_type, ctx);
            }
            break;
        case SausageCompany_RPC.RPC_CLIENT_SHOWWARNINGUI:
            if (GetGame().IsClient() && GetGame().GetUIManager())
            {
                GetGame().GetUIManager().EnterScriptedMenu(SC_Constants.SC_NOTICE_UI,null);                
                //GetGame().GetUIManager().ShowScriptedMenu(noticeUI, NULL);
                GetGame().GetMission().AddActiveInputExcludes({"menu"});
            }
            break;
        } 
        
	}

    override void SetActions(out TInputActionMap InputActionMap)
    {
        super.SetActions(InputActionMap);
        #ifdef CodeLock
        AddAction(ActionRaidCodelockOnSC, InputActionMap);       
        #endif 
        #ifdef RA_BASEBUILDING
        AddAction(ActionRaidRACodeLockOnSC, InputActionMap);       
        #endif 
    }
};