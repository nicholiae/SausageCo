class CfgPatches
{
	class SC_Weapons_Supports
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
class cfgVehicles
{
	class Inventory_Base;
	class ButtStockSC_SCARL: Inventory_Base
	{
		scope=2;
		displayName="SCARL ButtStock";
		descriptionShort="Tactical ButtStock for the SCAR-L";
		model="SausageCo\Weapons\attachments\buttstock\ButtStockSC_SCARL.p3d";
		rotationFlags=17;
		reversed=0;
		inventorySlot[]=
		{
			"ButtStockSC_SCARL"
		};
		weight=354;
		itemSize[]={2,1};
		dispersionModifier=-0.00019999999;
		dispersionCondition="true";
		recoilModifier[]={0.80000001,0.80000001,0.80000001};
		swayModifier[]={1,1,1};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\Weapons\data\Baige.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						}
					};
				};
			};
		};
		isMeleeWeapon=1;
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeLightBlunt";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=2.8;
			};
		};
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyButtStockSC_SCARL: ProxyAttachment
	{
		scope=2;
		inventorySlot="ButtStockSC_SCARL";
		model="SausageCo\Weapons\attachments\buttstock\ButtStockSC_SCARL.p3d";
	};
};