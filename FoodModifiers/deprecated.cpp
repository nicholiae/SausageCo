// class CfgPatches
// {
	// class SausageCo_Gear_Food
	// {
		// units[]=
		// {
			// "Food_CanBakedBeans",
			// "Food_CanFrankBeans",
			// "Food_CanPasta",
			// "Food_CanSardines",
			// "Food_BoxCerealCrunchin"
		// };
		// weapons[]={};
		// requiredVersion=0.1;
		// requiredAddons[]=
		// {
			// "DZ_Data"
		// };
	// };
// };
// class BaseFoodStageTransitions
// {
	// class Raw
	// {
		// class ToBaked
		// {
			// transition_to=2;
			// cooking_method=1;
		// };
		// class ToBoiled
		// {
			// transition_to=3;
			// cooking_method=2;
		// };
		// class ToBurned
		// {
			// transition_to=5;
			// cooking_method=3;
		// };
	// };
	// class Rotten
	// {
		// class ToBurned
		// {
			// transition_to=5;
			// cooking_method=1;
		// };
	// };
	// class Baked
	// {
		// class ToBurned
		// {
			// transition_to=5;
			// cooking_method=1;
		// };
	// };
	// class Boiled
	// {
		// class ToBaked
		// {
			// transition_to=2;
			// cooking_method=1;
		// };
	// };
	// class Dried
	// {
		// class ToBaked
		// {
			// transition_to=5;
			// cooking_method=1;
		// };
		// class ToBoiled
		// {
			// transition_to=5;
			// cooking_method=2;
		// };
	// };
	// class Burned
	// {
	// };
// };
// class NotCookable
// {
	// class Raw
	// {
		// class ToRotten
		// {
			// transition_to=6;
			// cooking_method=4;
		// };
	// };
// };
// class MeatStageTransitions: BaseFoodStageTransitions
// {
// };
// class FruitStageTransitions: BaseFoodStageTransitions
// {
// };
// class AnimalCorpsesStageTransitions: BaseFoodStageTransitions
// {
// };
// class MushroomsStageTransitions: BaseFoodStageTransitions
// {
// };
// class FoodAnimationSources
// {
	// class CS_Raw
	// {
		// source="user";
		// animPeriod=0.0099999998;
		// initPhase=1;
	// };
	// class CS_Rotten
	// {
		// source="user";
		// animPeriod=0.0099999998;
		// initPhase=1;
	// };
	// class CS_Baked
	// {
		// source="user";
		// animPeriod=0.0099999998;
		// initPhase=1;
	// };
	// class CS_Boiled
	// {
		// source="user";
		// animPeriod=0.0099999998;
		// initPhase=1;
	// };
	// class CS_Dried
	// {
		// source="user";
		// animPeriod=0.0099999998;
		// initPhase=1;
	// };
	// class CS_Burned
	// {
		// source="user";
		// animPeriod=0.0099999998;
		// initPhase=1;
	// };
// };
// class NutritionModifiers
// {
	// class General
	// {
		// base_stage="Raw";
		// class Raw
		// {
			// nutrition_properties[]={1,1,1,1,1};
		// };
		// class Rotten
		// {
			// nutrition_properties[]={0.5,0.75,1,0.25,1};
		// };
		// class Baked
		// {
			// nutrition_properties[]={2,0.5,0.75,0.75,1};
		// };
		// class Boiled
		// {
			// nutrition_properties[]={1,1,0.80000001,0.80000001,1};
		// };
		// class Dried
		// {
			// nutrition_properties[]={4,0.1,0.5,0.80000001,1};
		// };
		// class Burned
		// {
			// nutrition_properties[]={1,0.25,0.75,0.1,1};
		// };
	// };
