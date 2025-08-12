modded class ActionMineRock : ActionMineBase
{
    static ref map<string, string> cachedMiningConfig;
    static bool configLoaded = false;

    static ref array<string> validMiningNodes = {
        "SausageNode_copper",
        "SausageNode_gold",
        "SausageNode_Blood",
        "SausageNode_silver",
        "SausageNode_Rune",
        "SausageNode_Jade",
        "SausageNode_Presem"
    };

    bool configLoadFailedLogged = false;

    void LoadMiningConfigOnce()
    {
        if (!configLoaded)
        {
            SausageMiningConfig miningConfig = SausageMiningConfig.Cast(GetPlugin(SausageMiningConfig));

            if (miningConfig)
            {
                cachedMiningConfig = miningConfig.GetSausageMiningClientConfig();
				

                if (cachedMiningConfig && cachedMiningConfig.Count() > 0)
                {
                    Print("[Sausage_Mining] Mining config loaded successfully.");
                    configLoaded = true;
                    configLoadFailedLogged = false;
                }
                else
                {
                    if (!configLoadFailedLogged)
                    {
                        Print("[Sausage_Mining] Failed to load mining config or config is empty.");
                        LogConnectedClientNames();
                        configLoadFailedLogged = true;
                    }
                }
            }
            else
            {
                if (!configLoadFailedLogged)
                {
                    Print("[Sausage_Mining] Error: SausageMiningConfig plugin not found.");
                    LogConnectedClientNames();
                    configLoadFailedLogged = true;
                }
            }
        }
    }

    void LogConnectedClientNames()
    {
        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);

        string clientNames = "[Sausage_Mining] Connected clients: ";
        bool first = true;

        foreach (Man player : players)
        {
            PlayerIdentity identity = player.GetIdentity();
            if (identity)
            {
                if (!first)
                {
                    clientNames += ", ";
                }
                clientNames += identity.GetName();
                first = false;
            }
        }

        Print(clientNames);
    }

    bool IsValidMiningNode(string nodeType)
    {
        return validMiningNodes.Find(nodeType) > -1;
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        LoadMiningConfigOnce();
        if (!item)
            return false;

        // Only allow Pickaxe or SledgeHammer
        if (!(item.IsKindOf("Pickaxe") || item.IsKindOf("SledgeHammer")))
            return false;

        Object targetObject = target.GetObject();
        if (!targetObject)
            return false;

        string currentTargetType = targetObject.GetType();

        return targetObject.IsRock() || IsValidMiningNode(currentTargetType);
    }

    override void OnActionInfoUpdate(PlayerBase player, ActionTarget target, ItemBase item)
    {
        LoadMiningConfigOnce();
		
		SausageMiningConfig miningConfig = SausageMiningConfig.Cast(GetPlugin(SausageMiningConfig));
		
        Object targetObject = target.GetObject();
        EntityAI fTargetObject = EntityAI.Cast(targetObject);
        if (targetObject.IsRock())
        {
            m_Text = "#harvest" + " " + GetYieldName(player, target, item);
        }
        else if (fTargetObject)
        {
            string itemType = fTargetObject.GetType();
			string thisText = miningConfig.GetText(itemType);
			// Print(itemType);
			// Print(thisText);
            if (cachedMiningConfig.Contains(itemType))
            {
                m_Text = cachedMiningConfig.Get(itemType);
            }
            else
            {
                m_Text = thisText;
            }
        }
    }
}

