#define _ARMA_

class CfgPatches
{
	class ModularVestSystem
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Characters_Vests",
			"DZ_Characters_Backpacks",
			"DZ_Scripts",
			"DZ_Characters",
			"DZ_Gear_Drinks",
			"DZ_Gear_Medical",
			"DZ_Gear_Containers",
			"DZ_Weapons_Magazines"
		};
	};
};

class CfgMagazines
{
	class Ammunition_Base;
	class Ammo_Expansion_M203_Smoke_Base: Ammunition_Base
	{
		inventorySlot[] = {"VestGrenadeA","VestGrenadeB","VestGrenadeC","VestGrenadeD"};
	};
	class Ammo_Expansion_M203_HE: Ammunition_Base
	{
		inventorySlot[] = {"VestGrenadeA","VestGrenadeB","VestGrenadeC","VestGrenadeD"};
	};
};

class cfgVehicles
{	
	class Container_Base;
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class GP5GasMask;
	class BaseRadio;
	class Transmitter_Base;
	class Canteen;
	class MountainBag_ColorBase;
	class BalaclavaMask_ColorBase;
	class BaseballCap_ColorBase;
	class BDUPants;
	class TacticalShirt_ColorBase;
	class Grenade_Base;
	class PlateCarrierPouches;

	class MVS_Canteen_Base: Canteen
	{
		scope=0;
		displayName="MVS Canteen";
		model="\SausageCo\MVS Data\canteen\MVS_Canteen.p3d";
		hiddenSelections[] = {"zbytek",};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\canteen\canteen_co.paa"
		};	
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\canteen\canteen.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\canteen\canteen.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\canteen\canteen.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\canteen\canteen_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\canteen\canteen_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\canteen\canteen_destruct.rvmat"}}
                    };
				};
			};
		};		
	};

	class MVS_Canteen_OD: MVS_Canteen_Base
	{
		scope=2;
		displayName="MVS Canteen - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\canteen\canteen_co.paa"
		};		
	};
	class MVS_Canteen_ERDL: MVS_Canteen_Base
	{
		scope=2;
		displayName="MVS Canteen - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\canteen\canteen_co_ERDL.paa"
		};		
	};
	class MVS_Canteen_Tan: MVS_Canteen_Base
	{
		scope=2;
		displayName="MVS Canteen - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\canteen\canteen_co_Tan.paa"
		};		
	};
	class MVS_Canteen_Black: MVS_Canteen_Base
	{
		scope=2;
		displayName="MVS Canteen - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\canteen\canteen_co_Black.paa"
		};		
	};
	class MVS_Canteen_Snow: MVS_Canteen_Base
	{
		scope=2;
		displayName="MVS Canteen - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\canteen\canteen_co_Snow.paa"
		};		
	};
	class MVS_Canteen_Multicam: MVS_Canteen_Base
	{
		scope=2;
		displayName="MVS Canteen - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\canteen\canteen_co_MC.paa"
		};		
	};
	class MVS_Canteen_Multicam_Tropic: MVS_Canteen_Base
	{
		scope=2;
		displayName="MVS Canteen - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\canteen\canteen_co_MC_Tropic.paa"
		};		
	};
	class MVS_Canteen_Multicam_Black: MVS_Canteen_Base
	{
		scope=2;
		displayName="MVS Canteen - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\canteen\canteen_co_MC_Black.paa"
		};		
	};
	
	class PlateCarrierVest;
	class ModularVestSystem_Base: PlateCarrierVest
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_PlateCarrierBlank0";
		descriptionShort = "The Modular Vest System (MVS) is a plate carrier designed to accept multiple pouches to enhance warfighter capabilities.";
		model = "\SausageCo\MVS Data\ModularVestSystem_g.p3d";
		attachments[] = {"Belt_Left","VestGrenadeA","VestPouch","modular_pouch_2","modular_pouch_4","modular_pouch_5","modular_pouch_6","patch_01"};
		inventorySlot[] = {"Vest","MVS_vest"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co.paa"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\vestTextures\vest.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=225;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\vestTextures\vest.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\vestTextures\vest.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\vestTextures\vest_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\vestTextures\vest_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\vestTextures\vest_destruct.rvmat"}}
                    };
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.3;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.6;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.26;
					};
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\ModularVestSystem.p3d";
			female = "\SausageCo\MVS Data\ModularVestSystem.p3d";
		};
	};
	
	class HighCapacityVest_ColorBase;
	class ModularVestSystem_Heavy: PlateCarrierVest
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_PlateCarrierBlank0";
		descriptionShort = "The Modular Vest System (MVS) is a plate carrier designed to accept multiple pouches to enhance warfighter capabilities.";
		model = "\SausageCo\MVS Data\ModularVestSystemHeavy_g.p3d";
		attachments[] = {"Belt_Left","VestGrenadeA","modular_pouch_11","modular_pouch_6","Belt_Right","patch_01"};
		inventorySlot[] = {"Vest","MVS_vest"};		
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co.paa"
		};	
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\vestTextures\MVSHeavy.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=300;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\vestTextures\MVSHeavy.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\vestTextures\MVSHeavy.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\vestTextures\MVSHeavy_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\vestTextures\MVSHeavy_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\vestTextures\MVSHeavy_destruct.rvmat"}}
                    };
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.15;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.3;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.26;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\ModularVestSystemHeavy.p3d";
			female = "\SausageCo\MVS Data\ModularVestSystemHeavy.p3d";
		};
	};
	class MVS_Combat_Vest_Heavy_OD: ModularVestSystem_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co.paa"
		};
	};

	class MVS_Combat_Vest_Heavy_ERDL: ModularVestSystem_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_ERDL.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_ERDL.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_ERDL.paa"
		};
	};
	
	class MVS_Combat_Vest_Heavy_Tan: ModularVestSystem_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_Tan.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_Tan.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_Tan.paa"
		};
	};
	
	class MVS_Combat_Vest_Heavy_Black: ModularVestSystem_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_Black.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_Black.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_Black.paa"
		};
	};
		
	class MVS_Combat_Vest_Heavy_Snow: ModularVestSystem_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_Snow.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_Snow.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_Snow.paa"
		};
	};
	class MVS_Combat_Vest_Heavy_Multicam: ModularVestSystem_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_MC.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_MC.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_MC.paa"
		};
	};
	class MVS_Combat_Vest_Heavy_Multicam_Tropic: ModularVestSystem_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_MC_Tropic.paa"
		};
	};
	class MVS_Combat_Vest_Heavy_Multicam_Black: ModularVestSystem_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_MC_Black.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_MC_Black.paa",
			"\SausageCo\MVS Data\vestTextures\MVSHeavy_co_MC_Black.paa"
		};
	};

	class MVS_Combat_Vest_OD: ModularVestSystem_Base
	{
		scope = 2;
		displayName = "MVS - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co.paa"
		};
	};
	
	class MVS_Combat_Vest_ERDL: ModularVestSystem_Base
	{
		scope = 2;
		displayName = "MVS - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_ERDL.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_ERDL.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_ERDL.paa"
		};
	};
	
	class MVS_Combat_Vest_Tan: ModularVestSystem_Base
	{
		scope = 2;
		displayName = "MVS - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_tan.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_tan.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_tan.paa"
		};
	};
	
	class MVS_Combat_Vest_Black: ModularVestSystem_Base
	{
		scope = 2;
		displayName = "MVS - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_2.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_2.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_2.paa"
		};
	};
	
	class MVS_Combat_Vest_Snow: ModularVestSystem_Base
	{
		scope = 2;
		displayName = "MVS - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_snow.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_snow.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_snow.paa"
		};
	};
	class MVS_Combat_Vest_Multicam: ModularVestSystem_Base
	{
		scope = 2;
		displayName = "MVS - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_MC.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_MC.paa"
		};
	};
	class MVS_Combat_Vest_Multicam_Black: ModularVestSystem_Base
	{
		scope = 2;
		displayName = "MVS - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Black.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Black.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Black.paa"
		};
	};
	class MVS_Combat_Vest_Multicam_Tropic: ModularVestSystem_Base
	{
		scope = 2;
		displayName = "MVS - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Tropic.paa"
		};
	};
	class ModularChestRig_Base: HighCapacityVest_ColorBase
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_PlateCarrierBlank0";
		descriptionShort = "The Modular Vest System (MVS) is a chest rig designed to accept multiple pouches to enhance warfighter capabilities.";
		model = "\SausageCo\MVS Data\ModularVestRig_g.p3d";
		attachments[] = {"Belt_Left","VestGrenadeA","modular_pouch_2","VestPouch","modular_pouch_4","modular_pouch_5","modular_pouch_6","patch_01"};
		inventorySlot[] = {"Vest","MVS_vest"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co.paa"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\vestTextures\chestrig.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\vestTextures\chestrig.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\vestTextures\chestrig.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\vestTextures\chestrig_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\vestTextures\chestrig_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\vestTextures\chestrig_destruct.rvmat"}}
                    };
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\ModularVestRig.p3d";
			female = "\SausageCo\MVS Data\ModularVestRig_f.p3d";
		};
	};
	
	class MVS_ChestRig_OD: ModularChestRig_Base
	{
		scope = 2;
		displayName = "MVS Chestrig - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co.paa"
		};
	};
	
	class MVS_ChestRig_ERDL: ModularChestRig_Base
	{
		scope = 2;
		displayName = "MVS Chestrig - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_ERDL.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_ERDL.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_ERDL.paa"
		};
	};
	
	class MVS_ChestRig_Tan: ModularChestRig_Base
	{
		scope = 2;
		displayName = "MVS Chestrig - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_Tan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_Tan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_Tan.paa"
		};
	};
	
	class MVS_ChestRig_Black: ModularChestRig_Base
	{
		scope = 2;
		displayName = "MVS Chestrig - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_Black.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_Black.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_Black.paa"
		};
	};
	
	class MVS_ChestRig_Snow: ModularChestRig_Base
	{
		scope = 2;
		displayName = "MVS Chestrig - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_Snow.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_Snow.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_Snow.paa"
		};
	};
	class MVS_ChestRig_Multicam: ModularChestRig_Base
	{
		scope = 2;
		displayName = "MVS Chestrig - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_MC.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_MC.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_MC.paa"
		};
	};
	class MVS_ChestRig_Multicam_Tropic: ModularChestRig_Base
	{
		scope = 2;
		displayName = "MVS Chestrig - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_MC_Tropic.paa"
		};
	};
	class MVS_ChestRig_Multicam_Black: ModularChestRig_Base
	{
		scope = 2;
		displayName = "MVS Chestrig - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_MC_Black.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_MC_Black.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Chestrig_co_MC_Black.paa"
		};
	};
	
	class MVS_Pouch_Base: Container_Base
	{
		scope = 0;
		displayName = "";
		descriptionShort = "";
		model = "\SausageCo\MVS Data\modular_pouch_g.p3d";
		rotationFlags=0;
		itemSize[] = {4,3};
		itemsCargoSize[] = {6,4};
		inventorySlot[] = {"VestPouch","modular_pouch_2"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co.paa"
		};
		weight=250;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		allowOwnedCargoManipulation=1;
		randomQuantity=2;
		lootTag[]=
		{
			"Military_east",
			"Military_west"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\vestTextures\vest.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\vestTextures\vest.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\vestTextures\vest.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\vestTextures\vest_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\vestTextures\vest_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\vestTextures\vest_destruct.rvmat"}}
                    };
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
	
	class Modular_Pouch_Base: MVS_Pouch_Base
	{
		scope = 0;
		displayName = "Magazine Pouch";
		descriptionShort = "The MVS magazine pouch, capable of holding single stack magazines, up to drum-size";
		model = "\SausageCo\MVS Data\modular_pouch_g.p3d";
		itemSize[] = {4,3};
		itemsCargoSize[] = {6,4};
		inventorySlot[] = {"VestPouch","modular_pouch_2"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co.paa"
		};
	};
	
	class MVS_Magazine_Pouch_OD: Modular_Pouch_Base
	{
		scope = 2;
		displayName = "MVS Magazine Pouch - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co.paa"
		};
	};

	class MVS_Magazine_Pouch_ERDL: Modular_Pouch_Base
	{
		scope = 2;
		displayName = "MVS Magazine Pouch - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_ERDL.paa"
		};
	};
	
	class MVS_Magazine_Pouch_Tan: Modular_Pouch_Base
	{
		scope = 2;
		displayName = "MVS Magazine Pouch - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_tan.paa"
		};
	};
	
	class MVS_Magazine_Pouch_Black: Modular_Pouch_Base
	{
		scope = 2;
		displayName = "MVS Magazine Pouch - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_2.paa"
		};
	};
	class MVS_Magazine_Pouch_Snow: Modular_Pouch_Base
	{
		scope = 2;
		displayName = "MVS Magazine Pouch - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_snow.paa"
		};
	};
	class MVS_Magazine_Pouch_Multicam: Modular_Pouch_Base
	{
		scope = 2;
		displayName = "MVS Magazine Pouch - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC.paa"
		};
	};
	class MVS_Magazine_Pouch_Multicam_Black: Modular_Pouch_Base
	{
		scope = 2;
		displayName = "MVS Magazine Pouch - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Black.paa"
		};
	};
	class MVS_Magazine_Pouch_Multicam_Tropic: Modular_Pouch_Base
	{
		scope = 2;
		displayName = "MVS Magazine Pouch - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Tropic.paa"
		};
	};
	
	class MVS_Molle_Panel_Base: MVS_Pouch_Base
	{
		scope = 0;
		displayName = "MVS Molle Panel";
		descriptionShort = "The MVS molle panel, which attaches to the MVS belt, can store up to four grenades or 40mm rounds from DayZ Expansion mod.";
		model = "\SausageCo\MVS Data\MVS_Molle_Panel.p3d";
		rotationFlags=0;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		allowOwnedCargoManipulation = 1;
		itemSize[] = {2,3};
		itemsCargoSize[] = {};
		weight=250;
		inventorySlot[] = {"modular_pouch_10"};
		attachments[] = {"VestGrenadeA","VestGrenadeB","VestGrenadeC","VestGrenadeD"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co.paa"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	
	class MVS_Molle_Panel_OD: MVS_Molle_Panel_Base
	{
		scope = 2;
		displayName = "MVS Molle Panel - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co.paa"
		};
	};
	class MVS_Molle_Panel_Black: MVS_Molle_Panel_Base
	{
		scope = 2;
		displayName = "MVS Molle Panel - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_2.paa"
		};
	};
	class MVS_Molle_Panel_Tan: MVS_Molle_Panel_Base
	{
		scope = 2;
		displayName = "MVS Molle Panel - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_Tan.paa"
		};
	};
	class MVS_Molle_Panel_ERDL: MVS_Molle_Panel_Base
	{
		scope = 2;
		displayName = "MVS Molle Panel - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_ERDL.paa"
		};
	};
	class MVS_Molle_Panel_Snow: MVS_Molle_Panel_Base
	{
		scope = 2;
		displayName = "MVS Molle Panel - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_Snow.paa"
		};
	};
	class MVS_Molle_Panel_Multicam: MVS_Molle_Panel_Base
	{
		scope = 2;
		displayName = "MVS Molle Panel - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC.paa"
		};
	};
	class MVS_Molle_Panel_Multicam_Tropic: MVS_Molle_Panel_Base
	{
		scope = 2;
		displayName = "MVS Molle Panel - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Tropic.paa"
		};
	};
	class MVS_Molle_Panel_Multicam_Black: MVS_Molle_Panel_Base
	{
		scope = 2;
		displayName = "MVS Molle Panel - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Black.paa"
		};
	};
	
	class Modular_Pouch_Base_Taco: MVS_Pouch_Base
	{
		scope = 0;
		displayName = "MVS Raid Pouch";
		descriptionShort = "The MVS Raid pouch, capable of holding Pliers, a Screwdriver, and lockpick";
		model = "\SausageCo\MVS Data\modular_pouch_12.p3d";
		attachments[] = {"magazine4","magazine5","magazine7","MVS_Screwdriver","MVS_Pliers","Screwdriver1","Pliers1","MVS_Lockpick"};
		rotationFlags=0;		
		itemSize[] = {4,3};
		itemsCargoSize[] = {6,4};
		inventorySlot[] = {"modular_pouch_2","modular_pouch_12","VestPouch"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\taco_co.paa"
		};
		weight=250;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		allowOwnedCargoManipulation=1;
		randomQuantity=2;
		lootTag[]=
		{
			"Military_east",
			"Military_west"
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\vestTextures\taco.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\vestTextures\taco.rvmat"}},
						{0.7,{"SausageCo\MVS Data\vestTextures\taco.rvmat"}},
						{0.5,{"SausageCo\MVS Data\vestTextures\taco_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\vestTextures\taco_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\vestTextures\taco_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
	
	class MVS_Taco_Pouch_OD: Modular_Pouch_Base_Taco
	{
		scope = 2;
		displayName = "MVS Raid Pouch - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\taco_co.paa"
		};
	};
	
	class MVS_Taco_Pouch_ERDL: Modular_Pouch_Base_Taco
	{
		scope = 2;
		displayName = "MVS Raid Pouch - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\taco_co_ERDL.paa"
		};
	};
	
	class MVS_Taco_Pouch_Tan: Modular_Pouch_Base_Taco
	{
		scope = 2;
		displayName = "MVS Raid Pouch - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\taco_co_tan.paa"
		};
	};
	
	class MVS_Taco_Pouch_Black: Modular_Pouch_Base_Taco
	{
		scope = 2;
		displayName = "MVS Raid Pouch - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\taco_co_black.paa"
		};
	};
	class MVS_Taco_Pouch_Snow: Modular_Pouch_Base_Taco
	{
		scope = 2;
		displayName = "MVS Raid Pouch - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\taco_co_snow.paa"
		};
	};
	class MVS_Taco_Pouch_Multicam: Modular_Pouch_Base_Taco
	{
		scope = 2;
		displayName = "MVS Raid Pouch - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\taco_co_MC.paa"
		};
	};
	class MVS_Taco_Pouch_Multicam_Tropic: Modular_Pouch_Base_Taco
	{
		scope = 2;
		displayName = "MVS Raid Pouch - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\taco_co_MC_Tropic.paa"
		};
	};
	class MVS_Taco_Pouch_Multicam_Black: Modular_Pouch_Base_Taco
	{
		scope = 2;
		displayName = "MVS Raid Pouch - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\taco_co_MC_Black.paa"
		};
	};

	class Modular_Pouch_Base_Admin: MVS_Pouch_Base
	{
		scope = 0;
		displayName = "Magazine Pouch";
		descriptionShort = "The MVS admin pouch, good for storing quick access items like NVGs, batteries, etc.";
		model = "\SausageCo\MVS Data\modular_pouch_4.p3d";
		itemSize[] = {2,3};
		itemsCargoSize[] = {3,4};
		inventorySlot[] = {"modular_pouch_4","modular_pouch_9","modular_pouch_10","modular_pouch_13"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co.paa"
		};
		weight=250;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		allowOwnedCargoManipulation=1;
		randomQuantity=2;
		lootTag[]=
		{
			"Military_east",
			"Military_west"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
	
	class MVS_Admin_Pouch_OD: Modular_Pouch_Base_Admin
	{
		scope = 2;
		displayName = "MVS Admin Pouch - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co.paa"
		};
	};
	
	class MVS_Admin_Pouch_ERDL: Modular_Pouch_Base_Admin
	{
		scope = 2;
		displayName = "MVS Admin Pouch - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_ERDL.paa"
		};
	};
	
	class MVS_Admin_Pouch_Tan: Modular_Pouch_Base_Admin
	{
		scope = 2;
		displayName = "MVS Admin Pouch - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_tan.paa"
		};
	};	
	
	class MVS_Admin_Pouch_Black: Modular_Pouch_Base_Admin
	{
		scope = 2;
		displayName = "MVS Admin Pouch - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_2.paa"
		};
	};
	class MVS_Admin_Pouch_Snow: Modular_Pouch_Base_Admin
	{
		scope = 2;
		displayName = "MVS Admin Pouch - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_snow.paa"
		};
	};
	class MVS_Admin_Pouch_Multicam: Modular_Pouch_Base_Admin
	{
		scope = 2;
		displayName = "MVS Admin Pouch - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC.paa"
		};
	};
	class MVS_Admin_Pouch_Multicam_Black: Modular_Pouch_Base_Admin
	{
		scope = 2;
		displayName = "MVS Admin Pouch - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Black.paa"
		};
	};
	class MVS_Admin_Pouch_Multicam_Tropic: Modular_Pouch_Base_Admin
	{
		scope = 2;
		displayName = "MVS Admin Pouch - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Tropic.paa"
		};
	};
	class Modular_Pouch_Base_Heavy: MVS_Pouch_Base
	{
		scope = 0;
		displayName = "MVS Heavy LMG Pouch";
		descriptionShort = "The MVS LMG pouch, good for storing belt-fed ammunition or drum mags";
		model = "\SausageCo\MVS Data\modular_pouch_11.p3d";
		itemSize[] = {4,5};
		itemsCargoSize[] = {6,5};
		inventorySlot[] = {"modular_pouch_11"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vestheavy_co.paa"
		};
		weight=250;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		allowOwnedCargoManipulation=1;
		randomQuantity=2;
		lootTag[]=
		{
			"Military_east",
			"Military_west"
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\vestTextures\vestheavy.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\vestTextures\vestheavy.rvmat"}},
						{0.7,{"SausageCo\MVS Data\vestTextures\vestheavy.rvmat"}},
						{0.5,{"SausageCo\MVS Data\vestTextures\vestheavy_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\vestTextures\vestheavy_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\vestTextures\vestheavy_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};

	class MVS_Heavy_Pouch_OD: Modular_Pouch_Base_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy LMG Pouch - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vestheavy_co.paa"
		};
	};
	
	class MVS_Heavy_Pouch_ERDL: Modular_Pouch_Base_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy LMG Pouch - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vestheavy_co_ERDL.paa"
		};
	};
	
	class MVS_Heavy_Pouch_Tan: Modular_Pouch_Base_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy LMG Pouch - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vestheavy_co_tan.paa"
		};
	};	
	
	class MVS_Heavy_Pouch_Black: Modular_Pouch_Base_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy LMG Pouch - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vestheavy_co_2.paa"
		};
	};
	class MVS_Heavy_Pouch_Snow: Modular_Pouch_Base_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy LMG Pouch - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vestheavy_co_snow.paa"
		};
	};
	class MVS_Heavy_Pouch_Multicam: Modular_Pouch_Base_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy LMG Pouch - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vestheavy_co_MC.paa"
		};
	};
	class MVS_Heavy_Pouch_Multicam_Tropic: Modular_Pouch_Base_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy LMG Pouch - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vestheavy_co_MC_Tropic.paa"
		};
	};
	class MVS_Heavy_Pouch_Multicam_Black: Modular_Pouch_Base_Heavy
	{
		scope = 2;
		displayName = "MVS Heavy LMG Pouch - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vestheavy_co_MC_Black.paa"
		};
	};

	class Modular_Pouch_Base_Utility: MVS_Pouch_Base
	{
		scope = 0;
		displayName = "Magazine Pouch";
		descriptionShort = "The MVS utility pouch, good for storing a knife or multitool";
		model = "\SausageCo\MVS Data\modular_pouch_5.p3d";
		itemSize[] = {1,3};
		itemsCargoSize[] = {1,3};
		inventorySlot[] = {"modular_pouch_5"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co.paa"
		};
		weight=250;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		allowOwnedCargoManipulation=1;
		randomQuantity=2;
		lootTag[]=
		{
			"Military_east",
			"Military_west"
		};
	};
	
	class MVS_Utility_Pouch_OD: Modular_Pouch_Base_Utility
	{
		scope = 2;
		displayName = "MVS Utility Pouch - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co.paa"
		};
	};
	
	class MVS_Utility_Pouch_ERDL: Modular_Pouch_Base_Utility
	{
		scope = 2;
		displayName = "MVS Utility Pouch - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_ERDL.paa"
		};
	};
	
	class MVS_Utility_Pouch_Tan: Modular_Pouch_Base_Utility
	{
		scope = 2;
		displayName = "MVS Utility Pouch - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_tan.paa"
		};
	};	
	
	class MVS_Utility_Pouch_Black: Modular_Pouch_Base_Utility
	{
		scope = 2;
		displayName = "MVS Utility Pouch - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_2.paa"
		};
	};
	class MVS_Utility_Pouch_Snow: Modular_Pouch_Base_Utility
	{
		scope = 2;
		displayName = "MVS Utility Pouch - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_snow.paa"
		};
	};
	class MVS_Utility_Pouch_Multicam: Modular_Pouch_Base_Utility
	{
		scope = 2;
		displayName = "MVS Utility Pouch - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC.paa"
		};
	};
	class MVS_Utility_Pouch_Multicam_Black: Modular_Pouch_Base_Utility
	{
		scope = 2;
		displayName = "MVS Utility Pouch - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Black.paa"
		};
	};
	class MVS_Utility_Pouch_Multicam_Tropic: Modular_Pouch_Base_Utility
	{
		scope = 2;
		displayName = "MVS Utility Pouch - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Tropic.paa"
		};
	};

	class Modular_Pouch_Base_Medical: MVS_Pouch_Base
	{
		scope = 0;
		displayName = "Medical Pouch";
		descriptionShort = "The MVS medical pouch, which has three external attachment points for morphine, epinephrine, and bandages";
		model = "\SausageCo\MVS Data\modular_pouch_6.p3d";
		itemSize[] = {2,2};
		itemsCargoSize[] = {2,4};
		attachments[]={"morphine","epinephrine","MedicalBandage"};
		inventorySlot[] = {"modular_pouch_6","modular_pouch_9","modular_pouch_10","modular_pouch_13"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_medical.paa"
		};
		weight=250;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		allowOwnedCargoManipulation=1;
		randomQuantity=2;
		lootTag[]=
		{
			"Military_east",
			"Military_west"
		};
	};
	
	class MVS_Medical_Pouch_OD: Modular_Pouch_Base_Medical
	{
		scope = 2;
		displayName = "MVS Medical Pouch - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_medical.paa"
		};
	};
	
	class MVS_Medical_Pouch_ERDL: Modular_Pouch_Base_Medical
	{
		scope = 2;
		displayName = "MVS Medical Pouch - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_ERDL_medical.paa"
		};
	};
	
	class MVS_Medical_Pouch_Tan: Modular_Pouch_Base_Medical
	{
		scope = 2;
		displayName = "MVS Medical Pouch - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_tan_medical.paa"
		};
	};	
	
	class MVS_Medical_Pouch_Black: Modular_Pouch_Base_Medical
	{
		scope = 2;
		displayName = "MVS Medical Pouch - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_2_medical.paa"
		};
	};
	class MVS_Medical_Pouch_Snow: Modular_Pouch_Base_Medical
	{
		scope = 2;
		displayName = "MVS Medical Pouch - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_snow_medical.paa"
		};
	};
	class MVS_Medical_Pouch_Multicam: Modular_Pouch_Base_Medical
	{
		scope = 2;
		displayName = "MVS Medical Pouch - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_medical.paa"
		};
	};
	class MVS_Medical_Pouch_Multicam_Black: Modular_Pouch_Base_Medical
	{
		scope = 2;
		displayName = "MVS Medical Pouch - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Black_medical.paa"
		};
	};
	class MVS_Medical_Pouch_Multicam_Tropic: Modular_Pouch_Base_Medical
	{
		scope = 2;
		displayName = "MVS Medical Pouch - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\vest_co_MC_Tropic_medical.paa"
		};
	};

	class Mich2001Helmet;
	class MVS_Helmet_Base: Mich2001Helmet
	{
		scope = 0;
		displayName = "MVS Combat Helmet";
		descriptionShort = "The MICH-style combat helmet offers good ballistic protection, much like the MICH 2001 combat helmet";
		attachments[]={"NVG","patch_03","MVSBattery1","MVSBattery2","MVS_Comtacs","helmetFlashlight"};
		inventorySlot[] = {"Headgear","MVS_helmet"};
		model = "\SausageCo\MVS Data\Helmets\Combat_Helmet_g.p3d";
		hiddenSelections[] = {"camoground","camomale","camofemale","zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\do_helmets_co.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co.paa",
			"modularvestsystem\data\helmets\do_helmets_2_co.paa"
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Helmets\do_helmet.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Helmets\do_helmet.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Helmets\do_helmet.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Helmets\do_helmet_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Helmets\do_helmet_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Helmets\do_helmet_destruct.rvmat"}}
					};
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Helmets\Combat_Helmet_1.p3d";
			female = "\SausageCo\MVS Data\Helmets\Combat_Helmet_1.p3d";
		};
	};
	
	class MVS_Helmet_01_Tan: MVS_Helmet_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\do_helmets_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreComtacs_co.paa"
		};
	};
	
	class MVS_Helmet_01_Tan_Worn: MVS_Helmet_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Scuffed";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\do_helmets_co_Tan_Worn.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_Tan_Worn.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_Tan_Worn.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreComtacs_co.paa"
		};
	};
	
	class MVS_Helmet_01_OD: MVS_Helmet_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\do_helmets_co.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreComtacs_co.paa"
		};
	};
	
	class MVS_Helmet_01_Black: MVS_Helmet_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\do_helmets_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreComtacs_co.paa"
		};
	};
	class MVS_Helmet_01_Snow: MVS_Helmet_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\do_helmets_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreComtacs_co.paa"
		};
	};
	class MVS_Helmet_01_ERDL: MVS_Helmet_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\do_helmets_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreComtacs_co.paa"
		};
	};
	class MVS_Helmet_01_Multicam: MVS_Helmet_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\do_helmets_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreComtacs_co.paa"
		};
	};
	class MVS_Helmet_01_Multicam_Black: MVS_Helmet_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\do_helmets_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreComtacs_co.paa"
		};
	};
	class MVS_Helmet_01_Multicam_Tropic: MVS_Helmet_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\do_helmets_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreComtacs_co.paa"
		};
	};
	
	class MVS_Helmet_2_Base: Mich2001Helmet
	{
		scope = 0;
		displayName = "MVS Combat Helmet 2";
		descriptionShort = "The MICH-style combat helmet offers good ballistic protection, much like the MICH 2001 combat helmet";
		attachments[]={"NVG","patch_03","MVS_Comtacs","helmetFlashlight"};
		inventorySlot[] = {"Headgear","MVS_helmet"};
		model = "\SausageCo\MVS Data\Helmets\Combat_Helmet_2_g.p3d";
		hiddenSelections[] = {"camoground","camomale","camofemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_OD_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_OD_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_OD_co.paa"
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Helmets\mvs_helmet_2.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Helmets\mvs_helmet_2.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Helmets\mvs_helmet_2.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Helmets\mvs_helmet_2_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Helmets\mvs_helmet_2_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Helmets\mvs_helmet_2_destruct.rvmat"}}
					};
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Helmets\Combat_Helmet_2.p3d";
			female = "\SausageCo\MVS Data\Helmets\Combat_Helmet_2.p3d";
		};
	};
	
	class MVS_Helmet_02_OD: MVS_Helmet_2_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_OD_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_OD_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_OD_co.paa"
		};
	};
	class MVS_Helmet_02_Tan: MVS_Helmet_2_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_Tan_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_Tan_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_Tan_co.paa"
		};
	};
	class MVS_Helmet_02_Black: MVS_Helmet_2_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_Black_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_Black_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_Black_co.paa"
		};
	};
	class MVS_Helmet_02_Multicam_Black: MVS_Helmet_2_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_MC_Black_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_MC_Black_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_MC_Black_co.paa"
		};
	};
	class MVS_Helmet_02_Multicam: MVS_Helmet_2_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_MC_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_MC_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_MC_co.paa"
		};
	};
	class MVS_Helmet_02_Multicam_Tropic: MVS_Helmet_2_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_MC_Tropic_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_MC_Tropic_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_MC_Tropic_co.paa"
		};
	};
	class MVS_Helmet_02_ERDL: MVS_Helmet_2_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_ERDL_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_ERDL_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_ERDL_co.paa"
		};
	};
	class MVS_Helmet_02_Snow: MVS_Helmet_2_Base
	{
		scope = 2;
		displayName = "MVS Combat Helmet - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_snow_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_snow_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Helmet_2_snow_co.paa"
		};
	};
	
	class MVS_6B47Helmet_Base: Mich2001Helmet
	{
		scope = 0;
		displayName = "MVS 6B47 Helmet";
		descriptionShort = "The Russian-designed 6B47 helmet is a part of ‘Ratnik’ (‘Warrior’) combat gear.";
		attachments[]={"NVG","patch_03","MVS_Comtacs","helmetFlashlight"};
		inventorySlot[] = {"Headgear","MVS_helmet"};
		model = "\SausageCo\MVS Data\Helmets\MVS_6B47_g.p3d";
		hiddenSelections[] = {"camoground","camomale","camofemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\do_helmets_co.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co.paa",
			"\SausageCo\MVS Data\Helmets\do_helmets_co.paa"
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Helmets\MVS_6B47.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Helmets\MVS_6B47.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Helmets\MVS_6B47.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Helmets\MVS_6B47_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Helmets\MVS_6B47_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Helmets\MVS_6B47_destruct.rvmat"}}
					};
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Helmets\MVS_6B47.p3d";
			female = "\SausageCo\MVS Data\Helmets\MVS_6B47_f.p3d";
		};
	};
	
	class MVS_6B47_Helmet_OD: MVS_6B47Helmet_Base
	{
		scope = 2;
		displayName = "MVS 6B47 - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_6B47_OD_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_6B47_OD_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_6B47_OD_co.paa"
		};
	};
	
	class MVS_6B47_Helmet_Tan: MVS_6B47Helmet_Base
	{
		scope = 2;
		displayName = "MVS 6B47 - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_6B47_Tan_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_6B47_Tan_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_6B47_Tan_co.paa"
		};
	};
	
	class MVS_6B47_Helmet_Black: MVS_6B47Helmet_Base
	{
		scope = 2;
		displayName = "MVS 6B47 - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_6B47_Black_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_6B47_Black_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_6B47_Black_co.paa"
		};
	};
	
	class MVS_OpsCore_Base: Mich2001Helmet
	{
		scope = 0;
		displayName = "MVS High Cut Helmet";
		descriptionShort = "The High Cut style combat helmet offers good ballistic protection, and comes prepped with comtac hearing protection";
		attachments[]={"NVG","patch_03","MVS_Comtacs","helmetFlashlight"};
		inventorySlot[] = {"Headgear","MVS_helmet"};
		model = "\SausageCo\MVS Data\Helmets\OpsCore_Helmet_g.p3d";
		hiddenSelections[] = {"camoground","camomale","camofemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co.paa"
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Helmets\OpsCore.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Helmets\OpsCore.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Helmets\OpsCore.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Helmets\OpsCore_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Helmets\OpsCore_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Helmets\OpsCore_destruct.rvmat"}}
					};
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Helmets\OpsCore_Helmet.p3d";
			female = "\SausageCo\MVS Data\Helmets\OpsCore_Helmet.p3d";
		};
	};

	class MVS_OpsCore_Tan: MVS_OpsCore_Base
	{
		scope = 2;
		displayName = "MVS High Cut Helmet - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Tan.paa"
		};
	};
	
	class MVS_OpsCore_OD: MVS_OpsCore_Base
	{
		scope = 2;
		displayName = "MVS High Cut Helmet - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co.paa"
		};
	};
	
	class MVS_OpsCore_ERDL: MVS_OpsCore_Base
	{
		scope = 2;
		displayName = "MVS High Cut Helmet - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_ERDL.paa"
		};
	};
	
	class MVS_OpsCore_Black: MVS_OpsCore_Base
	{
		scope = 2;
		displayName = "MVS High Cut Helmet - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Black.paa"
		};
	};
	class MVS_OpsCore_Snow: MVS_OpsCore_Base
	{
		scope = 2;
		displayName = "MVS High Cut Helmet - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Snow.paa"
		};
	};	
	class MVS_OpsCore_Multicam: MVS_OpsCore_Base
	{
		scope = 2;
		displayName = "MVS High Cut Helmet - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC.paa"
		};
	};	
	class MVS_OpsCore_Multicam_Tropic: MVS_OpsCore_Base
	{
		scope = 2;
		displayName = "MVS High Cut Helmet - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Tropic.paa"
		};
	};	
	class MVS_OpsCore_Multicam_Black: MVS_OpsCore_Base
	{
		scope = 2;
		displayName = "MVS High Cut Helmet - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Black.paa"
		};
	};
	
	class MVS_ArmoredHelmet_Base: MVS_OpsCore_Base
	{
		scope=0;
		model="SausageCo\MVS Data\Helmets\Armored_Helmet_g.p3d";
		descriptionShort = "The Armored MVS helmet offers the best ballistic protection, and comes prepped with a mandible and ballistic visor. Identifier patch can be attached.";
		attachments[]={"patch_03"};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale",
			"zbytek",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co.paa",
			"\SausageCo\MVS Data\Helmets\Mandible_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Visor.paa"
		};
        hiddenSelectionsMaterials[]=
        {
			"SausageCo\MVS Data\Helmets\OpsCoreMandible.rvmat",
			"SausageCo\MVS Data\Helmets\OpsCore.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\Helmets\OpsCore.rvmat","SausageCo\MVS Data\Helmets\OpsCoreMandible.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\Helmets\OpsCore.rvmat","SausageCo\MVS Data\Helmets\OpsCoreMandible.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\Helmets\OpsCore_damage.rvmat","SausageCo\MVS Data\Helmets\OpsCoreMandible_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\Helmets\OpsCore_damage.rvmat","SausageCo\MVS Data\Helmets\OpsCoreMandible_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\Helmets\OpsCore_destruct.rvmat","SausageCo\MVS Data\Helmets\OpsCoreMandible_destruct.rvmat"}}
                    };
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.3;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.13;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.26;
					};
				};
			};
		};
		class ClothingTypes
		{
			male="SausageCo\MVS Data\Helmets\Armored_Helmet.p3d";
			female="SausageCo\MVS Data\Helmets\Armored_Helmet.p3d";
		};
	};

	class MVS_ArmoredHelmet_Tan: MVS_ArmoredHelmet_Base
	{
		scope = 2;
		displayName = "MVS Armored Helmet - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCoreArmored_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreArmored_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreArmored_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\Mandible_Tan.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Visor.paa"
		};
	};
	
	class MVS_ArmoredHelmet_OD: MVS_ArmoredHelmet_Base
	{
		scope = 2;
		displayName = "MVS Armored Helmet - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCoreArmored_co.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreArmored_co.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreArmored_co.paa",
			"\SausageCo\MVS Data\Helmets\Mandible_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Visor.paa"
		};
	};
	
	class MVS_ArmoredHelmet_ERDL: MVS_ArmoredHelmet_Base
	{
		scope = 2;
		displayName = "MVS Armored Helmet - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\Mandible_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Visor.paa"
		};
	};
	
	class MVS_ArmoredHelmet_Black: MVS_ArmoredHelmet_Base
	{
		scope = 2;
		displayName = "MVS Armored Helmet - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCoreArmored_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreArmored_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCoreArmored_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\Mandible_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Visor.paa"
		};
	};
	class MVS_ArmoredHelmet_Snow: MVS_ArmoredHelmet_Base
	{
		scope = 2;
		displayName = "MVS Armored Helmet - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\Mandible_Snow.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Visor.paa"
		};
	};	
	class MVS_ArmoredHelmet_Multicam: MVS_ArmoredHelmet_Base
	{
		scope = 2;
		displayName = "MVS Armored Helmet - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\Mandible_MC.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Visor.paa"
		};
	};
	class MVS_ArmoredHelmet_Multicam_Tropic: MVS_ArmoredHelmet_Base
	{
		scope = 2;
		displayName = "MVS Armored Helmet - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\Mandible_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Visor.paa"
		};
	};
	class MVS_ArmoredHelmet_Multicam_Black: MVS_ArmoredHelmet_Base
	{
		scope = 2;
		displayName = "MVS Armored Helmet - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\Mandible_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Visor.paa"
		};
	};
	
	class MVS_Altyn_Helmet_Base: MVS_ArmoredHelmet_Base
	{
		scope=0;
		model="SausageCo\MVS Data\Helmets\MVS_Altyn_Helmet_g.p3d";
		descriptionShort = "The Altyn MVS helmet offers the best ballistic protection. Identifier patch and Altyn Visor can be attached.";
		attachments[]={"MVS_Altyn_Visor","patch_03"};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_ca.paa"
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Helmets\MVS_Altyn.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Helmets\MVS_Altyn.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Helmets\MVS_Altyn.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Helmets\MVS_Altyn_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Helmets\MVS_Altyn_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Helmets\MVS_Altyn_destruct.rvmat"}}
					};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.3;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.13;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.26;
					};
				};
			};
		};		
		class ClothingTypes
		{
			male="SausageCo\MVS Data\Helmets\MVS_Altyn_Helmet.p3d";
			female="SausageCo\MVS Data\Helmets\MVS_Altyn_Helmet.p3d";
		};

	};

	class MVS_Altyn_OD: MVS_Altyn_Helmet_Base
	{
		scope = 2;
		displayName = "MVS Altyn Helmet - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_ca.paa"
		};
	};
	class MVS_Altyn_Tan: MVS_Altyn_Helmet_Base
	{
		scope = 2;
		displayName = "MVS Altyn Helmet - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_ca.paa"
		};
	};
	class MVS_Altyn_Black: MVS_Altyn_Helmet_Base
	{
		scope = 2;
		displayName = "MVS Altyn Helmet - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_ca.paa"
		};
	};
	class MVS_Altyn_Visor: Clothing
	{
		scope=0;
		displayName="MVS Altyn Visor";
		descriptionShort="Attaches to the MVS Altyn Helmet";
		weight = 110;
		absorbency = 0.8;
		heatIsolation = 0.25;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		model="SausageCo\MVS Data\Helmets\MVS_Altyn_Helmet_Visor.p3d";
		inventorySlot[]=
		{
			"MVS_Altyn_Visor"
		};
		itemSize[]={2,2};
		rotationFlags=0;
		attachments[]=
		{
		};
		simpleHiddenSelections[]=
		{
			"hide"
		};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_ca.paa"
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Helmets\MVS_Altyn.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Helmets\MVS_Altyn.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Helmets\MVS_Altyn.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Helmets\MVS_Altyn_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Helmets\MVS_Altyn_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Helmets\MVS_Altyn_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};

	};
	

	class MVS_Altyn_Visor_OD: MVS_Altyn_Visor
	{
		scope = 2;
		displayName = "MVS Altyn Visor - OD";
		color = "OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_ca.paa"
		};
	};
	class MVS_Altyn_Visor_Tan: MVS_Altyn_Visor
	{
		scope = 2;
		displayName = "MVS Altyn Visor - Tan";
		color = "Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_ca.paa"
		};
	};
	class MVS_Altyn_Visor_Black: MVS_Altyn_Visor
	{
		scope = 2;
		displayName = "MVS Altyn Visor - Black";
		color = "Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_ca.paa"
		};
	};
	
	class MVS_Altyn_Visor_Lifted: Clothing
	{
		scope=0;
		displayName="MVS Altyn Visor";
		descriptionShort="Attaches to the MVS Altyn Helmet";
		weight = 110;
		absorbency = 0.8;
		heatIsolation = 0.25;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		model="SausageCo\MVS Data\Helmets\MVS_Altyn_Helmet_Visor_Lifted.p3d";
		inventorySlot[]=
		{
			"MVS_Altyn_Visor"
		};
		itemSize[]={2,2};
		rotationFlags=0;
		attachments[]=
		{
		};
		simpleHiddenSelections[]=
		{
			"hide"
		};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_ca.paa"
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Helmets\MVS_Altyn.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Helmets\MVS_Altyn.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Helmets\MVS_Altyn.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Helmets\MVS_Altyn_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Helmets\MVS_Altyn_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Helmets\MVS_Altyn_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};

	};
	
	class MVS_Altyn_Visor_Lifted_OD: MVS_Altyn_Visor_Lifted
	{
		scope = 2;
		displayName = "MVS Altyn Visor - OD";
		color = "OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_ca.paa"
		};
	};
	class MVS_Altyn_Visor_Lifted_Tan: MVS_Altyn_Visor_Lifted
	{
		scope = 2;
		displayName = "MVS Altyn Visor - Tan";
		color = "Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_ca.paa"
		};
	};
	class MVS_Altyn_Visor_Lifted_Black: MVS_Altyn_Visor_Lifted
	{
		scope = 2;
		displayName = "MVS Altyn Visor - Black";
		color = "Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Altyn_ca.paa"
		};
	};
	
	class MVS_WarriorHelmet_Base: MVS_ArmoredHelmet_Base
	{
		scope=0;
		model="SausageCo\MVS Data\Helmets\Mandalorian_Helmet_g.p3d";
		descriptionShort = "The MVS Warrior helmet offers the best ballistic protection, and comes prepped with a bounty hunter-worthy face shield. Identifier patch and NVGs can be attached.";
		attachments[]={"NVG","patch_03","helmetFlashlight"};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale",
			"zbytek",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Helmet_co.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Visor_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"SausageCo\MVS Data\Helmets\OpsCore.rvmat",
			"SausageCo\MVS Data\Helmets\MandalorianHelmet.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Helmets\OpsCore.rvmat","SausageCo\MVS Data\Helmets\MandalorianHelmet.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Helmets\OpsCore.rvmat","SausageCo\MVS Data\Helmets\MandalorianHelmet.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Helmets\OpsCore_damage.rvmat","SausageCo\MVS Data\Helmets\MandalorianHelmet_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Helmets\OpsCore_damage.rvmat","SausageCo\MVS Data\Helmets\MandalorianHelmet_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Helmets\OpsCore_destruct.rvmat","SausageCo\MVS Data\Helmets\MandalorianHelmet_destruct.rvmat"}}
					};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.3;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.13;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.26;
					};
				};
			};
		};		
		class ClothingTypes
		{
			male="SausageCo\MVS Data\Helmets\Mandalorian_Helmet.p3d";
			female="SausageCo\MVS Data\Helmets\Mandalorian_Helmet.p3d";
		};
	};

	class MVS_WarriorHelmet_Tan: MVS_WarriorHelmet_Base
	{
		scope = 2;
		displayName = "MVS Warrior Helmet - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Helmet_co.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Visor_co.paa"
		};
	};
	class MVS_WarriorHelmet_OD: MVS_WarriorHelmet_Base
	{
		scope = 2;
		displayName = "MVS Warrior Helmet - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Helmet_co_OD.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Visor_co.paa"
		};
	};
	class MVS_WarriorHelmet_Black: MVS_WarriorHelmet_Base
	{
		scope = 2;
		displayName = "MVS Warrior Helmet - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Helmet_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Visor_co.paa"
		};
	};
	class MVS_WarriorHelmet_ERDL: MVS_WarriorHelmet_Base
	{
		scope = 2;
		displayName = "MVS Warrior Helmet - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Helmet_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Visor_co.paa"
		};
	};
	class MVS_WarriorHelmet_Snow: MVS_WarriorHelmet_Base
	{
		scope = 2;
		displayName = "MVS Warrior Helmet - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Helmet_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Visor_co.paa"
		};
	};
	class MVS_WarriorHelmet_Multicam: MVS_WarriorHelmet_Base
	{
		scope = 2;
		displayName = "MVS Warrior Helmet - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Helmet_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Visor_co.paa"
		};
	};
	class MVS_WarriorHelmet_Multicam_Tropic: MVS_WarriorHelmet_Base
	{
		scope = 2;
		displayName = "MVS Warrior Helmet - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Helmet_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Visor_co.paa"
		};
	};
	class MVS_WarriorHelmet_Multicam_Black: MVS_WarriorHelmet_Base
	{
		scope = 2;
		displayName = "MVS Warrior Helmet - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\OpsCore_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Helmet_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\Mandalorian_Visor_co.paa"
		};
	};
	class Pakol_ColorBase: Clothing
	{
		displayName = "Pakol";
		descriptionShort = "Pakol, popularly known as the Chitrali cap, is a soft round-topped men's hat, typically of wool and found in any of a variety of earthy colors.";
		model = "\SausageCo\MVS Data\Helmets\pakol_g.p3d";
		attachments[]={"MVS_Comtacs"};
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 110;
		itemSize[] = {3,2};
		absorbency = 0.8;
		heatIsolation = 0.25;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_baseballcap"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\Helmets\acr_equip2.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\Helmets\acr_equip2.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\Helmets\acr_equip2.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\Helmets\acr_equip2_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\Helmets\acr_equip2_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\Helmets\acr_equip2_destruct.rvmat"}}
                    };
				};
			};
		};
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Helmets\pakol.p3d";
			female = "\SausageCo\MVS Data\Helmets\pakol.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class MVS_Pakol_brown: Pakol_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\acr_equip2_co.paa",
			"\SausageCo\MVS Data\Helmets\acr_equip2_co.paa",
			"\SausageCo\MVS Data\Helmets\acr_equip2_co.paa"
		};
	};
	class MVS_Pack_Base: MountainBag_ColorBase
	{
		scope = 0;
		displayName = "MVS Combat Pack";
		descriptionShort = "The MVS Combat Pack - rugged, lightweight, and versatile.";
		model = "\SausageCo\MVS Data\Pack\MVS_pack_g.p3d";
		inventorySlot[] = {"Back","MVS_pack"};
		attachments[] = {"Shoulder","modular_pouch_9","Chemlight","WalkieTalkie","patch_02"};
		rotationFlags=16;
		quickBarBonus = 2;
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\pack_co.paa",
			"\SausageCo\MVS Data\Pack\pack_co.paa",
			"\SausageCo\MVS Data\Pack\pack_co.paa"
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Pack\pack.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Pack\pack.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Pack\pack.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Pack\pack_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Pack\pack_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Pack\pack_destruct.rvmat"}}
					};
				};
			};
		};			
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Pack\MVS_pack.p3d";
			female = "\SausageCo\MVS Data\Pack\MVS_pack.p3d";
		};
	};
	class MVS_Assault_Pack_Tan: MVS_Pack_Base
	{
		scope = 2;
		displayName = "MVS Raider Pack - Tan";
		descriptionShort = "The MVS Raider's Pack - a larger pack with additional storage. Can attach MVS admin or medical pouches, Raid pouches for additional tool storage, grenades, a rifle, and Identifier Patch.";
		model = "\SausageCo\MVS Data\Pack\MVS_RaidPack_g.p3d";
		attachments[] = {"Shoulder","VestGrenadeA","VestGrenadeB","modular_pouch_9","modular_pouch_12","Chemlight","WalkieTalkie","patch_02"};
		itemSize[] = {5,7};
		itemsCargoSize[] = {8,10};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RaidPack_co.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co.paa"
			
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Pack\RaidPack.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Pack\RaidPack.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Pack\RaidPack.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Pack\RaidPack_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Pack\RaidPack_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Pack\RaidPack_destruct.rvmat"}}
					};
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Pack\MVS_RaidPack.p3d";
			female = "\SausageCo\MVS Data\Pack\MVS_RaidPack.p3d";
		};
	};
	class MVS_Assault_Pack_OD: MVS_Assault_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Raider Pack - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RaidPack_co_OD.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_OD.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_OD.paa"
			
		};
	};
	class MVS_Assault_Pack_ERDL: MVS_Assault_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Raider Pack - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RaidPack_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_ERDL.paa"
			
		};
	};
	class MVS_Assault_Pack_Black: MVS_Assault_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Raider Pack - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RaidPack_co_Black.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_Black.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_Black.paa"
			
		};
	};
	class MVS_Assault_Pack_Snow: MVS_Assault_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Raider Pack - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RaidPack_co_Snow.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_Snow.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_Snow.paa"
			
		};
	};
	class MVS_Assault_Pack_Multicam: MVS_Assault_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Raider Pack - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RaidPack_co_MC.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_MC.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_MC.paa"
			
		};
	};
	class MVS_Assault_Pack_Multicam_Tropic: MVS_Assault_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Raider Pack - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RaidPack_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_MC_Tropic.paa"
			
		};
	};
	class MVS_Assault_Pack_Multicam_Black: MVS_Assault_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Raider Pack - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RaidPack_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\RaidPack_co_MC_Black.paa"
			
		};
	};

	class MVS_Sling_Pack_Base: MVS_Pack_Base
	{
		scope = 0;
		displayName = "MVS Sling Pack";
		descriptionShort = "The MVS Sling Pack - a medium sized pack with atttachable storage. Can attach MVS admin or medical pouches, a rifle, and Identifier Patch.";
		model = "\SausageCo\MVS Data\Pack\MVS_SlingPack_g.p3d";
		attachments[] = {"Shoulder","modular_pouch_9","Chemlight","WalkieTalkie","patch_02"};
		itemSize[] = {5,7};
		itemsCargoSize[] = {8,10};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Sling_OD_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_OD_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_OD_co.paa"
			
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Pack\SlingPack.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Pack\SlingPack.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Pack\SlingPack.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Pack\SlingPack_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Pack\SlingPack_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Pack\SlingPack_destruct.rvmat"}}
					};
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Pack\MVS_SlingPack.p3d";
			female = "\SausageCo\MVS Data\Pack\MVS_SlingPack.p3d";
		};
	};
	class MVS_SlingPack_OD: MVS_Sling_Pack_Base
	{
		scope = 2;
		displayName = "MVS Sling Pack - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Sling_OD_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_OD_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_OD_co.paa"
			
		};
	};	
	class MVS_SlingPack_Tan: MVS_Sling_Pack_Base
	{
		scope = 2;
		displayName = "MVS Sling Pack - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Sling_Tan_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_Tan_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_Tan_co.paa"
			
		};
	};
	class MVS_SlingPack_Black: MVS_Sling_Pack_Base
	{
		scope = 2;
		displayName = "MVS Sling Pack - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Sling_Black_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_Black_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_Black_co.paa"
			
		};
	};
	class MVS_SlingPack_Multicam: MVS_Sling_Pack_Base
	{
		scope = 2;
		displayName = "MVS Sling Pack - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Sling_Multicam_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_Multicam_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_Multicam_co.paa"
			
		};
	};
	class MVS_SlingPack_Multicam_Black: MVS_Sling_Pack_Base
	{
		scope = 2;
		displayName = "MVS Sling Pack - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Sling_Multicam_Black_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_Multicam_Black_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_Multicam_Black_co.paa"
			
		};
	};
	class MVS_SlingPack_Multicam_Tropic: MVS_Sling_Pack_Base
	{
		scope = 2;
		displayName = "MVS Sling Pack - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Sling_Multicam_Tropic_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_Multicam_Tropic_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_Multicam_Tropic_co.paa"
			
		};
	};
	class MVS_SlingPack_ERDL: MVS_Sling_Pack_Base
	{
		scope = 2;
		displayName = "MVS Sling Pack - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Sling_ERDL_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_ERDL_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_ERDL_co.paa"
			
		};
	};
	class MVS_SlingPack_Snow: MVS_Sling_Pack_Base
	{
		scope = 2;
		displayName = "MVS Sling Pack - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Sling_Snow_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_Snow_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Sling_Snow_co.paa"
			
		};
	};

	class MVS_Compact_Base: MVS_Pack_Base
	{
		scope = 0;
		displayName = "MVS Compact Pack 1";
		descriptionShort = "The MVS Compact Pack - a smaller pack for light mobility. Can attach MVS admin or medical pouches, grenades, and Identifier Patch.";
		model = "\SausageCo\MVS Data\Pack\MVS_Compact_1_g.p3d";
		attachments[] = {"VestGrenadeB","modular_pouch_9","Chemlight","WalkieTalkie","patch_02"};
		itemSize[] = {5,7};
		itemsCargoSize[] = {5,10};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co.paa"
			
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Pack\MVS_Compact_1.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Pack\MVS_Compact_1.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Pack\MVS_Compact_1.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Pack\MVS_Compact_1_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Pack\MVS_Compact_1_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Pack\MVS_Compact_1_destruct.rvmat"}}
					};
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Pack\MVS_Compact_1.p3d";
			female = "\SausageCo\MVS Data\Pack\MVS_Compact_1.p3d";
		};
	};	
	
	class MVS_Compact_1_OD: MVS_Compact_Base
	{
		scope = 2;
		displayName = "MVS Compact Pack 1 - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co.paa"
		};
	};
	
	class MVS_Compact_1_Tan: MVS_Compact_Base
	{
		scope = 2;
		displayName = "MVS Compact Pack 1 - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_Tan.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_Tan.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_Tan.paa"
		};
	};
	
	class MVS_Compact_1_Black: MVS_Compact_Base
	{
		scope = 2;
		displayName = "MVS Compact Pack 1 - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_Black.paa"
		};
	};
	
	class MVS_Compact_1_ERDL: MVS_Compact_Base
	{
		scope = 2;
		displayName = "MVS Compact Pack 1 - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_ERDL.paa"
		};
	};
	
	class MVS_Compact_1_Snow: MVS_Compact_Base
	{
		scope = 2;
		displayName = "MVS Compact Pack 1 - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_Snow.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_Snow.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_Snow.paa"
		};
	};
	class MVS_Compact_1_Multicam: MVS_Compact_Base
	{
		scope = 2;
		displayName = "MVS Compact Pack 1 - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_MC.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_MC.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_MC.paa"
		};
	};
	class MVS_Compact_1_Multicam_Tropic: MVS_Compact_Base
	{
		scope = 2;
		displayName = "MVS Compact Pack 1 - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_MC_Tropic.paa"
		};
	};
	class MVS_Compact_1_Multicam_Black: MVS_Compact_Base
	{
		scope = 2;
		displayName = "MVS Compact Pack 1 - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_1_co_MC_Black.paa"
		};
	};
	
	class MVS_Compact_Base_2: MVS_Pack_Base
	{
		scope = 0;
		displayName = "MVS Compact Pack 2";
		descriptionShort = "The MVS Compact Pack - a smaller pack for light mobility. Can attach MVS admin or medical pouches, grenades, and Identifier Patch.";
		model = "\SausageCo\MVS Data\Pack\MVS_Compact_2_g.p3d";
		itemSize[] = {5,7};
		itemsCargoSize[] = {5,10};
		attachments[] = {"VestGrenadeA","VestGrenadeB","modular_pouch_9","modular_pouch_13","Chemlight","WalkieTalkie","patch_02"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Details_OD.paa"
			
		};
		hiddenSelectionsMaterials[] = 
		{
			"SausageCo\MVS Data\Pack\MVS_Compact_2.rvmat",
			"SausageCo\MVS Data\Pack\MVS_Compact_2_Detail.rvmat"
		};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Pack\MVS_Compact_2.rvmat","SausageCo\MVS Data\Pack\MVS_Compact_2_Detail.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Pack\MVS_Compact_2.rvmat","SausageCo\MVS Data\Pack\MVS_Compact_2_Detail.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Pack\MVS_Compact_2_damage.rvmat","SausageCo\MVS Data\Pack\MVS_Compact_2_Detail_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Pack\MVS_Compact_2_damage.rvmat","SausageCo\MVS Data\Pack\MVS_Compact_2_Detail_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Pack\MVS_Compact_2_destruct.rvmat","SausageCo\MVS Data\Pack\MVS_Compact_2_Detail_destruct.rvmat"}}
					};
				};
			};
		};			
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Pack\MVS_Compact_2.p3d";
			female = "\SausageCo\MVS Data\Pack\MVS_Compact_2.p3d";
		};
	};
	
	class MVS_Compact_2_OD: MVS_Compact_Base_2
	{
		scope = 2;
		displayName = "MVS Compact Pack 2 - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Details_OD.paa"
		};
	};
	
	class MVS_Compact_2_Tan: MVS_Compact_Base_2
	{
		scope = 2;
		displayName = "MVS Compact Pack 2 - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Tan.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Tan.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Tan.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Details_Tan.paa"
		};
	};
	
	class MVS_Compact_2_Black: MVS_Compact_Base_2
	{
		scope = 2;
		displayName = "MVS Compact Pack 2 - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Details_Black.paa"
		};
	};
	
	class MVS_Compact_2_ERDL: MVS_Compact_Base_2
	{
		scope = 2;
		displayName = "MVS Compact Pack 2 - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Details_OD.paa"
		};
	};
	
	class MVS_Compact_2_Snow: MVS_Compact_Base_2
	{
		scope = 2;
		displayName = "MVS Compact Pack 2 - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Snow.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Snow.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Snow.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Details_OD.paa"
		};
	};
	class MVS_Compact_2_Multicam: MVS_Compact_Base_2
	{
		scope = 2;
		displayName = "MVS Compact Pack 2 - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_MC.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_MC.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_MC.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Details_MC.paa"
		};
	};
	class MVS_Compact_2_Multicam_Tropic: MVS_Compact_Base_2
	{
		scope = 2;
		displayName = "MVS Compact Pack 2 - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Details_OD.paa"
		};
	};
	class MVS_Compact_2_Multicam_Black: MVS_Compact_Base_2
	{
		scope = 2;
		displayName = "MVS Compact Pack 2 - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Compact_2_co_Details_OD.paa"
		};
	};

	class MVS_Radio_Pack_Tan: MVS_Pack_Base
	{
		scope = 2;
		displayName = "MVS Raider Pack - Tan";
		descriptionShort = "The MVS Radio Pack - accepts MVS Admin and Medical Pouch, a Rifle, Identifier Patch, and the MVS Radio.";
		model = "\SausageCo\MVS Data\Pack\RadioPack_g.p3d";
		attachments[] = {"Shoulder","modular_pouch_9","RottensRadio","patch_02"};
		itemSize[] = {5,7};
		itemsCargoSize[] = {6,4};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RadioPack_co.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co.paa"
			
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Pack\RadioPack.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Pack\RadioPack.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Pack\RadioPack.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Pack\RadioPack_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Pack\RadioPack_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Pack\RadioPack_destruct.rvmat"}}
					};
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Pack\RadioPack.p3d";
			female = "\SausageCo\MVS Data\Pack\RadioPack.p3d";
		};
	};
	class MVS_Radio_Pack_OD: MVS_Radio_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Radio Pack - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RadioPack_co_OD.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_OD.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_OD.paa"
			
		};
	};
	class MVS_Radio_Pack_ERDL: MVS_Radio_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Radio Pack - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RadioPack_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_ERDL.paa"
			
		};
	};
	class MVS_Radio_Pack_Black: MVS_Radio_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Radio Pack - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RadioPack_co_Black.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_Black.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_Black.paa"
			
		};
	};
	class MVS_Radio_Pack_Snow: MVS_Radio_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Radio Pack - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RadioPack_co_Snow.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_Snow.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_Snow.paa"
			
		};
	};
	class MVS_Radio_Pack_Multicam: MVS_Radio_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Radio Pack - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RadioPack_co_MC.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_MC.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_MC.paa"
			
		};
	};
	class MVS_Radio_Pack_Multicam_Tropic: MVS_Radio_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Radio Pack - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RadioPack_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_MC_Tropic.paa"
			
		};
	};
	class MVS_Radio_Pack_Multicam_Black: MVS_Radio_Pack_Tan
	{
		scope = 2;
		displayName = "MVS Radio Pack - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\RadioPack_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\RadioPack_co_MC_Black.paa"
			
		};
	};
	
	class MVS_Radio: BaseRadio
	{
		scope = 2;
		displayName = "MVS Military Radio";
		descriptionShort = "This radio can attach to the MVS Radio Pack, allowing the user to communicate long distances. Range - 50K";
		model = "\SausageCo\MVS Data\Pack\RottensRadio.p3d";
		weight = 2000;
		inventorySlot[] = {"RottensRadio"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\radio_co.paa"
		};		
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Pack\radio.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Pack\radio.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Pack\radio.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Pack\radio_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Pack\radio_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Pack\radio_destruct.rvmat"}}
					};
				};
			};
		};		
	};
	
	class MVS_Rucksack_Base: MVS_Pack_Base
	{
		scope = 0;
		displayName = "MVS Combat Pack";
		descriptionShort = "The MVS Rucksack - a large pack designed to withstand the elements and heavy weight. A rifle can be attached, along with Identifier Patch";
		model = "\SausageCo\MVS Data\Pack\MVS_Rucksack_g.p3d";
		inventorySlot[] = {"Back","MVS_pack"};
		attachments[] = {"Shoulder","Chemlight","WalkieTalkie","patch_02"};
		rotationFlags=16;
		itemSize[]={7,8};
		itemsCargoSize[]={10,12};
		weight=1600;
		quickBarBonus = 2;
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co.paa"
		};
		hiddenSelectionsMaterials[] = {"SausageCo\MVS Data\Pack\Rucksack.rvmat"};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = 	
					{					
						{1.0,{"SausageCo\MVS Data\Pack\Rucksack.rvmat"}},
						{0.7,{"SausageCo\MVS Data\Pack\Rucksack.rvmat"}},
						{0.5,{"SausageCo\MVS Data\Pack\Rucksack_damage.rvmat"}},
						{0.3,{"SausageCo\MVS Data\Pack\Rucksack_damage.rvmat"}},
						{0.0,{"SausageCo\MVS Data\Pack\Rucksack_destruct.rvmat"}}
					};
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Pack\MVS_Rucksack.p3d";
			female = "\SausageCo\MVS Data\Pack\MVS_Rucksack.p3d";
		};
	};
	
	class MVS_Rucksack_OD: MVS_Rucksack_Base
	{
		scope = 2;
		displayName = "MVS Rucksack - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co.paa"
		};
	};	
	class MVS_Rucksack_ERDL: MVS_Rucksack_Base
	{
		scope = 2;
		displayName = "MVS Rucksack - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_ERDL.paa"
		};
	};

	class MVS_Rucksack_Tan: MVS_Rucksack_Base
	{
		scope = 2;
		displayName = "MVS Rucksack - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_Tan.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_Tan.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_Tan.paa"
		};
	};
	
	class MVS_Rucksack_Black: MVS_Rucksack_Base
	{
		scope = 2;
		displayName = "MVS Rucksack - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_Black.paa"
		};
	};
	class MVS_Rucksack_Snow: MVS_Rucksack_Base
	{
		scope = 2;
		displayName = "MVS Rucksack - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_Snow.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_Snow.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_Snow.paa"
		};
	};
	class MVS_Rucksack_Multicam: MVS_Rucksack_Base
	{
		scope = 2;
		displayName = "MVS Rucksack - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_MC.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_MC.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_MC.paa"
		};
	};
	class MVS_Rucksack_Multicam_Tropic: MVS_Rucksack_Base
	{
		scope = 2;
		displayName = "MVS Rucksack - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_MC_Tropic.paa"
		};
	};
	class MVS_Rucksack_Multicam_Black: MVS_Rucksack_Base
	{
		scope = 2;
		displayName = "MVS Rucksack - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\MVS_Rucksack_co_MC_Black.paa"
		};
	};

	
	class MVS_Pack_OD: MVS_Pack_Base
	{
		scope = 2;
		displayName = "MVS Combat Pack - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\pack_co.paa",
			"\SausageCo\MVS Data\Pack\pack_co.paa",
			"\SausageCo\MVS Data\Pack\pack_co.paa"
		};
	};	
	class MVS_Pack_ERDL: MVS_Pack_Base
	{
		scope = 2;
		displayName = "MVS Combat Pack - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\pack_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\pack_co_ERDL.paa",
			"\SausageCo\MVS Data\Pack\pack_co_ERDL.paa"
		};
	};

	class MVS_Pack_Tan: MVS_Pack_Base
	{
		scope = 2;
		displayName = "MVS Combat Pack - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\pack_co_Tan.paa",
			"\SausageCo\MVS Data\Pack\pack_co_Tan.paa",
			"\SausageCo\MVS Data\Pack\pack_co_Tan.paa"
		};
	};
	
	class MVS_Pack_Black: MVS_Pack_Base
	{
		scope = 2;
		displayName = "MVS Combat Pack - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\pack_co_Black.paa",
			"\SausageCo\MVS Data\Pack\pack_co_Black.paa",
			"\SausageCo\MVS Data\Pack\pack_co_Black.paa"
		};
	};
	class MVS_Pack_Snow: MVS_Pack_Base
	{
		scope = 2;
		displayName = "MVS Combat Pack - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\pack_co_snow.paa",
			"\SausageCo\MVS Data\Pack\pack_co_snow.paa",
			"\SausageCo\MVS Data\Pack\pack_co_snow.paa"
		};
	};
	class MVS_Pack_Multicam: MVS_Pack_Base
	{
		scope = 2;
		displayName = "MVS Combat Pack - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\pack_co_MC.paa",
			"\SausageCo\MVS Data\Pack\pack_co_MC.paa",
			"\SausageCo\MVS Data\Pack\pack_co_MC.paa"
		};
	};
	class MVS_Pack_Multicam_Tropic: MVS_Pack_Base
	{
		scope = 2;
		displayName = "MVS Combat Pack - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\pack_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\pack_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Pack\pack_co_MC_Tropic.paa"
		};
	};
	class MVS_Pack_Multicam_Black: MVS_Pack_Base
	{
		scope = 2;
		displayName = "MVS Combat Pack - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Pack\pack_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\pack_co_MC_Black.paa",
			"\SausageCo\MVS Data\Pack\pack_co_MC_Black.paa"
		};
	};
	

	class Modular_Belt_Base: Clothing
	{
		scope = 0;
		displayName = "MVS Combat Belt";
		descriptionShort = "The MVS Combat Belt, a rugged piece of equipment with plenty of molle space for pouches and warfighter tools";
		model = "\SausageCo\MVS Data\Belt\ModularBeltSystem_g.p3d";
		attachments[] = {"Chemlight","modular_pouch_2","VestPouch","Belt_Back","modular_pouch_10","Belt_Right","WalkieTalkie"};
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot[] = {"Hips","MVS_belt"};
		itemInfo[] = {"Clothing","Hips"};
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		itemSize[] = {4,2};
		weight = 20;
		allowOwnedCargoManipulation=1;
		lootCategory = "Crafted";
		quickBarBonus = 2;
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\belt_co.paa",
			"\SausageCo\MVS Data\Belt\belt_co.paa",
			"\SausageCo\MVS Data\Belt\belt_co.paa"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\Belt\belt.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\Belt\belt.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\Belt\belt.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\Belt\belt_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\Belt\belt_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\Belt\belt_destruct.rvmat"}}
                    };
				};
			};
		};
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Belt\ModularBeltSystem.p3d";
			female = "\SausageCo\MVS Data\Belt\ModularBeltSystem.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	
	class MVS_Belt_OD: Modular_Belt_Base
	{
		scope = 2;
		displayName = "MVS Combat Belt - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\belt_co.paa",
			"\SausageCo\MVS Data\Belt\belt_co.paa",
			"\SausageCo\MVS Data\Belt\belt_co.paa"
		};
	};
	class MVS_Belt_ERDL: Modular_Belt_Base
	{
		scope = 2;
		displayName = "MVS Combat Belt - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\belt_co_ERDL.paa",
			"\SausageCo\MVS Data\Belt\belt_co_ERDL.paa",
			"\SausageCo\MVS Data\Belt\belt_co_ERDL.paa"
		};
	};
	class MVS_Belt_Tan: Modular_Belt_Base
	{
		scope = 2;
		displayName = "MVS Combat Belt - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\belt_co_Tan.paa",
			"\SausageCo\MVS Data\Belt\belt_co_Tan.paa",
			"\SausageCo\MVS Data\Belt\belt_co_Tan.paa"
		};
	};
	class MVS_Belt_Black: Modular_Belt_Base
	{
		scope = 2;
		displayName = "MVS Combat Belt - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\belt_co_Black.paa",
			"\SausageCo\MVS Data\Belt\belt_co_Black.paa",
			"\SausageCo\MVS Data\Belt\belt_co_Black.paa"
		};
	};
	class MVS_Belt_Snow: Modular_Belt_Base
	{
		scope = 2;
		displayName = "MVS Combat Belt - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\belt_co_snow.paa",
			"\SausageCo\MVS Data\Belt\belt_co_snow.paa",
			"\SausageCo\MVS Data\Belt\belt_co_snow.paa"
		};
	};
	class MVS_Belt_Multicam: Modular_Belt_Base
	{
		scope = 2;
		displayName = "MVS Combat Belt - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\belt_co_MC.paa",
			"\SausageCo\MVS Data\Belt\belt_co_MC.paa",
			"\SausageCo\MVS Data\Belt\belt_co_MC.paa"
		};
	};
	class MVS_Belt_Multicam_Black: Modular_Belt_Base
	{
		scope = 2;
		displayName = "MVS Combat Belt - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\belt_co_MC_Black.paa",
			"\SausageCo\MVS Data\Belt\belt_co_MC_Black.paa",
			"\SausageCo\MVS Data\Belt\belt_co_MC_Black.paa"
		};
	};
	class MVS_Belt_Multicam_Tropic: Modular_Belt_Base
	{
		scope = 2;
		displayName = "MVS Combat Belt - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\belt_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Belt\belt_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Belt\belt_co_MC_Tropic.paa"
		};
	};
	
	class PlateCarrierHolster;
	class MVS_Holster_OD: PlateCarrierHolster
	{
		displayName = "MVS Holster - OD";
		descriptionShort = "MVS Holster - OD";
		scope=2;
		hiddenSelections[] = {"camoGround","zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\holster_co.paa",
			"\SausageCo\MVS Data\Belt\holster_co.paa"
		};
	};
	class MVS_Holster_ERDL: PlateCarrierHolster
	{
		displayName = "MVS Holster - ERDL";
		descriptionShort = "MVS Holster - ERDL";
		scope=2;
		hiddenSelections[] = {"camoGround","zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\holster_co_ERDL.paa",
			"\SausageCo\MVS Data\Belt\holster_co_ERDL.paa"
		};
	};
	class MVS_Holster_Tan: PlateCarrierHolster
	{
		displayName = "MVS Holster - Tan";
		descriptionShort = "MVS Holster - Tan";
		scope=2;
		hiddenSelections[] = {"camoGround","zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\holster_co_Tan.paa",
			"\SausageCo\MVS Data\Belt\holster_co_Tan.paa"
		};
	};
	class MVS_Holster_Black: PlateCarrierHolster
	{
		displayName = "MVS Holster - Black";
		descriptionShort = "MVS Holster - Black";
		scope=2;
		hiddenSelections[] = {"camoGround","zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\holster_co_Black.paa",
			"\SausageCo\MVS Data\Belt\holster_co_Black.paa"
		};
	};
	class MVS_Holster_Snow: PlateCarrierHolster
	{
		displayName = "MVS Holster - Snow";
		descriptionShort = "MVS Holster - Snow";
		scope=2;
		hiddenSelections[] = {"camoGround","zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\holster_co_snow.paa",
			"\SausageCo\MVS Data\Belt\holster_co_snow.paa"
		};
	};
	class MVS_Holster_Multicam: PlateCarrierHolster
	{
		displayName = "MVS Holster - Multicam";
		descriptionShort = "MVS Holster - Multicam";
		scope=2;
		hiddenSelections[] = {"camoGround","zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\holster_co_MC.paa",
			"\SausageCo\MVS Data\Belt\holster_co_MC.paa"
		};
	};
	class MVS_Holster_Multicam_Black: PlateCarrierHolster
	{
		displayName = "MVS Holster - Multicam Black";
		descriptionShort = "MVS Holster - Multicam Black";
		scope=2;
		hiddenSelections[] = {"camoGround","zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\holster_co_MC_Black.paa",
			"\SausageCo\MVS Data\Belt\holster_co_MC_Black.paa"
		};
	};
	class MVS_Holster_Multicam_Tropic: PlateCarrierHolster
	{
		displayName = "MVS Holster - Multicam Tropic";
		descriptionShort = "MVS Holster - Multicam Tropic";
		scope=2;
		hiddenSelections[] = {"camoGround","zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\holster_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Belt\holster_co_MC_Tropic.paa"
		};
	};

	class NylonKnifeSheath;
	class MVS_Sheath_Base: NylonKnifeSheath
	{
		scope = 0;
		displayName = "MVS Sheath";
		descriptionShort = "$STR_cfgvehicles_knifesheath1";
		model = "\SausageCo\MVS Data\Belt\knife_sheath.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\sheath_co.paa"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\Belt\sheath.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\Belt\sheath.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\Belt\sheath.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\Belt\sheath_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\Belt\sheath_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\Belt\sheath_destruct.rvmat"}}
                    };
				};
			};
		};		
	};
	class MVS_Sheath_OD: MVS_Sheath_Base
	{
		displayName = "MVS Sheath - OD";
		descriptionShort = "MVS Sheath - OD";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\sheath_co.paa"
		};
	};
	class MVS_Sheath_ERDL: MVS_Sheath_Base
	{
		displayName = "MVS Sheath - ERDL";
		descriptionShort = "MVS Sheath - ERDL";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\sheath_co_ERDL.paa"
		};
	};
	class MVS_Sheath_Tan: MVS_Sheath_Base
	{
		displayName = "MVS Sheath - Tan";
		descriptionShort = "MVS Sheath - Tan";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\sheath_co_Tan.paa"
		};

	};
	class MVS_Sheath_Black: MVS_Sheath_Base
	{
		displayName = "MVS Sheath - Black";
		descriptionShort = "MVS Sheath - Black";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\sheath_co_Black.paa"
		};

	};
	class MVS_Sheath_Snow: MVS_Sheath_Base
	{
		displayName = "MVS Sheath - Snow";
		descriptionShort = "MVS Sheath - Snow";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\sheath_co_snow.paa"
		};

	};
	class MVS_Sheath_Multicam: MVS_Sheath_Base
	{
		displayName = "MVS Sheath - Multicam";
		descriptionShort = "MVS Sheath - Multicam";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\sheath_co_MC.paa"
		};

	};
	class MVS_Sheath_Multicam_Tropic: MVS_Sheath_Base
	{
		displayName = "MVS Sheath - Multicam Tropic";
		descriptionShort = "MVS Sheath - Multicam Tropic";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\sheath_co_MC_Tropic.paa"
		};

	};
	class MVS_Sheath_Multicam_Black: MVS_Sheath_Base
	{
		displayName = "MVS Sheath - Multicam Black";
		descriptionShort = "MVS Sheath - Multicam Black";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Belt\sheath_co_MC_Black.paa"
		};

	};
	class Inventory_Base;
	class Lockpick: Inventory_Base
	{
		inventorySlot[] = {"MVS_Lockpick"};
	};
	class Screwdriver: Inventory_Base
	{
		inventorySlot[] = {"Screwdriver","MassScrewDriver","Screwdriver1","Screwdriver2"};
	};
	class Pliers: Inventory_Base
	{
		inventorySlot[] = {"Pliers","Pliers1"};
	};
	class Morphine: Container_Base
	{
		inventorySlot[] = {"morphine","epinephrine"};
	};
	class Battery9V: Inventory_Base
	{
		inventorySlot[] = {"BatteryD","MVSBattery1","MVSBattery2"};
	};
	class Epinephrine: Container_Base
	{
		inventorySlot[] = {"epinephrine","morphine"};
	};
	class BandageDressing: Inventory_Base
	{
		inventorySlot[] = {"MedicalBandage"};
	};
	
	class WoodenCrate;
	class ArmorRack_Kit: WoodenCrate
	{
		scope = 2;
		displayName = "MVS Armor Rack Kit";
		descriptionShort = "Armor Rack Kit designed to display Modular Vest System (MVS) components";
		model = "\SausageCo\MVS Data\ArmorRack\kit_base.p3d";
		itemSize[] = {5,3};
		carveNavmesh = 1;
		canBeDigged = 0;
		simulation = "inventoryItem";
		physLayer = "item_small";
		SingleUseActions[] = {527};
		ContinuousActions[] = {231};
		rotationFlags = 2;
		InteractActions[] = {};
		weight = 300;
		itemBehaviour = 2;
		class Cargo{};
	};
	class ArmorRack_Base: Container_Base
	{
		scope = 0;
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100000000000;
					healthLevels[] = {{1,{"DZ\gear\camping\data\spotlight.rvmat"}},{0.7,{"DZ\gear\camping\data\spotlight.rvmat"}},{0.5,{"DZ\gear\camping\data\spotlight_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\spotlight_damage.rvmat"}},{0,{"DZ\gear\camping\data\spotlight_destruct.rvmat"}}};
				};
			};
		};
	};
	class Armor_Rack: ArmorRack_Base
	{
		scope = 2;
		displayName = "MVS Armor Rack Kit";
		descriptionShort = "Armor Rack Kit designed to display Modular Vest System (MVS) components";
		model = "\SausageCo\MVS Data\ArmorRack\ArmorRack.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		handheld = "true";
		carveNavmesh = 1;
		canBeDigged = 0;
		weight = 50000;
		itemSize[] = {10,10};
		physLayer = "item_large";
		rotationFlags = 0;
		class Cargo
		{
			itemsCargoSize[] = {10,2};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		attachments[] = {"MVS_helmet","MVS_mask","MVS_vest","MVS_belt","MVS_pack","Shoulder"};
		class GUIInventoryAttachmentsProps
		{
			class MVSHelmet
			{
				name = "MVS Helmet";
				description = "";
				attachmentSlots[] = {"MVS_helmet"};
				icon = "missing";
			};
			class MVSMASK
			{
				name = "MVS S10 Respirator";
				description = "";
				attachmentSlots[] = {"MVS_mask"};
				icon = "missing";
			};			
			class MVSRig
			{
				name = "MVS Rig";
				description = "";
				attachmentSlots[] = {"MVS_vest"};
				icon = "missing";
			};
			class MVSBelt
			{
				name = "MVS Belt";
				description = "";
				attachmentSlots[] = {"MVS_belt"};
				icon = "missing";
			};
			class MVSPack
			{
				name = "MVS Pack";
				description = "";
				attachmentSlots[] = {"MVS_pack"};
				icon = "missing";
			};
			class MVSWeapon
			{
				name = "Rifle";
				description = "";
				attachmentSlots[] = {"Shoulder"};
				icon = "missing";
			};
		};
	};

	class ArmorRack_Holo: Armor_Rack
	{
		scope = 0;
	};
	
	class MVS_GasMaskBase: GP5GasMask{};
	
	class MVS_S10Respirator: MVS_GasMaskBase
	{
		scope = 0;
		displayName = "S10 Respirator";
		descriptionShort = "The S10 NBC Respirator is a military gas mask that was formerly used within all branches of the British Armed Forces. Following the mask's replacement by the General Service Respirator in 2011, the S10 is now widely available to the public on the army surplus market.";
		inventorySlot[] = {"Mask","MVS_mask"};
		itemSize[] = {2,3};
		model = "\SausageCo\MVS Data\s10\s10_g.p3d";
		attachments[]={"GasMaskFilter","MVS_Comtacs"};
		headSelectionsToHide[] = {"Clipping_Gasmask","Clipping_Balaclava_3holes"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","zbytek"};
		hiddenSelectionsTextures[] = {"\SausageCo\MVS Data\s10\s10_co.paa","\SausageCo\MVS Data\s10\s10_co.paa","\SausageCo\MVS Data\s10\s10_co.paa","\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa"};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\s10\s10.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\s10\s10.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\s10\s10.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\s10\s10_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\s10\s10_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\s10\s10_destruct.rvmat"}}
                    };
				};
			};
		};			
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\s10\s10.p3d";
			female = "\SausageCo\MVS Data\s10\s10_f.p3d";
		};
	};
	class MVS_S10Respirator_FS: MVS_S10Respirator
	{
		scope = 2;
		displayName = "S10 Respirator - The 4th Survivor";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\s10_co_FS.paa",
			"\SausageCo\MVS Data\s10\s10_co_FS.paa",
			"\SausageCo\MVS Data\s10\s10_co_FS.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Black.paa"
		};
	};
	class MVS_S10Respirator_OD: MVS_S10Respirator
	{
		scope = 2;
		displayName = "S10 Respirator - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\s10_co_OD.paa",
			"\SausageCo\MVS Data\s10\s10_co_OD.paa",
			"\SausageCo\MVS Data\s10\s10_co_OD.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa"
		};
	};
	class MVS_S10Respirator_Tan: MVS_S10Respirator
	{
		scope = 2;
		displayName = "S10 Respirator - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\s10_co_Tan.paa",
			"\SausageCo\MVS Data\s10\s10_co_Tan.paa",
			"\SausageCo\MVS Data\s10\s10_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Tan.paa"
		};
	};
	class MVS_S10Respirator_Black: MVS_S10Respirator
	{
		scope = 2;
		displayName = "S10 Respirator - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\s10_co.paa",
			"\SausageCo\MVS Data\s10\s10_co.paa",
			"\SausageCo\MVS Data\s10\s10_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_black.paa"
		};
	};
	class MVS_S10Respirator_Snow: MVS_S10Respirator
	{
		scope = 2;
		displayName = "S10 Respirator - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\s10_co_Snow.paa",
			"\SausageCo\MVS Data\s10\s10_co_Snow.paa",
			"\SausageCo\MVS Data\s10\s10_co_Snow.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_snow.paa"
		};
	};
	
	class MVS_PMK2Respirator: MVS_GasMaskBase
	{
		scope = 0;
		displayName = "PMK2 Respirator";
		descriptionShort = "The PMK gas mask represents a family of gas masks used by the Soviet Armed Forces, and later by the Armed Forces of the Russian Federation.";
		model = "\SausageCo\MVS Data\s10\MVS_PMK2_g.p3d";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","zbytek","filter","lens"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_PMK2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_Filter_co.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_ca.paa"			
			
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat",
			"SausageCo\MVS Data\s10\MVS_PMK2.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat","SausageCo\MVS Data\s10\MVS_PMK2.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat","SausageCo\MVS Data\s10\MVS_PMK2.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\s10\MVS_Balaclava2_damage.rvmat","SausageCo\MVS Data\s10\MVS_PMK2_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\s10\MVS_Balaclava2_damage.rvmat","SausageCo\MVS Data\s10\MVS_PMK2_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\s10\MVS_Balaclava2_destruct.rvmat","SausageCo\MVS Data\s10\MVS_PMK2_destruct.rvmat"}}
                    };
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\s10\MVS_PMK2.p3d";
			female = "\SausageCo\MVS Data\s10\MVS_PMK2_f.p3d";
		};
	};
	class MVS_PMK2Respirator_Black: MVS_PMK2Respirator
	{
		scope = 2;
		displayName = "PMK-2 Respirator - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_PMK2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_black.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_Filter_co.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_ca.paa"	
		};
	};
	class MVS_PMK2Respirator_Tan: MVS_PMK2Respirator
	{
		scope = 2;
		displayName = "PMK-2 Respirator - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_PMK2_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_Filter_co.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_ca.paa"	
		};
	};
	class MVS_PMK2Respirator_OD: MVS_PMK2Respirator
	{
		scope = 2;
		displayName = "PMK-2 Respirator - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_PMK2_co_OD.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_co_OD.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_co_OD.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_Filter_co.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_ca.paa"	
		};
	};
	
	class MVS_PMK2Respirator_Snow: MVS_PMK2Respirator
	{
		scope = 2;
		displayName = "PMK-2 Respirator - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_PMK2_co_Snow.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_co_Snow.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_co_Snow.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_Filter_co.paa",
			"\SausageCo\MVS Data\s10\MVS_PMK2_ca.paa"	
		};
	};
	
	class MVS_M50Respirator: MVS_GasMaskBase
	{
		scope = 0;
		displayName = "M50 Respirator";
		descriptionShort = "The M50 series protective mask consisting of the M50 and M51 variants, officially known as the Joint Service General Protective Mask (JSGPM) is a lightweight, protective mask system consisting of the mask, a mask carrier, and additional accessories";
		model = "\SausageCo\MVS Data\s10\MVS_M50_g.p3d";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","zbytek"};
		hiddenSelectionsTextures[] = {"\SausageCo\MVS Data\s10\MVS_M50_co.paa","\SausageCo\MVS Data\s10\MVS_M50_co.paa","\SausageCo\MVS Data\s10\MVS_M50_co.paa","\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa"};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat",
			"SausageCo\MVS Data\s10\MVS_M50.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat","SausageCo\MVS Data\s10\MVS_M50.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat","SausageCo\MVS Data\s10\MVS_M50.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\s10\MVS_Balaclava2_damage.rvmat","SausageCo\MVS Data\s10\MVS_M50_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\s10\MVS_Balaclava2_damage.rvmat","SausageCo\MVS Data\s10\MVS_M50_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\s10\MVS_Balaclava2_destruct.rvmat","SausageCo\MVS Data\s10\MVS_M50_destruct.rvmat"}}
                    };
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\s10\MVS_M50.p3d";
			female = "\SausageCo\MVS Data\s10\MVS_M50_f.p3d";
		};
	};
	class MVS_M50Respirator_OD: MVS_M50Respirator
	{
		scope = 2;
		displayName = "M50 Respirator - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_M50_co_OD.paa",
			"\SausageCo\MVS Data\s10\MVS_M50_co_OD.paa",
			"\SausageCo\MVS Data\s10\MVS_M50_co_OD.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa"
		};
	};
	class MVS_M50Respirator_Tan: MVS_M50Respirator
	{
		scope = 2;
		displayName = "M50 Respirator - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_M50_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_M50_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_M50_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Tan.paa"
		};
	};
	class MVS_M50Respirator_Black: MVS_M50Respirator
	{
		scope = 2;
		displayName = "M50 Respirator - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_M50_co.paa",
			"\SausageCo\MVS Data\s10\MVS_M50_co.paa",
			"\SausageCo\MVS Data\s10\MVS_M50_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_black.paa"
		};
	};
	class MVS_M50Respirator_Snow: MVS_M50Respirator
	{
		scope = 2;
		displayName = "M50 Respirator - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_M50_co_Snow.paa",
			"\SausageCo\MVS Data\s10\MVS_M50_co_Snow.paa",
			"\SausageCo\MVS Data\s10\MVS_M50_co_Snow.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_snow.paa"
		};
	};
	
	class MVS_Balaclava: BalaclavaMask_ColorBase
	{
		scope = 0;
		displayName = "MVS Balaclava";
		descriptionShort = "A mask used for concealing one's identity... spooky right? Comtacs can be attached";
		inventorySlot[] = {"Mask"};
		itemSize[] = {3,2};
		rotationFlags=0;
		model = "\SausageCo\MVS Data\s10\MVS_Balaclava_g.p3d";
		attachments[] = {"MVS_Comtacs"};
		headSelectionsToHide[] = {"Clipping_Gasmask","Clipping_Balaclava_3holes"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","mask"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Wraith.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Wraith.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Wraith.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava_mask_co.paa"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat",
			"SausageCo\MVS Data\s10\MVS_Balaclava_mask.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat","SausageCo\MVS Data\s10\MVS_Balaclava_mask.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat","SausageCo\MVS Data\s10\MVS_Balaclava_mask.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\s10\MVS_Balaclava2_damage.rvmat","SausageCo\MVS Data\s10\MVS_Balaclava_mask_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\s10\MVS_Balaclava2_damage.rvmat","SausageCo\MVS Data\s10\MVS_Balaclava_mask_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\s10\MVS_Balaclava2_destruct.rvmat","SausageCo\MVS Data\s10\MVS_Balaclava_mask_destruct.rvmat"}}
                    };
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\s10\MVS_Balaclava.p3d";
			female = "\SausageCo\MVS Data\s10\MVS_Balaclava_f.p3d";
		};
	};
	
	class MVS_Balaclava_Wraith: MVS_Balaclava
	{
		scope = 2;
		displayName = "MVS Wraith Mask";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Wraith.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Wraith.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Wraith.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava_mask_co.paa"
		};
	};
	
	class MVS_Balaclava2: BalaclavaMask_ColorBase
	{
		scope = 0;
		displayName = "MVS Balaclava 2";
		descriptionShort = "A mask used for concealing one's identity... spooky right? Comtacs can be attached";
		inventorySlot[] = {"Mask"};
		itemSize[] = {3,2};
		rotationFlags=0;
		model = "\SausageCo\MVS Data\s10\MVS_Balaclava2_g.p3d";
		attachments[] = {"MVS_Comtacs"};
		headSelectionsToHide[] = {"Clipping_Gasmask","Clipping_Balaclava_3holes"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\s10\MVS_Balaclava2_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\s10\MVS_Balaclava2_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\s10\MVS_Balaclava2_destruct.rvmat"}}
                    };
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\s10\MVS_Balaclava2.p3d";
			female = "\SausageCo\MVS Data\s10\MVS_Balaclava2_f.p3d";
		};
	};
	
	class MVS_Balaclava_OD: MVS_Balaclava2
	{
		scope = 2;
		displayName = "MVS Balaclava - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa"
		};
	};
	class MVS_Balaclava_Tan: MVS_Balaclava2
	{
		scope = 2;
		displayName = "MVS Balaclava - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Tan.paa"
		};
	};
	class MVS_Balaclava_Black: MVS_Balaclava2
	{
		scope = 2;
		displayName = "MVS Balaclava - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Black.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Black.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Black.paa"
		};
	};
	class MVS_Balaclava_Snow: MVS_Balaclava2
	{
		scope = 2;
		displayName = "MVS Balaclava - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Snow.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Snow.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Snow.paa"
		};
	};
	
	class MVS_Balaclava3: BalaclavaMask_ColorBase
	{
		scope = 0;
		displayName = "MVS Balaclava 3";
		descriptionShort = "A mask used for concealing one's identity... spooky right?";
		inventorySlot[] = {"Mask"};
		itemSize[] = {3,2};
		rotationFlags=0;
		model = "\SausageCo\MVS Data\s10\MVS_Balaclava3_g.p3d";
		attachments[] = {"MVS_Comtacs"};
		headSelectionsToHide[] = {"Clipping_Gasmask"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\s10\MVS_Balaclava2.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\s10\MVS_Balaclava2_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\s10\MVS_Balaclava2_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\s10\MVS_Balaclava2_destruct.rvmat"}}
                    };
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\s10\MVS_Balaclava3.p3d";
			female = "\SausageCo\MVS Data\s10\MVS_Balaclava3_f.p3d";
		};
	};
	
	class MVS_Facemask_OD: MVS_Balaclava3
	{
		scope = 2;
		displayName = "MVS Facemask - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co.paa"
		};
	};
	class MVS_Facemask_Tan: MVS_Balaclava3
	{
		scope = 2;
		displayName = "MVS Facemask - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Tan.paa"
		};
	};
	class MVS_Facemask_Black: MVS_Balaclava3
	{
		scope = 2;
		displayName = "MVS Facemask - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Black.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Black.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Black.paa"
		};
	};
	class MVS_Facemask_Snow: MVS_Balaclava3
	{
		scope = 2;
		displayName = "MVS Facemask - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Snow.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Snow.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava2_co_Snow.paa"
		};
	};
	
	class MVS_Shroud_Base: BalaclavaMask_ColorBase
	{
		scope = 0;
		displayName = "MVS Shroud";
		descriptionShort = "A thin veil of netting used to break up outlines in the brush.";
		inventorySlot[] = {"Headgear"};
		itemSize[] = {3,2};
		rotationFlags=0;
		model = "\SausageCo\MVS Data\s10\MVS_Shroud_g.p3d";
		headSelectionsToHide[] = {"Clipping_Gasmask","Clipping_Balaclava_3holes"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Shroud_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Shroud_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Shroud_co.paa"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\s10\MVS_Shroud.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\s10\MVS_Shroud.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\s10\MVS_Shroud.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\s10\MVS_Shroud_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\s10\MVS_Shroud_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\s10\MVS_Shroud_destruct.rvmat"}}
                    };
				};
			};
		};		
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\s10\MVS_Shroud.p3d";
			female = "\SausageCo\MVS Data\s10\MVS_Shroud.p3d";
		};
		class AnimationSources
		{
			class CamoNet
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
	};
	
	class MVS_Shroud_OD: MVS_Shroud_Base
	{
		scope = 2;
		displayName = "MVS Shroud - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Shroud_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Shroud_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Shroud_co.paa"
		};
	};

	class MVS_Shroud_Tan: MVS_Shroud_Base
	{
		scope = 2;
		displayName = "MVS Shroud - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Shroud_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_Shroud_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_Shroud_co_Tan.paa"
		};
	};
	
	class MVS_Shroud_Black: MVS_Shroud_Base
	{
		scope = 2;
		displayName = "MVS Shroud - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\s10\MVS_Shroud_co_Black.paa",
			"\SausageCo\MVS Data\s10\MVS_Shroud_co_Black.paa",
			"\SausageCo\MVS Data\s10\MVS_Shroud_co_Black.paa"
		};
	};
	
	class MVS_Beard_01: BalaclavaMask_ColorBase
	{
		scope = 0;
		displayName = "MVS Beard";
		descriptionShort = "...";
		inventorySlot[] = {"Mask"};
		itemSize[] = {3,2};
		model = "\SausageCo\MVS Data\Beards\MVS_BeardKit_g.p3d";
		rotationFlags=0;
		headSelectionsToHide[] = {};
		hiddenSelections[] = {"zbytek","ground"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_01_co.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Beards\MVS_Beard_01.p3d";
			female = "\SausageCo\MVS Data\Beards\MVS_Beard_01.p3d";
		};
	};
	class MVS_Beard_01_Brown: MVS_Beard_01
	{
		scope = 2;
		displayName = "MVS Beard - Brown";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_01_co.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	class MVS_Beard_01_LightBrown: MVS_Beard_01
	{
		scope = 2;
		displayName = "MVS Beard - Light Brown";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_01_co_LightBrown.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	class MVS_Beard_01_Black: MVS_Beard_01
	{
		scope = 2;
		displayName = "MVS Beard 01 - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_01_co_Black.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	class MVS_Beard_01_Blonde: MVS_Beard_01
	{
		scope = 2;
		displayName = "MVS Beard 01 - Blonde";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_01_co_Blonde.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	class MVS_Beard_01_White: MVS_Beard_01
	{
		scope = 2;
		displayName = "MVS Beard 01 - White";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_01_co_White.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	
	class MVS_Beard_02: BalaclavaMask_ColorBase
	{
		scope = 0;
		displayName = "MVS Beard";
		descriptionShort = "...";
		inventorySlot[] = {"Mask"};
		rotationFlags=0;
		itemSize[] = {3,2};
		headSelectionsToHide[] = {};
		model = "\SausageCo\MVS Data\Beards\MVS_BeardKit_g.p3d";
		hiddenSelections[] = {"zbytek","ground"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_02_co.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Beards\MVS_Beard_02.p3d";
			female = "\SausageCo\MVS Data\Beards\MVS_Beard_02.p3d";
		};
	};
	class MVS_Beard_02_Brown: MVS_Beard_02
	{
		scope = 2;
		displayName = "MVS Beard - Brown";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_02_co.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	class MVS_Beard_02_LightBrown: MVS_Beard_02
	{
		scope = 2;
		displayName = "MVS Beard - Light Brown";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_02_co_LightBrown.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	class MVS_Beard_02_Black: MVS_Beard_02
	{
		scope = 2;
		displayName = "MVS Beard 02 - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_02_co_Black.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	class MVS_Beard_02_Blonde: MVS_Beard_02
	{
		scope = 2;
		displayName = "MVS Beard 02 - Blonde";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_02_co_Blonde.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	class MVS_Beard_02_White: MVS_Beard_02
	{
		scope = 2;
		displayName = "MVS Beard 02 - White";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_02_co_White.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};

	class MVS_Beard_03: BalaclavaMask_ColorBase
	{
		scope = 0;
		displayName = "MVS Beard";
		descriptionShort = "...";
		inventorySlot[] = {"Mask"};
		rotationFlags=0;
		itemSize[] = {3,2};
		headSelectionsToHide[] = {};
		model = "\SausageCo\MVS Data\Beards\MVS_BeardKit_g.p3d";
		hiddenSelections[] = {"zbytek","ground"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_02_co.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Beards\MVS_Beard_03.p3d";
			female = "\SausageCo\MVS Data\Beards\MVS_Beard_03.p3d";
		};
	};
	class MVS_Beard_03_Brown: MVS_Beard_03
	{
		scope = 2;
		displayName = "MVS Beard - Brown";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_02_co.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	class MVS_Beard_03_LightBrown: MVS_Beard_03
	{
		scope = 2;
		displayName = "MVS Beard - Light Brown";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_02_co_LightBrown.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	class MVS_Beard_03_Black: MVS_Beard_03
	{
		scope = 2;
		displayName = "MVS Beard 02 - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_02_co_Black.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	class MVS_Beard_03_Blonde: MVS_Beard_03
	{
		scope = 2;
		displayName = "MVS Beard 02 - Blonde";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_02_co_Blonde.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	class MVS_Beard_03_White: MVS_Beard_03
	{
		scope = 2;
		displayName = "MVS Beard 02 - White";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Beards\MVS_Beard_02_co_White.paa",
			"\SausageCo\MVS Data\Beards\MVS_BeardKit_co.paa"
		};
	};
	
	class MVS_Cap_Base: Clothing
	{
		scope = 0;
		displayName = "MVS Patrol Cap";
		descriptionShort = "The MVS Patrol Cap - Both Identifier Patch and Comtacs can be attached.";
		model = "\SausageCo\MVS Data\Helmets\MVS_Cap_g.p3d";
		attachments[] = {"patch_04","MVS_Comtacs"};
		inventorySlot[]=
		{
			"Headgear"
		};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Headgear"
		};
		//rotationFlags=0;
		weight=110;
		itemSize[]={3,2};
		absorbency=0.80000001;
		heatIsolation=0.25;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		headSelectionsToHide[]=
		{
			"Clipping_baseballcap"
		};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\Helmets\MVS_Cap.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\Helmets\MVS_Cap.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\Helmets\MVS_Cap.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\Helmets\MVS_Cap_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\Helmets\MVS_Cap_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\Helmets\MVS_Cap_destruct.rvmat"}}
                    };
				};
			};
		};
		class ClothingTypes
		{
			male = "\SausageCo\MVS Data\Helmets\MVS_Cap.p3d";
			female = "\SausageCo\MVS Data\Helmets\MVS_Cap.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="Shirt_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="Shirt_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	
	class MVS_Cap_OD: MVS_Cap_Base
	{
		scope = 2;
		displayName = "MVS Patrol Cap - OD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co.paa"
		};
	};
	class MVS_Cap_Tan: MVS_Cap_Base
	{
		scope = 2;
		displayName = "MVS Patrol Cap - Tan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_Tan.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_Tan.paa"
		};
	};
	class MVS_Cap_Black: MVS_Cap_Base
	{
		scope = 2;
		displayName = "MVS Patrol Cap - Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_Black.paa"
		};
	};
	class MVS_Cap_Multicam: MVS_Cap_Base
	{
		scope = 2;
		displayName = "MVS Patrol Cap - Multicam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_MC.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_MC.paa"
		};
	};
	class MVS_Cap_Multicam_Black: MVS_Cap_Base
	{
		scope = 2;
		displayName = "MVS Patrol Cap - Multicam Black";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_MC_Black.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_MC_Black.paa"
		};
	};
	class MVS_Cap_Multicam_Tropic: MVS_Cap_Base
	{
		scope = 2;
		displayName = "MVS Patrol Cap - Multicam Tropic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_MC_Tropic.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_MC_Tropic.paa"
		};
	};
	/*
	class MVS_Cap_Flecktarn: MVS_Cap_Base
	{
		scope = 2;
		displayName = "MVS Patrol Cap - Flecktarn";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_Flecktarn.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_Flecktarn.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_Flecktarn.paa"
		};
	};
	*/
	class MVS_Cap_ERDL: MVS_Cap_Base
	{
		scope = 2;
		displayName = "MVS Patrol Cap - ERDL";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_ERDL.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_ERDL.paa"
		};
	};
	class MVS_Cap_Snow: MVS_Cap_Base
	{
		scope = 2;
		displayName = "MVS Patrol Cap - Snow";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_Snow.paa",
			"\SausageCo\MVS Data\Helmets\MVS_Cap_co_Snow.paa"
		};
	};
	
	class MVS_Comtacs_Base: BalaclavaMask_ColorBase
	{
		scope = 0;
		displayName="MVS Comtacs";
		descriptionShort="MVS Comtacs - a trusted tactical communications and hearing protection headset that is field proven by law enforcement and militaries world wide";
		model="\SausageCo\MVS Data\Helmets\MVS_Comtacs_g.p3d";
		inventorySlot[]=
		{
			"Headgear",
			"MVS_Comtacs"
		};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Headgear"
		};
		rotationFlags=0;
		weight=110;
		itemSize[]={3,2};
		absorbency=0.80000001;
		heatIsolation=0.25;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		headSelectionsToHide[]=
		{
		};
		hiddenSelections[]=
		{
			"zbytek"
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
								"DZ\characters\headgear\data\BaseballCapII.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\headgear\data\BaseballCapII.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\headgear\data\BaseballCapII_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\headgear\data\BaseballCapII_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\characters\headgear\data\BaseballCapII_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\SausageCo\MVS Data\Helmets\MVS_Comtacs.p3d";
			female="\SausageCo\MVS Data\Helmets\MVS_Comtacs.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="Shirt_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="Shirt_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class MVS_Comtacs_OD: MVS_Comtacs_Base
	{
		scope=2;
		displayName="MVS Comtacs - OD";
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava_headphones_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava_headphones_co.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava_headphones_co.paa"
		};
	};
	class MVS_Comtacs_Tan: MVS_Comtacs_Base
	{
		scope=2;
		displayName="MVS Comtacs - Tan";
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava_headphones_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava_headphones_co_Tan.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava_headphones_co_Tan.paa"
		};
	};
	class MVS_Comtacs_Black: MVS_Comtacs_Base
	{
		scope=2;
		displayName="MVS Comtacs - Black";
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\MVS Data\s10\MVS_Balaclava_headphones_co_Black.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava_headphones_co_Black.paa",
			"\SausageCo\MVS Data\s10\MVS_Balaclava_headphones_co_Black.paa"
		};
	};
	
	class MVS_CombatPants_Base: BDUPants
	{
		scope=0;
		displayName="MVS Combat Pants";
		descriptionShort="Designed as a no-compromise assault uniform, these pants are aggressively cut for maximum mobility.";
		model="\SausageCo\MVS Data\Uniforms\MVS_CombatPants_g.p3d";
		quickBarBonus=2;
		hiddenSelections[]={"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_Tan_co.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_Tan_co.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_Tan_co.paa"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\Uniforms\MVS_CombatPants.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\Uniforms\MVS_CombatPants.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\Uniforms\MVS_CombatPants.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\Uniforms\MVS_CombatPants_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\Uniforms\MVS_CombatPants_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\Uniforms\MVS_CombatPants_destruct.rvmat"}}
                    };
				};
			};
		};		
		class ClothingTypes
		{
			male="\SausageCo\MVS Data\Uniforms\MVS_CombatPants.p3d";
			female="\SausageCo\MVS Data\Uniforms\MVS_CombatPants_f.p3d";
		};
	};	
	class MVS_CombatPants_Tan: MVS_CombatPants_Base
	{
		scope=2;
		displayName="MVS Combat Pants - Tan";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_Tan_co.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_Tan_co.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_Tan_co.paa"
		};
	};
	class MVS_CombatPants_OD: MVS_CombatPants_Base
	{
		scope=2;
		displayName="MVS Combat Pants - OD";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_OD.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_OD.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_OD.paa"
		};
	};
	class MVS_CombatPants_Black: MVS_CombatPants_Base
	{
		scope=2;
		displayName="MVS Combat Pants - Black";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_Black.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_Black.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_Black.paa"
		};
	};
	class MVS_CombatPants_ERDL: MVS_CombatPants_Base
	{
		scope=2;
		displayName="MVS Combat Pants - ERDL";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_ERDL.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_ERDL.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_ERDL.paa"
		};
	};
	class MVS_CombatPants_Snow: MVS_CombatPants_Base
	{
		scope=2;
		displayName="MVS Combat Pants - Snow";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_Snow.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_Snow.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_Snow.paa"
		};
	};
	class MVS_CombatPants_Multicam: MVS_CombatPants_Base
	{
		scope=2;
		displayName="MVS Combat Pants - Multicam";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_MC.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_MC.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_MC.paa"
		};
	};	
	class MVS_CombatPants_Multicam_Tropic: MVS_CombatPants_Base
	{
		scope=2;
		displayName="MVS Combat Pants - Multicam Tropic";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_MC_Tropic.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_MC_Tropic.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_MC_Tropic.paa"
		};
	};	
	class MVS_CombatPants_Multicam_Black: MVS_CombatPants_Base
	{
		scope=2;
		displayName="MVS Combat Pants - Multicam Black";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_MC_Black.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_MC_Black.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatPants_MC_Black.paa"
		};
	};	
	class MVS_CombatShirt_Base: TacticalShirt_ColorBase
	{
		scope=0;
		displayName="MVS Combat Shirt";
		descriptionShort="The MVS Combat Shirt is a combat-specific garment specifically designed to be worn under body armor.";
		model="SausageCo\MVS Data\Uniforms\MVS_CombatShirt_g.p3d";
		quickBarBonus=1;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\Uniforms\MVS_CombatShirt.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\Uniforms\MVS_CombatShirt.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\Uniforms\MVS_CombatShirt.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_destruct.rvmat"}}
                    };
				};
			};
		};
		class ClothingTypes
		{
			male="SausageCo\MVS Data\Uniforms\MVS_CombatShirt.p3d";
			female="SausageCo\MVS Data\Uniforms\MVS_CombatShirt_f.p3d";
		};
	};
	class MVS_CombatShirt_Tan: MVS_CombatShirt_Base
	{
		scope=2;
		displayName="MVS Combat Shirt - Tan";
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_Tan.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_Tan.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_Tan.paa"
		};
	};
	class MVS_CombatShirt_OD: MVS_CombatShirt_Base
	{
		scope=2;
		displayName="MVS Combat Shirt - OD";
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_OD.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_OD.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_OD.paa"
		};
	};
	class MVS_CombatShirt_Black: MVS_CombatShirt_Base
	{
		scope=2;
		displayName="MVS Combat Shirt - Black";
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_Black.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_Black.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_Black.paa"
		};
	};
	class MVS_CombatShirt_ERDL: MVS_CombatShirt_Base
	{
		scope=2;
		displayName="MVS Combat Shirt - ERDL";
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_ERDL.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_ERDL.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_ERDL.paa"
		};
	};
	class MVS_CombatShirt_Snow: MVS_CombatShirt_Base
	{
		scope=2;
		displayName="MVS Combat Shirt - Snow";
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_Snow.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_Snow.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_Snow.paa"
		};
	};
	class MVS_CombatShirt_Multicam: MVS_CombatShirt_Base
	{
		scope=2;
		displayName="MVS Combat Shirt - Multicam";
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_MC.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_MC.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_MC.paa"
		};
	};
	class MVS_CombatShirt_Multicam_Tropic: MVS_CombatShirt_Base
	{
		scope=2;
		displayName="MVS Combat Shirt - Multicam Tropic";
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_MC_Tropic.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_MC_Tropic.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_MC_Tropic.paa"
		};
	};
	class MVS_CombatShirt_Multicam_Black: MVS_CombatShirt_Base
	{
		scope=2;
		displayName="MVS Combat Shirt - Multicam Black";
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_MC_Black.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_MC_Black.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_MC_Black.paa"
		};
	};
	/*
	class MVS_CombatShirt_Flecktarn: MVS_CombatShirt_Base
	{
		scope=2;
		displayName="MVS Combat Shirt - Flecktarn";
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_Flecktarn.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_Flecktarn.paa",
			"SausageCo\MVS Data\Uniforms\MVS_CombatShirt_Flecktarn.paa"
		};
	};
	*/
	class GorkaPants_Flat;
	class MVS_GorkaPants: GorkaPants_Flat
	{
		displayName = "MVS Gorka Pants - ERDL";
		descriptionShort = "MVS Gorka Pants - ERDL";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants.paa"
		};
	};
	
	class MVS_GorkaPants_Snow: GorkaPants_Flat
	{
		displayName = "MVS Gorka Pants - Snow";
		descriptionShort = "MVS Gorka Pants - Snow";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants_Snow.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants_Snow.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants_Snow.paa"
		};
	};
	class MVS_GorkaPants_Multicam: GorkaPants_Flat
	{
		displayName = "MVS Gorka Pants - Multicam";
		descriptionShort = "MVS Gorka Pants - Multicam";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants_MC.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants_MC.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants_MC.paa"
		};
	};
	class MVS_GorkaPants_Multicam_Tropic: GorkaPants_Flat
	{
		displayName = "MVS Gorka Pants - Multicam Tropic";
		descriptionShort = "MVS Gorka Pants - Multicam Tropic";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants_MC_Tropic.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants_MC_Tropic.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants_MC_Tropic.paa"
		};
	};
	class MVS_GorkaPants_Multicam_Black: GorkaPants_Flat
	{
		displayName = "MVS Gorka Pants - Multicam Black";
		descriptionShort = "MVS Gorka Pants - Multicam Black";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants_MC_Black.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants_MC_Black.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaPants_MC_Black.paa"
		};
	};
	
	class GorkaEJacket_Flat;
	class MVS_GorkaJacket: GorkaEJacket_Flat
	{
		displayName = "MVS Gorka Top - ERDL";
		descriptionShort = "MVS Gorka Top - ERDL";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket.paa"
		};
	};	
	
	class MVS_GorkaJacket_Snow: GorkaEJacket_Flat
	{
		displayName = "MVS Gorka Top - Snow";
		descriptionShort = "MVS Gorka Top - Snow";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket_Snow.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket_Snow.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket_Snow.paa"
		};
	};
	class MVS_GorkaJacket_Multicam: GorkaEJacket_Flat
	{
		displayName = "MVS Gorka Top - Multicam";
		descriptionShort = "MVS Gorka Top - Multicam";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket_MC.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket_MC.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket_MC.paa"
		};
	};
	class MVS_GorkaJacket_Multicam_Tropic: GorkaEJacket_Flat
	{
		displayName = "MVS Gorka Top - Multicam Tropic";
		descriptionShort = "MVS Gorka Top - Multicam Tropic";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket_MC_Tropic.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket_MC_Tropic.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket_MC_Tropic.paa"
		};
	};
	class MVS_GorkaJacket_Multicam_Black: GorkaEJacket_Flat
	{
		displayName = "MVS Gorka Top - Multicam Black";
		descriptionShort = "MVS Gorka Top - Multicam Black";
		scope=2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket_MC_Black.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket_MC_Black.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_GorkaJacket_MC_Black.paa"
		};
	};
	
	class FlatCap_Black;
	class MVS_FlatCap: FlatCap_Black
	{
		displayName = "MVS Flat Cap - ERDL";
		descriptionShort = "MVS Flat Cap - ERDL";		
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap.paa"};
	};
	
	class MVS_FlatCap_Snow: FlatCap_Black
	{
		displayName = "MVS Flat Cap - Snow";
		descriptionShort = "MVS Flat Cap - Snow";		
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap_Snow.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap_Snow.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap_Snow.paa"};
	};
	class MVS_FlatCap_Multicam: FlatCap_Black
	{
		displayName = "MVS Flat Cap - Multicam";
		descriptionShort = "MVS Flat Cap - Multicam";		
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap_MC.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap_MC.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap_MC.paa"};
	};
	class MVS_FlatCap_Multicam_Tropic: FlatCap_Black
	{
		displayName = "MVS Flat Cap - Multicam Tropic";
		descriptionShort = "MVS Flat Cap - Multicam Tropic";		
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap_MC_Tropic.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap_MC_Tropic.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap_MC_Tropic.paa"};
	};
	class MVS_FlatCap_Multicam_Black: FlatCap_Black
	{
		displayName = "MVS Flat Cap - Multicam Black";
		descriptionShort = "MVS Flat Cap - Multicam Black";		
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap_MC_Black.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap_MC_Black.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_FlatCap_MC_Black.paa"};
	};
	
	class CargoPants_Beige;
	class TacticalShirt_Olive;
	class MVS_Pants_BDU: CargoPants_Beige
	{
		scope = 2;
		displayName = "MVS BDU Pants - ERDL";
		descriptionShort = "MVS BDU Pants - ERDL";
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = 
		{
			"SausageCo\MVS Data\Uniforms\MVS_pants_BDU.paa",
			"SausageCo\MVS Data\Uniforms\MVS_pants_BDU.paa",
			"SausageCo\MVS Data\Uniforms\MVS_pants_BDU.paa"
		};
	};
	
	class MVS_Pants_BDU_Snow: CargoPants_Beige
	{
		scope = 2;
		displayName = "MVS BDU Pants - Snow";
		descriptionShort = "MVS BDU Pants - Snow";
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = 
		{
			"SausageCo\MVS Data\Uniforms\MVS_pants_BDU_Snow.paa",
			"SausageCo\MVS Data\Uniforms\MVS_pants_BDU_Snow.paa",
			"SausageCo\MVS Data\Uniforms\MVS_pants_BDU_Snow.paa"
		};
	};

	class MVS_Shirt_BDU: TacticalShirt_Olive
	{
		scope = 2;
		displayName = "MVS BDU Top - ERDL";
		descriptionShort = "MVS BDU Top - ERDL";
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[] = 
		{
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU.paa",
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU.paa",
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU.paa"
		};
	};
	
	class MVS_Shirt_BDU_Snow: TacticalShirt_Olive
	{
		scope = 2;
		displayName = "MVS BDU Top - Snow";
		descriptionShort = "MVS BDU Top - Snow";
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[] = 
		{
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_Snow.paa",
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_Snow.paa",
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_Snow.paa"
		};
	};
	
	class MVS_Shirt_BDU_Multicam: TacticalShirt_Olive
	{
		scope = 2;
		displayName = "MVS BDU Top - Multicam";
		descriptionShort = "MVS BDU Top - Multicam";
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[] = 
		{
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_MC.paa",
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_MC.paa",
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_MC.paa"
		};
	};	
	
	class MVS_Shirt_BDU_Multicam_Tropic: TacticalShirt_Olive
	{
		scope = 2;
		displayName = "MVS BDU Top - Multicam Tropic";
		descriptionShort = "MVS BDU Top - Multicam Tropic";
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[] = 
		{
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_MC_Tropic.paa",
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_MC_Tropic.paa",
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_MC_Tropic.paa"
		};
	};
	
	class MVS_Shirt_BDU_Multicam_Black: TacticalShirt_Olive
	{
		scope = 2;
		displayName = "MVS BDU Top - Multicam Black";
		descriptionShort = "MVS BDU Top - Multicam Black";
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[] = 
		{
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_MC_Black.paa",
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_MC_Black.paa",
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_MC_Black.paa"
		};
	};
	/*
	class MVS_Shirt_BDU_Flecktarn: TacticalShirt_Olive
	{
		scope = 2;
		displayName = "MVS BDU Top - Flecktarn";
		descriptionShort = "MVS BDU Top - Flecktarn";
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[] = 
		{
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_Flecktarn.paa",
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_Flecktarn.paa",
			"SausageCo\MVS Data\Uniforms\MVS_jacket_BDU_Flecktarn.paa"
		};
	};
	*/
	class BoonieHat_Olive;
	class MVS_BoonieHat: BoonieHat_Olive
	{
		displayName = "MVS Boonie Hat - ERDL";
		descriptionShort = "MVS Boonie Hat - ERDL";
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat.paa"
		};
	};
	
	class MVS_BoonieHat_Snow: BoonieHat_Olive
	{
		displayName = "MVS Boonie Hat - Snow";
		descriptionShort = "MVS Boonie Hat - Snow";
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat_Snow.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat_Snow.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat_Snow.paa"
		};
	};
	class MVS_BoonieHat_Multicam: BoonieHat_Olive
	{
		displayName = "MVS Boonie Hat - Multicam";
		descriptionShort = "MVS Boonie Hat - Multicam";
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat_MC.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat_MC.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat_MC.paa"
		};
	};
	class MVS_BoonieHat_Multicam_Tropic: BoonieHat_Olive
	{
		displayName = "MVS Boonie Hat - Multicam Tropic";
		descriptionShort = "MVS Boonie Hat - Multicam Tropic";
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat_MC_Tropic.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat_MC_Tropic.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat_MC_Tropic.paa"
		};
	};
	class MVS_BoonieHat_Multicam_Black: BoonieHat_Olive
	{
		displayName = "MVS Boonie Hat - Multicam Black";
		descriptionShort = "MVS Boonie Hat - Multicam Black";
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat_MC_Black.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat_MC_Black.paa",
			"\SausageCo\MVS Data\Uniforms\MVS_BoonieHat_MC_Black.paa"
		};
	};
	
	class Modular_Patch_Base: Clothing
	{
		scope = 0;
		displayName = "Identifier Patch";
		descriptionShort = "MVS Identifier Patch - comes in a variety of patterns and emblems";
		model = "\SausageCo\MVS Data\patch.p3d";
		itemSize[] = {2,1};
		inventorySlot[] = {"Armband","patch_01","patch_02","patch_03","patch_04"};
		weight=0;
		hiddenSelections[] = {"zbytek","armband"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_sl.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\vestTextures\patch.rvmat",
			"SausageCo\MVS Data\vestTextures\MVS_Armband.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\vestTextures\patch.rvmat","SausageCo\MVS Data\vestTextures\MVS_Armband.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\vestTextures\patch.rvmat","SausageCo\MVS Data\vestTextures\MVS_Armband.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\vestTextures\patch_damage.rvmat","SausageCo\MVS Data\vestTextures\MVS_Armband_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\vestTextures\patch_damage.rvmat","SausageCo\MVS Data\vestTextures\MVS_Armband_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\vestTextures\patch_destruct.rvmat","SausageCo\MVS Data\vestTextures\MVS_Armband_destruct.rvmat"}}
                    };
				};
			};
		};		
		class ClothingTypes
		{
			male="SausageCo\MVS Data\MVS_Patch_m.p3d";
			female="SausageCo\MVS Data\MVS_Patch_m.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	
	class Modular_Patch_Base_2: Clothing
	{
		scope = 0;
		displayName = "MVS Country Flag";
		descriptionShort = "MVS Country Flag Patch";
		model = "\SausageCo\MVS Data\MVS_Country_Patch.p3d";
		itemSize[] = {2,1};
		inventorySlot[] = {"Armband","patch_01","patch_02","patch_03","patch_04"};
		weight=0;
		hiddenSelections[] = {"zbytek","armband"};
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Afghanistan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
        hiddenSelectionsMaterials[]=
        {
            "SausageCo\MVS Data\vestTextures\MVS_Country_Patch.rvmat",
			"SausageCo\MVS Data\vestTextures\MVS_Armband.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
                    healthLevels[] = 
                    {
                        {1.0,{"SausageCo\MVS Data\vestTextures\MVS_Country_Patch.rvmat","SausageCo\MVS Data\vestTextures\MVS_Armband.rvmat"}},
                        {0.7,{"SausageCo\MVS Data\vestTextures\MVS_Country_Patch.rvmat","SausageCo\MVS Data\vestTextures\MVS_Armband.rvmat"}},
                        {0.5,{"SausageCo\MVS Data\vestTextures\MVS_Country_Patch_damage.rvmat","SausageCo\MVS Data\vestTextures\MVS_Armband_damage.rvmat"}},
                        {0.3,{"SausageCo\MVS Data\vestTextures\MVS_Country_Patch_damage.rvmat","SausageCo\MVS Data\vestTextures\MVS_Armband_damage.rvmat"}},
                        {0.0,{"SausageCo\MVS Data\vestTextures\MVS_Country_Patch_destruct.rvmat","SausageCo\MVS Data\vestTextures\MVS_Armband_destruct.rvmat"}}
                    };
				};
			};
		};		
		class ClothingTypes
		{
			male="SausageCo\MVS Data\MVS_Patch_m2.p3d";
			female="SausageCo\MVS Data\MVS_Patch_m2.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	
	class MVS_CountryFlag_Afghanistan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Afghanistan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Afghanistan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Albania: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Albania";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Albania.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Algeria: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Algeria";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Algeria.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_AmericanSamoa: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - American Samoa";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\AmericanSamoa.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Andorra: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Andorra";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Andorra.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Angola: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Angola";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Angola.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Antigua: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Antigua";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Antigua.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Argentina: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Argentina";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Argentina.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Armenia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Armenia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Armenia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Aruba: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Aruba";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Aruba.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Australia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Australia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Australia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Austria: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Austria";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Austria.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Azerbaijan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Azerbaijan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Azerbaijan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Azores: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Azores";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Azores.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Bahamas: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Bahamas";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Bahamas.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Bahrain: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Bahrain";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Bahrain.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Bangladesh: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Bangladesh";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Bangladesh.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Barbados: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Barbados";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Barbados.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Belarus: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Belarus";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Belarus.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Belgium: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Belgium";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Belgium.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Belize: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Belize";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Belize.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Benin: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Benin";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Benin.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Bermuda: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Bermuda";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Bermuda.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Bhutan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Bhutan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Bhutan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Bolivia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Bolivia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Bolivia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};

	class MVS_CountryFlag_Bosnia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Bosnia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Bosnia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Botswana: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Botswana";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Botswana.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Brazil: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Brazil";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Brazil.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_BritishVirginIslands: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - British Virgin Islands";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\BritishVirginIslands.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_BruneiDarussalam: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Brunei Darussalam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\BruneiDarussalam.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Bulgaria: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Bulgaria";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Bulgaria.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_BurkinaFaso: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Burkina Faso";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\BurkinaFaso.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Burma: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Burma";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Burma.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Burundi: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Burundi";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Burundi.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Cambodia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Cambodia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Cambodia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Cameroon: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Cameroon";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Cameroon.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Canada: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Canada";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Canada.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_CapeVerde: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Cape Verde";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\CapeVerde.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_CaymanIslands: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Cayman Islands";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\CaymanIslands.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Chad: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Chad";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Chad.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Chile: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Chile";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Chile.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_China: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - China";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\China.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Colombia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Colombia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Colombia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Comoros: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Comoros";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Comoros.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_CookIslands: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Cook Islands";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\CookIslands.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_CostaRica: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Costa Rica";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\CostaRica.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Croatia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Croatia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Croatia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Cuba: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Cuba";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Cuba.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Curacao: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Curacao";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Curacao.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Cyprus: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Cyprus";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Cyprus.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Czech: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Czech";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Czech.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Denmark: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Denmark";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Denmark.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Djibouti: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Djibouti";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Djibouti.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_DominicanRepublic: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Dominican Republic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\DominicanRepublic.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_EastTimor: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - East Timor";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\EastTimor.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Ecuador: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Ecuador";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Ecuador.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Egypt: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Egypt";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Egypt.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_ElSalvador: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - El Salvador";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\ElSalvador.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Eritrea: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Eritrea";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Eritrea.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Estonia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Estonia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Estonia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Ethiopia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Ethiopia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Ethiopia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_FalklandIslands: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Falkland Islands";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\FalklandIslands.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Fiji: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Fiji";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Fiji.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Finland: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Finland";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Finland.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_France: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - France";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\France.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Gabon: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Gabon";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Gabon.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Gambia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Gambia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Gambia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Germany: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Germany";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Germany.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Ghana: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Ghana";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Ghana.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Gibraltar: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Gibraltar";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Gibraltar.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Greece: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Greece";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Greece.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Greenland: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Greenland";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Greenland.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Grenada: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Grenada";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Grenada.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Guam: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Guam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Guam.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Guatemala: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Guatemala";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Guatemala.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Guinea: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Guinea";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Guinea.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Guyana: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Guyana";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Guyana.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_GypsyRomani: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Gypsy Romani";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\GypsyRomani.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Haiti: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Haiti";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Haiti.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Honduras: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Honduras";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Honduras.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Hungary: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Hungary";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Hungary.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Iceland: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Iceland";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Iceland.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_India: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - India";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\India.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Indonesia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Indonesia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Indonesia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Iran: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Iran";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Iran.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Iraq: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Iraq";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Iraq.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Ireland: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Ireland";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Ireland.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Israel: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Israel";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Israel.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Italy: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Italy";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Italy.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Jamaica: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Jamaica";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Jamaica.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Japan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Japan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Japan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Jordan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Jordan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Jordan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Kazakhstan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Kazakhstan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Kazakhstan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Kenya: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Kenya";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Kenya.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Kiribati: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Kiribati";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Kiribati.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Kosovo: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Kosovo";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Kosovo.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Kuwait: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Kuwait";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Kuwait.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Kyrgyzstan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Kyrgyzstan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Kyrgyzstan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Laos: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Laos";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Laos.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Latvia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Latvia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Latvia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Lebanon: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Lebanon";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Lebanon.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Lesotho: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Lesotho";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Lesotho.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Liberia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Liberia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Liberia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Libya: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Libya";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Libya.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Lithuania: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Lithuania";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Lithuania.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Macau: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Macau";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Macau.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Macedonia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Macedonia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Macedonia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Madagascar: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Madagascar";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Madagascar.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Malawi: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Malawi";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Malawi.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Malaysia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Malaysia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Malaysia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Maldives: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Maldives";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Maldives.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Mali: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Mali";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Mali.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Malta: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Malta";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Malta.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_MarshallIslands: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Marshall Islands";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\MarshallIslands.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Mauritius: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Mauritius";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Mauritius.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Mexico: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Mexico";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Mexico.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Micronesia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Micronesia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Micronesia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Moldova: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Moldova";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Moldova.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Monaco: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Monaco";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Monaco.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Mongolia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Mongolia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Mongolia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Montenegro: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Montenegro";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Montenegro.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Morocco: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Morocco";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Morocco.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Mozambique: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Mozambique";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Mozambique.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Namibia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Namibia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Namibia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Nauru: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Nauru";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Nauru.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Netherlands: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Netherlands";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Netherlands.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_NewZealand: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - New Zealand";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\NewZealand.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Nicaragua: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Nicaragua";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Nicaragua.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Niger: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Niger";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Niger.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Nigeria: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Nigeria";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Nigeria.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_NorthernIreland: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Northern Ireland";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\NorthernIreland.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Norway: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Norway";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Norway.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Oman: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Oman";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Oman.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Pakistan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Pakistan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Pakistan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Palau: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Palau";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Palau.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Palestine: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Palestine";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Palestine.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Panama: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Panama";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Panama.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_PapuaNewGuinea: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Papua New Guinea";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\PapuaNewGuinea.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Paraguay: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Paraguay";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Paraguay.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Peru: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Peru";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Peru.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Philippines: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Philippines";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Philippines.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Poland: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Poland";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Poland.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Portugal: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Portugal";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Portugal.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_PuertoRico: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Puerto Rico";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\PuertoRico.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Qatar: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Qatar";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Qatar.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Romania: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Romania";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Romania.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Russia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Russia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Russia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	
	class MVS_CountryFlag_Rwanda: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Rwanda";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Rwanda.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Samoa: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Samoa";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Samoa.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_SanMarino: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - San Marino";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\SanMarino.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_SaudiArabia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Saudi Arabia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\SaudiArabia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Scotland: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Scotland";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Scotland.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Senegal: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Senegal";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Senegal.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Serbia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Serbia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Serbia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Seychelles: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Seychelles";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Seychelles.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Sicily: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Sicily";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Sicily.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_SierraLeone: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Sierra Leone";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\SierraLeone.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Singapore: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Singapore";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Singapore.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Slovakia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Slovakia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Slovakia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Slovenia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Slovenia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Slovenia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_SolomonIslands: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Solomon Islands";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\SolomonIslands.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Somalia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Somalia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Somalia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_SouthAfrica: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - South Africa";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\SouthAfrica.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_SouthKorea: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - South Korea";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\SouthKorea.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_SouthVietnam: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - South Vietnam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\SouthVietnam.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Spain: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Spain";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Spain.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_SriLanka: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Sri Lanka";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\SriLanka.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_StLucia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - St Lucia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\StLucia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_StMaarten: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - St Maarten";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\StMaarten.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Sudan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Sudan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Sudan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Suriname: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Suriname";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Suriname.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Swaziland: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Swaziland";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Swaziland.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Sweden: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Sweden";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Sweden.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Switzerland: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Switzerland";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Switzerland.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Syria: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Syria";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Syria.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Taiwan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Taiwan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Taiwan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Tajikistan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Tajikistan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Tajikistan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Tanzania: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Tanzania";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Tanzania.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Thailand: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Thailand";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Thailand.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Tibet: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Tibet";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Tibet.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Togo: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Togo";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Togo.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Tonga: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Tonga";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Tonga.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Trinidad: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Trinidad";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Trinidad.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Tunisia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Tunisia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Tunisia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Turkey: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Turkey";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Turkey.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Turkmenistan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Turkmenistan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Turkmenistan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_TurksCaicos: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Turks & Caicos";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\TurksCaicos.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Tuvalu: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Tuvalu";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Tuvalu.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_UAE: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - UAE";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\UAE.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Uganda: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Uganda";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Uganda.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Ukraine: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Ukraine";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Ukraine.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_UnitedKingdom: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - United Kingdom";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\UnitedKingdom.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_UnitedNations: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - United Nations";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\UnitedNations.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_UnitedStates: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - United States";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\UnitedStates.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Uruguay: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Uruguay";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Uruguay.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_USSR: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - USSR";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\USSR.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Uzbekistan: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Uzbekistan";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Uzbekistan.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Vanuatu: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Vanuatu";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Vanuatu.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Venezuela: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Venezuela";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Venezuela.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Vietnam: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Vietnam";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Vietnam.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Wales: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Wales";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Wales.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Yemen: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Yemen";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Yemen.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Yugoslavia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Yugoslavia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Yugoslavia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Zambia: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Zambia";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Zambia.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_CountryFlag_Zimbabwe: Modular_Patch_Base_2
	{
		scope = 2;
		displayName = "MVS Country Flag - Zimbabwe";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\CountryFlags\Zimbabwe.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};

	class MVS_Patch_01: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Squad Leader";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_sl.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_02: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Team Leader";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_tl.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_03: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Machinegunner";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_gnr.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_04: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Medic";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_med.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_05: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Sniper";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_snpr.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_06: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Rifleman";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_rfl.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_07: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - US";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_US.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_08: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - UK";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_UK.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_09: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - AUS";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_AUS.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_10: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - US";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_US_IR.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_11: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - UK";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_UK_IR.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_12: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - AUS";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_AUS_IR.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_13: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Rotten's Raiders";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_cobra.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_14: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - A10 Warthog";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_a10.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_15: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - EOD";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_EOD.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_16: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - F*ck Sh*t Up";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_FSU.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_17: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - No F*cks Given";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_fcks.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_18: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - I'm Too Old for This Sh*t";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_old.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_19: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Weyland-Yutani Corp";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_Weyland.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_20: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - The Warriors";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_warriors.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_21: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Canada";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_CAN.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_22: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Canada";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_CAN_IR.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_23: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - OBEY";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_obey.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_24: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Blackwater";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_Blackwater.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_25: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Lagoon Trade & Courier Services";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_lagoon.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_26: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - HCLI";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_HCLI.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_27: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Boogaloo";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_boogaloo.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_28: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - UN";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_UN.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_29: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Umbrella";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_Umbrella.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_30: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Umbrella";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_USS.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_31: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Romania";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_ROM.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_32: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Sweden";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_SWE.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_33: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - Anarchy";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_AN.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_34: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - RTO";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_RTO.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa",
			
		};
	};
	class MVS_Patch_35: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - This is the Way";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\patch_warrior.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
	class MVS_Patch_36: Modular_Patch_Base
	{
		scope = 2;
		displayName = "Identifier Patch - ADMIN";
		hiddenSelectionsTextures[] = 
		{
			"\SausageCo\MVS Data\vestTextures\MVS_admin_patch.paa",
			"\SausageCo\MVS Data\vestTextures\MVS_Armband_co.paa"
		};
	};
};

