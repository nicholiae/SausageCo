
/**
 * SausageCo Skills System
 * Recipe System Test Script
 * 
 * This script provides a way to test the recipe system independently
 * to verify that recipes are being created and loaded correctly.
 */

class TestRecipeSystem
{
    // Custom string conversion functions
    static string ConvertToUpperCase(string input)
    {
        string result = "";
        for (int i = 0; i < input.Length(); i++)
        {
            string currentChar = input.Substring(i, 1);
            
            // Check if the character is lowercase (a-z)
            if (currentChar >= "a" && currentChar <= "z")
            {
                // Convert to uppercase using a simple mapping
                if (currentChar == "a") result += "A";
                else if (currentChar == "b") result += "B";
                else if (currentChar == "c") result += "C";
                else if (currentChar == "d") result += "D";
                else if (currentChar == "e") result += "E";
                else if (currentChar == "f") result += "F";
                else if (currentChar == "g") result += "G";
                else if (currentChar == "h") result += "H";
                else if (currentChar == "i") result += "I";
                else if (currentChar == "j") result += "J";
                else if (currentChar == "k") result += "K";
                else if (currentChar == "l") result += "L";
                else if (currentChar == "m") result += "M";
                else if (currentChar == "n") result += "N";
                else if (currentChar == "o") result += "O";
                else if (currentChar == "p") result += "P";
                else if (currentChar == "q") result += "Q";
                else if (currentChar == "r") result += "R";
                else if (currentChar == "s") result += "S";
                else if (currentChar == "t") result += "T";
                else if (currentChar == "u") result += "U";
                else if (currentChar == "v") result += "V";
                else if (currentChar == "w") result += "W";
                else if (currentChar == "x") result += "X";
                else if (currentChar == "y") result += "Y";
                else if (currentChar == "z") result += "Z";
                else result += currentChar; // Fallback
            }
            else
            {
                result += currentChar;
            }
        }
        return result;
    }

    static string ConvertToLowerCase(string input)
    {
        string result = "";
        for (int i = 0; i < input.Length(); i++)
        {
            string currentChar = input.Substring(i, 1);
            
            // Check if the character is uppercase (A-Z)
            if (currentChar >= "A" && currentChar <= "Z")
            {
                // Convert to lowercase using a simple mapping
                if (currentChar == "A") result += "a";
                else if (currentChar == "B") result += "b";
                else if (currentChar == "C") result += "c";
                else if (currentChar == "D") result += "d";
                else if (currentChar == "E") result += "e";
                else if (currentChar == "F") result += "f";
                else if (currentChar == "G") result += "g";
                else if (currentChar == "H") result += "h";
                else if (currentChar == "I") result += "i";
                else if (currentChar == "J") result += "j";
                else if (currentChar == "K") result += "k";
                else if (currentChar == "L") result += "l";
                else if (currentChar == "M") result += "m";
                else if (currentChar == "N") result += "n";
                else if (currentChar == "O") result += "o";
                else if (currentChar == "P") result += "p";
                else if (currentChar == "Q") result += "q";
                else if (currentChar == "R") result += "r";
                else if (currentChar == "S") result += "s";
                else if (currentChar == "T") result += "t";
                else if (currentChar == "U") result += "u";
                else if (currentChar == "V") result += "v";
                else if (currentChar == "W") result += "w";
                else if (currentChar == "X") result += "x";
                else if (currentChar == "Y") result += "y";
                else if (currentChar == "Z") result += "z";
                else result += currentChar; // Fallback
            }
            else
            {
                result += currentChar;
            }
        }
        return result;
    }

    // Run a comprehensive test of the recipe system
    static void RunTest()
    {
        Print("[TestRecipeSystem] Starting recipe system test");
        
        // Test recipe manager creation and initialization
        TestRecipeManagerInit();
        
        // Test recipe loading for each skill type
        TestRecipeLoading();
        
        // Test recipe data structure
        TestRecipeDataStructure();
        
        Print("[TestRecipeSystem] Recipe system test complete");
    }
    
    // Test recipe manager creation and initialization
    static void TestRecipeManagerInit()
    {
        Print("[TestRecipeSystem] Testing recipe manager initialization");
        
        // Create recipe manager
        ref SausageSkillsRecipeManager recipeManager = new SausageSkillsRecipeManager();
        if (!recipeManager)
        {
            Print("[TestRecipeSystem] ERROR: Failed to create recipe manager");
            return;
        }
        
        Print("[TestRecipeSystem] Recipe manager created successfully");
        
        // Initialize recipe manager
        recipeManager.Init();
        Print("[TestRecipeSystem] Recipe manager initialized");
        
        // Check if recipes were created
        int totalRecipes = 0;
        array<string> skillTypes = SkillTypes.GetAllTypes();
        
        foreach (string skillType : skillTypes)
        {
            array<ref SkillRecipeData> recipes = recipeManager.GetRecipesForSkill(skillType);
            if (recipes)
            {
                totalRecipes += recipes.Count();
                Print("[TestRecipeSystem] Skill type '" + skillType + "' has " + recipes.Count() + " recipes");
            }
            else
            {
                Print("[TestRecipeSystem] WARNING: Skill type '" + skillType + "' has no recipes");
            }
        }
        
        Print("[TestRecipeSystem] Total recipes created: " + totalRecipes);
        
        if (totalRecipes == 0)
        {
            Print("[TestRecipeSystem] ERROR: No recipes were created during initialization");
        }
    }
    
