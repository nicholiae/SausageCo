class CfgPatches
{
	class NichosItemStacking
	{
		units[]=
		{
			
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Consumables",
			"DZ_Gear_Tools",
			"DZ_Gear_Camping",
			"DZ_Gear_Crafting",
			"DZ_Gear_Containers",
			"DZ_Weapons_Melee",
			"DZ_Gear_Cooking",
			"DZ_Gear_Medical",
			"DZ_Weapons_Magazines"
		};
	};
};
class CfgMagazines
{
	class Magazine_Base;
	class Ammunition_Base: Magazine_Base
	{
		itemSize[]={1,1};
		count=100;
	};
	class Ammo_45ACP: Ammunition_Base
	{
		count=250;
		inventorySlot[]=
		{
			"Ammo45ACP"	
		};
	};
	class Ammo_9x19: Ammunition_Base
	{
		count=250;
		inventorySlot[]=
		{
			"Ammo9x19"	
		};
	};
	class Ammo_380: Ammunition_Base
	{
		count=350;
		inventorySlot[]=
		{
			"Ammo380"	
		};
	};
	class Ammo_556x45: Ammunition_Base
	{
		count=200;
		inventorySlot[]=
		{
			"Ammo556x45"	
		};
	};
	class Ammo_556x45Tracer: Ammunition_Base
	{
		count=200;
		inventorySlot[]=
		{
			"Ammo556x45"	
		};
	};
	class Ammo_762x54: Ammunition_Base
	{
		count=200;
		inventorySlot[]=
		{
			"Ammo762x54"	
		};
	};
	class Ammo_762x54Tracer: Ammunition_Base
	{
		count=200;
		inventorySlot[]=
		{
			"Ammo762x54"	
		};
	};
	class Ammo_762x39: Ammunition_Base
	{
		count=200;
		inventorySlot[]=
		{
			"Ammo762x39"	
		};
	};
	class Ammo_762x39Tracer: Ammunition_Base
	{
		count=200;
		inventorySlot[]=
		{
			"Ammo762x39"	
		};
	};
	class Ammo_9x39AP: Ammunition_Base
	{
		count=200;
		inventorySlot[]=
		{
			"Ammo9x39"	
		};
	};
	class Ammo_9x39: Ammunition_Base
	{
		count=200;
		inventorySlot[]=
		{
			"Ammo9x39"	
		};
	};
	class Ammo_357: Ammunition_Base
	{
		count=200;
		inventorySlot[]=
		{
			"Ammo357"	
		};
	};
	class Ammo_545x39: Ammunition_Base
	{
		count=200;
		inventorySlot[]=
		{
			"Ammo545x39"	
		};
	};
	class Ammo_545x39Tracer: Ammunition_Base
	{
		count=200;
		inventorySlot[]=
		{
			"Ammo545x39"	
		};
	};
	class Ammo_22: Ammunition_Base
	{
		count=500;
		inventorySlot[]=
		{
			"Ammo22"	
		};
	};
	class Ammo_12gaPellets: Ammunition_Base
	{
		count=100;
	};
	class Ammo_12gaSlug: Ammunition_Base
	{
		count=100;
	};
	class Ammo_12gaRubberSlug: Ammunition_Base
	{
		count=100;
	};
	class Ammo_12gaBeanbag: Ammunition_Base
	{
		count=100;
	};
	class Ammo_308WinTracer: Ammunition_Base
	{
		count=100;
		inventorySlot[]=
		{
			"Ammo308Win"	
		};
	};
	class Ammo_308Win: Ammunition_Base
	{
		count=100;
		inventorySlot[]=
		{
			"Ammo308Win"	
		};
	};
	
};