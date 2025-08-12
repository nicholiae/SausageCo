class SausageCo_MedicsToolT4 extends Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionFixBrokenLeg);
		AddAction(ActionFixTargetBone);
		AddAction(ActionGiveHealthTarget);
		AddAction(ActionGiveHealthSelf);
	}
}