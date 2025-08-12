class CfgPatches
{
	class DZ_SausageBathroom_Items
	{
		units[]={
			"SausageBathroom_Cabinet"
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
	class Slot_SausageAmmo
	{
		name="SausageAmmo";
		displayName="SausageAmmo";
		ghostIcon="cat_common_cargo";
	};
	class Slot_SausageAid
	{
		name="SausageAid";
		displayName="SausageAid";
		ghostIcon="medicalbandage";
	};
};
class CfgVehicles
{
	class Container_Base;
	class SausageBathroom_Cabinet: Container_Base
	{
		scope=2;
		displayName="SausageCo MedicineCabinet";
		model="\DZ\structures\furniture\decoration\lekarnicka\lekarnicka.p3d";
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
			itemsCargoSize[]={10,8};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"Rags",
			"MedicalBandage",
			"SausageAid",
			"Knife"
			
		};
		class GUIInventoryAttachmentsProps
		{
			class Misc_Storage
			{
				name="Misc Storage";
				description="";
				attachmentSlots[]=
				{
					"Rags",
					"MedicalBandage",
					"Knife"
				};
				icon="missing";
			};
		};
	};
	class SausageBathroom_Cabinet_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Bathroom MedCabinet HOLO";
		model="\DZ\structures\furniture\decoration\lekarnicka\lekarnicka.p3d";
	};
};