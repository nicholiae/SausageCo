
/**
 * SausageCo Skills System
 * Recipe Manager - Enhanced Version with Debug Logging
 */

class SausageSkillsRecipeManager
{
    // Recipe database
    private ref map<string, ref SkillRecipeData> m_Recipes;
    
    // Debug flags
    private bool m_Debug = true;
    private bool m_Initialized = false;
    
    void SausageSkillsRecipeManager()
    {
        m_Recipes = new map<string, ref SkillRecipeData>();
        DebugLog("SausageSkillsRecipeManager constructor called");
    }
    
    void Init()
    {
        DebugLog("Initializing Recipe Manager");
        
        // Create default recipes
        CreateDefaultRecipes();
        
        // Mark as initialized
        m_Initialized = true;
        
        // Log recipe count
        DebugLog("Recipe Manager initialized with " + m_Recipes.Count() + " recipes");
        
        // Log recipes per skill type
        LogRecipesPerSkillType();
    }
    
    void CreateDefaultRecipes()
    {
        // Engineering recipes
        CreateWoodenPlankRecipe();
        CreateBasicShelterRecipe();
        CreateImprovedShelterRecipe();
        CreateWoodenCrateRecipe();
        CreateMiningFurnaceRecipe();
        CreateWorkBenchRecipe();
        
        // Farming recipes
        CreatePlantTomatoRecipe();
        CreatePlantZucchiniRecipe();
        CreatePlantPumpkinRecipe();
        CreateImprovedCompostRecipe();
        
        // Firearm recipes
        CreateBasicAmmoRecipe();
        CreateWeaponCleaningRecipe();
        CreateImprovedAmmoRecipe();
        
        // Leather recipes
        CreateBasicTanningRecipe();
        CreateLeatherPouchRecipe();
        
        // Mechanic recipes
        CreateBasicRepairRecipe();
        CreateTireChangeRecipe();
        
        // Medic recipes
        CreateBasicBandageRecipe();
        CreateHerbalTeaRecipe();
        
        // Hunter recipes
        CreateBasicButcheringRecipe();
        CreateSimpleSnareRecipe();
        
        // Cook recipes
        CreateBasicCookingRecipe();
        CreateSimplePreservationRecipe();
        
        DebugLog("Created " + m_Recipes.Count() + " recipes");
    }
    
