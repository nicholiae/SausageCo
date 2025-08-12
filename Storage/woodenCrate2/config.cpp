class CfgPatches
{
	class DZ_SausageBuilding_CrateWood2
	{
		units[]={
			"SausageBuilding_CrateWood2"
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
	class SausageCrateWood2_Storage: Container_Base
	{
		scope=2;
		displayName="Medium Crate Storage";
		model="DZ\structures_bliss\residential\misc\misc_woodencrate_3x.p3d";
		descriptionShort="Basebuilding medium storage crate. Created by Nicholiae.";
		itemSize[]={14,14};
		weight=900;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=0;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,60};
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
	class SausageCrateWood2_Storage_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Building Crate HOLO";
		model="DZ\structures_bliss\residential\misc\misc_woodencrate_3x.p3d";
	};
};