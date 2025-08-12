
class SBSConfig
{
	
	int g_SausageGarden_CompostBinTime;

}

class SBSGlobals
{
	private static ref SBSConfig m_SBSConfig = NULL;
	private static const int MAX_CONFIG_LINES = 500;
	private static const string configPath = "$profile:\\SBS_Settings.json";
	private static const string configRoot = "$profile:\\";
	
	static SBSConfig Get()
	{
		if (m_SBSConfig == NULL)
		{
			Set();
		}
		return m_SBSConfig;
	}

	static void Set()
	{
		m_SBSConfig = LoadConfig();
	}

	private static SBSConfig LoadConfig()
	{
		SBSConfig config = new SBSConfig;

		if (!FileExist(configPath))
        {
            Print("[SBS] 'SBS_Settings' does not exist, creating...");
            CreateDefaultConfig(config);
        }

		JsonFileLoader<SBSConfig>.JsonLoadFile(configPath, config);
		Print("[SBS] 'SBS_Settings' found, loading...");
		return config;
	}

	private static void CreateDefaultConfig(SBSConfig config)
	{
		
		config.g_SausageGarden_CompostBinTime = 252;
	
        if (!FileExist(configRoot))
        {
            Print("[SBS] '" + configRoot + "' does not exist, creating...");
            MakeDirectory(configRoot);
        }
        JsonFileLoader<SBSConfig>.JsonSaveFile(configPath, config);
	}
};
