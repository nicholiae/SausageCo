
/**
 * SausageCo Skills System
 * Skill Book Menu Controller - Fixed Version
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
    
    void SkillBookMenu()
    {
        Print("[SausageCo] SkillBookMenu constructor called");
        m_Recipes = new array<ref SkillRecipeData>();
        m_RecipeManager = new SausageSkillsRecipeManager();
        if (m_RecipeManager)
        {
            Print("[SausageCo] Recipe manager created, initializing...");
            m_RecipeManager.Init();
            Print("[SausageCo] Recipe manager initialized");
        }
        else
        {
            Print("[SausageCo] ERROR: Failed to create recipe manager");
        }
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
        
        // Get recipes for this skill type
        if (m_RecipeManager)
        {
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
            }
        }
        else
        {
            Print("[SausageCo] ERROR: Recipe manager is null in LoadRecipes");
        }
        
        // Update the UI
        UpdateRecipesGrid();
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
            // FIX: Corrected layout path from "ecipe_item.layout" to "recipe_item.layout"
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
        
        // Disable notifications while this menu is open
        // This is handled by our modded NotificationSystem class
    }
    
    // Override OnHide to handle any cleanup needed when the menu is hidden
    override void OnHide()
    {
        super.OnHide();
        Print("[SausageCo] SkillBookMenu OnHide called");
        
        // Notifications will automatically be re-enabled when this menu closes
        // This is handled by our modded NotificationSystem class
    }
}
