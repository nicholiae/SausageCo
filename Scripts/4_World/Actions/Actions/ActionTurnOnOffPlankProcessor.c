class ActionTurnOnOffPlankProcessor: ActionInteractBase
{	
	string TooltipText = "#switch_on";
	void ActionTurnOnOffPlankProcessor()
	{
	}

	override string GetText()
	{
		return TooltipText;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if(!targetObject)
			return false;
		SausagePlank_Processor plankProcessor = SausagePlank_Processor.Cast( targetObject );		
		
		if (plankProcessor)
		{
			if(plankProcessor.IsPlankProcessorOn())
			{
				TooltipText = "#switch_off";
				return true;
			}
			if(!plankProcessor.IsPlankProcessorOn() && plankProcessor.CanProcessLogs())
			{
				TooltipText = "#switch_on";
				return true;
			}
		}
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		SausagePlank_Processor plankProcessor = SausagePlank_Processor.Cast( targetObject );
		if (plankProcessor)
		{
			if(plankProcessor.IsPlankProcessorOn())
				plankProcessor.SwitchOffServer();
			if(!plankProcessor.IsPlankProcessorOn() && plankProcessor.CanProcessLogs())
				plankProcessor.SwitchOnServer();
		}
	}
};