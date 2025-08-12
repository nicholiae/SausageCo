class CfgPatches
{
	class SausageClothesDingle_Storage
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
	
	class DingleGloves: TacticalGloves_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Dingle";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DingleSet\data\DingleGloves.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleGloves.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleGloves.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class DingleHelm: Mich2001Helmet
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Dingle";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DingleSet\data\DingleHelmet.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleHelmet.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleHelmet.paa"
		};
	};
	class CargoPants_ColorBase: Clothing //PANTS
	{
		
	};
	class DinglePants: CargoPants_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.75;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DingleSet\data\DinglePants.paa",
			"SausageCo\storage\clothes\DingleSet\data\DinglePants.paa",
			"SausageCo\storage\clothes\DingleSet\data\DinglePants.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class DingleBoots: CombatBoots_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DingleSet\data\DingleBoots.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleBoots.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleBoots.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class DingleJacket: M65Jacket_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DingleSet\data\DingleJacket.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleJacket.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleJacket.paa"
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
	class DingleVest: PlateCarrierVest 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DingleSet\data\DingleVest.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleVest.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleVest.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleVest.paa"
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
	class DinglePouches: PlateCarrierPouches 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,5};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DingleSet\data\DingleVest.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleVest.paa"
		};
	};
	class HuntingBag: Clothing //Bag
	{
		
	};
	class DingleBag: HuntingBag 
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
			"SausageCo\storage\clothes\DingleSet\data\DingleBag.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleBag.paa",
			"SausageCo\storage\clothes\DingleSet\data\DingleBag.paa"
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
	class DingleFlag_Dingle: Flag_Base 
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DingleSet\data\DingleFlag.paa"
		};
	};
	
};