    // Engineering Recipes
    void CreateWoodenPlankRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "WoodenPlank";
        recipe.displayName = "Wooden Planks";
        recipe.description = "Process logs into wooden planks for building.";
        recipe.skillType = SkillTypes.ENGINEERING;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("WoodenLog", 1));
        recipe.results.Insert(new Param2<string, int>("WoodenPlank", 4));
        recipe.craftingTime = 5.0;
        recipe.xpReward = 15; // Added XP reward
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    // ... [All other recipe creation methods remain the same] ...
    
    // Get a recipe by name
    ref SkillRecipeData GetRecipe(string recipeName)
    {
        // Check if initialized
        if (!m_Initialized)
        {
            DebugLog("WARNING: GetRecipe called before initialization, initializing now...");
            Init();
        }
        
        if (m_Recipes.Contains(recipeName))
        {
            return m_Recipes.Get(recipeName);
        }
        
        DebugLog("Recipe not found: " + recipeName);
        return null;
    }
    
    // Get all recipes for a skill type
    array<ref SkillRecipeData> GetRecipesForSkill(string skillType)
    {
        // Check if initialized
        if (!m_Initialized)
        {
            DebugLog("WARNING: GetRecipesForSkill called before initialization, initializing now...");
            Init();
        }
        
        array<ref SkillRecipeData> recipes = new array<ref SkillRecipeData>();
        
        // Debug log
        DebugLog("Getting recipes for skill type: '" + skillType + "'");
        
        // Try case-sensitive match first
        int exactMatchCount = 0;
        foreach (string recipeName, ref SkillRecipeData recipe : m_Recipes)
        {
            if (recipe.skillType == skillType)
            {
                recipes.Insert(recipe);
                exactMatchCount++;
            }
        }
        
        DebugLog("Found " + exactMatchCount + " recipes with exact match for skill type: '" + skillType + "'");
        
        // If no exact matches, try case-insensitive match
        if (exactMatchCount == 0)
        {
            DebugLog("No exact matches, trying case-insensitive match for: '" + skillType + "'");
            
            string lowerSkillType = skillType.ToLower();
            foreach (string recipeName, ref SkillRecipeData recipe : m_Recipes)
            {
                string lowerRecipeSkillType = recipe.skillType.ToLower();
                if (lowerRecipeSkillType == lowerSkillType)
                {
                    recipes.Insert(recipe);
                    DebugLog("Found case-insensitive match: '" + recipe.skillType + "' for '" + skillType + "'");
                }
            }
            
            DebugLog("Found " + recipes.Count() + " recipes with case-insensitive match");
        }
        
        // Check if we found any recipes
        if (recipes.Count() == 0)
        {
            // Check if this is a valid skill type
            bool isValidSkillType = false;
            array<string> skillTypes = SkillTypes.GetAllTypes();
            foreach (string type : skillTypes)
            {
                if (type == skillType)
                {
                    isValidSkillType = true;
                    break;
                }
            }
            
            if (!isValidSkillType)
            {
                DebugLog("WARNING: Invalid skill type: '" + skillType + "'");
                DebugLog("Valid skill types are:");
                foreach (string type : skillTypes)
                {
                    DebugLog("  - '" + type + "'");
                }
            }
        }
        
        return recipes;
    }
    
    // Get recipes for a specific skill level
    array<ref SkillRecipeData> GetRecipesForSkillLevel(string skillType, int level)
    {
        // Check if initialized
        if (!m_Initialized)
        {
            DebugLog("WARNING: GetRecipesForSkillLevel called before initialization, initializing now...");
            Init();
        }
        
        array<ref SkillRecipeData> recipes = new array<ref SkillRecipeData>();
        
        foreach (string recipeName, ref SkillRecipeData recipe : m_Recipes)
        {
            if (recipe.skillType == skillType && recipe.requiredLevel == level)
            {
                recipes.Insert(recipe);
            }
        }
        
        return recipes;
    }
    
    // Award XP for crafting a recipe
    void AwardRecipeXP(PlayerBase player, string recipeName)
    {
        if (!GetGame().IsServer() || !player)
            return;
            
        ref SkillRecipeData recipe = GetRecipe(recipeName);
        if (recipe)
        {
            // Use the XP events system to award XP
            SkillXPEvents.AwardRecipeXP(player, recipeName, recipe.xpReward, recipe.skillType);
        }
    }
    
    // Debug logging
    private void DebugLog(string message)
    {
        if (m_Debug)
        {
            Print("[SausageSkillsRecipeManager] " + message);
        }
    }
    
    // Log recipes per skill type
    private void LogRecipesPerSkillType()
    {
        if (!m_Debug)
            return;
            
        DebugLog("Logging recipes per skill type:");
        
        // Get all skill types
        array<string> skillTypes = SkillTypes.GetAllTypes();
        
        // Count recipes for each skill type
        foreach (string skillType : skillTypes)
        {
            int count = 0;
            foreach (string recipeName, ref SkillRecipeData recipe : m_Recipes)
            {
                if (recipe.skillType == skillType)
                {
                    count++;
                }
            }
            
            DebugLog("  - Skill type '" + skillType + "' has " + count + " recipes");
        }
    }
    
    // Check if initialized
    bool IsInitialized()
    {
        return m_Initialized;
    }
    
    // Get total recipe count
    int GetTotalRecipeCount()
    {
        return m_Recipes.Count();
    }
    
    // Force reinitialization
    void ForceReinit()
    {
        DebugLog("Forcing reinitialization of recipe manager");
        m_Recipes.Clear();
        m_Initialized = false;
        Init();
    }
}
