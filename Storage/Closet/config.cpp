class CfgPatches
{
	class DZ_SausageGear_Storage
	{
		units[]={
			"Storage"
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
	class Slot_Shoulder1
	{
		name="Shoulder1";
		displayName="Shoulder1";
		ghostIcon="Shoulder";
		show="true";
	};
	class Slot_Shoulder2
	{
		name="Shoulder2";
		displayName="Shoulder2";
		ghostIcon="Shoulder";
		show="true";
	};
	class Slot_Shoulder3
	{
		name="Shoulder3";
		displayName="Shoulder3";
		ghostIcon="Shoulder";
		show="true";
	};
	class Slot_Shoulder4
	{
		name="Shoulder4";
		displayName="Shoulder4";
		ghostIcon="Shoulder";
		show="true";
	};
	class Slot_Shoulder5
	{
		name="Shoulder5";
		displayName="Shoulder5";
		ghostIcon="Shoulder";
		show="true";
	};
	
};
class CfgVehicles
{
	class Container_Base;
	class SausageGear_Storage: Container_Base
	{
		scope=2;
		displayName="Gear Storage";
		model="DZ\structures\furniture\cases\almara\almara.p3d";
		descriptionShort="Gear storage can hold 1 full set of gear, 3 shoulder weapons and a knife and sidearm. Created by Nicholiae.";
		itemSize[]={12,10};
		weight=1200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=0;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,5};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"Knife",
			"Melee",
			"Shoulder1",
			"Shoulder2",
			"Shoulder3",
			"Pistol",
			"Headgear",
			"Mask",
			"Eyewear",
			"Gloves",
			"Body",
			"Armband",
			"Vest",
			"Back",
			"Hips",
			"Legs",
			"Feet"
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
					"Melee",
					"Shoulder1",
					"Shoulder2",
					"Shoulder3",
					"Pistol"
				};
				icon="Shoulder";
			};
			class Gear_Storge
			{
				name="Gear Storage";
				description="";
				attachmentSlots[]=
				{
					"Headgear",
					"Mask",
					"Eyewear",
					"Gloves",
					"Body",
					"Armband",
					"Vest",
					"Back",
					"Hips",
					"Legs",
					"Feet"
				};
				icon="Body";
			};
		};
	};
	class SausageGear_Storage_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Gear Storage HOLO";
		model="DZ\structures\furniture\cases\almara\almara.p3d";
	};
};