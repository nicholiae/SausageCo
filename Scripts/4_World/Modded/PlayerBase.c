/*
 * SausageCo Skills System
 * PlayerBase Extension
 */

modded class PlayerBase
{
    // Cached skill data for client-side access
    private ref map<string, ref Param2<int, int>> m_SkillsData; // skillType -> (level, xp)
    
    // Reference to skills manager
    private ref PluginSausageSkillsManager m_SkillsManager;
    
    override void Init()
    {
        super.Init();
        
        // Initialize skills data
        m_SkillsData = new map<string, ref Param2<int, int>>();
        
        // Initialize with default values for all skill types
        array<string> skillTypes = SkillTypes.GetAllTypes();
        foreach (string skillType : skillTypes)
        {
            m_SkillsData.Set(skillType, new Param2<int, int>(0, 0));
        }
    }
    
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);
        
        // Handle skills-related RPCs
        // Note: This is handled by the SausageSkillsRPC class
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
    
    // Update all skills data (client-side)
    void UpdateSkillsData(ref array<ref Param3<string, int, int>> skillsData)
    {
        foreach (ref Param3<string, int, int> data : skillsData)
        {
            string skillType = data.param1;
            int level = data.param2;
            int experience = data.param3;
            
            UpdateSkillData(skillType, level, experience);
        }
    }
    
    // Update a single skill (client-side)
    void UpdateSkillData(string skillType, int level, int experience)
    {
        m_SkillsData.Set(skillType, new Param2<int, int>(level, experience));
    }
    
    // Get skill level (client-side)
    int GetSkillLevel(string skillType)
    {
        if (m_SkillsData.Contains(skillType))
        {
            return m_SkillsData.Get(skillType).param1;
        }
        
        return 0;
    }
    
    // Get skill experience (client-side)
    int GetSkillExperience(string skillType)
    {
        if (m_SkillsData.Contains(skillType))
        {
            return m_SkillsData.Get(skillType).param2;
        }
        
        return 0;
    }
    
    // Check if player has required skill level (server-side)
    bool HasSkillLevel(string skillType, int requiredLevel)
    {
        if (GetGame().IsServer())
        {
            // Server-side check
            if (!m_SkillsManager)
            {
                m_SkillsManager = PluginSausageSkillsManager.Cast(GetPlugin(PluginSausageSkillsManager));
            }
            
            if (m_SkillsManager && GetIdentity())
            {
                string steamId = GetIdentity().GetPlainId();
                return m_SkillsManager.HasSkillLevel(steamId, skillType, requiredLevel);
            }
        }
        else
        {
            // Client-side check (less secure but faster)
            return GetSkillLevel(skillType) >= requiredLevel;
        }
        
        return false;
    }
    
    // Add experience to a skill (server-side only)
    void AddSkillXP(string skillType, int amount)
    {
        if (GetGame().IsServer())
        {
            // Server-side implementation
            if (!m_SkillsManager)
            {
                m_SkillsManager = PluginSausageSkillsManager.Cast(GetPlugin(PluginSausageSkillsManager));
            }
            
            if (m_SkillsManager)
            {
                m_SkillsManager.AddSkillXP(this, skillType, amount);
            }
        }
    }
    
    // Open skills menu (client-side only)
    void OpenSkillsMenu()
    {
        if (GetGame().IsClient() && !GetGame().GetUIManager().IsMenuOpen(MENU_SAUSAGE_SKILLS))
        {
            GetGame().GetUIManager().EnterScriptedMenu(MENU_SAUSAGE_SKILLS, null);
        }
    }
    
    // Override SetActions to add key binding for skills menu
    override void SetActions(out TInputActionMap InputActionMap)
    {
        super.SetActions(InputActionMap);
        #ifdef CodeLock
        AddAction(ActionRaidCodelockOnSC, InputActionMap);       
        #endif 
        #ifdef RA_BASEBUILDING
        AddAction(ActionRaidRACodeLockOnSC, InputActionMap);       
        #endif 
        AddAction(ActionOpenSkillsMenu, InputActionMap);
    }
}

// Action to open skills menu
class ActionOpenSkillsMenu: ActionBase
{
    void ActionOpenSkillsMenu()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
    }
    
    override void CreateConditionComponents()
    {
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTNone;
    }
    
    override string GetText()
    {
        return "Open Skills Menu";
    }
    
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        return true;
    }
    
    override void OnExecuteServer(ActionData action_data)
    {
        // Server side - nothing to do
    }
    
    override void OnExecuteClient(ActionData action_data)
    {
        // Open skills menu
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        if (player)
        {
            player.OpenSkillsMenu();
        }
    }
}