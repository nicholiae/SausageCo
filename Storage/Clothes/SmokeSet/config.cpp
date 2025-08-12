class CfgPatches
{
	class SausageClothesSmoke
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
	
	class SmokeGloves: TacticalGloves_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Smoke";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\SmokeSet\data\SmokeGloves.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeGloves.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeGloves.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class SmokeHelm: Mich2001Helmet
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Smoke";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\SmokeSet\data\SmokeHelmet.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeHelmet.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeHelmet.paa"
		};
	};
	class CargoPants_ColorBase: Clothing //PANTS
	{
		
	};
	class SmokePants: CargoPants_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.75;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\SmokeSet\data\SmokePants.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokePants.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokePants.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class SmokeBoots: CombatBoots_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\SmokeSet\data\SmokeBoots.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeBoots.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeBoots.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class SmokeJacket: M65Jacket_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\SmokeSet\data\SmokeJacket.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeJacket.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeJacket.paa"
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
	class SmokeVest: PlateCarrierVest 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\SmokeSet\data\SmokeVest.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeVest.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeVest.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeVest.paa"
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
	class SmokePouches: PlateCarrierPouches 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,5};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\SmokeSet\data\SmokeVest.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeVest.paa"
		};
	};
	class HuntingBag: Clothing //Bag
	{
		
	};
	class SmokeBag: HuntingBag 
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
			"SausageCo\storage\clothes\SmokeSet\data\SmokeBag.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeBag.paa",
			"SausageCo\storage\clothes\SmokeSet\data\SmokeBag.paa"
		};
	};
	
};