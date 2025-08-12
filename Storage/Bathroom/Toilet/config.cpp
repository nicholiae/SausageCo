class CfgPatches
{
	class DZ_SausageBathroom_Items
	{
		units[]={
			"SausageBathroom_Toilet"
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
	class Container_Base;
	class Barrel_ColorBase: Container_Base
	{};
	class SausageBathroom_Toilet: Barrel_ColorBase
	{
		scope=2;
		displayName="Sausage Bathroom Toilet";
		model="\DZ\structures\furniture\bathroom\toilet_b_02\toilet_b_02.p3d";
		descriptionShort="";
		weight=100;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=1;
		physLayer="item_small";
		itemSize[]={11,11};
		itemBehaviour=0;
		stackedUnit="ml";
		randomQuantity=2;
		varLiquidTypeInit=512;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=20000;
		varQuantityMin=0;
		varQuantityMax=20000;
		absorbency=0.1;
		class Cargo
		{
			itemsCargoSize[]={3,3};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		
	};
	class SausageBathroom_Toilet_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Bathroom Toilet HOLO";
		model="\DZ\structures\furniture\bathroom\toilet_b_02\toilet_b_02.p3d";
	};
};