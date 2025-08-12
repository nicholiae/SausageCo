class CfgPatches
{
	class Sausage_Zombies
	{
		units[]=
		{
			"vurdalsk"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters"
		};
	};
};
class CfgVehicles
{
	class DZ_LightAI;
	class DayZInfected: DZ_LightAI
	{
	};
	class ZombieBase: DayZInfected
	{
	};
	class SC_ZombieBase: ZombieBase
	{
		scope=0;
		faction="dz_Civ_US";
		rarityUrban=-1;
		simulation="dayzinfected";
		attachments[]=
		{
			"Vest",
			"Back",
			"Headgear"
		};
		class enfanimsys
		{
			meshObject="dz\characters\zombies\z_hermit_m.xob";
			graphname="dz\anims\workspaces\infected\infected_main\infected.agr";
			defaultinstance="dz\anims\workspaces\infected\infected_main\infected_main.asi";
			skeletonName="hermit_newbindpose.xob";
			startnode="MasterControl";
		};
		class InputController
		{
			movementSpeedMapping[]={0,1.5,2.9000001,8.8999996};
			lookAtFilterTimeout=0.5;
			lookAtFilterSpeed=1.5700001;
		};
		accuracy=0;
		threat[]={1,0.050000001,0.050000001};
		displayName="$STR_cfgvehicles_infected0";
		descriptionShort="$STR_cfgvehicles_infected1";
		vehicleClass="Zombie";
		zombieLoot="civilian";
		storageCategory=3;
		attackSounds="zombie_attack";
		spottedSounds="zombie_spotted";
		chaseSounds="zombie_chase";
		idleSounds="zombie_idle";
		hiddenSelections[]=
		{
			"camo"
		};
		languages[]={};
		htMin=60;
		htMax=1800;
		afMax=30;
		mfMax=0;
		mFact=1;
		tBody=37;
		selectionPersonality="personality";
		faceType="MaleWhiteHeadNew";
		launcherBone="launcher";
		handGunBone="RightHand";
		weaponBone="weapon";
		selectionHeadWound="injury_head";
		selectionBodyWound="injury_body";
		selectionLArmWound="injury_hands";
		selectionRArmWound="injury_hands";
		selectionLLegWound="injury_legs";
		selectionRLegWound="injury_legs";
		memoryPointLStep="footstepL";
		memoryPointRStep="footstepR";
		memoryPointAim="aimPoint";
		memoryPointCameraTarget="camera";
		memoryPointCommonDamage="l_femur_hit";
		memoryPointLeaningAxis="leaning_axis";
		memoryPointAimingAxis="aiming_axis";
		memoryPointHeadAxis="head_axis";
		selectionLBrow="lBrow";
		selectionMBrow="mBrow";
		selectionRBrow="rBrow";
		selectionLMouth="lMouth";
		selectionMMouth="mMouth";
		selectionRMouth="rMouth";
		selectionEyelid="Eyelids";
		selectionLip="LLip";
		class InventoryEquipment
		{
			playerSlots[]=
			{
				"Slot_Vest",
				"Slot_Back",
				"Slot_Headgear"
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		class Wounds
		{
			tex[]={};
			mat[]=
			{
				"dz\characters\zombies\data\coveralls.rvmat",
				"dz\characters\zombies\data\coveralls_injury.rvmat",
				"dz\characters\zombies\data\coveralls_injury.rvmat"
			};
		};
		aiAgentTemplate="Infected";
		class NoiseTemplates
		{
			class StepNoise
			{
				strength=10;
				type="sound";
			};
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
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=30;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1.5;
							};
						};
						class Melee
						{
							class Health
							{
								damage=0.69999999;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=3;
							};
						};
					};
					componentNames[]=
					{
						"Head",
						"Neck"
					};
					fatalInjuryCoef=0.1;
					inventorySlots[]=
					{
						"Headgear",
						"Mask"
					};
				};
				class Torso
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=1.2;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"Spine1",
						"Spine3"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
				};
				class LeftArm: Torso
				{
					componentNames[]=
					{
						"LeftArm",
						"LeftForeArm"
					};
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
					fatalInjuryCoef=-1;
				};
				class RightArm: LeftArm
				{
					componentNames[]=
					{
						"RightArm",
						"RightForeArm"
					};
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
					fatalInjuryCoef=-1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.33000001;
					};
					class ArmorType
					{
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"LeftLeg",
						"LeftUpLeg"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Legs"
					};
				};
				class RightLeg: LeftLeg
				{
					componentNames[]=
					{
						"RightLeg",
						"RightUpLeg"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Legs"
					};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.1;
					};
					class ArmorType
					{
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					transferToZonesNames[]=
					{
						"LeftLeg"
					};
					transferToZonesCoefs[]={0.1};
					componentNames[]=
					{
						"LeftFoot"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Feet"
					};
				};
				class RightFoot: LeftFoot
				{
					transferToZonesNames[]=
					{
						"RightLeg"
					};
					transferToZonesCoefs[]={0.1};
					componentNames[]=
					{
						"RightFoot"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Feet"
					};
				};
			};
		};
	};
	class SC_ZombieFemaleBase: SC_ZombieBase
	{
		scope=0;
		meleeAmmo="MeleeZombieFemale";
		aiAgentTemplate="InfectedFemale";
		woman=1;
		clothingType="female";
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		class Wounds: Wounds
		{
			tex[]={};
			mat[]=
			{
				"dz\characters\zombies\data\shortskirt.rvmat",
				"dz\characters\zombies\data\shortskirt_injury.rvmat",
				"dz\characters\zombies\data\shortskirt_injury.rvmat"
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				attackName="attackLong";
				ammoType="MeleeZombieFemale";
				stanceName="erect";
				moveAnimNames[]=
				{
					"run",
					"sprint"
				};
				minDistance=0.75;
				distance=1.75;
				time=2.5;
				yawAngle=0;
				pitchAngle=0;
				attackWidth=2.2;
				repeatable=0;
				cooldown=2.75;
			};
			class AttackRun
			{
				attackName="attackRun";
				ammoType="MeleeZombieFemale";
				stanceName="erect";
				moveAnimNames[]=
				{
					"run",
					"sprint"
				};
				minDistance=0.5;
				distance=1.3;
				time=1;
				yawAngle=0;
				pitchAngle=0;
				attackWidth=1.5;
				repeatable=1;
				cooldown=1.25;
			};
			class AttackShort
			{
				attackName="attackShort";
				ammoType="MeleeZombieFemale";
				stanceName="erect";
				moveAnimNames[]=
				{
					"idle",
					"walk"
				};
				minDistance=0.5;
				distance=1.3;
				time=1;
				yawAngle=0;
				pitchAngle=0;
				attackWidth=1.5;
				repeatable=1;
				cooldown=1.25;
			};
			class AttackShortLow
			{
				attackName="attackShortLow";
				ammoType="MeleeZombieFemale";
				stanceName="erect";
				moveAnimNames[]=
				{
					"idle",
					"walk",
					"run"
				};
				minDistance=0;
				distance=2;
				time=1;
				yawAngle=0;
				pitchAngle=-45;
				attackWidth=2;
				repeatable=1;
				cooldown=1.25;
			};
			class CrawlAttackMove
			{
				attackName="crawlAttackMove";
				ammoType="MeleeZombieFemale";
				stanceName="crawl";
				moveAnimNames[]=
				{
					"walk"
				};
				distance=2;
				time=1.5;
				yawAngle=0;
				pitchAngle=45;
				attackWidth=2;
				cooldown=1.25;
			};
			class CrawlAttackStill
			{
				attackName="crawlAttackStill";
				ammoType="MeleeZombieFemale";
				stanceName="crawl";
				moveAnimNames[]=
				{
					"idle"
				};
				distance=2;
				time=1.1;
				yawAngle=0;
				pitchAngle=45;
				attackWidth=2;
				cooldown=1.25;
			};
		};
	};
	class SC_ZombieMaleBase: SC_ZombieBase
	{
		scope=0;
		meleeAmmo="MeleeZombieMale";
		aiAgentTemplate="InfectedMale";
		woman=0;
		clothingType="male";
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		class Wounds: Wounds
		{
			tex[]={};
			mat[]=
			{
				"dz\characters\zombies\data\jacket.rvmat",
				"dz\characters\zombies\data\jacket_injury.rvmat",
				"dz\characters\zombies\data\jacket_injury.rvmat"
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				attackName="attackLong";
				ammoType="MeleeZombieMale";
				stanceName="erect";
				moveAnimNames[]=
				{
					"run",
					"sprint"
				};
				minDistance=0.75;
				distance=1.75;
				time=2.5;
				yawAngle=0;
				pitchAngle=0;
				attackWidth=2.2;
				repeatable=0;
				cooldown=2.75;
			};
			class AttackRun
			{
				attackName="attackRun";
				ammoType="MeleeZombieMale";
				stanceName="erect";
				moveAnimNames[]=
				{
					"run",
					"sprint"
				};
				minDistance=0.5;
				distance=1.3;
				time=1;
				yawAngle=0;
				pitchAngle=0;
				attackWidth=1.5;
				repeatable=1;
				cooldown=1.25;
			};
			class AttackShort
			{
				attackName="attackShort";
				ammoType="MeleeZombieMale";
				stanceName="erect";
				moveAnimNames[]=
				{
					"idle",
					"walk"
				};
				minDistance=0.5;
				distance=1.3;
				time=1;
				yawAngle=0;
				pitchAngle=0;
				attackWidth=1.5;
				repeatable=1;
				cooldown=1.25;
			};
			class AttackShortLow
			{
				attackName="attackShortLow";
				ammoType="MeleeZombieMale";
				stanceName="erect";
				moveAnimNames[]=
				{
					"idle",
					"walk",
					"run"
				};
				minDistance=0;
				distance=2;
				time=1;
				yawAngle=0;
				pitchAngle=-45;
				attackWidth=2;
				repeatable=1;
				cooldown=1.25;
			};
			class CrawlAttackMove
			{
				attackName="crawlAttackMove";
				ammoType="MeleeZombieMale";
				stanceName="crawl";
				moveAnimNames[]=
				{
					"walk"
				};
				distance=2;
				time=1.5;
				yawAngle=0;
				pitchAngle=45;
				attackWidth=2;
				cooldown=1.25;
			};
			class CrawlAttackStill
			{
				attackName="crawlAttackStill";
				ammoType="MeleeZombieMale";
				stanceName="crawl";
				moveAnimNames[]=
				{
					"idle"
				};
				distance=2;
				time=1.1;
				yawAngle=0;
				pitchAngle=45;
				attackWidth=2;
				cooldown=1.25;
			};
		};
	};
	class SC_ZmbF_Vurdalsk_Base: SC_ZombieFemaleBase
	{
		scope=0;
		model="SausageCo\zombies\vurdalsk.p3d";
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\zombies\data\vurdalsk.rvmat"
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
			openable=0;
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
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=300;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1.5;
							};
						};
						class Melee
						{
							class Health
							{
								damage=0.69999999;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=3;
							};
						};
					};
					componentNames[]=
					{
						"Head",
						"Neck"
					};
					fatalInjuryCoef=0.1;
					inventorySlots[]=
					{
						"Headgear",
						"Mask"
					};
				};
				class Torso
				{
					class Health
					{
						hitpoints=500;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=1.2;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"Spine1",
						"Spine3"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
				};
				class LeftArm: Torso
				{
					componentNames[]=
					{
						"LeftArm",
						"LeftForeArm"
					};
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
					fatalInjuryCoef=-1;
				};
				class RightArm: LeftArm
				{
					componentNames[]=
					{
						"RightArm",
						"RightForeArm"
					};
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
					fatalInjuryCoef=-1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.33000001;
					};
					class ArmorType
					{
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"LeftLeg",
						"LeftUpLeg"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Legs"
					};
				};
				class RightLeg: LeftLeg
				{
					componentNames[]=
					{
						"RightLeg",
						"RightUpLeg"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Legs"
					};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.1;
					};
					class ArmorType
					{
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					transferToZonesNames[]=
					{
						"LeftLeg"
					};
					transferToZonesCoefs[]={0.1};
					componentNames[]=
					{
						"LeftFoot"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Feet"
					};
				};
				class RightFoot: LeftFoot
				{
					transferToZonesNames[]=
					{
						"RightLeg"
					};
					transferToZonesCoefs[]={0.1};
					componentNames[]=
					{
						"RightFoot"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Feet"
					};
				};
			};
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable="walkErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=1;
				};
				class Walk2
				{
					soundLookupTable="walkErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=2;
				};
				class Walk3
				{
					soundLookupTable="walkErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=3;
				};
				class Walk4
				{
					soundLookupTable="walkErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=4;
				};
				class Run1
				{
					soundLookupTable="runErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=5;
				};
				class Run2
				{
					soundLookupTable="runErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=6;
				};
				class Run3
				{
					soundLookupTable="runErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=7;
				};
				class Run4
				{
					soundLookupTable="runErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=8;
				};
				class Sprint1
				{
					soundLookupTable="sprintErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=9;
				};
				class Sprint2
				{
					soundLookupTable="sprintErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=10;
				};
				class Sprint3
				{
					soundLookupTable="sprintErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=11;
				};
				class Sprint4
				{
					soundLookupTable="sprintErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=12;
				};
				class Scuff1
				{
					soundLookupTable="scuffErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=17;
				};
				class Scuff2
				{
					soundLookupTable="scuffErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=18;
				};
				class Sccuff3
				{
					soundLookupTable="scuffErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=19;
				};
				class Scuff4
				{
					soundLookupTable="scuffErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=20;
				};
				class landFeetErc
				{
					soundLookupTable="landFeetErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=21;
				};
				class landFootErc
				{
					soundLookupTable="landFootErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=22;
				};
				class Bodyfall
				{
					soundLookupTable="bodyfall_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=23;
				};
				class Bodyfall_Hand
				{
					soundLookupTable="bodyfall_hand_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=24;
				};
				class Bodyfall_Slide
				{
					soundLookupTable="bodyfall_slide_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=25;
				};
				class Prone_Walk_L
				{
					soundLookupTable="walkProne_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=27;
				};
				class Prone_Walk_R
				{
					soundLookupTable="walkProne_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=28;
				};
				class Prone_Run_L
				{
					soundLookupTable="runProne_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=29;
				};
				class Prone_Run_R
				{
					soundLookupTable="runProne_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=30;
				};
			};
			class Sounds
			{
				class Attack_Light1
				{
					soundSet="ZmbSC_Normal_Attack_Soundset";
					id=1;
				};
				class Attack_Light2
				{
					soundSet="ZmbSC_Normal_Attack_Soundset";
					id=2;
				};
				class Attack_Heavy1
				{
					soundSet="ZmbSC_Normal_Attack_Soundset";
					id=3;
				};
				class Attack_Heavy2
				{
					soundSet="ZmbSC_Normal_Attack_Soundset";
					id=4;
				};
				class TwoHands
				{
					soundSet="ZmbSC_Normal_HeavyHit_Soundset";
					id=5;
				};
			};
			class SoundVoice
			{
				class LightHit
				{
					soundSet="ZmbSC_Normal_LightHit_Soundset";
					id=1;
				};
				class HeavyHit
				{
					soundSet="ZmbSC_Normal_HeavyHit_Soundset";
					id=2;
				};
				class Attack
				{
					soundSet="ZmbSC_Normal_Attack_Soundset";
					id=5;
				};
				class Jump
				{
					soundSet="ZmbF_Normal_Jump_Soundset";
					id=10;
				};
				class Land
				{
					soundSet="ZmbF_Normal_Land_Soundset";
					id=11;
				};
				class CallToArmsShort
				{
					soundSet="ZmbSC_Normal_CallToArmsShort_Soundset";
					id=20;
				};
			};
		};
	};
	class SC_ZmbF_Vurdalsk: SC_ZmbF_Vurdalsk_Base
	{
		scope=2;
		name="Vurdalsk Creature";
		descriptionShort="Vurdalsk Creature, pronounce ver-dulsk";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\zombies\data\vurdalsk_co.paa"
		};
	};
	class SC_ZmbF_FreshDead_Base: SC_ZombieFemaleBase
	{
		scope=0;
		model="SausageCo\zombies\freshdead\femaleBloody.p3d";
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat",
			"SausageCo\zombies\freshdead\data\freshdead.rvmat"
			
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
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=300;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1.5;
							};
						};
						class Melee
						{
							class Health
							{
								damage=0.69999999;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=3;
							};
						};
					};
					componentNames[]=
					{
						"Head",
						"Neck"
					};
					fatalInjuryCoef=0.1;
					inventorySlots[]=
					{
						"Headgear",
						"Mask"
					};
				};
				class Torso
				{
					class Health
					{
						hitpoints=500;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=1.2;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"Spine1",
						"Spine3"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
				};
				class LeftArm: Torso
				{
					componentNames[]=
					{
						"LeftArm",
						"LeftForeArm"
					};
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
					fatalInjuryCoef=-1;
				};
				class RightArm: LeftArm
				{
					componentNames[]=
					{
						"RightArm",
						"RightForeArm"
					};
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
					fatalInjuryCoef=-1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.33000001;
					};
					class ArmorType
					{
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"LeftLeg",
						"LeftUpLeg"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Legs"
					};
				};
				class RightLeg: LeftLeg
				{
					componentNames[]=
					{
						"RightLeg",
						"RightUpLeg"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Legs"
					};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.1;
					};
					class ArmorType
					{
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					transferToZonesNames[]=
					{
						"LeftLeg"
					};
					transferToZonesCoefs[]={0.1};
					componentNames[]=
					{
						"LeftFoot"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Feet"
					};
				};
				class RightFoot: LeftFoot
				{
					transferToZonesNames[]=
					{
						"RightLeg"
					};
					transferToZonesCoefs[]={0.1};
					componentNames[]=
					{
						"RightFoot"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Feet"
					};
				};
			};
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable="walkErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=1;
				};
				class Walk2
				{
					soundLookupTable="walkErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=2;
				};
				class Walk3
				{
					soundLookupTable="walkErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=3;
				};
				class Walk4
				{
					soundLookupTable="walkErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=4;
				};
				class Run1
				{
					soundLookupTable="runErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=5;
				};
				class Run2
				{
					soundLookupTable="runErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=6;
				};
				class Run3
				{
					soundLookupTable="runErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=7;
				};
				class Run4
				{
					soundLookupTable="runErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=8;
				};
				class Sprint1
				{
					soundLookupTable="sprintErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=9;
				};
				class Sprint2
				{
					soundLookupTable="sprintErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=10;
				};
				class Sprint3
				{
					soundLookupTable="sprintErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=11;
				};
				class Sprint4
				{
					soundLookupTable="sprintErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=12;
				};
				class Scuff1
				{
					soundLookupTable="scuffErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=17;
				};
				class Scuff2
				{
					soundLookupTable="scuffErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=18;
				};
				class Sccuff3
				{
					soundLookupTable="scuffErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=19;
				};
				class Scuff4
				{
					soundLookupTable="scuffErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=20;
				};
				class landFeetErc
				{
					soundLookupTable="landFeetErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=21;
				};
				class landFootErc
				{
					soundLookupTable="landFootErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=22;
				};
				class Bodyfall
				{
					soundLookupTable="bodyfall_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=23;
				};
				class Bodyfall_Hand
				{
					soundLookupTable="bodyfall_hand_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=24;
				};
				class Bodyfall_Slide
				{
					soundLookupTable="bodyfall_slide_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=25;
				};
				class Prone_Walk_L
				{
					soundLookupTable="walkProne_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=27;
				};
				class Prone_Walk_R
				{
					soundLookupTable="walkProne_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=28;
				};
				class Prone_Run_L
				{
					soundLookupTable="runProne_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=29;
				};
				class Prone_Run_R
				{
					soundLookupTable="runProne_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=30;
				};
			};
			class Sounds
			{
				class Attack_Light1
				{
					soundSet="ZmbF_Normal_Attack_Soundset";
					id=1;
				};
				class Attack_Light2
				{
					soundSet="ZmbF_Normal_Attack_Soundset";
					id=2;
				};
				class Attack_Heavy1
				{
					soundSet="ZmbF_Normal_Attack_Soundset";
					id=3;
				};
				class Attack_Heavy2
				{
					soundSet="ZmbF_Normal_Attack_Soundset";
					id=4;
				};
				class TwoHands
				{
					soundSet="ZmbF_Normal_HeavyHit_Soundset";
					id=5;
				};
			};
			class SoundVoice
			{
				class LightHit
				{
					soundSet="ZmbF_Normal_LightHit_Soundset";
					id=1;
				};
				class HeavyHit
				{
					soundSet="ZmbF_Normal_HeavyHit_Soundset";
					id=2;
				};
				class Attack
				{
					soundSet="ZmbF_Normal_Attack_Soundset";
					id=5;
				};
				class Jump
				{
					soundSet="ZmbF_Normal_Jump_Soundset";
					id=10;
				};
				class Land
				{
					soundSet="ZmbF_Normal_Land_Soundset";
					id=11;
				};
				class CallToArmsShort
				{
					soundSet="ZmbF_Normal_CallToArmsShort_Soundset";
					id=20;
				};
			};
		};
	};
	class SC_ZmbF_FreshDead: SC_ZmbF_FreshDead_Base
	{
		scope=2;
		name="FreshDead";
		descriptionShort="FreshlyDead, such a shame, if only we had gotten here sooner";
		hiddenSelections[]=
		{
			"paintBra",
			"paintCornea",
			"paintEyes",
			"paintPonyTail",
			"paintScalp",
			"paintEyeLashs",
			"paintLowerTeeth",
			"paintNails",
			"paintArms",
			"paintBody",
			"paintHead",
			"paintLegs",
			"paintTongue",
			"paintUpperTeeth",
			"paintUnderwearBottoms"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\zombies\freshdead\data\Bra_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Cornea_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Eye_diffuse.paa",
			"SausageCo\zombies\freshdead\data\High_polytail_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Scalp_High_polytail_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Std_Eyelash_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Std_Lower_Teeth_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Std_Nails_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Std_Skin_Arm_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Std_Skin_Body_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Std_Skin_Head_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Std_Skin_Leg_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Std__Tongue_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Std__Upper_Teeth_diffuse.paa",
			"SausageCo\zombies\freshdead\data\Underwear Bottoms_diffuse.paa"
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyHands;
	class ProxyAK_47_v58_Proxy: ProxyHands
	{
		model="\dz\Characters\Proxies\ak_47_v58_proxy.p3d";
	};
	class ProxyBack;
	class ProxyBackpack_DZ: ProxyBack
	{
		model="\dz\Characters\Proxies\Backpack_DZ.p3d";
	};
	class ProxyHeadgear;
	class ProxyHeadgear_DZ: ProxyHeadgear
	{
		model="\dz\Characters\Proxies\Headgear_DZ.p3d";
	};
	class ProxyMask;
	class ProxyMask_DZ: ProxyMask
	{
		model="\dz\Characters\Proxies\Mask_DZ.p3d";
	};
	class ProxyVest;
	class ProxyVest_DZ: ProxyVest
	{
		model="\dz\Characters\Proxies\Vest_DZ.p3d";
	};
	class ProxyMelee;
	class ProxyMelee_DZ: ProxyMelee
	{
		model="\dz\Characters\Proxies\Melee_DZ.p3d";
	};
};
