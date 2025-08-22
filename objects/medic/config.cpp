class CfgPatches
{
	class DZ_SausageCo_Objects_Medic
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
    class SausageCo_SkillBook_Base: Book_Base
    {
    };
	class Edible_Base;
	class SausageCo_MedKit: Inventory_Base
	{
		scope=2;
		displayName="Med Kit";
		descriptionShort="SausageCo Med Kit. Use this to fix a broken leg and restore some blood, CAREFUL Setting a bone harms the target for 12 health.";
		model="SausageCo\Objects\Medic\medkit.p3d"
		inventorySlot[]=
		{
			"MedicalBandage",
			"SausageAid"
		};
		hiddenSelections[]=
		{
			"handle",
			"kit"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Medic\data\medkit.paa",
			"SausageCo\Objects\Medic\data\medkit.paa"
		};
		isMeleeWeapon=1;
		rotationFlags=17;
		weight=85;
		absorbency=0.80000001;
		itemSize[]={3,3};
		repairableWithKits[]={};
		repairCosts[]={};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\Objects\Medic\data\medkit.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Objects\Medic\data\medkit.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Objects\Medic\data\medkit.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Objects\Medic\data\medkit.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Objects\Medic\data\medkit.rvmat"
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
				class Bandage_loop1
				{
					soundSet="Bandage_loop_SoundSet";
					id=201;
				};
				class Bandage_loop2
				{
					soundSet="Bandage_loop_SoundSet";
					id=202;
				};
				class Bandage_loop3
				{
					soundSet="Bandage_loop_SoundSet";
					id=203;
				};
				class Bandage_start
				{
					soundSet="Bandage_start_SoundSet";
					id=204;
				};
				class Bandage_end
				{
					soundSet="Bandage_end_SoundSet";
					id=205;
				};
			};
		};
	};
	class SausageCo_FirstAidKit: SausageCo_MedKit
	{
		displayName="First Aid Kit";
		descriptionShort="SausageCo Med Kit. Use this to fix a broken leg and restore some blood, CAREFUL Setting a bone harms the target for 12 health.";
		
	};
	class SausageCo_MedicsTool: SausageCo_SkillBook_Base
	{
		model="DZ\gear\books\book_kniga.p3d";
		isMeleeWeapon=1;
		weight=5;
		absorbency=0;
		itemSize[]={1,1};
		rotationFlags=17;
		repairKitType=5;
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
			"SausageCo\Objects\Medic\data\book_ApprenticeMedic_co.paa"
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
								"SausageCo\Objects\Medic\data\book_Medic.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Objects\Medic\data\book_Medic.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Objects\Medic\data\book_Medic.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Objects\Medic\data\book_Medic.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Objects\Medic\data\book_Medic.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SausageCo_MedicsToolT1: SausageCo_MedicsTool
	{
		scope=2;
		title="Apprentice Medic's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Apprentice Medic's Guide";
		descriptionShort="Medics can use this tool to craft Tier 1 Medicine.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Medic\data\book_ApprenticeMedic_co.paa"
		};
	};
	class SausageCo_MedicsToolT2: SausageCo_MedicsTool
	{
		scope=2;
		title="Journeyman Medic's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Journeyman Medic's Guide";
		descriptionShort="Medics can use this tool to craft Tier 2 Medicine.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Medic\data\book_ArtisanMedic_co.paa"
		};
	};
	class SausageCo_MedicsToolT3: SausageCo_MedicsTool
	{
		scope=2;
		title="Master Medic's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Master Medic's Guide";
		descriptionShort="Medics can use this tool to craft Tier 3 Medicine.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Medic\data\book_MasterMedic_co.paa"
		};
	};
	class SausageCo_MedicsToolT4: SausageCo_MedicsTool
	{
		scope=2;
		title="GrandMaster of Medic's Tool";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="GrandMaster of Medicine Tool";
		descriptionShort="Your fierce determination has lead you here, to your T4 Medics tool. You are now an awknowledged GrandMaster!";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Medic\mastery\data\book_MasteryMedic_co.paa"
		};
	};
	class SC_BandageDressing: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Bandages";
		descriptionShort="SausageCo Bandages are so much better then regular bandages, 5 uses and faster application.";
		model="\dz\gear\medical\Bandage_dressing.p3d";
		inventorySlot[]=
		{
			"MedicalBandage"
		};
		isMeleeWeapon=1;
		varQuantityInit=5;
		varQuantityMin=0;
		varQuantityMax=5;
		quantityBar=1;
		varQuantityDestroyOnMin=1;
		rotationFlags=17;
		weight=115;
		absorbency=0.80000001;
		itemSize[]={1,1};
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\bandage.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\bandage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\bandage_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\bandage_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\bandage_destruct.rvmat"
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
				class Bandage_loop1
				{
					soundSet="Bandage_loop_SoundSet";
					id=201;
				};
				class Bandage_loop2
				{
					soundSet="Bandage_loop_SoundSet";
					id=202;
				};
				class Bandage_loop3
				{
					soundSet="Bandage_loop_SoundSet";
					id=203;
				};
				class Bandage_start
				{
					soundSet="Bandage_start_SoundSet";
					id=204;
				};
				class Bandage_end
				{
					soundSet="Bandage_end_SoundSet";
					id=205;
				};
			};
		};
	};
	class SC_BetterBandages: SC_BandageDressing
	{
		scope=2;
		displayName="SausageCo Better Bandages";
		descriptionShort="SausageCo Bandages are so much better then regular bandages, 10 uses and faster application.";
		model="\dz\gear\medical\Bandage_dressing.p3d";
		inventorySlot[]=
		{
			"MedicalBandage"
		};
		isMeleeWeapon=1;
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		
	};
	class SC_BestBandages: SC_BandageDressing
	{
		scope=2;
		displayName="SausageCo Best Bandages";
		descriptionShort="SausageCo Bandages are so much better then regular bandages, 15 uses and faster application.";
		model="\dz\gear\medical\Bandage_dressing.p3d";
		inventorySlot[]=
		{
			"MedicalBandage"
		};
		isMeleeWeapon=1;
		varQuantityInit=15;
		varQuantityMin=0;
		varQuantityMax=15;
		
	};
	class VitaminBottle: Edible_Base
	{};
	class SC_BetterVitamins: VitaminBottle
	{
		displayName="SausageCo Better Vitamins";
		descriptionShort="Better Vitamins brought to you by SausageCo, up to 85% prevention efficiency and may treat some illnesses";
		
		class Medicine
		{
			prevention=0.85;
			treatment=0.7;
			diseaseExit=0;
		};
	};
	class SC_BestVitamins: VitaminBottle
	{
		displayName="SausageCo Best Vitamins";
		descriptionShort="The Best Vitamins brought to you by SausageCo, up to 95% prevention efficiency and WILL treat some illnesses";
	
		class Medicine
		{
			prevention=0.95;
			treatment=0.9;
			diseaseExit=1;
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
			"SausageMedicExperience",
			"SausageFirearmExperience"
		};
		model="SausageCo\Objects\ExperienceCurrency\data\proxies\SausageXP.p3d";
	};
};