class ChefsMeal : Edible_Base
{
	override bool CanBeCooked()
	{
		return false;
	}		
	
	override bool CanBeCookedOnStick()
	{
		return false;
	}	
	
	override bool IsMeat()
	{
		return true;
	}
	override bool CanDecay()
	{
		return false;
	}
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEatMeat);
	}
}
class ChefsMealT1 : ChefsMeal {};
class ChefsMealT2 : ChefsMeal {};
class ChefsMealT3 : ChefsMeal {};
class ChefsMealT4 : ChefsMeal {};