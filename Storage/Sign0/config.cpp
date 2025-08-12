class CfgPatches
{
	class DZ_SausageBuilding_Sign0
	{
		units[]={
			"SausageBuilding_Sign0"
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
	class SausageBuilding_Sign0: Container_Base
	{
		scope=2;
		displayName="BaseSign# 0";
		model = "SausageCo\storage\data\billboard1.p3d";
		descriptionShort="Can be deployed into a sign that says 'Trespassers WILL be SHOT on sight' and yes, you can shoot on sight with this sign on your base. Players must be within 75m of this sign for this to apply! Created by Nicholiae.";
		hiddenSelections[]=
		{
			"panel",
			"bags",
			"camo",
			"xlights_glass_r",
			"xlights_glass_g",
			"xlights_glass_b",
			"xlights_glass_y"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\data\Addons\Trespassers.paa"
		};
		itemSize[]={12,12};
		weight=2400;
		canBeDigged=0;
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";		
		carveNavmesh=0;
		physLayer="item_small";	
		class Cargo
		{
			itemsCargoSize[]={10,2};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"CamoNet",
			"Lights"
			
		};
		class GUIInventoryAttachmentsProps
		{
			class ChristmasLights
			{
				name="ChristmasLights";
				description="";
				attachmentSlots[]=
				{
					"CamoNet",
					"Lights"
				};
				icon="christmaslights";
			};
		};
	};
	class SausageBuilding_Sign0_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "BaseSign HOLO";
		model="SausageCo\storage\data\billboard1.p3d";
	};
};