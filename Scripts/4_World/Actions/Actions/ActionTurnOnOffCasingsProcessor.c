class ActionTurnOnOffCasingsProcessor: ActionInteractBase
{	
	string TooltipText = "#switch_on";
	void ActionTurnOnOffCasingsProcessor()
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
		SausageCo_CasingsProcessor casingsProcessor = SausageCo_CasingsProcessor.Cast( targetObject );		
		
		if (casingsProcessor)
		{
			if(casingsProcessor.IsCasingsProcessorOn())
			{
				TooltipText = "#switch_off";
				return true;
			}
			if(!casingsProcessor.IsCasingsProcessorOn() && casingsProcessor.CanProcessCasings())
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
		SausageCo_CasingsProcessor casingsProcessor = SausageCo_CasingsProcessor.Cast( targetObject );
		if (casingsProcessor)
		{
			if(casingsProcessor.IsCasingsProcessorOn())
				casingsProcessor.SwitchOffServer();
			if(!casingsProcessor.IsCasingsProcessorOn() && casingsProcessor.CanProcessCasings())
				casingsProcessor.SwitchOnServer();
		}
	}
};