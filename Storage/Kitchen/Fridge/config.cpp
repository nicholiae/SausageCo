class CfgPatches
{
	class DZ_SausageKitchen_Fridge
	{
		units[]={
			"SausageKitchen_Fridge"
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
	class Container_Base;
	class SC_Fridge_Base: Container_Base
	{
		hasCargoRestrictions=1;
		class EnergyManager
		{
			hasIcon=1;
			powerSocketsCount=1;
			energyUsagePerSecond=0.029999999;
			cordTextureFile="DZ\gear\camping\Data\plug_black_CO.paa";
			cordLength=5;
			plugType=2;
			updateInterval=5;
		};
		class AnimationSources
		{
			class Doors1
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class Doors2
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class Doors3
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
			class Doors4
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
	};
	class SausageKitchen_Fridge: SC_Fridge_Base
	{
		scope=2;
		displayName="SausageCo Fridge";
		model="\DZ\structures\furniture\kitchen\fridge\fridge.p3d";
		descriptionShort="A Fridge for all your cold food storage needs";
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
			itemsCargoSize[]={10,20};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		class AnimEvents
		{
			
		};
	};
	class SausageKitchen_Fridge_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "SausageCo Fridge HOLO";
		model="\DZ\structures\furniture\kitchen\fridge\fridge.p3d";
	};
};