

/**
 * SausageCo Skills System
 * Action to read skill books - UPDATED VERSION with Skill Book Type and Debug Logging
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
        Print("[SausageCo] ActionReadSkillBook: OnFinishProgressServer called");
        
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        if (!player)
        {
            Print("[SausageCo] ActionReadSkillBook: Player is null");
            return;
        }
            
        // Get the skill book
        SausageCo_SkillBook_Base skillBook = SausageCo_SkillBook_Base.Cast(action_data.m_MainItem);
        if (!skillBook)
        {
            Print("[SausageCo] ActionReadSkillBook: Skill book is null");
            return;
        }
            
        // Get the skill type from the book
        string skillType = skillBook.GetSkillType();
        
        // Get the actual skill book type/class name
        string skillBookType = skillBook.GetType();
        
        Print("[SausageCo] ActionReadSkillBook: Reading skill book - Type: " + skillBookType + ", Skill: " + skillType);
        
        // Open the skill book menu on the client with the skill book type
        OpenSkillBookMenuOnClient(player, skillType, skillBook.GetBookTitle(), skillBook.GetBookDescription(), skillBookType);
    }
    
    void OpenSkillBookMenuOnClient(PlayerBase player, string skillType, string bookTitle, string bookDescription, string skillBookType)
    {
        if (!player || !player.GetIdentity())
        {
            Print("[SausageCo] ActionReadSkillBook: Player or identity is null");
            return;
        }
            
        Print("[SausageCo] ActionReadSkillBook: Opening skill book menu on client - Type: " + skillBookType + ", Skill: " + skillType);
        
        // Send RPC to client using a Param4 object to include the skill book type
        Param4<string, string, string, string> bookData = new Param4<string, string, string, string>(skillType, bookTitle, bookDescription, skillBookType);
        
        // Send RPC to client to open the skill book menu
        GetGame().RPCSingleParam(player, SausageSkillsRPCCommands.OPEN_SKILLBOOK_MENU, bookData, true, player.GetIdentity());
        
        Print("[SausageCo] ActionReadSkillBook: RPC sent to client");
    }
}
