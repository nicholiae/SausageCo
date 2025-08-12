class CfgPatches
{
	class SC_Weapons_Optics
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
	class ItemOptics: Inventory_Base
	{};
	class SC_NV_M4_T3NRDSOptic: ItemOptics
	{
		scope=2;
		displayName="SC NV Red Dot Sight";
		descriptionShort="$STR_cfgVehicles_M4_T3NRDSOptic1";
		model="\DZ\weapons\attachments\optics\optic_t3n_rds.p3d";
		attachments[]=
		{
			"BatteryD"
		};
		animClass="Binoculars";
		simulation="itemoptics";
		inventorySlot[]=
		{
			"weaponOptics"
		};
		selectionFireAnim="zasleh";
		memoryPointCamera="eyeScope";
		cameraDir="cameraDir";
		rotationFlags=4;
		reversed=0;
		weight=265;
		itemSize[]={2,1};
		recoilModifier[]={1,1,1};
		swayModifier[]={1,1,1};
		hiddenSelections[]=
		{
			"reddot"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
		NVOptic=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"dz\weapons\attachments\optics\data\lensglass_ca.paa",
								"DZ\weapons\attachments\data\t3n.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"dz\weapons\attachments\optics\data\lensglass_damage_ca.paa",
								"DZ\weapons\attachments\data\t3n_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"dz\weapons\attachments\optics\data\lensglass_destruct_ca.paa",
								"DZ\weapons\attachments\data\t3n_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class OpticsInfo
		{
			memoryPointCamera="eyeScope";
			cameraDir="cameraDir";
			modelOptics="-";
			opticsDisablePeripherialVision=0.67000002;
			opticsFlare=1;
			opticsPPEffects[]={};
			opticsZoomMin=0.52359998;
			opticsZoomMax=0.52359998;
			opticsZoomInit=0.52359998;
			distanceZoomMin=25;
			distanceZoomMax=100;
			discreteDistance[]={25,50,100};
			discreteDistanceInitIndex=0;
			PPMaskProperties[]={0.5,0.5,0.40000001,0.050000001};
			PPLensProperties[]={1,0.15000001,0,0};
			PPBlurProperties=0.2;
			opticSightTexture="dz\weapons\attachments\optics\data\collimdot_red_ca.paa";
		};
		repairableWithKits[]={7};
		repairCosts[]={25};
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0.02;
			plugType=1;
			attachmentAction=1;
		};
	};
	class SC_NV_HuntingOptic: ItemOptics
	{
		scope=2;
		displayName="SC NV Hunting Optic";
		descriptionShort="$STR_cfgVehicles_HuntingOptic1";
		model="\DZ\weapons\attachments\optics\optic_hunting.p3d";
		animClass="Binoculars";
		rotationFlags=4;
		reversed=0;
		weight=700;
		itemSize[]={4,1};
		attachments[]=
		{
			"BatteryD"
		};
		inventorySlot[]=
		{
			"weaponOpticsHunting"
		};
		simulation="itemoptics";
		dispersionModifier=-0.00025000001;
		dispersionCondition="true";
		recoilModifier[]={1,1,1};
		swayModifier[]={1,1,1};
		memoryPointCamera="eyeScope_temp";
		cameraDir="cameraDir";
		NVOptic=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\attachments\optics\data\lensglass_ca.paa",
								"DZ\weapons\attachments\data\terra.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\attachments\optics\data\lensglass_damage_ca.paa",
								"DZ\weapons\attachments\data\terra_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\weapons\attachments\optics\data\lensglass_destruct_ca.paa",
								"DZ\weapons\attachments\data\terra_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0.02;
			plugType=1;
			attachmentAction=1;
		};
		class OpticsInfo
		{
			memoryPointCamera="eyeScope";
			cameraDir="cameraDir";
			useModelOptics=1;
			modelOptics="\DZ\weapons\attachments\optics\opticview_longrange.p3d";
			preloadOpticType="Preload2DOptic_Longrange";
			opticsDisablePeripherialVision=0.67000002;
			opticsFlare=1;
			opticsPPEffects[]=
			{
				"OpticsCHAbera3",
				"OpticsBlur1"
			};
			opticsZoomMin="0.3926/4";
			opticsZoomMax="0.3926/12";
			opticsZoomInit="0.3926/4";
			discretefov[]=
			{
				"0.3926/4",
				"0.3926/8",
				"0.3926/12"
			};
			discreteInitIndex=0;
			distanceZoomMin=100;
			distanceZoomMax=1000;
			discreteDistance[]={200,300,400,500,600,700,800};
			discreteDistanceInitIndex=0;
			PPMaskProperties[]={0.5,0.5,0.43000001,0.1};
			PPLensProperties[]={0.30000001,0.15000001,0,0};
			PPBlurProperties=0.30000001;
		};
		class AnimationSources
		{
			class hide
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class rings_ris
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class rings_ris_pilot
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class rings_winchester
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class rings_winchester_pilot
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
		};
	};
	class SC_NV_ACOGOptic: ItemOptics
	{
		scope=2;
		displayName="SC NV ACOG";
		descriptionShort="$STR_cfgVehicles_ACOGOptic1";
		model="\DZ\weapons\attachments\optics\optic_acog.p3d";
		animClass="Binoculars";
		rotationFlags=16;
		reversed=0;
		weight=440;
		itemSize[]={2,1};
		attachments[]=
		{
			"BatteryD"
		};
		inventorySlot[]=
		{
			"WeaponOptics"
		};
		selectionFireAnim="zasleh";
		simulation="itemoptics";
		dispersionModifier=-0.00012500001;
		dispersionCondition="true";
		recoilModifier[]={1,1,1};
		swayModifier[]={1,1,1};
		memoryPointCamera="eyeScope";
		cameraDir="cameraDir";
		NVOptic=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\attachments\data\scope_alpha_clear_ca.paa",
								"DZ\weapons\attachments\optics\data\lensglass_standard.rvmat",
								"DZ\weapons\attachments\data\acog.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\attachments\data\scope_alpha_damaged_ca.paa",
								"DZ\weapons\attachments\optics\data\lensglass_standard_damage.rvmat",
								"DZ\weapons\attachments\data\acog_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\weapons\attachments\data\scope_alpha_destroyed_ca.paa",
								"DZ\weapons\attachments\optics\data\lensglass_standard_destruct.rvmat",
								"DZ\weapons\attachments\data\acog_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0.02;
			plugType=1;
			attachmentAction=1;
		};
		class OpticsInfo
		{
			memoryPointCamera="eyeScope";
			cameraDir="cameraDir";
			modelOptics="-";
			opticsDisablePeripherialVision=0.67000002;
			opticsFlare=1;
			opticsPPEffects[]={};
			opticsZoomMin="0.3926/4";
			opticsZoomMax="0.3926/4";
			opticsZoomInit="0.3926/4";
			distanceZoomMin=100;
			distanceZoomMax=600;
			discreteDistance[]={100,200,300,400,500,600};
			discreteDistanceInitIndex=0;
			PPMaskProperties[]={0.5,0.5,0.375,0.050000001};
			PPLensProperties[]={0.5,0.15000001,0,0};
			PPBlurProperties=0.60000002;
		};
		class OpticsInfoWeaponOverride
		{
			memoryPointCamera="eyeIronsights";
			cameraDir="cameraDirIronsights";
			opticsZoomMin=0.52359998;
			opticsZoomMax=0.52359998;
			opticsZoomInit=0.52359998;
			distanceZoomMin=200;
			distanceZoomMax=200;
			discreteDistance[]={200};
			discreteDistanceInitIndex=0;
			PPMaskProperties[]={0.5,0.5,0.375,0.050000001};
			PPLensProperties[]={0.5,0.15000001,0,0};
			PPBlurProperties=0.60000002;
			PPDOFProperties[]={1,0.1,20,200,4,10};
		};
	};
};