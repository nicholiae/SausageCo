class SausageCompany_Codelock_Settings
{     
    float RaidTimeInSeconds;
    string CanAttach;
    string CanRaid;
    string DeleteLockOnRaid;
    int ToolDamageOnRaid;
	ref array<string> RaidTools;
    
    void SausageCompany_Codelock_Settings(float inRaidTimeInSeconds, string inCanAttach, string inCanRaid, string inDeleteLockOnRaid, int inToolDamageOnRaid, array<string> inRaidTools )
    {
        RaidTimeInSeconds = inRaidTimeInSeconds;
        CanAttach = inCanAttach;
        CanRaid = inCanRaid;
        DeleteLockOnRaid = inDeleteLockOnRaid;
        ToolDamageOnRaid = inToolDamageOnRaid;
        RaidTools = inRaidTools;
    }
};

class PluginSausageCompanyCodelockConfig : PluginReadJson
{	
    [NonSerialized()]
    ref SausageCompany_Codelock_Settings settings;
    private float RaidTimeInSeconds;
    private string CanAttach;
    private string CanRaid;
    private string DeleteLockOnRaid;
    private int ToolDamageOnRaid;
	private ref array<string> RaidTools;

	void PluginSausageCompanyCodelockConfig()
	{
        m_ConfigFolder = "SausageFramework";
		m_ConfigName = "SC_CodeLockConfig";
        m_PrintName = "SC Codelock Config";
	}	    

#ifdef SERVER
	override void Load()
    {
		if (FileExist(FULLPATH))
        {
            Print("[" + m_PrintName+ "] '" + FULLPATH + "' found, loading existing config!");
            JsonFileLoader<PluginSausageCompanyCodelockConfig>.JsonLoadFile(FULLPATH, this);
            VersionCheck();
            settings = new SausageCompany_Codelock_Settings(RaidTimeInSeconds, CanAttach, CanRaid, DeleteLockOnRaid, ToolDamageOnRaid, RaidTools);
        }
    }

	override void Save()
    {
        JsonFileLoader<PluginSausageCompanyCodelockConfig>.JsonSaveFile(FULLPATH, this);
    }

	override void Default()
    {
        version = 1.0;
        RaidTimeInSeconds = 10.0;
        CanAttach = "true";
        CanRaid = "false";
        DeleteLockOnRaid = "false";
        ToolDamageOnRaid = 100;
        RaidTools = new array<string>;
		RaidTools.Insert("Hacksaw");
		Save();
	}

    protected void VersionCheck()
    {
        if(version != 1.0)
        {
            version = 1.0;
            Save();
            return; 
        }
    }

    override void Server_SendConfigToClient(PlayerBase player, PlayerIdentity identity)
    { 
        if(!GetGame().IsServer())
            return;
        auto proxiesConfigParams = new Param1<SausageCompany_Codelock_Settings>(settings);
        GetGame().RPCSingleParam(player, SausageCompany_RPC.RPC_CLIENT_CODELOCK_SETCONFIG, proxiesConfigParams, true, identity);
    }    

#endif

    override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		switch (rpc_type)
		{
			case SausageCompany_RPC.RPC_CLIENT_CODELOCK_SETCONFIG: 
            {
                if(!GetGame().IsClient())
                    return;
				Param1<SausageCompany_Codelock_Settings> config;
                if(!ctx.Read(config))
                    return;
                settings = config.param1;                
                RaidTimeInSeconds = settings.RaidTimeInSeconds;
                CanAttach = settings.CanAttach;
                CanRaid = settings.CanRaid;
                DeleteLockOnRaid = settings.DeleteLockOnRaid;
                ToolDamageOnRaid = settings.ToolDamageOnRaid;
                RaidTools = settings.RaidTools;
                Print("[" + m_PrintName + "] Received instance of config " + settings);
				break;
			}           
		}
	}

	float Get_RaidTimeInSeconds()
	{
		return RaidTimeInSeconds;
	}

    bool CanAttach() 
    {
        CanAttach.ToLower();
        return CanAttach == "true";
    }

    bool CanRaid()
    {
        CanRaid.ToLower();
        return CanRaid == "true";
    }

    bool ShouldDeleteLockOnRaid()
    {
        DeleteLockOnRaid.ToLower();
        return DeleteLockOnRaid == "true";
    }

	int Get_ToolDamageOnRaid()
	{
		return ToolDamageOnRaid;
	}

    array<string> Get_RaidTools()
	{
		return RaidTools;
	}
};


static PluginSausageCompanyCodelockConfig GetSausageCompanyCodelockConfig()
{
    PluginSausageCompanyCodelockConfig codelock_config = PluginSausageCompanyCodelockConfig.Cast(GetPlugin(PluginSausageCompanyCodelockConfig));
    if(codelock_config)
    {
        return codelock_config;
    }
    return null;
};