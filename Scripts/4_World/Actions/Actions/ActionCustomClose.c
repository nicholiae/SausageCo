class ActionCustomClose: ActionInteractBase
{
	void ActionCustomClose()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.CloseDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
	}

	override string GetText()
	{
		return "#close";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;

		if(!IsInReach(player, target, UAMaxDistances.DEFAULT)) return false;

		string selection = target.GetObject().GetActionComponentName(target.GetComponentIndex());
		if(selection && selection == "lever")
			return false;	
		SC_ItemBase SCitembase = SC_ItemBase.Cast(target.GetObject());
		if(SCitembase)			
			return SCitembase.IsOpen();
			
		return false;
	}

	override void OnStartServer( ActionData action_data )
	{
		SC_ItemBase SCitembase = SC_ItemBase.Cast(action_data.m_Target.GetObject());
		if(SCitembase)		
		{						
		#ifdef SERVER
			if(SCitembase.IsSCAutoStoreOnCloseEnabled())
			{
				if(SCitembase.CanStoreCargo())
				{
					SCitembase.StoreSCInventory(action_data.m_Player);
				}
			}
		#endif
			SCitembase.Close();
		}
	}
};