class CfgPatches
{
	class SausageClothes_Storage
	{
		units[]=
		{
			"CraftedLargeBag",
			"CraftedMediumBag",
			"CraftedSmallBag",
			"CraftedSmallShoe",
			"CraftedSmallBelt",
			"CraftedSmallGloves",
			"CraftedLargeVest",
			"CraftedMediumVest",
			"CraftedSmallVest",
			"CraftedLargePants",
			"CraftedMediumPants",
			"CraftedSmallPants",
			"CraftedLargeShirt",
			"CraftedMediumShirt",
			"CraftedSmallShirt"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Consumables",
			"DZ_Structures",
			"DZ_Scripts"
		};
	};
};
class CfgSlots
{
	class Slot_Shoulder1
	{
		name="Shoulder1";
		displayName="Shoulder1";
		ghostIcon="shoulderleft";
		show="true";
	};
	class Slot_Shoulder2
	{
		name="Shoulder2";
		displayName="Shoulder2";
		ghostIcon="shoulderleft";
		show="true";
	};
	class Slot_Shoulder3
	{
		name="Shoulder3";
		displayName="Shoulder3";
		ghostIcon="shoulderleft";
		show="true";
	};
	class Slot_Shoulder4
	{
		name="Shoulder4";
		displayName="Shoulder4";
		ghostIcon="shoulderleft";
		show="true";
	};
	class Slot_Shoulder5
	{
		name="Shoulder5";
		displayName="Shoulder5";
		ghostIcon="shoulderleft";
		show="true";
	};
	
};
class CfgVehicles
{	
	class Container_Base;
	class Inventory_Base;
	class Clothing_Base;
	class Clothing: Clothing_Base
	{
	};
	class CargoPants_ColorBase: Clothing
	{
		visibilityModifier=0.85000002;
	};
	class Starters_CargoPants: CargoPants_ColorBase
	{
		scope=2;
		visibilityModifier=0.89999998;
		itemSize[]={4,4};
		itemsCargoSize[]={8,8};
		heatIsolation=0.4;
		varWetMax=0.36;
		absorbency=0;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\Starters\starterpants.paa",
			"SausageCo\storage\Clothes\Starters\starterpants.paa",
			"SausageCo\storage\Clothes\Starters\starterpants.paa"
		};
	};
	class TShirt_ColorBase: Clothing
	{
		visibilityModifier=0.85000002;
	};
	class Starters_TShirt: TShirt_ColorBase
	{
		scope=2;
		visibilityModifier=1;
		itemSize[]={3,3};
		itemsCargoSize[]={6,6};
		heatIsolation=0.4;
		varWetMax=0.36;
		absorbency=0;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\Starters\startertshirt.paa",
			"SausageCo\storage\Clothes\Starters\startertshirt.paa",
			"SausageCo\storage\Clothes\Starters\startertshirt.paa"
		};
	};
	class BalaclavaMask_ColorBase: Clothing
	{
		visibilityModifier=0.85000002;
	};
	class Nomad_Skull_Balaclava: BalaclavaMask_ColorBase
	{
		scope=2;
		displayName="Nomad BALACLAVA";
		descriptionShort="Skull balaclava made by Nomad";
		repairCosts[]={50,10};
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		color="roninblackskull";
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\RONIN_MOD\data\balaclava_black_test1_co.paa",
			"SausageCo\storage\Clothes\RONIN_MOD\data\balaclava_black_test1_co.paa",
			"SausageCo\storage\Clothes\RONIN_MOD\data\balaclava_black_test1_co.paa"
		};
	};
	class Bandana_ColorBase: Clothing
	{
		visibilityModifier=0.85000002;
	};
	class Nomad_Skull_Bandana: Bandana_ColorBase
	{
		scope=2;
		displayName="Nomad BANDANA";
		descriptionShort="Skull bandana made by Nomad";
		repairCosts[]={50,10};
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		hiddenSelectionsTextures[]=
		{
            "SausageCo\storage\Clothes\RONIN_MOD\data\bandanafhg_skull_co.paa",
            "SausageCo\storage\Clothes\RONIN_MOD\data\bandanafhg_skull_co.paa",
            "SausageCo\storage\Clothes\RONIN_MOD\data\bandanafhg_skull_co.paa",
            "SausageCo\storage\Clothes\RONIN_MOD\data\bandanafhg_skull_co.paa",
            "SausageCo\storage\Clothes\RONIN_MOD\data\bandanafhg_skull_co.paa"
		};
	};
	class LeatherPants_ColorBase: Clothing
	{
		displayName="$STR_CfgVehicles_LeatherPants_ColorBase0";
		visibilityModifier=0.85000002;
		descriptionShort="$STR_CfgVehicles_LeatherPants_ColorBase1";
		model="\DZ\characters\pants\Pants_LeatherPants_g.p3d";
		inventorySlot[]=
		{
			"Legs"
		};
		simulation="clothing";
		itemInfo[]=
		{
			"Clothing",
			"Legs"
		};
		lootCategory="Crafted";
		itemSize[]={4,4};
		itemsCargoSize[]={6,4};
		weight=590;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		rotationFlags=16;
		quickBarBonus=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class ClothingTypes
		{
			male="\DZ\characters\pants\Pants_LeatherPants_m.p3d";
			female="\DZ\characters\pants\Pants_LeatherPants_f.p3d";
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
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.69999999;
					};
					class Blood
					{
						damage=0.60000002;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.69999999;
					};
					class Blood
					{
						damage=0.60000002;
					};
					class Shock
					{
						damage=0.80000001;
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
	class CraftedLargePants: LeatherPants_ColorBase
	{
		scope=2;
		displayName="Large Leather Pants";
		descriptionShort=" Crafted Leather Pants";
		visibilityModifier=0.85000002;
		color="Natural";
		itemSize[]={3,3};
		itemsCargoSize[]={10,20};
		weight=590;
		quickBarBonus=4;
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
			"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
			"SausageCo\storage\Clothes\data\myfuckingpants.rvmat"
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.29999999;
					};
					class Blood
					{
						damage=0.20000002;
					};
					class Shock
					{
						damage=0.20000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.29999999;
					};
					class Blood
					{
						damage=0.20000002;
					};
					class Shock
					{
						damage=0.20000001;
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
	class CraftedMediumPants: LeatherPants_ColorBase
	{
		scope=2;
		displayName="Medium Leather Pants";
		descriptionShort=" Crafted Leather Pants";
		visibilityModifier=0.85000002;
		color="Natural";
		itemSize[]={3,3};
		itemsCargoSize[]={10,15};
		weight=590;
		quickBarBonus=3;
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
			"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
			"SausageCo\storage\Clothes\data\myfuckingpants.rvmat"
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints=600;
					healthLevels[]=
					{
						
						{
							1,
							
							{					
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.49999999;
					};
					class Blood
					{
						damage=0.40000002;
					};
					class Shock
					{
						damage=0.40000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.49999999;
					};
					class Blood
					{
						damage=0.40000002;
					};
					class Shock
					{
						damage=0.40000001;
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
	class CraftedSmallPants: LeatherPants_ColorBase
	{
		scope=2;
		displayName="Small Leather Pants";
		descriptionShort=" Crafted Leather Pants";
		visibilityModifier=0.85000002;
		color="Natural";
		itemSize[]={3,3};
		itemsCargoSize[]={10,10};
		weight=590;
		quickBarBonus=2;
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
			"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
			"SausageCo\storage\Clothes\data\myfuckingpants.rvmat"
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat",
								"SausageCo\storage\Clothes\data\myfuckingpants.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.69999999;
					};
					class Blood
					{
						damage=0.60000002;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.69999999;
					};
					class Blood
					{
						damage=0.60000002;
					};
					class Shock
					{
						damage=0.80000001;
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
	class CraftedLargePants_black: CraftedLargePants
	{
		displayName="LargeRoninBlackPants";
		descriptionShort="Ronin made these pants, so fucking like it! Look at the butthole, there is a vagina.";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\data\leatherpant_black_co.paa",
			"SausageCo\storage\Clothes\data\leatherpant_black_co.paa",
			"SausageCo\storage\Clothes\data\leatherpant_black_co.paa"
		};
	};
	class CraftedMediumPants_black: CraftedMediumPants
	{
		displayName="MediumRoninBlackPants";
		descriptionShort="Ronin made these pants, so fucking like it! Look at the butthole, there is a vagina.";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\data\leatherpant_black_co.paa",
			"SausageCo\storage\Clothes\data\leatherpant_black_co.paa",
			"SausageCo\storage\Clothes\data\leatherpant_black_co.paa"
		};
	};
	class CraftedSmallPants_black: CraftedSmallPants
	{
		displayName="SmallRoninBlackPants";
		descriptionShort="Ronin made these pants, so fucking like it! Look at the butthole, there is a vagina.";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\data\leatherpant_black_co.paa",
			"SausageCo\storage\Clothes\data\leatherpant_black_co.paa",
			"SausageCo\storage\Clothes\data\leatherpant_black_co.paa"
		};
	};
	class LeatherJacket_ColorBase: Clothing
	{
		displayName="$STR_CfgVehicles_LeatherJacket_ColorBase0";
		visibilityModifier=0.85000002;
		descriptionShort="$STR_CfgVehicles_LeatherJacket_ColorBase1";
		model="\DZ\characters\tops\Top_LeatherJacket_g.p3d";
		inventorySlot[]=
		{
			"Body"
		};
		itemInfo[]=
		{
			"Clothing",
			"Body"
		};
		weight=3100;
		itemSize[]={4,4};
		itemsCargoSize[]={7,6};
		quickBarBonus=3;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		durability=0.5;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		soundAttType="LeatherJacket";
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
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
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.69999999;
					};
					class Blood
					{
						damage=0.60000002;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.69999999;
					};
					class Blood
					{
						damage=0.60000002;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\DZ\characters\tops\Top_LeatherJacket_m.p3d";
			female="\DZ\characters\tops\Top_LeatherJacket_f.p3d";
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
	class CraftedLargeShirt: LeatherJacket_ColorBase
	{
		scope=2;
		displayName="Large Leather Shirt";
		descriptionShort="A Crafted Leather Shirt";
		visibilityModifier=0.85000002;
		weight=1400;
		itemSize[]={3,3};
		itemsCargoSize[]={10,20};
		quickBarBonus=4;
		hiddenSelectionsMaterials[]=
		{
			"DZ\characters\tops\data\Top_LeatherJacket_g_natural.rvmat",
			"DZ\characters\tops\data\Top_LeatherJacket_natural.rvmat",
			"DZ\characters\tops\data\Top_LeatherJacket_natural.rvmat"
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\tops\data\Top_LeatherJacket_g_natural.rvmat",
								"DZ\characters\tops\data\Top_LeatherJacket_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\tops\Data\Top_LeatherJacket_g_natural_damage.rvmat",
								"DZ\characters\tops\Data\Top_LeatherJacket_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\tops\Data\Top_LeatherJacket_g_natural_destruct.rvmat",
								"DZ\characters\tops\Data\Top_LeatherJacket_natural_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.29999999;
					};
					class Blood
					{
						damage=0.20000002;
					};
					class Shock
					{
						damage=0.20000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.29999999;
					};
					class Blood
					{
						damage=0.20000002;
					};
					class Shock
					{
						damage=0.20000001;
					};
				};
			};
		};
	};
	class CraftedMediumShirt: LeatherJacket_ColorBase
	{
		scope=2;
		displayName="Medium Leather Shirt";
		descriptionShort="A Crafted Leather Shirt";
		visibilityModifier=0.85000002;
		weight=1200;
		itemSize[]={3,3};
		itemsCargoSize[]={10,15};
		quickBarBonus=3;
		hiddenSelectionsMaterials[]=
		{
			"DZ\characters\tops\data\Top_LeatherJacket_g_natural.rvmat",
			"DZ\characters\tops\data\Top_LeatherJacket_natural.rvmat",
			"DZ\characters\tops\data\Top_LeatherJacket_natural.rvmat"
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\tops\data\Top_LeatherJacket_g_natural.rvmat",
								"DZ\characters\tops\data\Top_LeatherJacket_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\tops\Data\Top_LeatherJacket_g_natural_damage.rvmat",
								"DZ\characters\tops\Data\Top_LeatherJacket_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\tops\Data\Top_LeatherJacket_g_natural_destruct.rvmat",
								"DZ\characters\tops\Data\Top_LeatherJacket_natural_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.49999999;
					};
					class Blood
					{
						damage=0.40000002;
					};
					class Shock
					{
						damage=0.40000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.49999999;
					};
					class Blood
					{
						damage=0.40000002;
					};
					class Shock
					{
						damage=0.40000001;
					};
				};
			};
		};
	};
	class CraftedSmallShirt: LeatherJacket_ColorBase
	{
		scope=2;
		displayName="Small Leather Shirt";
		descriptionShort="A Crafted Leather Shirt";
		visibilityModifier=0.85000002;
		weight=600;
		itemSize[]={3,3};
		itemsCargoSize[]={10,10};
		quickBarBonus=2;
		hiddenSelectionsMaterials[]=
		{
			"DZ\characters\tops\data\Top_LeatherJacket_g_natural.rvmat",
			"DZ\characters\tops\data\Top_LeatherJacket_natural.rvmat",
			"DZ\characters\tops\data\Top_LeatherJacket_natural.rvmat"
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\tops\data\Top_LeatherJacket_g_natural.rvmat",
								"DZ\characters\tops\data\Top_LeatherJacket_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\tops\Data\Top_LeatherJacket_g_natural_damage.rvmat",
								"DZ\characters\tops\Data\Top_LeatherJacket_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\tops\Data\Top_LeatherJacket_g_natural_destruct.rvmat",
								"DZ\characters\tops\Data\Top_LeatherJacket_natural_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.69999999;
					};
					class Blood
					{
						damage=0.60000002;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.69999999;
					};
					class Blood
					{
						damage=0.60000002;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
			};
		};
	};
	class CraftedLargeShirt_black: CraftedLargeShirt
	{
		displayName="LargeRoninBlackShirt";
		descriptionShort="Ronin made this Shirt, so fucking like it! Look at the boobs...";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\data\top_leathershirt_black_co.paa",
			"SausageCo\storage\Clothes\data\top_leathershirt_black_co.paa",
			"SausageCo\storage\Clothes\data\top_leathershirt_black_co.paa"
		};
	};
	class CraftedMediumShirt_black: CraftedMediumShirt
	{
		displayName="MediumRoninBlackShirt";
		descriptionShort="Ronin made this Shirt, so fucking like it! Look at the boobs...";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\data\top_leathershirt_black_co.paa",
			"SausageCo\storage\Clothes\data\top_leathershirt_black_co.paa",
			"SausageCo\storage\Clothes\data\top_leathershirt_black_co.paa"
		};
	};
	class CraftedSmallShirt_black: CraftedSmallShirt
	{
		displayName="SmallRoninBlackShirt";
		descriptionShort="Ronin made this Shirt, so fucking like it! Look at the boobs...";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\data\top_leathershirt_black_co.paa",
			"SausageCo\storage\Clothes\data\top_leathershirt_black_co.paa",
			"SausageCo\storage\Clothes\data\top_leathershirt_black_co.paa"
		};
	};
	class LeatherStorageVest_ColorBase: Clothing
	{
		displayName="$STR_CfgVehicles_LeatherStorageVest_ColorBase0";
		visibilityModifier=0.85000002;
		descriptionShort="$STR_CfgVehicles_LeatherStorageVest_ColorBase1";
		model="\DZ\characters\vests\Vest_LeatherStorage_g.p3d";
		inventorySlot[]=
		{
			"Vest"
		};
		attachments[]=
		{
			"VestGrenadeA",
			"VestGrenadeC"
		};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Vest"
		};
		weight=2800;
		itemSize[]={4,3};
		itemsCargoSize[]={7,5};
		quickBarBonus=3;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		lootCategory="Crafted";
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
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
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.69999999;
					};
					class Blood
					{
						damage=0.60000002;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.69999999;
					};
					class Blood
					{
						damage=0.60000002;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\DZ\characters\vests\Vest_LeatherStorage_m.p3d";
			female="\DZ\characters\vests\Vest_LeatherStorage_f.p3d";
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
	class CraftedLargeVest: LeatherStorageVest_ColorBase
	{
		scope=2;
		displayName="A Large Leather Vest";
		descriptionShort="A Crafted Leather Vest";
		attachments[]=
		{
			"VestGrenadeA",
			"VestGrenadeB",
			"VestGrenadeC",
			"VestGrenadeD"
		};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Vest"
		};
		weight=2800;
		itemSize[]={3,3};
		itemsCargoSize[]={10,20};
		quickBarBonus=6;
		visibilityModifier=0.85000002;
		hiddenSelectionsMaterials[]=
		{
			"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat",
			"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat",
			"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\vests\Data\Vest_LeatherStorage_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\vests\Data\Vest_LeatherStorage_natural_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.29999999;
					};
					class Blood
					{
						damage=0.20000002;
					};
					class Shock
					{
						damage=0.20000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.29999999;
					};
					class Blood
					{
						damage=0.20000002;
					};
					class Shock
					{
						damage=0.20000001;
					};
				};
			};
		};
	};
	class CraftedMediumVest: LeatherStorageVest_ColorBase
	{
		scope=2;
		displayName="A Medium Leather Vest";
		descriptionShort="A Crafted Leather Vest";
		attachments[]=
		{
			"VestGrenadeA",
			"VestGrenadeB",
			"VestGrenadeC"
		};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Vest"
		};
		weight=2800;
		itemSize[]={3,3};
		itemsCargoSize[]={10,15};
		quickBarBonus=4;
		visibilityModifier=0.85000002;
		hiddenSelectionsMaterials[]=
		{
			"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat",
			"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat",
			"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\vests\Data\Vest_LeatherStorage_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\vests\Data\Vest_LeatherStorage_natural_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.49999999;
					};
					class Blood
					{
						damage=0.40000002;
					};
					class Shock
					{
						damage=0.40000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.49999999;
					};
					class Blood
					{
						damage=0.40000002;
					};
					class Shock
					{
						damage=0.40000001;
					};
				};
			};
		};
	};
	class CraftedSmallVest: LeatherStorageVest_ColorBase
	{
		scope=2;
		displayName="A Small Leather Vest";
		descriptionShort="A Crafted Leather Vest";
		attachments[]=
		{
			"VestGrenadeA",
			"VestGrenadeC"
		};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Vest"
		};
		weight=2800;
		itemSize[]={3,3};
		itemsCargoSize[]={10,10};
		quickBarBonus=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsMaterials[]=
		{
			"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat",
			"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat",
			"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\vests\Data\Vest_LeatherStorage_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\vests\Data\Vest_LeatherStorage_natural_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.69999999;
					};
					class Blood
					{
						damage=0.60000002;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.69999999;
					};
					class Blood
					{
						damage=0.60000002;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
			};
		};
	};
	
	class CraftedLargeVest_black: CraftedLargeVest
	{
		displayName="LargeRoninBlackVest";
		descriptionShort="Ronin made this Vest, so fucking like it! Look at the boobs...";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\data\crafted_leather_vest_black_co.paa",
			"SausageCo\storage\Clothes\data\crafted_leather_vest_black_co.paa",
			"SausageCo\storage\Clothes\data\crafted_leather_vest_black_co.paa"
		};
	};
	class CraftedMediumVest_black: CraftedMediumVest
	{
		displayName="MediumRoninBlackVest";
		descriptionShort="Ronin made this Vest, so fucking like it! Look at the boobs...";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\data\crafted_leather_vest_black_co.paa",
			"SausageCo\storage\Clothes\data\crafted_leather_vest_black_co.paa",
			"SausageCo\storage\Clothes\data\crafted_leather_vest_black_co.paa"
		};
	};
	class CraftedSmallVest_black: CraftedSmallVest
	{
		displayName="SmallRoninBlackVest";
		descriptionShort="Ronin made this Vest, so fucking like it! Look at the boobs...";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\data\crafted_leather_vest_black_co.paa",
			"SausageCo\storage\Clothes\data\crafted_leather_vest_black_co.paa",
			"SausageCo\storage\Clothes\data\crafted_leather_vest_black_co.paa"
		};
	};
	class LeatherGloves_ColorBase: Clothing
	{
		scope=0;
		visibilityModifier=0.85000002;
		displayName="Crafted Leather Gloves";
		descriptionShort="A crafted pair of leather gloves";
		model="\DZ\characters\gloves\leather_gloves_g.p3d";
		inventorySlot[]=
		{
			"Gloves"
		};
		simulation="clothing";
		itemInfo[]=
		{
			"Clothing",
			"Gloves"
		};
		rotationFlags=34;
		weight=200;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		itemSize[]={1,1};
		repairableWithKits[]={5};
		repairCosts[]={30};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale",
			"personality"
		};
		class ClothingTypes
		{
			male="\DZ\characters\gloves\leather_gloves_m.p3d";
			female="\DZ\characters\gloves\leather_gloves_f.p3d";
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
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
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
	class CraftedSmallGloves: LeatherGloves_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsMaterials[]=
		{
			"DZ\Characters\gloves\data\leather_gloves_Natural.rvmat",
			"DZ\Characters\gloves\data\leather_gloves_Natural.rvmat",
			"DZ\Characters\gloves\data\leather_gloves_Natural.rvmat"
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\gloves\data\leather_gloves_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\gloves\Data\leather_gloves_Natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\gloves\Data\leather_gloves_Natural_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class LeatherBelt_ColorBase: Clothing
	{
		scope=0;
		visibilityModifier=0.85000002;
		displayName="Crafted Leather Belt";
		descriptionShort="A crafted leather belt.";
		model="\DZ\characters\belts\belt_leather_g.p3d";
		attachments[]=
		{
			"Belt_Back",
			"Belt_Right",
			"Belt_Left"
		};
		vehicleClass="Clothing";
		simulation="clothing";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		inventorySlot[]=
		{
			"Hips"
		};
		itemInfo[]=
		{
			"Clothing",
			"Hips"
		};
		itemSize[]={2,1};
		weight=20;
		lootCategory="Crafted";
		lootTag[]=
		{
			"Civilian"
		};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\dz\characters\belts\data\belt_leather_co.paa",
			"\dz\characters\belts\data\belt_leather_co.paa",
			"\dz\characters\belts\data\belt_leather_co.paa"
		};
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\belts\data\belt_leather_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\belts\data\belt_leather_natural.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\belts\data\belt_leather_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\belts\data\belt_leather_natural_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\characters\belts\data\belt_leather_natural_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\DZ\characters\belts\belt_leather_m.p3d";
			female="\DZ\characters\belts\belt_leather_f.p3d";
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
	class CraftedSmallBelt: LeatherBelt_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsMaterials[]=
		{
			"DZ\characters\belts\data\belt_leather_natural.rvmat",
			"DZ\characters\belts\data\belt_leather_natural.rvmat",
			"DZ\characters\belts\data\belt_leather_natural.rvmat"
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\belts\data\belt_leather_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\belts\data\belt_leather_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\belts\data\belt_leather_natural_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class LeatherShoes_ColorBase: Clothing
	{
		displayName="Small Leather Shoes";
		visibilityModifier=0.85000002;
		descriptionShort="A crafted leather shoe";
		model="\DZ\characters\shoes\Shoes_LeatherMoccasins_g.p3d";
		inventorySlot[]=
		{
			"Feet"
		};
		itemInfo[]=
		{
			"Clothing",
			"Feet"
		};
		itemSize[]={2,1};
		weight=380;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		durability=0.5;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		soundAttType="Boots";
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\characters\shoes\data\Shoes_LeatherMoccasins_CO.paa",
			"\DZ\characters\shoes\data\Shoes_LeatherMoccasins_CO.paa",
			"\DZ\characters\shoes\data\Shoes_LeatherMoccasins_CO.paa"
		};
		class ClothingTypes
		{
			male="\DZ\characters\shoes\Shoes_LeatherMoccasins_m.p3d";
			female="\DZ\characters\shoes\Shoes_LeatherMoccasins_f.p3d";
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
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.80000001;
					};
					class Blood
					{
						damage=0.80000001;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.80000001;
					};
					class Blood
					{
						damage=0.80000001;
					};
					class Shock
					{
						damage=0.80000001;
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
					soundSet="AthleticShoes_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="AthleticShoes_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class CraftedSmallShoe: LeatherShoes_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsMaterials[]=
		{
			"DZ\characters\shoes\data\Shoes_LeatherMoccasins_natural.rvmat",
			"DZ\characters\shoes\data\Shoes_LeatherMoccasins_natural.rvmat",
			"DZ\characters\shoes\data\Shoes_LeatherMoccasins_natural.rvmat"
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\shoes\data\Shoes_LeatherMoccasins_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\shoes\Data\Shoes_LeatherMoccasins_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\shoes\Data\Shoes_LeatherMoccasins_natural_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor: GlobalArmor
			{
			};
		};
	};
	class LeatherSack_ColorBase: Clothing
	{
		displayName="$STR_cfgVehicles_LeatherSack_ColorBase0";
		visibilityModifier=0.85000002;
		descriptionShort="$STR_cfgVehicles_LeatherSack_ColorBase1";
		model="\dz\characters\backpacks\Bag_LeatherSack_g.p3d";
		inventorySlot[]=
		{
			"Back"
		};
		attachments[]=
		{
			"Chemlight",
			"WalkieTalkie",
			"Shoulder1",
			"Shoulder2",
			"Shoulder3"
		};
		itemInfo[]=
		{
			"Clothing",
			"Back"
		};
		lootCategory="Crafted";
		rotationFlags=2;
		itemSize[]={3,3};
		itemsCargoSize[]={10,7};
		weight=1300;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		canBeDigged=1;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class ClothingTypes
		{
			male="\DZ\characters\backpacks\Bag_LeatherSack_m.p3d";
			female="\DZ\characters\backpacks\Bag_LeatherSack_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpBackPack_Leather_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBackPack_Leather_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="taloonbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class CraftedLargeBag: LeatherSack_ColorBase
	{
		scope=2;
		displayName="Large Leather Bag";
		descriptionShort="A Crafted Large Leather Bag.";
		color="Natural";
		visibilityModifier=0.75;
		quickBarBonus=6;
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\backpacks\data\Bag_LeatherSack_natural.rvmat",
			"dz\characters\backpacks\data\Bag_LeatherSack_natural.rvmat",
			"dz\characters\backpacks\data\Bag_LeatherSack_natural.rvmat"
		};
		attachments[]=
		{
			"Chemlight",
			"WalkieTalkie",
			"Shoulder1",
			"Shoulder2",
			"Shoulder3"
		};
		itemSize[]={3,3};
		itemsCargoSize[]={10,30};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1200;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\backpacks\data\Bag_LeatherSack_natural.rvmat",
								"dz\characters\backpacks\data\Bag_LeatherSack_g_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\backpacks\Data\Bag_LeatherSack_natural_damage.rvmat",
								"dz\characters\backpacks\data\Bag_LeatherSack_g_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\backpacks\Data\Bag_LeatherSack_natural_destruct.rvmat",
								"dz\characters\backpacks\data\Bag_LeatherSack_g_natural_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class CraftedMediumBag: LeatherSack_ColorBase
	{
		scope=2;
		displayName="Medium Leather Bag";
		descriptionShort="A Crafted Medium Leather Bag.";
		color="Natural";
		visibilityModifier=0.75;
		quickBarBonus=4;
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\backpacks\data\Bag_LeatherSack_natural.rvmat",
			"dz\characters\backpacks\data\Bag_LeatherSack_natural.rvmat",
			"dz\characters\backpacks\data\Bag_LeatherSack_natural.rvmat"
		};
		attachments[]=
		{
			"Chemlight",
			"WalkieTalkie",
			"Shoulder1",
			"Shoulder2"
		};
		itemSize[]={3,3};
		itemsCargoSize[]={10,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=600;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\backpacks\data\Bag_LeatherSack_natural.rvmat",
								"dz\characters\backpacks\data\Bag_LeatherSack_g_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\backpacks\Data\Bag_LeatherSack_natural_damage.rvmat",
								"dz\characters\backpacks\data\Bag_LeatherSack_g_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\backpacks\Data\Bag_LeatherSack_natural_destruct.rvmat",
								"dz\characters\backpacks\data\Bag_LeatherSack_g_natural_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class CraftedSmallBag: LeatherSack_ColorBase
	{
		scope=2;
		displayName="Small Leather Bag";
		descriptionShort="A Crafted Small Leather Bag.";
		color="Natural";
		visibilityModifier=0.75;
		quickBarBonus=3;
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\backpacks\data\Bag_LeatherSack_natural.rvmat",
			"dz\characters\backpacks\data\Bag_LeatherSack_natural.rvmat",
			"dz\characters\backpacks\data\Bag_LeatherSack_natural.rvmat"
		};
		attachments[]=
		{
			"Chemlight",
			"WalkieTalkie",
			"Shoulder1"
		};
		itemSize[]={3,3};
		itemsCargoSize[]={10,10};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\backpacks\data\Bag_LeatherSack_natural.rvmat",
								"dz\characters\backpacks\data\Bag_LeatherSack_g_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\backpacks\Data\Bag_LeatherSack_natural_damage.rvmat",
								"dz\characters\backpacks\data\Bag_LeatherSack_g_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\backpacks\Data\Bag_LeatherSack_natural_destruct.rvmat",
								"dz\characters\backpacks\data\Bag_LeatherSack_g_natural_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class CraftedLargeBag_black: CraftedLargeBag
	{
		displayName="LargeRoninBlackBag";
		visibilityModifier=0.85000002;
		descriptionShort="Ronin made this Bag, so fucking like it!Look at the sack";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\data\leatherbag_black_co.paa",
			"SausageCo\storage\Clothes\data\leatherbag_black_co.paa",
			"SausageCo\storage\Clothes\data\leatherbag_black_co.paa"
		};
	};
	class CraftedMediumBag_black: CraftedMediumBag
	{
		displayName="MediumRoninBlackBag";
		visibilityModifier=0.85000002;
		descriptionShort="Ronin made this Bag, so fucking like it!Look at the sack";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\data\leatherbag_black_co.paa",
			"SausageCo\storage\Clothes\data\leatherbag_black_co.paa",
			"SausageCo\storage\Clothes\data\leatherbag_black_co.paa"
		};
	};
	class CraftedSmallBag_black: CraftedSmallBag
	{
		displayName="SmallRoninBlackBag";
		visibilityModifier=0.85000002;
		descriptionShort="Ronin made this Bag, so fucking like it!Look at the sack";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\data\leatherbag_black_co.paa",
			"SausageCo\storage\Clothes\data\leatherbag_black_co.paa",
			"SausageCo\storage\Clothes\data\leatherbag_black_co.paa"
		};
	};
	class NomadBag: CraftedLargeBag_black
	{
		displayName="Nomad Bag";
		descriptionShort="Nomad has a big sack. Here it is, take a look.";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\bag_leathersack_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\bag_leathersack_natural.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\bag_leathersack_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\bag_leathersack_natural_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\bag_leathersack_natural_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class NomadVest: CraftedLargeVest_black
	{
		displayName="Nomad Vest";
		descriptionShort="Nomad has a big Vest. Here it is, take a look.";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\vest_leatherstorage_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\vest_leatherstorage_natural.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\vest_leatherstorage_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\vest_leatherstorage_natural_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\vest_leatherstorage_natural_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class NomadJacket: CraftedLargeShirt_black
	{
		displayName="Nomad Jacket";
		descriptionShort="Nomad has a big Jacket. Here it is, take a look.";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\top_leatherjacket_natural.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\top_leatherjacket_natural.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\top_leatherjacket_natural_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\top_leatherjacket_natural_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\storage\clothes\NomadSet\data\top_leatherjacket_natural_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		visibilityModifier=0.85000002;
	};
	class NomadBoots: CombatBoots_ColorBase
	{
		scope=2;
		displayName="Nomad Boots";
		descriptionShort="Nomad has big Boots. Here it is, take a look.";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\NomadSet\data\nomadBoots.paa",
			"SausageCo\storage\clothes\NomadSet\data\nomadBoots.paa",
			"SausageCo\storage\clothes\NomadSet\data\nomadBoots.paa"
		};
		attachments[]=
		{
			"Knife"
		};
	};
	class NomadPants: CraftedLargePants_black
	{
		displayName="Nomad Pants";
		descriptionShort="Nomad has big Pants. Here it is, take a look.";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class NomadHelm: Mich2001Helmet
	{
		scope=2;
		displayName="Nomad Helm";
		descriptionShort="Nomad has a big Helm. Here it is, take a look.";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Alek";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\NomadSet\data\nomadHelmet.paa",
			"SausageCo\storage\clothes\NomadSet\data\nomadHelmet.paa",
			"SausageCo\storage\clothes\NomadSet\data\nomadHelmet.paa"
		};
	};
	class TacticalGloves_ColorBase: Clothing //GLOVES
	{
		
	};
	class NomadGloves: TacticalGloves_ColorBase
	{
		scope=2;
		displayName="Nomad Gloves";
		descriptionShort="Nomad has big Gloves. Here it is, take a look.";
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Stinky";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\NomadSet\data\nomadGloves.paa",
			"SausageCo\storage\clothes\NomadSet\data\nomadGloves.paa",
			"SausageCo\storage\clothes\NomadSet\data\nomadGloves.paa"
		};
	};
	class SC_DuffleSling: Clothing
	{
		scope=2;
		displayName="Duffle Sling";
		descriptionShort="SausageCo Duffle Sling, capable of holding a bag, weapon, radio, chemlight, and medical pouch.";
		model="SausageCo\storage\Clothes\Sling\DuffleSling_g.p3d";
		inventorySlot[]=
		{
			"Armband"
		};
		quickBarBonus=6;
		attachments[]=
		{
			"Chemlight",
			"WalkieTalkie",
			"Back",
			"Shoulder",
			"SausageAid"
			
		};
		itemInfo[]=
		{
			"Clothing",
			"Armband"
		};
		allowOwnedCargoManipulation=1;
		rotationFlags=16;
		weight=1300;
		itemSize[]={3,2};
		itemsCargoSize[]={0,0};
		visibilityModifier=0.69999999;
		varWetMax=0.79000002;
		heatIsolation=0.5;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		soundAttType="Outdoor";
		randomQuantity=3;
		hiddenSelections[]=
		{
			"cube",
			"cubeMale",
			"cubeFemale"
		};
		class ClothingTypes
		{
			male="SausageCo\storage\Clothes\Sling\DuffleSling_m.p3d";
			female="SausageCo\storage\Clothes\Sling\DuffleSling_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\storage\Clothes\Sling\data\rubber4k.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\storage\Clothes\Sling\data\rubber4k.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\storage\Clothes\Sling\data\rubber4k.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\storage\Clothes\Sling\data\rubber4k.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\storage\Clothes\Sling\data\rubber4k.rvmat"
							}
						}
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
					soundSet="pickUpBackPack_Plastic_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBackPack_Plastic_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="taloonbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class SC_DuffleBag: Clothing
	{
		scope=2;
		displayName="Duffle Bag";
		visibilityModifier=0.85000002;
		descriptionShort="SausageCo Duffle Bag, capable of holding a full set of gear. does not hold a backpack.";
		model="SausageCo\storage\Clothes\Sling\DuffleBag_g.p3d";
		inventorySlot[]=
		{
			"Back"
		};
		attachments[]=
		{
			"Headgear",
			"Mask",
			"Eyewear",
			"Gloves",
			"Body",
			"Armband",
			"Vest",
			"Hips",
			"Legs",
			"Feet"
			
		};
		itemInfo[]=
		{
			"Clothing",
			"Back"
		};
		allowOwnedCargoManipulation=1;
		rotationFlags=16;
		weight=1300;
		itemSize[]={4,4};
		itemsCargoSize[]={5,5};
		varWetMax=0.79000002;
		heatIsolation=0.5;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		soundAttType="Outdoor";
		randomQuantity=3;
		hiddenSelections[]=
		{
			"cube",
			"cubeMale",
			"cubeFemale"
		};
		class ClothingTypes
		{
			male="SausageCo\storage\Clothes\Sling\DuffleBag_m.p3d";
			female="SausageCo\storage\Clothes\Sling\DuffleBag_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\storage\Clothes\Sling\data\duffle.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\storage\Clothes\Sling\data\duffle.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\storage\Clothes\Sling\data\duffle.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\storage\Clothes\Sling\data\duffle.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\storage\Clothes\Sling\data\duffle.rvmat"
							}
						}
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
					soundSet="pickUpBackPack_Plastic_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBackPack_Plastic_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="taloonbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};