class CfgSlots
{
	class Slot_MVSBattery1
	{
		name="MVSBattery1";
		displayName="MVSBattery1";
		ghostIcon="batteryd";
	};
	
	class Slot_MVSBattery2
	{
		name="MVSBattery2";
		displayName="MVSBattery2";
		ghostIcon="batteryd";
	};
	
	class Slot_magazine4
	{
		name="magazine4";
		displayName="magazine4";
		ghostIcon="magazine2";
	};	
	class Slot_magazine5
	{
		name="magazine5";
		displayName="magazine5";
		ghostIcon="magazine2";
	};
	class Slot_magazine7
	{
		name="magazine7";
		displayName="magazine7";
		ghostIcon="magazine";
	};	
	class Slot_magazine8
	{
		name="magazine8";
		displayName="magazine8";
		ghostIcon="magazine2";
	};	
	class Slot_magazine9
	{
		name="magazine9";
		displayName="magazine9";
		ghostIcon="magazine2";
	};
	class Slot_magazine10
	{
		name="magazine10";
		displayName="magazine10";
		ghostIcon="magazine";
	};
	class Slot_modular_pouch_2
	{
		name = "modular_pouch_2";
		displayName = "modular_pouch_2";
		ghostIcon = "vestpouches";
	};
	class Slot_modular_pouch_4
	{
		name = "modular_pouch_4";
		displayName = "modular_pouch_4";
		ghostIcon = "pouches";
	};
	
