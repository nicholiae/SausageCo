class CfgPatches
{
	class DZ_SausageKitchen_Stove
	{
		units[]={
			"SausageKitchen_Stove"
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
class CfgSlots
{
	class Slot_CookingEquipmentA
	{
		name="CookingEquipmentA";
		displayName="CookingEquipmentA";
		ghostIcon="cookingequipment";
	};
	class Slot_CookingEquipmentB
	{
		name="CookingEquipmentB";
		displayName="CookingEquipmentB";
		ghostIcon="cookingequipment";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class SausageKitchen_Stove: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Stove";
		model="\DZ\structures\furniture\kitchen\kitchenstove_elec\kitchenstove_elec.p3d";
		descriptionShort="A Gas Stove, unfortunately only one burner works, use the first to cook and the other 3 to store or make a cooking rotation.";
		overrideDrawArea="3.0";
		slopeTolerance=0.30000001;
		lootCategory="Tools";
		itemSize[]={10,15};
		weight=10000;
		itemBehaviour=0;
		quantityBar=0;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		stackedUnit="";
		attachments[]=
		{	
			"GasCanister",
			"CookingEquipment",
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC"
		};
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		canBeDigged=0;
		physLayer="item_large";
		class GUIInventoryAttachmentsProps
		{
			class CookingEquipment
			{
				name="$STR_attachment_CookingEquipment0";
				description="";
				attachmentSlots[]=
				{
					"CookingEquipment",
					"DirectCookingA",
					"DirectCookingB",
					"DirectCookingC"
				};
				icon="cookingequipment";
			};
			class Fuel
			{
				name="$STR_attachment_Fuel0";
				description="";
				attachmentSlots[]=
				{
					"GasCanister"
				};
				icon="cat_fp_fuel";
			};
		};
		hiddenSelections[]=
		{
		};
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		class EnergyManager
		{
			switchOnAtSpawn=0;
			autoSwitchOff=1;
			autoSwitchOffWhenInCargo=1;
			energyStorageMax=0;
			energyUsagePerSecond=1;
			energyAtSpawn=0;
			powerSocketsCount=0;
			plugType=7;
			attachmentAction=1;
		};
		class PointLights
		{
			class PointLight
			{
				color[]={1,0.60000002,0.5,1};
				brightness=1;
				radius=5;
				dayLight=0;
				position="light";
				hitpoint="bulb";
				selection="bulb";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet="barrel_movement_SoundSet";
					id=1;
				};
				class pickUpItem_Light
				{
					soundSet="pickUpBarrelLight_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBarrel_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="barrel_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class SausageKitchen_Stove_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "SausageCo Stove HOLO";
		model="\DZ\structures\furniture\kitchen\kitchenstove_elec\kitchenstove_elec.p3d";
	};
	class LargeGasCanister: Inventory_Base
	{};
	class SC_ExtraLargeGasCanister: LargeGasCanister
	{
		scope=2;
		displayName="Extra Large Gas Canister";
		descriptionShort="SausageCo Extra Large Gas Canister, built for the gas stove.";
		model="SausageCo\storage\Kitchen\Stove\XLGasCannister.p3d";
		overrideDrawArea="8.0";
		weight=640;
		itemSize[]={3,3};
		stackedUnit="w";
		canBeSplit=0;
		destroyOnEmpty=0;
		quantityBar=1;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=0;
		inventorySlot[]=
		{
			"GasCanister"
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
								"SausageCo\Storage\Kitchen\data\ButaneCan.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Storage\Kitchen\data\ButaneCan.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Storage\Kitchen\data\ButaneCan.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Storage\Kitchen\data\ButaneCan.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Storage\Kitchen\data\ButaneCan.rvmat"
							}
						}
					};
				};
			};
		};
		class EnergyManager
		{
			switchOnAtSpawn=1;
			isPassiveDevice=1;
			energyStorageMax=3200;
			energyUsagePerSecond=0;
			energyAtSpawn=3200;
			powerSocketsCount=1;
			compatiblePlugTypes[]={7};
			convertEnergyToQuantity=1;
		};
	};
};