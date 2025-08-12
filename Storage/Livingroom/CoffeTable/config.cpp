class CfgPatches
{
	class DZ_SausageLivingroom_CoffeeTable
	{
		units[]={
			"SausageLivingroom_CoffeeTable"
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
	class SausageLivingroom_CoffeeTable: Container_Base
	{
		scope=2;
		displayName="SausageCo CoffeeTable";
		model="\DZ\structures\furniture\tables\lobby_table\lobby_table.p3d";
		descriptionShort="CoffeeTable for your Livingroom back at base.";
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
					"Melee",
					"Pistol"
				};
				icon="Shoulder";
			};
		};
	};
	class SausageLivingroom_CoffeeTable_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "CoffeeTable HOLO";
		model="\DZ\structures\furniture\tables\lobby_table\lobby_table.p3d";
	};
};