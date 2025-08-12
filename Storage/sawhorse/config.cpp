class CfgPatches
{
	class DZ_SausageBuilding_Storage
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
	class Slot_Shoulder1
	{
		name="Shoulder1";
		displayName="Shoulder1";
		ghostIcon="Shoulder";
		show="true";
	};
	class Slot_Shoulder2
	{
		name="Shoulder2";
		displayName="Shoulder2";
		ghostIcon="Shoulder";
		show="true";
	};
	class Slot_Shoulder3
	{
		name="Shoulder3";
		displayName="Shoulder3";
		ghostIcon="Shoulder";
		show="true";
	};
	class Slot_Shoulder4
	{
		name="Shoulder4";
		displayName="Shoulder4";
		ghostIcon="Shoulder";
		show="true";
	};
	class Slot_Shoulder5
	{
		name="Shoulder5";
		displayName="Shoulder5";
		ghostIcon="Shoulder";
		show="true";
	};
	
};
class CfgVehicles
{
	class Container_Base;
	class SausageBuilding_Storage: Container_Base
	{
		scope=2;
		displayName="Building Material Storage";
		model="DZ\structures\furniture\Various\sawhorse_DZ.p3d";
		descriptionShort="Basebuilding material storage. Created by Nicholiae.";
		itemSize[]={12,10};
		weight=1200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=0;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,50};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"Material_WoodenLogs",
			"Material_L1_WoodenLogs",
			"Material_L2_WoodenLogs",
			"Material_L3_WoodenLogs",
			"Material_WoodenPlanks",
			"Material_L3_WoodenPlanks",
			"Material_L1W1_WoodenPlanks",
			"Material_L1W2_WoodenPlanks",
			"Material_L1W3_WoodenPlanks",
			"Material_L2W1_WoodenPlanks",
			"Material_L2W2_WoodenPlanks",
			"Material_L2W3_WoodenPlanks",
			"Material_L3W1_WoodenPlanks",
			"Material_L3W2_WoodenPlanks",
			"Material_L3W3_WoodenPlanks",
			"Material_Nails",
			"Material_L1_Nails",
			"Material_L1W1_Nails",
			"Material_L1W2_Nails",
			"Material_L1W3_Nails",
			"Material_L2_Nails",
			"Material_L2W1_Nails",
			"Material_L2W2_Nails",
			"Material_MetalSheets",
			"Material_L3_MetalSheets",
			"Material_L1W1_MetalSheets",
			"Material_L1W2_MetalSheets",
			"Material_L1W3_MetalSheets",
			"Material_L2W1_MetalSheets",
			"Material_L2W2_MetalSheets",
			"Material_L2W3_MetalSheets",
			"Material_L3W1_MetalSheets",
			"Material_L3W2_MetalSheets",
			"Material_L3W3_MetalSheets",
			"Firewood",
			"WoodenStick",
			"CookingTripod",
			"CookingEquipment",
			"Stones",
			"Rags",
			"MedicalBandage",
			"Paper",
			"Book",
			"OakBark",
			"BirchBark",
			"Melee",
			"Knife",
			"Shoulder"
			
		};
		class GUIInventoryAttachmentsProps
		{
			class Log_Storage
			{
				name="Log Storage";
				description="";
				attachmentSlots[]=
				{
					"Material_WoodenLogs",
					"Material_L1_WoodenLogs",
					"Material_L2_WoodenLogs",
					"Material_L3_WoodenLogs"
				};
				icon="woodenlog";
			};
			class Plank_Storage
			{
				name="Plank Storage";
				description="";
				attachmentSlots[]=
				{
					"Material_WoodenPlanks",
					"Material_L3_WoodenPlanks",
					"Material_L1W1_WoodenPlanks",
					"Material_L1W2_WoodenPlanks",
					"Material_L1W3_WoodenPlanks",
					"Material_L2W1_WoodenPlanks",
					"Material_L2W2_WoodenPlanks",
					"Material_L2W3_WoodenPlanks",
					"Material_L3W1_WoodenPlanks",
					"Material_L3W2_WoodenPlanks",
					"Material_L3W3_WoodenPlanks"
				};
				icon="planks";
			};
			class Nails_Storage
			{
				name="Nails Storage";
				description="";
				attachmentSlots[]=
				{
					"Material_Nails",
					"Material_L1_Nails",
					"Material_L1W1_Nails",
					"Material_L1W2_Nails",
					"Material_L1W3_Nails",
					"Material_L2_Nails",
					"Material_L2W1_Nails",
					"Material_L2W2_Nails"
				};
				icon="nail";
			};
			class MetalSheets_Storage
			{
				name="Metal Storage";
				description="";
				attachmentSlots[]=
				{
					"Material_MetalSheets",
					"Material_L3_MetalSheets",
					"Material_L1W1_MetalSheets",
					"Material_L1W2_MetalSheets",
					"Material_L1W3_MetalSheets",
					"Material_L2W1_MetalSheets",
					"Material_L2W2_MetalSheets",
					"Material_L2W3_MetalSheets",
					"Material_L3W1_MetalSheets",
					"Material_L3W2_MetalSheets",
					"Material_L3W3_MetalSheets"
				};
				icon="metalsheets";
			};
			class Kindling_Storage
			{
				name="Fuel and Kindling";
				description="";
				attachmentSlots[]=
				{
					"Firewood",
					"WoodenStick",
					"Rags",
					"MedicalBandage",
					"Paper",
					"Book",
					"OakBark",
					"BirchBark"
				};
				icon="firewood";
			};
			class Misc_Storage
			{
				name="Misc Storage";
				description="";
				attachmentSlots[]=
				{
					"CookingTripod",
					"CookingEquipment",
					"Stones",
					"Melee",
					"Knife",
					"Shoulder"
				};
				icon="missing";
			};
		};
	};
	class SausageBuilding_Storage_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "BuildingStorage HOLO";
		model="DZ\structures\furniture\Various\sawhorse_DZ.p3d";
	};
};