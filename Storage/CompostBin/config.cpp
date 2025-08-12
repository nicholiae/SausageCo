class CfgPatches
{
	class DZ_SausageGear_Storage
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
	class sc_PlantMaterial: Inventory_Base
	{
		scope=2;
		displayName="Processed Plant Material";
		descriptionShort="Processed Plant Material for the compost bin";
		model="\dz\gear\cultivation\plant_material.p3d";
		inventorySlot[]=
		{
			"Plant"
		};
		lootCategory="Crafted";
		itemSize[]={1,2};
		rotationFlags=34;
		weight=10;
		spawnOffset=0;
		canBeSplit=1;
		varQuantityInit=200;
		varQuantityMin=0;
		varQuantityMax=200;
		varQuantityDestroyOnMin=1;  // Add this to destroy empty containers
		weightPerQuantityUnit=1;     // Add this to define weight per unit
		stackedUnit="g";
		quantityBar=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\cultivation\data\plant_material.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\cultivation\data\plant_material.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\cultivation\data\plant_material_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\cultivation\data\plant_material_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\cultivation\data\plant_material_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class Horticulture
		{
			TexId=2;
			AddEnergyToSlot=0.5;
			ConsumedQuantity=100;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpPlantMaterialLight_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpPlantMaterial_SoundSet";
					id=797;
				};
			};
		};
	};
	class SausageGarden_CompostBin: Inventory_Base
	{
		scope=2;
		displayName="Compost Bin";
		model="\DZ\structures\residential\Misc\Garbage_Bin.p3d";
		descriptionShort="Put 1 of each the following into the inventory to make fertilizer for agriculture: guts, lard, Processed plant material(take a knife to regular plant material). Created by Nicholiae.";
		itemsCargoSize[]={10,10};
		canBeDigged=0;
		overrideDrawArea="8.0";
		placement="ForceSlopeOnTerrain";		
		destroyOnEmpty=0;
		quantityBar=0;
		varQuantityMax=0;
		carveNavmesh=1;
		heavyItem=1;
		weight=10000;
		itemBehaviour=0;
		physLayer="item_large";
		allowOwnedCargoManipulation=1;
		attachments[]=
		{	
			"Guts",
			"Ingredient",
			"Plant"			
		};
		class GUIInventoryAttachmentsProps
		{
			class Compost_Storage
			{
				name="Compost Storage";
				description="";
				attachmentSlots[]=
				{
					"Guts",
					"Ingredient",
					"Plant"
				};
				icon="Plant";
			};
		};
	};
	class SausageGarden_CompostBin_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "CompostBin HOLO";
		model="\DZ\structures\residential\Misc\Garbage_Bin.p3d";
	};
};