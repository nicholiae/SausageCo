class CfgPatches
{
	class SC_Weapons_Firearms_SCARL
	{
		units[]=
		{
			"SC_SCARL"
		};
		weapons[]=
		{
			
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_data",
			"DZ_Weapons_Firearms"
		};
	};
};
class cfgSlots
{
	class Slot_ButtStockSC_SCARL
	{
		name="ButtStockSC_SCARL";
		displayName="ButtStockSC_SCARL";
		ghostIcon="buttstock";
	};
	class Slot_MagSC_Barret
	{
		name="MagSC_Barret";
		displayName="MagSC_Barret";
		ghostIcon="magazine";
	};
	class Slot_MagSC_DMR
	{
		name="MagSC_DMR";
		displayName="MagSC_DMR";
		ghostIcon="magazine";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class ItemSuppressor: Inventory_Base
	{};
	class M4_Suppressor: ItemSuppressor
	{
		itemSize[]={2,1};
	};
	class SausageCo_UniSilencer: M4_Suppressor
	{
		scope=2;
		displayName="SausageCo Universal Silencer";
		descriptionShort="Universal Silencer can be attached to any gun of any calibre";
		model="SausageCo\weapons\attachments\silencers\SCuni_silencer.p3d";
		inventorySlot[]=
		{
			"suppressorImpro",
			"weaponMuzzleAK",
			"weaponMuzzleM4",
			"pistolMuzzle"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\weapons\attachments\silencers\data\glossblack_co.paa"
		};
		noiseShootModifier="-0.5 * 8";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=7500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\weapons\attachments\silencers\data\uni_silencer.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\weapons\attachments\silencers\data\uni_silencer.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\weapons\attachments\silencers\data\uni_silencer.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\weapons\attachments\silencers\data\uni_silencer.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\weapons\attachments\silencers\data\uni_silencer.rvmat"
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
class OpticsInfoPistol;
class cfgWeapons
{
	class Rifle_Base;
	class Launcher_Base;
	class BoltActionRifle_Base;
	class AKM_Base: Rifle_Base
	{};
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
	class FNX45_Base: Pistol_Base
	{};
	class SC_Auto_FNX45_Base: FNX45_Base
	{
		scope=0;
		weight=950;
		absorbency=0;
		repairableWithKits[]={1};
		repairCosts[]={25};
		PPDOFProperties[]={1,0.5,10,250,4,10};
		ironsightsExcludingOptics[]=
		{
			"FNP45_MRDSOptic"
		};
		WeaponLength=0.634148;
		barrelArmor=0.75;
		chamberSize=1;
		chamberedRound="";
		magazines[]=
		{
			"Mag_FNX45_15Rnd",
			"SC_Mag_AutoFNX_45Rnd"
		};
		chamberableFrom[]=
		{
			"Ammo_45ACP"
		};
		ejectType=1;
		recoilModifier[]={1,1,1};
		swayModifier[]={1.3,1.3,0.80000001};
		drySound[]=
		{
			"dz\sounds\weapons\firearms\FNX45\FNX45_dry",
			0.5,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"dz\sounds\weapons\firearms\FNX45\FNX45_reload",
			0.80000001,
			1,
			20
		};
		modes[]=
		{
			"FullAuto",
			"SemiAuto"
		};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[]=
			{
				"FNX45_Shot_SoundSet",
				"FNX45_Tail_SoundSet",
				"FNX45_InteriorTail_SoundSet"
			};
			soundSetShotExt[]=
			{
				
				{
					"FNX45_silencerPro_SoundSet",
					"FNX45_silencerTail_SoundSet",
					"FNX45_silencerInteriorTail_SoundSet"
				}
			};
			begin1[]=
			{
				"dz\sounds\weapons\firearms\FNX45\FNX45_single_1",
				1,
				1,
				600
			};
			begin2[]=
			{
				"dz\sounds\weapons\firearms\FNX45\FNX45_single_2",
				1,
				1,
				600
			};
			soundBegin[]=
			{
				"begin1",
				0.33333001,
				"begin2",
				0.33333001,
				"begin2",
				0.33333001
			};
			reloadTime=0.125;
			recoil="recoil_fnx";
			recoilProne="recoil_fnx_prone";
			dispersion=0.003;
			magazineSlot="magazine";
			beginSilenced_Pro[]=
			{
				"dz\sounds\weapons\firearms\colt1911\1911Silenced",
				1,
				1,
				60
			};
			beginSilenced_HomeMade[]=
			{
				"dz\sounds\weapons\firearms\colt1911\1911Silenced",
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
		class NoiseShoot
		{
			strength=50;
			type="shot";
		};
		class OpticsInfo: OpticsInfoPistol
		{
			memoryPointCamera="eye";
			discreteDistance[]={25};
			discreteDistanceInitIndex=0;
			modelOptics="-";
			distanceZoomMin=100;
			distanceZoomMax=100;
		};
	};
	class SC_Auto_FNX45: SC_Auto_FNX45_Base
	{
		
		scope=2;
		displayName="SausageCo Auto FNX";
		descriptionShort="Modified FNX to run full auto!";
		model="\dz\weapons\pistols\fnx45\fnp45.p3d";
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
								"DZ\weapons\pistols\fnx45\data\herstal45.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\pistols\fnx45\data\herstal45.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\pistols\fnx45\data\herstal45_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\pistols\fnx45\data\herstal45_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\pistols\fnx45\data\herstal45_destruct.rvmat"
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
	class SC_FNP90_Base: AKM_Base
	{
		
