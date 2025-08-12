class CfgPatches
{
	class DZ_SausageGarage_TrashCan_Item
	{
		units[]={
			"SausageGarage_TrashCan"
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
	class SausageGarage_TrashCan: Container_Base
	{
		scope=2;
		displayName="SausageCo TrashCan";
		model="DZ\structures_bliss\residential\misc\garbage_bin2.p3d";
		descriptionShort="TrashCan for your trash ass back at base.";
		itemSize[]={13,11};
		weight=1200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=1;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,10};
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
	class SausageGarage_TrashCan_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "TrashCan HOLO";
		model="DZ\structures_bliss\residential\misc\garbage_bin2.p3d";
	};
};