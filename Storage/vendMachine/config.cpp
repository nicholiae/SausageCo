class CfgPatches
{
	class DZ_SausageBuilding_VendMachine
	{
		units[]={
			"SausageBuilding_VendMachine"
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
	class SausageBuilding_VendMachine: Container_Base
	{
		scope=2;
		displayName="Vending Machine Storage";
		model="DZ\structures\furniture\Eletrical_appliances\vending_machine\vending_machine.p3d";
		descriptionShort="Basebuilding material storage. Created by Nicholiae.";
		itemSize[]={13,11};
		weight=1200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=0;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,10};
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
	class SausageBuilding_VendMachine_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "BuildingStorage HOLO";
		model="DZ\structures\furniture\Eletrical_appliances\vending_machine\vending_machine.p3d";
	};
};