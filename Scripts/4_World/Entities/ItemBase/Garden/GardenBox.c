class SausageCo_EmptyGardenBox : ItemBase
{
	string Get_FullGardenBox() { return "SausageCo_GardenBox"; }
	override bool IsDeployable()
	{
		return true;
	}	

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionFillGardenBox);
	}
};

class SausageCo_GardenBox_Base : GardenPlot
{

	string Get_EmptyGardenBox() { return "SausageCo_EmptyGardenBox"; }
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
		PlayerBase player_base = PlayerBase.Cast(player);
		if (GetGame().IsMultiplayer() && GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			if (m_ClutterCutter)
			{
				GetGame().ObjectDelete(m_ClutterCutter);
				m_ClutterCutter = NULL;
			}

			if (!m_ClutterCutter)
			{
				m_ClutterCutter = GetGame().CreateObject("ClutterCutter2x2", position, false);
				m_ClutterCutter.SetOrientation(orientation);
			}
		}
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionEmptyGardenBox);
	}
	
};

class SausageCo_GardenBox : SausageCo_GardenBox_Base
{	
	override string Get_EmptyGardenBox() { return "SausageCo_EmptyGardenBox"; }
	void SausageCo_GardenBox()
	{
		SetBaseFertility(0.75);
	}
	
	override bool IsInventoryVisible()
	{
		return true;
	}

	override int GetGardenSlotsCount()
	{
		return 3;
	}

	override void RefreshSlots()
	{
		HideSelection("SeedBase_1");
		HideSelection("SeedBase_2");
		HideSelection("SeedBase_3");
	}	
	
	override void SetActions()
	{
		super.SetActions();		
		AddAction(ActionEmptyGardenBox);
	}
};
