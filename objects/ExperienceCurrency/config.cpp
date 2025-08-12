class CfgPatches
{
	class DZ_SausageCo_XPCurrency
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
	class Slot_SausageExperience
	{
		name="SausageExperience";
		displayName="SausageExperience"; 
		ghostIcon="book";
		stackMax=3000;
		show="true";
	};
	class Slot_SausageLeatherExperience
	{
		name="SausageLeatherExperience";
		displayName="SausageLeatherExperience"; 
		ghostIcon="book";
		stackMax=3000;
		show="true";
	};
	class Slot_SausageMechanicExperience
	{
		name="SausageMechanicExperience";
		displayName="SausageMechanicExperience"; 
		ghostIcon="book";
		stackMax=3000;
		show="true";
	};
	class Slot_SausageEngineerExperience
	{
		name="SausageEngineerExperience";
		displayName="SausageEngineerExperience"; 
		ghostIcon="book";
		stackMax=3000;
		show="true";
	};
	class Slot_SausageFirearmExperience
	{
		name="SausageFirearmExperience";
		displayName="SausageFirearmExperience"; 
		ghostIcon="book";
		stackMax=3000;
		show="true";
	};
	class Slot_SausageFarmerExperience
	{
		name="SausageFarmerExperience";
		displayName="SausageFarmerExperience"; 
		ghostIcon="book";
		stackMax=3000;
		show="true";
	};
	class Slot_SausageCookExperience
	{
		name="SausageCookExperience";
		displayName="SausageCookExperience"; 
		ghostIcon="book";
		stackMax=3000;
		show="true";
	};
	class Slot_SausageHunterExperience
	{
		name="SausageHunterExperience";
		displayName="SausageHunterExperience"; 
		ghostIcon="book";
		stackMax=3000;
		show="true";
	};
	class Slot_SausageMedicExperience
	{
		name="SausageMedicExperience";
		displayName="SausageMedicExperience"; 
		ghostIcon="book";
		stackMax=3000;
		show="true";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class SausageCo_Experience_Pouch: Inventory_Base
	{
		scope=2;
		displayName="Experience Bill-Fold";
		descriptionShort="use this to store all your skills XP";
		model="\dz\gear\containers\wallet.p3d";
		inventorySlot[]=
		{
			"VestPouch"
		};
		weight=250;
		itemSize[]={2,2};
		itemsCargoSize[]={0,0};
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		allowOwnedCargoManipulation=1;
		attachments[]=
		{	
			"SausageMedicExperience",
			"SausageLeatherExperience",
			"SausageFarmerExperience",
			"SausageFirearmExperience",
			"SausageEngineerExperience",
			"SausageCookExperience",
			"SausageHunterExperience",
			"SausageMechanicExperience"
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
		};
		class GUIInventoryAttachmentsProps
		{
			class MedicXP_Storage
			{
				name="MedicXP Storage";
				description="";
				attachmentSlots[]=
				{
					"SausageMedicExperience"
				};
				icon="book";
			};
			class LeatherXP_Storage
			{
				name="LeatherXP Storage";
				description="";
				attachmentSlots[]=
				{
					"SausageLeatherExperience"
				};
				icon="book";
			};
			class FarmerXP_Storage
			{
				name="FarmerXP Storage";
				description="";
				attachmentSlots[]=
				{
					"SausageFarmerExperience"
				};
				icon="book";
			};
			class FirearmXP_Storage
			{
				name="FirearmXP Storage";
				description="";
				attachmentSlots[]=
				{
					"SausageFirearmExperience"
				};
				icon="book";
			};
			class EngineerXP_Storage
			{
				name="EngineerXP Storage";
				description="";
				attachmentSlots[]=
				{
					"SausageEngineerExperience"
				};
				icon="book";
			};
			class MechanicXP_Storage
			{
				name="MechanicXP Storage";
				description="";
				attachmentSlots[]=
				{
					"SausageMechanicExperience"
				};
				icon="book";
			};
			class HunterXP_Storage
			{
				name="HunterXP Storage";
				description="";
				attachmentSlots[]=
				{
					"SausageHunterExperience"
				};
				icon="book";
			};
			class CookXP_Storage
			{
				name="CookXP Storage";
				description="";
				attachmentSlots[]=
				{
					"SausageCookExperience"
				};
				icon="book";
			};
		};
	};
	class SausageCo_Experience_Base: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Experience Base";
		descriptionShort="Experience used in the leveling of skills.";
		model="SausageCo\Objects\ExperienceCurrency\data\SausageXP.p3d";
		canBeSplit=1;
		rotationFlags=16;
		lootCategory="Materials";
		lootTag[]=
		{
			
		};
		itemSize[]={1,1};
		weight=1;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=3000;
		varQuantityDestroyOnMin=1;
		destroyOnEmpty=1;
		absorbency=1;
		inventorySlot[]=
		{
			"SausageExperience"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\ExperienceCurrency\data\book_Experience_co.paa"
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
								"SausageCo\Objects\ExperienceCurrency\data\experienceCurrency.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Objects\ExperienceCurrency\data\experienceCurrency.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Objects\ExperienceCurrency\data\experienceCurrency.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Objects\ExperienceCurrency\data\experienceCurrency.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Objects\ExperienceCurrency\data\experienceCurrency.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SausageCo_Experience_Starter: SausageCo_Experience_Base
	{
		displayName="SausageCo Starter's Experience";
		inventorySlot[]=
		{
			"SausageStarterExperience"
		};
	};
	class SausageCo_Experience_Hunter: SausageCo_Experience_Base
	{
		displayName="SausageCo Hunter's Experience";
		inventorySlot[]=
		{
			"SausageHunterExperience"
		};
	};
	class SausageCo_Experience_Cook: SausageCo_Experience_Base
	{
		displayName="SausageCo Cook's Experience";
		inventorySlot[]=
		{
			"SausageCookExperience"
		};
	};
	class SausageCo_Experience_Medic: SausageCo_Experience_Base
	{
		displayName="SausageCo Medic's Experience";
		inventorySlot[]=
		{
			"SausageMedicExperience"
		};
	};
	class SausageCo_Experience_Farmer: SausageCo_Experience_Base
	{
		displayName="SausageCo Farmer's Experience";
		inventorySlot[]=
		{
			"SausageFarmerExperience"
		};
	};
	class SausageCo_Experience_Leather: SausageCo_Experience_Base
	{
		displayName="SausageCo Leatherworker's Experience";
		inventorySlot[]=
		{
			"SausageLeatherExperience"
		};
	};
	class SausageCo_Experience_Firearm: SausageCo_Experience_Base
	{
		displayName="SausageCo Firearm's Experience";
		inventorySlot[]=
		{
			"SausageFirearmExperience"
		};
	};
	class SausageCo_Experience_Engineer: SausageCo_Experience_Base
	{
		displayName="SausageCo Engineer's Experience";
		inventorySlot[]=
		{
			"SausageEngineerExperience"
		};
	};
	class SausageCo_Experience_Mechanic: SausageCo_Experience_Base
	{
		displayName="SausageCo Mechanic's Experience";
		inventorySlot[]=
		{
			"SausageMechanicExperience"
		};
	};
};
