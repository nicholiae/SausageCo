class CfgPatches
{
	class DZ_SausageBuilding_Sign2
	{
		units[]={
			"SausageBuilding_Sign2"
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
	class SausageBuilding_Sign2: Container_Base
	{
		scope=2;
		displayName="TraderSign# 1";
		model = "SausageCo\storage\data\fatbillboard3.p3d";
		descriptionShort="Used as a prop for trader locations. Created by Nicholiae.";
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
			"SausageCo\storage\data\Addons\TradeDistrict.paa"
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
	class SausageBuilding_SignKind: SausageBuilding_Sign2
	{
		scope=2;
		displayName="TraderSign: kind";
		model = "SausageCo\storage\data\fatbillboard3.p3d";
		descriptionShort="Used as a warning / extension of kindness to passbyers. Created by Nicholiae.";
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
			"SausageCo\storage\data\Addons\KindSign.paa"
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
	class SausageBuilding_Sign2_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "TraderSign HOLO";
		model="SausageCo\storage\data\fatbillboard3.p3d";
	};
	class SausageBuilding_SignKind_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "TraderSign HOLO";
		model="SausageCo\storage\data\fatbillboard3.p3d";
	};
};