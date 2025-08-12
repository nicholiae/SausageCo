class CfgPatches
{
	class DZ_SausageLivingroom_EndTable
	{
		units[]={
			"SausageLivingroom_EndTable"
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
	class SausageLivingroom_EndTable: Container_Base
	{
		scope=2;
		displayName="SausageCo EndTable";
		model="\DZ\structures\furniture\tables\table_drawer\table_drawer.p3d";
		descriptionShort="EndTable for your Livingroom back at base.";
		itemSize[]={13,11};
		weight=1200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=1;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,5};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"SausageAid",
			"Pistol"
		};
		class GUIInventoryAttachmentsProps
		{
			class Gear_Storage
			{
				name="FirstAid Storage";
				description="";
				attachmentSlots[]=
				{
					"SausageAid",
					"Pistol"
				};
				icon="medicalbandage";
			};
		};
	};
	class SausageLivingroom_EndTable_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "EndTables HOLO";
		model="\DZ\structures\furniture\tables\table_drawer\table_drawer.p3d";
	};
};