class CfgPatches
{
	class DZ_SausageEdible_Foods
	{
		units[]={
			"Storage"
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

class CfgVehicles
{
	class Inventory_Base;
	class Edible_Base: Inventory_Base
	{
		varTemperatureMax=100;
	};
	class SausageCo_Kielbasa: Edible_Base
	{
		scope=2;
		displayName="Kielbasa madeby SausageCo";
		model="\SausageCo\storage\sausage\SaucageCoKielba.p3d";
		descriptionShort="A Sausage link for all you hungry bastards out there. And for all you sick minds, eat the SausageCo sausage. Does not Rott!";
		weight=40;
		varQuantityInit=1100;
		varQuantityMin=0;
		varQuantityMax=1100;
		isMeleeWeapon=1;
		hiddenSelections[]=
		{
			"camoGround"
		};
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\storage\sausage\data\sausage_co.paa"
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
								"\SausageCo\storage\sausage\data\sausage_nohq.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"\SausageCo\storage\sausage\data\sausage_nohq.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"\SausageCo\storage\sausage\data\sausage_nohq.rvmat"							
							}
						},
						
						{
							0.30000001,
							
							{
								"\SausageCo\storage\sausage\data\sausage_nohq.rvmat"							
							}
						},
						
						{
							0,
							
							{
								"\SausageCo\storage\sausage\data\sausage_nohq.rvmat"							
							}
						}
					};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex=1.9;
			energy=185;
			water=110;
			nutritionalIndex=1;
			toxicity=0;
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeBlunt";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeBlunt_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeBlunt_Heavy";
				range=2.8;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
};