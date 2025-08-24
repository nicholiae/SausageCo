
/**
 * SausageCo Skills System
 * Skill Book Menu Controller - Enhanced Version with Debug Logging
 */

class SkillBookMenu extends UIScriptedMenu
{
    // Layout widgets
    private Widget m_Root;
    private TextWidget m_TitleText;
    private TextWidget m_BookTypeText;
    private TextWidget m_DescriptionText;
    private ButtonWidget m_CloseButton;
    private GridSpacerWidget m_RecipesGrid;
    
    // Data
    private string m_SkillType;
    private string m_BookTitle;
    private string m_BookDescription;
    private ref array<ref SkillRecipeData> m_Recipes;
    
    // Recipe manager
    private ref SausageSkillsRecipeManager m_RecipeManager;
    
    // Static flag to track if notifications should be suppressed
    private static bool m_NotificationsSuppressed = false;
    
    // Debug helper
    private ref RecipeSystemDebugger m_Debugger;
    
    void SkillBookMenu()
    {
        Print("[SausageCo] SkillBookMenu constructor called");
        m_Recipes = new array<ref SkillRecipeData>();
        
        // Create recipe manager - IMPORTANT: This must be created here to ensure it's available
        m_RecipeManager = new SausageSkillsRecipeManager();
        if (m_RecipeManager)
        {
            Print("[SausageCo] Recipe manager created, initializing...");
            m_RecipeManager.Init();
            Print("[SausageCo] Recipe manager initialized");
            
            // Verify recipe manager has data
            VerifyRecipeManagerData();
        }
        else
        {
            Print("[SausageCo] ERROR: Failed to create recipe manager");
        }
        
        // Create debugger
        m_Debugger = RecipeSystemDebugger.GetInstance();
    }
    
    void ~SkillBookMenu()
    {
        // Clean up
        if (m_Recipes)
        {
            m_Recipes.Clear();
        }
    }
    
    // Initialize the menu
    override Widget Init()
    {
        // Load the layout
        m_Root = GetGame().GetWorkspace().CreateWidgets("SausageCo/GUI/layouts/skillbook/skillbook_menu.layout");
        if (!m_Root)
        {
            Print("[SausageCo] ERROR: Failed to load skillbook_menu.layout");
            return null;
        }
        
        // Get widgets
        m_TitleText = TextWidget.Cast(m_Root.FindAnyWidget("TitleText"));
        m_BookTypeText = TextWidget.Cast(m_Root.FindAnyWidget("BookTypeText"));
        m_DescriptionText = TextWidget.Cast(m_Root.FindAnyWidget("DescriptionText"));
        m_CloseButton = ButtonWidget.Cast(m_Root.FindAnyWidget("CloseButton"));
        
        // Get the recipes grid
        ScrollWidget recipesScroll = ScrollWidget.Cast(m_Root.FindAnyWidget("RecipesScroll"));
        if (recipesScroll)
        {
            m_RecipesGrid = GridSpacerWidget.Cast(recipesScroll.FindAnyWidget("RecipesGrid"));
            if (!m_RecipesGrid)
            {
                Print("[SausageCo] ERROR: Failed to find RecipesGrid in skillbook_menu.layout");
            }
        }
        else
        {
            Print("[SausageCo] ERROR: Failed to find RecipesScroll in skillbook_menu.layout");
        }
        
        return m_Root;
    }
    
    // Set the book data
    void SetBookData(string skillType, string bookTitle, string bookDescription)
    {
        Print("[SausageCo] Setting book data: " + skillType + ", " + bookTitle);
        
        // Store data
        m_SkillType = skillType;
        m_BookTitle = bookTitle;
        m_BookDescription = bookDescription;
        
        // Update UI
        if (m_TitleText)
        {
            m_TitleText.SetText(m_BookTitle);
        }
        
        if (m_BookTypeText)
        {
            m_BookTypeText.SetText("Book Type: " + GetSkillTypeDisplayName(m_SkillType));
        }
        
        if (m_DescriptionText)
        {
            m_DescriptionText.SetText(m_BookDescription);
        }
        
        // Debug: Check skill type string
        if (m_Debugger)
        {
            m_Debugger.CheckSkillTypeStrings(m_SkillType);
        }
        
        // Load recipes for this skill type
        LoadRecipes();
    }
    
