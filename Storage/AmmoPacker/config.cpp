class CfgPatches
{
	class DZ_SausageAmmo_Packer
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
	class Slot_Magazine45ACP
	{
		name="Magazine45ACP";
		displayName="45ACP"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine22
	{
		name="Magazine22";
		displayName="22"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine357
	{
		name="Magazine357";
		displayName="357"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine9x39
	{
		name="Magazine9x39";
		displayName="9x39"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine9x19
	{
		name="Magazine9x19";
		displayName="9x19"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine380
	{
		name="Magazine380";
		displayName="380"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine545x39
	{
		name="Magazine545x39";
		displayName="545x39"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine556x45
	{
		name="Magazine556x45";
		displayName="556x45"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine762x39
	{
		name="Magazine762x39";
		displayName="762x39"; 
		ghostIcon="";
		show="true";
	};
	class Slot_Magazine762x54
	{
		name="Magazine762x54";
		displayName="762x54"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine308Win
	{
		name="Magazine308Win";
		displayName="308Win"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine45ACP_2
	{
		name="Magazine45ACP_2";
		displayName="45ACP"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine22_2
	{
		name="Magazine22_2";
		displayName="22"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine357_2
	{
		name="Magazine357_2";
		displayName="357"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine9x39_2
	{
		name="Magazine9x39_2";
		displayName="9x39"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine9x19_2
	{
		name="Magazine9x19_2";
		displayName="9x19"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine380_2
	{
		name="Magazine380_2";
		displayName="380"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine545x39_2
	{
		name="Magazine545x39_2";
		displayName="545x39"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine556x45_2
	{
		name="Magazine556x45_2";
		displayName="556x45"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine762x39_2
	{
		name="Magazine762x39_2";
		displayName="762x39"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine762x54_2
	{
		name="Magazine762x54_2";
		displayName="762x54"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Magazine308Win_2
	{
		name="Magazine308Win_2";
		displayName="308Win"; 
		ghostIcon="magazine";
		show="true";
	};
	class Slot_Ammo45ACP
	{
		name="Ammo45ACP";
		displayName="45ACP"; 
		ghostIcon="";
		show="true";
	};
	class Slot_Ammo22
	{
		name="Ammo22";
		displayName="22"; 
		ghostIcon="";
		show="true";
	};
	class Slot_Ammo357
	{
		name="Ammo357";
		displayName="357"; 
		ghostIcon="";
		show="true";
	};
	class Slot_Ammo9x39
	{
		name="Ammo9x39";
		displayName="9x39"; 
		ghostIcon="";
		show="true";
	};
	class Slot_Ammo9x19
	{
		name="Ammo9x19";
		displayName="9x19"; 
		ghostIcon="";
		show="true";
	};
	class Slot_Ammo380
	{
		name="Ammo380";
		displayName="380"; 
		ghostIcon="";
		show="true";
	};
	class Slot_Ammo545x39
	{
		name="Ammo545x39";
		displayName="545x39"; 
		ghostIcon="";
		show="true";
	};
	class Slot_Ammo556x45
	{
		name="Ammo556x45";
		displayName="556x45"; 
		ghostIcon="";
		show="true";
	};
	class Slot_Ammo762x39
	{
		name="Ammo762x39";
		displayName="762x39"; 
		ghostIcon="";
		show="true";
	};
	class Slot_Ammo762x54
	{
		name="Ammo762x54";
		displayName="762x54"; 
		ghostIcon="";
		show="true";
	};
	class Slot_Ammo308Win
	{
		name="Ammo308Win";
		displayName="308Win"; 
		ghostIcon="";
		show="true";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class SausageAmmo_Packer: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Ammo Processor";
		model="\DZ\structures\furniture\various\soustruh_proxy.p3d";
		descriptionShort="Used for packing ammunition into magazines";
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
			"Ammo45ACP",
			"Magazine45ACP",
			"Magazine45ACP_2",
			"Ammo22",
			"Magazine22",
			"Magazine22_2",
			"Ammo357",
			"Magazine357",
			"Magazine357_2",
			"Ammo9x39",
			"Magazine9x39",
			"Magazine9x39_2",
			"Ammo9x19",
			"Magazine9x19",
			"Magazine9x19_2",
			"Ammo380",
			"Magazine380",
			"Magazine380_2",
			"Ammo545x39",
			"Magazine545x39",
			"Magazine545x39_2",
			"Ammo556x45",
			"Magazine556x45",
			"Magazine556x45_2",
			"Ammo762x39",
			"Magazine762x39",
			"Magazine762x39_2",
			"Ammo762x54",
			"Magazine762x54",
			"Magazine762x54_2",
			"Ammo308Win",
			"Magazine308Win",
			"Magazine308Win_2"
		};
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		canBeDigged=0;
		physLayer="item_large";
		class GUIInventoryAttachmentsProps
		{
			class Ammo45ACP_Storage
			{
				name="45ACP Storage";
				description="";
				attachmentSlots[]=
				{
					"Ammo45ACP",
					"Magazine45ACP",
					"Magazine45ACP_2"
				};
				icon="magazine2";
			};
			class Ammo22_Storage
			{
				name="22 Storage";
				description="";
				attachmentSlots[]=
				{
					"Ammo22",
					"Magazine22",
					"Magazine22_2"
				};
				icon="magazine2";
			};
			class Ammo357_Storage
			{
				name="357 Storage";
				description="";
				attachmentSlots[]=
				{
					"Ammo357",
					"Magazine357",
					"Magazine357_2"
				};
				icon="magazine2";
			};
			class Ammo9x39_Storage
			{
				name="9x39 Storage";
				description="";
				attachmentSlots[]=
				{
					"Ammo9x39",
					"Magazine9x39",
					"Magazine9x39_2"
				};
				icon="magazine2";
			};
			class Ammo9x19_Storage
			{
				name="9x19 Storage";
				description="";
				attachmentSlots[]=
				{
					"Ammo9x19",
					"Magazine9x19",
					"Magazine9x19_2"
				};
				icon="magazine2";
			};
			class Ammo380_Storage
			{
				name="380 Storage";
				description="";
				attachmentSlots[]=
				{
					"Ammo380",
					"Magazine380",
					"Magazine380_2"
				};
				icon="magazine2";
			};
			class Ammo545x39_Storage
			{
				name="545x39 Storage";
				description="";
				attachmentSlots[]=
				{
					"Ammo545x39",
					"Magazine545x39",
					"Magazine545x39_2"
				};
				icon="magazine2";
			};
			class Ammo556x45_Storage
			{
				name="556x45 Storage";
				description="";
				attachmentSlots[]=
				{
					"Ammo556x45",
					"Magazine556x45",
					"Magazine556x45_2"
				};
				icon="magazine2";
			};
			class Ammo762x39_Storage
			{
				name="762x39 Storage";
				description="";
				attachmentSlots[]=
				{
					"Ammo762x39",
					"Magazine762x39",
					"Magazine762x39_2"
				};
				icon="magazine2";
			};
			class Ammo762x54_Storage
			{
				name="762x54 Storage";
				description="";
				attachmentSlots[]=
				{
					"Ammo762x54",
					"Magazine762x54",
					"Magazine762x54_2"
				};
				icon="magazine2";
			};
			class Ammo308Win_Storage
			{
				name="308 Storage";
				description="";
				attachmentSlots[]=
				{
					"Ammo308Win",
					"Magazine308Win",
					"Magazine308Win_2"
				};
				icon="magazine2";
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
	class SausageAmmo_Packer_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "AmmoPacker HOLO";
		model="\DZ\structures\furniture\various\soustruh_proxy.p3d";
	};
};