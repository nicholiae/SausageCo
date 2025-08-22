/**
 * SausageCo Skills System
 * Skills Menu
 */

// Define the SkillRecipeData class that was missing
// class SkillRecipeData
// {
    // string displayName;
    // string description;
    // string skillType;
    // int requiredLevel;
    // string recipeName;
    // string recipeClassName;
    
    // void SkillRecipeData()
    // {
        // displayName = "Unknown Recipe";
        // description = "No description available";
        // skillType = "";
        // requiredLevel = 0;
        // recipeName = "";
        // recipeClassName = "";
    // }
// }

class SausageSkillsMenu extends UIScriptedMenu
{
    // UI Controls
    private Widget m_Root;
    private TabberUI m_Tabber;
    private TextWidget m_PlayerNameText;
    private ButtonWidget m_CloseButton;
    
    // Skill panels
    private ref map<string, ref SkillPanel> m_SkillPanels;
    
    // Current skill data
    private ref map<string, ref Param2<int, int>> m_SkillsData; // skillType -> (level, xp)
    
    // Config reference
    private ref PluginSausageSkillsConfig m_Config;
    
    override Widget Init()
    {
        m_Root = GetGame().GetWorkspace().CreateWidgets("SausageCo\\GUI\\layouts\\skills_menu.layout");
        
        // Get UI elements
        m_Tabber = TabberUI.Cast(m_Root.FindAnyWidget("SkillsTabber"));
        m_PlayerNameText = TextWidget.Cast(m_Root.FindAnyWidget("PlayerNameText"));
        m_CloseButton = ButtonWidget.Cast(m_Root.FindAnyWidget("CloseButton"));
        
        // Initialize skill panels
        m_SkillPanels = new map<string, ref SkillPanel>();
        
        // Get config
        m_Config = PluginSausageSkillsConfig.Cast(GetPlugin(PluginSausageSkillsConfig));
        
        // Initialize skill data
        m_SkillsData = new map<string, ref Param2<int, int>>();
        
        // Create tabs for each skill type
        array<string> skillTypes = SkillTypes.GetAllTypes();
        foreach (string skillType : skillTypes)
        {
            // Create skill panel
            ref SkillPanel panel = new SkillPanel(m_Root.FindAnyWidget("SkillContent"), skillType);
            m_SkillPanels.Set(skillType, panel);
            
            // Add tab
            m_Tabber.AddTab(m_Config.GetSkillDisplayName(skillType), panel.GetRootWidget());
            
            // Initialize skill data
            m_SkillsData.Set(skillType, new Param2<int, int>(0, 0));
        }
        
        // Set player name
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && player.GetIdentity())
        {
            m_PlayerNameText.SetText("Player: " + player.GetIdentity().GetName());
        }
        
        // Request skill data from server
        GetRPCManager().SendRPC("SausageSkills", "RequestSkillsData", null, true);
        
        return m_Root;
    }
    
    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w == m_CloseButton)
        {
            Close();
            return true;
        }
        
        // Check if click was in a skill panel
        foreach (string skillType, ref SkillPanel panel : m_SkillPanels)
        {
            if (panel.OnClick(w, x, y, button))
            {
                return true;
            }
        }
        
        return super.OnClick(w, x, y, button);
    }
    
    void UpdateSkillData(string skillType, int level, int experience)
    {
        // Update local data
        m_SkillsData.Set(skillType, new Param2<int, int>(level, experience));
        
        // Update UI
        if (m_SkillPanels.Contains(skillType))
        {
            ref SkillPanel panel = m_SkillPanels.Get(skillType);
            panel.UpdateSkill(level, experience, m_Config.GetXpForLevel(skillType, level + 1));
        }
    }
    
    void UpdateAllSkills(ref array<ref Param3<string, int, int>> skillsData)
    {
        foreach (ref Param3<string, int, int> data : skillsData)
        {
            UpdateSkillData(data.param1, data.param2, data.param3);
        }
    }
    
    override void OnHide()
    {
        super.OnHide();
        
        // Clean up
        m_SkillPanels.Clear();
        m_SkillsData.Clear();
    }
}

// Skill panel class for individual skill display
class SkillPanel
{
    private Widget m_Root;
    private TextWidget m_LevelText;
    private ProgressBarWidget m_XpBar;
    private TextWidget m_XpText;
    private GridSpacerWidget m_RecipesGrid;
    private TextWidget m_DescriptionText;
    
    private string m_SkillType;
    
    // Recipe items
    private ref array<ref RecipeListItem> m_RecipeItems;
    
