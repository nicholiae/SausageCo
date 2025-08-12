class CfgPatches
{
	class SausageClothesRedTeam_Storage
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
	
	class RedTeamGloves: TacticalGloves_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		color="Red";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Redset\data\RedGloves.paa",
			"SausageCo\storage\clothes\Redset\data\RedGloves.paa",
			"SausageCo\storage\clothes\Redset\data\RedGloves.paa"
		};
	};
	class Mich2001Helmet: Clothing //HELMET
	{
		
	};
	class RedTeamHelm: Mich2001Helmet
	{
		scope=2;
		visibilityModifier=0.69999999;
		color="Red";
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Redset\data\RedHelmet.paa",
			"SausageCo\storage\clothes\Redset\data\RedHelmet.paa",
			"SausageCo\storage\clothes\Redset\data\RedHelmet.paa"
		};
	};
	class GorkaPants_ColorBase: Clothing //PANTS
	{
		
	};
	class RedTeamPants: GorkaPants_ColorBase
	{
		scope=2;
		visibilityModifier=0.75;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Redset\data\RedPants.paa",
			"SausageCo\storage\clothes\Redset\data\RedPants.paa",
			"SausageCo\storage\clothes\Redset\data\RedPants.paa"
		};
	};
	class CombatBoots_ColorBase: Clothing //BOOTS
	{
		
	};
	class RedTeamBoots: CombatBoots_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Redset\data\RedBoots.paa",
			"SausageCo\storage\clothes\Redset\data\RedBoots.paa",
			"SausageCo\storage\clothes\Redset\data\RedBoots.paa"
		};
	};
	class M65Jacket_ColorBase: Clothing //JACKET
	{
		
	};
	class RedTeamJacket: M65Jacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Redset\data\RedJacket.paa",
			"SausageCo\storage\clothes\Redset\data\RedJacket.paa",
			"SausageCo\storage\clothes\Redset\data\RedJacket.paa"
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
	
	class RedTeamVest: PlateCarrierVest 
	{
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\clothes\Redset\data\RedVest.paa",
			"SausageCo\storage\clothes\Redset\data\RedVest.paa",
			"SausageCo\storage\clothes\Redset\data\RedVest.paa",
			"SausageCo\storage\clothes\Redset\data\RedVest.paa"
		};
	};
};