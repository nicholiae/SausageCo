class CfgPatches
{
	class DZ_SausageKitchen_Sink
	{
		units[]={
			"SausageKitchen_Sink"
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
	class SausageKitchen_Sink: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Sink";
		model="\DZ\structures\furniture\kitchen\case_sink_a\case_sink_a.p3d";
		descriptionShort="A Kitchen Sink, so you can wash dishes. No not really, you just fill shit up and wash your hands! Who the fuck washes dishes in the apocolypse?";
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
			"ashes",
			"camoGround",
			"inventory"
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		class AnimEvents
		{
			
		};
	};
	class SausageKitchen_Sink_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "SausageCo Sink HOLO";
		model="\DZ\structures\furniture\kitchen\case_sink_a\case_sink_a.p3d";
	};
};