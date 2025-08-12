class CfgPatches
{
	class DZ_SausageLivingroom_Couch
	{
		units[]={
			"SausageLivingroom_Couch"
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
	class Slot_Back1
	{
		name="Back1";
		displayName="Back1";
		ghostIcon="back";
		show="true";
	};
	class Slot_Back2
	{
		name="Back2";
		displayName="Back2";
		ghostIcon="back";
		show="true";
	};
	class Slot_Back3
	{
		name="Back3";
		displayName="Back3";
		ghostIcon="back";
		show="true";
	};
	class Slot_Back4
	{
		name="Back4";
		displayName="Back4";
		ghostIcon="back";
		show="true";
	};
};
class CfgVehicles
{
	class Container_Base;
	class SausageLivingroom_Couch: Container_Base
	{
		scope=2;
		displayName="SausageCo Couch";
		model="\SausageCo\storage\Livingroom\Couch\SausageCouch.p3d";
		descriptionShort="Couch for your Livingroom back at base.";
		itemSize[]={12,10};
		weight=7500;
		carveNavmesh=1;
		visibilityModifier=0.0;
		canBeDigged=0;
		alignHologramToTerain=1;
		heavyItem=1;
		itemBehaviour=2;
		physLayer="item_large";
		rotationFlags=2;
		class Cargo
		{
			itemsCargoSize[]={10,10};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"Back",
			"Back1",
			"Back2",
			"Back3",
			"Back4"
		};
		class GUIInventoryAttachmentsProps
		{
			class Gear_Storage
			{
				name="Backpack Storage";
				description="";
				attachmentSlots[]=
				{
					"Back",
					"Back1",
					"Back2",
					"Back3",
					"Back4"
				};
				icon="back";
			};
		};
	};
	class SausageLivingroom_Couch_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Couch HOLO";
		model="\SausageCo\storage\Livingroom\Couch\SausageCouch.p3d";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyBack: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"Back"
		};
		model="\SausageCo\storage\Livingroom\Couch\proxies\Back.p3d";
	};
	class ProxyBack1: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"Back1"
		};
		model="\SausageCo\storage\Livingroom\Couch\proxies\Back1.p3d";
	};
	class ProxyBack2: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"Back2"
		};
		model="\SausageCo\storage\Livingroom\Couch\proxies\Back2.p3d";
	};
	class ProxyBack3: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"Back3"
		};
		model="\SausageCo\storage\Livingroom\Couch\proxies\Back3.p3d";
	};
	class ProxyBack4: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"Back4"
		};
		model="\SausageCo\storage\Livingroom\Couch\proxies\Back4.p3d";
	};
};