class CfgPatches
{
	class DZ_SausageBedroom_Hopechest
	{
		units[]={
			"SausageBedroom_Hopechest"
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
	class SausageBedroom_Hopechest: Container_Base
	{
		scope=2;
		displayName="SausageCo Hopechest";
		model="\DZ\structures\furniture\various\chest_dz.p3d";
		descriptionShort="Hopechest for your bedrooms back at base.";
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
	class SausageBedroom_Hopechest_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Hopechest HOLO";
		model="\DZ\structures\furniture\various\chest_dz.p3d";
	};
};