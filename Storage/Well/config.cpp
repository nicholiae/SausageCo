class CfgPatches
{
	class DZ_SausageWell_Storage
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
	class HouseNoDestruct;
	class House;
	class SausageBuilding_Well: Inventory_Base
	{
		scope=2;
		displayName="Old SausageWell";
		model="\DZ\structures\residential\misc\misc_well_pump_blue.p3d";
		descriptionShort="A really simple well, can be used to fill your water containers or drink and wash your hands. Created by Nicholiae.";
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
	class SausageBuilding_Well_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "SasuageWell HOLO";
		model="\DZ\structures\residential\misc\misc_well_pump_blue.p3d";
	};
	class SausageBuilding_GasPump: Inventory_Base
	{
		scope=2;
		displayName="Old GasPump";
		model="\DZ\structures\specific\fuelstation\fuelstation_feed.p3d";
		descriptionShort="A really simple Gaspump.";
		itemsCargoSize[]={10,10};
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
	class SausageBuilding_GasPump_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "SasuageGaspump HOLO";
		model="\DZ\structures\specific\fuelstation\fuelstation_feed.p3d";
	};
};