    // Load recipes for the current skill type
    void LoadRecipes()
    {
        Print("[SausageCo] Loading recipes for skill type: " + m_SkillType);
        
        // Clear existing recipes
        if (m_Recipes)
        {
            m_Recipes.Clear();
        }
        else
        {
            m_Recipes = new array<ref SkillRecipeData>();
        }
        
        // Verify recipe manager is initialized
        if (!m_RecipeManager)
        {
            Print("[SausageCo] ERROR: Recipe manager is null, recreating...");
            m_RecipeManager = new SausageSkillsRecipeManager();
            if (m_RecipeManager)
            {
                m_RecipeManager.Init();
                Print("[SausageCo] Recipe manager recreated and initialized");
            }
            else
            {
                Print("[SausageCo] CRITICAL ERROR: Failed to recreate recipe manager");
                // Try to get recipe manager from plugin
                m_RecipeManager = GetRecipeManagerFromPlugin();
                if (!m_RecipeManager)
                {
                    Print("[SausageCo] CRITICAL ERROR: Could not get recipe manager from plugin");
                    // Show error notification
                    SausageNotification.Show("Error loading recipes. Please restart the game.", SausageNotification.TYPE_ERROR);
                    return;
                }
            }
        }
        
        // Get recipes for this skill type
        array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(m_SkillType);
        if (recipes && recipes.Count() > 0)
        {
            // Copy recipes to our array
            foreach (SkillRecipeData recipe : recipes)
            {
                m_Recipes.Insert(recipe);
            }
            
            Print("[SausageCo] Loaded " + m_Recipes.Count() + " recipes for skill type: " + m_SkillType);
        }
        else
        {
            Print("[SausageCo] No recipes found for skill type: " + m_SkillType);
            
            // Debug: Test recipe loading with debugger
            if (m_Debugger)
            {
                m_Debugger.TestRecipeLoading(m_SkillType);
            }
            
            // Try to normalize skill type case
            TryNormalizedSkillType();
        }
        
        // Update the UI
        UpdateRecipesGrid();
    }
    
    // Try to load recipes with normalized skill type case
    void TryNormalizedSkillType()
    {
        Print("[SausageCo] Trying to load recipes with normalized skill type case");
        
        // Get all skill types
        array<string> skillTypes = SkillTypes.GetAllTypes();
        
        // Find matching skill type (case insensitive)
        string normalizedType = "";
        foreach (string type : skillTypes)
        {
            if (m_SkillType.ToLower() == type.ToLower())
            {
                normalizedType = type;
                break;
            }
        }
        
        // If found, try loading with normalized type
        if (normalizedType != "" && normalizedType != m_SkillType)
        {
            Print("[SausageCo] Found normalized skill type: " + normalizedType);
            
            // Get recipes for normalized skill type
            array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(normalizedType);
            if (recipes && recipes.Count() > 0)
            {
                // Copy recipes to our array
                foreach (SkillRecipeData recipe : recipes)
                {
                    m_Recipes.Insert(recipe);
                }
                
                Print("[SausageCo] Loaded " + m_Recipes.Count() + " recipes using normalized skill type");
            }
        }
    }
    
    // Update the recipes grid
    void UpdateRecipesGrid()
    {
        Print("[SausageCo] Updating recipes grid");
        
        // Check if grid exists
        if (!m_RecipesGrid)
        {
            Print("[SausageCo] ERROR: RecipesGrid is null in UpdateRecipesGrid");
            return;
        }
        
        // Clear the grid
        Widget child = m_RecipesGrid.GetChildren();
        while (child)
        {
            Widget nextChild = child.GetSibling();
            child.Unlink();
            child = nextChild;
        }
        
        // Check if we have recipes
        if (!m_Recipes || m_Recipes.Count() == 0)
        {
            Print("[SausageCo] No recipes to display, creating no recipes message");
            
            // Create a simple text widget directly
            TextWidget noRecipesText = TextWidget.Cast(GetGame().GetWorkspace().CreateWidgets("SausageCo/GUI/layouts/text_widget.layout", m_RecipesGrid));
            if (noRecipesText)
            {
                noRecipesText.SetText("No recipes available for this skill type.");
                noRecipesText.SetColor(ARGB(255, 200, 200, 200));
                Print("[SausageCo] No recipes message created successfully");
            }
            else
            {
                Print("[SausageCo] ERROR: Failed to create no recipes message");
            }
            return;
        }
        
        // Add recipes to the grid
        Print("[SausageCo] Adding " + m_Recipes.Count() + " recipes to grid");
        int recipeCount = 0;
        
        foreach (SkillRecipeData recipe : m_Recipes)
        {
            if (!recipe)
            {
                Print("[SausageCo] ERROR: Null recipe in UpdateRecipesGrid");
                continue;
            }
            
            // Create a recipe item widget
            Widget recipeWidget = GetGame().GetWorkspace().CreateWidgets("SausageCo/GUI/layouts/recipe_item.layout", m_RecipesGrid);
            if (!recipeWidget)
            {
                Print("[SausageCo] ERROR: Failed to create recipe_item.layout widget");
                continue;
            }
            
            // Set recipe data
            TextWidget recipeName = TextWidget.Cast(recipeWidget.FindAnyWidget("RecipeName"));
            TextWidget recipeDescription = TextWidget.Cast(recipeWidget.FindAnyWidget("RecipeDescription"));
            TextWidget requiredLevel = TextWidget.Cast(recipeWidget.FindAnyWidget("RequiredLevel"));
            ButtonWidget craftButton = ButtonWidget.Cast(recipeWidget.FindAnyWidget("CraftButton"));
            
            if (recipeName)
            {
                recipeName.SetText(recipe.displayName);
            }
            
            if (recipeDescription)
            {
                recipeDescription.SetText(recipe.description);
            }
            
            if (requiredLevel)
            {
                requiredLevel.SetText("Level " + recipe.requiredLevel.ToString());
            }
            
            if (craftButton)
            {
                // Disable craft button in the book view
                craftButton.Show(false);
            }
            
            recipeCount++;
        }
        
        Print("[SausageCo] Successfully added " + recipeCount + " recipes to grid");
    }
    
