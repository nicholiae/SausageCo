class CfgPatches
{
	class SausageClothesSausageF
	{
		units[]=
		{
			""
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_data",
			"DZ_Gear_Consumables",
			"DZ_Structures",
			"DZ_Scripts"
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
	class Rifle_Base;
	class Launcher_Base;
	class M4A1_Base: Rifle_Base
	{
		
	};
	class Sausage_M4Variant_Base: M4A1_Base
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
			"Ammo_308Win",
			"Ammo_308WinTracer"
		};
		magazines[]=
		{
			"SC_Mag_SausageM4_9999Rnd"
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
			"SemiAuto",
			"FullAuto"
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
			reloadTime=0.005;
			recoil="recoil_m4";
			recoilProne="recoil_m4_prone";
			dispersion=0.0005;
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
			reloadTime=0.001000003;
			recoil="recoil_m4";
			recoilProne="recoil_m4_prone";
			dispersion=0.0005;
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
			distanceZoomMax=125;
		};
	};
	class Sausage_M4Variant: Sausage_M4Variant_Base
	{
		scope=2;
		displayName="M4-A1 SausageVariant";
		descriptionShort="An M4-A1 Variant rifle, modified to take 308 rounds. ADMIN GUN YOU NO ADMIN YOU NO HAVE!";
		model="\dz\weapons\firearms\m4\m4a1.p3d";
		attachments[]=
		{
			"weaponButtstockM4",
			"WeaponHandguardM4",
			"weaponWrap",
			"weaponOptics",
			"weaponFlashlight",
			"weaponMuzzleM4",
			"weaponBayonet"
		};
		itemSize[]={5,1};
		spawnDamageRange[]={0,0.60000002};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\Factions\SausageGear\data\SausageGun.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\weapons\firearms\m4\data\m4_body.rvmat"
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
				maxOverheatingValue=12000;
				shotsToStartOverheating=170;
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
					hitpoints=2000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\firearms\M4\Data\m4_body.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\firearms\M4\Data\m4_body.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\firearms\M4\Data\m4_body_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\firearms\M4\Data\m4_body_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\firearms\M4\Data\m4_body_destruct.rvmat"
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
	class Mag_STANAG_30Rnd: Magazine_Base
	{
		
	};
	class SC_Mag_SausageM4_9999Rnd: Mag_STANAG_30Rnd
	{
		scope=2;
		displayName="SausageM4 ADMIN 9999Rnd Mag";
		descriptionShort="An ADMIN 9999Rnd mag for the M4-A1 SausageVariant rifle, loads 308, makes every round a tracer.";
		model="\DZ\weapons\attachments\magazine\magazine_stanag30.p3d";
		weight=180;
		itemSize[]={1,2};
		count=9999;
		ammo="Bullet_308Win";
		ammoItems[]=
		{
			"Ammo_308Win",
			"Ammo_308WinTracer"
		};
		tracersEvery=1;
	};
};
class CfgVehicles
{	
	class Inventory_Base;
	class Clothing_Base;
	class Container_Base;
	class Clothing: Clothing_Base
	{
	};
	class TacticalGloves_ColorBase: Clothing //GLOVES
	{
		
	};
	
	class SausageFGloves: TacticalGloves_ColorBase
	{
		scope=2;
		displayName=" ADMIN SET";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="SausageF";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFGloves.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFGloves.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFGloves.paa"
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
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
			};
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class SausageFHelm: Mich2001Helmet
	{
		scope=2;
		displayName=" ADMIN SET";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="SausageF";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFHelmet.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFHelmet.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFHelmet.paa"
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
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
			};
		};
	};
	class CargoPants_ColorBase: Clothing //PANTS
	{
		
	};
	class SausageFPants: CargoPants_ColorBase
	{
		scope=2;
		displayName=" ADMIN SET";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.75;
		itemsCargoSize[]={10,50};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFPants.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFPants.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFPants.paa"
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
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
			};
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class SausageFBoots: CombatBoots_ColorBase
	{
		scope=2;
		displayName=" ADMIN SET";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFBoots.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFBoots.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFBoots.paa"
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
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
			};
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class SausageFJacket: M65Jacket_ColorBase
	{
		scope=2;
		displayName=" ADMIN SET";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,50};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFJacket.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFJacket.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFJacket.paa"
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
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
			};
		};
	};
	class PlateCarrierVest: Clothing // Vest
	{
		hiddenSelections[]=
		{
			"camoGround",
			"camoFemale",
			"camoMale",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa"
		};
	};
	class SausageFVest: PlateCarrierVest 
	{
		scope=2;
		displayName=" ADMIN SET";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,50};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFVest.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFVest.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFVest.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFVest.paa"
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
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.0;
					};
				};
			};
		};
	};
	class PlateCarrierPouches: Container_Base //Pouches
	{
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa"
		};
	};
	class SausageFPouches: PlateCarrierPouches 
	{
		scope=2;
		displayName=" ADMIN SET";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,50};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFVest.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFVest.paa"
		};
	};
	class HuntingBag: Clothing //Bag
	{
		
	};
	class SausageFBag: HuntingBag 
	{
		scope=2;
		displayName=" ADMIN SET";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,50};
		attachments[]=
		{
			"Chemlight",
			"WalkieTalkie",
			"shoulder1",
			"shoulder2",
			"shoulder3",
			"shoulder4",
			"shoulder5",
			"shoulder6"
		};
		inventorySlot[]=
		{
			"Back",
			"Back1",
			"Back2",
			"Back3"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFBag.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFBag.paa",
			"SausageCo\storage\clothes\Factions\SausageGear\data\SausageFBag.paa"
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
					damage=0.0;
				};
				class Blood
				{
					damage=0;
				};
				class Shock
				{
					damage=0.0;
				};
			};
			class Melee
			{
				class Health
				{
					damage=0.0;
				};
				class Blood
				{
					damage=0;
				};
				class Shock
				{
					damage=0.0;
				};
			};
			class Infected
			{
				class Health
				{
					damage=0.0;
				};
				class Blood
				{
					damage=0;
				};
				class Shock
				{
					damage=0.0;
				};
			};
			class FragGrenade
			{
				class Health
				{
					damage=0.0;
				};
				class Blood
				{
					damage=0;
				};
				class Shock
				{
					damage=0.0;
				};
			};
		};
	};
};