// };
// class CfgVehicles
// {
	// class Inventory_Base;
	// class Edible_Base: Inventory_Base
	// {
		// varTemperatureMax=100;
	// };
	// class BoxCerealCrunchin: Edible_Base
	// {
		// class Nutrition
		// {
			// fullnessIndex=2.5;
			// energy=133;
			// water=1;
			// nutritionalIndex=1;
			// toxicity=0;
		// };
	// };
	// class PowderedMilk: Edible_Base
	// {
		// class Nutrition
		// {
			// fullnessIndex=2.5;
			// energy=132;
			// water=1;
			// nutritionalIndex=1;
			// toxicity=0;
		// };
	// };
	// class SmallGuts: Edible_Base
	// {
		// class Nutrition
		// {
			// fullnessIndex=2.5;
			// energy=30;
			// water=170;
			// nutritionalIndex=1;
			// toxicity=3.1;
			// agents=4;
		// };
	// };
	// class Guts: Edible_Base
	// {
		// class Nutrition
		// {
			// fullnessIndex=2.5;
			// energy=30;
			// water=170;
			// nutritionalIndex=1;
			// toxicity=2.0;
			// agents=4;
		// };
	// };
	// class Rice: Edible_Base
	// {
		// class Nutrition
		// {
			// fullnessIndex=2.5;
			// energy=121;
			// water=7.5;
			// nutritionalIndex=1;
			// toxicity=0;
		// };
	// };
	// class Marmalade: Edible_Base
	// {
		// class Nutrition
		// {
			// fullnessIndex=1.5;
			// energy=130;
			// water=10;
			// nutritionalIndex=1;
			// toxicity=0;
		// };
	// };
	// class BakedBeansCan_Opened: Edible_Base
	// {
		// class Nutrition
		// {
			// fullnessIndex=1.5;
			// energy=41;
			// water=23;
			// nutritionalIndex=1;
			// toxicity=0;
		// };
	// };
	// class PeachesCan_Opened: Edible_Base
	// {
		// class Nutrition
		// {
			// fullnessIndex=1.5;
			// energy=26;
			// water=30;
			// nutritionalIndex=1;
			// toxicity=0;
		// };
	// };
	// class TacticalBaconCan_Opened: Edible_Base
	// {
		// class Nutrition
		// {
			// fullnessIndex=2;
			// energy=166;
			// water=4.5;
			// nutritionalIndex=1;
			// toxicity=0;
		// };
	// };
	// class SpaghettiCan_Opened: Edible_Base
	// {
		// class Nutrition
		// {
			// fullnessIndex=1.5;
			// energy=39;
			// water=29;
			// nutritionalIndex=1;
			// toxicity=0;
		// };
	// };
	// class SardinesCan_Opened: Edible_Base
	// {
		// class Nutrition
		// {
			// fullnessIndex=1.5;
			// energy=70;
			// water=20;
			// nutritionalIndex=1;
			// toxicity=0;
		// };
	// };
	// class TunaCan_Opened: Edible_Base
	// {
		// class Nutrition
		// {
			// fullnessIndex=1.5;
			// energy=62;
			// water=21;
			// nutritionalIndex=1;
			// toxicity=0;
		// };
	// };
	// class GoatSteakMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=75;
		// varQuantityMin=0;
		// varQuantityMax=75;
	// };
	// class MouflonSteakMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=115;
		// varQuantityMin=0;
		// varQuantityMax=115;
	// };
	// class BoarSteakMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=100;
		// varQuantityMin=0;
		// varQuantityMax=100;
	// };
	// class PigSteakMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=100;
		// varQuantityMin=0;
		// varQuantityMax=100;
	// };
	// class DeerSteakMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=100;
		// varQuantityMin=0;
		// varQuantityMax=100;
	// };
	// class WolfSteakMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=90;
		// varQuantityMin=0;
		// varQuantityMax=90;
	// };
	// class BearSteakMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=120;
		// varQuantityMin=0;
		// varQuantityMax=120;
	// };
	// class CowSteakMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=200;
		// varQuantityMin=0;
		// varQuantityMax=200;
	// };
	// class SheepSteakMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=75;
		// varQuantityMin=0;
		// varQuantityMax=75;
	// };
	// class FoxSteakMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=65;
		// varQuantityMin=0;
		// varQuantityMax=65;
	// };
	// class ChickenBreastMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=60;
		// varQuantityMin=0;
		// varQuantityMax=60;
	// };
	// class RabbitLegMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=55;
		// varQuantityMin=0;
		// varQuantityMax=55;
	// };
	// class CarpFilletMeat: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=180;
		// varQuantityMin=0;
		// varQuantityMax=180;
	// };
	// class MackerelFilletMeat: Edible_Base
	// {
		// varQuantityInit=150;
		// varQuantityMin=0;
		// varQuantityMax=150;
		
	// };
	// class Lard: Edible_Base
	// {
		// varQuantityInit=200;
		// varQuantityMin=0;
		// varQuantityMax=200;
		// quantityBar=1;
	// };
	// class Carp: Edible_Base
	// {
		// quantityBar=1;
		// varQuantityInit=250;
		// varQuantityMin=0;
		// varQuantityMax=250;
	// };
// };
