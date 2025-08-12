class CfgPatches
{
	class SausageCoTrophy
	{
		units[]={
			"SC_TrophyWorstKD",
			"SC_TrophyBestKD",
			"SC_TrophyDeathbynades",
			"SC_TrophyFirst210",
			"SC_TrophyLeastKills",
			"SC_TrophyLongestShot",
			"SC_TrophyMostDeaths",
			"SC_TrophyMostKills"
			
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Structures",
			"DZ_Scripts"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class SC_TrophyBase: Inventory_Base
	{
		scope=2;
		displayName="Trophy base";
		descriptionShort="A Trophy from a ShadowLands Event!";
		model="SausageCo\objects\trophiesWorstKD.p3d";
		isMeleeWeapon=1;
		rotationFlags=17;
		itemBehaviour=1;
		carveNavmesh=1;
		weight=85;
		absorbency=0.00000001;
		itemSize[]={3,3};
		repairableWithKits[]={};
		repairCosts[]={};
		physLayer="item_small";
	};
	class SC_TrophyWorstKD: SC_TrophyBase
	{
		displayName="Trophy WorstKD";
		model="SausageCo\objects\trophiesWorstKD.p3d";
	};
	class SC_TrophyBestKD: SC_TrophyBase
	{
		displayName="Trophy BestKD";
		model="SausageCo\objects\trophiesbestKD.p3d";
	};
	class SC_TrophyDeathbynades: SC_TrophyBase
	{
		displayName="Trophy Deathbynades";
		model="SausageCo\objects\trophiesDeathbyNades.p3d";
	};
	class SC_TrophyFirst210: SC_TrophyBase
	{
		displayName="Trophy First210";
		model="SausageCo\objects\trophiesFirst210.p3d";
	};
	class SC_TrophyLeastKills: SC_TrophyBase
	{
		displayName="Trophy LeastKills";
		model="SausageCo\objects\trophiesLeastKillsParticipation.p3d";
	};
	class SC_TrophyLongestShot: SC_TrophyBase
	{
		displayName="Trophy LongestShot";
		model="SausageCo\objects\trophiesLongestShot.p3d";
	};
	class SC_TrophyMostDeaths: SC_TrophyBase
	{
		displayName="Trophy MostDeaths";
		model="SausageCo\objects\trophiesMostDeaths.p3d";
	};
	class SC_TrophyMostKills: SC_TrophyBase
	{
		displayName="Trophy MostKills";
		model="SausageCo\objects\trophiesMostKills.p3d";
	};
	//skills
	class SausageCo_StartersTool: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Starter's Tool";
		descriptionShort="Use this tool to begin your Skills journey in one of the 4 selections";
		model="\dz\gear\consumables\Stone_slice.p3d";
		rotationFlags=2;
		openable=0;
		weight=150;
		itemSize[]={2,1};
		itemsCargoSize[]={0,0};
		fragility=0.000000001;
		allowOwnedCargoManipulation=1;
		volume=1000;
		varTemperatureMax=200;
	};
	
	
};