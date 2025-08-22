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
	class Slot_poison
	{
		name="poison";
		displayName="poison"; 
		ghostIcon="hook";
		stackMax=100;
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
	class Book_Base;
    class SausageCo_SkillBook_Base: Book_Base
    {
    };
	class HouseNoDestruct;
	class SausageCo_HuntersTool: SausageCo_SkillBook_Base
	{
		scope=2;
		displayName="SausageCo Hunter's Tool";
		descriptionShort="Use this tool with a protien, vege, seasoning, and a poison.";
		model="\SausageCo\Objects\Hunter\hunterTool.p3d";
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
			"ht1",
			"ht2",
			"ht3",
			"ht4"
		};
		hiddenSelections[]=
		{
			"Mortar",
			"Pestle"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Hunter\data\Mortar_MarbleDark_BaseColor.paa",
			"SausageCo\Objects\Hunter\data\Pestle_Bone_BaseColor.paa"
		};
		attachments[]=
		{	
			"protien",
			"veges",
			"seasoning",
			"poison"
		};
		class GUIInventoryAttachmentsProps
		{
			class Ingredients_Storage
			{
				name="Bait prep";
				description="";
				attachmentSlots[]=
				{
					"protien",
					"veges",
					"seasoning",
					"poison"
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
	class SausageCo_HuntersToolT1: SausageCo_HuntersTool
	{
		displayName="Apprentice Hunter's Tool";
		hiddenSelections[]=
		{
			"Mortar",
			"Pestle"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Hunter\data\Mortar_Bone_BaseColor.paa",
			"SausageCo\Objects\Hunter\data\Pestle_Bone_BaseColor.paa"
		};
	};
	class SausageCo_HuntersToolT2: SausageCo_HuntersTool
	{
		displayName="Journeyman Hunter's Tool";
		hiddenSelections[]=
		{
			"Mortar",
			"Pestle"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Hunter\data\Mortar_Jade_BaseColor.paa",
			"SausageCo\Objects\Hunter\data\Pestle_Jade_BaseColor.paa"
		};
	};
	class SausageCo_HuntersToolT3: SausageCo_HuntersTool
	{
		displayName="Master Hunter's Tool";
		hiddenSelections[]=
		{
			"Mortar",
			"Pestle"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Hunter\data\Mortar_MarbleDark_BaseColor.paa",
			"SausageCo\Objects\Hunter\data\Pestle_MarbleDark_BaseColor.paa"
		};
	};
	class SausageCo_HuntersToolT4: SausageCo_HuntersTool
	{
		displayName="GrandMaster Hunter's Tool";
		hiddenSelections[]=
		{
			"Mortar",
			"Pestle"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Objects\Hunter\data\Mortar_Sapphire_BaseColor.paa",
			"SausageCo\Objects\Hunter\data\Pestle_Sapphire_BaseColor.paa"
		};
	};
	class HuntersBate: Inventory_Base
	{
		scope=2;
		displayName="HuntersBaitTest NO USE";
		descriptionShort="HuntersBaitTest NO USE";
		model="SausageCo\Objects\Hunter\hunterBate.p3d"
		rotationFlags=17;
		weight=10;
		overrideDrawArea="8.0";
		forceFarBubble="true";
		itemSize[]={2,3};
		absorbency=0.89999999;
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
	class HuntersBateT1: HuntersBate
	{
		scope=2;
		displayName="Basic Hunter's Bait";
		descriptionShort="This Bait, made by a certified apprentice hunter, meant to be used to attract some of the smaller farm animals";
		
	};
	class HuntersBateT2: HuntersBate
	{
		scope=2;
		displayName="Neat Hunter's Bait";
		descriptionShort="This Bait, made by a certified journeyman hunter, meant to be used to attract some of the most meaty of farm animals";
		
	};
	class HuntersBateT3: HuntersBate
	{
		scope=2;
		displayName="Wonderful Hunter's Bait";
		descriptionShort="This Bait, made by a certified master hunter, meant to be used to attract some of the most feared packs";
		
	};
	class HuntersBateT4: HuntersBate
	{
		scope=2;
		displayName="Extravagant Hunter's Bait";
		descriptionShort="This Bait, made by a certified grandmaster hunter, meant to be used to attract some of the most dangerous animals";
		
	};
};
