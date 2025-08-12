class CfgPatches
{
    class MyMod_DryingRack
    {
        units[] = {"DryingRack"};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgVehicles
{
    class Inventory_Base;
    class SC_DryingRack: Inventory_Base
    {
        scope = 2;
        displayName = "Clothing Drying Rack";
        descriptionShort = "A rack for drying wet clothing";
        model = "SausageCo\Objects\dryingrack\drying_rack.p3d";  // You'll need to create this model
        weight = 3000;
        itemSize[] = {4,8};
        physLayer = "item_large";
        hiddenSelections[] = {
            "proxy_body",
            "proxy_legs",
            "proxy_feet",
            "proxy_headgear",
            "proxy_mask",
            "proxy_gloves",
            "proxy_back",
            "proxy_hips",
            "proxy_vest"
        };
        hiddenSelectionsTextures[] = {
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
        attachments[] = {
            "Body",
            "Legs",
            "Feet",
            "Headgear",
            "Mask",
            "Gloves",
			"Back",
			"Hips",
			"Vest"
			
        };
        
        class GUIInventoryAttachmentsProps
        {
            class Clothing
            {
                name = "Clothing";
                description = "Clothing attachment slots";
                attachmentSlots[] = {
                    "Body",
					"Legs",
					"Feet",
					"Headgear",
					"Mask",
					"Gloves",
					"Back",
					"Hips",
					"Vest"
                };
                icon = "set:dayz_inventory image:clothes";
            };
        };
    };
	class SC_DryingRack_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "DryingRack HOLO";
		model="SausageCo\Objects\DryingRack\DryingRack.p3d";
	};
};