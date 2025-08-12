class CfgPatches
{
	class DZ_SausageOffice_Desk
	{
		units[]={
			"SausageOffice_Desk"
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
	class SausageOffice_Desk: Container_Base
	{
		scope=2;
		displayName="SausageCo Desk";
		model="\DZ\structures\furniture\tables\office_desk\desk_office.p3d";
		descriptionShort="Desk for your office back at base.";
		itemSize[]={13,11};
		weight=1200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=1;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,10};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"Knife",
			"Pistol",
			"Rags",
			"MedicalBandage",
			"SausageAid",
			"magazine",
			"magazine2",
			"magazine3"
		};
		class GUIInventoryAttachmentsProps
		{
			class TopLeftDrawer_Storage
			{
				name="TopLeft Drawer";
				description="";
				attachmentSlots[]=
				{
					"Knife",
					"Pistol"
				};
				icon="Shoulder";
			};
			class TopRightDrawer_Storage
			{
				name="TopRight Drawer";
				description="";
				attachmentSlots[]=
				{
					"Rags",
					"MedicalBandage",
				};
				icon="Rags";
			};
			class 2ndRightDrawer_Storage
			{
				name="2ndRight Drawer";
				description="";
				attachmentSlots[]=
				{
					"SausageAid"
				};
				icon="MedicalBandage";
			};
			class BotRightDrawer_Storage
			{
				name="BotRight Drawer";
				description="";
				attachmentSlots[]=
				{
					"magazine",
					"magazine2",
					"magazine3"
				};
				icon="magazine";
			};
		};
	};
	class SausageOffice_Desk_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Desk HOLO";
		model="\DZ\structures\furniture\tables\office_desk\desk_office.p3d";
	};
};