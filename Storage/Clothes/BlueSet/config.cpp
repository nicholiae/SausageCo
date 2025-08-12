class CfgPatches
{
	class SausageClothesBlueTeam_Storage
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
	
	class BlueTeamGloves: TacticalGloves_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		color="Blue";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\blueset\data\BlueGloves.paa",
			"SausageCo\storage\clothes\blueset\data\BlueGloves.paa",
			"SausageCo\storage\clothes\blueset\data\BlueGloves.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class BlueTeamHelm: Mich2001Helmet
	{
		scope=2;
		visibilityModifier=0.69999999;
		color="Blue";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\blueset\data\BlueHelmet.paa",
			"SausageCo\storage\clothes\blueset\data\BlueHelmet.paa",
			"SausageCo\storage\clothes\blueset\data\BlueHelmet.paa"
		};
	};
	class GorkaPants_ColorBase: Clothing //PANTS
	{
		
	};
	class BlueTeamPants: GorkaPants_ColorBase
	{
		scope=2;
		visibilityModifier=0.75;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\blueset\data\BluePants.paa",
			"SausageCo\storage\clothes\blueset\data\BluePants.paa",
			"SausageCo\storage\clothes\blueset\data\BluePants.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class BlueTeamBoots: CombatBoots_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\blueset\data\BlueBoots.paa",
			"SausageCo\storage\clothes\blueset\data\BlueBoots.paa",
			"SausageCo\storage\clothes\blueset\data\BlueBoots.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class BlueTeamJacket: M65Jacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\blueset\data\BlueJacket.paa",
			"SausageCo\storage\clothes\blueset\data\BlueJacket.paa",
			"SausageCo\storage\clothes\blueset\data\BlueJacket.paa"
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
	
	class BlueTeamVest: PlateCarrierVest // Vest
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\blueset\data\BlueVest.paa",
			"SausageCo\storage\clothes\blueset\data\BlueVest.paa",
			"SausageCo\storage\clothes\blueset\data\BlueVest.paa",
			"SausageCo\storage\clothes\blueset\data\BlueVest.paa"
		};
	};
};