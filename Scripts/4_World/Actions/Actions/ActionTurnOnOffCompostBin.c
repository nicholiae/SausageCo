class ActionTurnOnOffCompostBin: ActionInteractBase
{	
	string TooltipText = "#switch_on";
	void ActionTurnOnOffCompostBin()
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
		SausageGarden_CompostBin compostBin = SausageGarden_CompostBin.Cast( targetObject );		
		
		if (compostBin)
		{
			if(compostBin.IsCompostBinOn())
			{
				TooltipText = "#switch_off";
				return true;
			}
			if(!compostBin.IsCompostBinOn() && compostBin.CanCraft())
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
		SausageGarden_CompostBin compostBin = SausageGarden_CompostBin.Cast( targetObject );
		if (compostBin)
		{
			if(compostBin.IsCompostBinOn())
				compostBin.SwitchOffServer();
			if(!compostBin.IsCompostBinOn() && compostBin.CanCraft())
				compostBin.SwitchOnServer();
		}
	}
};