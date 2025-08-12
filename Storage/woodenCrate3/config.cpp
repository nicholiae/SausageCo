class CfgPatches
{
	class DZ_SausageBuilding_CrateWood3
	{
		units[]={
			"SausageBuilding_CrateWood3"
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
	class SausageCrateWood3_Storage: Container_Base
	{
		scope=2;
		displayName="Large Crate Storage";
		model="DZ\structures_bliss\residential\misc\misc_woodencrate_5x.p3d";
		descriptionShort="Basebuilding large storage crate. Created by Nicholiae.";
		itemSize[]={16,16};
		weight=1500;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=0;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,100};
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
	class SausageCrateWood3_Storage_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Building Crate HOLO";
		model="DZ\structures_bliss\residential\misc\misc_woodencrate_5x.p3d";
	};
};