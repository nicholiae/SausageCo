
/**
\u2022 SausageCo Skills System
\u2022 Skill Book Menu Controller - Enhanced Version with Debug Logging
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
	private string m_SkillBookType; // NEW: Store the actual skill book type/class name

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
			Print("[SausageCo] ERROR: Failed to load skillbook_menu.layout, trying alternative path");
			m_Root = GetGame().GetWorkspace().CreateWidgets("SausageCo/GUI/layouts/skillbook_menu.layout");
			
			if (!m_Root)
			{
				Print("[SausageCo] CRITICAL ERROR: Failed to load skillbook_menu.layout from any path");
				return null;
			}
		}
		
		Print("[SausageCo] Successfully loaded skillbook_menu.layout");
		
		// Get widgets
		m_TitleText = TextWidget.Cast(m_Root.FindAnyWidget("TitleText"));
		if (!m_TitleText)
		{
			Print("[SausageCo] ERROR: Failed to find TitleText widget");
		}
		
		m_BookTypeText = TextWidget.Cast(m_Root.FindAnyWidget("BookTypeText"));
		if (!m_BookTypeText)
		{
			Print("[SausageCo] ERROR: Failed to find BookTypeText widget");
		}
		
		m_DescriptionText = TextWidget.Cast(m_Root.FindAnyWidget("DescriptionText"));
		if (!m_DescriptionText)
		{
			Print("[SausageCo] ERROR: Failed to find DescriptionText widget");
		}
		
		m_CloseButton = ButtonWidget.Cast(m_Root.FindAnyWidget("CloseButton"));
		if (!m_CloseButton)
		{
			Print("[SausageCo] ERROR: Failed to find CloseButton widget");
		}
		
		// Get the recipes grid
		ScrollWidget recipesScroll = ScrollWidget.Cast(m_Root.FindAnyWidget("RecipesScroll"));
		if (recipesScroll)
		{
			Print("[SausageCo] Found RecipesScroll widget");
			
			// Make sure the scroll widget is visible
			recipesScroll.Show(true);
			
			m_RecipesGrid = GridSpacerWidget.Cast(recipesScroll.FindAnyWidget("RecipesGrid"));
			if (!m_RecipesGrid)
			{
				Print("[SausageCo] ERROR: Failed to find RecipesGrid in skillbook_menu.layout");
			}
			else
			{
				Print("[SausageCo] Found RecipesGrid widget");
				
				// Make sure the grid is visible
				m_RecipesGrid.Show(true);
			}
		}
		else
		{
			Print("[SausageCo] ERROR: Failed to find RecipesScroll in skillbook_menu.layout");
		}
		
		return m_Root;
	}

	// Set the book data
	void SetBookData(string bookSkillType, string bookTitle, string bookDescription)
	{
		Print("[SausageCo] Setting book data: " + bookSkillType + ", " + bookTitle);
		
		// Store data
		m_SkillType = bookSkillType;
		m_BookTitle = bookTitle;
		m_BookDescription = bookDescription;
		m_SkillBookType = ""; // Clear the skill book type
		
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

	// NEW: Set the book data with the actual skill book type/class name
	void SetBookDataWithType(string bookSkillType, string bookTitle, string bookDescription, string skillBookType)
	{
		Print("[SausageCo] Setting book data with type: " + bookSkillType + ", " + bookTitle + ", book type: " + skillBookType);
		
		// Store the skill book type
		m_SkillBookType = skillBookType;
		
		// Call the original method to set other data
		SetBookData(bookSkillType, bookTitle, bookDescription);
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
		
		// UPDATED: Use the skill book type if available, otherwise fall back to skill type
		if (m_SkillBookType && m_SkillBookType != "")
		{
			Print("[SausageCo] Using skill book type for recipe lookup: " + m_SkillBookType);
			
			// Get recipes for this skill book type
			array<ref SkillRecipeData> bookRecipes = m_RecipeManager.GetRecipesForSkillBook(m_SkillBookType);
			if (bookRecipes && bookRecipes.Count() > 0)
			{
				// Debug dump the recipes
				DebugDumpRecipes(bookRecipes);
				
				// Copy recipes to our array
				foreach (SkillRecipeData bookRecipe : bookRecipes)
				{
					if (bookRecipe)
					{
						m_Recipes.Insert(bookRecipe);
					}
					else
					{
						Print("[SausageCo] WARNING: Null recipe found in bookRecipes");
					}
				}
				
				Print("[SausageCo] Loaded " + m_Recipes.Count() + " recipes for skill book type: " + m_SkillBookType);
			}
			else
			{
				Print("[SausageCo] No recipes found for skill book type: " + m_SkillBookType + ", falling back to skill type");
				
				// Fall back to skill type
				LoadRecipesBySkillType();
			}
		}
		else
		{
			// Fall back to skill type
			LoadRecipesBySkillType();
		}
		
		// Debug dump the final recipes
		Print("[SausageCo] Final recipes loaded:");
		DebugDumpRecipes(m_Recipes);
		
		// Create hardcoded recipes if none were found
		if (!m_Recipes || m_Recipes.Count() == 0)
		{
			Print("[SausageCo] No recipes found, creating hardcoded recipes");
			CreateHardcodedRecipes();
		}
		
		// Update the UI
		UpdateRecipesGrid();
	}

	// Create hardcoded recipes for testing
	private void CreateHardcodedRecipes()
	{
		// Create a few hardcoded recipes based on the skill type
		if (m_SkillType == SkillTypes.ENGINEERING)
		{
			// Workbench recipe
			ref SkillRecipeData workbenchRecipe = new SkillRecipeData();
			workbenchRecipe.recipeName = "createWorkbench";
			workbenchRecipe.displayName = "Workbench";
			workbenchRecipe.description = "Create a workbench for crafting items.";
			workbenchRecipe.skillType = SkillTypes.ENGINEERING;
			workbenchRecipe.requiredLevel = 1;
			workbenchRecipe.ingredients = new array<ref Param2<string, int>>();
			workbenchRecipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 15));
			workbenchRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_EngineersTool", 1));
			workbenchRecipe.results = new array<ref Param2<string, int>>();
			workbenchRecipe.results.Insert(new Param2<string, int>("SausageCo_Workbench", 1));
			workbenchRecipe.craftingTime = 25.0;
			workbenchRecipe.xpReward = 120;
			m_Recipes.Insert(workbenchRecipe);
			
			// Storage Crate recipe
			ref SkillRecipeData storageRecipe = new SkillRecipeData();
			storageRecipe.recipeName = "createStorageCrate";
			storageRecipe.displayName = "Storage Crate";
			storageRecipe.description = "Create a storage crate for storing items.";
			storageRecipe.skillType = SkillTypes.ENGINEERING;
			storageRecipe.requiredLevel = 1;
			storageRecipe.ingredients = new array<ref Param2<string, int>>();
			storageRecipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 10));
			storageRecipe.ingredients.Insert(new Param2<string, int>("Nail", 8));
			storageRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_EngineersTool", 1));
			storageRecipe.results = new array<ref Param2<string, int>>();
			storageRecipe.results.Insert(new Param2<string, int>("SausageCo_StorageCrate", 1));
			storageRecipe.craftingTime = 15.0;
			storageRecipe.xpReward = 80;
			m_Recipes.Insert(storageRecipe);
		}
		else if (m_SkillType == SkillTypes.FARMING)
		{
			// Garden Box recipe
			ref SkillRecipeData gardenBoxRecipe = new SkillRecipeData();
			gardenBoxRecipe.recipeName = "createGardenBox";
			gardenBoxRecipe.displayName = "Garden Box";
			gardenBoxRecipe.description = "Create a garden box for planting crops.";
			gardenBoxRecipe.skillType = SkillTypes.FARMING;
			gardenBoxRecipe.requiredLevel = 1;
			gardenBoxRecipe.ingredients = new array<ref Param2<string, int>>();
			gardenBoxRecipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 20));
			gardenBoxRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_FarmersToolT1", 1));
			gardenBoxRecipe.results = new array<ref Param2<string, int>>();
			gardenBoxRecipe.results.Insert(new Param2<string, int>("SausageCo_EmptyGardenBox", 1));
			gardenBoxRecipe.craftingTime = 10.0;
			gardenBoxRecipe.xpReward = 80;
			m_Recipes.Insert(gardenBoxRecipe);
			
			// Seeds Pack recipe
			ref SkillRecipeData seedsRecipe = new SkillRecipeData();
			seedsRecipe.recipeName = "createSeedsPack";
			seedsRecipe.displayName = "Seeds Pack";
			seedsRecipe.description = "Create a pack of seeds for planting.";
			seedsRecipe.skillType = SkillTypes.FARMING;
			seedsRecipe.requiredLevel = 1;
			seedsRecipe.ingredients = new array<ref Param2<string, int>>();
			seedsRecipe.ingredients.Insert(new Param2<string, int>("PlantMaterial", 5));
			seedsRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_FarmersToolT1", 1));
			seedsRecipe.results = new array<ref Param2<string, int>>();
			seedsRecipe.results.Insert(new Param2<string, int>("SausageCo_SeedsPack", 1));
			seedsRecipe.craftingTime = 5.0;
			seedsRecipe.xpReward = 25;
			m_Recipes.Insert(seedsRecipe);
		}
		// Add more hardcoded recipes for other skill types as needed
		
		Print("[SausageCo] Created " + m_Recipes.Count() + " hardcoded recipes");
	}

	// Helper method to load recipes by skill type (fallback method)
	private void LoadRecipesBySkillType()
	{
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
	}

	// Try to load recipes with normalized skill type case
	void TryNormalizedSkillType()
	{
		Print("[SausageCo] Trying to load recipes with normalized skill type case");
		
		// Get all skill types
		array<string> allSkillTypes = SkillTypes.GetAllTypes();
		
		// Find matching skill type (case insensitive)
		string normalizedType = "";
		foreach (string skillTypeEntry : allSkillTypes)
		{
			if (m_SkillType.ToLower() == skillTypeEntry.ToLower())
			{
				normalizedType = skillTypeEntry;
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
		
		// Declare variables at the beginning of the function
		Widget textWidget;
		Widget fallbackPanel;
		TextWidget fallbackText;
		
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
			
			// Create a text widget directly in the grid
			textWidget = GetGame().GetWorkspace().CreateWidgets("SausageCo/GUI/layouts/skillbook/text_widget.layout", m_RecipesGrid);
			if (textWidget)
			{
				TextWidget noRecipesText = TextWidget.Cast(textWidget.FindAnyWidget("MessageText"));
				if (noRecipesText)
				{
					noRecipesText.SetText("No recipes available for this skill type.");
					noRecipesText.SetColor(ARGB(255, 200, 200, 200));
					Print("[SausageCo] No recipes message created successfully");
				}
				else
				{
					Print("[SausageCo] ERROR: Could not find MessageText in text_widget.layout");
				}
			}
			else
			{
				Print("[SausageCo] ERROR: Failed to create text_widget.layout");
				
				// Fallback: Use a different approach to create a text message
				Print("[SausageCo] Using alternative method to display no recipes message");
				
				// Create a panel widget first
				fallbackPanel = GetGame().GetWorkspace().CreateWidget(FrameWidgetTypeID, 0, 0, 1, 0.1, WidgetFlags.VISIBLE | WidgetFlags.EXACTPOS, ARGB(255, 50, 50, 50), 0, m_RecipesGrid);
				if (fallbackPanel)
				{
					// Then create a text widget as a child of the panel
					fallbackText = TextWidget.Cast(GetGame().GetWorkspace().CreateWidget(TextWidgetTypeID, 0, 0, 1, 1, WidgetFlags.VISIBLE | WidgetFlags.EXACTPOS, ARGB(255, 200, 200, 200), 0, fallbackPanel));
					if (fallbackText)
					{
						fallbackText.SetText("No recipes available for this skill type.");
						Print("[SausageCo] Created fallback no recipes message");
					}
				}
			}
			return;
		}
		
		// Add recipes to the grid
		Print("[SausageCo] Adding " + m_Recipes.Count() + " recipes to grid");
		int recipeCount = 0;
		float width, height;
		foreach (SkillRecipeData recipe : m_Recipes)
		{
			if (!recipe)
			{
				Print("[SausageCo] ERROR: Null recipe in UpdateRecipesGrid");
				continue;
			}
			
			// Create a recipe item widget
			Print("[SausageCo] Creating recipe widget from layout: SausageCo/GUI/layouts/skillbook/recipe_item.layout");
			Widget recipeWidget = GetGame().GetWorkspace().CreateWidgets("SausageCo/GUI/layouts/skillbook/recipe_item.layout", m_RecipesGrid);
			
			// Make sure the recipe widget is visible
			if (recipeWidget)
			{
				recipeWidget.Show(true);
				recipeWidget.GetSize(width, height);
				Print("[SausageCo] Recipe widget created and set to visible - Size: " + width + "x" + height);
				
				// Set explicit size for the recipe widget
				recipeWidget.SetSize(1.0, 0.15);
			}
			else
			{
				Print("[SausageCo] ERROR: Failed to create recipe widget from layout");
			}
			if (!recipeWidget)
			{
				Print("[SausageCo] ERROR: Failed to create recipe_item.layout widget, trying fallback path");
				
				// Try alternative path
				Print("[SausageCo] Trying alternative path: SausageCo/GUI/layouts/recipe_item.layout");
				recipeWidget = GetGame().GetWorkspace().CreateWidgets("SausageCo/GUI/layouts/recipe_item.layout", m_RecipesGrid);
				
				if (recipeWidget)
				{
					recipeWidget.Show(true);
					Print("[SausageCo] Recipe widget created from alternative path and set to visible");
					
					// Set explicit size for the recipe widget
					recipeWidget.SetSize(1.0, 0.15);
				}
				
				if (!recipeWidget)
				{
					Print("[SausageCo] ERROR: Failed to create recipe widget with fallback path");
					
					// Create a simple text widget as fallback
					textWidget = GetGame().GetWorkspace().CreateWidgets("SausageCo/GUI/layouts/skillbook/text_widget.layout", m_RecipesGrid);
					if (textWidget)
					{
						TextWidget recipeText = TextWidget.Cast(textWidget.FindAnyWidget("MessageText"));
						if (recipeText)
						{
							recipeText.SetText(recipe.displayName + " - " + recipe.description);
							recipeText.SetColor(ARGB(255, 255, 255, 255));
							recipeCount++;
						}
					}
					else
					{
						// Use an alternative approach if layout file can't be loaded
						Print("[SausageCo] Using alternative method to display recipe");
						
						// Create a panel widget first
						fallbackPanel = GetGame().GetWorkspace().CreateWidget(FrameWidgetTypeID, 0, 0, 1, 0.15, WidgetFlags.VISIBLE | WidgetFlags.EXACTPOS, ARGB(255, 50, 50, 50), 0, m_RecipesGrid);
						if (fallbackPanel)
						{
							// Then create a text widget as a child of the panel
							fallbackText = TextWidget.Cast(GetGame().GetWorkspace().CreateWidget(TextWidgetTypeID, 0.02, 0.1, 0.96, 0.8, WidgetFlags.VISIBLE | WidgetFlags.EXACTPOS, ARGB(255, 255, 255, 255), 0, fallbackPanel));
							if (fallbackText)
							{
								fallbackText.SetText(recipe.displayName + " - " + recipe.description);
								Print("[SausageCo] Created fallback recipe display");
								recipeCount++;
							}
						}
					}
					continue;
				}
			}
			
			// Set recipe data
			TextWidget recipeName = TextWidget.Cast(recipeWidget.FindAnyWidget("RecipeName"));
			TextWidget recipeDescription = TextWidget.Cast(recipeWidget.FindAnyWidget("RecipeDescription"));
			TextWidget requiredLevel = TextWidget.Cast(recipeWidget.FindAnyWidget("RequiredLevel"));
			ButtonWidget craftButton = ButtonWidget.Cast(recipeWidget.FindAnyWidget("CraftButton"));
			
			// Debug log the widget references
			Print("[SausageCo] Recipe widget components - Name: " + recipeName + ", Description: " + recipeDescription + ", Level: " + requiredLevel + ", Button: " + craftButton);
			
			if (recipeName)
			{
				recipeName.SetText(recipe.displayName);
				Print("[SausageCo] Set recipe name: " + recipe.displayName);
			}
			else
			{
				Print("[SausageCo] ERROR: RecipeName widget not found");
			}
			
			if (recipeDescription)
			{
				recipeDescription.SetText(recipe.description);
				Print("[SausageCo] Set recipe description: " + recipe.description);
			}
			else
			{
				Print("[SausageCo] ERROR: RecipeDescription widget not found");
			}
			
			if (requiredLevel)
			{
				requiredLevel.SetText("Level " + recipe.requiredLevel.ToString());
				Print("[SausageCo] Set required level: " + recipe.requiredLevel.ToString());
			}
			else
			{
				Print("[SausageCo] ERROR: RequiredLevel widget not found");
			}
			
			if (craftButton)
			{
				// Disable craft button in the book view
				craftButton.Show(false);
				Print("[SausageCo] Disabled craft button");
			}
			else
			{
				Print("[SausageCo] ERROR: CraftButton widget not found");
			}
			
			recipeCount++;
		}
		
		Print("[SausageCo] Successfully added " + recipeCount + " recipes to grid");
		
		// Force layout update
		m_RecipesGrid.Update();
		
		// Make sure the grid is visible
		m_RecipesGrid.Show(true);
		
		// Set the grid size explicitly
		m_RecipesGrid.SetSize(1.0, 1.0);
		
		// Debug log the grid properties
		m_RecipesGrid.GetSize(width, height);
		Print("[SausageCo] Grid properties - Visible: " + m_RecipesGrid.IsVisible() + ", Size: " + width + "x" + height);
	}

	// Get display name for skill type
	string GetSkillTypeDisplayName(string displaySkillType)
	{
		string displayName = "Unknown";
		
		switch (displaySkillType)
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
		array<string> allSkillTypes = SkillTypes.GetAllTypes();
		
		foreach (string skillTypeItem1 : allSkillTypes)
		{
			array<ref SkillRecipeData> recipes = m_RecipeManager.GetRecipesForSkill(skillTypeItem1);
			if (recipes)
			{
				recipeCount += recipes.Count();
				
				// Debug: Print details of first recipe for each skill type
				if (recipes.Count() > 0)
				{
					SkillRecipeData firstRecipe = recipes[0];
					Print("[SausageCo] Sample recipe for " + skillTypeItem1 + ":");
					Print("[SausageCo]   - Name: " + firstRecipe.recipeName);
					Print("[SausageCo]   - Display Name: " + firstRecipe.displayName);
					Print("[SausageCo]   - Description: " + firstRecipe.description);
					Print("[SausageCo]   - Required Level: " + firstRecipe.requiredLevel);
					Print("[SausageCo]   - Ingredients: " + firstRecipe.ingredients.Count());
					Print("[SausageCo]   - Results: " + firstRecipe.results.Count());
				}
			}
		}
		
		Print("[SausageCo] Recipe manager has " + recipeCount + " total recipes");
		
		if (recipeCount == 0)
		{
			Print("[SausageCo] WARNING: Recipe manager has no recipes, reinitializing...");
			m_RecipeManager.Init();
			
			// Check again
			recipeCount = 0;
			foreach (string skillTypeItem2 : allSkillTypes)
			{
				array<ref SkillRecipeData> recipes2 = m_RecipeManager.GetRecipesForSkill(skillTypeItem2);
				if (recipes2)
				{
					recipeCount += recipes2.Count();
				}
			}
			
			Print("[SausageCo] After reinitialization, recipe manager has " + recipeCount + " total recipes");
		}
	}

	// Debug function to dump recipe data
	private void DebugDumpRecipes(array<ref SkillRecipeData> recipes)
	{
		if (!recipes || recipes.Count() == 0)
		{
			Print("[SausageCo] DEBUG: No recipes to dump");
			return;
		}
		
		Print("[SausageCo] DEBUG: Dumping " + recipes.Count() + " recipes:");
		
		int index = 0;
		foreach (SkillRecipeData recipe : recipes)
		{
			if (!recipe)
			{
				Print("[SausageCo] DEBUG: Recipe at index " + index + " is null");
				continue;
			}
			
			Print("[SausageCo] DEBUG: Recipe " + index + ":");
			Print("[SausageCo] DEBUG:   - Name: " + recipe.recipeName);
			Print("[SausageCo] DEBUG:   - Display Name: " + recipe.displayName);
			Print("[SausageCo] DEBUG:   - Description: " + recipe.description);
			Print("[SausageCo] DEBUG:   - Skill Type: " + recipe.skillType);
			Print("[SausageCo] DEBUG:   - Required Level: " + recipe.requiredLevel);
			
			// Print ingredients
			Print("[SausageCo] DEBUG:   - Ingredients (" + recipe.ingredients.Count() + "):");
			for (int i = 0; i < recipe.ingredients.Count(); i++)
			{
				Param2<string, int> ingredient = recipe.ingredients[i];
				if (ingredient)
				{
					Print("[SausageCo] DEBUG:     * " + ingredient.param1 + " x" + ingredient.param2);
				}
				else
				{
					Print("[SausageCo] DEBUG:     * Null ingredient at index " + i);
				}
			}
			
			// Print results
			Print("[SausageCo] DEBUG:   - Results (" + recipe.results.Count() + "):");
			for (int j = 0; j < recipe.results.Count(); j++)
			{
				Param2<string, int> result = recipe.results[j];
				if (result)
				{
					Print("[SausageCo] DEBUG:     * " + result.param1 + " x" + result.param2);
				}
				else
				{
					Print("[SausageCo] DEBUG:     * Null result at index " + j);
				}
			}
			
			index++;
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
