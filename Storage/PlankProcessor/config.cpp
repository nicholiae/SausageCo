class CfgPatches
{
	class DZ_SausagePlank_Processor
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
class CfgSlots
{
	class Slot_Material_Processor_WoodenPlanks
	{
		name="Material_Processor_WoodenPlanks";
		displayName="Wooden planks";
		selection="material_processor_woodenplanks";
		ghostIcon="planks";
		stackMax=300;
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class SausagePlank_Processor: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Plank Processor";
		model="\DZ\structures\furniture\various\soustruh_proxy.p3d";
		descriptionShort="Used for Processing Logs into Planks";
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
			"Material_L1_WoodenLogs",
			"Material_Processor_WoodenPlanks"
			
		};
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		canBeDigged=0;
		physLayer="item_large";
		class GUIInventoryAttachmentsProps
		{
			class Log_Storage
			{
				name="Log Storage";
				description="";
				attachmentSlots[]=
				{
					"Material_L1_WoodenLogs"
				};
				icon="woodenlog";
			};
			class Plank_Storage
			{
				name="Plank Storage";
				description="";
				attachmentSlots[]=
				{
					"Material_Processor_WoodenPlanks"
				};
				icon="planks";
			};
		};
		hiddenSelections[]=
		{
			
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
	class SausagePlank_Processor_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "Plank HOLO";
		model="\DZ\structures\furniture\various\soustruh_proxy.p3d";
	};
};