modded class CAContinuousMineRock : CAContinuousMineWood
{
    SausageMiningConfig miningConfig;
    vector lastPosition = vector.Zero;
    bool configAttemptedLoad = false;

    void EnsureMiningConfigLoaded()
    {
        if (configAttemptedLoad) return;

        miningConfig = SausageMiningConfig.Cast(GetPlugin(SausageMiningConfig));
        if (miningConfig)
        {
            miningConfig.LoadConfig();
            Print("[Sausage_Mining] Config loaded successfully.");
        }
        else
        {
            Print("[Sausage_Mining] ERROR: SausageMiningConfig plugin not found.");
        }
        configAttemptedLoad = true;
    }

    override bool GetMiningData(ActionData action_data)
    {
        EnsureMiningConfigLoaded();

        RockBase ntarget;
        if (Class.CastTo(ntarget, action_data.m_Target.GetObject()))
        {
            return true;
        }

        Building starget;
        if (Class.CastTo(starget, action_data.m_Target.GetObject()))
        {
            return true;
        }

        Print("[Sausage_Mining] Failed to cast target object to valid mining object.");
        return false;
    }

    override int Execute(ActionData action_data)
    {
        vector currentPosition = action_data.m_Player.GetPosition();

        if (lastPosition != vector.Zero && vector.Distance(currentPosition, lastPosition) > 0.02)
        {
            Print("[Sausage_Mining] Player moved or jumped, canceling the mining action.");
            StopMiningAction(action_data);
            return UA_FINISHED;
        }
        lastPosition = currentPosition;

        if (!action_data.m_Player || !m_DataLoaded)
        {
            Print("[Sausage_Mining] Error: Player or mining data not loaded.");
            StopMiningAction(action_data);
            return UA_ERROR;
        }

        Object targetObject = action_data.m_Target.GetObject();

        if (GetGame().IsServer())
        {
            if (targetObject && targetObject.IsDamageDestroyed())
            {
                Print("[Sausage_Mining] Target object is destroyed, stopping mining.");
                StopMiningAction(action_data);
                return UA_FINISHED;
            }

            if (action_data.m_MainItem && action_data.m_MainItem.IsDamageDestroyed())
            {
                Print("[Sausage_Mining] Tool is destroyed, stopping mining.");
                StopMiningAction(action_data);
                return UA_FINISHED;
            }
        }

        if (m_TimeElpased < m_AdjustedTimeBetweenMaterialDrops)
        {
            m_TimeElpased += action_data.m_Player.GetDeltaT();
            return UA_PROCESSING;
        }

        m_TimeElpased = 0;

        OnCompleteProgress(action_data);
        return UA_PROCESSING;
    }

    void StopMiningAction(ActionData action_data)
    {
        if (action_data && action_data.m_Player)
        {
            ActionManagerClient actionManager = ActionManagerClient.Cast(action_data.m_Player.GetActionManager());
            if (actionManager)
            {
                actionManager.Interrupt();
                Print("[Sausage_Mining] Stopped mining animation/action for player: " + action_data.m_Player.GetIdentity().GetName());
            }
        }
    }

    void OnCompleteProgress(ActionData action_data)
    {
        EnsureMiningConfigLoaded();

        if (GetGame().IsServer() && action_data.m_Player && action_data.m_MainItem)
        {
            PlayerBase player = action_data.m_Player;
            ItemBase tool = action_data.m_MainItem;
            Object targetObject = action_data.m_Target.GetObject();

            if (targetObject)
            {
                string targetType = targetObject.GetType();
                int maxMine = miningConfig.GetMaxMineForNode(targetType);
                int damagePerHit = 1000 / maxMine;
				
				
                targetObject.DecreaseHealth("", "", damagePerHit);
				
                Print("[Sausage_Mining] Node health decreased by " + damagePerHit + ". Remaining health: " + targetObject.GetHealth("", ""));
                if (targetObject.GetHealth("", "") <= 0)
                {
                    Print("[Sausage_Mining] Node destroyed: " + targetType);
                    GetGame().ObjectDelete(targetObject);
                }
				
                string minedItem = "";
                ref SausageMinableItemConfig config = miningConfig.getItemConfig(targetType);
                if (config)
                {
                    minedItem = GetItemBasedOnProbability(config.getProbabilities());
                }
                else
                {
                    minedItem = GetItemBasedOnProbability(miningConfig.getProbabilities());
                }

                if (minedItem != "")
                {
                    ItemBase minedItemInstance = ItemBase.Cast(GetGame().CreateObjectEx(minedItem, player.GetPosition(), ECE_PLACE_ON_SURFACE));
                    minedItemInstance.SetQuantity(Math.RandomInt(1, 5));
                    Print("[Sausage_Mining] Mined item: " + minedItem + " created.");
                }

                if (tool && tool.GetHealth() > 0)
                {
                    float toolDamagePerUse = 10.0;
                    tool.DecreaseHealth("", "", toolDamagePerUse);
                    Print("[Sausage_Mining] Tool health decreased by " + toolDamagePerUse + ". New health: " + tool.GetHealth());
                }
            }
        }
    }

    string GetItemBasedOnProbability(array<ref SausageItemProbability> itemProbabilities)
    {
        int total = 0;
        SausageItemProbability prob;

        for (int idx = 0; idx < itemProbabilities.Count(); idx++)
        {
            prob = itemProbabilities.Get(idx);
            total += prob.probability;
        }

        int randomnumber = Math.RandomInt(0, total);

        for (int idx2 = 0; idx2 < itemProbabilities.Count(); idx2++)
        {
            prob = itemProbabilities.Get(idx2);
            if (randomnumber < prob.probability)
            {
                return prob.item;
            }
            randomnumber -= prob.probability;
        }

        return "Stone";
    }

    string GetItemBasedOnProbability(map<string, int> itemProbabilities)
    {
        int total = 0;

        for (int i = 0; i < itemProbabilities.Count(); i++)
        {
            total += itemProbabilities.GetElement(i);
        }

        int randomnumber = Math.RandomInt(0, total);

        for (int j = 0; j < itemProbabilities.Count(); j++)
        {
            randomnumber -= itemProbabilities.GetElement(j);
            if (randomnumber < 0)
            {
                return itemProbabilities.GetKey(j);
            }
        }

        return "Stone";
    }
}
