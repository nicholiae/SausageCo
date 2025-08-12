class CfgPatches
{
	class DZ_SausageHelipad
	{
		units[]={
			"SausageHelipad_Single"
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
class CfgSlots
{
};
class CfgVehicles
{
	class Container_Base;
	class SausageHelipad_Single: Container_Base
	{
		scope=2;
		displayName="SausageCo Single Helipad";
		model="SausageCo\storage\Helipad\Singlehelipad2.p3d";
		descriptionShort="Deploy for a nice place to land your heli.";
		itemSize[]={13,11};
		weight=3200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=1;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,50};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class SausageHelipad_Single_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "helipad HOLO";
		model="SausageCo\storage\helipad\Singlehelipad2.p3d";
	};
};
class CfgNonAIVehicles
{
	
};