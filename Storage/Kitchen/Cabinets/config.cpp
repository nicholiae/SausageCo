class CfgPatches
{
	class DZ_SausageKitchen_Cabinets
	{
		units[]={
			"SausageKitchen_Cabinets"
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
	class SausageKitchen_Cabinets: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Cabinets";
		model="\DZ\structures\furniture\various\kitchen_unit_a_dz.p3d";
		descriptionShort="A Cabinet for all your food storage needs.";
		overrideDrawArea="3.0";
		slopeTolerance=0.30000001;
		lootCategory="Crafted";
		itemSize[]={10,15};
		weight=10000;
		itemBehaviour=0;
		quantityBar=0;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		stackedUnit="";
		attachments[]=
		{	
				
		};
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		canBeDigged=0;
		physLayer="item_large";
		class GUIInventoryAttachmentsProps
		{
			
		};
		hiddenSelections[]=
		{
			
		};
		class Cargo
		{
			itemsCargoSize[]={10,15};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		class AnimEvents
		{
		
		};
	};
	class SausageKitchen_Cabinets_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "SausageCo Cabinets HOLO";
		model="\DZ\structures\furniture\various\kitchen_unit_a_dz.p3d";
	};
};