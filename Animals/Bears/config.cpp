class CfgPatches
{
	class Sausage_Animals_DireBear
	{
		units[]=
		{
			"Animal_DireBear_Red"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Animals",
			"DZ_Data_Bliss",
			"DZ_AI_Bliss",
			"DZ_Weapons_Melee"
		};
	};
};
class CfgAmmo
{
	class Bullet_Base;
	class MeleeDamage;
	class MeleeBear: MeleeDamage
	{};
};
class CfgVehicles
{
	class AnimalBase;
	class Inventory_Base;
	class Pelt_Base: Inventory_Base
	{
	};
	class DireBearPelt: Pelt_Base
	{
		scope=2;
		displayName="Dire Bear Pelt";
		descriptionShort="A fine pelt from a dire red-Bear. Quite an acheivement these things are beastly.";
		model="\dz\gear\consumables\Pelt_Bear.p3d";
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
			"SausageCo\Animals\Bears\data\bear_DireRedPelt_co.paa"
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
								"DZ\gear\consumables\data\pelt_bear.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\consumables\data\pelt_bear.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\consumables\data\pelt_bear_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\consumables\data\pelt_bear_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\consumables\data\pelt_bear_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Animal_UrsusArctos: AnimalBase
	{
		hiddenSelections[]=
		{
			"body_injury"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\animals_bliss\ursus_arctos\data\bear_co.paa"
		};
	};
	class Animal_DireBear_Red: Animal_UrsusArctos
	{
		armor=1.8;
		hiddenSelections[]=
		{
			"body_injury"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Animals\Bears\data\DireBear_Red_co.paa"
		};
		class Skinning
		{
			class ObtainedPelt
			{
				item="DireBearPelt";
				count=2;
				itemZones[]=
				{
					"Zone_Pelvis",
					"Zone_Belly"
				};
				quantityCoef=1;
				transferToolDamageCoef=1;
			};
			class ObtainedSteaks
			{
				item="BearSteakMeat";
				count=20;
				itemZones[]=
				{
					"Zone_Belly",
					"Zone_Pelvis"
				};
				countByZone[]={8,8};
				quantityMinMaxCoef[]={0.69999999,1};
			};
			class ObtainedLard
			{
				item="Lard";
				count=2;
				quantityMinMaxCoef[]={0.2,1};
			};
			class ObtainedGuts
			{
				item="Guts";
				count=4;
				quantityMinMaxCoef[]={0.5,0.80000001};
			};
			class ObtainedBones
			{
				item="Bone";
				count=5;
				quantityMinMaxCoef[]={0.30000001,1};
				transferToolDamageCoef=1;
			};
		};
		
	};
};
