class CfgPatches
{
	class DZ_Gear_Tools
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Weapons_Melee"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Switchable_Base;
	class Powered_Base;
	class FishingRod_Base;
	class SC_FishingRod_Base: FishingRod_Base
	{};
	class SC_FishingRod: SC_FishingRod_Base
	{
		scope=2;
		displayName="Improved Fishing Rod";
		descriptionShort="Your better off catching things with this, promise!";
		model="\dz\gear\tools\fishing_rod.p3d";
		rotationFlags=12;
		weight=910;
		itemSize[]={2,5};
		absorbency=0;
		attachments[]=
		{
			"Hook"
		};
		energyResources[]=
		{
			
			{
				"power",
				0.55000001
			}
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=450;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\tools\data\fishing_rod.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\tools\data\fishing_rod.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\tools\data\fishing_rod_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\tools\data\fishing_rod_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\tools\data\fishing_rod_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimationSources
		{
			class AnimateRod
			{
				source="user";
				initPhase=0;
				animPeriod=0.69999999;
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeLightBlunt";
				range=1.8;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1.8;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=3.7;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Fishing_in_SoundSet
				{
					soundSet="Fishing_in_SoundSet";
					id=201;
				};
				class Fishing_check_SoundSet
				{
					soundSet="Fishing_check_SoundSet";
					id=202;
				};
				class Fishing_cancel_SoundSet
				{
					soundSet="Fishing_cancel_SoundSet";
					id=203;
				};
				class FishingRod_extend_SoundSet
				{
					soundSet="FishingRod_extend_SoundSet";
					id=204;
				};
				class FishingRod_retract_SoundSet
				{
					soundSet="FishingRod_retract_SoundSet";
					id=205;
				};
				class Fishing_puddle_SoundSet
				{
					soundSet="Fishing_puddle_SoundSet";
					id=206;
				};
				class Fishing_splash_SoundSet
				{
					soundSet="Fishing_splash_SoundSet";
					id=207;
				};
				class Fishing_splash_small_SoundSet
				{
					soundSet="Fishing_splash_small_SoundSet";
					id=208;
				};
				class Fish_struggling_SoundSet
				{
					soundSet="Fish_struggling_SoundSet";
					id=209;
				};
			};
		};
	};
	class Bait: Inventory_Base
	{};
	class SC_Lure: Bait
	{
		scope=2;
		displayName="Lure";
		descriptionShort="No need for bait";
		model="\dz\gear\consumables\bait_worm_pinned.p3d";
		weight=15;
		absorbency=0.80000001;
		itemSize[]={1,1};
		inventorySlot[]=
		{
			"Hook"
		};
		rotationFlags=17;
		hookType="Hook";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=90;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\consumables\data\bait.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\consumables\data\bait.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\consumables\data\bait_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\consumables\data\bait_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\consumables\data\bait_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimationSources
		{
			class cover
			{
				source="user";
				animPeriod=0.5;
				initPhase=1;
			};
		};
	};
	class BoneBait: Inventory_Base
	{};
	class SC_BoneLure: BoneBait
	{
		scope=2;
		displayName="BoneLure";
		descriptionShort="No need for bait";
		model="\dz\gear\crafting\bone_bait.p3d";
		weight=15;
		absorbency=0.80000001;
		itemSize[]={1,1};
		inventorySlot[]=
		{
			"Hook"
		};
		rotationFlags=17;
		hookType="BoneHook";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\crafting\data\bone_hook.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\crafting\data\bone_hook.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\crafting\data\bone_hook_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\crafting\data\bone_hook_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\crafting\data\bone_hook_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimationSources
		{
			class cover
			{
				source="user";
				animPeriod=0.5;
				initPhase=1;
			};
		};
	};
};
