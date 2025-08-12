class CfgPatches
{
	class SausageClothesTrev_Storage
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
	
	class TrevGloves: TacticalGloves_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Trev";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\TrevSet\data\TrevGloves.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevGloves.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevGloves.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class TrevHelm: Mich2001Helmet
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Trev";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\TrevSet\data\TrevHelmet.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevHelmet.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevHelmet.paa"
		};
	};
	class CargoPants_ColorBase: Clothing //PANTS
	{
		
	};
	class TrevPants: CargoPants_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.75;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\TrevSet\data\TrevPants.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevPants.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevPants.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class TrevBoots: CombatBoots_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\TrevSet\data\TrevBoots.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevBoots.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevBoots.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class TrevJacket: M65Jacket_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\TrevSet\data\TrevJacket.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevJacket.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevJacket.paa"
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
	class TrevVest: PlateCarrierVest 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\TrevSet\data\TrevVest.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevVest.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevVest.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevVest.paa"
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
	class TrevPouches: PlateCarrierPouches 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,5};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\TrevSet\data\TrevVest.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevVest.paa"
		};
	};
	class HuntingBag: Clothing //Bag
	{
		
	};
	class TrevBag: HuntingBag 
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
			"SausageCo\storage\clothes\TrevSet\data\TrevBag.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevBag.paa",
			"SausageCo\storage\clothes\TrevSet\data\TrevBag.paa"
		};
	};
	class Flag_Base: Inventory_Base
	{
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\camping\data\flag_chern_co.paa"
		};
	};
	class TrevFlag_Trev: Flag_Base 
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\TrevSet\data\TrevFlag.paa"
		};
	};
	
};