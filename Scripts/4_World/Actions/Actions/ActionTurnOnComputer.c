class ActionTurnOnComputer: ActionInteractBase
{	
	void ActionTurnOnComputer()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
	}

	override string GetText()
	{
		return "#switch_on";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		SausageOffice_Computer target_PG = SausageOffice_Computer.Cast( targetObject );

		float c_index = target.GetComponentIndex();		
		
		if ( target_PG.GetCompEM().CanSwitchOn()  &&  target_PG.HasSparkplug())
		{
			return true;
		}
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if (targetObject)
		{
			ItemBase target_IB = ItemBase.Cast( targetObject );
			target_IB.GetCompEM().SwitchOn();
		}
	}
};