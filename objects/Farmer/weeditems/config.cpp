class CfgPatches
{
	class DZ_SausageWeed_Items
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
	class Edible_Base: Inventory_Base
	{
		varTemperatureMax=100;
	};
	class SC_RollingPapers: Inventory_Base
	{
		scope=2;
		displayName="RollingPapers";
		descriptionShort="Rolling papers, so you can roll your weed into a joint.";
		model="SausageCo\objects\farmer\weeditems\rollingpapers.p3d";
		rotationFlags=16;
		weight=30;
		itemSize[]={1,2};
		varQuantityDestroyOnMin=1;
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		canBeSplit=0;
		canBeDigged=0;
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\rollingpaperbox.paa",
			"SausageCo\objects\farmer\weeditems\data\rollingpapers.paa"
		};
	};
	class SC_BluntWraps: Inventory_Base
	{
		scope=2;
		displayName="BluntWraps";
		descriptionShort="BluntWraps, so you can roll your weed into a Blunt.";
		model="SausageCo\objects\farmer\weeditems\bluntwraps.p3d";
		rotationFlags=16;
		weight=30;
		itemSize[]={2,2};
		varQuantityDestroyOnMin=1;
		varQuantityInit=3;
		varQuantityMin=0;
		varQuantityMax=3;
		canBeSplit=0;
		canBeDigged=0;
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\bluntwraps.paa"
		};
	};
	class SC_Joint_base: Edible_Base
	{
		scope=2;
		displayName="Joint";
		descriptionShort="A finely rolled cannabis Joint. Restores minimal water and food, can prevent some sicknesses.";
		model="SausageCo\objects\farmer\weeditems\joint.p3d";
		rotationFlags=16;
		weight=30;
		itemSize[]={4,2};
		varQuantityDestroyOnMin=1;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		quantityBar=1;
		canBeSplit=0;
		canBeDigged=0;
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\Joint.paa"
		};
		class Nutrition
		{
			fullnessIndex=2;
			energy=50;
			water=50;
			nutritionalIndex=1;
			toxicity=0;
		};
		class Medicine
		{
			prevention=0.55;
			treatment=0.05;
			diseaseExit=1;
		};
	};
	class SC_Joint_ATF: SC_Joint_base
	{
		scope=2;
		displayName="Joint-ATF";
		// descriptionShort="A finely rolled Alaskan Thunder Fuck Joint.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\Joint.paa"
		};
	};
	class SC_Joint_GG: SC_Joint_base
	{
		scope=2;
		displayName="Joint-GG";
		// descriptionShort="A finely rolled GorillaGlue Joint.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\Joint.paa"
		};
	};
	class SC_Joint_TW: SC_Joint_base
	{
		scope=2;
		displayName="Joint-TW";
		// descriptionShort="A finely rolled Trainwreck Joint.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\Joint.paa"
		};
	};
	class SC_Joint_WW: SC_Joint_base
	{
		scope=2;
		displayName="Joint-WW";
		// descriptionShort="A finely rolled WhiteWidow Joint.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\Joint.paa"
		};
	};
	class SC_Joint_BD: SC_Joint_base
	{
		scope=2;
		displayName="Joint-BD";
		// descriptionShort="A finely rolled BlueDream Joint.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\Joint.paa"
		};
	};
	class SC_Joint_FC: SC_Joint_base
	{
		scope=2;
		displayName="Joint-FC";
		// descriptionShort="A finely rolled FireCrotch Joint.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\Joint.paa"
		};
	};
	class SC_Joint_SD: SC_Joint_base
	{
		scope=2;
		displayName="Joint-SD";
		// descriptionShort="A finely rolled SourDiesel Joint.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\Joint.paa"
		};
	};
	class SC_Joint_PE: SC_Joint_base
	{
		scope=2;
		displayName="Joint-PE";
		// descriptionShort="A finely rolled PineappleExpress Joint.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\Joint.paa"
		};
	};
	class SC_Blunt_base: Edible_Base
	{
		scope=2;
		displayName="Blunt";
		descriptionShort="A finely rolled cannabis blunt. Refills Small amounts of food and water, best used as a preventative medicine!";
		model="SausageCo\objects\farmer\weeditems\blunt.p3d";
		rotationFlags=16;
		weight=30;
		itemSize[]={4,2};
		varTemperatureFreezePoint=-60;
		varTemperatureThawPoint=-60;
		varTemperatureFreezeTime=7920;
		varTemperatureThawTime=7920;
		varQuantityInit=500;
		varQuantityMin=0;
		varQuantityMax=500;
		varTemperatureMax=105;
		temperaturePerQuantityWeight=3;
		quantityBar=1;
		canBeSplit=0;
		canBeDigged=0;
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\blunt.paa"
		};
		class Nutrition
		{
			fullnessIndex=2;
			energy=100;
			water=100;
			nutritionalIndex=1;
			toxicity=0;
		};
		class Medicine
		{
			prevention=0.95;
			treatment=0.25;
			diseaseExit=1;
		};
	};
	class SC_Blunt_ATF: SC_Blunt_base
	{
		scope=2;
		displayName="Blunt-ATF";
		// descriptionShort="A finely rolled Alaskan Thunder Fuck blunt.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\blunt.paa"
		};
	};
	class SC_Blunt_GG: SC_Blunt_base
	{
		scope=2;
		displayName="Blunt-GG";
		// descriptionShort="A finely rolled GorillaGlue blunt.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\blunt.paa"
		};
	};
	class SC_Blunt_TW: SC_Blunt_base
	{
		scope=2;
		displayName="Blunt-TW";
		// descriptionShort="A finely rolled Trainwreck blunt.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\blunt.paa"
		};
	};
	class SC_Blunt_WW: SC_Blunt_base
	{
		scope=2;
		displayName="Blunt-WW";
		// descriptionShort="A finely rolled WhiteWidow blunt.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\blunt.paa"
		};
	};
	class SC_Blunt_BD: SC_Blunt_base
	{
		scope=2;
		displayName="Blunt-BD";
		// descriptionShort="A finely rolled BlueDream blunt.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\blunt.paa"
		};
	};
	class SC_Blunt_FC: SC_Blunt_base
	{
		scope=2;
		displayName="Blunt-FC";
		// descriptionShort="A finely rolled FireCrotch blunt.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\blunt.paa"
		};
	};
	class SC_Blunt_SD: SC_Blunt_base
	{
		scope=2;
		displayName="Blunt-SD";
		// descriptionShort="A finely rolled SourDiesel blunt.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\blunt.paa"
		};
	};
	class SC_Blunt_PE: SC_Blunt_base
	{
		scope=2;
		displayName="Blunt-PE";
		// descriptionShort="A finely rolled PineappleExpress blunt.";
		hiddenSelections[]=
		{
			
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\farmer\weeditems\data\blunt.paa"
		};
	};
};