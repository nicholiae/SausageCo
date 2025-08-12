class CfgPatches
{
	class DZ_SausageCo_CasingsProcessor
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
	class Slot_SCAS_casings
	{
		name="SCAS_casings";
		displayName="SCAS_casings"; 
		ghostIcon="missing";
		show="true";
	};
	class Slot_SCAS_casingsFilled
	{
		name="SCAS_casingsFilled";
		displayName="SCAS_casingsFilled"; 
		ghostIcon="missing";
		show="true";
	};
	class Slot_SCAS_gunpowder
	{
		name="SCAS_gunpowder";
		displayName="SCAS_gunpowder"; 
		ghostIcon="missing";
		show="true";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class SausageCo_CasingsProcessor: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Casings Processor";
		model="\DZ\structures\furniture\various\drill.p3d";
		descriptionShort="Used for processing empty casings and gunpowder, MAKE SURE YOU HAVE ATLEAST 1 FULLCASING in the Last attachmentslot!";
		overrideDrawArea="3.0";
		slopeTolerance=0.30000001;
		lootCategory="Crafted";
		itemSize[]={10,15};
		weight=10000;
		itemBehaviour=0;
		quantityBar=0;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		stackedUnit="";
		attachments[]=
		{	
			"SCAS_gunpowder",
			"SCAS_casings",
			"SCAS_casingsFilled",
		};
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		canBeDigged=0;
		physLayer="item_large";
		class GUIInventoryAttachmentsProps
		{
			class gunpowder_Storage
			{
				name="Gunpowder Storage";
				description="";
				attachmentSlots[]=
				{
					"SCAS_gunpowder",
				};
				icon="missing";
			};
			class casing_storage
			{
				name="Casings Storage";
				description="";
				attachmentSlots[]=
				{
					"SCAS_casings",
				};
				icon="missing";
			};
			class casingFilled_storage
			{
				name="CasingsFilled Storage";
				description="";
				attachmentSlots[]=
				{
					"SCAS_casingsFilled",
				};
				icon="missing";
			};
		};
		hiddenSelections[]=
		{
			
		};
		class Cargo
		{	
			itemsCargoSize[]={10,10};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		class AnimEvents
		{
		
		};
	};
	class SausageCo_CasingsProcessor_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "CasingsProcessor HOLO";
		model="\DZ\structures\furniture\various\drill.p3d";
	};
};