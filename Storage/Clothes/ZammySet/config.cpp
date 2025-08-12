class CfgPatches
{
	class SausageClothesZammy
	{
		units[]=
		{
			""
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
class CfgVehicles
{	
	class Inventory_Base;
	class CarDoor: Inventory_Base
	{
		
	};
	class Truck_01_Door_1_1: CarDoor
	{
		hiddenSelections[]=
		{
			"dmgZone_doors",
			"dmgZone_doors_inside"
		};
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.521569,0.427451,0.054902,1.0,co)",
			"#(argb,8,8,3)color(0.521569,0.427451,0.054902,1.0,co)"
		};
	};
	class Truck_01_Door_2_1: Truck_01_Door_1_1
	{
		displayName="$STR_V3SDoors_CoDriver0";
		descriptionShort="$STR_V3SDoors_CoDriver1";
		model="\DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_Door_2_1.p3d";
		inventorySlot[]=
		{
			"Truck_01_Door_2_1"
		};
		rotationFlags=4;
	};
	class Truck_01_Hood: CarDoor
	{
		hiddenSelections[]=
		{
			"dmgZone_doors",
			"camo_door"
		};
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.521569,0.427451,0.054902,1.0,co)",
			"#(argb,8,8,3)color(0.521569,0.427451,0.054902,1.0,co)"
		};
	};
	
	class ZammyTruck_Door_1_1: Truck_01_Door_1_1
	{
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\ZammySet\data\zammyDoor.paa",
			"SausageCo\storage\Clothes\ZammySet\data\zammyDoor.paa"
		};
		
	};
	class ZammyTruck_Door_2_1: ZammyTruck_Door_1_1
	{
		displayName="$STR_V3SDoors_CoDriver0";
		descriptionShort="$STR_V3SDoors_CoDriver1";
		model="\DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_Door_2_1.p3d";
		inventorySlot[]=
		{
			"Truck_01_Door_2_1"
		};
		rotationFlags=4;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\ZammySet\data\zammyDoor.paa",
			"SausageCo\storage\Clothes\ZammySet\data\zammyDoor.paa"
		};
		
	};
	class ZammyTruck_Hood: Truck_01_Hood
	{
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\ZammySet\data\zammyHood.paa",
			"SausageCo\storage\Clothes\ZammySet\data\zammyHood.paa"
		};
		
	};
	class Clothing_Base;
	class Container_Base;
	class WoodAxe: Inventory_Base{};
	class ZammyAxe: WoodAxe
	{
		scope=2;
		displayName="Zammy Medieval Axe";
		descriptionShort="A medieval axe from the Zammy Dinesty";
		model="\SausageCo\storage\Clothes\ZammySet\ZammyAxe.p3d";
		repairableWithKits[]={4};
		repairCosts[]={20};
		rotationFlags=12;
		weight=1360;
		itemSize[]={1,3};
		itemBehaviour=2;
		fragility=0.0099999998;
		inventorySlot[]=
		{
			"Shoulder",
			"Melee"
		};
		lootCategory="Tools";
		lootTag[]=
		{
			"Work",
			"Forester",
			"Camping"
		};
		dismantle_action_type=74;
		openItemSpillRange[]={20,40};
		itemInfo[]=
		{
			"Axe"
		};
		isMeleeWeapon=1;
		suicideAnim="woodaxe";
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeAxe";
				range=1.8;
			};
			class Heavy
			{
				ammo="MeleeAxe_Heavy";
				range=1.8;
			};
			class Sprint
			{
				ammo="MeleeAxe_Heavy";
				range=3.7;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=750;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								
							}
						},
						
						{
							0.69999999,
							
							{
								
							}
						},
						
						{
							0.5,
							
							{
								
							}
						},
						
						{
							0.30000001,
							
							{
								
							}
						},
						
						{
							0,
							
							{
								
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
				class pickup_light
				{
					soundSet="hatchet_pickup_light_SoundSet";
					id=796;
				};
				class pickup
				{
					soundSet="hatchet_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="woodaxe_drop_SoundSet";
					id=898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet="FirefighterAxe_loop_SoundSet";
					id=1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet="FirefighterAxe_end_SoundSet";
					id=1122;
				};
				class ShoulderR_Hide
				{
					soundset="ShoulderR_Hide_SoundSet";
					id=1210;
				};
				class ShoulderR_Show
				{
					soundset="ShoulderR_Show_SoundSet";
					id=1211;
				};
			};
		};
	};
	class Clothing: Clothing_Base
	{
	};
	class TacticalGloves_ColorBase: Clothing //GLOVES
	{
		
	};
	
	class ZammyGloves: TacticalGloves_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Zammy";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\ZammySet\data\ZammyGloves.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyGloves.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyGloves.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class ZammyHelm: Mich2001Helmet
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Zammy";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\ZammySet\data\ZammyHelmet.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyHelmet.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyHelmet.paa"
		};
	};
	class CargoPants_ColorBase: Clothing //PANTS
	{
		
	};
	class ZammyPants: CargoPants_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.75;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\ZammySet\data\ZammyPants.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyPants.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyPants.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class ZammyBoots: CombatBoots_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\ZammySet\data\ZammyBoots.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyBoots.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyBoots.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class ZammyJacket: M65Jacket_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\ZammySet\data\ZammyJacket.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyJacket.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyJacket.paa"
		};
	};
	class PlateCarrierVest: Clothing // Vest
	{
		hiddenSelections[]=
		{
			"camoGround",
			"camoFemale",
			"camoMale",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa"
		};
	};
	class ZammyVest: PlateCarrierVest 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\ZammySet\data\ZammyVest.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyVest.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyVest.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyVest.paa"
		};
	};
	class PlateCarrierPouches: Container_Base //Pouches
	{
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa"
		};
	};
	class ZammyPouches: PlateCarrierPouches 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,5};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\ZammySet\data\ZammyVest.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyVest.paa"
		};
	};
	class HuntingBag: Clothing //Bag
	{
		
	};
	class ZammyBag: HuntingBag 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,30};
		attachments[]=
		{
			"Chemlight",
			"WalkieTalkie",
			"shoulder1",
			"shoulder2",
			"shoulder3"
		};
		inventorySlot[]=
		{
			"Back",
			"Back1",
			"Back2",
			"Back3"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\ZammySet\data\ZammyBag.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyBag.paa",
			"SausageCo\storage\clothes\ZammySet\data\ZammyBag.paa"
		};
	};
};