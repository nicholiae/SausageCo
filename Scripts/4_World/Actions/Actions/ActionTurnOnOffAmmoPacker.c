class ActionTurnOnOffAmmoPacker: ActionInteractBase
{	
	string TooltipText = "#switch_on";
	void ActionTurnOnOffAmmoPacker()
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
		SausageAmmo_Packer ammoPacker = SausageAmmo_Packer.Cast( targetObject );		
		
		if (ammoPacker)
		{
			if(ammoPacker.IsAmmoPackerOn())
			{
				TooltipText = "#switch_off";
				return true;
			}
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo45())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo22())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo357())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo9x39())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo9x19())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo380())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo545x39())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo556x45())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo762x39())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo762x54())
			{
				TooltipText = "#switch_on";
				return true;
			}
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo308Win())
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
		SausageAmmo_Packer ammoPacker = SausageAmmo_Packer.Cast( targetObject );
		if (ammoPacker)
		{
			if(ammoPacker.IsAmmoPackerOn())
				ammoPacker.SwitchOffServer();
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo45())
				ammoPacker.SwitchOnServer();
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo22())
				ammoPacker.SwitchOnServer();
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo357())
				ammoPacker.SwitchOnServer();
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo9x39())
				ammoPacker.SwitchOnServer();
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo9x19())
				ammoPacker.SwitchOnServer();
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo380())
				ammoPacker.SwitchOnServer();
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo545x39())
				ammoPacker.SwitchOnServer();
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo556x45())
				ammoPacker.SwitchOnServer();
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo762x39())
				ammoPacker.SwitchOnServer();
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo762x54())
				ammoPacker.SwitchOnServer();
			if(!ammoPacker.IsAmmoPackerOn() && ammoPacker.CanProcessAmmo308Win())
				ammoPacker.SwitchOnServer();
		}
	}
};