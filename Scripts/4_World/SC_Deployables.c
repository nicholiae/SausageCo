class SC_Deployables : ItemBase
{
    override bool CanPutInCargo( EntityAI parent )
	{
        return true;
    }
    override bool CanPutIntoHands( EntityAI parent )
    {
        return true;
    }

	override void SetActions()
	{
		super.SetActions();
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
};

class SC_TrophyBase : SC_Deployables
{
	
};