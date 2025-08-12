class CfgPatches
{
	class SausageClothesBones_Storage
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
	
	class BonesGloves: TacticalGloves_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Bones";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\BonesSet\data\BonesGloves.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesGloves.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesGloves.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class BonesHelm: Mich2001Helmet
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		color="Bones";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\BonesSet\data\BonesHelmet.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesHelmet.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesHelmet.paa"
		};
	};
	class CargoPants_ColorBase: Clothing //PANTS
	{
		
	};
	class BonesPants: CargoPants_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.75;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\BonesSet\data\BonesPants.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesPants.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesPants.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class BonesBoots: CombatBoots_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\BonesSet\data\BonesBoots.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesBoots.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesBoots.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class BonesJacket: M65Jacket_ColorBase
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\BonesSet\data\BonesJacket.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesJacket.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesJacket.paa"
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
	class BonesVest: PlateCarrierVest 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\BonesSet\data\BonesVest.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesVest.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesVest.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesVest.paa"
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
	class BonesPouches: PlateCarrierPouches 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,5};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\BonesSet\data\BonesVest.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesVest.paa"
		};
	};
	class HuntingBag: Clothing //Bag
	{
		
	};
	class BonesBag: HuntingBag 
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
			"SausageCo\storage\clothes\BonesSet\data\BonesBag.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesBag.paa",
			"SausageCo\storage\clothes\BonesSet\data\BonesBag.paa"
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
	class BonesFlag_Bones: Flag_Base 
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\BonesSet\data\BonesFlag.paa"
		};
	};
	
};