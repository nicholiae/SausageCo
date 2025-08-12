class CfgPatches
{
	class DZ_SausageBuilding_Storage
	{
		units[]={
			"SausageCompost_Fertilizer"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Consumables"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class GardenLime: Inventory_Base
	{
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"DZ\Gear\Consumables\data\garden_lime_co.paa"
		};
	};
	class SausageCompost_Fertilizer: GardenLime
	{
		scope=2;
		varQuantityInit=9999;
		varQuantityMin=0;
		varQuantityMax=9999;
		hiddenSelectionsTextures[]=
		{
			"SausageBuildingStorage\storage\Fertilizer\data\sausage_lime_co.paa"
		};
		class Horticulture
		{
			TexId=1;
			AddEnergyToSlot=1.5;
			ConsumedQuantity=333;
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
							1.0,
							
							{
								"SausageBuildingStorage\storage\Fertilizer\data\sausage_lime.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageBuildingStorage\storage\Fertilizer\data\sausage_lime.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageBuildingStorage\storage\Fertilizer\data\sausage_lime_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageBuildingStorage\storage\Fertilizer\data\sausage_lime_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"SausageBuildingStorage\storage\Fertilizer\data\sausage_lime_destruct.rvmat"
							}
						}
					};
				};
			};
		};	
	};
};