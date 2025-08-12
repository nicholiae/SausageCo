class CfgPatches
{
	class DZ_SausageBuilding_Sign1
	{
		units[]={
			"SausageBuilding_Sign1"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Structures",
			"DZ_Scripts"
		};
	};
};
class CfgVehicles
{
	class Container_Base;
	class SausageBuilding_Sign1: Container_Base
	{
		scope=2;
		displayName="BaseSign# 2";
		model = "SausageCo\storage\data\fatbillboard3.p3d";
		descriptionShort="Can be deployed into a sign that says 'Open for Trade, Holster all weapons, Hands Up, Call out 'Looking to Trade', we come to you'. Created by Nicholiae.";
		hiddenSelections[]=
		{
			"panel",
			"bags",
			"camo",
			"xlights_glass_r",
			"xlights_glass_g",
			"xlights_glass_b",
			"xlights_glass_y"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\data\Addons\TradingOpen.paa"
		};
		itemSize[]={12,20};
		weight=3200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=0;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={6,5};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"CamoNet",
			"Lights"
			
		};
		class GUIInventoryAttachmentsProps
		{
			class ChristmasLights
			{
				name="ChristmasLights";
				description="";
				attachmentSlots[]=
				{
					"CamoNet",
					"Lights"
				};
				icon="christmaslights";
			};
		};
	};
	class SausageBuilding_Sign1_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "BaseSign HOLO";
		model="SausageCo\storage\data\fatbillboard3.p3d";
	};
};