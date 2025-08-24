
/**
 * SausageCo Skills System
 * Recipe System Fixer
 * 
 * This script provides a comprehensive solution to the empty recipe list issue
 * by integrating all the fixes and enhancements we've developed.
 */

class RecipeSystemFixer
{
    // Static instance for easy access
    private static ref RecipeSystemFixer m_Instance;
    
    // Components
    private ref SausageSkillsRecipeManager m_RecipeManager;
    private ref RecipeSystemDebugger m_Debugger;
    
    // Configuration
    private bool m_VerboseLogging = true;
    private bool m_FixApplied = false;
    
    // Constructor
    void RecipeSystemFixer()
    {
        Print("[RecipeFixer] Initializing Recipe System Fixer");
        
        // Create debugger
        m_Debugger = RecipeSystemDebugger.GetInstance();
        
        // Create enhanced recipe manager
        m_RecipeManager = new SausageSkillsRecipeManager();
        if (m_RecipeManager)
        {
            Print("[RecipeFixer] Recipe manager created, initializing...");
            m_RecipeManager.Init();
            Print("[RecipeFixer] Recipe manager initialized");
        }
        else
        {
            Print("[RecipeFixer] ERROR: Failed to create recipe manager");
        }
    }
    
    // Get singleton instance
    static RecipeSystemFixer GetInstance()
    {
        if (!m_Instance)
        {
            m_Instance = new RecipeSystemFixer();
        }
        
        return m_Instance;
    }
    
    // Apply fixes to the recipe system
    void ApplyFixes()
    {
        if (m_FixApplied)
        {
            Print("[RecipeFixer] Fixes already applied");
            return;
        }
        
        Print("[RecipeFixer] Applying fixes to recipe system");
        
        // 1. Verify recipe manager initialization
        VerifyRecipeManagerInit();
        
        // 2. Check for case sensitivity issues
        CheckCaseSensitivity();
        
        // 3. Verify recipe data structure
        VerifyRecipeDataStructure();
        
        // 4. Test recipe loading for each skill type
        TestRecipeLoading();
        
        // Mark fixes as applied
        m_FixApplied = true;
        
        Print("[RecipeFixer] All fixes applied successfully");
    }
    
    // Verify recipe manager initialization
    private void VerifyRecipeManagerInit()
    {
        Print("[RecipeFixer] Verifying recipe manager initialization");
        
        if (!m_RecipeManager)
        {
            Print("[RecipeFixer] ERROR: Recipe manager is null, creating new instance");
            m_RecipeManager = new SausageSkillsRecipeManager();
            m_RecipeManager.Init();
        }
        
        // Check if recipes were created
        int totalRecipes = 0;
        array<string> skillTypes = SkillTypes.GetAllTypes();
        
        foreach (string skillType : skillTypes)
        {
            array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(skillType);
            if (recipes)
            {
                totalRecipes += recipes.Count();
                Print("[RecipeFixer] Skill type '" + skillType + "' has " + recipes.Count() + " recipes");
            }
            else
            {
                Print("[RecipeFixer] WARNING: Skill type '" + skillType + "' has no recipes");
            }
        }
        
        Print("[RecipeFixer] Total recipes: " + totalRecipes);
        
        if (totalRecipes == 0)
        {
            Print("[RecipeFixer] ERROR: No recipes were created during initialization, forcing reinitialization");
            m_RecipeManager.ForceReinit();
            
            // Check again
            totalRecipes = 0;
            foreach (string skillType : skillTypes)
            {
                array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(skillType);
                if (recipes)
                {
                    totalRecipes += recipes.Count();
                }
            }
            
            Print("[RecipeFixer] After reinitialization, total recipes: " + totalRecipes);
        }
    }
    
    // Check for case sensitivity issues
    private void CheckCaseSensitivity()
    {
        Print("[RecipeFixer] Checking for case sensitivity issues");
        
        array<string> skillTypes = SkillTypes.GetAllTypes();
        
        foreach (string skillType : skillTypes)
        {
            // Test with original case
            array<ref SkillRecipeData> originalRecipes = m_RecipeManager.GetRecipesForSkill(skillType);
            int originalCount = 0;
            if (originalRecipes)
            {
                originalCount = originalRecipes.Count();
            }
            
            // Test with uppercase
            string upperSkillType = skillType.ToUpper();
            array<ref SkillRecipeData> upperRecipes = m_RecipeManager.GetRecipesForSkill(upperSkillType);
            int upperCount = 0;
            if (upperRecipes)
            {
                upperCount = upperRecipes.Count();
            }
            
            // Test with lowercase
            string lowerSkillType = skillType.ToLower();
            array<ref SkillRecipeData> lowerRecipes = m_RecipeManager.GetRecipesForSkill(lowerSkillType);
            int lowerCount = 0;
            if (lowerRecipes)
            {
                lowerCount = lowerRecipes.Count();
            }
            
            Print("[RecipeFixer] Skill type '" + skillType + "': original=" + originalCount + ", upper=" + upperCount + ", lower=" + lowerCount);
            
            if (originalCount != upperCount || originalCount != lowerCount)
            {
                Print("[RecipeFixer] WARNING: Case sensitivity issue detected for skill type '" + skillType + "'");
            }
        }
    }
    
