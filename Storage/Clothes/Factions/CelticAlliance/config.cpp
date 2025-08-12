class CfgPatches
{
	class SausageClothesCelticF
	{
		units[]=
		{
			""
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_data",
			"DZ_Gear_Consumables",
			"DZ_Structures",
			"DZ_Scripts"
		};
	};
};
class CfgVehicles
{	
	class Inventory_Base;
	class Clothing_Base;
	class Container_Base;
	class Clothing: Clothing_Base
	{
	};
	class TacticalGloves_ColorBase: Clothing //GLOVES
	{
		
	};
	
	class CelticFGloves: TacticalGloves_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="CelticF";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFGloves.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFGloves.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFGloves.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class CelticFHelm: Mich2001Helmet
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="CelticF";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFHelmet.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFHelmet.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFHelmet.paa"
		};
	};
	class CargoPants_ColorBase: Clothing //PANTS
	{
		
	};
	class CelticFPants: CargoPants_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.75;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFPants.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFPants.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFPants.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class CelticFBoots: CombatBoots_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFBoots.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFBoots.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFBoots.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class CelticFJacket: M65Jacket_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFJacket.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFJacket.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFJacket.paa"
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
	class CelticFVest: PlateCarrierVest 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFVest.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFVest.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFVest.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFVest.paa"
		};
	};
	class PlateCarrierPouches: Container_Base //Pouches
	{
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
	};
	class CelticFPouches: PlateCarrierPouches 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,5};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFVest.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFVest.paa"
		};
	};
	class HuntingBag: Clothing //Bag
	{
		
	};
	class CelticFBag: HuntingBag 
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
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFBag.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFBag.paa",
			"SausageCo\storage\clothes\Factions\CelticAlliance\data\CelticFBag.paa"
		};
	};
	
};