class CfgPatches
{
	class SausageClothesDyer_Storage
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
	class Clothing: Clothing_Base
	{
	};
	class TacticalGloves_ColorBase: Clothing //GLOVES
	{
		
	};
	
	class DyerGloves: TacticalGloves_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Dyer";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2048.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2048.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2048.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class DyerHelm: Mich2001Helmet
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Dyer";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2048.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2048.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2048.paa"
		};
	};
	class CargoPants_ColorBase: Clothing //PANTS
	{
		
	};
	class DyerPants: CargoPants_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.75;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo1024.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo1024.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo1024.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class DyerBoots: CombatBoots_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo512.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo512.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo512.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class DyerJacket: M65Jacket_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2x1.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2x1.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2x1.paa"
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
	class DyerVest: PlateCarrierVest 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2048.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2048.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2048.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo2048.paa"
		};
	};
	class HuntingBag: Clothing //Bag
	{
		
	};
	class DyerBag: HuntingBag 
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
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo1024.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo1024.paa",
			"SausageCo\storage\clothes\DyerSet\data\ladyCamo1024.paa"
		};
	};
	
};