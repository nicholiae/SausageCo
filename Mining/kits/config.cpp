class CfgPatches
{
	class SausageMining_Base_Kit
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class Container_Base;
	class WoodenCrate: Container_Base
	{
	};
	class SausageMining_Kit_Base: WoodenCrate
	{
		scope=0;
		displayName="";
		descriptionShort="";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={3,2};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class SausageFurnace_Kit: SausageMining_Kit_Base
	{
		scope=2;
		displayName="SmeltingFurnace Kit";
		descriptionShort="Furnace kit can be deployed into a working furnace used to smelt down ores into bars";
	};
	class SausageAnvil_Kit: SausageMining_Kit_Base
	{
		scope=2;
		displayName="CraftingAnvil Kit";
		descriptionShort="Anvil kit can be deployed into an interactable Anvil. Using ore bars with the anvil will allow you to craft various recipes.";
	};
};
