class CfgPatches
{
	class DZ_SausageBase_Storage
	{
		units[]={
			"Storage"
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
	class Inventory_Base;
	class SausageBuilding_Statue: Inventory_Base
	{
		scope=2;
		displayName="Sausage Statue";
		model="nichosassets\assets\sausagestatue.p3d";
		descriptionShort="Show your patriotic side and tell everyone you support the sausage!";
		itemsCargoSize[]={0,0};
		canBeDigged=0;
		overrideDrawArea="8.0";
		placement="ForceSlopeOnTerrain";		
		destroyOnEmpty=0;
		quantityBar=0;
		varQuantityMax=0;
		carveNavmesh=1;
		heavyItem=1;
		weight=10000;
		itemBehaviour=0;
		physLayer="item_large";
		allowOwnedCargoManipulation=1;
		attachments[]=
		{	
			
		};
		class GUIInventoryAttachmentsProps
		{
			
		};
	};
	class SausageBuilding_Statue_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "Statue HOLO";
		model="nichosassets\assets\sausagestatue.p3d";
	};
};