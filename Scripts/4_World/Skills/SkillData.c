/**
 * SausageCo Skills System
 * Skill Data Structures
 */

// Player information class
class PlayerInfo
{
    string steamId;
    string playerName;
    string lastUpdate;
    
    void PlayerInfo(string id = "")
    {
        steamId = id;
        playerName = "";
        lastUpdate = "";
    }
}

// Individual skill data
class SkillData
{
    int level;
    int experience;
    int nextLevelAt;
    ref array<string> unlockedRecipes;
    
    void SkillData()
    {
        level = 0;
        experience = 0;
        nextLevelAt = 1000;
        unlockedRecipes = new array<string>();
    }
}

// Complete player skills data
class PlayerSkillsData
{
    ref PlayerInfo playerInfo;
    ref map<string, ref SkillData> skills;
    
    void PlayerSkillsData()
    {
        playerInfo = new PlayerInfo();
        skills = new map<string, ref SkillData>();
    }
    
    // Get skill level for a specific skill type
    int GetSkillLevel(string skillType)
    {
        if (skills && skills.Contains(skillType))
        {
            return skills.Get(skillType).level;
        }
        return 0;
    }
    
    // Get skill experience for a specific skill type
    int GetSkillExperience(string skillType)
    {
        if (skills && skills.Contains(skillType))
        {
            return skills.Get(skillType).experience;
        }
        return 0;
    }
    
    // Check if a recipe is unlocked
    bool HasUnlockedRecipe(string skillType, string recipeName)
    {
        if (skills && skills.Contains(skillType))
        {
            ref SkillData skillData = skills.Get(skillType);
            if (skillData.unlockedRecipes)
            {
                return skillData.unlockedRecipes.Find(recipeName) != -1;
            }
        }
        return false;
    }
    
    // Get all unlocked recipes for a skill type
    array<string> GetUnlockedRecipes(string skillType)
    {
        array<string> recipes = new array<string>();
        
        if (skills && skills.Contains(skillType))
        {
            ref SkillData skillData = skills.Get(skillType);
            if (skillData.unlockedRecipes)
            {
                recipes.Copy(skillData.unlockedRecipes);
            }
        }
        
        return recipes;
    }
}

// Skill type configuration
class SkillTypeConfig
{
    string displayName;
    string description;
    string icon;
    ref array<int> levelXpRequirements;
    ref map<int, ref array<string>> levelRecipes;
    
    void SkillTypeConfig()
    {
        levelXpRequirements = new array<int>();
        levelRecipes = new map<int, ref array<string>>();
    }
}

// Recipe data structure
class SkillRecipeData
{
    string recipeName;
    string displayName;
    string description;
    string skillType;
    int requiredLevel;
    ref array<ref Param2<string, int>> ingredients; // Item classname and quantity
    ref array<ref Param2<string, int>> results; // Item classname and quantity
    float craftingTime;
    int xpReward; // Added XP reward field
    
    void SkillRecipeData()
    {
        ingredients = new array<ref Param2<string, int>>();
        results = new array<ref Param2<string, int>>();
        craftingTime = 1.0;
        xpReward = 10; // Default XP reward
    }
}