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
			"DZ_Data",
			"DZ_Structures",
			"DZ_Scripts"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class GardenLime;
	class SausageCompost_Fertilizer: GardenLime
	{
		scope=2;
		
		displayName="Garden Fertilizer";
		descriptionShort="Fertilizer made from a compost bin. Super effective for your plants! better then lime. Made by Nicholiae!";
		model="SausageCo\storage\Fertilizer\SausageFertilizerBag.p3d";
		animClass="NoFireClass";
		weight=100;
		itemSize[]={2,2};
		stackedUnit="g";
		quantityBar=1;
		inventorySlot[]=
		{
			"Lime"
		};
		varQuantityInit=9000;
		varQuantityMin=0;
		varQuantityMax=9000;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Fertilizer\data\sausage_lime_co.paa",
			"SausageCo\storage\Fertilizer\data\sausage_lime_co.paa",
			"SausageCo\storage\Fertilizer\data\sausage_lime_co.paa"
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
								"SausageCo\storage\Fertilizer\data\sausage_lime.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\storage\Fertilizer\data\sausage_lime.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\storage\Fertilizer\data\sausage_lime_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\storage\Fertilizer\data\sausage_lime_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\storage\Fertilizer\data\sausage_lime_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class Horticulture
		{
			TexId=1;
			AddEnergyToSlot=3.0;
			ConsumedQuantity=600;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItemLight
				{
					soundSet="pickUpGardenLimeLight_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpGardenLime_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="gardenlime_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};