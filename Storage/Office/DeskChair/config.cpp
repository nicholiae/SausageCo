class CfgPatches
{
	class DZ_SausageOffice_Chair
	{
		units[]={
			"SausageOffice_Chair"
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
	class SausageOffice_Chair: Container_Base
	{
		scope=2;
		displayName="SausageCo Chair";
		model="\DZ\structures\furniture\chairs\ch_office_b\ch_office_b.p3d";
		descriptionShort="Chair for your office back at base.";
		itemSize[]={13,11};
		weight=1200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=1;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={6,3};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"Shoulder1",
			"Shoulder2",
			"Back"
		};
		class GUIInventoryAttachmentsProps
		{
			class Misc_Storage
			{
				name="Misc Storage";
				description="";
				attachmentSlots[]=
				{
					"Shoulder1",
					"Shoulder2",
					"Back"
				};
				icon="Back";
			};
		};
	};
	class SausageOffice_Chair_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Chair HOLO";
		model="\DZ\structures\furniture\chairs\ch_office_b\ch_office_b.p3d";
	};
};