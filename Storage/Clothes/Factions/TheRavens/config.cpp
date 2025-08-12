class CfgPatches
{
	class SausageClothesRavensF
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
	
	class RavensFGloves: TacticalGloves_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="RavensF";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFGloves.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFGloves.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFGloves.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class RavensFHelm: Mich2001Helmet
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="RavensF";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFHelmet.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFHelmet.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFHelmet.paa"
		};
	};
	class CargoPants_ColorBase: Clothing //PANTS
	{
		
	};
	class RavensFPants: CargoPants_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.75;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFPants.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFPants.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFPants.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class RavensFBoots: CombatBoots_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFBoots.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFBoots.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFBoots.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class RavensFJacket: M65Jacket_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFJacket.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFJacket.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFJacket.paa"
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
	class RavensFVest: PlateCarrierVest 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFVest.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFVest.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFVest.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFVest.paa"
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
	class RavensFPouches: PlateCarrierPouches 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,5};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFVest.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFVest.paa"
		};
	};
	class HuntingBag: Clothing //Bag
	{
		
	};
	class RavensFBag: HuntingBag 
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
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFBag.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFBag.paa",
			"SausageCo\storage\clothes\Factions\TheRavens\data\RavensFBag.paa"
		};
	};
	
};