    // Get display name for skill type
    string GetSkillTypeDisplayName(string skillType)
    {
        string displayName = "Unknown";
        
        switch (skillType)
        {
            case SkillTypes.ENGINEERING:
                displayName = "Engineering";
                break;
            case SkillTypes.FARMING:
                displayName = "Farming";
                break;
            case SkillTypes.FIREARM:
                displayName = "Firearm";
                break;
            case SkillTypes.LEATHER:
                displayName = "Leatherworking";
                break;
            case SkillTypes.MECHANIC:
                displayName = "Mechanic";
                break;
            case SkillTypes.MEDIC:
                displayName = "Medical";
                break;
            case SkillTypes.HUNTER:
                displayName = "Hunting";
                break;
            case SkillTypes.COOK:
                displayName = "Cooking";
                break;
            default:
                displayName = "Unknown";
                break;
        }
        
        return displayName;
    }
    
    // Handle button clicks
    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w == m_CloseButton)
        {
            Close();
            return true;
        }
        
        return false;
    }
    
    // Handle key presses
    override bool OnKeyPress(Widget w, int x, int y, int key)
    {
        // Close on ESC
        if (key == KeyCode.KC_ESCAPE)
        {
            Close();
            return true;
        }
        
        return false;
    }
    
    // Override OnShow to handle any setup needed when the menu is shown
    override void OnShow()
    {
        super.OnShow();
        Print("[SausageCo] SkillBookMenu OnShow called");
        
        // Set the static flag to suppress notifications
        m_NotificationsSuppressed = true;
        
        // Show a notification using our new system to inform the player
        // We use SausageNotification.Show directly to bypass the suppression check
        SausageNotification.Show("Skill Book opened. Regular notifications will be suppressed.", SausageNotification.TYPE_INFO, 3.0);
    }
    
    // Override OnHide to handle any cleanup needed when the menu is hidden
    override void OnHide()
    {
        super.OnHide();
        Print("[SausageCo] SkillBookMenu OnHide called");
        
        // Clear the static flag to allow notifications again
        m_NotificationsSuppressed = false;
        
        // Show a notification using our new system to inform the player
        SausageNotification.Show("Skill Book closed. Regular notifications restored.", SausageNotification.TYPE_INFO, 3.0);
    }
    
    // Static method to check if notifications are currently suppressed
    static bool AreNotificationsSuppressed()
    {
        return m_NotificationsSuppressed;
    }
    
    // Verify recipe manager has data
    private void VerifyRecipeManagerData()
    {
        if (!m_RecipeManager)
            return;
            
        // Check if recipe manager has recipes
        int recipeCount = 0;
        array<string> skillTypes = SkillTypes.GetAllTypes();
        
        foreach (string skillType : skillTypes)
        {
            array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(skillType);
            if (recipes)
            {
                recipeCount += recipes.Count();
            }
        }
        
        Print("[SausageCo] Recipe manager has " + recipeCount + " total recipes");
        
        if (recipeCount == 0)
        {
            Print("[SausageCo] WARNING: Recipe manager has no recipes, reinitializing...");
            m_RecipeManager.Init();
            
            // Check again
            recipeCount = 0;
            foreach (string skillType : skillTypes)
            {
                array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(skillType);
                if (recipes)
                {
                    recipeCount += recipes.Count();
                }
            }
            
            Print("[SausageCo] After reinitialization, recipe manager has " + recipeCount + " total recipes");
        }
    }
    
    // Try to get recipe manager from plugin
    private SausageSkillsRecipeManager GetRecipeManagerFromPlugin()
    {
        Print("[SausageCo] Attempting to get recipe manager from plugin");
        
        // Try to get the skills manager plugin
        PluginSausageSkillsManager skillsManager = PluginSausageSkillsManager.Cast(GetPlugin(PluginSausageSkillsManager));
        if (skillsManager)
        {
            Print("[SausageCo] Found skills manager plugin");
            
            // Access the recipe manager through reflection (this is a hack, but might work)
            // Note: This assumes the recipe manager is stored in a field called m_RecipeManager
            // This is just for debugging purposes
            
            // For now, just create a new one
            SausageSkillsRecipeManager recipeManager = new SausageSkillsRecipeManager();
            recipeManager.Init();
            
            return recipeManager;
        }
        
        Print("[SausageCo] Could not find skills manager plugin");
        return null;
    }
}