    void SkillPanel(Widget parent, string skillType)
    {
        m_SkillType = skillType;
        
        // Create panel from layout
        m_Root = GetGame().GetWorkspace().CreateWidgets("SausageCo\\GUI\\layouts\\skill_panel.layout", parent);
        
        // Get UI elements
        m_LevelText = TextWidget.Cast(m_Root.FindAnyWidget("LevelText"));
        m_XpBar = ProgressBarWidget.Cast(m_Root.FindAnyWidget("XpBar"));
        m_XpText = TextWidget.Cast(m_Root.FindAnyWidget("XpText"));
        m_RecipesGrid = GridSpacerWidget.Cast(m_Root.FindAnyWidget("RecipesGrid"));
        m_DescriptionText = TextWidget.Cast(m_Root.FindAnyWidget("DescriptionText"));
        
        // Initialize recipe items array
        m_RecipeItems = new array<ref RecipeListItem>();
        
        // Set description
        PluginSausageSkillsConfig config = PluginSausageSkillsConfig.Cast(GetPlugin(PluginSausageSkillsConfig));
        m_DescriptionText.SetText(config.GetSkillDescription(skillType));
        
        // Initialize with default values
        UpdateSkill(0, 0, 1000);
    }
    
    Widget GetRootWidget()
    {
        return m_Root;
    }
    
    void UpdateSkill(int level, int experience, int nextLevelAt)
    {
        // Update level text
        m_LevelText.SetText("Level " + level.ToString());
        
        // Update XP bar
        float progress = 0;
        if (nextLevelAt > 0)
        {
            progress = Math.Clamp(experience / (float)nextLevelAt, 0, 1);
        }
        m_XpBar.SetCurrent(progress * 100);
        
        // Update XP text
        m_XpText.SetText(experience.ToString() + " / " + nextLevelAt.ToString() + " XP");
        
        // Update recipes
        UpdateRecipes(level);
    }
    
    void UpdateRecipes(int level)
    {
        // Clear existing recipe items
        foreach (RecipeListItem item : m_RecipeItems)
        {
            delete item;
        }
        m_RecipeItems.Clear();
        
        // Get recipes for this skill type
        SausageSkillsRecipeManager recipeManager = new SausageSkillsRecipeManager();
        recipeManager.Init();
        array<ref SkillRecipeData> recipes = recipeManager.GetRecipesForSkill(m_SkillType);
        
        // Sort recipes by required level
        recipes.Sort(RecipeLevelSorter);
        
        // Add recipe widgets
        foreach (SkillRecipeData recipe : recipes)
        {
            // Create recipe item
            RecipeListItem recipeItem = new RecipeListItem(m_RecipesGrid, recipe, level >= recipe.requiredLevel);
            m_RecipeItems.Insert(recipeItem);
        }
    }
    
    bool OnClick(Widget w, int x, int y, int button)
    {
        // Check if click was in a recipe item
        foreach (RecipeListItem item : m_RecipeItems)
        {
            if (item.OnClick(w, x, y, button))
            {
                return true;
            }
        }
        
        return false;
    }
    
    // Recipe sorting function
    static int RecipeLevelSorter(SkillRecipeData recipe1, SkillRecipeData recipe2)
    {
        if (recipe1.requiredLevel < recipe2.requiredLevel)
            return -1;
        else if (recipe1.requiredLevel > recipe2.requiredLevel)
            return 1;
        else
            return 0;
    }
}

// Recipe list item for displaying individual recipes
class RecipeListItem
{
    private Widget m_Root;
    private TextWidget m_RecipeName;
    private TextWidget m_RecipeDescription;
    private TextWidget m_RequiredLevel;
    private ButtonWidget m_CraftButton;
    
    private ref SkillRecipeData m_Recipe;
    private bool m_Unlocked;
    
    void RecipeListItem(Widget parent, SkillRecipeData recipe, bool unlocked)
    {
        m_Recipe = recipe;
        m_Unlocked = unlocked;
        
        // Create widget from layout
        m_Root = GetGame().GetWorkspace().CreateWidgets("SausageCo\\GUI\\layouts\\recipe_item.layout", parent);
        
        // Get UI elements
        m_RecipeName = TextWidget.Cast(m_Root.FindAnyWidget("RecipeName"));
        m_RecipeDescription = TextWidget.Cast(m_Root.FindAnyWidget("RecipeDescription"));
        m_RequiredLevel = TextWidget.Cast(m_Root.FindAnyWidget("RequiredLevel"));
        m_CraftButton = ButtonWidget.Cast(m_Root.FindAnyWidget("CraftButton"));
        
        // Set recipe data
        m_RecipeName.SetText(recipe.displayName);
        m_RecipeDescription.SetText(recipe.description);
        m_RequiredLevel.SetText("Level " + recipe.requiredLevel.ToString());
        
        // Set button state based on unlock status
        if (unlocked)
        {
            m_CraftButton.SetText("Craft");
            m_CraftButton.Enable(true);
            m_Root.SetColor(ARGB(255, 255, 255, 255)); // White for unlocked
        }
        else
        {
            m_CraftButton.SetText("Locked");
            m_CraftButton.Enable(false);
            m_Root.SetColor(ARGB(255, 150, 150, 150)); // Gray for locked
        }
    }
    
    bool OnClick(Widget w, int x, int y, int button)
    {
        if (w == m_CraftButton && m_Unlocked)
        {
            // Send craft request to server
            GetRPCManager().SendRPC("SausageSkills", "CraftRecipe", new Param2<string, string>(m_Recipe.skillType, m_Recipe.recipeName), true);
            return true;
        }
        
        return false;
    }
}