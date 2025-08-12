class ActionTurnOnOffFurnace: ActionInteractBase
{	
	string TooltipText = "#switch_on";
	void ActionTurnOnOffFurnace()
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
		SausageFurnace sausagefurnace = SausageFurnace.Cast( targetObject );		
		
		if (sausagefurnace)
		{
			if(sausagefurnace.IsFurnaceOn())
			{
				TooltipText = "#switch_off";
				return true;
			}
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftBase())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftSilver())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftCopper())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftGold())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftPresem())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftRune())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftBlood())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftJade())
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
		SausageFurnace sausagefurnace = SausageFurnace.Cast( targetObject );
		if (sausagefurnace)
		{
			if(sausagefurnace.IsFurnaceOn())
				sausagefurnace.SwitchOffServer();
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftBase())
				sausagefurnace.SwitchOnServer();
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftGold())
				sausagefurnace.SwitchOnServer();
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftSilver())
				sausagefurnace.SwitchOnServer();
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftCopper())
				sausagefurnace.SwitchOnServer();
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftJade())
				sausagefurnace.SwitchOnServer();
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftBlood())
				sausagefurnace.SwitchOnServer();
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftPresem())
				sausagefurnace.SwitchOnServer();
			if(!sausagefurnace.IsFurnaceOn() && sausagefurnace.CanCraftRune())
				sausagefurnace.SwitchOnServer();
		}
	}
};