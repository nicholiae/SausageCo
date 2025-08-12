class ActionFillGardenBox: ActionInteractBase
{
	void ActionFillGardenBox()
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

	override string GetText()
	{
		return "Fill With Dirt";
	}
	
	override void OnStartServer( ActionData action_data )
	{
		SausageCo_EmptyGardenBox emptyGardenBox = SausageCo_EmptyGardenBox.Cast( action_data.m_Target.GetObject() );

		if ( emptyGardenBox )
		{
			vector pos = emptyGardenBox.GetPosition();
			vector ori = emptyGardenBox.GetOrientation();
			Object myGardenBox = GetGame().CreateObject(emptyGardenBox.Get_FullGardenBox(), pos, false );
			myGardenBox.SetPosition( pos );
			myGardenBox.SetOrientation( ori );
            emptyGardenBox.Delete();
		}
	}
};