class ActionCustomOpen: ActionInteractBase
{
	void ActionCustomOpen()
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

	override string GetText()
	{
		return "#open";
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
		{
			if(SCitembase.IsKindOf("SC_MedievalGibbet") && !SCitembase.IsSCFacingPlayer(player))
				return false;
			
			#ifdef CodeLock
				if(SCitembase.IsCodeLocked())
					return false;
			#endif
			#ifdef RA_BASEBUILDING
				if(SCitembase.IsCodeLocked(player.GetIdentity()))
					return false;
			#endif
			
			if(!SCitembase.IsOpen() && SCitembase.SC_CanBeOpenedOrRestored())
			{
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
		#ifdef SERVER
			if(SCitembase.IsSCVirtualStorageEnabled())
			{
				SCitembase.RestoreSCInventory(action_data.m_Player);
			}
		#endif
			SCitembase.Open();
		}
	}
};