class CfgPatches
{
	class DZ_SausageCo_Mechanic
	{
		units[]={
			""
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
	// class Slot_Magazine45ACP
	// {
		// name="Magazine45ACP";
		// displayName="45ACP"; 
		// ghostIcon="magazine";
		// stackMax=8;
		// show="true";
	// };
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class Book_Base;
    class SausageCo_SkillBook_Base: Inventory_Base
    {
    };
	class SausageCo_MechanicsTool: SausageCo_SkillBook_Base
	{
		model="DZ\gear\books\book_kniga.p3d";
		quantityBar=1;
		varQuantityDestroyOnMin=0;
		varLiquidTypeInit=8192;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=10000;
		varQuantityMin=0;
		varQuantityMax=20000;
		repairKitType=10;
		stackedUnit="percentage";
		animClass="Knife";
		inventorySlot[]=
		{
			"book1",
			"book2",
			"book3",
			"book4",
			"book5",
			"book6",
			"book7",
			"book8",
			"book9",
			"book10",
			"book11",
			"book12",
			"book13",
			"book14",
			"book15",
			"book16",
			"book17",
			"book18",
			"book19",
			"book20",
			"book21",
			"book22",
			"book23",
			"book24",
			"book25",
			"book26",
			"book27",
			"book28",
			"book29",
			"book30",
			"book31",
			"book32",
			"book33",
			"book34",
			"book35",
			"book36"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Mechanic\data\book_ApprenticeMechanic_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\Objects\Mechanic\data\book_mechanic.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Objects\Mechanic\data\book_mechanic.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Objects\Mechanic\data\book_mechanic.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Objects\Mechanic\data\book_mechanic.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Objects\Mechanic\data\book_mechanic.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SausageCo_MechanicsToolT1: SausageCo_MechanicsTool
	{
		scope=2;
		title="Apprentice Mechanic's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Apprentice Mechanic's Guide";
		descriptionShort="Mechanics can use this tool to craft Tier 1 Vehicle Parts.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Mechanic\data\book_ApprenticeMechanic_co.paa"
		};
	};
	class SausageCo_MechanicsToolT2: SausageCo_MechanicsTool
	{
		scope=2;
		title="Journeyman Mechanic's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Journeyman Mechanic's Guide";
		descriptionShort="Mechanics can use this tool to craft Tier 2 Vehicle Parts.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Mechanic\data\book_ArtisanMechanic_co.paa"
		};
	};
	class SausageCo_MechanicsToolT3: SausageCo_MechanicsTool
	{
		scope=2;
		title="Master Mechanic's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Master Mechanic's Guide";
		descriptionShort="Mechanics can use this tool to craft Tier 3 Vehicle Parts.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Mechanic\data\book_MasterMechanic_co.paa"
		};
	};
	class SausageCo_MechanicsToolT4: SausageCo_MechanicsTool
	{
		scope=2;
		title="GrandMaster of Mechanic's Tool";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="GrandMaster of Mechanic's Tool";
		descriptionShort="Your determination and dedication to the mastery of Mechanics has lead you here to your T4 Mechanics tool. You are now an awknowledged GrandMaster in the art of mechanics.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Mechanic\Mastery\data\book_MasteryofMechanic_co.paa"
		};
	};
	class SausageCo_MechanicSmallEngine: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Small engine";
		descriptionShort="SausageCo Small engine used in the crafting of small vehicles";
		model="DZ\gear\camping\power_generator.p3d";
		weight=20;
		absorbency=1;
		itemSize[]={3,3};
		rotationFlags=16;
		stackedUnit="g";
	};
	class SausageCo_MechanicMediumEngine: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Medium engine";
		descriptionShort="SausageCo Medium engine, used in the crafting of medium vehicles";
		model="DZ\gear\camping\power_generator.p3d";
		weight=20;
		absorbency=1;
		itemSize[]={3,3};
		rotationFlags=16;
		stackedUnit="g";
	};
	class SausageCo_MechanicHeavyEngine: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Heavy engine";
		descriptionShort="SausageCo Heavy engine, used in the crafting of heavy vehicles";
		model="DZ\gear\camping\power_generator.p3d";
		weight=20;
		absorbency=1;
		itemSize[]={3,3};
		rotationFlags=16;
		stackedUnit="g";
	};
	class SausageCo_MechanicSmallPiston: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Small Piston";
		descriptionShort="SausageCo Small Piston used in the crafting of small vehicles";
		model="DZ\vehicles\parts\sparkplug.p3d";
		weight=20;
		absorbency=1;
		itemSize[]={3,3};
		rotationFlags=16;
		stackedUnit="g";
	};
	class SausageCo_MechanicMediumPiston: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Medium Piston";
		descriptionShort="SausageCo Medium Piston, used in the crafting of medium vehicles";
		model="DZ\vehicles\parts\aviator_spark_plug.p3d";
		weight=20;
		absorbency=1;
		itemSize[]={3,3};
		rotationFlags=16;
		stackedUnit="g";
	};
	class SausageCo_MechanicHeavyPiston: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Heavy Piston";
		descriptionShort="SausageCo Heavy Piston, used in the crafting of heavy vehicles";
		model="DZ\vehicles\parts\aviator_spark_plug.p3d";
		weight=20;
		absorbency=1;
		itemSize[]={3,3};
		rotationFlags=16;
		stackedUnit="g";
	};
	class SausageCo_Vehicle_Kit_Base: Container_Base
	{
		scope=2;
		displayName="SausageVehicle Kit Base, NO USE";
		descriptionShort="";
		model="\DZ\gear\camping\wooden_case.p3d";
		itemSize[]={2,3};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=1;
		attachments[]=
		{	
			
		};
		class GUIInventoryAttachmentsProps
		{
			class Tire_Storage
			{
				name="Tire Storage";
				description="";
				attachmentSlots[]=
				{
					
				};
				icon="wheel";
			};
			class Door_Storage
			{
				name="Door Storage";
				description="";
				attachmentSlots[]=
				{
					
				};
				icon="doorfront";
			};
			class Engine_Storage
			{
				name="Engine Storage";
				description="";
				attachmentSlots[]=
				{
					
				};
				icon="enginebelt";
			};
		};
	};
	class SausageCo_Vehicle_ADA4x4Base_Kit: SausageCo_Vehicle_Kit_Base
	{
		displayName="SausageCo 4x4ADA Kit";
		descriptionShort="Use this to place your Vehicle, you will need the attachments to drive it off the lot.";
		
		attachments[]=
		{	
			"NivaWheel_1_1",
			"NivaWheel_1_2",
			"NivaWheel_2_1",
			"NivaWheel_2_2",
			"NivaWheel_Spare_1",
			"NivaHood",
			"NivaTrunk",
			"NivaDriverDoors",
			"NivaCoDriverDoors",
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug"
		};
		class GUIInventoryAttachmentsProps
		{
			class Tire_Storage
			{
				name="Tire Storage";
				description="";
				attachmentSlots[]=
				{
					"NivaWheel_1_1",
					"NivaWheel_1_2",
					"NivaWheel_2_1",
					"NivaWheel_2_2",
					"NivaWheel_Spare_1"
				};
				icon="wheel";
			};
			class Door_Storage
			{
				name="Door Storage";
				description="";
				attachmentSlots[]=
				{
					"NivaDriverDoors",
					"NivaCoDriverDoors",
					"NivaHood",
					"NivaTrunk"
				};
				icon="doorfront";
			};
			class Engine_Storage
			{
				name="Engine Storage";
				description="";
				attachmentSlots[]=
				{
					"CarBattery",
					"Reflector_1_1",
					"Reflector_2_1",
					"CarRadiator",
					"SparkPlug"
				};
				icon="enginebelt";
			};
		};
	};
	class SausageCo_Vehicle_OlgaBase_Kit: SausageCo_Vehicle_Kit_Base
	{
		displayName="SausageCo Olga Kit";
		descriptionShort="Use this to place your Vehicle, you will need the attachments to drive it off the lot.";
		
		attachments[]=
		{	
			"CivSedanWheel_1_1",
			"CivSedanWheel_1_2",
			"CivSedanWheel_2_1",
			"CivSedanWheel_2_2",
			"CivSedanHood",
			"CivSedanTrunk",
			"CivSedanDriverDoors",
			"CivSedanCoDriverDoors",
			"CivSedanCargo1Doors",
			"CivSedanCargo2Doors",
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug"
		};
		class GUIInventoryAttachmentsProps
		{
			class Tire_Storage
			{
				name="Tire Storage";
				description="";
				attachmentSlots[]=
				{
					"CivSedanWheel_1_1",
					"CivSedanWheel_1_2",
					"CivSedanWheel_2_1",
					"CivSedanWheel_2_2"
				};
				icon="wheel";
			};
			class Door_Storage
			{
				name="Door Storage";
				description="";
				attachmentSlots[]=
				{
					"CivSedanDriverDoors",
					"CivSedanCoDriverDoors",
					"CivSedanCargo1Doors",
					"CivSedanCargo2Doors",
					"CivSedanHood",
					"CivSedanTrunk"
				};
				icon="doorfront";
			};
			class Engine_Storage
			{
				name="Engine Storage";
				description="";
				attachmentSlots[]=
				{
					"CarBattery",
					"Reflector_1_1",
					"Reflector_2_1",
					"CarRadiator",
					"SparkPlug"
				};
				icon="enginebelt";
			};
		};
	};
	class SausageCo_Vehicle_GunterBase_Kit: SausageCo_Vehicle_Kit_Base
	{
		displayName="SausageCo Gunter Kit";
		descriptionShort="Use this to place your Vehicle, you will need the attachments to drive it off the lot.";
		
		attachments[]=
		{	
			"Hatchback_02_Wheel_1_1",
			"Hatchback_02_Wheel_1_2",
			"Hatchback_02_Wheel_2_1",
			"Hatchback_02_Wheel_2_2",
			"Hatchback_02_Hood",
			"Hatchback_02_Trunk",
			"Hatchback_02_Door_1_1",
			"Hatchback_02_Door_1_2",
			"Hatchback_02_Door_2_1",
			"Hatchback_02_Door_2_2",
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
		};
		class GUIInventoryAttachmentsProps
		{
			class Tire_Storage
			{
				name="Tire Storage";
				description="";
				attachmentSlots[]=
				{
					"Hatchback_02_Wheel_1_1",
					"Hatchback_02_Wheel_1_2",
					"Hatchback_02_Wheel_2_1",
					"Hatchback_02_Wheel_2_2"
				};
				icon="wheel";
			};
			class Door_Storage
			{
				name="Door Storage";
				description="";
				attachmentSlots[]=
				{
					"Hatchback_02_Door_1_1",
					"Hatchback_02_Door_1_2",
					"Hatchback_02_Door_2_1",
					"Hatchback_02_Door_2_2",
					"Hatchback_02_Trunk",
					"Hatchback_02_Hood"
				};
				icon="doorfront";
			};
			class Engine_Storage
			{
				name="Engine Storage";
				description="";
				attachmentSlots[]=
				{
					"CarBattery",
					"Reflector_1_1",
					"Reflector_2_1",
					"CarRadiator",
					"SparkPlug"
				};
				icon="enginebelt";
			};
		};
	};
	class SausageCo_Vehicle_SarkaBase_Kit: SausageCo_Vehicle_Kit_Base
	{
		displayName="SausageCo Sarka Kit";
		descriptionShort="Use this to place your Vehicle, you will need the attachments to drive it off the lot.";
		
		attachments[]=
		{	
			"Sedan_02_Wheel_1_1",
			"Sedan_02_Wheel_1_2",
			"Sedan_02_Wheel_2_1",
			"Sedan_02_Wheel_2_2",
			"Sedan_02_Hood",
			"Sedan_02_Trunk",
			"Sedan_02_Door_1_1",
			"Sedan_02_Door_2_1",
			"Sedan_02_Door_1_2",
			"Sedan_02_Door_2_2",
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug"
		};
		class GUIInventoryAttachmentsProps
		{
			class Tire_Storage
			{
				name="Tire Storage";
				description="";
				attachmentSlots[]=
				{
					"Sedan_02_Wheel_1_1",
					"Sedan_02_Wheel_1_2",
					"Sedan_02_Wheel_2_1",
					"Sedan_02_Wheel_2_2"
				};
				icon="wheel";
			};
			class Door_Storage
			{
				name="Door Storage";
				description="";
				attachmentSlots[]=
				{
					"Sedan_02_Hood",
					"Sedan_02_Trunk",
					"Sedan_02_Door_1_1",
					"Sedan_02_Door_2_1",
					"Sedan_02_Door_1_2",
					"Sedan_02_Door_2_2"
				};
				icon="doorfront";
			};
			class Engine_Storage
			{
				name="Engine Storage";
				description="";
				attachmentSlots[]=
				{
					"CarBattery",
					"Reflector_1_1",
					"Reflector_2_1",
					"CarRadiator",
					"SparkPlug"
				};
				icon="enginebelt";
			};
		};
	};
	class SausageCo_Vehicle_HummerBase_Kit: SausageCo_Vehicle_Kit_Base
	{
		displayName="SausageCo Hummer Kit";
		descriptionShort="Use this to place your Vehicle, you will need the attachments to drive it off the lot.";
		attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"GlowPlug",
			"Offroad_02_Hood",
			"Offroad_02_Trunk",
			"Offroad_02_Door_1_1",
			"Offroad_02_Door_2_1",
			"Offroad_02_Door_1_2",
			"Offroad_02_Door_2_2",
			"Offroad_02_Wheel_1_1",
			"Offroad_02_Wheel_1_2",
			"Offroad_02_Wheel_2_1",
			"Offroad_02_Wheel_2_2",
			"Offroad_02_Wheel_Spare_1"
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name="$STR_attachment_Engine0";
				description="";
				icon="set:dayz_inventory image:cat_vehicle_engine";
				attachmentSlots[]=
				{
					"CarBattery",
					"GlowPlug"
				};
			};
			class Body
			{
				name="$STR_attachment_Body0";
				description="";
				icon="set:dayz_inventory image:cat_vehicle_body";
				attachmentSlots[]=
				{
					"Reflector_1_1",
					"Reflector_2_1",
					"Offroad_02_Door_1_1",
					"Offroad_02_Door_2_1",
					"Offroad_02_Door_1_2",
					"Offroad_02_Door_2_2",
					"Offroad_02_Hood",
					"Offroad_02_Trunk",
					"Offroad_02_Wheel_Spare_1"
				};
			};
			class Chassis
			{
				name="$STR_attachment_Chassis0";
				description="";
				icon="set:dayz_inventory image:cat_vehicle_chassis";
				attachmentSlots[]=
				{
					"Offroad_02_Wheel_1_1",
					"Offroad_02_Wheel_1_2",
					"Offroad_02_Wheel_2_1",
					"Offroad_02_Wheel_2_2"
				};
			};
		};
	};
	class SausageCo_Vehicle_M3SBase_Kit: SausageCo_Vehicle_Kit_Base
	{
		displayName="SausageCo M3S Kit";
		descriptionShort="Use this to place your Vehicle, you will need the attachments to drive it off the lot.";
		
		attachments[]=
		{	
			"Truck_01_Wheel_1_1",
			"Truck_01_Wheel_1_2",
			"Truck_01_Wheel_1_3",
			"Truck_01_Wheel_2_1",
			"Truck_01_Wheel_2_2",
			"Truck_01_Wheel_2_3",
			"Truck_01_Wheel_Spare_1",
			"Truck_01_Wheel_Spare_2",
			"Truck_01_Door_1_1",
			"Truck_01_Door_2_1",
			"Truck_01_Hood",
			"TruckBattery",
			"Reflector_1_1",
			"Reflector_2_1"
		};
		class GUIInventoryAttachmentsProps
		{
			class Tire_Storage
			{
				name="Tire Storage";
				description="";
				attachmentSlots[]=
				{		
					"Truck_01_Wheel_1_1",
					"Truck_01_Wheel_2_1",
					"Truck_01_Wheel_Spare_1",
					"Truck_01_Wheel_Spare_2",
					"Truck_01_Wheel_1_2",
					"Truck_01_Wheel_2_2",
					"Truck_01_Wheel_1_3",
					"Truck_01_Wheel_2_3"
				};
				icon="wheel";
			};
			class Door_Storage
			{
				name="Door Storage";
				description="";
				attachmentSlots[]=
				{
					"Truck_01_Door_1_1",
					"Truck_01_Door_2_1",
					"Truck_01_Hood"
				};
				icon="doorfront";
			};
			class Engine_Storage
			{
				name="Engine Storage";
				description="";
				attachmentSlots[]=
				{
					"TruckBattery",
					"Reflector_1_1",
					"Reflector_2_1"
				};
				icon="enginebelt";
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxySausageXP: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"SausageExperience",
			"SausageLeatherExperience",
			"SausageMechanicExperience",
			"SausageEngineerExperience",
			"SausageFirearmExperience"
		};
		model="SausageCo\Objects\ExperienceCurrency\data\proxies\SausageXP.p3d";
	};
};