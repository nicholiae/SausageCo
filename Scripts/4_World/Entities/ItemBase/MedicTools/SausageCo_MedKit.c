class SausageCo_MedKit extends Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionUseHealthPackOnTarget);
		AddAction(ActionUseHealthPack);
	}
}
class SausageCo_FirstAidKit extends Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionUseHealthPackOnTarget);
		AddAction(ActionUseHealthPack);
	}
}