	class Slot_modular_pouch_5
	{
		name = "modular_pouch_5";
		displayName = "modular_pouch_5";
		ghostIcon = "pouches";
	};
	
	class Slot_modular_pouch_6
	{
		name = "modular_pouch_6";
		displayName = "modular_pouch_6";
		ghostIcon = "pouches";
	};
	class Slot_modular_pouch_8
	{
		name = "modular_pouch_8";
		displayName = "modular_pouch_8";
		ghostIcon = "pouches";
	};
	class Slot_modular_pouch_9
	{
		name = "modular_pouch_9";
		displayName = "modular_pouch_9";
		ghostIcon = "pouches";
	};
	class Slot_modular_pouch_10
	{
		name = "modular_pouch_10";
		displayName = "modular_pouch_10";
		ghostIcon = "pouches";
	};
	class Slot_modular_pouch_11
	{
		name = "modular_pouch_11";
		displayName = "modular_pouch_11";
		ghostIcon = "pouches";
	};
	class Slot_modular_pouch_12
	{
		name = "modular_pouch_12";
		displayName = "modular_pouch_12";
		ghostIcon = "vestpouches";
	};
	class Slot_modular_pouch_13
	{
		name = "modular_pouch_13";
		displayName = "modular_pouch_13";
		ghostIcon = "pouches";
	};
	class Slot_patch_01
	{
		name = "patch_01";
		displayName = "patch_01";
		ghostIcon = "armband";
	};
	class Slot_patch_02
	{
		name = "patch_02";
		displayName = "patch_02";
		ghostIcon = "armband";
	};
	class Slot_patch_03
	{
		name = "patch_03";
		displayName = "patch_03";
		ghostIcon = "armband";
	};
	class Slot_patch_04
	{
		name = "patch_04";
		displayName = "patch_04";
		ghostIcon = "armband";
	};	
	
