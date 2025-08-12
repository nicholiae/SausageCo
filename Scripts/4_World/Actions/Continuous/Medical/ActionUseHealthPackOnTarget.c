class ActionUseHealthPackOnTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.SALINE);
	}
};
class ActionUseHealthPackOnTarget: ActionContinuousBase
{   
	void ActionUseHealthPackOnTarget()
	{
		m_CallbackClass = ActionUseHealthPackOnTargetCB;
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
		return "Fix Player Leg";
	}
	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		Param1<float> nacdata = Param1<float>.Cast( action_data.m_ActionComponent.GetACData() );
		float delta = nacdata.param1;

		ntarget.AddHealth("RightLeg", "Health", 100);
		ntarget.AddHealth("LeftLeg", "Health", 100);
		ntarget.AddHealth("GlobalHealth", "Health", -12);
		ntarget.AddHealth("GlobalHealth", "Blood", 225);
		ntarget.GetModifiersManager().ActivateModifier(eModifiers.MDF_SALINE);

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		// action_data.m_MainItem.Delete();
	}
};
