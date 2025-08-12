class ActionTurnOnOffWeedProcessor: ActionInteractBase
{	
	string TooltipText = "#switch_on";
	void ActionTurnOnOffWeedProcessor()
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
		SausageWeed_Processor weedprocessor = SausageWeed_Processor.Cast( targetObject );		
		
		if (weedprocessor)
		{
			if(weedprocessor.IsWeedProcessorOn())
			{
				TooltipText = "#switch_off";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeed())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPounds())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT2())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT2())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT3())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT3())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT4())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT4())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT5())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT5())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT6())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT6())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT7())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT7())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT8())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT8())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT9())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT9())
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
		SausageWeed_Processor weedprocessor = SausageWeed_Processor.Cast( targetObject );
		if (weedprocessor)
		{
			if(weedprocessor.IsWeedProcessorOn())
				weedprocessor.SwitchOffServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeed())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPounds())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT2())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT2())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT3())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT3())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT4())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT4())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT5())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT5())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT6())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT6())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT7())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT7())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT8())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT8())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessWeedT9())
				weedprocessor.SwitchOnServer();
			if(!weedprocessor.IsWeedProcessorOn() && weedprocessor.CanProcessPoundsT9())
				weedprocessor.SwitchOnServer();
		}
	}
};