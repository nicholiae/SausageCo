class CfgPatches
{
	class DZ_SausageGarage_GunRack_Item
	{
		units[]={
			"SausageGarage_Gunrack"
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
	class SausageGarage_Gunrack: Container_Base
	{
		scope=2;
		displayName="SausageCo Gunrack";
		model="DZ\structures\military\misc\misc_gunrack.p3d";
		descriptionShort="A gunrack with 24 slots for weapons.";
		itemsCargoSize[]={0,0};
		itemSize[]={11,11};
		canBeDigged=0;
		overrideDrawArea="8.0";
		placement="ForceSlopeOnTerrain";		
		destroyOnEmpty=0;
		quantityBar=0;
		varQuantityMax=0;
		carveNavmesh=1;
		heavyItem=1;
		weight=10000;
		itemBehaviour=0;
		physLayer="item_large";
		allowOwnedCargoManipulation=1;
		attachments[]=
		{	
			"Shoulder1",
			"Shoulder2",
			"Shoulder3",
			"Shoulder4",
			"Shoulder5",
			"Shoulder6",
			"Shoulder7",
			"Shoulder8",
			"Shoulder9",
			"Shoulder10",
			"Shoulder11",
			"Shoulder12",
			"Shoulder13",
			"Shoulder14",
			"Shoulder15",
			"Shoulder16",
			"Shoulder17",
			"Shoulder18",
			"Shoulder19",
			"Shoulder20",
			"Shoulder21",
			"Shoulder22",
			"Shoulder23",
			"Shoulder24"	
		};
		class GUIInventoryAttachmentsProps
		{
			class Weapons_Storage
			{
				name="Left Storage";
				description="";
				attachmentSlots[]=
				{
					"Shoulder1",
					"Shoulder2",
					"Shoulder3",
					"Shoulder4",
					"Shoulder5",
					"Shoulder6",
					"Shoulder7",
					"Shoulder8",
					"Shoulder9",
					"Shoulder10",
					"Shoulder11",
					"Shoulder12"
				};
				icon="Shoulder";
			};
			class Weapons_Storage2
			{
				name="Right Storage2";
				description="";
				attachmentSlots[]=
				{
					"Shoulder13",
					"Shoulder14",
					"Shoulder15",
					"Shoulder16",
					"Shoulder17",
					"Shoulder18",
					"Shoulder19",
					"Shoulder20",
					"Shoulder21",
					"Shoulder22",
					"Shoulder23",
					"Shoulder24"
				};
				icon="Shoulder";
			};
		};
	};
	class SausageGarage_Gunrack_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Gunrack HOLO";
		model="DZ\structures\military\misc\misc_gunrack.p3d";
	};
};