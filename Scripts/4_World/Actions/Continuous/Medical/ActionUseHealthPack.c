class ActionUseHealthPackCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.SALINE);
	}
};
class ActionUseHealthPack : ActionContinuousBase
{   
	void ActionUseHealthPack()
	{
		m_CallbackClass = ActionUseHealthPackCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}
	override bool HasTarget()
	{
		return false;
	}
	override string GetText()
	{
		return "Fix own Leg";
	}	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		action_data.m_MainItem.TransferModifiers(action_data.m_Player);
		Param1<float> nacdata = Param1<float>.Cast( action_data.m_ActionComponent.GetACData() );		
		float delta = nacdata.param1;
		action_data.m_Player.AddHealth("RightLeg", "Health", 100);
		action_data.m_Player.AddHealth("LeftLeg", "Health", 100);
		action_data.m_Player.AddHealth("GlobalHealth", "Health", -12);
		action_data.m_Player.AddHealth("GlobalHealth", "Blood", 225);
		action_data.m_Player.GetModifiersManager().ActivateModifier(eModifiers.MDF_SALINE);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		// action_data.m_MainItem.Delete();
	}
};
