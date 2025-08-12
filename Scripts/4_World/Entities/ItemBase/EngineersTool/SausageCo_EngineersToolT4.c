class SausageCo_EngineersToolT4 extends ToolBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionRepairPart);
		AddAction(ActionMineTree);
		AddAction(ActionMineBush);
		AddAction(ActionBuildPart);
		AddAction(ActionDismantlePart);
		AddAction(ActionDestroyPart);
		AddAction(ActionSawPlanks);
		AddAction(ActionUnrestrainTarget);
	}
	bool isBBPAdminTool()
	{
		return true;
	}
}