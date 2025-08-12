class CfgPatches
{
	class DZ_SausageGear_Storage
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
	class HouseNoDestruct;
	class Container_Base;
	class SausageStorage_Shed: Container_Base
	{
		scope=2;
		displayName="Shed Storage";
		model="\DZ\structures\Residential\Sheds\Shed_W5.p3d";
		descriptionShort="Shed storage can hold 1 full set of gear, 3 shoulder weapons and a knife and 1000 storage space! Created by Nicholiae.";
		itemSize[]={11,11};
		weight=7500;
		carveNavmesh=1;
		visibilityModifier=0.94999999;
		canBeDigged=0;
		alignHologramToTerain=1;
		heavyItem=1;
		itemBehaviour=2;
		physLayer="item_large";
		rotationFlags=2;
		class Cargo
		{
			itemsCargoSize[]={10,100};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{	
			"Knife",
			"Melee",
			"Shoulder1",
			"Shoulder2",
			"Shoulder3",
			"pistol",
			"Headgear",
			"Mask",
			"Eyewear",
			"Gloves",
			"Body",
			"Armband",
			"Vest",
			"Back",
			"Hips",
			"Legs",
			"Feet",
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
			"Att_CombinationLock"
		};
		class GUIInventoryAttachmentsProps
		{
			class CodeLock
			{
				name="CodeLock";
				description="";
				attachmentSlots[]=
				{
					"Att_CombinationLock"
				};
				icon="cat_bb_attachments";
				selection="wall";
			};
			class Weapons_Storage
			{
				name="Weapons Storage";
				description="";
				attachmentSlots[]=
				{	
					"Knife",
					"Melee",
					"Shoulder1",
					"Shoulder2",
					"Shoulder3",
					"pistol"
				};
				icon="Melee";
			};
			class Gear_Storage
			{
				name="Gear Storage";
				description="";
				attachmentSlots[]=
				{
					"Headgear",
					"Mask",
					"Eyewear",
					"Gloves",
					"Body",
					"Armband",
					"Vest",
					"Back",
					"Hips",
					"Legs",
					"Feet"
				};
				icon="Body";
			};
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
				icon="Nails";
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
				icon="MetalSheets";
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
					"Stones"
				};
				icon="missing";
			};
		};
		class Doors
		{
			class Doors1
			{
				displayName="door 1";
				component="Doors1";
				soundPos="doors1_action";
				animPeriod=1.25;
				initPhase=0;
				initOpened=0;
				soundOpen="doorWoodNolatchOpen";
				soundClose="doorWoodNolatchClose";
				soundLocked="doorWoodNolatchRattle";
				soundOpenABit="doorWoodNolatchOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
			class DamageZones
			{
				class door1
				{
					class Health
					{
						hitpoints=1000;
						transferToGlobalCoef=0;
					};
					componentNames[]=
					{
						"doors1"
					};
					fatalInjuryCoef=-1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=3;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class Melee
						{
							class Health
							{
								damage=5;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=3;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
					};
				};
			};
		};
	};
	class SausageStorage_Shed_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Shed Storage HOLO";
		model="\DZ\structures\Residential\Sheds\Shed_W5.p3d";
	};
};