class CfgPatches
{
	class SC_Tools_Extra
	{
		units[]={
			"SC_Pickaxe_Blood",
			"SC_Pickaxe_Presem",
			"SC_Pickaxe_Rune",
			"SC_Pickaxe_Jade",
			"SC_Pickaxe_Gold",
			"SC_Pickaxe_Silver",
			"SC_Pickaxe_Copper",
			"SC_Hatchet_Blood",
			"SC_Hatchet_Presem",
			"SC_Hatchet_Rune",
			"SC_Hatchet_Jade",
			"SC_Hatchet_Gold",
			"SC_Hatchet_Silver",
			"SC_Hatchet_Copper"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Weapons_Melee"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Hatchet: Inventory_Base
	{
		scope=2;
		displayName="$STR_CfgVehicles_Hatchet0";
		descriptionShort="$STR_CfgVehicles_Hatchet1";
		model="\dz\weapons\melee\blade\hatchet.p3d";
		debug_ItemCategory=2;
		build_action_type=10;
		dismantle_action_type=74;
		repairableWithKits[]={4};
		repairCosts[]={18};
		rotationFlags=17;
		weight=1000;
		itemSize[]={2,4};
		fragility=0.0099999998;
		lootCategory="Tools";
		lootTag[]=
		{
			"Work",
			"Forester",
			"Camping"
		};
		itemInfo[]=
		{
			"Axe"
		};
		inventorySlot[]=
		{
			"Backpack_1"
		};
		openItemSpillRange[]={20,40};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=150;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\melee\blade\data\hatchet.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\melee\blade\data\hatchet.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\melee\blade\data\hatchet_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\melee\blade\data\hatchet_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\melee\blade\data\hatchet_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeSharpLight_2";
				range=1.4;
			};
			class Heavy
			{
				ammo="MeleeSharpHeavy_2";
				range=1.4;
			};
			class Sprint
			{
				ammo="MeleeSharpHeavy_2";
				range=3.3;
			};
		};
		isMeleeWeapon=1;
		suicideAnim="woodaxe";
		soundImpactType="metal";
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup_light
				{
					soundSet="hatchet_pickup_light_SoundSet";
					id=796;
				};
				class pickup
				{
					soundSet="hatchet_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="woodaxe_drop_SoundSet";
					id=898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet="FirefighterAxe_loop_SoundSet";
					id=1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet="FirefighterAxe_end_SoundSet";
					id=1122;
				};
				class ShoulderR_Hide
				{
					soundset="ShoulderR_Hide_SoundSet";
					id=1210;
				};
				class ShoulderR_Show
				{
					soundset="ShoulderR_Show_SoundSet";
					id=1211;
				};
				class WoodHammer_SoundSet
				{
					soundSet="WoodHammer_SoundSet";
					id=11161;
				};
				class animalSkinning_in
				{
					soundSet="animalSkinning_in_SoundSet";
					id=516;
				};
				class animalSkinning
				{
					soundSet="animalSkinning_SoundSet";
					id=517;
				};
				class animalSkinning_out
				{
					soundSet="animalSkinning_out_SoundSet";
					id=518;
				};
			};
			class Sound
			{
				class SurfaceDig
				{
					class DigPrimary
					{
						default=907;
						sakhal_snow=907;
						sakhal_snow_forest=907;
						sakhal_grass_brown=907;
					};
				};
			};
		};
	};
	class Hacksaw: Inventory_Base
	{
		scope=2;
		displayName="$STR_CfgVehicles_Hacksaw0";
		descriptionShort="$STR_CfgVehicles_Hacksaw1";
		model="\dz\weapons\melee\blade\Hacksaw.p3d";
		debug_ItemCategory=2;
		build_action_type=10;
		dismantle_action_type=74;
		repairableWithKits[]={4};
		repairCosts[]={18};
		rotationFlags=17;
		weight=1000;
		itemSize[]={2,4};
		fragility=0.0099999998;
		lootCategory="Tools";
		lootTag[]=
		{
			"Work",
			"Forester",
			"Camping"
		};
		itemInfo[]=
		{
			"Axe"
		};
		inventorySlot[]=
		{
			"Backpack_1"
		};
		openItemSpillRange[]={20,40};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=150;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\melee\blade\data\Hacksaw.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\melee\blade\data\Hacksaw.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\melee\blade\data\Hacksaw_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\melee\blade\data\Hacksaw_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\melee\blade\data\Hacksaw_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeSharpLight_2";
				range=1.4;
			};
			class Heavy
			{
				ammo="MeleeSharpHeavy_2";
				range=1.4;
			};
			class Sprint
			{
				ammo="MeleeSharpHeavy_2";
				range=3.3;
			};
		};
		isMeleeWeapon=1;
		suicideAnim="woodaxe";
		soundImpactType="metal";
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup_light
				{
					soundSet="Hacksaw_pickup_light_SoundSet";
					id=796;
				};
				class pickup
				{
					soundSet="Hacksaw_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="woodaxe_drop_SoundSet";
					id=898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet="FirefighterAxe_loop_SoundSet";
					id=1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet="FirefighterAxe_end_SoundSet";
					id=1122;
				};
				class ShoulderR_Hide
				{
					soundset="ShoulderR_Hide_SoundSet";
					id=1210;
				};
				class ShoulderR_Show
				{
					soundset="ShoulderR_Show_SoundSet";
					id=1211;
				};
				class WoodHammer_SoundSet
				{
					soundSet="WoodHammer_SoundSet";
					id=11161;
				};
				class animalSkinning_in
				{
					soundSet="animalSkinning_in_SoundSet";
					id=516;
				};
				class animalSkinning
				{
					soundSet="animalSkinning_SoundSet";
					id=517;
				};
				class animalSkinning_out
				{
					soundSet="animalSkinning_out_SoundSet";
					id=518;
				};
			};
			class Sound
			{
				class SurfaceDig
				{
					class DigPrimary
					{
						default=907;
						sakhal_snow=907;
						sakhal_snow_forest=907;
						sakhal_grass_brown=907;
					};
				};
			};
		};
	};
	class SC_Hacksaw_Blood: Hacksaw
	{
		displayName="Blood Hacksaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\BloodHacksaw_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=2500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawBlood.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawBlood.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damageBlood.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damageBlood.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_destructBlood.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hacksaw_Copper: Hacksaw
	{
		displayName="Copper Hacksaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\CopperHacksaw_co.paa"
		};
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
								"SausageCo\objects\ExtraTools\data\SCHacksawCopper.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawCopper.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damageCopper.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damageCopper.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_destructCopper.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hacksaw_Rune: Hacksaw
	{
		displayName="Rune Hacksaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\RuneHacksaw_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawRune.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawRune.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damageRune.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damageRune.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_destructRune.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hacksaw_Silver: Hacksaw
	{
		displayName="Silver Hacksaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\SilverHacksaw_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=750;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawSilver.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawSilver.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damageSilver.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damageSilver.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_destructSilver.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hacksaw_Jade: Hacksaw
	{
		displayName="Jade Hacksaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\JadeHacksaw_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawJade.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawJade.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damageJade.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damageJade.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_destructJade.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hacksaw_Presem: Hacksaw
	{
		displayName="Presem Hacksaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\PresemHacksaw_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=2000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawPresem.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawPresem.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damagePresem.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damagePresem.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_destructPresem.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hacksaw_Gold: Hacksaw
	{
		displayName="Gold Hacksaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\GoldHacksaw_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=850;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawGold.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCHacksawGold.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damageGold.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_damageGold.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hacksaw_destructGold.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hatchet_Blood: Hatchet
	{
		displayName="Blood Hatchet";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\BloodHatchet_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=2500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetBlood.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetBlood.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damageBlood.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damageBlood.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_destructBlood.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hatchet_Copper: Hatchet
	{
		displayName="Copper Hatchet";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\CopperHatchet_co.paa"
		};
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
								"SausageCo\objects\ExtraTools\data\SChatchetCopper.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetCopper.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damageCopper.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damageCopper.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_destructCopper.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hatchet_Rune: Hatchet
	{
		displayName="Rune Hatchet";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\RuneHatchet_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetRune.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetRune.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damageRune.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damageRune.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_destructRune.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hatchet_Silver: Hatchet
	{
		displayName="Silver Hatchet";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\SilverHatchet_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=750;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetSilver.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetSilver.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damageSilver.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damageSilver.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_destructSilver.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hatchet_Jade: Hatchet
	{
		displayName="Jade Hatchet";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\JadeHatchet_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetJade.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetJade.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damageJade.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damageJade.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_destructJade.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hatchet_Presem: Hatchet
	{
		displayName="Presem Hatchet";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\PresemHatchet_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=2000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetPresem.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetPresem.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damagePresem.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damagePresem.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_destructPresem.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Hatchet_Gold: Hatchet
	{
		displayName="Gold Hatchet";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\GoldHatchet_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=850;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetGold.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SChatchetGold.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damageGold.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_damageGold.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Hatchet_destructGold.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Pickaxe: Inventory_Base
	{
		scope=2;
		displayName="$STR_CfgVehicles_Pickaxe0";
		descriptionShort="$STR_CfgVehicles_Pickaxe1";
		model="\dz\weapons\melee\blade\Pickaxe.p3d";
		debug_ItemCategory=2;
		inventorySlot[]=
		{
			"Shoulder",
			"Melee"
		};
		rotationFlags=12;
		repairableWithKits[]={4};
		repairCosts[]={25};
		build_action_type=36;
		dismantle_action_type=46;
		itemInfo[]=
		{
			"Pickaxe"
		};
		RestrainUnlockType=1;
		itemSize[]={3,6};
		weight=2500;
		itemBehaviour=2;
		lootTag[]=
		{
			"Work"
		};
		lootCategory="Tools";
		openItemSpillRange[]={40,70};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\melee\blade\data\Pickaxe_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\melee\blade\data\Pickaxe.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\melee\blade\data\Pickaxe.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\melee\blade\data\Pickaxe_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\melee\blade\data\Pickaxe_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\melee\blade\data\Pickaxe_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		isMeleeWeapon=1;
		suicideAnim="fireaxe";
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeSharpLight_4";
				range=1.8;
			};
			class Heavy
			{
				ammo="MeleeSharpHeavy_4";
				range=1.8;
			};
			class Sprint
			{
				ammo="MeleeSharpHeavy_4";
				range=3.7;
			};
		};
		class Horticulture
		{
			ToolAnim="CHOPPINGWOOD";
			DiggingTimeToComplete=4.5;
		};
		soundImpactType="metal";
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup_light
				{
					soundSet="pickUpShovelLight_SoundSet";
					id=796;
				};
				class pickup
				{
					soundSet="pickUpShovel_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="woodaxe_drop_SoundSet";
					id=898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet="FirefighterAxe_loop_SoundSet";
					id=1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet="FirefighterAxe_end_SoundSet";
					id=1122;
				};
				class ShoulderR_Hide
				{
					soundset="ShoulderR_Hide_SoundSet";
					id=1210;
				};
				class ShoulderR_Show
				{
					soundset="ShoulderR_Show_SoundSet";
					id=1211;
				};
				class animalSkinning_in
				{
					soundSet="animalSkinning_in_SoundSet";
					id=516;
				};
				class animalSkinning
				{
					soundSet="animalSkinning_SoundSet";
					id=517;
				};
				class animalSkinning_out
				{
					soundSet="animalSkinning_out_SoundSet";
					id=518;
				};
			};
			class Sound
			{
				class SurfaceDig
				{
					class DigPrimary
					{
						default=15;
						sakhal_snow=903;
						sakhal_snow_forest=903;
						sakhal_grass_brown=903;
						sakhal_ice_sea=904;
						sakhal_ice_lake=904;
					};
				};
			};
		};
	};
	class SC_Pickaxe_Blood: Pickaxe
	{
		displayName="Blood Pickaxe";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\Bloodpickaxe_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=2500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxeBlood.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxeBlood.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damageBlood.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damageBlood.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_destructBlood.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Pickaxe_Copper: Pickaxe
	{
		displayName="Copper Pickaxe";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\Copperpickaxe_co.paa"
		};
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
								"SausageCo\objects\ExtraTools\data\SCpickaxeCopper.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxeCopper.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damageCopper.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damageCopper.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_destructCopper.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Pickaxe_Rune: Pickaxe
	{
		displayName="Rune Pickaxe";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\Runepickaxe_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxeRune.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxeRune.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damageRune.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damageRune.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_destructRune.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Pickaxe_Silver: Pickaxe
	{
		displayName="Silver Pickaxe";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\Silverpickaxe_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=750;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxeSilver.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxeSilver.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damageSilver.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damageSilver.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_destructSilver.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Pickaxe_Jade: Pickaxe
	{
		displayName="Jade Pickaxe";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\Jadepickaxe_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxeJade.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxeJade.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damageJade.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damageJade.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_destructJade.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Pickaxe_Presem: Pickaxe
	{
		displayName="Presem Pickaxe";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\Presempickaxe_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=2000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxePresem.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxePresem.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damagePresem.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damagePresem.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_destructPresem.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SC_Pickaxe_Gold: Pickaxe
	{
		displayName="Gold Pickaxe";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\objects\ExtraTools\data\Goldpickaxe_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=850;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxeGold.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\objects\ExtraTools\data\SCpickaxeGold.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damageGold.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_damageGold.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\objects\ExtraTools\data\Pickaxe_destructGold.rvmat"
							}
						}
					};
				};
			};
		};
	};
};