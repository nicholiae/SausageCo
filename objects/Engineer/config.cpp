class CfgPatches
{
	class DZ_SausageCo_Engineering
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
	class BaseBuildingBase: Inventory_Base
	{
	};
	class SausageCo_EngineersTool: SausageCo_SkillBook_Base
	{
		model="DZ\gear\books\book_kniga.p3d";
		isMeleeWeapon=1;
		weight=5;
		absorbency=0;
		itemSize[]={1,1};
		rotationFlags=17;
		stackedUnit="percentage";
		varQuantityDestroyOnMin=0;
		quantityBar=1;
		varQuantityInit=1000;
		varQuantityMin=100;
		varQuantityMax=1000;
		repairKitType=7;
		OnRestrainChange="SausageCo_EngineersToolT1";
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
			"SausageCo\Objects\Engineer\data\book_ApprenticeEngineer_co.paa"
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
								"SausageCo\Objects\Engineer\data\book_engineer.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Objects\Engineer\data\book_engineer.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Objects\Engineer\data\book_engineer.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Objects\Engineer\data\book_engineer.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Objects\Engineer\data\book_engineer.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SausageCo_EngineersToolT1: SausageCo_EngineersTool
	{
		scope=2;
		title="Apprentice Engineer's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Apprentice Engineer's Guide";
		descriptionShort="Engineers can use this tool to craft Tier 1 Base Storage kits.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Engineer\data\book_ApprenticeEngineer_co.paa"
		};
	};
	class SausageCo_EngineersToolT2: SausageCo_EngineersTool
	{
		scope=2;
		title="Journeyman Engineer's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Journeyman Engineer's Guide";
		descriptionShort="Engineers can use this tool to craft Tier 2 Base Storage kits.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Engineer\data\book_ArtisanEngineer_co.paa"
		};
	};
	class SausageCo_EngineersToolT3: SausageCo_EngineersTool
	{
		scope=2;
		title="Master Engineer's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Master Engineer's Guide";
		descriptionShort="Engineers can use this tool to craft Tier 3 Base Storage kits.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Engineer\data\book_MasterEngineer_co.paa"
		};
	};
	class SausageCo_EngineersToolT4: SausageCo_EngineersTool
	{
		scope=2;
		model="DZ\gear\books\book_kniga.p3d";
		isMeleeWeapon=1;
		itemSize[]={1,1};
		title="GrandMaster of Engineer's Tool";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="GrandMaster of Engineering Tool";
		descriptionShort="Your fierce determination has lead you here, to your T4 engineering tool. You are now an awknowledged GrandMaster!";
		rotationFlags=1;
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
			"SausageCo\Objects\Engineer\Mastery\data\book_Masteryengineer_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\Objects\Engineer\data\book_engineer.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Objects\Engineer\data\book_engineer.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Objects\Engineer\data\book_engineer.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Objects\Engineer\data\book_engineer.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Objects\Engineer\data\book_engineer.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SausageCo_PrefabHouse_Base: BaseBuildingBase
	{
		scope=2;
		displayName="Prefab Base NO USE";
		model="SausageCo\Objects\Engineer\Mastery\prefabs\sausagehouse1.p3d";
		itemsCargoSize[]={0,0};
		canBeDigged=0;
		overrideDrawArea="8.0";
		placement="ForceSlopeOnTerrain";		
		destroyOnEmpty=0;
		quantityBar=0;
		varQuantityMax=0;
		carveNavmesh=1;
		heavyItem=1;
		weight=1500;
		itemBehaviour=0;
		physLayer="item_large";
		allowOwnedCargoManipulation=1;
		hiddenSelections[]=
		{
			"prefab"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Engineer\Mastery\Prefabs\data\wornplaster_co.paa"
		};
		attachments[]=
		{	
				
		};
		class GUIInventoryAttachmentsProps
		{
			
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0,
							
							{
								""
							}
						}
					};
				};
			};
			class GlobalArmor
			{
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
				class Body
				{
					class Health
					{
						hitpoints=100000;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\house.rvmat"
								}
							},
							{
								0.69999999,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\house.rvmat"
								}
							},
							{
								0.5,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\house.rvmat"
								}
							},
							{
								0.30000001,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\house.rvmat"
								}
							},
							{
								0,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\house.rvmat"
								}
							}
						};
					};
					class ArmorType
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
					fatalInjuryCoef=-1;
				};
			};
		};
	};
	class NewSC_Prefab1: SausageCo_PrefabHouse_Base
	{
		displayName="House";
		model="SausageCo\Objects\Engineer\Mastery\prefabs\prefab1.p3d";
	};
	class SausageCo_PrefabHouse1: SausageCo_PrefabHouse_Base
	{
		displayName="Prefab 1";
		model="SausageCo\Objects\Engineer\Mastery\prefabs\sausagehouse1.p3d";
	};
	class SausageCo_PrefabHouse2: SausageCo_PrefabHouse_Base
	{
		displayName="Prefab 2";
		model="SausageCo\Objects\Engineer\Mastery\prefabs\sausagehouse2.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0,
							
							{
								""
							}
						}
					};
				};
			};
			class GlobalArmor
			{
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
				class Body
				{
					class Health
					{
						hitpoints=100000;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							},
							
							{
								0,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							}
						};
					};
					class ArmorType
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
					fatalInjuryCoef=-1;
				};
			};
		};
	};
	class SausageCo_PrefabHouse3: SausageCo_PrefabHouse_Base
	{
		displayName="Prefab 3";
		model="SausageCo\Objects\Engineer\Mastery\prefabs\sausagehouse3.p3d";
	};
	class SausageCo_PrefabHouse3_Camo: SausageCo_PrefabHouse_Base
	{
		displayName="Prefab 3";
		model="SausageCo\Objects\Engineer\Mastery\prefabs\sausagehouse3camo.p3d";
		hiddenSelections[]=
		{
			"prefab"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Engineer\Mastery\Prefabs\data\Woodland_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0,
							
							{
								""
							}
						}
					};
				};
			};
			class GlobalArmor
			{
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
				class Body
				{
					class Health
					{
						hitpoints=100000;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2camo.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2camo.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2camo.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2camo.rvmat"
								}
							},
							
							{
								0,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2camo.rvmat"
								}
							}
						};
					};
					class ArmorType
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
					fatalInjuryCoef=-1;
				};
			};
		};
	};
	class SausageCo_PrefabHouse4: SausageCo_PrefabHouse_Base
	{
		displayName="Prefab 4";
		model="SausageCo\Objects\Engineer\Mastery\prefabs\sausagehouse4.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0,
							
							{
								""
							}
						}
					};
				};
			};
			class GlobalArmor
			{
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
				class Body
				{
					class Health
					{
						hitpoints=100000;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							},
							
							{
								0,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							}
						};
					};
					class ArmorType
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
					fatalInjuryCoef=-1;
				};
			};
		};
	};
	class SausageCo_PrefabHouse5: SausageCo_PrefabHouse_Base
	{
		displayName="Prefab 5";
		model="SausageCo\Objects\Engineer\Mastery\prefabs\sausagehouse5.p3d";
	};
	class SausageCo_PrefabHouse6: SausageCo_PrefabHouse_Base
	{
		displayName="Prefab 6";
		model="SausageCo\Objects\Engineer\Mastery\prefabs\sausagehouse6.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0,
							
							{
								""
							}
						}
					};
				};
			};
			class GlobalArmor
			{
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
				class Body
				{
					class Health
					{
						hitpoints=100000;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							},
							
							{
								0,
								
								{
									"SausageCo\Objects\Engineer\Mastery\Prefabs\data\prefabhouse2.rvmat"
								}
							}
						};
					};
					class ArmorType
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
					fatalInjuryCoef=-1;
				};
			};
		};
	};
	class SausageCo_House_Kit_Base: Inventory_Base
	{
		scope=2;
		displayName="SausageHouse Kit Base, NO USE";
		descriptionShort="";
		model="\DZ\gear\camping\wooden_case.p3d";
		itemSize[]={4,4};
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
		class Cargo
		{
		};
	};
	class SausageCo_PrefabHouse1_Kit: SausageCo_House_Kit_Base
	{
		displayName="SausageCo Prefab House1";
		descriptionShort="Prefab Base with large rearporch, large interior, DISCLAIMER(IF overhanging, build extra floor over hanging section for best results!";
	};
	class SausageCo_PrefabHouse2_Kit: SausageCo_House_Kit_Base
	{
		displayName="SausageCo Prefab House2";
		descriptionShort="This wooden house has a nice split design, 2 rooms and nice views from each room. May need some patching though.";
	};
	class SausageCo_PrefabHouse3_Kit: SausageCo_House_Kit_Base
	{
		displayName="SausageCo Prefab House3";
		descriptionShort="Giant 2 story Cement home for only the most needy of storage space.";
	};
	class SausageCo_PrefabHouse3_Camo_Kit: SausageCo_House_Kit_Base
	{
		displayName="SausageCo Prefab House3Camo";
		descriptionShort="Giant 2 story CamoCement home for only the most needy of storage space.";
	};
	class SausageCo_PrefabHouse4_Kit: SausageCo_House_Kit_Base
	{
		displayName="SausageCo Prefab House4";
		descriptionShort="";
	};
	class SausageCo_PrefabHouse5_Kit: SausageCo_House_Kit_Base
	{
		displayName="SausageCo Prefab House5";
		descriptionShort="Giant 4 story Cement Tower.";
	};
	class SausageCo_PrefabHouse6_Kit: SausageCo_House_Kit_Base
	{
		displayName="SausageCo Prefab House6";
		descriptionShort="";
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