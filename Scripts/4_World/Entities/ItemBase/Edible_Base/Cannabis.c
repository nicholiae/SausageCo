modded class Cannabis : Edible_Base
{
	override bool CanBeCooked()
	{
		return false;
	}		
	
	override bool CanBeCookedOnStick()
	{
		return false;
	}	
	
	override bool IsFruit()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEatSmall);
	}
}
class BasicCannabis : Edible_Base
{
	override bool CanBeCooked()
	{
		return false;
	}		
	
	override bool CanBeCookedOnStick()
	{
		return false;
	}	
	
	override bool IsFruit()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEatSmall);
	}
}
class SC_CaninaBerry : Edible_Base
{
	override bool CanBeCooked()
	{
		return false;
	}		
	
	override bool CanBeCookedOnStick()
	{
		return false;
	}	
	
	override bool IsFruit()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEatSmall);
	}
}
class SC_SambucusBerry : Edible_Base
{
	override bool CanBeCooked()
	{
		return false;
	}		
	
	override bool CanBeCookedOnStick()
	{
		return false;
	}	
	
	override bool IsFruit()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEatSmall);
	}
}
class SC_Kiwi : SC_SambucusBerry {};
class SC_Potato : SC_SambucusBerry {};
class SC_Orange : SC_SambucusBerry {};
class SC_Banana : SC_SambucusBerry {};
class SC_Pear : SC_SambucusBerry {};
class SC_Plum : SC_SambucusBerry {};
class SC_Apple : SC_SambucusBerry {};
class SC_Joint_base : Edible_Base 
{
	
	//Specify this item can only be combined but not split
	override void InitItemVariables()
	{
		super.InitItemVariables();

		can_this_be_combined = true;
	}
	
	override void OnConsume(float amount, PlayerBase consumer)
	{
		if (consumer.GetModifiersManager().IsModifierActive(eModifiers.MDF_IMMUNITYBOOST)) //effectively resets the timer
		{
			consumer.GetModifiersManager().DeactivateModifier(eModifiers.MDF_IMMUNITYBOOST);
		}

		consumer.GetModifiersManager().ActivateModifier(eModifiers.MDF_IMMUNITYBOOST);
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEatSmall);
	}
	
};
class SC_Blunt_base : SC_Joint_base {};

