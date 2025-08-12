class CfgPatches
{
	class SausageClothesStinky_Storage
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
	
	class StinkyGloves: TacticalGloves_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Stinky";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\StinkySet\data\StinkyGloves.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyGloves.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyGloves.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class StinkyHelm: Mich2001Helmet
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Stinky";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\StinkySet\data\StinkyHelmet.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyHelmet.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyHelmet.paa"
		};
	};
	class CargoPants_ColorBase: Clothing //PANTS
	{
		
	};
	class StinkyPants: CargoPants_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.75;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\StinkySet\data\StinkyPants.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyPants.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyPants.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class StinkyBoots: CombatBoots_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\StinkySet\data\StinkyBoots.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyBoots.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyBoots.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class StinkyJacket: M65Jacket_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\StinkySet\data\StinkyJacket.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyJacket.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyJacket.paa"
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
	class StinkyVest: PlateCarrierVest 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\StinkySet\data\StinkyVest.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyVest.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyVest.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyVest.paa"
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
	class StinkyPouches: PlateCarrierPouches 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,5};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\StinkySet\data\StinkyVest.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyVest.paa"
		};
	};
	class HuntingBag: Clothing //Bag
	{
		
	};
	class StinkyBag: HuntingBag 
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
			"SausageCo\storage\clothes\StinkySet\data\StinkyBag.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyBag.paa",
			"SausageCo\storage\clothes\StinkySet\data\StinkyBag.paa"
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
	class StinkyFlag_Stinky: Flag_Base 
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\StinkySet\data\StinkyFlag.paa"
		};
	};
	
};