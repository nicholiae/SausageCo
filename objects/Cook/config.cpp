class CfgPatches
{
	class DZ_SausageCo_Cook
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
	class Slot_protien
	{
		name="protien";
		displayName="protien"; 
		ghostIcon="food";
		show="true";
	};
	class Slot_veges
	{
		name="veges";
		displayName="veges"; 
		ghostIcon="berry";
		show="true";
	};
	class Slot_seasoning
	{
		name="seasoning";
		displayName="seasoning"; 
		ghostIcon="directcooking";
		show="true";
	};
	class Slot_liquid
	{
		name="liquid";
		displayName="liquid"; 
		ghostIcon="canteen";
		show="true";
	};
};

class BaseFoodStageTransitions
{
	class Raw
	{
		class ToBaked
		{
			transition_to=2;
			cooking_method=1;
		};
		class ToBoiled
		{
			transition_to=3;
			cooking_method=2;
		};
		class ToDried
		{
			transition_to=4;
			cooking_method=3;
		};
		class ToBurned
		{
			transition_to=5;
			cooking_method=3;
		};
		class ToRotten
		{
			transition_to=6;
			cooking_method=4;
		};
	};
	class Rotten
	{
		class ToBurned
		{
			transition_to=5;
			cooking_method=1;
		};
	};
	class Baked
	{
		class ToBurned
		{
			transition_to=5;
			cooking_method=1;
		};
		class ToRotten
		{
			transition_to=6;
			cooking_method=4;
		};
	};
	class Boiled
	{
		class ToBaked
		{
			transition_to=2;
			cooking_method=1;
		};
		class ToRotten
		{
			transition_to=6;
			cooking_method=4;
		};
	};
	class Dried
	{
		class ToBaked
		{
			transition_to=5;
			cooking_method=1;
		};
		class ToBoiled
		{
			transition_to=3;
			cooking_method=2;
		};
		class ToBurned
		{
			transition_to=5;
			cooking_method=3;
		};
	};
	class Burned
	{
	};
};
class NotCookable
{
	class Raw
	{
		class ToRotten
		{
			transition_to=6;
			cooking_method=4;
		};
	};
};
class MeatStageTransitions: BaseFoodStageTransitions
{
};
class FruitStageTransitions: BaseFoodStageTransitions
{
};
class AnimalCorpsesStageTransitions: BaseFoodStageTransitions
{
};
class MushroomsStageTransitions: BaseFoodStageTransitions
{
};
class FoodAnimationSources
{
	class CS_Raw
	{
		source="user";
		animPeriod=0.0099999998;
		initPhase=1;
	};
	class CS_Rotten
	{
		source="user";
		animPeriod=0.0099999998;
		initPhase=1;
	};
	class CS_Baked
	{
		source="user";
		animPeriod=0.0099999998;
		initPhase=1;
	};
	class CS_Boiled
	{
		source="user";
		animPeriod=0.0099999998;
		initPhase=1;
	};
	class CS_Dried
	{
		source="user";
		animPeriod=0.0099999998;
		initPhase=1;
	};
	class CS_Burned
	{
		source="user";
		animPeriod=0.0099999998;
		initPhase=1;
	};
};
class NutritionModifiers
{
	class General
	{
		base_stage="Raw";
		class Raw
		{
			nutrition_properties[]={1,1,1,1,1};
		};
		class Rotten
		{
			nutrition_properties[]={0.5,0.75,1,0.25,1};
		};
		class Baked
		{
			nutrition_properties[]={2,0.5,0.75,0.75,1};
		};
		class Boiled
		{
			nutrition_properties[]={1,1,0.80000001,0.80000001,1};
		};
		class Dried
		{
			nutrition_properties[]={4,0.1,0.5,0.80000001,1};
		};
		class Burned
		{
			nutrition_properties[]={1,0.25,0.75,0.1,1};
		};
	};
};
class CfgHorticulture
{
	class Plants
	{
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Edible_Base: Inventory_Base
	{
		varTemperatureMax=100;
	};
	class Book_Base;
	class HouseNoDestruct;
	class SausageCo_ChefsTool: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Chef's Tool";
		descriptionShort="Use this tool with 3 of the 4 ingredient slots filled to make meals.";
		model="\dz\gear\cooking\FryingPan.p3d";
		rotationFlags=2;
		openable=0;
		weight=150;
		itemSize[]={2,1};
		itemsCargoSize[]={0,0};
		fragility=0.000000001;
		allowOwnedCargoManipulation=1;
		volume=1000;
		varTemperatureMax=200;
		inventorySlot[]=
		{
			"ct1",
			"ct2",
			"ct3",
			"ct4"
		};
		attachments[]=
		{	
			"protien",
			"veges",
			"seasoning",
			"liquid"			
		};
		class GUIInventoryAttachmentsProps
		{
			class Ingredients_Storage
			{
				name="meal prep";
				description="";
				attachmentSlots[]=
				{
					"protien",
					"veges",
					"seasoning",
					"liquid"
				};
				icon="ingredients";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
				};
			};
		};
	};
	class SausageCo_ChefsToolT1: SausageCo_ChefsTool
	{
		displayName="Apprentice Chef's Tool";
	};
	class SausageCo_ChefsToolT2: SausageCo_ChefsTool
	{
		displayName="Journeyman Chef's Tool";
	};
	class SausageCo_ChefsToolT3: SausageCo_ChefsTool
	{
		displayName="Master Chef's Tool";
	};
	class SausageCo_ChefsToolT4: SausageCo_ChefsTool
	{
		displayName="GrandMaster Chef's Tool";
	};
	class SausageCo_zest: Inventory_Base
	{
		scope=2;
		displayName="NO USE BASE ZEST";
		descriptionShort="Used in chef's skill as seasoning";
		model="\dz\gear\food\Marmalade.p3d";
		weight=10;
		itemSize[]={1,2};
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		quantityBar=1;
		absorbency=0.0;
		inventorySlot[]=
		{
			"seasoning"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\food\data\marmalade_ca.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\food\data\marmalade_jar.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\food\data\marmalade_jar.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\food\data\marmalade_jar_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\food\data\marmalade_jar_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\food\data\marmalade_jar_destruct.rvmat"
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
				class pickUpItem
				{
					soundSet="Marmalade_pickup_SoundSet";
					id=797;
				};
			};
		};
	};
	class SC_ZestOrange: SausageCo_zest
	{
		displayName="Orange Zest";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\cook\data\Orange.paa"
		};
	};
	class SC_ZestBanana: SausageCo_zest
	{
		displayName="Banana Zest";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\cook\data\Banana.paa"
		};
	};
	class SC_ZestPear: SausageCo_zest
	{
		displayName="Pear Zest";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\cook\data\Pear.paa"
		};
	};
	class SC_ZestPlum: SausageCo_zest
	{
		displayName="Plum Zest";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\cook\data\Plum.paa"
		};
	};
	class SC_ZestApple: SausageCo_zest
	{
		displayName="Apple Zest";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\cook\data\Apple.paa"
		};
	};
	class SC_ZestKiwi: SausageCo_zest
	{
		displayName="Kiwi Zest";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\cook\data\Kiwi.paa"
		};
	};
	class ChefsMeal: Edible_Base
	{
		scope=2;
		displayName="ChefsMealTest NO USE";
		descriptionShort="ChefsMealTest NO USE";
		model="SausageCo\Objects\Cook\chefmeal.p3d"
		rotationFlags=17;
		weight=10;
		overrideDrawArea="8.0";
		forceFarBubble="true";
		itemSize[]={2,3};
		varQuantityInit=255;
		varQuantityMin=0;
		varQuantityMax=255;
		destroyOnEmpty=0;
		absorbency=0.89999999;
		isMeleeWeapon=0;
		heavyItem=1;
		itemBehaviour=0;
		physLayer="item_large";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
				};
			};
		};
		class Nutrition
		{
			fullnessIndex=4;
			energy=1200;
			water=400;
			nutritionalIndex=1;
			toxicity=0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet="seachest_movement_SoundSet";
					id=1;
				};
				class pickUpItem_Light
				{
					soundSet="pickUpSeaChest_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpSeaChest_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="seachest_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class ChefsMealT1: ChefsMeal
	{
		scope=2;
		displayName="Basic Chef's Meal";
		descriptionShort="This meal, made by a certified apprentice chef, meant to be shared amongst a small community cannot decay";
		varQuantityInit=500;
		varQuantityMin=0;
		varQuantityMax=500;
		class Nutrition
		{
			fullnessIndex=4;
			energy=600;
			water=300;
			nutritionalIndex=1;
			toxicity=0;
		};
	};
	class ChefsMealT2: ChefsMeal
	{
		scope=2;
		displayName="Neat Chef's Meal";
		descriptionShort="This meal, made by a certified journeyman chef, meant to be shared amongst a medium community cannot decay";
		varQuantityInit=800;
		varQuantityMin=0;
		varQuantityMax=800;
		class Nutrition
		{
			fullnessIndex=4;
			energy=800;
			water=500;
			nutritionalIndex=1;
			toxicity=0;
		};
	};
	class ChefsMealT3: ChefsMeal
	{
		scope=2;
		displayName="Wonderful Chef's Meal";
		descriptionShort="This meal, made by a certified master chef, meant to be shared amongst a large community cannot decay";
		varQuantityInit=1250;
		varQuantityMin=0;
		varQuantityMax=1250;
		class Nutrition
		{
			fullnessIndex=4;
			energy=1000;
			water=700;
			nutritionalIndex=1;
			toxicity=0;
		};
	};
	class ChefsMealT4: ChefsMeal
	{
		scope=2;
		displayName="Extravagant Chef's Meal";
		descriptionShort="This meal, made by a certified grandmaster chef, meant to be shared amongst the largest of communities cannot decay";
		varQuantityInit=2000;
		varQuantityMin=0;
		varQuantityMax=2000;
		class Nutrition
		{
			fullnessIndex=4;
			energy=1200;
			water=900;
			nutritionalIndex=1;
			toxicity=0;
		};
	};
};
