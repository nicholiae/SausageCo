class CfgPatches
{
	class SausageClothesDiman_AutumnVibe
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
	
	class DimanGloves_AutumnVibe: TacticalGloves_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Diman";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanGloves.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanGloves.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanGloves.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class DimanHelm_AutumnVibe: Mich2001Helmet
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Diman";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanHelmet.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanHelmet.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanHelmet.paa"
		};
	};
	class CargoPants_ColorBase: Clothing //PANTS
	{
		
	};
	class DimanPants_AutumnVibe: CargoPants_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.75;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanPants.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanPants.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanPants.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class DimanBoots_AutumnVibe: CombatBoots_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanBoots.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanBoots.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanBoots.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class DimanJacket_AutumnVibe: M65Jacket_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanJacket.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanJacket.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanJacket.paa"
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
	class DimanVest_AutumnVibe: PlateCarrierVest 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanVest.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanVest.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanVest.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanVest.paa"
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
	class DimanPouches_AutumnVibe: PlateCarrierPouches 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,5};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanVest.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanVest.paa"
		};
	};
	class HuntingBag: Clothing //Bag
	{
		
	};
	class DimanBag_AutumnVibe: HuntingBag 
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
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanBag.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanBag.paa",
			"SausageCo\storage\clothes\DimanObjects\autumnVibe\data\DimanBag.paa"
		};
	};
	
};