		scope=0;
		weight=1140;
		absorbency=0;
		repairableWithKits[]={1};
		repairCosts[]={25};
		PPDOFProperties[]={1,0.5,50,160,4,10};
		ironsightsExcludingOptics[]=
		{
			"KashtanOptic",
			"GrozaOptic",
			"KobraOptic"
		};
		WeaponLength=0.52906699;
		barrelArmor=2.4439998;
		chamberSize=1;
		chamberedRound="";
		chamberableFrom[]=
		{
			"Ammo_762x39",
			"Ammo_762x39Tracer"
		};
		magazines[]=
		{
			"SC_Mag_FNP90_25Rnd",
			"SC_Mag_FNP90_50Rnd"
		};
		magazineSwitchTime=0.12;
		ejectType=1;
		recoilModifier[]={.01,.01,.01};
		swayModifier[]={.02,.02,.01.01};
		simpleHiddenSelections[]=
		{
			
		};
		drySound[]=
		{
			"dz\sounds\weapons\firearms\SKS\SKS_dry",
			0.5,
			1,
			20
		};
		reloadAction="ReloadAKM";
		reloadMagazineSound[]=
		{
			"dz\sounds\weapons\firearms\akm\Akm_reload",
			0.80000001,
			1,
			20
		};
		hiddenSelections[]=
		{
			"camo"
		};
		modes[]=
		{
			"FullAuto",
			"Burst",
			"SemiAuto"
		};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[]=
			{
				"AK_Shot_SoundSet",
				"AK_Tail_SoundSet",
				"AK_InteriorTail_SoundSet"
			};
			soundSetShotExt[]=
			{
				
				{
					"AK_silencer_SoundSet",
					"AK_silencerTail_SoundSet",
					"AK_silencerInteriorTail_SoundSet"
				},
				
				{
					"AK_silencerHomeMade_SoundSet",
					"AK_silencerHomeMadeTail_SoundSet",
					"AK_silencerInteriorHomeMadeTail_SoundSet"
				}
			};
			begin1[]=
			{
				"dz\sounds\weapons\firearms\akm\Akm_single_0",
				1,
				1,
				900
			};
			begin2[]=
			{
				"dz\sounds\weapons\firearms\akm\Akm_single_1",
				1,
				1,
				900
			};
			begin3[]=
			{
				"dz\sounds\weapons\firearms\akm\Akm_single_2",
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
				"begin2",
				0.33333001
			};
			reloadTime=0.0125;
			recoil="recoil_AKM";
			recoilProne="recoil_AKM_prone";
			dispersion=0.000015;
			magazineSlot="magazine";
			beginSilenced_Pro[]=
			{
				"dz\sounds\weapons\firearms\AK101\akSilenced",
				1,
				1,
				200
			};
			beginSilenced_HomeMade[]=
			{
				"dz\sounds\weapons\firearms\AK101\akSilenced",
				1,
				1,
				300
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
		class Burst: Mode_Burst
		{
			soundSetShot[]=
			{
				"AK_Shot_SoundSet",
				"AK_Tail_SoundSet",
				"AK_InteriorTail_SoundSet"
			};
			reloadTime=0.00000001;
			dispersion=0.00000001;
			magazineSlot="magazine";
		};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[]=
			{
				"AK_Shot_SoundSet",
				"AK_Tail_SoundSet",
				"AK_InteriorTail_SoundSet"
			};
			soundSetShotExt[]=
			{
				
				{
					"AK_silencer_SoundSet",
					"AK_silencerTail_SoundSet",
					"AK_silencerInteriorTail_SoundSet"
				},
				
				{
					"AK_silencerHomeMade_SoundSet",
					"AK_silencerHomeMadeTail_SoundSet",
					"AK_silencerInteriorHomeMadeTail_SoundSet"
				}
			};
			begin1[]=
			{
				"dz\sounds\weapons\firearms\akm\Akm_single_0",
				1,
				1,
				900
			};
			begin2[]=
			{
				"dz\sounds\weapons\firearms\akm\Akm_single_1",
				1,
				1,
				900
			};
			begin3[]=
			{
				"dz\sounds\weapons\firearms\akm\Akm_single_2",
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
				"begin2",
				0.33333001
			};
			reloadTime=0.05;
			recoil="recoil_AKM";
			recoilProne="recoil_AKM_prone";
			dispersion=0.00015;
			magazineSlot="magazine";
			beginSilenced_Pro[]=
			{
				"dz\sounds\weapons\firearms\AK101\akSilenced",
				1,
				1,
				200
			};
			beginSilenced_HomeMade[]=
			{
				"dz\sounds\weapons\firearms\AK101\akSilenced",
				1,
				1,
				300
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
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera="eye";
			discreteDistance[]={100,200,300,400,500,600,700,800,900,1000};
			discreteDistanceInitIndex=0;
			modelOptics="-";
			distanceZoomMin=100;
			distanceZoomMax=1000;
		};
	};
	class SC_FNP90: SC_FNP90_Base
	{
		scope=2;
		displayName="FNP90";
		descriptionShort="A FNP90 made by SausageCo! Does the shoosting in 762x39!";
		model="SausageCo\Weapons\FNP90.p3d";
		attachments[]=
		{
			
		};
		itemSize[]={4,1};
		spawnDamageRange[]={0,0.30000002};
		hiddenSelections[]=
		{
			"polymerSelect",
			"blackmetalSelect",
			"aluminumSelect"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Weapons\data\polymer.paa",
			"SausageCo\Weapons\data\blackmetal.paa",
			"SausageCo\Weapons\data\aluminum.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\Weapons\data\polymer.rvmat",
			"SausageCo\Weapons\data\blackmetal.rvmat",
			"SausageCo\Weapons\data\aluminum.rvmat"
		};
		class Particles
		{
			class OnFire
			{
				class SmokeCloud
				{
					overrideParticle="weapon_shot_winded_smoke";
				};
				class MuzzleFlash
				{
					overrideParticle="weapon_shot_ump45_01";
					ignoreIfSuppressed=1;
					illuminateWorld=1;
				};
				class ChamberSmokeBurst
				{
					overrideParticle="weapon_shot_chamber_smoke";
					overridePoint="Nabojnicestart";
					overrideDirectionPoint="Nabojniceend";
				};
			};
			class OnOverheating
			{
				maxOverheatingValue=160;
				shotsToStartOverheating=12;
				overheatingDecayInterval=.2;
				class SmokingBarrel1
				{
					positionOffset[]={0.2,0,0};
					overrideParticle="smoking_barrel_small";
					onlyWithinOverheatLimits[]={0,0.2};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHot1
				{
					positionOffset[]={0.2,0,0};
					overrideParticle="smoking_barrel";
					onlyWithinOverheatLimits[]={0.2,0.60000002};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHot3
				{
					positionOffset[]={0.2,0,0};
					overrideParticle="smoking_barrel_heavy";
					onlyWithinOverheatLimits[]={0.60000002,1};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHotSteam
				{
					overrideParticle="smoking_barrel_steam";
					positionOffset[]={0.34999999,0,0};
					onlyWithinOverheatLimits[]={0,1};
					onlyWithinRainLimits[]={0.2,1};
				};
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
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\blackmetal.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\blackmetal.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\blackmetal.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\blackmetal.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\blackmetal.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class M4A1_Base: Rifle_Base
	{};
	class SC_SCARL_Base: M4A1_Base
	{
		scope=0;
		weight=1332;
		absorbency=0;
		repairableWithKits[]={1};
		repairCosts[]={10};
		PPDOFProperties[]={1,0.60000002,50,200,4,10};
		ironsightsExcludingOptics[]=
		{
			"M4_CarryHandleOptic",
			"BUISOptic",
			"M68Optic",
			"M4_T3NRDSOptic",
			"ReflexOptic",
			"ACOGOptic"
		};
		WeaponLength=0.81478399;
		barrelArmor=3.75;
		chamberSize=1;
		chamberedRound="";
		chamberableFrom[]=
		{
			"Ammo_556x45",
			"Ammo_556x45Tracer"
		};
		magazines[]=
		{
			"SC_Mag_SCARL_30Rnd",
			"SC_Mag_SCARL_60Rnd",
			"SC_Mag_SCARL_100RndDrum",
			"Mag_STANAG_30Rnd",
			"Mag_STANAGCoupled_30Rnd",
			"Mag_CMAG_10Rnd",
			"Mag_CMAG_20Rnd",
			"Mag_CMAG_30Rnd",
			"Mag_CMAG_40Rnd",
			"Mag_CMAG_10Rnd_Green",
			"Mag_CMAG_20Rnd_Green",
			"Mag_CMAG_30Rnd_Green",
			"Mag_CMAG_40Rnd_Green",
			"Mag_CMAG_10Rnd_Black",
			"Mag_CMAG_20Rnd_Black",
			"Mag_CMAG_30Rnd_Black",
			"Mag_CMAG_40Rnd_Black"
		}; 
		magazineSwitchTime=0.15;
		ejectType=1;
		recoilModifier[]={1,1,1};
		swayModifier[]={2,2,1.1};
		simpleHiddenSelections[]=
		{
			
		};
		drySound[]=
		{
			"dz\sounds\weapons\firearms\m4a1\m4_dry",
			0.5,
			1,
			20
		};
		reloadAction="ReloadM4";
		reloadMagazineSound[]=
		{
			"dz\sounds\weapons\firearms\m4a1\m4_reload_0",
			0.80000001,
			1,
			20
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		modes[]=
		{
			"FullAuto",
			"SemiAuto"
		};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[]=
			{
				"M4_Shot_SoundSet",
				"M4_Tail_SoundSet",
				"M4_InteriorTail_SoundSet"
			};
			soundSetShotExt[]=
			{
				
				{
					"M4_silencer_SoundSet",
					"M4_silencerTail_SoundSet",
					"M4_silencerInteriorTail_SoundSet"
				},
				
				{
					"M4_silencerHomeMade_SoundSet",
					"M4_silencerHomeMadeTail_SoundSet",
					"M4_silencerInteriorHomeMadeTail_SoundSet"
				}
			};
			begin1[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4_single_1",
				1,
				1,
				1000
			};
			begin2[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4_single_2",
				1,
				1,
				1000
			};
			begin3[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4_single_3",
				1,
				1,
				1000
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
			recoil="recoil_m4";
			recoilProne="recoil_m4_prone";
			dispersion=0.00125;
			magazineSlot="magazine";
			beginSilenced_Pro1[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4Silenced",
				1,
				1,
				75
			};
			beginSilenced_Pro2[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4Silenced2",
				1,
				1,
				75
			};
			beginSilenced_HomeMade[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4Silenced",
				1,
				1,
				150
			};
			soundBeginExt[]=
			{
				
				{
					"beginSilenced_Pro1",
					0.5,
					"beginSilenced_Pro2",
					0.5
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
				"M4_Shot_SoundSet",
				"M4_Tail_SoundSet",
				"M4_InteriorTail_SoundSet"
			};
			soundSetShotExt[]=
			{
				
				{
					"M4_silencer_SoundSet",
					"M4_silencerTail_SoundSet",
					"M4_silencerInteriorTail_SoundSet"
				},
				
				{
					"M4_silencerHomeMade_SoundSet",
					"M4_silencerHomeMadeTail_SoundSet",
					"M4_silencerInteriorHomeMadeTail_SoundSet"
				}
			};
			begin1[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4_single_1",
				1.7782794,
				1,
				1000
			};
			begin2[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4_single_2",
				1.7782794,
				1,
				1000
			};
			begin3[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4_single_3",
				1.7782794,
				1,
				1000
			};
			soundBegin[]=
			{
				"begin1",
				0.33333001,
				"begin2",
				0.33333001,
				"begin2",
				0.33333001
			};
			reloadTime=0.035000003;
			recoil="recoil_m4";
			recoilProne="recoil_m4_prone";
			dispersion=0.00025;
			magazineSlot="magazine";
			beginSilenced_Pro1[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4Silenced",
				1,
				1,
				75
			};
			beginSilenced_Pro2[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4Silenced2",
				1,
				1,
				75
			};
			beginSilenced_HomeMade[]=
			{
				"ddz\sounds\weapons\firearms\m4a1\m4Silenced",
				1,
				1,
				150
			};
			soundBeginExt[]=
			{
				
				{
					"beginSilenced_Pro1",
					0.5,
					"beginSilenced_Pro2",
					0.5
				},
				
				{
					"beginSilenced_HomeMade",
					1
				}
			};
		};
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera="eye";
			discreteDistance[]={25};
			discreteDistanceInitIndex=0;
			modelOptics="-";
			distanceZoomMin=25;
			distanceZoomMax=25;
		};
	};
	class SC_SCARL: SC_SCARL_Base
	{
		scope=2;
		displayName="SCAR-L";
		descriptionShort="A SCAR-L made by SausageCo! Does the shoosting in 556x45!";
		model="SausageCo\Weapons\SCAR_L.p3d";
		attachments[]=
		{
			"ButtStockSC_SCARL",
			"weaponOptics",
			"weaponMuzzleM4"
		};
		itemSize[]={5,1};
		spawnDamageRange[]={0,0.60000002};
		hiddenSelections[]=
		{
			"zbytek",
			"mySelection",
			"myOtherSelection"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Weapons\data\Baige.paa",
			"SausageCo\Weapons\data\black.paa",
			"SausageCo\Weapons\data\black.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\Weapons\data\ScarL.rvmat",
			"SausageCo\Weapons\data\ScarL.rvmat",
			"SausageCo\Weapons\data\ScarL.rvmat"
		};
		class Particles
		{
			class OnFire
			{
				class SmokeCloud
				{
					overrideParticle="weapon_shot_winded_smoke";
				};
				class MuzzleFlash
				{
					overrideParticle="weapon_shot_ump45_01";
					ignoreIfSuppressed=1;
					illuminateWorld=1;
				};
				class ChamberSmokeBurst
				{
					overrideParticle="weapon_shot_chamber_smoke";
					overridePoint="Nabojnicestart";
					overrideDirectionPoint="Nabojniceend";
				};
			};
			class OnOverheating
			{
				maxOverheatingValue=60;
				shotsToStartOverheating=7;
				overheatingDecayInterval=1;
				class SmokingBarrel1
				{
					positionOffset[]={0.2,0,0};
					overrideParticle="smoking_barrel_small";
					onlyWithinOverheatLimits[]={0,0.2};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHot1
				{
					positionOffset[]={0.2,0,0};
					overrideParticle="smoking_barrel";
					onlyWithinOverheatLimits[]={0.2,0.60000002};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHot3
				{
					positionOffset[]={0.2,0,0};
					overrideParticle="smoking_barrel_heavy";
					onlyWithinOverheatLimits[]={0.60000002,1};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHotSteam
				{
					overrideParticle="smoking_barrel_steam";
					positionOffset[]={0.34999999,0,0};
					onlyWithinOverheatLimits[]={0,1};
					onlyWithinRainLimits[]={0.2,1};
				};
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
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat",
								"SausageCo\Weapons\data\ScarL.rvmat",
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat",
								"SausageCo\Weapons\data\ScarL.rvmat",
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat",
								"SausageCo\Weapons\data\ScarL.rvmat",
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat",
								"SausageCo\Weapons\data\ScarL.rvmat",
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat",
								"SausageCo\Weapons\data\ScarL.rvmat",
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_DMR_Base: M4A1_Base
	{
		scope=0;
		weight=1332;
		absorbency=0;
		repairableWithKits[]={1};
		repairCosts[]={10};
		PPDOFProperties[]={1,0.5,50,150,4,10};
		ironsightsExcludingOptics[]=
		{
			"HuntingOptic",
			"ACOGOptic"
		};
		WeaponLength=0.61478399;
		barrelArmor=3.75;
		chamberSize=1;
		chamberedRound="";
		chamberableFrom[]=
		{
			"Ammo_308Win",
			"Ammo_308WinTracer"
		};
		magazines[]=
		{
			"SC_Mag_DMR_20Rnd",
			"SC_Mag_DMR_20RndTracers"
		}; 
		magazineSwitchTime=0.15;
		ejectType=1;
		recoilModifier[]={1,1,1};
		swayModifier[]={2,2,1.1};
		simpleHiddenSelections[]=
		{
			
		};
		drySound[]=
		{
			"dz\sounds\weapons\firearms\m4a1\m4Silenced",
			0.5,
			1,
			20
		};
		reloadAction="ReloadM4";
		reloadMagazineSound[]=
		{
			"dz\sounds\weapons\firearms\m4a1\m4_reload_0",
			0.80000001,
			1,
			20
		};
		hiddenSelections[]=
		{
			"polymerSelect",
			"alumSelect",
			"blackmetalSelect",
			"goldRoughSelect"
		};
		modes[]=
		{
			"SemiAuto"
		};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[]=
			{
				"M4_silencer_SoundSet",
				"M4_silencerTail_SoundSet",
				"M4_silencerInteriorTail_SoundSet"
			};
			begin1[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4Silenced",
				1,
				1,
				100
			};
			begin2[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4Silenced",
				1,
				1,
				100
			};
			begin3[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4Silenced",
				1,
				1,
				100
			};
			soundBegin[]=
			{
				"begin1",
				0.33333001,
				"begin2",
				0.33333001,
				"begin2",
				0.33333001
			};
			reloadTime=0.125;
			recoil="recoil_m4";
			recoilProne="recoil_m4_prone";
			dispersion=0.00125;
			magazineSlot="magazine";
			beginSilenced_Pro1[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4Silenced",
				0.30000001,
				1,
				75
			};
			soundBeginExt[]=
			{
				
				{
					"beginSilenced_Pro1",
					1
				}
			};
		};
		class NoiseShoot
		{
			strength=2;
			type="shot";
		};
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera="eye";
			discreteDistance[]={25};
			discreteDistanceInitIndex=0;
			modelOptics="-";
			distanceZoomMin=25;
			distanceZoomMax=25;
		};
	};
	class SC_DMR: SC_DMR_Base
	{
		scope=2;
		displayName="DMR";
		descriptionShort="A DMR made by SausageCo! Does the shoosting in 308Win and has an integrated Silencer!";
		model="SausageCo\Weapons\DMR.p3d";
		attachments[]=
		{
			"weaponOptics",
			"weaponOpticsHunting"
		};
		itemSize[]={5,1};
		spawnDamageRange[]={0,0.60000002};
		hiddenSelections[]=
		{
			"polymerSelect",
			"alumSelect",
			"blackmetalSelect",
			"goldRoughSelect"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Weapons\data\polymer.paa",
			"SausageCo\Weapons\data\aluminum.paa",
			"SausageCo\Weapons\data\blackMetal.paa",
			"SausageCo\Weapons\data\goldRough.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\Weapons\data\polymer.rvmat",
			"SausageCo\Weapons\data\aluminum.rvmat",
			"SausageCo\Weapons\data\blackMetal.rvmat",
			"SausageCo\Weapons\data\goldRough.rvmat"
		};
		class Particles
		{
			class OnFire
			{
				class SmokeCloud
				{
					overrideParticle="weapon_shot_winded_smoke";
				};
				class MuzzleFlash
				{
					overrideParticle="weapon_shot_ump45_01";
					ignoreIfSuppressed=1;
					illuminateWorld=1;
				};
				class ChamberSmokeBurst
				{
					overrideParticle="weapon_shot_chamber_smoke";
					overridePoint="Nabojnicestart";
					overrideDirectionPoint="Nabojniceend";
				};
			};
			class OnOverheating
			{
				maxOverheatingValue=60;
				shotsToStartOverheating=7;
				overheatingDecayInterval=1;
				class SmokingBarrel1
				{
					positionOffset[]={0.2,0,0};
					overrideParticle="smoking_barrel_small";
					onlyWithinOverheatLimits[]={0,0.2};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHot1
				{
					positionOffset[]={0.2,0,0};
					overrideParticle="smoking_barrel";
					onlyWithinOverheatLimits[]={0.2,0.60000002};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHot3
				{
					positionOffset[]={0.2,0,0};
					overrideParticle="smoking_barrel_heavy";
					onlyWithinOverheatLimits[]={0.60000002,1};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHotSteam
				{
					overrideParticle="smoking_barrel_steam";
					positionOffset[]={0.34999999,0,0};
					onlyWithinOverheatLimits[]={0,1};
					onlyWithinRainLimits[]={0.2,1};
				};
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
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat",
								"SausageCo\Weapons\data\blackMetal.rvmat",
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat",
								"SausageCo\Weapons\data\blackMetal.rvmat",
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat",
								"SausageCo\Weapons\data\blackMetal.rvmat",
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat",
								"SausageCo\Weapons\data\blackMetal.rvmat",
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat",
								"SausageCo\Weapons\data\blackMetal.rvmat",
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class CZ527_Base: BoltActionRifle_Base
	{};
	class SC_Barret_Base: CZ527_Base
	{
		scope=0;
		weight=2720;
		absorbency=0;
		repairableWithKits[]={1};
		repairCosts[]={25};
		modelOptics="-";
		distanceZoomMin=100;
		distanceZoomMax=100;
		PPDOFProperties[]={1,0.5,50,160,4,10};
		opticsFlare=0;
		winchesterTypeOpticsMount=1;
		ironsightsExcludingOptics[]=
		{
			"HuntingOptic"
		};
		WeaponLength=0.95;
		barrelArmor=1.5;
		chamberSize=1;
		chamberedRound="";
		chamberableFrom[]=
		{
			"Ammo_308Win",
			"Ammo_308WinTracer"
		};
		magazines[]=
		{
			"SC_Mag_Barret_10rnd"
		};
		magazineSwitchTime=0.18;
		ejectType=0;
		recoilModifier[]={1,1,1};
		swayModifier[]={1.2,2.2,1.2};
		simpleHiddenSelections[]=
		{
			"hide_barrel"
		};
		drySound[]=
		{
			"dz\sounds\weapons\firearms\mosin9130\mosin_dry",
			0.5,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"dz\sounds\weapons\firearms\CR527\SC_Barret_reload_0",
			1,
			1,
			20
		};
		reloadSound[]=
		{
			"dz\sounds\weapons\firearms\CR527\SC_Barret_cycling_0",
			1,
			1,
			20
		};
		reloadAction="ReloadSC_Barret";
		shotAction="ReloadSC_BarretShot";
		hiddenSelections[]=
		{
			"polymerSelect",
			"alumSelect",
			"darkSelect"
		};
		modes[]=
		{
			"Single"
		};
		class Single: Mode_SemiAuto
		{
			soundSetShot[]=
			{
				"CR527_Shot_SoundSet",
				"CR527_Tail_SoundSet",
				"CR527_InteriorTail_SoundSet"
			};
			soundSetShotExt[]=
			{
				
				{
					"CR527_silencerHomeMade_SoundSet",
					"CR527_silencerHomeMadeTail_SoundSet",
					"CR527_silencerInteriorHomeMadeTail_SoundSet"
				}
			};
			begin1[]=
			{
				"dz\sounds\weapons\firearms\SC_Barret\SC_Barret_single_0",
				1,
				1,
				1000
			};
			begin2[]=
			{
				"dz\sounds\weapons\firearms\SC_Barret\SC_Barret_single_1",
				1,
				1,
				1000
			};
			begin3[]=
			{
				"dz\sounds\weapons\firearms\SC_Barret\SC_Barret_single_2",
				1,
				1,
				1000
			};
			soundBegin[]=
			{
				"begin1",
				0.33333001,
				"begin2",
				0.33333001,
				"begin2",
				0.33333001
			};
			beginSilenced_HomeMade[]=
			{
				"dz\sounds\weapons\firearms\m4a1\m4Silenced",
				1,
				1,
				150
			};
			soundBeginExt[]=
			{
				
				{
					"beginSilenced_HomeMade",
					1
				}
			};
			reloadTime=1;
			recoil="recoil_SC_Barret";
			recoilProne="recoil_SC_Barret_prone";
			dispersion=0.001;
			magazineSlot="magazine";
		};
		class Particles
		{
			class OnFire
			{
				class SmokeCloud
				{
					overrideParticle="weapon_shot_winded_smoke";
				};
				class MuzzleFlash
				{
					overrideParticle="weapon_shot_SC_Barret_01";
					ignoreIfSuppressed=1;
					illuminateWorld=1;
					positionOffset[]={-0.050000001,0,0};
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating=6;
				maxOverheatingValue=8;
				overheatingDecayInterval=2;
				class BarrelSmoke
				{
					overrideParticle="smoking_barrel_small";
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
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera="eye";
			modelOptics="-";
			distanceZoomMin=200;
			distanceZoomMax=200;
			discreteDistance[]={200};
			discreteDistanceInitIndex=0;
		};
	};
	class SC_Barret: SC_Barret_Base
	{
		scope=2;
		displayName="SausageCo Barret 308";
		descriptionShort="A 50.cal barret modified for 308Win rounds.";
		model="SausageCo\Weapons\Barret.p3d";
		attachments[]=
		{
			"weaponOpticsHunting"
		};
		itemSize[]={6,2};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Weapons\data\polymer.paa",
			"SausageCo\Weapons\data\aluminum.paa",
			"SausageCo\Weapons\data\aluminumDark.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\Weapons\data\polymer.rvmat",
			"SausageCo\Weapons\data\aluminum.rvmat",
			"SausageCo\Weapons\data\aluminumDark.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat",
								"SausageCo\Weapons\data\aluminumDark.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat",
								"SausageCo\Weapons\data\aluminumDark.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat",
								"SausageCo\Weapons\data\aluminumDark.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat",
								"SausageCo\Weapons\data\aluminumDark.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Weapons\data\polymer.rvmat",
								"SausageCo\Weapons\data\aluminum.rvmat",
								"SausageCo\Weapons\data\aluminumDark.rvmat"
							}
						}
					};
				};
			};
		};
	};
};
class CfgMagazines
{
	class DefaultMagazine;
	class Magazine_Base: DefaultMagazine
	{
		
	};
	class Mag_Glock_15Rnd: Magazine_Base
	{};
	class SC_Mag_AutoGlock_45Rnd: Mag_Glock_15Rnd
	{
		scope=2;
		displayName="SausageCo AutoGlockMag";
		descriptionShort="AutoGlockMag 45 round capacity modified by SausageCo!";
		model="\DZ\weapons\attachments\magazine\magazine_glock19.p3d";
		weight=131;
		itemSize[]={1,1};
		inventorySlot[]=
		{
			"magazine",
			"magazine2",
			"magazine3",
			"Magazine9x19",
			"Magazine9x19_2"
		};
		count=45;
		ammo="Bullet_9x19";
		ammoItems[]=
		{
			"Ammo_9x19"
		};
		tracersEvery=0;
		mass=10;
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
								"DZ\weapons\attachments\magazine\data\glock19_mag.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\attachments\magazine\data\glock19_mag.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\attachments\magazine\data\glock19_mag_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\attachments\magazine\data\glock19_mag_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\attachments\magazine\data\glock19_mag_destruct.rvmat"
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
				class MagRifle_fill_in
				{
					soundSet="MagRifle_fill_in_SoundSet";
					id=1;
				};
				class MagRifle_fill_loop
				{
					soundSet="MagRifle_fill_loop_SoundSet";
					id=2;
				};
				class MagRifle_fill_out
				{
					soundSet="MagRifle_fill_out_SoundSet";
					id=3;
				};
				class MagRifle_empty_in
				{
					soundSet="MagRifle_empty_in_SoundSet";
					id=4;
				};
				class MagRifle_empty_loop
				{
					soundSet="MagRifle_empty_loop_SoundSet";
					id=5;
				};
				class MagRifle_empty_out
				{
					soundSet="MagRifle_empty_out_SoundSet";
					id=6;
				};
				class MagPistol_fill_in
				{
					soundSet="MagPistol_fill_in_SoundSet";
					id=7;
				};
				class MagPistol_fill_loop
				{
					soundSet="MagPistol_fill_loop_SoundSet";
					id=8;
				};
				class MagPistol_fill_out
				{
					soundSet="MagPistol_fill_out_SoundSet";
					id=9;
				};
				class MagPistol_empty_in
				{
					soundSet="MagPistol_empty_in_SoundSet";
					id=10;
				};
				class MagPistol_empty_loop
				{
					soundSet="MagPistol_empty_loop_SoundSet";
					id=11;
				};
				class MagPistol_empty_out
				{
					soundSet="MagPistol_empty_out_SoundSet";
					id=12;
				};
			};
		};
	};
	class Mag_FNX45_15Rnd: Magazine_Base
	{};
	class SC_Mag_AutoFNX_45Rnd: Magazine_Base
	{
		scope=2;
		displayName="Auto FNX45 Mag";
		descriptionShort="45 ACP auto modified";
		model="\DZ\weapons\attachments\magazine\magazine_fnp45.p3d";
		weight=113;
		itemSize[]={1,2};
		count=45;
		ammo="Bullet_45ACP";
		inventorySlot[]=
		{
			"magazine",
			"magazine2",
			"magazine3",
			"Magazine45ACP",
			"Magazine45ACP_2"
		};
		ammoItems[]=
		{
			"Ammo_45ACP"
		};
		tracersEvery=0;
		mass=10;
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
								"DZ\weapons\pistols\fnx45\data\herstal45.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\pistols\fnx45\data\herstal45.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\pistols\fnx45\data\herstal45_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\pistols\fnx45\data\herstal45_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\pistols\fnx45\data\herstal45_destruct.rvmat"
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
				class MagRifle_fill_in
				{
					soundSet="MagRifle_fill_in_SoundSet";
					id=1;
				};
				class MagRifle_fill_loop
				{
					soundSet="MagRifle_fill_loop_SoundSet";
					id=2;
				};
				class MagRifle_fill_out
				{
					soundSet="MagRifle_fill_out_SoundSet";
					id=3;
				};
				class MagRifle_empty_in
				{
					soundSet="MagRifle_empty_in_SoundSet";
					id=4;
				};
				class MagRifle_empty_loop
				{
					soundSet="MagRifle_empty_loop_SoundSet";
					id=5;
				};
				class MagRifle_empty_out
				{
					soundSet="MagRifle_empty_out_SoundSet";
					id=6;
				};
				class MagPistol_fill_in
				{
					soundSet="MagPistol_fill_in_SoundSet";
					id=7;
				};
				class MagPistol_fill_loop
				{
					soundSet="MagPistol_fill_loop_SoundSet";
					id=8;
				};
				class MagPistol_fill_out
				{
					soundSet="MagPistol_fill_out_SoundSet";
					id=9;
				};
				class MagPistol_empty_in
				{
					soundSet="MagPistol_empty_in_SoundSet";
					id=10;
				};
				class MagPistol_empty_loop
				{
					soundSet="MagPistol_empty_loop_SoundSet";
					id=11;
				};
				class MagPistol_empty_out
				{
					soundSet="MagPistol_empty_out_SoundSet";
					id=12;
				};
			};
		};
	};
	class SC_Mag_FNP90_25Rnd: Magazine_Base
	{
		scope=2;
		displayName="SC FNP90 Mag";
		descriptionShort="SausageCo made 25Rnd FNP90 magazine. Loads 762x39";
		model="SausageCo\Weapons\attachments\Magazine\SC_Mag_FNP90_25Rnd.p3d";
		weight=90;
		itemSize[]={1,2};
		count=25;
		ammo="Bullet_762x39";
		inventorySlot[]=
		{
			"magazine",
			"magazine2",
			"magazine3",
			"Magazine762x39",
			"Magazine762x39_2"
		};
		ammoItems[]=
		{
			"Ammo_762x39",
			"Ammo_762x39Tracer"
		};
		tracersEvery=0;
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
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Weapons\data\goldRough.rvmat"
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
				class MagRifle_fill_in
				{
					soundSet="MagRifle_fill_in_SoundSet";
					id=1;
				};
				class MagRifle_fill_loop
				{
					soundSet="MagRifle_fill_loop_SoundSet";
					id=2;
				};
				class MagRifle_fill_out
				{
					soundSet="MagRifle_fill_out_SoundSet";
					id=3;
				};
				class MagRifle_empty_in
				{
					soundSet="MagRifle_empty_in_SoundSet";
					id=4;
				};
				class MagRifle_empty_loop
				{
					soundSet="MagRifle_empty_loop_SoundSet";
					id=5;
				};
				class MagRifle_empty_out
				{
					soundSet="MagRifle_empty_out_SoundSet";
					id=6;
				};
				class MagPistol_fill_in
				{
					soundSet="MagPistol_fill_in_SoundSet";
					id=7;
				};
				class MagPistol_fill_loop
				{
					soundSet="MagPistol_fill_loop_SoundSet";
					id=8;
				};
				class MagPistol_fill_out
				{
					soundSet="MagPistol_fill_out_SoundSet";
					id=9;
				};
				class MagPistol_empty_in
				{
					soundSet="MagPistol_empty_in_SoundSet";
					id=10;
				};
				class MagPistol_empty_loop
				{
					soundSet="MagPistol_empty_loop_SoundSet";
					id=11;
				};
				class MagPistol_empty_out
				{
					soundSet="MagPistol_empty_out_SoundSet";
					id=12;
				};
			};
		};
	};
	class SC_Mag_FNP90_50Rnd: SC_Mag_FNP90_25Rnd
	{
		descriptionShort="SausageCo made 50Rnd FNP90 magazine. Loads 762x39";
		model="SausageCo\Weapons\attachments\Magazine\SC_Mag_FNP90_25Rnd.p3d";
		weight=90;
		itemSize[]={1,3};
		count=50;
	};
	class SC_Mag_DMR_20RndTracers: Magazine_Base
	{
		scope=2;
		displayName="SC DMR Tracers Mag";
		descriptionShort="SausageCo made 20Rnd DMR magazine. Loads 308 Tracers";
		model="SausageCo\Weapons\attachments\Magazine\SC_Mag_DMR_20Rnd.p3d";
		weight=90;
		itemSize[]={1,2};
		count=20;
		ammo="Bullet_308Win";
		inventorySlot[]=
		{
			"magazine",
			"magazine2",
			"magazine3",
			"Magazine308Win",
			"Magazine308Win_2"
		};
		ammoItems[]=
		{
			"Ammo_308WinTracer"
		};
		tracersEvery=1;
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
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Weapons\data\goldRough.rvmat"
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
				class MagRifle_fill_in
				{
					soundSet="MagRifle_fill_in_SoundSet";
					id=1;
				};
				class MagRifle_fill_loop
				{
					soundSet="MagRifle_fill_loop_SoundSet";
					id=2;
				};
				class MagRifle_fill_out
				{
					soundSet="MagRifle_fill_out_SoundSet";
					id=3;
				};
				class MagRifle_empty_in
				{
					soundSet="MagRifle_empty_in_SoundSet";
					id=4;
				};
				class MagRifle_empty_loop
				{
					soundSet="MagRifle_empty_loop_SoundSet";
					id=5;
				};
				class MagRifle_empty_out
				{
					soundSet="MagRifle_empty_out_SoundSet";
					id=6;
				};
				class MagPistol_fill_in
				{
					soundSet="MagPistol_fill_in_SoundSet";
					id=7;
				};
				class MagPistol_fill_loop
				{
					soundSet="MagPistol_fill_loop_SoundSet";
					id=8;
				};
				class MagPistol_fill_out
				{
					soundSet="MagPistol_fill_out_SoundSet";
					id=9;
				};
				class MagPistol_empty_in
				{
					soundSet="MagPistol_empty_in_SoundSet";
					id=10;
				};
				class MagPistol_empty_loop
				{
					soundSet="MagPistol_empty_loop_SoundSet";
					id=11;
				};
				class MagPistol_empty_out
				{
					soundSet="MagPistol_empty_out_SoundSet";
					id=12;
				};
			};
		};
	};
	class SC_Mag_DMR_20Rnd: Magazine_Base
	{
		scope=2;
		displayName="SC DMR Mag";
		descriptionShort="SausageCo made 20Rnd DMR magazine. Loads 308";
		model="SausageCo\Weapons\attachments\Magazine\SC_Mag_DMR_20Rnd.p3d";
		weight=90;
		itemSize[]={1,2};
		count=20;
		ammo="Bullet_308Win";
		inventorySlot[]=
		{
			"magazine",
			"magazine2",
			"magazine3",
			"Magazine308Win",
			"Magazine308Win_2"
		};
		ammoItems[]=
		{
			"Ammo_308Win",
			"Ammo_308WinTracer"
		};
		tracersEvery=0;
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
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Weapons\data\goldRough.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Weapons\data\goldRough.rvmat"
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
				class MagRifle_fill_in
				{
					soundSet="MagRifle_fill_in_SoundSet";
					id=1;
				};
				class MagRifle_fill_loop
				{
					soundSet="MagRifle_fill_loop_SoundSet";
					id=2;
				};
				class MagRifle_fill_out
				{
					soundSet="MagRifle_fill_out_SoundSet";
					id=3;
				};
				class MagRifle_empty_in
				{
					soundSet="MagRifle_empty_in_SoundSet";
					id=4;
				};
				class MagRifle_empty_loop
				{
					soundSet="MagRifle_empty_loop_SoundSet";
					id=5;
				};
				class MagRifle_empty_out
				{
					soundSet="MagRifle_empty_out_SoundSet";
					id=6;
				};
				class MagPistol_fill_in
				{
					soundSet="MagPistol_fill_in_SoundSet";
					id=7;
				};
				class MagPistol_fill_loop
				{
					soundSet="MagPistol_fill_loop_SoundSet";
					id=8;
				};
				class MagPistol_fill_out
				{
					soundSet="MagPistol_fill_out_SoundSet";
					id=9;
				};
				class MagPistol_empty_in
				{
					soundSet="MagPistol_empty_in_SoundSet";
					id=10;
				};
				class MagPistol_empty_loop
				{
					soundSet="MagPistol_empty_loop_SoundSet";
					id=11;
				};
				class MagPistol_empty_out
				{
					soundSet="MagPistol_empty_out_SoundSet";
					id=12;
				};
			};
		};
	};
	class SC_Mag_Barret_10Rnd: Magazine_Base
	{
		scope=2;
		displayName="SC Barret Mag";
		descriptionShort="SausageCo made 10Rnd Barret magazine. Loads 308";
		model="SausageCo\Weapons\attachments\Magazine\SC_Mag_Barret_10Rnd.p3d";
		weight=90;
		itemSize[]={1,2};
		count=10;
		ammo="Bullet_308Win";
		inventorySlot[]=
		{
			"magazine",
			"magazine2",
			"magazine3",
			"Magazine308Win",
			"Magazine308Win_2"
		};
		ammoItems[]=
		{
			"Ammo_308Win",
			"Ammo_308WinTracer"
		};
		tracersEvery=0;
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
								"SausageCo\Weapons\data\aluminumDark.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Weapons\data\aluminumDark.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Weapons\data\aluminumDark.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Weapons\data\aluminumDark.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Weapons\data\aluminumDark.rvmat"
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
				class MagRifle_fill_in
				{
					soundSet="MagRifle_fill_in_SoundSet";
					id=1;
				};
				class MagRifle_fill_loop
				{
					soundSet="MagRifle_fill_loop_SoundSet";
					id=2;
				};
				class MagRifle_fill_out
				{
					soundSet="MagRifle_fill_out_SoundSet";
					id=3;
				};
				class MagRifle_empty_in
				{
					soundSet="MagRifle_empty_in_SoundSet";
					id=4;
				};
				class MagRifle_empty_loop
				{
					soundSet="MagRifle_empty_loop_SoundSet";
					id=5;
				};
				class MagRifle_empty_out
				{
					soundSet="MagRifle_empty_out_SoundSet";
					id=6;
				};
				class MagPistol_fill_in
				{
					soundSet="MagPistol_fill_in_SoundSet";
					id=7;
				};
				class MagPistol_fill_loop
				{
					soundSet="MagPistol_fill_loop_SoundSet";
					id=8;
				};
				class MagPistol_fill_out
				{
					soundSet="MagPistol_fill_out_SoundSet";
					id=9;
				};
				class MagPistol_empty_in
				{
					soundSet="MagPistol_empty_in_SoundSet";
					id=10;
				};
				class MagPistol_empty_loop
				{
					soundSet="MagPistol_empty_loop_SoundSet";
					id=11;
				};
				class MagPistol_empty_out
				{
					soundSet="MagPistol_empty_out_SoundSet";
					id=12;
				};
			};
		};
	};
	class Mag_UMP_25Rnd: Magazine_Base
	{
	};
	class SausageMag_45ACP_SMG_50Rnd: Mag_UMP_25Rnd
	{
		count=50;
	};
};
