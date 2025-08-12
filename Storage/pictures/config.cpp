class CfgPatches
{
	class DZ_SausageDecor_Picture
	{
		units[]={
			"SausageDecor_Picture1"
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
	class SausageDecor_Picture1: Container_Base
	{
		scope=2;
		displayName="Base Picture 1";
		model="\DZ\structures\furniture\decoration\wallboards\picture_a\picture_a.p3d";
		descriptionShort="";
		itemSize[]={4,4};
		weight=100;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=0;
		physLayer="item_small";	
	};
	class SausageDecor_Picture1_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Base Picture1 HOLO";
		model="\DZ\structures\furniture\decoration\wallboards\picture_a\picture_a.p3d";
	};
};