class SC_VirtualStorage_Settings
{
    bool EnableVirtualStorage = false;
    bool EnableAutoStoreOnClose = false;
    bool EnableAutoStoreTimer = false;
    int AutoStoreTimerInSeconds = 600;
	ref array<string> ItemsBlacklist = new array<string>;
	ref array<string> ContainerBlacklist = new array<string>;
};

class SC_Openable_Settings
{
    bool EnableAutoClose = false;
    int AutoCloseTimerInSeconds = 600;
};

class SC_Fridge_Settings
{
    bool EnableFridgePreservation = false;
	ref array<string> OtherFridgeClasses = new array<string>;
    float PreservationMultiplier = 2.0;
};

class SC_Settings
{    
    ref SC_VirtualStorage_Settings VirtualStorage = new SC_VirtualStorage_Settings;
    ref SC_Openable_Settings Openables = new SC_Openable_Settings;
    ref SC_Fridge_Settings Fridge_Settings = new SC_Fridge_Settings;
};

class PluginSCSettingsConfig : PluginReadJson
{		
    private ref SC_Settings m_Settings;

    static float PreservationMultiplier = 1.0;

	void PluginSCSettingsConfig()
	{
        m_ConfigFolder = "SausageFramework";
		m_ConfigName = "Settings";
        m_PrintName = "SausageFramework General Settings Config";
        wantedVersion =  1.1;
	}

#ifdef SERVER
	override void Load()
    {
		if (FileExist(FULLPATH))
        {
            Print("[" + m_PrintName+ "] '" + FULLPATH + "' found, loading existing config!");
            PluginSCSettingsConfig settingsConfig = PluginSCSettingsConfig.Cast(GetPlugin(PluginSCSettingsConfig));
            JsonFileLoader<PluginSCSettingsConfig>.JsonLoadFile(FULLPATH, settingsConfig);
            VersionCheck();
        }
        if(m_Settings && m_Settings.Fridge_Settings)
        {
           PreservationMultiplier = m_Settings.Fridge_Settings.PreservationMultiplier;
        }
    }

	override void Save()
    {
        PluginSCSettingsConfig settingsConfig = PluginSCSettingsConfig.Cast(GetPlugin(PluginSCSettingsConfig));
        JsonFileLoader<PluginSCSettingsConfig>.JsonSaveFile(FULLPATH, settingsConfig);
    }

	override void Default()
    {        
        if(!m_Settings)
        {
            m_Settings = new SC_Settings();
        }
        version = wantedVersion;
		Save();
	}

    protected void VersionCheck()
    {
        if(version != wantedVersion)
        {
            //TODO: Change here when we change the version
            Default();
            return; 
        }
    }    

    override void Server_SendConfigToClient(PlayerBase player, PlayerIdentity identity)
    { 
        if(!GetGame().IsServer())
            return;
        auto settingsConfigParams = new Param1<SC_Settings>(m_Settings);
        GetGame().RPCSingleParam(player, SausageCompany_RPC.RPC_CLIENT_SETSETTINGSCONFIG, settingsConfigParams, true, identity);
    }
#endif

	SC_Settings GetSettings()
	{
		return m_Settings;
	}

    override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		switch (rpc_type)
		{
			case SausageCompany_RPC.RPC_CLIENT_SETSETTINGSCONFIG: 
            {
                if(!GetGame().IsClient())
                    return;
				Param1<SC_Settings> settingsConfig;
                if(!ctx.Read(settingsConfig))
                    return;
                m_Settings = settingsConfig.param1;
                Print("[" + m_PrintName+ "] Received instance of config " + m_Settings);
				break;
			}           
		}
	}
};


static SC_Settings GetSCSettingsConfig()
{
    PluginSCSettingsConfig config = PluginSCSettingsConfig.Cast(GetPlugin(PluginSCSettingsConfig));
    if(config)
    {
        return config.GetSettings();
    }
    return null;
}