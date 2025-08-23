class CfgPatches
{
	class DZ_SausageCo_LeatherWorkering
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
	class Book_Base;
    class SausageCo_SkillBook_Base: Inventory_Base
    {
    };
	class SausageCo_LeatherWorkersTool: SausageCo_SkillBook_Base
	{
		model="DZ\gear\books\book_kniga.p3d";
		quantityBar=1;
		varQuantityInit=1000;
		varQuantityMin=100;
		varQuantityMax=1000;
		varQuantityDestroyOnMin=0;
		repairKitType=3;
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
			"SausageCo\Objects\LeatherWorker\data\book_ApprenticeLeather_co.paa"
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
								"SausageCo\Objects\LeatherWorker\data\book_leather.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Objects\LeatherWorker\data\book_leather.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Objects\LeatherWorker\data\book_leather.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Objects\LeatherWorker\data\book_leather.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Objects\LeatherWorker\data\book_leather.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SausageCo_LeatherWorkersToolT1: SausageCo_LeatherWorkersTool
	{
		scope=2;
		title="Apprentice LeatherWorker's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Apprentice LeatherWorker's Guide";
		descriptionShort="LeatherWorkers can use this tool to craft Tier 1 Leather Gear.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\LeatherWorker\data\book_ApprenticeLeather_co.paa"
		};
	};
	class SausageCo_LeatherWorkersToolT2: SausageCo_LeatherWorkersTool
	{
		scope=2;
		title="Journeyman LeatherWorker's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Journeyman LeatherWorker's Guide";
		descriptionShort="LeatherWorkers can use this tool to craft Tier 2 Leather Gear.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\LeatherWorker\data\book_ArtisanLeather_co.paa"
		};
	};
	class SausageCo_LeatherWorkersToolT3: SausageCo_LeatherWorkersTool
	{
		scope=2;
		title="Master LeatherWorker's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Master LeatherWorker's Guide";
		descriptionShort="LeatherWorkers can use this tool to craft Tier 3 Leather Gear.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\LeatherWorker\data\book_MasterLeather_co.paa"
		};
	};
	class SausageCo_LeatherWorkersToolT4: SausageCo_LeatherWorkersTool
	{
		scope=2;
		title="GrandMaster of LeatherWorkering";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="GrandMaster of LeatherWorkering Tool";
		descriptionShort="Your dedication and determination in the art of leatherworking has lead you here, to your T4 Leatherworkers Tool. You are now an Awknowledged GrandMaster!";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\LeatherWorker\Mastery\data\book_MasteryLeather_co.paa"
		};
	};
	class LeatherUpgradeKit: Inventory_Base
	{
		scope=2;
		displayName="Leather Upgrade Kit";
		descriptionShort="A leather upgrade kit that can be used to upgrade the crafted leather gear to the next tier.";
		model="\dz\gear\tools\leather_sewing_kit.p3d";
		weight=2;
		absorbency=1;
		itemSize[]={1,2};
		rotationFlags=16;
	};
	class LeatherUpgradeKit_T2: LeatherUpgradeKit
	{
		displayName="Leather Upgrade Kit T2";
		descriptionShort="A Tier 2 leather upgrade kit, capable of upgrading the smallCraftedLeather gear to mediumCraftedLeather";
	};
	class LeatherUpgradeKit_T3: LeatherUpgradeKit
	{
		displayName="Leather Upgrade Kit T3";
		descriptionShort="A Tier 3 leather upgrade kit, capable of upgrading the mediumCraftedLeather gear to largeCraftedLeather";
	};
	class SausageCo_PaintBucket_base: Inventory_Base
	{
		scope=2;
		displayName="SausageCo PaintBucket Base";
		descriptionShort="A paint bucket that can be used to paint objects and dye clothing to a certain color.";
		model="DZ\structures\furniture\decoration\bucket\bucket.p3d";
		weight=2;
		absorbency=1;
		itemSize[]={1,2};
		rotationFlags=16;
		stackedUnit="g";
		quantityBar=1;
		varQuantityInit=200;
		varQuantityMin=0;
		varQuantityMax=200;
		varQuantityDestroyOnMin=1;
	};
	class SausageCo_PaintBucket_DimanCamo: SausageCo_PaintBucket_base
	{
		displayName="SausageCo PaintBucket DimanCamo";
	};
	class SausageCo_PaintBucket_Red: SausageCo_PaintBucket_base
	{
		displayName="SausageCo PaintBucket Red";
	};
	class SausageCo_PaintBucket_Green: SausageCo_PaintBucket_base
	{
		displayName="SausageCo PaintBucket Green";
	};
	class SausageCo_PaintBucket_Blue: SausageCo_PaintBucket_base
	{
		displayName="SausageCo PaintBucket Blue";
	};
	class SausageCo_PaintBucket_Black: SausageCo_PaintBucket_base
	{
		displayName="SausageCo PaintBucket Black";
	};
	class SausageCo_PaintBucket_Yellow: SausageCo_PaintBucket_base
	{
		displayName="SausageCo PaintBucket Yellow";
	};
	class SausageCo_PaintBucket_Orange: SausageCo_PaintBucket_base
	{
		displayName="SausageCo PaintBucket Orange";
	};
	class SausageCo_PaintBucket_Grey: SausageCo_PaintBucket_base
	{
		displayName="SausageCo PaintBucket Grey";
	};
	class SausageCo_PaintBucket_Purple: SausageCo_PaintBucket_base
	{
		displayName="SausageCo PaintBucket Purple";
	};
	class SausageCoLeatherScraps: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Leather Scraps";
		descriptionShort="Leather Scraps made from animal pelts to craft gear.";
		model="\dz\gear\consumables\tanned_leather.p3d";
		weight=2;
		absorbency=0.30000001;
		itemSize[]={2,1};
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=200;
		varQuantityDestroyOnMin=1;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\consumables\data\tanned_leather.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\consumables\data\tanned_leather.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\consumables\data\tanned_leather_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\consumables\data\tanned_leather_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\consumables\data\tanned_leather_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
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