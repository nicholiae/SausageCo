class CfgPatches
{
	class SausageCo_DimanClothing
	{
		units[]=
		{
			"DimanHelmet",
			"DimanBag",
			"DimanJacket",
			"DimanPants",
			"DimanBoots",
			"DimanGloves"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters"
		};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base
	{
	};
	class Switchable_Base;
	class DimanJacket_ColorBase: Clothing
	{
		displayName="DimanGear Jacket";
		descriptionShort="Diman Jacket, apart of the Military Camo set made in the 21st century for marines deployed in the amazon during the 3rd world war. USABLE ONLY IN SAUSAGECO SERVERS!";
		model="\DZ\characters\tops\M65_Jacket_g.p3d";
		inventorySlot[]=
		{
			"Body"
		};
		itemInfo[]=
		{
			"Clothing",
			"Body"
		};
		weight=1630;
		itemSize[]={2,2};
		itemsCargoSize[]={8,7};
		quickBarBonus=2;
		absorbency=0.2;
		heatIsolation=0.80000001;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		soundAttType="HeavyJacket";
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\tops\Data\M65_Jacket.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\tops\Data\M65_Jacket.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\tops\Data\M65_Jacket_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\tops\Data\M65_Jacket_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\characters\tops\Data\M65_Jacket_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0.0;
					};
					class Shock
					{
						damage=0.89999998;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0.0;
					};
					class Shock
					{
						damage=0.89999998;
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\DZ\characters\tops\M65_Jacket_m.p3d";
			female="\DZ\characters\tops\M65_Jacket_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="Shirt_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="Shirt_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class DimanJacket_Feather: DimanJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\data\diman_m65_jacket_feather_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\data\diman_m65_jacket_feather_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\data\diman_m65_jacket_feather_co.paa"
		};
	};
	class DimanJacket_Redlon: DimanJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_m65_jacket_redlon_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_m65_jacket_redlon_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_m65_jacket_redlon_co.paa"
		};
	};
	class DimanJacket_Grimmer: DimanJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_m65_jacket_Grimmer_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_m65_jacket_Grimmer_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_m65_jacket_Grimmer_co.paa"
		};
	};
	class DimanJacket_VibeD17: DimanJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanJacket_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanJacket_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanJacket_VibeD17.paa"
		};
	};
	class DimanPants_ColorBase: Clothing
	{
		displayName="DimanGear Pants";
		descriptionShort="Diman Pants, apart of the Military Camo set made in the 21st century for marines deployed in the amazon during the 3rd world war. USABLE ONLY IN SAUSAGECO SERVERS!";
		model="\DZ\characters\pants\jeans_ground.p3d";
		ContinuouActions[]=
		{
			"AT_WRING_CLOTHES"
		};
		inventorySlot[]=
		{
			"Legs"
		};
		simulation="clothing";
		itemInfo[]=
		{
			"Clothing",
			"Legs"
		};
		itemSize[]={2,2};
		itemsCargoSize[]={7,7};
		weight=470;
		ragQuantity=3;
		absorbency=0.69999999;
		heatIsolation=0.60000002;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		quickBarBonus=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]={};
		class ClothingTypes
		{
			male="\DZ\characters\pants\jeans_m.p3d";
			female="\DZ\characters\pants\jeans_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\pants\Data\Jeans_m_grd.rvmat",
								"DZ\characters\pants\Data\jeans.rvmat",
								"DZ\characters\pants\Data\jeans_f.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\pants\Data\Jeans_m_grd.rvmat",
								"DZ\characters\pants\Data\jeans.rvmat",
								"DZ\characters\pants\Data\jeans_f.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\pants\Data\Jeans_m_grd_damage.rvmat",
								"DZ\characters\pants\Data\jeans_damage.rvmat",
								"DZ\characters\pants\Data\jeans_f_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\pants\Data\Jeans_m_grd_damage.rvmat",
								"DZ\characters\pants\Data\jeans_damage.rvmat",
								"DZ\characters\pants\Data\jeans_f_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\characters\pants\Data\Jeans_m_grd_destruct.rvmat",
								"DZ\characters\pants\Data\jeans_destruct.rvmat",
								"DZ\characters\pants\Data\jeans_f_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0.0;
					};
					class Shock
					{
						damage=0.89999998;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0.0;
					};
					class Shock
					{
						damage=0.89999998;
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="Shirt_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="Shirt_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class DimanPants_Feather: DimanPants_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\data\diman_jeans_feather_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\data\diman_jeans_feather_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\data\diman_jeans_feather_co.paa"
		};
	};
	class DimanPants_Redlon: DimanPants_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_jeans_redlon_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_jeans_redlon_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_jeans_redlon_co.paa"
		};
	};
	class DimanPants_Grimmer: DimanPants_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_jeans_Grimmer_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_jeans_Grimmer_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_jeans_Grimmer_co.paa"
		};
	};
	class DimanPants_VibeD17: DimanPants_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanPants_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanPants_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanPants_VibeD17.paa"
		};
	};
	class DimanBag_ColorBase: Clothing
	{
		displayName="DimanBag";
		descriptionShort="Diman Bag, apart of the Military Camo set made in the 21st century for marines deployed in the amazon during the 3rd world war. USABLE ONLY IN SAUSAGECO SERVERS!";
		model="\dz\characters\backpacks\boulder_m53_g.p3d";
		inventorySlot[]=
		{
			"Back",
			"Back1",
			"Back2",
			"Back3",
			"Back4"
		};
		attachments[]=
		{
			"WalkieTalkie",
			"shoulder1",
			"shoulder2"
		};
		simulation="clothing";
		itemInfo[]=
		{
			"Clothing",
			"Back",
			"Back1",
			"Back2",
			"Back3"
		};
		rotationFlags=16;
		itemSize[]={2,2};
		itemsCargoSize[]={10,12};
		weight=0;
		absorbency=0;
		heatIsolation=0.1;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		soundAttType="Military";
		randomQuantity=4;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class ClothingTypes
		{
			male="\DZ\characters\backpacks\boulder_m53_m.p3d";
			female="\DZ\characters\backpacks\boulder_m53_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\Characters\backpacks\data\boulder_m53.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\Characters\backpacks\data\boulder_m53.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\Characters\backpacks\data\boulder_m53_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\Characters\backpacks\data\boulder_m53_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\Characters\backpacks\data\boulder_m53_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpBackPack_Metal_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBackPack_Metal_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="taloonbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class DimanBag_Feather: DimanBag_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\data\diman_boulder_m53_feather_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\data\diman_boulder_m53_feather_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\data\diman_boulder_m53_feather_co.paa"
		};
	};
	class DimanBag_Redlon: DimanBag_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_boulder_m53_redlon_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_boulder_m53_redlon_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_boulder_m53_redlon_co.paa"
		};
	};
	class DimanBag_Grimmer: DimanBag_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_boulder_m53_Grimmer_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_boulder_m53_Grimmer_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_boulder_m53_Grimmer_co.paa"
		};
	};
	class DimanBag_VibeD17: DimanBag_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanBag_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanBag_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanBag_VibeD17.paa"
		};
	};
	class DimanBoots_ColorBase: Clothing
	{
		displayName="DimanBoots";
		descriptionShort="Diman Boots, apart of the Military Camo set made in the 21st century for marines deployed in the amazon during the 3rd world war. USABLE ONLY IN SAUSAGECO SERVERS!";
		model="\DZ\characters\shoes\MilitaryBoots_ground.p3d";
		inventorySlot[]=
		{
			"Feet"
		};
		itemInfo[]=
		{
			"Clothing",
			"Feet"
		};
		itemSize[]={2,2};
		weight=1100;
		durability=0.5;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		attachments[]=
		{
			"Knife"
		};
		absorbency=0.1;
		heatIsolation=0.69999999;
		soundAttType="Boots";
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class ClothingTypes
		{
			male="\DZ\characters\shoes\MilitaryBoots_m.p3d";
			female="\DZ\characters\shoes\MilitaryBoots_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\shoes\Data\MilitaryBoots.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\shoes\Data\MilitaryBoots.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\shoes\Data\MilitaryBoots_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\shoes\Data\MilitaryBoots_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\characters\shoes\Data\MilitaryBoots_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.80000001;
					};
					class Blood
					{
						damage=0.80000001;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.80000001;
					};
					class Blood
					{
						damage=0.80000001;
					};
					class Shock
					{
						damage=0.80000001;
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="AthleticShoes_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="AthleticShoes_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class DimanBoots_Feather: DimanBoots_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\data\diman_militaryboots_feather_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\data\diman_militaryboots_feather_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\data\diman_militaryboots_feather_co.paa"
		};
	};
	class DimanBoots_Redlon: DimanBoots_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_militaryboots_redlon_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_militaryboots_redlon_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_militaryboots_redlon_co.paa"
		};
	};
	class DimanBoots_Grimmer: DimanBoots_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_militaryboots_Grimmer_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_militaryboots_Grimmer_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_militaryboots_Grimmer_co.paa"
		};
	};
	class DimanBoots_VibeD17: DimanBoots_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanBoots_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanBoots_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanBoots_VibeD17.paa"
		};
	};
	class DimanGloves_ColorBase: Clothing
	{
		displayName="DimanGloves";
		descriptionShort="Diman Gloves, apart of the Military Camo set made in the 21st century for marines deployed in the amazon during the 3rd world war. USABLE ONLY IN SAUSAGECO SERVERS!";
		model="\DZ\characters\gloves\tactical_gloves_g.p3d";
		inventorySlot[]=
		{
			"Gloves"
		};
		simulation="clothing";
		itemInfo[]=
		{
			"Clothing",
			"Gloves"
		};
		rotationFlags=34;
		weight=454;
		itemSize[]={1,1};
		absorbency=0.40000001;
		heatIsolation=0.25;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale",
			"personality"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\Characters\gloves\data\TacticalGloves.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\Characters\gloves\data\TacticalGloves.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\Characters\gloves\data\TacticalGloves_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\Characters\gloves\data\TacticalGloves_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\Characters\gloves\data\TacticalGloves_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\DZ\characters\gloves\tactical_gloves_m.p3d";
			female="\DZ\characters\gloves\tactical_gloves_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="WorkingGloves_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="WorkingGloves_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class DimanGloves_Feather: DimanGloves_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\data\diman_tacticalgloves_feather_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\data\diman_tacticalgloves_feather_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\data\diman_tacticalgloves_feather_co.paa"
		};
	};
	class DimanGloves_Redlon: DimanGloves_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_tacticalgloves_redlon_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_tacticalgloves_redlon_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\diman_tacticalgloves_redlon_co.paa"
		};
	};
	class DimanGloves_Grimmer: DimanGloves_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_tacticalgloves_Grimmer_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_tacticalgloves_Grimmer_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\diman_tacticalgloves_Grimmer_co.paa"
		};
	};
	class DimanGloves_VibeD17: DimanGloves_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanGloves_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanGloves_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanGloves_VibeD17.paa"
		};
	};
	class Mich2001Helmet: Clothing
	{
		
	};
	class DimanHelmet: Mich2001Helmet
	{
		scope=2;
		displayName="Military Diman Helmet";
		descriptionShort="A Diman series Military Helmet. Made in the early 21st century for combat marines deployed in the amazon during the earths 3rd world war. USABLE IN SAUSAGECO SERVERS ONLY!";
		model="\DZ\characters\headgear\Mich2001_g.p3d";
		repairableWithKits[]={5,8};
		repairCosts[]={30,25};
		inventorySlot[]=
		{
			"Headgear"
		};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Headgear"
		};
		attachments[]=
		{
			"NVG",
			"helmetFlashlight"
		};
		rotationFlags=2;
		weight=1200;
		itemSize[]={2,1};
		noMask=0;
		absorbency=0;
		heatIsolation=0.80000001;
		visibilityModifier=0.94999999;
		headSelectionsToHide[]=
		{
			"Clipping_Mich2001"
		};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\data\dimanmitch2001_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\data\dimanmitch2001_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\data\dimanmitch2001_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\headgear\data\mich2001.rvmat",
								"DZ\characters\headgear\data\mich2001_rail.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\headgear\data\mich2001.rvmat",
								"DZ\characters\headgear\data\mich2001_rail.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\headgear\data\mich2001_damage.rvmat",
								"DZ\characters\headgear\data\mich2001_rail_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\headgear\data\mich2001_damage.rvmat",
								"DZ\characters\headgear\data\mich2001_rail_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\characters\headgear\data\mich2001_destruct.rvmat",
								"DZ\characters\headgear\data\mich2001_rail_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0.1;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.25999999;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.25;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0.2;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.25999999;
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\DZ\characters\headgear\Mich2001.p3d";
			female="\DZ\characters\headgear\Mich2001.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="pickUpPot_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="BallisticHelmet_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class DimanJacket_GreenMonster: DimanJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\m65_jacket_greenmonster_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\m65_jacket_greenmonster_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\m65_jacket_greenmonster_co.paa"
		};
	};
	class DimanPants_GreenMonster: DimanPants_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\jeans_greenmonster_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\jeans_greenmonster_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\jeans_greenmonster_co.paa"
		};
	};
	class DimanBag_GreenMonster: DimanBag_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\boulder_m53_greenmonster_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\boulder_m53_greenmonster_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\boulder_m53_greenmonster_co.paa"
		};
	};
	class DimanBoots_GreenMonster: DimanBoots_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\militaryboots_greenmonster_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\militaryboots_greenmonster_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\militaryboots_greenmonster_co.paa"
		};
	};
	class DimanGloves_GreenMonster: DimanGloves_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\tacticalgloves_greenmonster_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\tacticalgloves_greenmonster_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\tacticalgloves_greenmonster_co.paa"
		};
	};
	class DimanHelmet_GreenMonster: Mich2001Helmet
	{
		scope=2;
		displayName="Military Diman Helmet";
		descriptionShort="A Diman series Military Helmet. Made in the early 21st century for combat marines deployed in the amazon during the earths 3rd world war. USABLE IN SAUSAGECO SERVERS ONLY!";
		model="\DZ\characters\headgear\Mich2001_g.p3d";
		repairableWithKits[]={5,8};
		repairCosts[]={30,25};
		inventorySlot[]=
		{
			"Headgear"
		};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Headgear"
		};
		attachments[]=
		{
			"NVG",
			"helmetFlashlight"
		};
		rotationFlags=2;
		weight=1200;
		itemSize[]={2,1};
		noMask=0;
		absorbency=0;
		heatIsolation=0.80000001;
		visibilityModifier=0.94999999;
		headSelectionsToHide[]=
		{
			"Clipping_Mich2001"
		};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\greenmonster_mich2001_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\greenmonster_mich2001_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\dimanGreenmonster\diman_greenmonster\data\greenmonster_mich2001_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\headgear\data\mich2001.rvmat",
								"DZ\characters\headgear\data\mich2001_rail.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\headgear\data\mich2001.rvmat",
								"DZ\characters\headgear\data\mich2001_rail.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\headgear\data\mich2001_damage.rvmat",
								"DZ\characters\headgear\data\mich2001_rail_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\headgear\data\mich2001_damage.rvmat",
								"DZ\characters\headgear\data\mich2001_rail_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\characters\headgear\data\mich2001_destruct.rvmat",
								"DZ\characters\headgear\data\mich2001_rail_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0.1;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.25999999;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.25;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0.2;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.25999999;
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\DZ\characters\headgear\Mich2001.p3d";
			female="\DZ\characters\headgear\Mich2001.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="pickUpPot_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="BallisticHelmet_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class DimanHelmet_Redlon: DimanHelmet_GreenMonster
	{
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\redlon_mich2001_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\redlon_mich2001_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\redlon_mich2001_co.paa"
		};
		
	};
	class DimanHelmet_Grimmer: DimanHelmet_GreenMonster
	{
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\Grimmer_mich2001_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\Grimmer_mich2001_co.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\Grimmer_mich2001_co.paa"
		};
		
	};
	class DimanHelmet_VibeD17: DimanHelmet_GreenMonster
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanHelmet_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanHelmet_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimanHelmet_VibeD17.paa"
		};
	};
	class PlateCarrierVest: Clothing // Vest
	{
		hiddenSelections[]=
		{
			"camoGround",
			"camoFemale",
			"camoMale",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa"
		};
	};
	class DimanVest_Redlon: PlateCarrierVest
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\DimanVest_Redlon.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\DimanVest_Redlon.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\DimanVest_Redlon.paa",
			"SausageCo\storage\Clothes\DimanObjects\redlon\data\DimanVest_Redlon.paa"
		};
		
	};
	class DimanVest_Grimmer: PlateCarrierVest
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\DimanVest_Grimmer.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\DimanVest_Grimmer.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\DimanVest_Grimmer.paa",
			"SausageCo\storage\Clothes\DimanObjects\Grimmer\data\DimanVest_Grimmer.paa"
		};
		
	};
	class DimnanVest_VibeD17: PlateCarrierVest 
	{
		scope=2;
		varWetMax=0.36;
		heatIsolation=0.4;
		absorbency=0;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,10};
		hiddenSelectionsTextures[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimnanVest_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimnanVest_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimnanVest_VibeD17.paa",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\DimnanVest_VibeD17.paa"
		};
	};
	class Inventory_Base;
	class CarWheel: Inventory_Base{};
	class CarDoor: Inventory_Base{};
	class Car;
	class CarScript: Car
	{
		rotationFlags=64;
		storageCategory=4;
		insideSoundCoef=0.89999998;
		fuelCapacity=50;
		brakeFluidCapacity=1;
		oilCapacity=4;
		coolantCapacity=6;
		brakeFluidLeakDebit[]={0,0};
		oilLeakDebit[]={0,0};
		coolantLeakDebit[]={0,0};
		brakeFluidForceCoef[]={0,1,1,1};
		damageFromOil[]={0,0,1,0};
		damageFromCoolant[]={0,0,1,0};
		engineBeltSlot="EngineBelt";
		batterySlot="CarBattery";
		electricPowerResName="power";
		electricConsumptionIgnition=3001;
		electricConsumptionEngine=0;
		electricConsumptionLights=0;
		electricOutputEngine=5;
		selectionDashboard="light_dashboard";
		selectionLightFrontL="light_left";
		selectionLightFrontR="light_right";
		selectionBrakeLights="light_break";
		class Crew
		{
			class Driver
			{
				actionSel="seat_driver";
				proxyPos="crewDriver";
				getInPos="pos_driver";
				getInDir="pos_driver_dir";
				isDriver=1;
			};
			class CoDriver
			{
				actionSel="seat_coDriver";
				proxyPos="crewCoDriver";
				getInPos="pos_coDriver";
				getInDir="pos_coDriver_dir";
			};
		};
		class SimulationModule
		{
			class Axles
			{
				class Front
				{
					class Wheels
					{
						class Left
						{
							inventorySlot="";
							animTurn="turnfrontleft";
							animRotation="wheelfrontleft";
							animDamper="damperfrontleft";
							wheelHub="wheel_1_1_damper_land";
						};
						class Right
						{
							inventorySlot="";
							animTurn="turnfrontright";
							animRotation="wheelfrontright";
							animDamper="damperfrontright";
							wheelHub="wheel_2_1_damper_land";
						};
					};
				};
				class Rear
				{
					class Wheels
					{
						class Left
						{
							inventorySlot="";
							animTurn="turnbackleft";
							animRotation="wheelbackleft";
							animDamper="damperbackleft";
							wheelHub="wheel_1_2_damper_land";
						};
						class Right
						{
							inventorySlot="";
							animTurn="turnbackright";
							animRotation="wheelbackright";
							animDamper="damperbackright";
							wheelHub="wheel_2_2_damper_land";
						};
					};
				};
			};
		};
		attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1"
		};
		hiddenSelections[]=
		{
			""
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
		hiddenSelectionsMaterials[]=
		{
			""
		};
		class AnimationSources
		{
			class DoorsDriver
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class DoorsCoDriver: DoorsDriver
			{
			};
			class DoorsHood: DoorsDriver
			{
			};
			class DoorsTrunk: DoorsDriver
			{
			};
			class HideDestroyed_1_1
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class HideDestroyed_1_2
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class HideDestroyed_2_1
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class HideDestroyed_2_2
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class AnimHitWheel_1_1
			{
				source="Hit";
				hitpoint="HitWheel_1_1";
				raw=1;
			};
			class AnimHitWheel_1_2: AnimHitWheel_1_1
			{
				hitpoint="HitWheel_1_2";
			};
			class AnimHitWheel_2_1: AnimHitWheel_1_1
			{
				hitpoint="HitWheel_2_1";
			};
			class AnimHitWheel_2_2: AnimHitWheel_1_1
			{
				hitpoint="HitWheel_2_2";
			};
			class HitDoorsHood: AnimHitWheel_1_1
			{
				hitpoint="HitDoorsHood";
			};
			class HitDoorsTrunk: AnimHitWheel_1_1
			{
				hitpoint="HitDoorsTrunk";
			};
			class HitDoorsDrivers: AnimHitWheel_1_1
			{
				hitpoint="HitDoorsDriver";
			};
			class HitDoorsCoDrivers: AnimHitWheel_1_1
			{
				hitpoint="HitDoorsCoDriver";
			};
			class HitDoorsCargo: AnimHitWheel_1_1
			{
				hitpoint="HitDoorsCargo";
			};
		};
	};
	class Hatchback_02_Door_1_1: CarDoor
	{
	};
	class Diman_Door_1_1: Hatchback_02_Door_1_1
	{
		displayName="Diman Door";
		model="\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Door_1_1.p3d";
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanfrontdoor.rvmat";
		};
		inventorySlot[]=
		{
			"Hatchback_02_Door_1_1"
		};
		rotationFlags=8;
	};
	class Diman_Door_2_1: Diman_Door_1_1
	{
		displayName="Diman Door";
		model="\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Door_2_1.p3d";
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanbackdoor.rvmat";
		};
		inventorySlot[]=
		{
			"Hatchback_02_Door_2_1"
		};
		rotationFlags=4;
	};
	class Diman_Door_1_2: Diman_Door_1_1
	{
		displayName="Diman Door";
		model="\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Door_1_2.p3d";
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanfrontdoor.rvmat";
		};
		inventorySlot[]=
		{
			"Hatchback_02_Door_1_2"
		};
		rotationFlags=8;
	};
	class Diman_Door_2_2: Diman_Door_1_2
	{
		displayName="Diman Hood";
		model="\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Door_2_2.p3d";
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanbackdoor.rvmat";
		};
		inventorySlot[]=
		{
			"Hatchback_02_Door_2_2"
		};
		rotationFlags=4;
	};
	class Diman_Hood: Diman_Door_1_1
	{
		model="\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Hood.p3d";
		displayName="Diman Hood";
		rotationFlags=2;
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanhood.rvmat";
		};
		inventorySlot[]=
		{
			"Hatchback_02_Hood"
		};
	};
	class Diman_Trunk: Diman_Door_1_1
	{
		displayName="Diman Trunk";
		model="\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Trunk.p3d";
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimantrunk.rvmat";
		};
		rotationFlags=2;
		inventorySlot[]=
		{
			"Hatchback_02_Trunk"
		};
	};
	class Hatchback_02: CarScript
	{
		scope=2;
		displayName="$STR_CivHatchback0";
		descriptionShort="$STR_CivHatchback1";
		model="\dz\vehicles\wheeled\Hatchback_02\Hatchback_02.p3d";
		frontReflectorMatDamaged="";
		frontReflectorMatRuined="";
		fuelCapacity=55;
		fuelConsumption=6.5;
		attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"Hatchback_02_Door_1_1",
			"Hatchback_02_Door_1_2",
			"Hatchback_02_Door_2_1",
			"Hatchback_02_Door_2_2",
			"Hatchback_02_Trunk",
			"Hatchback_02_Hood",
			"Hatchback_02_Wheel_1_1",
			"Hatchback_02_Wheel_1_2",
			"Hatchback_02_Wheel_2_1",
			"Hatchback_02_Wheel_2_2"
		};
		hiddenSelections[]=
		{
			"light_1_1",
			"light_2_1",
			"light_brake_1_2",
			"light_brake_2_2",
			"light_reverse_1_2",
			"light_reverse_2_2",
			"light_1_2",
			"light_2_2",
			"light_dashboard",
			"camo_chassi"
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			""
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"
		};
		dashboardMatOn="dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_gauges_e.rvmat";
		dashboardMatOff="dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_gauges.rvmat";
		frontReflectorMatOn="dz\vehicles\wheeled\hatchback_02\data\Hatchback_02_headlights_e.rvmat";
		frontReflectorMatOff="dz\vehicles\wheeled\hatchback_02\data\Hatchback_02_headlights.rvmat";
		brakeReflectorMatOn="dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_TailLights_e.rvmat";
		brakeReflectorMatOff="dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_TailLights.rvmat";
		tailReflectorMatOn="dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_TailLights_e.rvmat";
		tailReflectorMatOff="dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_TailLights.rvmat";
		reverseReflectorMatOn="dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_TailLights_e.rvmat";
		reverseReflectorMatOff="dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_TailLights.rvmat";
		class Crew: Crew
		{
			class Driver: Driver
			{
			};
			class CoDriver: CoDriver
			{
			};
			class Cargo1
			{
				actionSel="seat_cargo1";
				proxyPos="crewCargo1";
				getInPos="pos_driver";
				getInDir="pos_driver_dir";
			};
			class Cargo2
			{
				actionSel="seat_cargo2";
				proxyPos="crewCargo2";
				getInPos="pos_coDriver";
				getInDir="pos_coDriver_dir";
			};
		};
		class SimulationModule: SimulationModule
		{
			drive="DRIVE_FWD";
			airDragFrontTotal=0.79000002;
			class Steering
			{
				increaseSpeed[]={0,50,60,30,100,15};
				decreaseSpeed[]={0,90,60,45,100,20};
				centeringSpeed[]={0,0,15,27,60,45,100,63};
			};
			class Throttle
			{
				reactionTime=0.69999999;
				defaultThrust=0.75;
				gentleThrust=0.5;
				turboCoef=2.2;
				gentleCoef=0.5;
			};
			braking[]={0,0.1,0.5,0.30000001,2.5,0.40000001,3,1};
			class Engine
			{
				inertia=0.27000001;
				torqueMax=186;
				torqueRpm=4400;
				powerMax=100;
				powerRpm=5800;
				rpmIdle=1250;
				rpmMin=1350;
				rpmClutch=1500;
				rpmRedline=6250;
				rpmMax=7000;
			};
			class Gearbox
			{
				reverse=3.1670001;
				ratios[]={3.4549999,2.118,1.444,1.1289999,0.912};
				timeToUncoupleClutch=0.25;
				timeToCoupleClutch=0.34999999;
				maxClutchTorque=225;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle=35;
					finalRatio=3.6670001;
					brakeBias=0.75;
					brakeForce=4000;
					wheelHubMass=5;
					wheelHubRadius=0.125;
					class Suspension
					{
						swayBar=1850;
						stiffness=30000;
						compression=1650;
						damping=6000;
						travelMaxUp=0.16;
						travelMaxDown=0.16;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_1";
							inventorySlot="Hatchback_02_Wheel_1_1";
						};
						class Right: Right
						{
							animDamper="damper_2_1";
							inventorySlot="Hatchback_02_Wheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle=0;
					brakeBias=0.44999999;
					brakeForce=3500;
					wheelHubMass=5;
					wheelHubRadius=0.125;
					class Suspension
					{
						swayBar=1850;
						stiffness=27000;
						compression=1700;
						damping=7000;
						travelMaxUp=0.16;
						travelMaxDown=0.16;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_2";
							inventorySlot="Hatchback_02_Wheel_1_2";
						};
						class Right: Right
						{
							animDamper="damper_2_2";
							inventorySlot="Hatchback_02_Wheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,30};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		class AnimationSources: AnimationSources
		{
			class DoorsCargo1
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class DoorsCargo2
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class damper_1_1
			{
				source="user";
				initPhase=0.5;
				animPeriod=1;
			};
			class damper_2_1: damper_1_1
			{
			};
			class damper_1_2: damper_1_1
			{
			};
			class damper_2_2: damper_1_2
			{
			};
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
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_chassis"
					};
					class Health
					{
						hitpoints=3000;
						transferToGlobalCoef=0;
					};
					inventorySlots[]={};
				};
				class Front
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_front"
					};
					componentNames[]=
					{
						"dmgZone_front",
						"dmgZone_bumper_1"
					};
					class Health
					{
						hitpoints=700;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Fender_1_1",
						"Fender_2_1",
						"Engine"
					};
					transferToZonesCoefs[]={0.30000001,0.30000001,0.40000001};
					inventorySlots[]=
					{
						"Hatchback_02_Hood",
						"CarRadiator",
						"Hatchback_02_Wheel_1_1",
						"Hatchback_02_Wheel_2_1"
					};
					inventorySlotsCoefs[]={0.69999999,0.5,0.40000001,0.40000001};
				};
				class Reflector_1_1
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_lights_1_1"
					};
					memoryPoints[]=
					{
						"dmgZone_lights_1_1"
					};
					class Health
					{
						hitpoints=20;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_windows.rvmat"
								}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\glass_i_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\glass_i_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Front",
						"Fender_1_1"
					};
					transferToZonesCoefs[]={1,1};
					inventorySlots[]=
					{
						"Reflector_1_1",
						"Hatchback_02_Wheel_1_1"
					};
					inventorySlotsCoefs[]={1,0.30000001};
				};
				class Reflector_2_1: Reflector_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_lights_2_1"
					};
					componentNames[]=
					{
						"dmgZone_lights_2_1"
					};
					transferToZonesNames[]=
					{
						"Front",
						"Fender_2_1"
					};
					inventorySlots[]=
					{
						"Reflector_2_1",
						"Hatchback_02_Wheel_2_1"
					};
				};
				class Back
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_back"
					};
					componentNames[]=
					{
						"dmgZone_back",
						"dmgZone_bumper_2"
					};
					class Health
					{
						hitpoints=500;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_body.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_body.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_body_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_body_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_body_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Fender_1_2",
						"Fender_2_2"
					};
					transferToZonesCoefs[]={0.30000001,0.30000001};
					inventorySlots[]=
					{
						"Hatchback_02_Trunk",
						"Hatchback_02_Wheel_1_2",
						"Hatchback_02_Wheel_2_2"
					};
					inventorySlotsCoefs[]={0.60000002,0.40000001,0.40000001};
				};
				class Roof
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_roof"
					};
					memoryPoints[]=
					{
						"dmgZone_roof"
					};
					class Health
					{
						hitpoints=400;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_destruct.rvmat"
								}
							}
						};
					};
					inventorySlots[]={};
				};
				class Fender_1_1
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_fender_1_1"
					};
					memoryPoints[]=
					{
						"dmgZone_fender_1_1"
					};
					class Health
					{
						hitpoints=700;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Front",
						"Reflector_1_1",
						"Engine"
					};
					transferToZonesCoefs[]={0.30000001,0.60000002,0.2};
					inventorySlots[]=
					{
						"Hatchback_02_Hood",
						"Hatchback_02_Wheel_1_1",
						"Hatchback_02_Door_1_1"
					};
					inventorySlotsCoefs[]={0.5,0.69999999,0.30000001};
				};
				class Fender_2_1: Fender_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_fender_2_1"
					};
					componentNames[]=
					{
						"dmgZone_fender_2_1"
					};
					transferToZonesNames[]=
					{
						"Front",
						"Reflector_2_1",
						"Engine"
					};
					transferToZonesCoefs[]={0.30000001,0.60000002,0.2};
					inventorySlots[]=
					{
						"Hatchback_02_Hood",
						"Hatchback_02_Wheel_2_1",
						"Hatchback_02_Door_2_1"
					};
					inventorySlotsCoefs[]={0.5,0.69999999,0.30000001};
				};
				class Fender_1_2: Fender_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_fender_1_2"
					};
					componentNames[]=
					{
						"dmgZone_fender_1_2"
					};
					transferToZonesNames[]=
					{
						"Back",
						"FuelTank"
					};
					transferToZonesCoefs[]={0.30000001,0.69999999};
					inventorySlots[]=
					{
						"Hatchback_02_Trunk",
						"Hatchback_02_Wheel_1_2",
						"Hatchback_02_Door_1_2"
					};
					inventorySlotsCoefs[]={0.5,0.69999999,0.30000001};
				};
				class Fender_2_2: Fender_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_fender_2_2"
					};
					componentNames[]=
					{
						"dmgZone_fender_2_2"
					};
					transferToZonesNames[]=
					{
						"Back",
						"FuelTank"
					};
					transferToZonesCoefs[]={0.30000001,0.69999999};
					inventorySlots[]=
					{
						"Hatchback_02_Trunk",
						"Hatchback_02_Wheel_2_2",
						"Hatchback_02_Door_2_2"
					};
					inventorySlotsCoefs[]={0.5,0.69999999,0.30000001};
				};
				class WindowFront
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_windowFront"
					};
					componentNames[]=
					{
						"dmgZone_windowFront"
					};
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\Hatchback_02_Windows.rvmat",
									"dz\vehicles\wheeled\hatchback_02\data\glass_i.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\wheeled\hatchback_02\data\Hatchback_02_Windows.rvmat",
									"dz\vehicles\wheeled\hatchback_02\data\glass_i_damage.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"hidden",
									"dz\vehicles\wheeled\hatchback_02\data\glass_i_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"hidden",
									"dz\vehicles\wheeled\hatchback_02\data\glass_i_destruct.rvmat"
								}
							},
							
							{
								0,
								"hidden",
								"hidden"
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
				class Engine
				{
					fatalInjuryCoef=0.001;
					memoryPoints[]=
					{
						"dmgZone_engine"
					};
					componentNames[]=
					{
						"dmgZone_engine"
					};
					class Health
					{
						hitpoints=1000;
						transferToGlobalCoef=1;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								{}
							},
							
							{
								0.30000001,
								{}
							},
							{0}
						};
					};
					inventorySlots[]=
					{
						"CarBattery",
						"SparkPlug"
					};
					inventorySlotsCoefs[]={0.1,0.2};
				};
				class FuelTank
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_fuelTank"
					};
					class Health
					{
						hitpoints=600;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								{}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								{}
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
			};
		};
		class ObstacleGenerator
		{
			carve=1;
			timeToStationary=5;
			moveThreshold=0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius=1;
						height=1.5;
						center[]={0,0,0.69999999};
					};
					class Cyl3
					{
						radius=1;
						height=1.5;
						center[]={0,0,-0.69999999};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name="$STR_attachment_Engine0";
				description="";
				icon="cat_vehicle_engine";
				attachmentSlots[]=
				{
					"CarBattery",
					"CarRadiator",
					"SparkPlug"
				};
			};
			class Body
			{
				name="$STR_attachment_Body0";
				description="";
				icon="cat_vehicle_body";
				attachmentSlots[]=
				{
					"Reflector_1_1",
					"Reflector_2_1",
					"Hatchback_02_Door_1_1",
					"Hatchback_02_Door_1_2",
					"Hatchback_02_Door_2_1",
					"Hatchback_02_Door_2_2",
					"Hatchback_02_Hood",
					"Hatchback_02_Trunk"
				};
			};
			class Chassis
			{
				name="$STR_attachment_Chassis0";
				description="";
				icon="cat_vehicle_chassis";
				attachmentSlots[]=
				{
					"Hatchback_02_Wheel_1_1",
					"Hatchback_02_Wheel_1_2",
					"Hatchback_02_Wheel_2_1",
					"Hatchback_02_Wheel_2_2"
				};
			};
		};
	};
	class Diman_Hatchback_02: Hatchback_02
	{
		scope=2;
		displayName="Diman mobile";
		model="\dz\vehicles\wheeled\Hatchback_02\Hatchback_02.p3d";
		fuelCapacity=155;
		fuelConsumption=6.5;
		attachments[]=
		{
			"Knife",
			"Melee",
			"Pistol",
			"shoulder1",
			"shoulder2",
			"Headgear",
			"Mask",
			"Eyewear",
			"Gloves",
			"Body",
			"Armband",
			"Vest",
			"Back",
			"Hips",
			"Legs",
			"Feet",
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"Hatchback_02_Trunk",
			"Hatchback_02_Hood",
			"Hatchback_02_Door_1_1",
			"Hatchback_02_Door_1_2",
			"Hatchback_02_Door_2_1",
			"Hatchback_02_Door_2_2",
			"Hatchback_02_Wheel_1_1",
			"Hatchback_02_Wheel_1_2",
			"Hatchback_02_Wheel_2_1",
			"Hatchback_02_Wheel_2_2"
		};
		hiddenSelections[]=
		{
			"light_1_1",
			"light_2_1",
			"light_brake_1_2",
			"light_brake_2_2",
			"light_reverse_1_2",
			"light_reverse_2_2",
			"light_1_2",
			"light_2_2",
			"light_dashboard",
			"camo_chassi"
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanCar.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\data\dimanCar.rvmat"
		};
		class Crew: Crew
		{
			class Driver: Driver
			{
			};
			class CoDriver: CoDriver
			{
			};
			class Cargo1
			{
				actionSel="seat_cargo1";
				proxyPos="crewCargo1";
				getInPos="pos_driver";
				getInDir="pos_driver_dir";
			};
			class Cargo2
			{
				actionSel="seat_cargo2";
				proxyPos="crewCargo2";
				getInPos="pos_coDriver";
				getInDir="pos_coDriver_dir";
			};
		};
		class SimulationModule: SimulationModule
		{
			drive="DRIVE_FWD";
			airDragFrontTotal=0.55000001;
			class Steering
			{
				increaseSpeed[]={0,50,60,30,100,15};
				decreaseSpeed[]={0,90,60,45,100,20};
				centeringSpeed[]={0,0,15,27,60,45,100,63};
			};
			class Throttle
			{
				reactionTime=0.64999998;
				defaultThrust=0.75;
				gentleThrust=0.5;
				turboCoef=2.2;
				gentleCoef=0.5;
			};
			class Engine
			{
				inertia=0.37000001;
				torqueMax=286;
				torqueRpm=4400;
				powerMax=300;
				powerRpm=5800;
				rpmIdle=1250;
				rpmMin=2350;
				rpmClutch=2500;
				rpmRedline=8850;
				rpmMax=9000;
			};
			class Gearbox
			{
				reverse=3.1670001;
				ratios[]={3.6800001,2.55,1.55,1.1900001,1};
				timeToUncoupleClutch=0.15000001;
				timeToCoupleClutch=0.15000001;
				maxClutchTorque=300;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle=35;
					finalRatio=3.6670001;
					brakeBias=0.75;
					brakeForce=5500;
					wheelHubMass=5;
					wheelHubRadius=0.125;
					class Suspension
					{
						swayBar=800;
						stiffness=16000;
						compression=1650;
						damping=6000;
						travelMaxUp=0.16;
						travelMaxDown=0.16;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_1";
							inventorySlot="Hatchback_02_Wheel_1_1";
						};
						class Right: Right
						{
							animDamper="damper_2_1";
							inventorySlot="Hatchback_02_Wheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle=0;
					brakeBias=0.44999999;
					brakeForce=4000;
					wheelHubMass=5;
					wheelHubRadius=0.125;
					class Suspension
					{
						swayBar=600;
						stiffness=16000;
						compression=1650;
						damping=6000;
						travelMaxUp=0.16;
						travelMaxDown=0.16;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_2";
							inventorySlot="Hatchback_02_Wheel_1_2";
						};
						class Right: Right
						{
							animDamper="damper_2_2";
							inventorySlot="Hatchback_02_Wheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,60};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		class GUIInventoryAttachmentsProps
		{
			class Weapons_Storage
			{
				name="Weapons Storage";
				description="";
				attachmentSlots[]=
				{
					"Knife",
					"Melee",
					"Pistol",
					"shoulder1",
					"shoulder2"
				};
				icon="Shoulder";
			};
			class Gear_Storge
			{
				name="Gear Storage";
				description="";
				attachmentSlots[]=
				{
					"Headgear",
					"Mask",
					"Eyewear",
					"Gloves",
					"Body",
					"Armband",
					"Vest",
					"Back",
					"Hips",
					"Legs",
					"Feet"
				};
				icon="Body";
			};
			
			class Engine
			{
				name="$STR_attachment_Engine0";
				description="";
				icon="cat_vehicle_engine";
				attachmentSlots[]=
				{
					"CarBattery",
					"CarRadiator",
					"SparkPlug"
				};
			};
			class Body
			{
				name="$STR_attachment_Body0";
				description="";
				icon="cat_vehicle_body";
				attachmentSlots[]=
				{
					"Reflector_1_1",
					"Reflector_2_1",
					"Hatchback_02_Door_1_1",
					"Hatchback_02_Door_1_2",
					"Hatchback_02_Door_2_1",
					"Hatchback_02_Door_2_2",
					"Hatchback_02_Hood",
					"Hatchback_02_Trunk"
				};
			};
			class Chassis
			{
				name="$STR_attachment_Chassis0";
				description="";
				icon="cat_vehicle_chassis";
				attachmentSlots[]=
				{
					"Hatchback_02_Wheel_1_1",
					"Hatchback_02_Wheel_1_2",
					"Hatchback_02_Wheel_2_1",
					"Hatchback_02_Wheel_2_2"
				};
			};
		};
	};
	class OffroadHatchback: CarScript{};
	class HatchbackDoors_Driver: CarDoor{};
	class HatchbackDoors_CoDriver: HatchbackDoors_Driver
	{
		displayName="$STR_HatchbackDoors_CoDriver0";
		descriptionShort="$STR_HatchbackDoors_CoDriver1";
		model="\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_coDriver.p3d";
		inventorySlot[]=
		{
			"NivaCoDriverDoors"
		};
		rotationFlags=4;
	};
	class HatchbackHood: CarDoor{};
	class HatchbackTrunk: CarDoor{};
	class Diman_OffroadDriverDoor: HatchbackDoors_Driver
	{
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFfrontdoor.rvmat";
		};
	};
	class Diman_OffroadCoDriverDoor: HatchbackDoors_CoDriver
	{
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFfrontdoor.rvmat";
		};
	};
	class Diman_HatchbackHood: HatchbackHood
	{
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFhood.rvmat";
		};
	};
	class Diman_HatchbackTrunk: HatchbackTrunk
	{
		hiddenSelectionsMaterials[]=
		{
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFtrunk.rvmat";
		};	
	};
	
	class Diman_OffroadHatchback: OffroadHatchback
	{
		scope=2;
		displayName="Diman OffroadHatchback";
		model="\dz\vehicles\wheeled\OffroadHatchback\OffroadHatchback.p3d";
		attachments[]=
		{
			"Knife",
			"Melee",
			"Pistol",
			"shoulder1",
			"shoulder2",
			"Headgear",
			"Mask",
			"Eyewear",
			"Gloves",
			"Body",
			"Armband",
			"Vest",
			"Back",
			"Hips",
			"Legs",
			"Feet",
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"NivaDriverDoors",
			"NivaCoDriverDoors",
			"NivaHood",
			"NivaTrunk",
			"NivaWheel_1_1",
			"NivaWheel_1_2",
			"NivaWheel_2_1",
			"NivaWheel_2_2",
			"NivaWheel_Spare_1"
		};
		hiddenSelections[]=
		{
			"light_left",
			"light_right",
			"light_brake_1_2",
			"light_brake_2_2",
			"light_reverse_1_2",
			"light_reverse_2_2",
			"light_1_2",
			"light_2_2",
			"light_dashboard",
			"dmgZone_chassis",
			"dmgZone_front",
			"dmgZone_back",
			"dmgZone_roof",
			"dmgZone_fender_1_1",
			"dmgZone_fender_1_2",
			"dmgZone_fender_2_1",
			"dmgZone_fender_2_2"
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat",
			"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
		};
		dashboardMatOn="dz\vehicles\wheeled\offroadhatchback\data\niva_dashboard_light.rvmat";
		dashboardMatOff="dz\vehicles\wheeled\offroadhatchback\data\niva_dashboard.rvmat";
		frontReflectorMatOn="dz\vehicles\wheeled\offroadhatchback\data\niva_lights.rvmat";
		frontReflectorMatOff="dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat";
		brakeReflectorMatOn="dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights_e.rvmat";
		brakeReflectorMatOff="dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat";
		ReverseReflectorMatOn="dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights_e.rvmat";
		ReverseReflectorMatOff="dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat";
		TailReflectorMatOn="dz\vehicles\wheeled\offroadhatchback\data\OffroadHatchback_lights_e.rvmat";
		TailReflectorMatOff="dz\vehicles\wheeled\offroadhatchback\data\OffroadHatchback_lights.rvmat";
		fuelCapacity=142;
		fuelConsumption=21;
		class Crew: Crew
		{
			class Driver: Driver
			{
			};
			class CoDriver: CoDriver
			{
			};
			class Cargo1
			{
				actionSel="seat_cargo1";
				proxyPos="crewCargo1";
				getInPos="pos_driver";
				getInDir="pos_driver_dir";
			};
			class Cargo2
			{
				actionSel="seat_cargo2";
				proxyPos="crewCargo2";
				getInPos="pos_coDriver";
				getInDir="pos_coDriver_dir";
			};
		};
		class SimulationModule: SimulationModule
		{
			drive="DRIVE_AWD";
			airDragFrontTotal=0.995;
			class Steering
			{
				increaseSpeed[]={0,45,60,23,100,12};
				decreaseSpeed[]={0,80,60,40,90,20};
				centeringSpeed[]={0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime=1;
				defaultThrust=0.85000002;
				gentleThrust=0.69999999;
				turboCoef=4;
				gentleCoef=0.75;
			};
			braking[]={0,0.1,1,0.80000001,2.5,0.89999998,3,1};
			class Engine
			{
				inertia=0.45000001;
				torqueMax=164;
				torqueRpm=5400;
				powerMax=153.700001;
				powerRpm=7400;
				rpmIdle=1850;
				rpmMin=1900;
				rpmClutch=2350;
				rpmRedline=8700;
				rpmMax=9000;
			};
			class Gearbox
			{
				reverse=3.526;
				ratios[]={3.6670001,2.0999999,1.3609999,1};
				timeToUncoupleClutch=0.30000001;
				timeToCoupleClutch=0.44999999;
				maxClutchTorque=260;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle=30;
					finalRatio=4.0999999;
					brakeBias=0.60000002;
					brakeForce=9000;
					wheelHubMass=5;
					wheelHubRadius=0.15000001;
					class Suspension
					{
						swayBar=1700;
						stiffness=40000;
						compression=2100;
						damping=7500;
						travelMaxUp=0.088200003;
						travelMaxDown=0.083300002;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_1";
							inventorySlot="NivaWheel_1_1";
						};
						class Right: Right
						{
							animDamper="damper_2_1";
							inventorySlot="NivaWheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle=0;
					finalRatio=4.0999999;
					brakeBias=0.40000001;
					brakeForce=8800;
					wheelHubMass=5;
					wheelHubRadius=0.15000001;
					class Suspension
					{
						swayBar=1800;
						stiffness=40000;
						compression=2200;
						damping=7600;
						travelMaxUp=0.1587;
						travelMaxDown=0.1059;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_2";
							inventorySlot="NivaWheel_1_2";
						};
						class Right: Right
						{
							animDamper="damper_2_2";
							inventorySlot="NivaWheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,60};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		class AnimationSources: AnimationSources
		{
			class SeatDriver
			{
				source="user";
				initPhase=0;
				animPeriod=0.80000001;
			};
			class SeatCoDriver
			{
				source="user";
				initPhase=0;
				animPeriod=0.80000001;
			};
			class damper_1_1
			{
				source="user";
				initPhase=0.48570001;
				animPeriod=1;
			};
			class damper_2_1: damper_1_1
			{
			};
			class damper_1_2
			{
				source="user";
				initPhase=0.40020001;
				animPeriod=1;
			};
			class damper_2_2: damper_1_2
			{
			};
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
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_chassis"
					};
					class Health
					{
						hitpoints=3000;
						transferToGlobalCoef=0;
					};
					inventorySlots[]={};
				};
				class Front
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_front"
					};
					componentNames[]=
					{
						"dmgZone_front"
					};
					class Health
					{
						hitpoints=1200;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Fender_1_1",
						"Fender_2_1",
						"Engine"
					};
					transferToZonesCoefs[]={0.30000001,0.30000001,0.40000001};
					inventorySlots[]=
					{
						"NivaHood",
						"CarRadiator",
						"NivaWheel_1_1",
						"NivaWheel_2_1"
					};
					inventorySlotsCoefs[]={0.69999999,0.5,0.40000001,0.40000001};
				};
				class Reflector_1_1
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_lights_1_1"
					};
					memoryPoints[]=
					{
						"dmgZone_lights_1_1"
					};
					class Health
					{
						hitpoints=10;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\headlights_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\glass_i_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\glass_i_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Front",
						"Fender_1_1"
					};
					transferToZonesCoefs[]={1,1};
					inventorySlots[]=
					{
						"Reflector_1_1",
						"NivaWheel_1_1"
					};
					inventorySlotsCoefs[]={1,0.30000001};
				};
				class Reflector_2_1: Reflector_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_lights_2_1"
					};
					componentNames[]=
					{
						"dmgZone_lights_2_1"
					};
					transferToZonesNames[]=
					{
						"Front",
						"Fender_2_1"
					};
					inventorySlots[]=
					{
						"Reflector_2_1",
						"NivaWheel_2_1"
					};
				};
				class Back
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_back"
					};
					componentNames[]=
					{
						"dmgZone_back"
					};
					class Health
					{
						hitpoints=1500;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Fender_1_2",
						"Fender_2_2",
						"WindowLR",
						"WindowRR"
					};
					transferToZonesCoefs[]={0.30000001,0.30000001,0.1,0.1};
					inventorySlots[]=
					{
						"NivaTrunk",
						"NivaWheel_1_2",
						"NivaWheel_2_2"
					};
					inventorySlotsCoefs[]={0.60000002,0.40000001,0.40000001};
				};
				class Roof
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_roof"
					};
					memoryPoints[]=
					{
						"dmgZone_roof"
					};
					class Health
					{
						hitpoints=700;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							}
						};
					};
					inventorySlotsCoefs[]={};
					inventorySlots[]={};
				};
				class Fender_1_1
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_fender_1_1"
					};
					memoryPoints[]=
					{
						"dmgZone_fender_1_1"
					};
					class Health
					{
						hitpoints=1200;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							},
							
							{
								0,
								
								{
									"SausageCo\storage\Clothes\DimanObjects\VibeD17\offroad\data\dimanOFFCar.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Front",
						"Reflector_1_1",
						"Engine"
					};
					transferToZonesCoefs[]={0.30000001,0.60000002,0.2};
					inventorySlots[]=
					{
						"NivaHood",
						"NivaWheel_1_1",
						"NivaDriverDoors"
					};
					inventorySlotsCoefs[]={0.5,0.69999999,0.30000001};
				};
				class Fender_2_1: Fender_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_fender_2_1"
					};
					componentNames[]=
					{
						"dmgZone_fender_2_1"
					};
					transferToZonesNames[]=
					{
						"Front",
						"Reflector_2_1",
						"Engine"
					};
					transferToZonesCoefs[]={0.30000001,0.60000002,0.2};
					inventorySlots[]=
					{
						"NivaHood",
						"NivaWheel_2_1",
						"NivaCoDriverDoors"
					};
					inventorySlotsCoefs[]={0.5,0.69999999,0.30000001};
				};
				class Fender_1_2: Fender_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_fender_1_2"
					};
					componentNames[]=
					{
						"dmgZone_fender_1_2"
					};
					transferToZonesNames[]=
					{
						"Back",
						"FuelTank",
						"WindowLR"
					};
					transferToZonesCoefs[]={0.30000001,0.69999999,0.69999999};
					inventorySlots[]=
					{
						"NivaTrunk",
						"NivaWheel_1_2",
						"NivaDriverDoors"
					};
					inventorySlotsCoefs[]={0.5,0.69999999,0.30000001};
				};
				class Fender_2_2: Fender_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_fender_2_2"
					};
					componentNames[]=
					{
						"dmgZone_fender_2_2"
					};
					transferToZonesNames[]=
					{
						"Back",
						"FuelTank",
						"WindowRR"
					};
					transferToZonesCoefs[]={0.30000001,0.69999999,0.69999999};
					inventorySlots[]=
					{
						"NivaTrunk",
						"NivaWheel_2_2",
						"NivaCoDriverDoors"
					};
					inventorySlotsCoefs[]={0.5,0.69999999,0.30000001};
				};
				class WindowFront
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_windowFront"
					};
					componentNames[]=
					{
						"dmgZone_windowFront"
					};
					class Health
					{
						hitpoints=120;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"
								}
							},
							
							{
								0,
								"hidden"
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
				class WindowLR
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_windowLeft"
					};
					componentNames[]=
					{
						"dmgZone_windowLeft"
					};
					class Health
					{
						hitpoints=150;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"
								}
							},
							
							{
								0,
								"hidden"
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
				class WindowRR: WindowLR
				{
					memoryPoints[]=
					{
						"dmgZone_windowRight"
					};
					componentNames[]=
					{
						"dmgZone_windowRight"
					};
				};
				class Engine
				{
					fatalInjuryCoef=0.001;
					memoryPoints[]=
					{
						"dmgZone_engine"
					};
					componentNames[]=
					{
						"dmgZone_engine"
					};
					class Health
					{
						hitpoints=1000;
						transferToGlobalCoef=1;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\engine_niva.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\engine_niva.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\engine_niva_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\engine_niva_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\engine_niva_destruct.rvmat"
								}
							}
						};
					};
					inventorySlots[]=
					{
						"CarBattery",
						"SparkPlug"
					};
					inventorySlotsCoefs[]={0.2,0.2};
				};
				class FuelTank
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_fuelTank"
					};
					class Health
					{
						hitpoints=500;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								{}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								{}
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
			};
		};
		class ObstacleGenerator
		{
			carve=1;
			timeToStationary=5;
			moveThreshold=0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius=1;
						height=1.5;
						center[]={0,0,0.69999999};
					};
					class Cyl3
					{
						radius=1;
						height=1.5;
						center[]={0,0,-0.69999999};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Weapons_Storage
			{
				name="Weapons Storage";
				description="";
				attachmentSlots[]=
				{
					"Knife",
					"Melee",
					"Pistol",
					"shoulder1",
					"shoulder2"
				};
				icon="Shoulder";
			};
			class Gear_Storge
			{
				name="Gear Storage";
				description="";
				attachmentSlots[]=
				{
					"Headgear",
					"Mask",
					"Eyewear",
					"Gloves",
					"Body",
					"Armband",
					"Vest",
					"Back",
					"Hips",
					"Legs",
					"Feet"
				};
				icon="Body";
			};
			class Engine
			{
				name="$STR_attachment_Engine0";
				description="";
				icon="cat_vehicle_engine";
				attachmentSlots[]=
				{
					"CarBattery",
					"CarRadiator",
					"SparkPlug"
				};
			};
			class Body
			{
				name="$STR_attachment_Body0";
				description="";
				icon="cat_vehicle_body";
				attachmentSlots[]=
				{
					"Reflector_1_1",
					"Reflector_2_1",
					"NivaHood",
					"NivaTrunk",
					"NivaDriverDoors",
					"NivaCoDriverDoors",
					"NivaWheel_Spare_1"
				};
			};
			class Chassis
			{
				name="$STR_attachment_Chassis0";
				description="";
				icon="cat_vehicle_chassis";
				attachmentSlots[]=
				{
					"NivaWheel_1_1",
					"NivaWheel_1_2",
					"NivaWheel_2_1",
					"NivaWheel_2_2"
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyMxHelmet_visor: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"DBHelmetVisor"
		};
		model="\dz\characters\headgear\MxHelmet_visor.p3d";
	};
	class ProxyMxHelmet_mouthguard: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"DBHelmetMouth"
		};
		model="\dz\characters\headgear\MxHelmet_mouthguard.p3d";
	};
	class Proxyhelmet_flashlight: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"helmetFlashlight"
		};
		model="\dz\characters\headgear\proxies\helmet_flashlight.p3d";
	};
};
