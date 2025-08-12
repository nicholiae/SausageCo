class SC_Proxies_Settings
{    
    bool HideAllProxiesWhenClosed;
    bool HideWeaponProxies;
    bool HideClothingProxies;
    bool HideOtherProxies;
};

class PluginSausageCompanyProxiesConfig : PluginReadJson
{		
    private ref SC_Proxies_Settings proxies_settings;

	void PluginSausageCompanyProxiesConfig()
	{
        m_ConfigFolder = "SausageFramework";
		m_ConfigName = "Proxies_Config";
        m_PrintName = "SausageFramework Proxies Config";
	}	    

#ifdef SERVER
	override void Load()
    {
		if (FileExist(FULLPATH))
        {
            Print("[" + m_PrintName+ "] '" + FULLPATH + "' found, loading existing config!");
            PluginSausageCompanyProxiesConfig SC_config = PluginSausageCompanyProxiesConfig.Cast(GetPlugin(PluginSausageCompanyProxiesConfig));
            JsonFileLoader<PluginSausageCompanyProxiesConfig>.JsonLoadFile(FULLPATH, SC_config);
            VersionCheck();
        }
    }

	override void Save()
    {
        PluginSausageCompanyProxiesConfig SC_config = PluginSausageCompanyProxiesConfig.Cast(GetPlugin(PluginSausageCompanyProxiesConfig));
        JsonFileLoader<PluginSausageCompanyProxiesConfig>.JsonSaveFile(FULLPATH, SC_config);
    }

	override void Default()
    {
        proxies_settings = new SC_Proxies_Settings();
        proxies_settings.HideAllProxiesWhenClosed = true;
        proxies_settings.HideWeaponProxies = false;
        proxies_settings.HideClothingProxies = false;
        proxies_settings.HideOtherProxies = false;	
        version = 1.0;
		Save();
	}

    protected void VersionCheck()
    {
        if(version != 1)
        {
            Default();
            return; 
        }
    }    

    override void Server_SendConfigToClient(PlayerBase player, PlayerIdentity identity)
    { 
        if(!GetGame().IsServer())
            return;
        auto proxiesConfigParams = new Param1<SC_Proxies_Settings>(proxies_settings);
        GetGame().RPCSingleParam(player, SausageCompany_RPC.RPC_CLIENT_SETPROXIESCONFIG, proxiesConfigParams, true, identity);
    }
#endif

	SC_Proxies_Settings GetProxiesSettings()
	{
		return proxies_settings;
	}

    override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		switch (rpc_type)
		{
			case SausageCompany_RPC.RPC_CLIENT_SETPROXIESCONFIG: 
            {
                if(!GetGame().IsClient())
                    return;
				Param1<SC_Proxies_Settings> proxiesConfig;
                if(!ctx.Read(proxiesConfig))
                    return;
                proxies_settings = proxiesConfig.param1;
                Print("[" + m_PrintName+ "] Received instance of config " + proxies_settings);
				break;
			}           
		}
	}
};


static SC_Proxies_Settings GetSausageCompanyProxiesConfig()
{
    PluginSausageCompanyProxiesConfig proxies_config = PluginSausageCompanyProxiesConfig.Cast(GetPlugin(PluginSausageCompanyProxiesConfig));
    if(proxies_config)
    {
        return proxies_config.GetProxiesSettings();
    }
    return null;
}