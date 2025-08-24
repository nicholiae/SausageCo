
/**
 * SausageCo Skills System
 * Recipe System Debugger
 * 
 * This script helps diagnose issues with the recipe system by providing
 * detailed logging and verification of the recipe data flow.
 */

class RecipeSystemDebugger
{
    // Static instance for easy access
    private static ref RecipeSystemDebugger m_Instance;
    
    // Recipe manager reference
    private ref SausageSkillsRecipeManager m_RecipeManager;
    
    // Debug flags
    private bool m_VerboseLogging = true;
    
    // Constructor
    void RecipeSystemDebugger()
    {
        Print("[RecipeDebugger] Initializing Recipe System Debugger");
        
        // Create recipe manager
        m_RecipeManager = new SausageSkillsRecipeManager();
        if (m_RecipeManager)
        {
            Print("[RecipeDebugger] Recipe manager created, initializing...");
            m_RecipeManager.Init();
            Print("[RecipeDebugger] Recipe manager initialized");
            
            // Verify recipe data
            VerifyRecipeData();
        }
        else
        {
            Print("[RecipeDebugger] ERROR: Failed to create recipe manager");
        }
    }
    
    // Get singleton instance
    static RecipeSystemDebugger GetInstance()
    {
        if (!m_Instance)
        {
            m_Instance = new RecipeSystemDebugger();
        }
        
        return m_Instance;
    }
    
    // Verify recipe data
    void VerifyRecipeData()
    {
        Print("[RecipeDebugger] Verifying recipe data...");
        
        // Check if recipe manager is initialized
        if (!m_RecipeManager)
        {
            Print("[RecipeDebugger] ERROR: Recipe manager is null");
            return;
        }
        
        // Get all skill types
        array<string> skillTypes = SkillTypes.GetAllTypes();
        Print("[RecipeDebugger] Found " + skillTypes.Count() + " skill types");
        
        // Check recipes for each skill type
        foreach (string skillType : skillTypes)
        {
            array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(skillType);
            
            if (recipes && recipes.Count() > 0)
            {
                Print("[RecipeDebugger] Skill type '" + skillType + "' has " + recipes.Count() + " recipes");
                
                if (m_VerboseLogging)
                {
                    // Log each recipe
                    foreach (SkillRecipeData recipe : recipes)
                    {
                        Print("[RecipeDebugger]   - Recipe: " + recipe.recipeName + " (" + recipe.displayName + ")");
                        Print("[RecipeDebugger]     Level: " + recipe.requiredLevel);
                        Print("[RecipeDebugger]     Ingredients: " + recipe.ingredients.Count());
                        Print("[RecipeDebugger]     Results: " + recipe.results.Count());
                    }
                }
            }
            else
            {
                Print("[RecipeDebugger] WARNING: Skill type '" + skillType + "' has no recipes");
            }
        }
        
        Print("[RecipeDebugger] Recipe verification complete");
    }
    
    // Test recipe loading for a specific skill type
    void TestRecipeLoading(string skillType)
    {
        Print("[RecipeDebugger] Testing recipe loading for skill type: " + skillType);
        
        // Check if recipe manager is initialized
        if (!m_RecipeManager)
        {
            Print("[RecipeDebugger] ERROR: Recipe manager is null");
            return;
        }
        
        // Get recipes for this skill type
        array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(skillType);
        
        if (recipes && recipes.Count() > 0)
        {
            Print("[RecipeDebugger] Successfully loaded " + recipes.Count() + " recipes for skill type: " + skillType);
            
            // Log each recipe
            foreach (SkillRecipeData recipe : recipes)
            {
                Print("[RecipeDebugger]   - Recipe: " + recipe.recipeName + " (" + recipe.displayName + ")");
            }
        }
        else
        {
            Print("[RecipeDebugger] ERROR: No recipes found for skill type: " + skillType);
            
            // Check if skill type is valid
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
                Print("[RecipeDebugger] ERROR: Invalid skill type: " + skillType);
                Print("[RecipeDebugger] Valid skill types are:");
                foreach (string type : skillTypes)
                {
                    Print("[RecipeDebugger]   - " + type);
                }
            }
        }
    }
    
    // Compare skill type strings to check for case sensitivity issues
    void CheckSkillTypeStrings(string skillType)
    {
        Print("[RecipeDebugger] Checking skill type string: '" + skillType + "'");
        
        array<string> skillTypes = SkillTypes.GetAllTypes();
        foreach (string type : skillTypes)
        {
            Print("[RecipeDebugger] Comparing with: '" + type + "'");
            Print("[RecipeDebugger]   - Equal (==): " + (skillType == type));
            Print("[RecipeDebugger]   - Case insensitive: " + (skillType.ToLower() == type.ToLower()));
        }
    }
    
    // Check recipe manager initialization
    bool IsRecipeManagerInitialized()
    {
        return m_RecipeManager != null;
    }
    
    // Get recipe count for a skill type
    int GetRecipeCount(string skillType)
    {
        if (!m_RecipeManager)
            return 0;
            
        array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(skillType);
        if (recipes)
            return recipes.Count();
            
        return 0;
    }
}

// Helper function to create and run the debugger
void RunRecipeDebugger()
{
    Print("[SausageCo] Starting Recipe System Debugger");
    
    // Create debugger
    RecipeSystemDebugger debugger = RecipeSystemDebugger.GetInstance();
    
    // Test recipe loading for each skill type
    array<string> skillTypes = SkillTypes.GetAllTypes();
    foreach (string skillType : skillTypes)
    {
        debugger.TestRecipeLoading(skillType);
    }
    
    Print("[SausageCo] Recipe System Debugger complete");
}
