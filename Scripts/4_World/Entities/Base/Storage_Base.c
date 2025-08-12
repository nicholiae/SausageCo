class SC_Storage_Base: SC_ItemBase 
{   
    override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		ShowHideSCProxies();
	}
    
	override bool CanPutInCargo( EntityAI parent )
    {
		if( !super.CanPutInCargo(parent) ) {return false;}
        return IsSCInvEmpty();
    }
    
    override bool CanPutIntoHands(EntityAI parent)
	{
		if( !super.CanPutIntoHands(parent) ) {return false;}
		return IsSCInvEmpty();		
    } 

	override bool IsContainer()
	{
		return true;
	}
    
    override bool IsDeployable() 
    {
        return true;
    }   
    
    override void OnInventoryEnter(Man player)
    {
        super.OnInventoryEnter(player);
        GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);        
    }
    
    override void OnInventoryExit(Man player)
    {
        super.OnInventoryExit(player);
        GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);        
    }

    override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
};

class SC_InventoryStorage_Base: SC_ItemBase 
{
	override bool CanStoreCargo()
	{
		return false;
	}

	override bool AreChildrenAccessible()
	{
		return true;
	}

    override bool IsDeployable() 
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