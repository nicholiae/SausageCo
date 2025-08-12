class ActionEmptyGardenBox: ActionInteractBase
{
	void ActionEmptyGardenBox()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );	

		if ( target_entity && target_entity.GetInventory().AttachmentCount() == 0 )	
		{
			return true;
		}
		
		return false;
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override string GetText()
	{
		return "Empty Garden box";
	}
	
	override void OnStartServer( ActionData action_data )
	{
		SausageCo_GardenBox_Base fullGardenBox = SausageCo_GardenBox_Base.Cast( action_data.m_Target.GetObject() );

		if ( fullGardenBox )
		{
			vector pos = fullGardenBox.GetPosition();
			vector ori = fullGardenBox.GetOrientation();
			Object myGardenBox = GetGame().CreateObject(fullGardenBox.Get_EmptyGardenBox(), pos, false );
			myGardenBox.SetPosition( pos );
			myGardenBox.SetOrientation( ori );
            fullGardenBox.Delete();
		}
	}
};