class SausageItemProbability {
	string item;
	int probability;

	void SausageItemProbability(string item, int prob) {
	    this.item = item;
	    this.probability = prob;
	}
}

class SausageMinableItemConfig
{
    string actionText;
    int max_mine = 10;
    ref array<string> enabledTypes;
    ref array<ref SausageItemProbability> itemsProbabilities;

    void SausageMinableItemConfig( ) {
        this.enabledTypes = new ref array<string>;
        this.itemsProbabilities = new ref array< ref SausageItemProbability>;
    }

    ref array<ref SausageItemProbability> getProbabilities() {
        return this.itemsProbabilities;
    }

    bool hasType(string type) {
        return this.enabledTypes.Find(type) > -1;
    }
}

class SausageMiningConfig extends PluginBase
{
	static ref map<string, string> g_SausageMiningClientConfig = new map<string, string>();

    static ref map<string, string> GetSausageMiningClientConfig() {
        return g_SausageMiningClientConfig;
    }
	
	ref array<ref SausageMinableItemConfig> buildings = new array<ref SausageMinableItemConfig>;
    ref map<string, int> minedItemsProbabilities = new map<string, int>;
    const static ref map<string, int> mineCount = new map<string, int>;
    const static int max_mine = 10;
	private const static string FileFolder = "$profile:Sausage\\Mining\\";
	private const static string FilePath = FileFolder + "config.json";

    override void OnInit()
    {
        Print("[Sausage_Mining] SausageMiningConfig::OnInit()");
        LoadConfig();
        if (GetGame().IsServer()) {
            SendConfigToAllClients();
        }
    }

    int GetMaxMineForNode(string nodeType) {
        for (int i = 0; i < buildings.Count(); i++) {
            SausageMinableItemConfig config = buildings.Get(i);
            if (config.hasType(nodeType)) {
                if (config.max_mine > 0) {
                    return config.max_mine;
                } else {
                    return 10;
                }
            }
        }
        return 10;
    }
	
	void LoadConfig()
	{
		Print("[Sausage_Mining] Started loading config");
		if(!FileExist(FilePath)) {
			
            Print("[Sausage_Mining] Config file not found, initializing new config.");
            Init();
            SaveConfig();
		}
		else{
			JsonFileLoader<SausageMiningConfig>.JsonLoadFile(FilePath, this);

			int buildingCounts = buildings.Count();
			Print("[Sausage_Mining] Number of minable items loaded: " + buildingCounts.ToString());
			
			for(int i = 0; i < buildings.Count(); i++)
			{
			   SausageMinableItemConfig config = buildings.Get(i);
			   for(int j = 0; j < config.enabledTypes.Count();j++)
			   {
					string enabledType = config.enabledTypes.Get(j);
					g_SausageMiningClientConfig.Set(config.enabledTypes.Get(j),  config.actionText);
				}
			}
			Print("[Sausage_Mining] Finished loading config");
		}
	}
	
