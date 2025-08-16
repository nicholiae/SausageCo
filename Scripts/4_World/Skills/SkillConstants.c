/**
 * SausageCo Skills System
 * Skill Constants and Definitions
 */

// RPC Commands for Skills System
enum SausageSkillsRPCCommands
{
    INVALID = 0,
    REQUEST_SKILLS_DATA = 100,
    SYNC_PLAYER_SKILLS = 101,
    UPDATE_SKILL = 102,
    CRAFT_RECIPE = 103
}

// Menu ID for Skills Menu
const int MENU_SAUSAGE_SKILLS = 38475; // Unique ID for our menu

// Skill Types
class SkillTypes
{
    const static string ENGINEERING = "engineering";
    const static string FARMING = "farming";
    const static string FIREARM = "firearm";
    const static string LEATHER = "leather";
    const static string MECHANIC = "mechanic";
    const static string MEDIC = "medic";
    const static string HUNTER = "hunter";
    const static string COOK = "cook";
    
    // Get all skill types as an array
    static array<string> GetAllTypes()
    {
        array<string> types = new array<string>();
        types.Insert(ENGINEERING);
        types.Insert(FARMING);
        types.Insert(FIREARM);
        types.Insert(LEATHER);
        types.Insert(MECHANIC);
        types.Insert(MEDIC);
        types.Insert(HUNTER);
        types.Insert(COOK);
        return types;
    }
}

// Input action for opening skills menu
class SausageSkillsInputActions
{
    const static int OPEN_SKILLS_MENU = 1043; // Unique ID for our input action
}