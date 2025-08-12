class CfgPatches
{
	class DZ_SausageCoModular_Belt
	{
		units[]={
			""
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
	// class Slot_Magazine45ACP
	// {
		// name="Magazine45ACP";
		// displayName="45ACP"; 
		// ghostIcon="magazine";
		// stackMax=8;
		// show="true";
	// };
};
class CfgVehicles
{
	class Inventory_Base;
	class Clothing_Base;
	class SausageCo_ModularBeltSystem: Clothing_Base
	{
		scope=2;
		displayName="SausageCo ModularBelt";
		visibilityModifier=0.85000002;
		descriptionShort="A Modular Belt that takes an extra holster, a Pouch, AmmoCrate, and a medkit.";
		model="\DZ\characters\belts\mil_belt_g.p3d";
		attachments[]=
		{
			"Belt_Back",
			"Belt_Right",
			"Belt_Left",
			"VestHolster",
			"VestPouch",
			"SausageAmmo",
			"SausageAid"
			
		};
		vehicleClass="Clothing";
		simulation="clothing";
		quickBarBonus=12;
		inventorySlot[]=
		{
			"Hips"
		};
		itemInfo[]=
		{
			"Clothing",
			"Hips"
		};
		itemSize[]={3,2};
		weight=20;
		lootCategory="Crafted";
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0,0,0,1.0,co)",
			"#(argb,8,8,3)color(0,0,0,1.0,co)",
			"#(argb,8,8,3)color(0,0,0,1.0,co)"
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
								"DZ\characters\belts\data\mil_belt.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\belts\data\mil_belt.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\belts\data\mil_belt_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\belts\data\mil_belt_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\characters\belts\data\mil_belt_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\DZ\characters\belts\mil_belt_m.p3d";
			female="\DZ\characters\belts\mil_belt_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="WorkingGloves_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="WorkingGloves_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};
