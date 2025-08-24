
/**
 * SausageCo Skills System
 * Action to read skill books - FIXED VERSION
 */

class ActionReadSkillBookCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(3.0); // 3 seconds to read
    }
}

class ActionReadSkillBook : ActionContinuousBase
{
    void ActionReadSkillBook()
    {
        m_CallbackClass = ActionReadSkillBookCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_VIEWMAP;
        m_FullBody = true;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_Text = "Read";
    }
    
    override void CreateConditionComponents()
    {
        m_ConditionItem = new CCINonRuined;
        m_ConditionTarget = new CCTNone;
    }
    
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        // Check if the item is a skill book
        if (item && item.IsInherited(SausageCo_SkillBook_Base))
        {
            return true;
        }
        
        return false;
    }
    
    override void OnFinishProgressServer(ActionData action_data)
    {
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        if (!player)
            return;
            
        // Get the skill book
        SausageCo_SkillBook_Base skillBook = SausageCo_SkillBook_Base.Cast(action_data.m_MainItem);
        if (!skillBook)
            return;
            
        // Get the skill type from the book
        string skillType = skillBook.GetSkillType();
        
        // Open the skill book menu on the client
        OpenSkillBookMenuOnClient(player, skillType, skillBook.GetBookTitle(), skillBook.GetBookDescription());
    }
    
    void OpenSkillBookMenuOnClient(PlayerBase player, string skillType, string bookTitle, string bookDescription)
    {
        if (!player || !player.GetIdentity())
            return;
            
        // FIX: Send RPC to client using a single Param3 object instead of individual strings
        // This prevents string corruption issues during RPC transmission
        Param3<string, string, string> bookData = new Param3<string, string, string>(skillType, bookTitle, bookDescription);
        
        // Send RPC to client to open the skill book menu
        GetGame().RPCSingleParam(player, SausageSkillsRPCCommands.OPEN_SKILLBOOK_MENU, bookData, true, player.GetIdentity());
    }
}
