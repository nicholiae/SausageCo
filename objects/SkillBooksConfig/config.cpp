class CfgPatches
{
    class SausageCo_SkillBooks
    {
        units[] = {
            "SausageCo_SkillBook_Engineering",
            "SausageCo_SkillBook_Farming",
            "SausageCo_SkillBook_Firearm",
            "SausageCo_SkillBook_Leather",
            "SausageCo_SkillBook_Mechanic",
            "SausageCo_SkillBook_Medic",
            "SausageCo_SkillBook_Hunter",
            "SausageCo_SkillBook_Cook"
        };
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgVehicles
{
    class Inventory_Base;
    
    // Base Skill Book
    class SausageCo_SkillBook_Base: Inventory_Base
    {
        scope = 0;
        displayName = "Skill Book";
        descriptionShort = "A book containing knowledge about various skills.";
        model = "\dz\gear\books\book_kniga.p3d";
        weight = 200;
        itemSize[] = {2,2};
        rotationFlags = 1;
        hiddenSelectionsTextures[] = {"dz\gear\books\data\book_kniga_co.paa"};
    };
    
    // Engineering Skill Book
    class SausageCo_SkillBook_Engineering: SausageCo_SkillBook_Base
    {
        scope = 2;
        displayName = "Engineering Manual";
        descriptionShort = "A book containing detailed instructions for various engineering projects and structures.";
        hiddenSelectionsTextures[] = {"dz\gear\books\data\book_kniga_co.paa"};
    };
    
    // Farming Skill Book
    class SausageCo_SkillBook_Farming: SausageCo_SkillBook_Base
    {
        scope = 2;
        displayName = "Farming Guide";
        descriptionShort = "A book containing information about planting, growing, and harvesting various crops.";
        hiddenSelectionsTextures[] = {"dz\gear\books\data\book_kniga_green_co.paa"};
    };
    
    // Firearm Skill Book
    class SausageCo_SkillBook_Firearm: SausageCo_SkillBook_Base
    {
        scope = 2;
        displayName = "Firearm Handbook";
        descriptionShort = "A book containing information about firearm maintenance, ammunition crafting, and weapon modifications.";
        hiddenSelectionsTextures[] = {"dz\gear\books\data\book_kniga_red_co.paa"};
    };
    
    // Leather Skill Book
    class SausageCo_SkillBook_Leather: SausageCo_SkillBook_Base
    {
        scope = 2;
        displayName = "Leatherworking Guide";
        descriptionShort = "A book containing techniques for tanning hides and crafting leather items.";
        hiddenSelectionsTextures[] = {"dz\gear\books\data\book_kniga_yellow_co.paa"};
    };
    
    // Mechanic Skill Book
    class SausageCo_SkillBook_Mechanic: SausageCo_SkillBook_Base
    {
        scope = 2;
        displayName = "Mechanic's Manual";
        descriptionShort = "A book containing information about vehicle repair, maintenance, and part fabrication.";
        hiddenSelectionsTextures[] = {"dz\gear\books\data\book_kniga_blue_co.paa"};
    };
    
    // Medic Skill Book
    class SausageCo_SkillBook_Medic: SausageCo_SkillBook_Base
    {
        scope = 2;
        displayName = "Medical Handbook";
        descriptionShort = "A book containing information about treating injuries, crafting medical supplies, and disease management.";
        hiddenSelectionsTextures[] = {"dz\gear\books\data\book_kniga_white_co.paa"};
    };
    
    // Hunter Skill Book
    class SausageCo_SkillBook_Hunter: SausageCo_SkillBook_Base
    {
        scope = 2;
        displayName = "Hunter's Guide";
        descriptionShort = "A book containing information about tracking, trapping, and processing game animals.";
        hiddenSelectionsTextures[] = {"dz\gear\books\data\book_kniga_brown_co.paa"};
    };
    
    // Cook Skill Book
    class SausageCo_SkillBook_Cook: SausageCo_SkillBook_Base
    {
        scope = 2;
        displayName = "Cooking Manual";
        descriptionShort = "A book containing recipes for preparing and preserving various foods.";
        hiddenSelectionsTextures[] = {"dz\gear\books\data\book_kniga_orange_co.paa"};
    };
};