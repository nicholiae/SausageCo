class ActionSCVSRestoreContents: ActionInteractBase
{
	void ActionSCVSRestoreContents()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
	}

    override typename GetInputType()
    {
        return ContinuousInteractActionInput;
    }

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
	
		SC_ItemBase SCitembase = SC_ItemBase.Cast(target.GetObject());
		if(SCitembase)
		{
			#ifdef CodeLock
				if(SCitembase.IsCodeLocked())
					return false;
			#endif
			#ifdef RA_BASEBUILDING
				if(SCitembase.IsCodeLocked(player.GetIdentity()))
					return false;
			#endif
			if(!SCitembase.CanDoVSRestoreAction())
			{
				return false;
			}

			if(!SCitembase.SC_CanBeOpenedOrRestored())
			{
				return false;
			}

			if(SCitembase.HasStoredCargo())
			{
				m_Text = "Restore contents";
				return true;
			}			
		}
		return false;
	}
	
	override void OnStartServer( ActionData action_data )
	{
		SC_ItemBase SCitembase = SC_ItemBase.Cast(action_data.m_Target.GetObject());
		if(SCitembase)
		{			
			SCitembase.RestoreSCInventory(action_data.m_Player);
		}
	}
};