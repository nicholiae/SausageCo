class CfgPatches
{
	class DZ_SausageCo_Firearms
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

class CfgMagazines
{
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
	class SausageCo_FirearmsTool: SausageCo_SkillBook_Base
	{
		model="DZ\gear\books\book_kniga.p3d";
		quantityBar=1;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=200;
		varQuantityDestroyOnMin=0;
		repairKitType=1;
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
			"SausageCo\Objects\FirearmSpecialist\data\book_ApprenticeBallistics_co.paa"
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
								"SausageCo\Objects\FirearmSpecialist\data\book_ballistics.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Objects\FirearmSpecialist\data\book_ballistics.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Objects\FirearmSpecialist\data\book_ballistics.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Objects\FirearmSpecialist\data\book_ballistics.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Objects\FirearmSpecialist\data\book_ballistics.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SausageCo_FirearmsToolT1: SausageCo_FirearmsTool
	{
		scope=2;
		title="Apprentice Firearm's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Apprentice Firearm's Guide";
		descriptionShort="Firearms can use this tool to craft Tier 1 Ammunition & Magazines.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\FirearmSpecialist\data\book_ApprenticeBallistics_co.paa"
		};
	};
	class SausageCo_FirearmsToolT2: SausageCo_FirearmsTool
	{
		scope=2;
		title="Journeyman Firearm's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Journeyman Firearm's Guide";
		descriptionShort="Firearms can use this tool to craft Tier 2 Ammunition & Magazines.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\FirearmSpecialist\data\book_ArtisanBallistics_co.paa"
		};
	};
	class SausageCo_FirearmsToolT3: SausageCo_FirearmsTool
	{
		scope=2;
		title="Master Firearm's Guide";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="Master Firearm's Guide";
		descriptionShort="Firearms can use this tool to craft Tier 3 Ammunition & Magazines.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\FirearmSpecialist\data\book_MasterBallistics_co.paa"
		};
	};
	class SausageCo_FirearmsToolT4: SausageCo_FirearmsTool
	{
		scope=2;
		title="GrandMaster of Firearms Tool";
		author="SausageCo Publishing Unit";
		file="";
		lootTag[]=
		{
			""
		};
		displayName="GrandMaster of Firearms Tool";
		descriptionShort="Your time dedicated in the mastery of firearms has lead you here to your GrandMaster Firearms tool.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\FirearmSpecialist\Mastery\data\book_MasteryBallistics_co.paa"
		};
	};
	class SausageCo_WeaponMold_Base: Inventory_Base
	{
		scope=2;
		displayName="SausageCo weapon mold base item NO USE";
		descriptionShort="SausageCo Weapon Mold. Made for Firearms Specialists in their Mastery to craft weapon barrels and frames, two items needed for weapon crafting.";
		model="SausageCo\Objects\FirearmSpecialist\Mastery\weaponMold.p3d";
		weight=20;
		absorbency=1;
		itemSize[]={2,2};
		rotationFlags=16;
		stackedUnit="g";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\FirearmSpecialist\Mastery\data\mold_texture_co.paa"
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
								"SausageCo\Objects\FirearmSpecialist\Mastery\data\mould.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Objects\FirearmSpecialist\Mastery\data\mould.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Objects\FirearmSpecialist\Mastery\data\mould.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Objects\FirearmSpecialist\Mastery\data\mould.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Objects\FirearmSpecialist\Mastery\data\mould.rvmat"
							}
						}
					};
				};
			};
		};
	};
	
	class SausageCo_WeaponMold_pistolframe: SausageCo_WeaponMold_Base
	{
		displayName="SausageCo PistolFrame mould";
	};
	class SausageCo_WeaponMold_pistolbarrel: SausageCo_WeaponMold_Base
	{
		displayName="SausageCo PistolBarrel mould";
	};
	class SausageCo_WeaponMold_arframe: SausageCo_WeaponMold_Base
	{
		displayName="SausageCo ARFrame mould";
	};
	class SausageCo_WeaponMold_arbarrel: SausageCo_WeaponMold_Base
	{
		displayName="SausageCo ARBarrel mould";
	};
	class SausageCo_WeaponMold_heavyarframe: SausageCo_WeaponMold_Base
	{
		displayName="SausageCo HeavyARFrame mould";
	};
	class SausageCo_WeaponMold_heavyarbarrel: SausageCo_WeaponMold_Base
	{
		displayName="SausageCo HeavyARBarrel mould";
	};
	//NONFILLED END FILLED START
	class SausageCo_WeaponMold_Filled_Base: Inventory_Base
	{
		scope=2;
		displayName="SausageCo weapon mold base item NO USE";
		descriptionShort="SausageCo Weapon Mold. Made for Firearms Specialists in their Mastery to craft weapon barrels and frames, two items needed for weapon crafting.";
		model="SausageCo\Objects\FirearmSpecialist\Mastery\weaponMold.p3d";
		weight=20;
		absorbency=1;
		itemSize[]={2,2};
		rotationFlags=16;
		stackedUnit="g";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\FirearmSpecialist\Mastery\data\moldFilled_texture_co.paa"
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
								"SausageCo\Objects\FirearmSpecialist\Mastery\data\mouldFilled.rvmat"
							}
						},
						{
							0.69999999,
							
							{
								"SausageCo\Objects\FirearmSpecialist\Mastery\data\mouldFilled.rvmat"
							}
						},
						{
							0.5,
							
							{
								"SausageCo\Objects\FirearmSpecialist\Mastery\data\mouldFilled.rvmat"
							}
						},
						{
							0.30000001,
							
							{
								"SausageCo\Objects\FirearmSpecialist\Mastery\data\mouldFilled.rvmat"
							}
						},
						{
							0,
							
							{
								"SausageCo\Objects\FirearmSpecialist\Mastery\data\mouldFilled.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SausageCo_WeaponMold_pistolframe_filled: SausageCo_WeaponMold_Filled_Base
	{
		displayName="Filled PistolFrame mould";
	};
	class SausageCo_WeaponMold_pistolbarrel_filled: SausageCo_WeaponMold_Filled_Base
	{
		displayName="Filled PistolBarrel mould";
	};
	class SausageCo_WeaponMold_arframe_filled: SausageCo_WeaponMold_Filled_Base
	{
		displayName="Filled ARFrame mould";
	};
	class SausageCo_WeaponMold_arbarrel_filled: SausageCo_WeaponMold_Filled_Base
	{
		displayName="Filled ARBarrel mould";
	};
	class SausageCo_WeaponMold_heavyarframe_filled: SausageCo_WeaponMold_Filled_Base
	{
		displayName="Filled HeavyARFrame mould";
	};
	class SausageCo_WeaponMold_heavyarbarrel_filled: SausageCo_WeaponMold_Filled_Base
	{
		displayName="Filled HeavyARBarrel mould";
	};
	class SausageCo_PistolBarrel: Inventory_Base
	{
		scope=2;
		displayName="Pistol barrel";
		descriptionShort="The barrel of a pistol used in the crafting of weapons.";
		model="\dz\weapons\attachments\muzzle\suppressor_45acp.p3d";
		itemSize[]={2,1};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class SausageCo_PistolFrame: Inventory_Base
	{
		scope=2;
		displayName="Pistol frame";
		descriptionShort="The frame of a pistol used in the crafting of weapons.";
		model="\dz\weapons\nonlethal\dartgun\dartgun.p3d";
		itemSize[]={2,1};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class SausageCo_ARBarrel: Inventory_Base
	{
		scope=2;
		displayName="AR barrel";
		descriptionShort="The barrel of an AR used in the crafting of Assault Rifles.";
		model="\dz\weapons\firearms\ots14\ots14.p3d";
		itemSize[]={2,1};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class SausageCo_ARFrame: Inventory_Base
	{
		scope=2;
		displayName="AR frame";
		descriptionShort="The frame of an AR used in the crafting of Assault Rifles.";
		model="\dz\weapons\firearms\pm73rak\pm73rak.p3d";
		itemSize[]={3,1};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class SausageCo_HeavyARBarrel: Inventory_Base
	{
		scope=2;
		displayName="Heavy AR barrel";
		descriptionShort="The barrel of a Heavy AR used in the crafting of Heavy weapons.";
		model="\dz\weapons\attachments\muzzle\suppressor_545.p3d";
		itemSize[]={4,1};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class SausageCo_HeavyARFrame: Inventory_Base
	{
		scope=2;
		displayName="Heavy AR frame";
		descriptionShort="The frame of a Heavy AR used in the crafting of Heavy weapons.";
		model="\dz\weapons\firearms\fal\fal.p3d";
		itemSize[]={4,1};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class SausageCo_GunPowder: Inventory_Base
	{
		scope=2;
		displayName="SausageCo GunPowder";
		descriptionShort="Gunpowder used in the crafting of ammunition. Combine at least a stack of 50 with 50 bullet casing to fill the empty casing.";
		model="\dz\gear\food\PowderedMilk.p3d";
		weight=2;
		absorbency=1;
		itemSize[]={1,1};
		rotationFlags=16;
		stackedUnit="g";
		quantityBar=1;
		varQuantityInit=200;
		varQuantityMin=0;
		varQuantityMax=200;
		varQuantityDestroyOnMin=1;
		inventorySlot[]=
		{
			"SCAS_gunpowder",
			"SCAS_gunpowder1",
			"SCAS_gunpowder2",
			"SCAS_gunpowder3"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\FirearmSpecialist\data\gun_powder_co.paa"
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
								"SausageCo\Objects\FirearmSpecialist\data\gun_powder.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Objects\FirearmSpecialist\data\gun_powder.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Objects\FirearmSpecialist\data\gun_powder.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Objects\FirearmSpecialist\data\gun_powder.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Objects\FirearmSpecialist\data\gun_powder.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SausageCo_BulletCasing: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Bullet Casing";
		descriptionShort="Bullet Casing used for crafting ammo. Fill with gunpowder and then use your Firearms tool to craft ammo.";
		model="SausageCo\Objects\FirearmSpecialist\casingemptyTest.p3d";
		canBeSplit=1;
		rotationFlags=16;
		lootCategory="Materials";
		itemSize[]={1,1};
		weight=0.1;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=200;
		absorbency=1;
		inventorySlot[]=
		{
			"SCAS_casings",
			"SCAS_casings1",
			"SCAS_casings2",
			"SCAS_casings3"
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
								"SausageCo\Objects\FirearmSpecialist\data\bulletCasing.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Objects\FirearmSpecialist\data\bulletCasing.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Objects\FirearmSpecialist\data\bulletCasing.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Objects\FirearmSpecialist\data\bulletCasing.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Objects\FirearmSpecialist\data\bulletCasing.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SausageCo_BulletCasing_Filled: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Bullet Casing Filled";
		descriptionShort="Bullet Casing used for crafting ammo. Use your Firearms tool to craft ammo.";
		model="SausageCo\Objects\FirearmSpecialist\casingfilledTest.p3d";
		canBeSplit=1;
		rotationFlags=16;
		lootCategory="Materials";
		itemSize[]={1,1};
		weight=0.3;
		varQuantityInit=1;
		varQuantityMin=1;
		varQuantityMax=200;
		absorbency=1;
		inventorySlot[]=
		{
			"SCAS_casingsFilled",
			"SCAS_casings1Filled",
			"SCAS_casings2Filled",
			"SCAS_casings3Filled"
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
								
							}
						},
						
						{
							0.69999999,
							
							{
								
							}
						},
						
						{
							0.5,
							
							{
								
							}
						},
						
						{
							0.30000001,
							
							{
								
							}
						},
						
						{
							0,
							
							{
								
							}
						}
					};
				};
			};
		};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoRifle;
class cfgWeapons
{
	class Pistol_Base;
	class Glock19_Base: Pistol_Base
	{
	};
	class SC_AutoGlock19_Base : Glock19_Base
	{
		magazines[]=
		{
			"SC_Mag_AutoGlock_45Rnd",
			"Mag_Glock_15Rnd"
		};
		modes[]=
		{
			"Single",
			"FullAuto",
			"SemiAuto"
		};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[]=
			{
				"MP5K_Shot_SoundSet",
				"MP5K_Tail_SoundSet",
				"MP5K_InteriorTail_SoundSet"
			};
			soundSetShotExt[]=
			{
				
				{
					"MP5K_silencerPro_SoundSet",
					"MP5K_silencerTail_SoundSet",
					"MP5K_silencerInteriorTail_SoundSet"
				}
			};
			begin1[]=
			{
				"dz\sounds\weapons\firearms\mp5k\mp5k_single_0",
				1,
				1,
				900
			};
			begin2[]=
			{
				"dz\sounds\weapons\firearms\mp5k\mp5k_single_1",
				1,
				1,
				900
			};
			begin3[]=
			{
				"dz\sounds\weapons\firearms\mp5k\mp5k_single_2",
				1,
				1,
				900
			};
			soundBegin[]=
			{
				"begin1",
				0.33333001,
				"begin2",
				0.33333001,
				"begin3",
				0.33333001
			};
			reloadTime=0.125;
			recoil="recoil_mp5";
			recoilProne="recoil_mp5_prone";
			dispersion=0.003;
			magazineSlot="magazine";
			beginSilenced_Pro[]=
			{
				"dz\sounds\weapons\firearms\mp5k\mp5Silenced",
				1,
				1,
				75
			};
			beginSilenced_HomeMade[]=
			{
				"dz\sounds\weapons\firearms\mp5k\mp5Silenced",
				1,
				1,
				100
			};
			soundBeginExt[]=
			{
				
				{
					"beginSilenced_Pro",
					1
				},
				
				{
					"beginSilenced_HomeMade",
					1
				}
			};
		};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[]=
			{
				"MP5K_Shot_SoundSet",
				"MP5K_Tail_SoundSet",
				"MP5K_InteriorTail_SoundSet"
			};
			soundSetShotExt[]=
			{
				
				{
					"MP5K_silencerPro_SoundSet",
					"MP5K_silencerTail_SoundSet",
					"MP5K_silencerInteriorTail_SoundSet"
				}
			};
			begin1[]=
			{
				"dz\sounds\weapons\firearms\mp5k\mp5k_single_0",
				1,
				1,
				900
			};
			begin2[]=
			{
				"dz\sounds\weapons\firearms\mp5k\mp5k_single_1",
				1,
				1,
				900
			};
			begin3[]=
			{
				"dz\sounds\weapons\firearms\mp5k\mp5k_single_2",
				1,
				1,
				900
			};
			soundBegin[]=
			{
				"begin1",
				0.33333001,
				"begin2",
				0.33333001,
				"begin3",
				0.33333001
			};
			reloadTime=0.067000002;
			recoil="recoil_mp5";
			recoilProne="recoil_mp5_prone";
			dispersion=0.003;
			magazineSlot="magazine";
			beginSilenced_Pro[]=
			{
				"dz\sounds\weapons\firearms\mp5k\mp5Silenced",
				1,
				1,
				75
			};
			beginSilenced_HomeMade[]=
			{
				"dz\sounds\weapons\firearms\mp5k\mp5Silenced",
				1,
				1,
				100
			};
			soundBeginExt[]=
			{
				
				{
					"beginSilenced_Pro",
					1
				},
				
				{
					"beginSilenced_HomeMade",
					1
				}
			};
		};
	};
	class SC_AutoGlock19: SC_AutoGlock19_Base
	{
		scope=2;
		displayName="SausageCo AutoGlock19";
		descriptionShort="A Glock19 modified by SausageCo to fire automatic.";
		model="\dz\weapons\pistols\glock\Glock19.p3d";
		attachments[]=
		{
			"pistolOptics",
			"pistolFlashlight",
			"pistolMuzzle"
		};
		itemSize[]={2,1};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=750;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\pistols\glock\data\glock19.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\pistols\glock\data\glock19.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\pistols\glock\data\glock19_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\pistols\glock\data\glock19_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\pistols\glock\data\glock19_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlashForward
				{
					ignoreIfSuppressed=1;
					illuminateWorld=1;
					overrideParticle="weapon_shot_fnx_01";
				};
				class SmokeCloud
				{
					overrideParticle="weapon_shot_winded_smoke_small";
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating=1;
				maxOverheatingValue=7;
				overheatingDecayInterval=1;
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen=1;
					overrideParticle="smoking_barrel_small";
					overridePoint="Nabojnicestart";
				};
			};
			class OnBulletCasingEject
			{
				class ChamberSmokeRaise
				{
					overrideParticle="weapon_shot_chamber_smoke_raise";
					overridePoint="Nabojnicestart";
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
		model="SausageCo\Objects\ExperienceCurrency\data\SausageXP.p3d";
	};
	class ProxyGlock: ProxyAttachment
	{
		scope=2;
		inventorySlot="pistol";
		model="\dz\weapons\pistols\glock\Glock19.p3d";
	};
};