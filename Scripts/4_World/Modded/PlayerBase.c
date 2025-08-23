
modded class PlayerBase
{
    // Add skills data
    protected ref map<string, ref Param2<int, int>> m_Skills; // skillType -> (level, xp)
    
    // Override Init to initialize skills
    override void Init()
    {
        super.Init();
        
        // Initialize skills map
        m_Skills = new map<string, ref Param2<int, int>>();
        
        // Initialize with default values
        array<string> skillTypes = SkillTypes.GetAllTypes();
        foreach (string skillType : skillTypes)
        {
            m_Skills.Set(skillType, new Param2<int, int>(0, 0));
        }
    }
    
    // Get skill level
    int GetSkillLevel(string skillType)
    {
        if (m_Skills && m_Skills.Contains(skillType))
        {
            return m_Skills.Get(skillType).param1;
        }
        return 0;
    }
    
    // Get skill experience
    int GetSkillExperience(string skillType)
    {
        if (m_Skills && m_Skills.Contains(skillType))
        {
            return m_Skills.Get(skillType).param2;
        }
        return 0;
    }
    
    // Set skill data
    void SetSkillData(string skillType, int level, int experience)
    {
        if (m_Skills)
        {
            m_Skills.Set(skillType, new Param2<int, int>(level, experience));
        }
    }
    
    // Update a single skill's data
    void UpdateSkillData(string skillType, int level, int experience)
    {
        SetSkillData(skillType, level, experience);
    }
    
    // Update all skills data from array
    void UpdateSkillsData(array<ref Param3<string, int, int>> skillsData)
    {
        if (skillsData && m_Skills)
        {
            foreach (ref Param3<string, int, int> data : skillsData)
            {
                SetSkillData(data.param1, data.param2, data.param3);
            }
        }
    }
    
    // Add experience to a skill
    void AddSkillExperience(string skillType, int experienceToAdd)
    {
        if (m_Skills && m_Skills.Contains(skillType))
        {
            Param2<int, int> skillData = m_Skills.Get(skillType);
            int currentLevel = skillData.param1;
            int currentExperience = skillData.param2;
            
            // Add experience
            currentExperience += experienceToAdd;
            
            // Check for level up
            PluginSausageSkillsConfig config = PluginSausageSkillsConfig.Cast(GetPlugin(PluginSausageSkillsConfig));
            if (config)
            {
                int requiredXp = config.GetXpForLevel(skillType, currentLevel + 1);
                while (currentExperience >= requiredXp && requiredXp > 0)
                {
                    // Level up
                    currentLevel++;
                    currentExperience -= requiredXp;
                    
                    // Get XP for next level
                    requiredXp = config.GetXpForLevel(skillType, currentLevel + 1);
                    
                    // Notify player of level up
                    if (GetGame().IsClient() || !GetGame().IsMultiplayer())
                    {
                        string skillName = config.GetSkillDisplayName(skillType);
                        // Use a simpler approach to display messages
                        GetGame().Chat(string.Format("You've reached level %1 in %2!", currentLevel, skillName), "");
                    }
                }
            }
            
            // Update skill data
            m_Skills.Set(skillType, new Param2<int, int>(currentLevel, currentExperience));
            
            // Sync to client if on server
            if (GetGame().IsServer())
            {
                SausageSkillsRPCManager.GetRPCManager().SendRPC("SausageSkills", "SyncPlayerSkill", new Param3<string, int, int>(skillType, currentLevel, currentExperience), true, this.GetIdentity());
            }
        }
    }
    
    // Open the skills menu
    void OpenSkillsMenu()
    {
        if (GetGame().IsClient())
        {
            GetGame().GetUIManager().EnterScriptedMenu(MENU_SAUSAGE_SKILLS, null);
        }
    }
    
    // Open the skillbook menu
    void OpenSkillBookMenu(string skillType, string bookTitle, string bookDescription)
    {
        if (GetGame().IsClient())
        {
            // Create and open the skillbook menu
            SkillBookMenu skillBookMenu = SkillBookMenu.Cast(GetGame().GetUIManager().EnterScriptedMenu(MENU_SAUSAGE_SKILLBOOK, null));
            if (skillBookMenu)
            {
                skillBookMenu.SetBookData(skillType, bookTitle, bookDescription);
            }
        }
    }
    
    // Override OnRPC to handle skill-related RPCs
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);
        
        // Handle skill-related RPCs
        if (rpc_type == SausageSkillsRPCCommands.SYNC_PLAYER_SKILLS)
        {
            // Sync all player skills
            ref array<ref Param3<string, int, int>> skillsData;
            if (ctx.Read(skillsData))
            {
                foreach (ref Param3<string, int, int> data : skillsData)
                {
                    SetSkillData(data.param1, data.param2, data.param3);
                }
                
                // Update UI if skills menu is open
                if (GetGame().GetUIManager().IsMenuOpen(MENU_SAUSAGE_SKILLS))
                {
                    SausageSkillsMenu skillsMenu = SausageSkillsMenu.Cast(GetGame().GetUIManager().FindMenu(MENU_SAUSAGE_SKILLS));
                    if (skillsMenu)
                    {
                        skillsMenu.UpdateAllSkills(skillsData);
                    }
                }
            }
        }
        else if (rpc_type == SausageSkillsRPCCommands.UPDATE_SKILL)
        {
            // Update a single skill
            string skillType;
            int level;
            int experience;
            if (ctx.Read(skillType) && ctx.Read(level) && ctx.Read(experience))
            {
                SetSkillData(skillType, level, experience);
                
                // Update UI if skills menu is open
                if (GetGame().GetUIManager().IsMenuOpen(MENU_SAUSAGE_SKILLS))
                {
                    // Use a different variable name to avoid multiple declaration
                    SausageSkillsMenu skillsMenuUI = SausageSkillsMenu.Cast(GetGame().GetUIManager().FindMenu(MENU_SAUSAGE_SKILLS));
                    if (skillsMenuUI)
                    {
                        skillsMenuUI.UpdateSkillData(skillType, level, experience);
                    }
                }
            }
        }
        else if (rpc_type == SausageSkillsRPCCommands.OPEN_SKILLBOOK_MENU)
        {
            // Open the skillbook menu
            // Use a different variable name to avoid multiple declaration
            string bookSkillType;
            string bookTitle;
            string bookDescription;
            if (ctx.Read(bookSkillType) && ctx.Read(bookTitle) && ctx.Read(bookDescription))
            {
                OpenSkillBookMenu(bookSkillType, bookTitle, bookDescription);
            }
        }
    }
}

// Action to open skills menu
class ActionOpenSkillsMenu: ActionInteractBase
{
    // Removed m_CommandUID declaration as it's already defined in ActionInteractBase
    
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
    
    // Changed from OnExecuteClient to StartAction to match ActionInteractBase
    void StartAction(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (player)
        {
            player.OpenSkillsMenu();
        }
    }
}
