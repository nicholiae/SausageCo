class CfgPatches
{
	class DZ_SausageBuilding_CrateWood1
	{
		units[]={
			"SausageBuilding_CrateWood1"
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
	class SausageCrateWood1_Storage: Container_Base
	{
		scope=2;
		displayName="Small Crate Storage";
		model="DZ\structures_bliss\residential\misc\misc_woodencrate.p3d";
		descriptionShort="Basebuilding small storage crate. Created by Nicholiae.";
		itemSize[]={12,12};
		weight=300;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=0;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,20};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			
		};
		class GUIInventoryAttachmentsProps
		{
			
		};
	};
	class SausageCrateWood1_Storage_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Crate Storage HOLO";
		model="DZ\structures_bliss\residential\misc\misc_woodencrate.p3d";
	};
};