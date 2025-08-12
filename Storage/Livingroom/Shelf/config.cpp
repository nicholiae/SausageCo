class CfgPatches
{
	class DZ_SausageLivingroom_Shelf
	{
		units[]={
			"SausageLivingroom_Shelf"
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
	class SausageLivingroom_Shelf: Container_Base
	{
		scope=2;
		displayName="SausageCo Shelf";
		model="\DZ\structures_bliss\ruins\proxy\shelfs_small.p3d";
		descriptionShort="Shelf for your Livingroom back at base.";
		itemSize[]={13,11};
		weight=1200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=1;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,15};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"Knife",
			"Pistol"
		};
		class GUIInventoryAttachmentsProps
		{
			class Weapons_Storage
			{
				name="Weapons Storage";
				description="";
				attachmentSlots[]=
				{
					"Knife",
					"Pistol",
					"Melee"
				};
				icon="Shoulder";
			};
		};
	};
	class SausageLivingroom_Shelf_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Shelf HOLO";
		model="\DZ\structures_bliss\ruins\proxy\shelfs_small.p3d";
	};
};