	class Slot_morphine
	{
		name = "morphine";
		displayName = "morphine";
		ghostIcon = "";
	};
	class Slot_epinephrine
	{
		name = "epinephrine";
		displayName = "epinephrine";
		ghostIcon = "";
	};
	class Slot_MVS_vest
	{
		name = "MVS_vest";
		displayName = "MVS_vest";
		ghostIcon = "vest";
	};
	class Slot_MVS_helmet
	{
		name = "MVS_helmet";
		displayName = "MVS_helmet";
		ghostIcon = "headgear";
	};
	class Slot_MVS_Comtacs
	{
		name = "MVS_Comtacs";
		displayName = "MVS_Comtacs";
		ghostIcon = "headgear";
	};
	class Slot_MVS_mask
	{
		name = "MVS_mask";
		displayName = "MVS_mask";
		ghostIcon = "mask";
	};
	class Slot_MVS_pack
	{
		name = "MVS_pack";
		displayName = "MVS_pack";
		ghostIcon = "back";
	};
	class Slot_MVS_belt
	{
		name = "MVS_belt";
		displayName = "MVS_belt";
		ghostIcon = "hips";
	};
	class Slot_RottensRadio
	{
		name="RottensRadio";
		displayName = "RottensRadio";
		ghostIcon = "walkietalkie";
	};
	class Slot_MVS_Screwdriver
	{
		name="MVS_Screwdriver";
		displayName = "MVS_Screwdriver";
		ghostIcon = "";
	};
	class Slot_MVS_Pliers
	{
		name="MVS_Pliers";
		displayName = "MVS_Pliers";
		ghostIcon = "";
	};
	class Slot_Screwdriver1
	{
		name="Screwdriver1";
		displayName = "Screwdriver1";
		ghostIcon = "";
	};
	class Slot_Pliers1
	{
		name="Pliers1";
		displayName = "Pliers1";
		ghostIcon = "";
	};
	class Slot_MVS_Lockpick
	{
		name="MVS_Lockpick";
		displayName = "MVS_Lockpick";
		ghostIcon = "";
	};
	class Slot_MVS_Altyn_Visor
	{
		name="MVS_Altyn_Visor";
		displayName = "MVS_Altyn_Visor";
		ghostIcon = "gorkavisor";
	};
	class Slot_MVS_C4_Charge
	{
		name="MVS_C4_Charge";
		displayName = "MVS_C4_Charge";
		ghostIcon = "";
	};
	class Slot_MVS_C4_Charge2
	{
		name="MVS_C4_Charge2";
		displayName = "MVS_C4_Charge2";
		ghostIcon = "";
	};
	class Slot_MVS_C4_Charge3
	{
		name="MVS_C4_Charge3";
		displayName = "MVS_C4_Charge3";
		ghostIcon = "";
	};
	class Slot_MVS_C4_Charge4
	{
		name="MVS_C4_Charge4";
		displayName = "MVS_C4_Charge4";
		ghostIcon = "";
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyMVS_Altyn_Helmet_Visor: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MVS_Altyn_Visor";
		model = "\SausageCo\MVS Data\helmets\MVS_Altyn_Helmet_Visor.p3d";
	};	
	class Proxymodular_pouch_2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "modular_pouch_2";
		model = "\SausageCo\MVS Data\modular_pouch_2.p3d";
	};
	class Proxymodular_pouch_4: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "modular_pouch_4";
		model = "\SausageCo\MVS Data\modular_pouch_4.p3d";
	};
	
	class Proxymodular_pouch_5: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "modular_pouch_5";
		model = "\SausageCo\MVS Data\modular_pouch_5.p3d";
	};
	class Proxymodular_pouch_6: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "modular_pouch_6";
		model = "\SausageCo\MVS Data\modular_pouch_6.p3d";
	};
	class Proxymodular_pouch_8: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "modular_pouch_8";
		model = "\SausageCo\MVS Data\modular_pouch_8.p3d";
	};
	class Proxymodular_pouch_9: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "modular_pouch_9";
		model = "\SausageCo\MVS Data\modular_pouch_9.p3d";
	};
	class Proxymodular_pouch_10: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "modular_pouch_10";
		model = "\SausageCo\MVS Data\modular_pouch_10.p3d";
	};
	class Proxymodular_pouch_11: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "modular_pouch_11";
		model = "\SausageCo\MVS Data\modular_pouch_11.p3d";
	};
	class Proxymodular_pouch_12: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "modular_pouch_12";
		model = "\SausageCo\MVS Data\modular_pouch_12.p3d";
	};
	class Proxymodular_pouch_13: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "modular_pouch_13";
		model = "\SausageCo\MVS Data\modular_pouch_13.p3d";
	};
	class Proxymodular_weapon: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Shoulder";
		model = "\SausageCo\MVS Data\modular_weapon.p3d";
	};
	class Proxymodular_weapon_rack: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Shoulder";
		model = "\SausageCo\MVS Data\modular_weapon_rack.p3d";
	};
	class ProxyMorphine: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "morphine";
		model = "\DZ\gear\medical\Morphine.p3d";
	};
	class ProxyEpinephrine: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "epinephrine";
		model = "\DZ\gear\medical\Epinephrine.p3d";
	};
	class ProxyBandage: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MedicalBandage";
		model = "\DZ\gear\medical\Bandage.p3d";
	};
	class ProxyspawnVest: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MVS_vest";
		model = "\SausageCo\MVS Data\ArmorRack\spawnVest.p3d";
	};
	class ProxyspawnHeadgear: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MVS_helmet";
		model = "\SausageCo\MVS Data\ArmorRack\spawnHeadgear.p3d";
	};
	class ProxyspawnMask: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MVS_mask";
		model = "\SausageCo\MVS Data\ArmorRack\spawnMask.p3d";
	};
	class ProxyspawnPack: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MVS_pack";
		model = "\SausageCo\MVS Data\ArmorRack\spawnPack.p3d";
	};
	class ProxyspawnBelt: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MVS_belt";
		model = "\SausageCo\MVS Data\ArmorRack\spawnBelt.p3d";
	};
	class Proxypatch: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "patch_01";
		model = "\SausageCo\MVS Data\patch.p3d";
	};
	class Proxypatch_01: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "patch_02";
		model = "\SausageCo\MVS Data\patch_01.p3d";
	};
	/*
	class ProxyCombatPatch: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "patch_02";
		model = "\SausageCo\MVS Data\uniforms\CombatPatch.p3d";
	};
	*/
	class Proxypatch_02: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "patch_03";
		model = "\SausageCo\MVS Data\patch_02.p3d";
	};
	class Proxypatch_03: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "patch_04";
		model = "\SausageCo\MVS Data\patch_03.p3d";
	};	
	class ProxyMVS_Mag: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine4";
		model = "\SausageCo\MVS Data\MVS_Mag.p3d";
	};
	class ProxyMVS_Mag2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine5";
		model = "\SausageCo\MVS Data\MVS_Mag2.p3d";
	};
	class ProxyMVS_MagPistol: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine7";
		model = "\SausageCo\MVS Data\MVS_MagPistol.p3d";
	};
	
	class ProxyMVS_Pliers: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Pliers1";
		model = "\SausageCo\MVS Data\MVS_Pliers.p3d";
	};
	class ProxyMVS_Screwdriver: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Screwdriver1";
		model = "\SausageCo\MVS Data\MVS_Screwdriver.p3d";
	};
	class ProxyMVS_Lockpick: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MVS_Lockpick";
		model = "\SausageCo\MVS Data\MVS_Lockpick.p3d";
	};
	class ProxyRottensRadio: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "RottensRadio";
		model = "\SausageCo\MVS Data\Pack\RottensRadio.p3d";
	};
	class ProxyMVS_Comtacs_g: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MVS_Comtacs";
		model = "\SausageCo\MVS Data\Helmets\MVS_Comtacs_g.p3d";
	};
	class ProxyMVS_C4_Charge: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MVS_C4_Charge";
		model = "\SausageCo\MVS Data\MVS_C4_Charge.p3d";
	};
	class ProxyMVS_C4_Charge2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MVS_C4_Charge2";
		model = "\SausageCo\MVS Data\MVS_C4_Charge2.p3d";
	};
	class ProxyMVS_C4_Charge3: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MVS_C4_Charge3";
		model = "\SausageCo\MVS Data\MVS_C4_Charge3.p3d";
	};
	class ProxyMVS_C4_Charge4: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "MVS_C4_Charge4";
		model = "\SausageCo\MVS Data\MVS_C4_Charge4.p3d";
	};
};