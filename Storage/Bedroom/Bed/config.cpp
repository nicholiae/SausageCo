class CfgPatches
{
	class DZ_SausageBedroom_BunkBed
	{
		units[]={
			"SausageBedroom_BunkBed"
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
	class SausageBedroom_BunkBed: Container_Base
	{
		scope=2;
		displayName="SausageCo BunkBeds";
		model="DZ\structures\wrecks\ships\proxy\aship_armybed.p3d";
		descriptionShort="Bunkbeds for your bedrooms back at base.";
		itemSize[]={13,11};
		weight=1200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=1;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,6};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			
		};
		class GUIInventoryAttachmentsProps
		{
			
		};
	};
	class SausageBedroom_BunkBed_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "BunkBeds HOLO";
		model="DZ\structures\wrecks\ships\proxy\aship_armybed.p3d";
	};
};