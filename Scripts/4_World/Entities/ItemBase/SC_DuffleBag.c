class SC_DuffleBag extends Container_Base 
{
	
	override bool CanPutInCargo(EntityAI parent)
	{
		return true;
	}
	
	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		return true;
	}
	
};