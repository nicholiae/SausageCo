class CfgPatches
{
	class DZ_SausageOffice_Shelves
	{
		units[]={
			"SausageOffice_Shelves"
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
	class SausageOffice_Shelves: Container_Base
	{
		scope=2;
		displayName="SausageCo Shelves";
		model="\DZ\structures\furniture\cases\case_wall_unit_part_c.p3d";
		descriptionShort="Shelves for your office back at base.";
		itemSize[]={13,11};
		weight=1200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=1;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,30};
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
	class SausageOffice_Shelves_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Shelves HOLO";
		model="\DZ\structures\furniture\cases\case_wall_unit_part_c.p3d";
	};
};