class CfgPatches
{
	class DZ_SausageBedroom_Dressor
	{
		units[]={
			"SausageBedroom_Dressor"
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
	class SausageBedroom_Dressor: Container_Base
	{
		scope=2;
		displayName="SausageCo Dressor";
		model="DZ\structures\furniture\school_equipment\class_case_b_closed.p3d";
		descriptionShort="Dressor for your bedrooms back at base.";
		itemSize[]={13,11};
		weight=1200;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=1;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,20};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"Knife",
			"Melee",
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
	class SausageBedroom_Dressor_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Dressor HOLO";
		model="DZ\structures\furniture\school_equipment\class_case_b_closed.p3d";
	};
};