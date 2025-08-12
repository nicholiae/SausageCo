class CfgPatches
{
	class DZ_SausageBathroom_Items
	{
		units[]={
			"SausageBathroom_Sink"
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
	class SausageBathroom_Sink: Container_Base
	{
		scope=2;
		displayName="Sausage Bathroom Sink";
		model="\DZ\structures\furniture\bathroom\basin_a\basin_a.p3d";
		descriptionShort="";
		weight=100;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=1;
		physLayer="item_small";
		itemSize[]={11,11};
		itemBehaviour=0;
		class Cargo
		{
			itemsCargoSize[]={3,3};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		
	};
	class SausageBathroom_Sink_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Bathroom Sink HOLO";
		model="\DZ\structures\furniture\bathroom\basin_a\basin_a.p3d";
	};
};