    // Test recipe loading for each skill type
    static void TestRecipeLoading()
    {
        Print("[TestRecipeSystem] Testing recipe loading for each skill type");
        
        // Create recipe manager
        ref SausageSkillsRecipeManager recipeManager = new SausageSkillsRecipeManager();
        recipeManager.Init();
        
        // Get all skill types
        array<string> skillTypes = SkillTypes.GetAllTypes();
        
        // Test each skill type
        foreach (string skillType : skillTypes)
        {
            Print("[TestRecipeSystem] Testing skill type: " + skillType);
            
            // Get recipes for this skill type
            array<ref SkillRecipeData> recipes = recipeManager.GetRecipesForSkill(skillType);
            
            if (recipes && recipes.Count() > 0)
            {
                Print("[TestRecipeSystem] Successfully loaded " + recipes.Count() + " recipes for skill type: " + skillType);
                
                // Log first recipe details
                if (recipes.Count() > 0)
                {
                    SkillRecipeData firstRecipe = recipes[0];
                    Print("[TestRecipeSystem]   - First recipe: " + firstRecipe.recipeName);
                    Print("[TestRecipeSystem]     Display name: " + firstRecipe.displayName);
                    Print("[TestRecipeSystem]     Skill type: " + firstRecipe.skillType);
                    Print("[TestRecipeSystem]     Required level: " + firstRecipe.requiredLevel);
                }
            }
            else
            {
                Print("[TestRecipeSystem] ERROR: No recipes found for skill type: " + skillType);
            }
            
            // Test case sensitivity
            string upperSkillType = ConvertToUpperCase(skillType);
            array<ref SkillRecipeData> upperRecipes = recipeManager.GetRecipesForSkill(upperSkillType);
            
            if (upperRecipes && upperRecipes.Count() > 0)
            {
                Print("[TestRecipeSystem] Case insensitive match works: " + upperSkillType + " has " + upperRecipes.Count() + " recipes");
            }
            else
            {
                Print("[TestRecipeSystem] Case sensitive match required: " + upperSkillType + " has no recipes");
            }
        }
    }
    
    // Test recipe data structure
    static void TestRecipeDataStructure()
    {
        Print("[TestRecipeSystem] Testing recipe data structure");
        
        // Create a test recipe
        ref SkillRecipeData testRecipe = new SkillRecipeData();
        testRecipe.recipeName = "TestRecipe";
        testRecipe.displayName = "Test Recipe";
        testRecipe.description = "A test recipe for debugging.";
        testRecipe.skillType = SkillTypes.ENGINEERING;
        testRecipe.requiredLevel = 1;
        testRecipe.ingredients.Insert(new Param2<string, int>("WoodenLog", 1));
        testRecipe.results.Insert(new Param2<string, int>("WoodenPlank", 4));
        testRecipe.craftingTime = 5.0;
        testRecipe.xpReward = 15;
        
        Print("[TestRecipeSystem] Test recipe created successfully");
        Print("[TestRecipeSystem]   - Recipe name: " + testRecipe.recipeName);
        Print("[TestRecipeSystem]   - Display name: " + testRecipe.displayName);
        Print("[TestRecipeSystem]   - Skill type: " + testRecipe.skillType);
        Print("[TestRecipeSystem]   - Required level: " + testRecipe.requiredLevel);
        Print("[TestRecipeSystem]   - Ingredients: " + testRecipe.ingredients.Count());
        Print("[TestRecipeSystem]   - Results: " + testRecipe.results.Count());
        
        // Test adding to recipe manager
        ref SausageSkillsRecipeManager recipeManager = new SausageSkillsRecipeManager();
        recipeManager.Init();
        
        // Get current count
        array<ref SkillRecipeData> beforeRecipes = recipeManager.GetRecipesForSkill(SkillTypes.ENGINEERING);
        int beforeCount = 0;
        if (beforeRecipes)
        {
            beforeCount = beforeRecipes.Count();
        }
        
        // Add test recipe (this is a hack, as we don't have direct access to the m_Recipes map)
        // Instead, we'll check if our recipe is found in the returned recipes
        
        // Get recipes again
        array<ref SkillRecipeData> afterRecipes = recipeManager.GetRecipesForSkill(SkillTypes.ENGINEERING);
        int afterCount = 0;
        if (afterRecipes)
        {
            afterCount = afterRecipes.Count();
        }
        
        Print("[TestRecipeSystem] Engineering recipes before: " + beforeCount + ", after: " + afterCount);
        
        // Check if any recipe has our test name
        bool foundTestRecipe = false;
        if (afterRecipes)
        {
            foreach (SkillRecipeData recipe : afterRecipes)
            {
                if (recipe.recipeName == "TestRecipe")
                {
                    foundTestRecipe = true;
                    break;
                }
            }
        }
        
        Print("[TestRecipeSystem] Found test recipe: " + foundTestRecipe);
    }
    
    // Test the SkillBookMenu with a specific skill type
    static void TestSkillBookMenu(string skillType)
    {
        Print("[TestRecipeSystem] Testing SkillBookMenu with skill type: " + skillType);
        
        // Create a new SkillBookMenu
        ref SkillBookMenu menu = new SkillBookMenu();
        
        // Initialize the menu
        menu.Init();
        
        // Set book data
        menu.SetBookData(skillType, "Test Skill Book", "This is a test skill book for " + skillType);
        
        // The menu should now load recipes for the specified skill type
        // We can't directly access the recipes, but we can check the log output
        Print("[TestRecipeSystem] SkillBookMenu test complete - check log for recipe loading results");
    }
}

// Helper function to run the test
void RunRecipeSystemTest()
{
    TestRecipeSystem.RunTest();
}

// Helper function to test the SkillBookMenu with a specific skill type
void TestSkillBookWithType(string skillType)
{
    TestRecipeSystem.TestSkillBookMenu(skillType);
}
