class CfgPatches
{
	class Sausage_Animals_Wolves
	{
		units[]=
		{
			"Animal_Dire_Red",
			"Animal_DireLite_Red"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Animals"
		};
	};
};
class CfgVehicles
{
	class AnimalBase;
	class Inventory_Base;
	class Pelt_Base: Inventory_Base
	{
	};
	class DireWolfPelt: Pelt_Base
	{
		scope=2;
		displayName="Dire Wolf Pelt";
		descriptionShort="A fine pelt from a dire red-wolf. Quite an acheivement these things are beastly.";
		model="\dz\gear\consumables\Pelt_Wolf.p3d";
		weight=1200;
		itemSize[]={3,2};
		peltGain=6;
		leatherYield=4;
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Animals\Wolves\data\wolf_DireRedPelt_co.paa"
		};
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
								"DZ\gear\consumables\data\pelt_wolf.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\consumables\data\pelt_wolf.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\consumables\data\pelt_wolf_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\consumables\data\pelt_wolf_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\consumables\data\pelt_wolf_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Animal_CanisLupus: AnimalBase
	{};
	class Animal_Dire_Red: Animal_CanisLupus
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Animals\Wolves\data\wolf_DireRed_co.paa",
			"SausageCo\Animals\Wolves\data\direfur_alpha.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=600;
					healthLabels[]={1,0.69999999,0.5,0.30000001,0};
				};
				class Blood
				{
					hitpoints=10000;
				};
				class Shock
				{
					hitpoints=300;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[]=
					{
						"Zone_Head"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.15000001;
					canBleed=0;
					class Health
					{
						hitpoints=240;
						transferToGlobalCoef=1;
					};
					class Blood: Health
					{
						hitpoints=0;
					};
					class Shock: Health
					{
						hitpoints=0;
					};
				};
				class Zone_Neck: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Neck"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=200;
					};
				};
				class Zone_Chest: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Chest"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=300;
					};
				};
				class Zone_Belly: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Belly"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=300;
					};
				};
				class Zone_Spine: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Spine_Front",
						"Zone_Spine_Back"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=300;
					};
				};
				class Zone_Pelvis: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Pelvis"
					};
					transferToZonesNames[]=
					{
						"Zone_Spine"
					};
					transferToZonesCoefs[]={0.5};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=300;
					};
				};
				class Zone_Legs: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Legs_Front",
						"Zone_Legs_Back"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0;
					class Health: Health
					{
						hitpoints=200;
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedSteaks
			{
				item="WolfSteakMeat";
				count=10;
				itemZones[]=
				{
					"Zone_Chest",
					"Zone_Belly",
					"Zone_Pelvis"
				};
				countByZone[]={3,3,3};
				quantityMinMaxCoef[]={0.5,1};
			};
			class ObtainedPelt
			{
				item="DireWolfPelt";
				count=1;
				itemZones[]=
				{
					"Zone_Chest",
					"Zone_Belly"
				};
				quantityCoef=1;
				transferToolDamageCoef=1;
			};
			class ObtainedGuts
			{
				item="Guts";
				count=2;
				quantityMinMaxCoef[]={0.5,0.80000001};
			};
			class ObtainedLard
			{
				item="Lard";
				count=1;
				quantityMinMaxCoef[]={0.5,1};
			};
			class ObtainedBones
			{
				item="Bone";
				count=1;
				quantityMinMaxCoef[]={0.69999999,1};
				transferToolDamageCoef=1;
			};
		};
	};
	class Animal_DireLite_Red: Animal_CanisLupus
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Animals\Wolves\data\wolf_DireLiteRed_co.paa",
			"SausageCo\Animals\Wolves\data\direfur_alpha.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=600;
					healthLabels[]={1,0.69999999,0.5,0.30000001,0};
				};
				class Blood
				{
					hitpoints=10000;
				};
				class Shock
				{
					hitpoints=300;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[]=
					{
						"Zone_Head"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.15000001;
					canBleed=0;
					class Health
					{
						hitpoints=240;
						transferToGlobalCoef=1;
					};
					class Blood: Health
					{
						hitpoints=0;
					};
					class Shock: Health
					{
						hitpoints=0;
					};
				};
				class Zone_Neck: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Neck"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=200;
					};
				};
				class Zone_Chest: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Chest"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=300;
					};
				};
				class Zone_Belly: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Belly"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=300;
					};
				};
				class Zone_Spine: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Spine_Front",
						"Zone_Spine_Back"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=300;
					};
				};
				class Zone_Pelvis: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Pelvis"
					};
					transferToZonesNames[]=
					{
						"Zone_Spine"
					};
					transferToZonesCoefs[]={0.5};
					fatalInjuryCoef=0.050000001;
					class Health: Health
					{
						hitpoints=300;
					};
				};
				class Zone_Legs: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Legs_Front",
						"Zone_Legs_Back"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0;
					class Health: Health
					{
						hitpoints=200;
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedSteaks
			{
				item="WolfSteakMeat";
				count=10;
				itemZones[]=
				{
					"Zone_Chest",
					"Zone_Belly",
					"Zone_Pelvis"
				};
				countByZone[]={3,3,3};
				quantityMinMaxCoef[]={0.5,1};
			};
			class ObtainedPelt
			{
				item="DireWolfPelt";
				count=1;
				itemZones[]=
				{
					"Zone_Chest",
					"Zone_Belly"
				};
				quantityCoef=1;
				transferToolDamageCoef=1;
			};
			class ObtainedGuts
			{
				item="Guts";
				count=2;
				quantityMinMaxCoef[]={0.5,0.80000001};
			};
			class ObtainedLard
			{
				item="Lard";
				count=1;
				quantityMinMaxCoef[]={0.5,1};
			};
			class ObtainedBones
			{
				item="Bone";
				count=1;
				quantityMinMaxCoef[]={0.69999999,1};
				transferToolDamageCoef=1;
			};
		};
	};
};