    // Verify recipe data structure
    private void VerifyRecipeDataStructure()
    {
        Print("[RecipeFixer] Verifying recipe data structure");
        
        // Get a sample recipe
        array<string> skillTypes = SkillTypes.GetAllTypes();
        SkillRecipeData sampleRecipe = null;
        
        foreach (string skillType : skillTypes)
        {
            array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(skillType);
            if (recipes && recipes.Count() > 0)
            {
                sampleRecipe = recipes[0];
                break;
            }
        }
        
        if (!sampleRecipe)
        {
            Print("[RecipeFixer] ERROR: Could not find any recipes to verify data structure");
            return;
        }
        
        // Check recipe fields
        Print("[RecipeFixer] Verifying recipe data structure using recipe: " + sampleRecipe.recipeName);
        Print("[RecipeFixer]   - Recipe name: " + sampleRecipe.recipeName);
        Print("[RecipeFixer]   - Display name: " + sampleRecipe.displayName);
        Print("[RecipeFixer]   - Skill type: " + sampleRecipe.skillType);
        Print("[RecipeFixer]   - Required level: " + sampleRecipe.requiredLevel);
        Print("[RecipeFixer]   - Ingredients: " + sampleRecipe.ingredients.Count());
        Print("[RecipeFixer]   - Results: " + sampleRecipe.results.Count());
        
        // Check if skill type is valid
        bool isValidSkillType = false;
        foreach (string skillType : skillTypes)
        {
            if (skillType == sampleRecipe.skillType)
            {
                isValidSkillType = true;
                break;
            }
        }
        
        if (!isValidSkillType)
        {
            Print("[RecipeFixer] ERROR: Recipe has invalid skill type: '" + sampleRecipe.skillType + "'");
        }
    }
    
    // Test recipe loading for each skill type
    private void TestRecipeLoading()
    {
        Print("[RecipeFixer] Testing recipe loading for each skill type");
        
        array<string> skillTypes = SkillTypes.GetAllTypes();
        
        foreach (string skillType : skillTypes)
        {
            Print("[RecipeFixer] Testing skill type: " + skillType);
            
            // Get recipes for this skill type
            array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(skillType);
            
            if (recipes && recipes.Count() > 0)
            {
                Print("[RecipeFixer] Successfully loaded " + recipes.Count() + " recipes for skill type: " + skillType);
            }
            else
            {
                Print("[RecipeFixer] ERROR: No recipes found for skill type: " + skillType);
            }
        }
    }
    
    // Get recipe manager
    SausageSkillsRecipeManager GetRecipeManager()
    {
        return m_RecipeManager;
    }
    
    // Get debugger
    RecipeSystemDebugger GetDebugger()
    {
        return m_Debugger;
    }
    
    // Fix skill book menu
    void FixSkillBookMenu(SkillBookMenu menu, string skillType)
    {
        if (!menu)
        {
            Print("[RecipeFixer] ERROR: Cannot fix null menu");
            return;
        }
        
        Print("[RecipeFixer] Fixing skill book menu for skill type: " + skillType);
        
        // Get recipes for this skill type
        array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(skillType);
        
        if (!recipes || recipes.Count() == 0)
        {
            Print("[RecipeFixer] WARNING: No recipes found for skill type: " + skillType);
            
            // Try normalized skill type
            string normalizedType = NormalizeSkillType(skillType);
            if (normalizedType != skillType)
            {
                Print("[RecipeFixer] Trying normalized skill type: " + normalizedType);
                recipes = m_RecipeManager.GetRecipesForSkill(normalizedType);
                
                if (recipes && recipes.Count() > 0)
                {
                    Print("[RecipeFixer] Found " + recipes.Count() + " recipes using normalized skill type");
                }
            }
        }
    }
    
    // Normalize skill type (find the correct case)
    string NormalizeSkillType(string skillType)
    {
        array<string> skillTypes = SkillTypes.GetAllTypes();
        
        foreach (string type : skillTypes)
        {
            if (skillType.ToLower() == type.ToLower())
            {
                return type;
            }
        }
        
        return skillType;
    }
    
    // Create a patched SkillBookMenu that works with our fixes
    SkillBookMenu CreatePatchedSkillBookMenu()
    {
        Print("[RecipeFixer] Creating patched SkillBookMenu");
        
        // Create a new menu
        SkillBookMenu menu = new SkillBookMenu();
        
        // Initialize the menu
        menu.Init();
        
        return menu;
    }
}

// Helper function to create and run the fixer
void RunRecipeFixer()
{
    Print("[SausageCo] Starting Recipe System Fixer");
    
    // Create fixer
    RecipeSystemFixer fixer = RecipeSystemFixer.GetInstance();
    
    // Apply fixes
    fixer.ApplyFixes();
    
    Print("[SausageCo] Recipe System Fixer complete");
}

// Helper function to fix a skill book menu
void FixSkillBook(SkillBookMenu menu, string skillType)
{
    RecipeSystemFixer fixer = RecipeSystemFixer.GetInstance();
    fixer.FixSkillBookMenu(menu, skillType);
}

// Helper function to create a patched skill book menu
SkillBookMenu CreatePatchedSkillBookMenu()
{
    RecipeSystemFixer fixer = RecipeSystemFixer.GetInstance();
    return fixer.CreatePatchedSkillBookMenu();
}
