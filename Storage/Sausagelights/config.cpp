class CfgPatches
{
	class DZ_SausageLights_Torch
	{
		units[]={
			"SausageLights_Torch"
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
	class Slot_torchfire1
	{
		name="torchfire1";
		displayName="torchfire1";
		selection="torchfire1";
		ghostIcon="rags";
	};
	class Slot_SausageLight
	{
		name="SausageLight";
		displayName="SausageLight";
		selection="SausageLight";
		ghostIcon="rags";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class PortableGasLamp: Inventory_Base
	{};
	class SC_PortableGasLamp: PortableGasLamp
	{
		scope=2;
		displayName="Portable Gas Lamp";
		descriptionShort="Attach a GasCanister to operate.";
		model="SausageCo\storage\Sausagelights\lamp.p3d";
		overrideDrawArea="8.0";
		weight=330;
		itemSize[]={2,3};
		attachments[]=
		{
			"GasCanister"
		};
		inventorySlot[]=
		{
			"SausageLight"
		};
		containerSlot="GasCanister";
		hiddenSelections[]=
		{
			"glow",
			"anchr",
			"metal",
			"wood",
			"glow_on",
			"glow_off"
		};
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Sausagelights\data\anchr.rvmat",
			"SausageCo\storage\Sausagelights\data\anchr.rvmat",
			"SausageCo\storage\Sausagelights\data\metalPipe.rvmat",
			"SausageCo\storage\Sausagelights\data\woodBirch.rvmat",
			"",
			"SausageCo\storage\Sausagelights\data\anchr.rvmat",
		};
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
								"SausageCo\storage\Sausagelights\data\metalPipe.rvmat",
								"SausageCo\storage\Sausagelights\data\anchr.rvmat",
								"SausageCo\storage\Sausagelights\data\woodBirch.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\storage\Sausagelights\data\metalPipe.rvmat",
								"SausageCo\storage\Sausagelights\data\anchr.rvmat",
								"SausageCo\storage\Sausagelights\data\woodBirch.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\storage\Sausagelights\data\metalPipe.rvmat",
								"SausageCo\storage\Sausagelights\data\anchr.rvmat",
								"SausageCo\storage\Sausagelights\data\woodBirch.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\storage\Sausagelights\data\metalPipe.rvmat",
								"SausageCo\storage\Sausagelights\data\anchr.rvmat",
								"SausageCo\storage\Sausagelights\data\woodBirch.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\storage\Sausagelights\data\metalPipe.rvmat",
								"SausageCo\storage\Sausagelights\data\anchr.rvmat",
								"SausageCo\storage\Sausagelights\data\woodBirch.rvmat"
							}
						}
					};
				};
			};
		};
		class EnergyManager
		{
			switchOnAtSpawn=0;
			autoSwitchOff=1;
			autoSwitchOffWhenInCargo=1;
			energyStorageMax=0;
			energyUsagePerSecond=0.045;
			energyAtSpawn=0;
			powerSocketsCount=0;
			plugType=7;
			attachmentAction=1;
			updateInterval=50;
		};
	};
	class SausageLights_Torch: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Brazier";
		descriptionShort="A nice looking pedestal for your fire to light your world!";
		model="\SausageCo\storage\Sausagelights\fireplace.p3d";
		overrideDrawArea="8.0";
		rotationFlags=17;
		absorbency=0.5;
		isMeleeWeapon=1;
		burnTimePerRag=360;
		burnTimePerFullLardDose=900;
		burnTimePerFullFuelDose=600;
		maxConsumableLardDose=200;
		maxConsumableFuelDose=200;
		canBeSplit=0;
		stackedUnit="w";
		quantityBar=1;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=0;
		weight=240;
		itemSize[]={1,5}; 
		inventorySlot[]=
		{
			"Shoulder",
			"Melee"
		};
		hiddenSelections[]=
		{
			"flame",
			"zbytek"
		};
		attachments[]=
		{
			"Rags"
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
								"",
								"\SausageCo\storage\Sausagelights\data\metalbowl.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"",
								"\SausageCo\storage\Sausagelights\data\metalbowl.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"",
								"\SausageCo\storage\Sausagelights\data\metalbowl.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"",
								"\SausageCo\storage\Sausagelights\data\metalbowl.rvmat"
							}
						},
						
						{
							0,
							
							{
								"",
								"\SausageCo\storage\Sausagelights\data\metalbowl.rvmat"
							}
						}
					};
				};
			};
		};
		class EnergyManager
		{
			autoSwitchOff=1;
			energyAtSpawn=1800; // Start with full energy
			energyStorageMax=1800;
			energyUsagePerSecond=0; // Set to 0 for infinite burning
			wetnessExposure=0.01;
			updateInterval=4;
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeLightBlunt";
				range=1.6;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1.6;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=2.2;
			};
			class Default_SwitchedOn
			{
				ammo="MeleeLightBluntShock";
				range=1.6;
			};
			class Heavy_SwitchedOn
			{
				ammo="MeleeLightBluntShock_Heavy";
				range=1.6;
			};
			class Sprint_SwitchedOn
			{
				ammo="MeleeLightBluntShock_Heavy";
				range=2.2;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class TorchKindle
				{
					soundSet="Torch_kindle_SoundSet";
					id=201;
				};
				class pickup
				{
					soundSet="hatchet_pickup_SoundSet";
					id=797;
				};
				class woodenlog_drop
				{
					soundset="baseballbat_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class SausageLights_Torch_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "Torch Kit HOLO";
		model="\SausageCo\storage\Sausagelights\fireplace.p3d";
		
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxytorchfire1: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"torchfire1"
		};
		model="DZ\gear\cooking\fireplace.p3d";
	};
};