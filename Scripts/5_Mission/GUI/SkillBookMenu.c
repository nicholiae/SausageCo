/**
 * SausageCo Skills System
 * Skill Book Menu Controller
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
        m_Recipes = new array<ref SkillRecipeData>();
        m_RecipeManager = new SausageSkillsRecipeManager();
        m_RecipeManager.Init();
    }
    
    void ~SkillBookMenu()
    {
        // Clean up
        m_Recipes.Clear();
    }
    
    // Initialize the menu
    override Widget Init()
    {
        // Load the layout
        m_Root = GetGame().GetWorkspace().CreateWidgets("SausageCo/GUI/layouts/skillbook/skillbook_menu.layout");
        
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
        }
        
        // Set up event handlers
        if (m_CloseButton)
        {
            m_CloseButton.SetHandler(this);
        }
        
        return m_Root;
    }
    
    // Set the book data
    void SetBookData(string skillType, string bookTitle, string bookDescription)
    {
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
        // Clear existing recipes
        m_Recipes.Clear();
        
        // Get recipes for this skill type
        if (m_RecipeManager)
        {
            m_Recipes = m_RecipeManager.GetRecipesForSkill(m_SkillType);
        }
        
        // Update the UI
        UpdateRecipesGrid();
    }
    
    // Update the recipes grid
    void UpdateRecipesGrid()
    {
        // Clear the grid
        if (m_RecipesGrid)
        {
            m_RecipesGrid.ClearItems();
            
            // Add recipes to the grid
            foreach (SkillRecipeData recipe : m_Recipes)
            {
                // Create a recipe item widget
                Widget recipeWidget = GetGame().GetWorkspace().CreateWidgets("SausageCo/GUI/layouts/recipe_item.layout", m_RecipesGrid);
                if (recipeWidget)
                {
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
                        requiredLevel.SetText("Level " + recipe.requiredLevel);
                    }
                    
                    if (craftButton)
                    {
                        // Disable craft button in the book view
                        craftButton.Show(false);
                    }
                }
            }
        }
    }
    
    // Get display name for skill type
    string GetSkillTypeDisplayName(string skillType)
    {
        switch (skillType)
        {
            case SkillTypes.ENGINEERING:
                return "Engineering";
            case SkillTypes.FARMING:
                return "Farming";
            case SkillTypes.FIREARM:
                return "Firearm";
            case SkillTypes.LEATHER:
                return "Leatherworking";
            case SkillTypes.MECHANIC:
                return "Mechanic";
            case SkillTypes.MEDIC:
                return "Medical";
            case SkillTypes.HUNTER:
                return "Hunting";
            case SkillTypes.COOK:
                return "Cooking";
            default:
                return "Unknown";
        }
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
    
    // Open the menu
    void Open(string skillType, string bookTitle, string bookDescription)
    {
        // Set book data
        SetBookData(skillType, bookTitle, bookDescription);
        
        // Show the menu
        GetGame().GetUIManager().ShowScriptedMenu(this, NULL);
    }
    
    // Close the menu
    void Close()
    {
        GetGame().GetUIManager().Back();
    }
}