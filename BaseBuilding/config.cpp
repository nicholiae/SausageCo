class CfgPatches
{
	class DZ_SausageCo_BaseBuilding
	{
		units[]={
			""
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
	class Slot_Material_SC_Clay
	{
		name="Material_SC_Clay";
		displayName="SC_Clay"; 
		ghostIcon="stone";
		stackMax=10;
		show="true";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class WorldContainer_Base;
	class HouseNoDestruct;
	class Static;
	class BaseBuildingBase: Inventory_Base
	{
	};
	class SausageCo_BaseBuilding_Base: BaseBuildingBase
	{
		scope=2;
		displayName="SausageCo_BaseBuilding_Base";
		descriptionShort="BASE CLASS NO IN GAME USE";
		model="SausageCo\BaseBuilding\.p3d";
		bounding="BSphere";
		overrideDrawArea="3.0";
		forceFarBubble="true";
		handheld="false";
		lootCategory="Crafted";
		carveNavmesh=1;
		weight=10000;
		itemSize[]={2,3};
		physLayer="item_large";
		createProxyPhysicsOnInit="false";
		createdProxiesOnInit[]=
		{
			"Deployed"
		};
		hybridAttachments[]=
		{
			"Material_WoodenLogs",
			"Material_SC_Clay",
			"Wall_Barbedwire_1",
			"Wall_Barbedwire_2"
		};
		mountables[]=
		{
			"Wall_Barbedwire_1",
			"Wall_Barbedwire_2"
		};
		rotationFlags=2;
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
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0,
							
							{
								""
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
			class DamageZones
			{
				class Body
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks_destruct.rvmat"
								}
							}
						};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=0;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class Melee
						{
							class Health
							{
								damage=0;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=0;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
					};
					componentNames[]=
					{
						"body"
					};
					fatalInjuryCoef=-1;
				};
				class Wall_Base_Down
				{
					class Health
					{
						hitpoints=12000;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks_worn.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"
								}
							}
						};
					};
					displayName="$STR_CfgVehicles_Construction_Part_Base_Down";
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class Melee
						{
							class Health
							{
								damage=0.64999998;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=50;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
					};
					componentNames[]=
					{
						"wall_base_down"
					};
					fatalInjuryCoef=-1;
				};
				class Wall_Base_Up: Wall_Base_Down
				{
					displayName="$STR_CfgVehicles_Construction_Part_Base_Up";
					componentNames[]=
					{
						"wall_base_up"
					};
				};
				class Wall_Clay_Down
				{
					class Health
					{
						hitpoints=16000;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks_worn.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"
								}
							}
						};
					};
					displayName="Clay Bottom Wall";
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class Melee
						{
							class Health
							{
								damage=0.64999998;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=50;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
					};
					componentNames[]=
					{
						"Wall_Clay_Down"
					};
					fatalInjuryCoef=-1;
				};
				class Wall_Clay_Up: Wall_Clay_Down
				{
					displayName="Clay Top Wall";
					componentNames[]=
					{
						"Wall_Clay_Up"
					};
				};
				class Wall_Barbedwire_1
				{
					class Health
					{
						hitpoints=300;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"DZ\gear\camping\data\barbed_wire.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"DZ\gear\camping\data\barbed_wire.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"DZ\gear\camping\data\barbed_wire.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"DZ\gear\camping\data\barbed_wire.rvmat"
								}
							},
							
							{
								0,
								
								{
									"DZ\gear\camping\data\barbed_wire.rvmat"
								}
							}
						};
					};
					displayName="$STR_cfgvehicles_barbedwire0";
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=0.0099999998;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class Melee
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=40;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
					};
					componentNames[]=
					{
						"wall_barbedwire_1",
						"wall_barbedwire_1_mounted"
					};
					inventorySlots[]=
					{
						"Wall_Barbedwire_1"
					};
					fatalInjuryCoef=-1;
				};
				class Wall_Barbedwire_2: Wall_Barbedwire_1
				{
					displayName="$STR_cfgvehicles_barbedwire0";
					componentNames[]=
					{
						"wall_barbedwire_2",
						"wall_barbedwire_2_mounted"
					};
					inventorySlots[]=
					{
						"Wall_Barbedwire_2"
					};
				};
				class Material_WoodenLogs
				{
					class Health
					{
						hitpoints=500;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks.rvmat"
								}
							},
							
							{
								0,
								
								{
									"DZ\gear\camping\data\fence_pile_of_planks.rvmat"
								}
							}
						};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class Melee
						{
							class Health
							{
								damage=0.64999998;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=50;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
					};
					componentNames[]=
					{
						"Material_WoodenLogs"
					};
					inventorySlots[]=
					{
						"Material_WoodenLogs"
					};
					fatalInjuryCoef=-1;
				};
			};
		};
		attachments[]=
		{
			"Wall_Barbedwire_1",
			"Wall_Barbedwire_2",
			"Wall_Camonet",
			"Att_CombinationLock",
			"Material_Nails",
			"Material_SC_Clay",
			"Material_WoodenLogs",
			"Material_MetalWire"
		};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name="$STR_CfgVehicles_Fence_Att_Category_Base";
				description="";
				attachmentSlots[]=
				{
					"Material_WoodenLogs"
				};
				icon="set:dayz_inventory image:cat_bb_base";
				selection="wall";
			};
			class Attachments
			{
				name="$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description="";
				attachmentSlots[]=
				{
					"Wall_Camonet",
					"Wall_Barbedwire_1",
					"Wall_Barbedwire_2",
					"Att_CombinationLock"
				};
				icon="set:dayz_inventory image:cat_bb_attachments";
				selection="wall";
			};
			class Material
			{
				name="$STR_CfgVehicles_Fence_Att_Category_Materials";
				description="";
				attachmentSlots[]=
				{
					"Material_Nails",
					"Material_WoodenLogs",
					"Material_SC_Clay",
					"Material_MetalWire"
				};
				icon="set:dayz_inventory image:cat_bb_material";
				selection="wall";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class AnimSourceHidden
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class AnimRotate
			{
				source="user";
				animPeriod=0.017999999;
				initPhase=0;
			};
			class Wall_Interact_Rotate: AnimRotate
			{
			};
			class Wall_Barbedwire_1_Mounted_Rotate: AnimRotate
			{
			};
			class Wall_Barbedwire_2_Mounted_Rotate: AnimRotate
			{
			};
			class Wall_Camonet_Rotate: AnimRotate
			{
			};
			class Wall_Gate_Rotate: AnimRotate
			{
			};
			class Wall_Base_Down_Rotate: AnimRotate
			{
			};
			class Wall_Base_Up_Rotate: AnimRotate
			{
			};
			class Wall_Clay_Down_Rotate: AnimRotate
			{
			};
			class Wall_Clay_Up_Rotate: AnimRotate
			{
			};
			class Material_WoodenLogs: AnimSourceHidden
			{
			};
			class Material_MetalWire: AnimSourceHidden
			{
			};
			class Wall_Barbedwire_1: AnimSourceHidden
			{
			};
			class Wall_Barbedwire_1_Mounted: AnimSourceHidden
			{
			};
			class Wall_Barbedwire_2: AnimSourceHidden
			{
			};
			class Wall_Barbedwire_2_Mounted: AnimSourceHidden
			{
			};
			class Wall_Camonet: AnimSourceHidden
			{
			};
			class Deployed: AnimSourceHidden
			{
			};
			class Base: AnimSourceHidden
			{
			};
			class Wall_Base_Down: AnimSourceHidden
			{
			};
			class Wall_Base_Up: AnimSourceHidden
			{
			};
			class Wall_Clay_Down: AnimSourceHidden
			{
			};
			class Wall_Clay_Up: AnimSourceHidden
			{
			};
		};
		class Construction
		{
			class wall
			{
				class base
				{
					name="$STR_CfgVehicles_Construction_Part_Base";
					is_base=1;
					id=1;
					required_parts[]={};
					conflicted_parts[]={};
					collision_data[]={};
					build_action_type=4;
					dismantle_action_type=4;
					material_type=1;
					class Materials
					{
						class Material1
						{
							type="WoodenLog";
							slot_name="Material_WoodenLogs";
							quantity=2;
							lockable=1;
						};
					};
				};
				class wall_base_down
				{
					name="$STR_CfgVehicles_Construction_Part_Base_Down";
					id=6;
					required_parts[]=
					{
						"base"
					};
					conflicted_parts[]={};
					collision_data[]=
					{
						"wall_down_min",
						"wall_down_max"
					};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="WoodenLog";
							slot_name="Material_WoodenLogs";
							quantity=1;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=4;
						};
					};
				};
				class Wall_Clay_Down
				{
					name="Clay Bottom Wall";
					id=7;
					required_parts[]=
					{
						"wall_base_down"
					};
					conflicted_parts[]=
					{
						"wall_clay_down"
					};
					collision_data[]=
					{
						"wall_down_min",
						"wall_down_max"
					};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="SC_Clay";
							slot_name="Material_SC_Clay";
							quantity=5;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
						};
					};
				};
				class wall_base_up
				{
					name="$STR_CfgVehicles_Construction_Part_Base_Up";
					id=9;
					required_parts[]=
					{
						"base"
					};
					conflicted_parts[]={};
					collision_data[]=
					{
						"wall_up_min",
						"wall_up_max"
					};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="WoodenLog";
							slot_name="Material_WoodenLogs";
							quantity=1;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=4;
						};
					};
				};
				class Wall_Clay_Up
				{
					name="Clay Top Wall";
					id=10;
					required_parts[]=
					{
						"wall_base_up"
					};
					conflicted_parts[]=
					{
						"wall_clay_up"
					};
					collision_data[]=
					{
						"wall_up_min",
						"wall_up_max"
					};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="SC_Clay";
							slot_name="Material_SC_Clay";
							quantity=5;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
						};
					};
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[]={1,1,1,0.050000001};
				ambient[]={0.0099999998,0.0099999998,0.0099999998,0.0099999998};
				position="light";
				hitpoint="bulb";
				selection="bulb";
				size=0;
				radius=5;
				brightness=0.001;
				dayLight=1;
				heatHazeRadius=0;
				heatHazePower=0;
				fireEffect=0;
				fireEffectOctaves=0;
				fireEffectPersistence=0;
				fireEffectFract=0;
			};
		};
	};
};
