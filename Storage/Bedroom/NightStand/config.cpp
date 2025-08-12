class CfgPatches
{
	class DZ_SausageBedroom_NightStand
	{
		units[]={
			"SausageBedroom_NightStand"
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
	class SausageBedroom_NightStand: Container_Base
	{
		scope=2;
		displayName="SausageCo NightStand";
		model="\DZ\structures_bliss\ruins\proxy\case_bedroom_a.p3d";
		descriptionShort="NightStand for your bedrooms back at base.";
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
					"Pistol"
				};
				icon="Shoulder";
			};
		};
	};
	class SausageBedroom_NightStand_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "NightStand HOLO";
		model="\DZ\structures_bliss\ruins\proxy\case_bedroom_a.p3d";
	};
};