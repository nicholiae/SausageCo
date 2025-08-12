class CfgPatches
{
	class SausageBuilding_Storage_Base_Kit
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
	class Inventory_Base;
	class SausageKit_SmallBase: Inventory_Base
	{
		scope=2;
		displayName="SausageBase SmallKit";
		descriptionShort="";
		model="\DZ\gear\camping\wooden_case.p3d";
		itemSize[]={1,3};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=1;
		class Cargo
		{
		};
	};
	class SausageKit_Base: Inventory_Base
	{
		scope=2;
		displayName="SausageBase Kit";
		descriptionShort="";
		model="\DZ\gear\camping\wooden_case.p3d";
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
	class  SausageBuilding_GasPump_Kit: SausageKit_SmallBase
	{
		scope=2;
		displayName="SausageCo GasPump Kit";
		descriptionShort="Can be deployed into a GasPump. Created by SausageCo.";
		itemSize[]={3,3};
		weight=100;
	};
	class SausageLights_Torch_Kit: SausageKit_SmallBase
	{
		scope=2;
		displayName="SausageCo Torch Kit";
		descriptionShort="Can be deployed into an Torch to lightup your base. Created by SausageCo.";
		model="\dz\gear\crafting\Torch.p3d";
		itemSize[]={1,3};
		weight=100;
	};
	class SausageBook_Storage_Kit: SausageKit_SmallBase
	{
		scope=2;
		displayName="SausageCo Bookshelf Kit";
		descriptionShort="Can be deployed into a bookshelf to store all your skill books. Created by SausageCo.";
		itemSize[]={3,3};
		weight=100;
	};
	class SausageCo_CasingsProcessor_Kit: SausageKit_SmallBase
	{
		scope=2;
		displayName="SausageCo CasingsProcessor Kit";
		descriptionShort="Can be deployed into a Casings Processor that will fill your casings with gunpowder. Created by SausageCo.";
		itemSize[]={3,3};
		weight=100;
	};
	class SC_DryingRack_Kit: SausageKit_SmallBase
	{
		scope=2;
		displayName="SausageCo Drying Rack Kit";
		descriptionShort="Can be deployed into a Drying Rack for your clothes. Created by SausageCo.";
		itemSize[]={3,3};
		weight=100;
	};
	class SausagePlank_Processor_Kit: SausageKit_SmallBase
	{
		scope=2;
		displayName="SausageCo PlankProcessor Kit";
		descriptionShort="Can be deployed into a PlankProcessor. Created by SausageCo.";
		itemSize[]={3,3};
		weight=100;
	};
	class SC_SolarPanel_Kit: SausageKit_SmallBase
	{
		scope=2;
		displayName="SausageCo SolarPanel Kit";
		descriptionShort="Can be deployed into a SolarPanel. Created by SausageCo.";
		itemSize[]={3,3};
		weight=100;
	};
	class SausageMedical_Tent_Kit: SausageKit_Base
	{
		scope=2;
		displayName="SausageCo Medical Tent Kit";
		descriptionShort="Can be deployed into a medical tent for your base so you can easily patch the holes in your groups dumbasses. Created by SausageCo.";
		itemSize[]={5,5};
		weight=100;
	};
	class SausageHelipad_Single_Kit: SausageKit_Base
	{
		scope=2;
		displayName="SausageHelipad Single Kit";
		descriptionShort="Can be deployed into a Helipad. Created by SausageCo.";
		itemSize[]={9,9};
		weight=1800;
	};
	class SausageBuilding_SmokeHouse_Kit: SausageKit_Base
	{
		scope=2;
		displayName="SausageBuilding Smokehouse Kit";
		descriptionShort="Can be deployed into a base. Created by SausageCo.";
		itemSize[]={9,9};
		weight=900;
	};
	class SausageBuilding_DyerHouse_Kit: SausageKit_Base
	{
		scope=2;
		displayName="SausageBuilding DyerHouse Kit";
		descriptionShort="Can be deployed into a base. Created by SausageCo.";
		itemSize[]={8,8};
		weight=800;
	};
	class SausageAmmo_Packer_Kit: SausageKit_Base
	{
		scope=2;
		displayName="SausageCo AmmoPacker Kit";
		descriptionShort="Can be deployed into an Ammo Processor for your base so you can easily process ammunition and magazines. Created by SausageCo.";
		
		itemSize[]={3,3};
		weight=100;
	};
	class SausageGarage_Gunrack_Kit: SausageKit_Base
	{
		scope=2;
		displayName="SausageCo Gunrack Kit";
		descriptionShort="Can be deployed into a gunrack that cna hold 24 guns. Created by SausageCo.";
		
		itemSize[]={3,3};
		weight=100;
	};
	class SausageGarage_TrashCan_Kit: SausageKit_Base
	{
		scope=2;
		displayName="SausageCo TrashCan Kit";
		descriptionShort="Can be deployed into a TrashCan for your base so you can throw your shit away. Created by SausageCo.";
		
		itemSize[]={3,2};
		weight=100;
	};
	class SausageKitchen_Cabinets_Kit: SausageKit_Base
	{
		scope=2;
		displayName="SausageCo Cabinets Kit";
		descriptionShort="Can be deployed into a Cabinet for your base so you can store your food or other shit. Created by SausageCo.";
		
		itemSize[]={4,4};
		weight=1600;
	};
	class SausageKitchen_Fridge_Kit: SausageKit_Base
	{
		scope=2;
		displayName="SausageCo Fridge Kit";
		descriptionShort="Can be deployed into a Fridge for your base so you can store your food. Created by SausageCo.";
		
		itemSize[]={4,4};
		weight=1600;
	};
	class SausageKitchen_Sink_Kit: SausageKit_Base
	{
		scope=2;
		displayName="SausageCo Sink Kit";
		descriptionShort="Can be deployed into a Sink for your base so clean your dishes, no not really, you just fill shit up and drink and wash your hands. Created by SausageCo.";
		
		itemSize[]={4,4};
		weight=1600;
	};
	class SausageKitchen_Stove_Kit: SausageKit_Base
	{
		scope=2;
		displayName="SausageCo Stove Kit";
		descriptionShort="Can be deployed into a Stove for your base so you can cook. Created by SausageCo.";
		
		itemSize[]={4,4};
		weight=1600;
	};
	class SausageOffice_Computer_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Office Computer Kit";
		descriptionShort="A Office Couch kit!";
		
		itemSize[]={3,3};
		weight=2000;
	};
	class SausageOffice_Chair_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Office Chair Kit";
		descriptionShort="A Office Chair kit!";
		
		itemSize[]={3,3};
		weight=2000;
	};
	class SausageOffice_Shelves_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Office Shelves Kit";
		descriptionShort="A Office Shelves kit!";
		
		itemSize[]={4,3};
		weight=2000;
	};
	class SausageOffice_Desk_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Office Desk Kit";
		descriptionShort="A Office Desk kit!";
		
		itemSize[]={5,3};
		weight=2000;
	};
	class SausageLivingroom_Couch_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Livingroom Couch Kit";
		descriptionShort="A Livingroom Couch kit!";
		
		itemSize[]={3,3};
		weight=2000;
	};
	class SausageLivingroom_EndTable_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Livingroom EndTable Kit";
		descriptionShort="A Livingroom EndTable kit!";
		
		itemSize[]={4,5};
		weight=2000;
	};
	class SausageLivingroom_Shelf_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Livingroom Shelf Kit";
		descriptionShort="A Livingroom Shelf kit!";
		
		itemSize[]={3,2};
		weight=2000;
	};
	class SausageLivingroom_CoffeeTable_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Livingroom CoffeeTable Kit";
		descriptionShort="A Livingroom CoffeeTable kit!";
		
		itemSize[]={2,3};
		weight=2000;
	};
	class SausageBedroom_BunkBed_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Bedroom BunkBed Kit";
		descriptionShort="A Bedroom BunkBed kit so you can have somewhere to sleep!";
		
		itemSize[]={3,3};
		weight=2000;
	};
	class SausageBedroom_Hopechest_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Bedroom Hopechest Kit";
		descriptionShort="A Bedroom Hopechest kit so you can have somewhere else to store a set of gear and shit!";
		
		itemSize[]={4,5};
		weight=2000;
	};
	class SausageBedroom_NightStand_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Bedroom NightStand Kit";
		descriptionShort="A Bedroom NightStand kit so you can have a stand next to you... at night, a nightstand!";
		
		itemSize[]={3,2};
		weight=2000;
	};
	class SausageBedroom_Dressor_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Bedroom Dressor Kit";
		descriptionShort="A Bedroom Dressor kit so you can have some more storage!";
		
		itemSize[]={2,3};
		weight=2000;
	};
	class SausageBathroom_Sink_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Bathroom Sink Kit";
		descriptionShort="A Bathroom Sink kit so you can have somewhere to wash your hands!";
		
		itemSize[]={3,2};
		weight=2000;
	};
	class SausageBathroom_Bath_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Bathroom Bath Kit";
		descriptionShort="A Bathroom Bath kit so you can have some water storage, or shower, or both... gross!";
		
		itemSize[]={4,5};
		weight=2000;
	};
	class SausageBathroom_Toilet_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Bathroom Toilet Kit";
		descriptionShort="A Bathroom Toilet kit so you can have some poop storage!";
		
		itemSize[]={3,3};
		weight=2000;
	};
	class SausageBathroom_Cabinet_Kit: SausageKit_Base
	{
		scope=2;
		displayName="BathroomCabinet Kit";
		descriptionShort="A Bathroom cabinet kit so you can have some medicine storage!";
		
		itemSize[]={2,3};
		weight=2000;
	};
	class SausageBuilding_Statue_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Statue Kit";
		descriptionShort="Can be deployed into a Statue to Show off your patriotic side!";
		
		itemSize[]={5,6};
		weight=2000;
	};
	class SausageBuilding_WatchTower_Kit: SausageKit_Base
	{
		scope=2;
		displayName="WatchTower Kit";
		descriptionShort="Can be deployed into a WatchTower for base defence!";
		
		itemSize[]={5,6};
		weight=2000;
	};
	class SausageBuilding_Well_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Well Kit";
		descriptionShort="Can be deployed into a Well to use at your base for water. Created by SausageCo.";
		
		itemSize[]={5,6};
		weight=2000;
	};
	class SausageGarden_CompostBin_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Garden Compostbin Kit";
		descriptionShort="Can be deployed into a Compostbin to make fertilizer for gardening. Created by SausageCo.";
		
		itemSize[]={3,2};
		weight=300;
	};
	class SausageStorage_Shed_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Shed Storage Kit";
		descriptionShort="Can be deployed into a Shed you can use for storage. Created by SausageCo.";
		
		itemSize[]={8,6};
		weight=2750;
	};
	class SausageBuilding_Storage_Kit: SausageKit_Base
	{
		scope=2;
		displayName="BuildingStorage Kit";
		descriptionShort="Can be deployed into a sawhorse you can use for storage. Created by SausageCo.";
		
		itemSize[]={4,3};
		weight=750;
	};
	class SausageBuilding_VendMachine_Kit: SausageKit_Base
	{
		scope=2;
		displayName="VendingMachine Kit";
		descriptionShort="Can be deployed into a VendingMachine you can use for storage. Created by SausageCo.";
		
		itemSize[]={4,3};
		weight=750;
	};
	class SausageBuilding_Sign0_Kit: SausageKit_Base
	{
		scope=2;
		displayName="BaseSign#0 Kit";
		descriptionShort="Can be deployed into a sign that says 'Trespassers WILL be SHOT on sight'. Created by SausageCo.";
		
		itemSize[]={4,3};
		weight=750;
	};
	class SausageBuilding_Sign1_Kit: SausageKit_Base
	{
		scope=2;
		displayName="BaseSign#1 Kit";
		descriptionShort="Can be deployed into a sign that says 'Open for Trade, Holster all weapons, Hands Up, Call out 'Looking to Trade', we come to you'. Created by SausageCo.";
		
		itemSize[]={4,5};
		weight=750;
	};
	class SausageBuilding_SignKind_Kit: SausageKit_Base
	{
		scope=2;
		displayName="BaseSign:Kind Kit";
		descriptionShort="Can be deployed into a sign that says 'Help your self to the garden or the well, no payment necessary...'. Created by SausageCo.";
		
		itemSize[]={4,5};
		weight=750;
	};
	class SausageCrateWood1_Storage_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Small WoodenCrate Storage Kit";
		descriptionShort="Can be deployed into a crate to give you more storage! Plus it looks cool. Created by SausageCo.";
		
		itemSize[]={4,4};
		weight=750;
	};
	class SausageCrateWood2_Storage_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Medium WoodenCrate Storage Kit";
		descriptionShort="Can be deployed into a set of crates to give you more storage! Plus it looks cool. Created by SausageCo.";
		
		itemSize[]={4,5};
		weight=1500;
	};
	class SausageCrateWood3_Storage_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Large WoodenCrate Storage Kit";
		descriptionShort="Can be deployed into a set of crates to give you more storage! Plus it looks cool. Created by SausageCo.";
		
		itemSize[]={4,6};
		weight=2250;
		
	};
	class SausageGear_Storage_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Gear Storage Kit";
		descriptionShort="Can be deployed into a Closet to give you a place to store a set of gear! Plus it looks cool. Created by SausageCo.";
		
		itemSize[]={4,6};
		weight=2250;
		
	};
	class SausageDecor_Picture1_Kit: SausageKit_Base
	{
		scope=2;
		displayName="Picture to place around your base.";
		descriptionShort="Picture to place around your base.";
		model="\DZ\structures\furniture\decoration\wallboards\picture_a\picture_a.p3d";
		itemSize[]={2,2};
		weight=10;	
		
	};
};
