class ActionGiveHealthTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.SALINE);
	}
};
class ActionGiveHealthTarget: ActionContinuousBase
{   
	void ActionGiveHealthTarget()
	{
		m_CallbackClass = ActionGiveHealthTargetCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(5);	
	}	
	override string GetText()
	{
		return "Heal Player";
	}
	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		Param1<float> nacdata = Param1<float>.Cast( action_data.m_ActionComponent.GetACData() );
		float delta = nacdata.param1;

		ntarget.AddHealth("GlobalHealth", "Health", 35);
		ntarget.AddHealth("GlobalHealth", "Blood", 500);
		ntarget.GetModifiersManager().ActivateModifier(eModifiers.MDF_SALINE);

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		// action_data.m_MainItem.Delete();
	}
};
