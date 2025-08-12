class CfgPatches
{
	class SausageClothesVincent
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
	class Clothing_Base;
	class Container_Base;
	class Clothing: Clothing_Base
	{
	};
	class TacticalGloves_ColorBase: Clothing //GLOVES
	{
		
	};
	
	class VincentGloves: TacticalGloves_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Vincent";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\VincentSet\data\VincentGloves.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentGloves.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentGloves.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class VincentHelm: Mich2001Helmet
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Vincent";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\VincentSet\data\VincentHelmet.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentHelmet.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentHelmet.paa"
		};
	};
	class CargoPants_ColorBase: Clothing //PANTS
	{
		
	};
	class VincentPants: CargoPants_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.75;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\VincentSet\data\VincentPants.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentPants.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentPants.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class VincentBoots: CombatBoots_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\VincentSet\data\VincentBoots.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentBoots.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentBoots.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class VincentJacket: M65Jacket_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\VincentSet\data\VincentJacket.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentJacket.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentJacket.paa"
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
	class VincentVest: PlateCarrierVest 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\VincentSet\data\VincentVest.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentVest.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentVest.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentVest.paa"
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
	class VincentPouches: PlateCarrierPouches 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,5};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\VincentSet\data\VincentVest.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentVest.paa"
		};
	};
	class HuntingBag: Clothing //Bag
	{
		
	};
	class VincentBag: HuntingBag 
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
			"SausageCo\storage\clothes\VincentSet\data\VincentBag.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentBag.paa",
			"SausageCo\storage\clothes\VincentSet\data\VincentBag.paa"
		};
	};
	
};