	void Init()
	{
	    this.CheckFolder();
		
        ref SausageMinableItemConfig Coppercfg = new SausageMinableItemConfig();
        Coppercfg.actionText = "Mine for Copper Ore";
        Coppercfg.enabledTypes = {"SausageNode_copper"};
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Blood", 0));
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Rune", 0));
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Jade", 0));
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Presem", 0));
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_silver", 0));
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_gold", 0));
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_copper", 100));
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Emerald", 40));
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Saphire", 20));
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Ruby", 0));
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Diamond", 0));
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_base", 70));
        Coppercfg.itemsProbabilities.Insert(new ref SausageItemProbability("Stone", 30));
        this.buildings.Insert(Coppercfg);
        Print("[Sausage_Mining] Configured Copper Ore.");

        ref SausageMinableItemConfig Silvercfg = new SausageMinableItemConfig();
        Silvercfg.actionText = "Mine for Silver Ore";
        Silvercfg.enabledTypes = {"SausageNode_silver"};
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Blood", 0));
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Rune", 0));
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Jade", 0));
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Presem", 0));
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_silver", 100));
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_gold", 0));
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_copper", 0));
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Emerald", 45));
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Saphire", 25));
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Ruby", 5));
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Diamond", 0));
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_base", 70));
        Silvercfg.itemsProbabilities.Insert(new ref SausageItemProbability("Stone", 30));
        this.buildings.Insert(Silvercfg);
        Print("[Sausage_Mining] Configured Silver Ore.");

        ref SausageMinableItemConfig Goldcfg = new SausageMinableItemConfig();
        Goldcfg.actionText = "Mine for Gold Ore";
        Goldcfg.enabledTypes = {"SausageNode_gold"};
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Blood", 0));
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Rune", 0));
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Jade", 0));
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Presem", 0));
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_silver", 0));
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_gold", 100));
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_copper", 0));
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Emerald", 50));
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Saphire", 30));
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Ruby", 10));
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Diamond", 0));
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_base", 70));
        Goldcfg.itemsProbabilities.Insert(new ref SausageItemProbability("Stone", 30));
        this.buildings.Insert(Goldcfg);
        Print("[Sausage_Mining] Configured Gold Ore.");

        ref SausageMinableItemConfig Presemcfg = new SausageMinableItemConfig();
        Presemcfg.actionText = "Mine for Presem Ore";
        Presemcfg.enabledTypes = {"SausageNode_Presem"};
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Blood", 0));
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Rune", 0));
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Jade", 0));
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Presem", 100));
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_silver", 0));
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_gold", 0));
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_copper", 0));
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Emerald", 55));
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Saphire", 35));
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Ruby", 15));
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Diamond", 0));
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_base", 70));
        Presemcfg.itemsProbabilities.Insert(new ref SausageItemProbability("Stone", 30));
        this.buildings.Insert(Presemcfg);
        Print("[Sausage_Mining] Configured Presem Ore.");

        ref SausageMinableItemConfig Jadecfg = new SausageMinableItemConfig();
        Jadecfg.actionText = "Mine for Jade Ore";
        Jadecfg.enabledTypes = {"SausageNode_Jade"};
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Blood", 0));
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Rune", 0));
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Jade", 100));
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Presem", 0));
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_silver", 0));
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_gold", 0));
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_copper", 0));
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Emerald", 60));
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Saphire", 40));
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Ruby", 20));
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Diamond", 0));
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_base", 70));
        Jadecfg.itemsProbabilities.Insert(new ref SausageItemProbability("Stone", 30));
        this.buildings.Insert(Jadecfg);
        Print("[Sausage_Mining] Configured Jade Ore.");

        ref SausageMinableItemConfig Runecfg = new SausageMinableItemConfig();
        Runecfg.actionText = "Mine for Rune";
        Runecfg.enabledTypes = {"SausageNode_Rune"};
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Blood", 0));
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Rune", 100));
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Jade", 0));
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Presem", 0));
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_silver", 0));
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_gold", 0));
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_copper", 0));
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Emerald", 65));
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Saphire", 45));
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Ruby", 25));
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Diamond", 5));
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_base", 70));
        Runecfg.itemsProbabilities.Insert(new ref SausageItemProbability("Stone", 30));
        this.buildings.Insert(Runecfg);
        Print("[Sausage_Mining] Configured Rune Ore.");

        ref SausageMinableItemConfig Bloodcfg = new SausageMinableItemConfig();
        Bloodcfg.actionText = "Mine for Blood Ore";
        Bloodcfg.enabledTypes = {"SausageNode_Blood"};
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Blood", 100));
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Rune", 0));
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Jade", 0));
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_Presem", 0));
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_silver", 0));
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_gold", 0));
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_copper", 0));
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Emerald", 70));
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Saphire", 50));
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Ruby", 30));
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageGem_Diamond", 10));
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("SausageNugget_base", 70));
        Bloodcfg.itemsProbabilities.Insert(new ref SausageItemProbability("Stone", 30));
        this.buildings.Insert(Bloodcfg);
        Print("[Sausage_Mining] Configured Blood Ore.");

	}

    ref map<string, int> getProbabilities() {
    	return this.minedItemsProbabilities;
    }

    ref array<ref SausageItemProbability> getBuildingProbabilities(string buildingType) {
        for(int i = 0; i < this.buildings.Count(); i++)
        {
            SausageMinableItemConfig config = this.buildings.Get(i);
            if(config.hasType(buildingType)) {
                return config.getProbabilities();
            }
        }

        return null;
    }

    ref SausageMinableItemConfig getItemConfig(string buildingType) {

        for(int i = 0; i < this.buildings.Count(); i++)
        {
            SausageMinableItemConfig config = this.buildings.Get(i);
            if(config.hasType(buildingType)) {
                return config;
            }
        }

        return null;
    }

    bool hasType(string itemType) {
        for(int i = 0; i < this.buildings.Count(); i++)
        {
            SausageMinableItemConfig config = this.buildings.Get(i);
            if(config.hasType(itemType)) {
               return true;
            }
        }

        return false;
    }

    string GetText(string itemType) {
        for(int i = 0; i < this.buildings.Count(); i++)
        {
            SausageMinableItemConfig config = this.buildings.Get(i);
			// Print("Get Textc");
			// Print(itemType);
			// Print(config.actionText);
			// Print(config.enabledTypes);
			// return config.actionText;
            if(config.hasType(itemType)) {
				
               return config.actionText;
            }
        }

        return "Default Action";
    }

    void SaveConfig() {
        JsonFileLoader<SausageMiningConfig>.JsonSaveFile(FilePath, this);
        Print("[Sausage_MiningCfg] Saved mining config to file with " + buildings.Count().ToString() + " items.");
        for (int i = 0; i < buildings.Count(); i++) {
            SausageMinableItemConfig config = buildings.Get(i);
            Print("[Sausage_MiningCfg] Saving Item: " + config.actionText + " with " + config.itemsProbabilities.Count().ToString() + " probabilities.");
        }
    }
    void sendToClient(PlayerIdentity identity) {
       Print("[Sausage_Mining] Sending batch configuration to client...");

        ref array<ref Param2<string, string>> configDataArray = new array<ref Param2<string, string>>();

        foreach (SausageMinableItemConfig config : buildings) {
            foreach (string enabledType : config.enabledTypes) {
                configDataArray.Insert(new Param2<string, string>(enabledType, config.actionText));
            }
        }

        GetRPCManager().SendRPC("SausageMiningRPC", "SausageMiningRPCPopulateConfig", new Param1<ref array<ref Param2<string, string>>>(configDataArray), true, identity);
       Print("[Sausage_Mining] Batch configuration sent to client.");
    }

    void SendConfigToAllClients() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            return;
        }

        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);

        if (players.Count() == 0) {
            Print("[Sausage_Mining] No players connected. Skipping config send.");
            return;
        }

        foreach (Man player : players) {
            PlayerIdentity identity = player.GetIdentity();

            if (identity) {
                sendToClient(identity);
            } else {
                Print("[Sausage_Mining] Skipped sending config to a player without a valid identity.");
            }
        }
    }
    static void CheckFolder(){
        if (!FileExist(SausageMiningConfig.FileFolder))
        {
            if (!FileExist("$profile:\\Sausage\\")) {
                MakeDirectory("$profile:\\Sausage\\");
            }
			Print("[Sausage_Mining] Did not find profile folder, Creating Folder");
            MakeDirectory(SausageMiningConfig.FileFolder);
        }
		Print("[Sausage_Mining] Found profile folder");
    }
};
