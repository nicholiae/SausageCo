/**
 * SausageCo Skills System
 * Recipe Scanner - Scans recipe files in the directory
 */

class RecipeScanner
{
    // Debug flag
    private bool m_Debug = true;
    
    // Recipe directory path
    private const string RECIPE_DIR_PATH = "$profile:SausageCo/Scripts/4_World/Recipes";
    
    // Constructor
    void RecipeScanner()
    {
        DebugLog("RecipeScanner initialized");
    }
    
    /**
     * Scan recipe files for a specific skill book type
     * @param skillBookType The skill book type to scan for (e.g., "SausageCo_FarmersToolT1")
     * @return Array of SkillRecipeData objects for the skill book
     */
    array<ref SkillRecipeData> ScanRecipesForSkillBook(string skillBookType)
    {
        DebugLog("Scanning recipes for skill book: " + skillBookType);
        
        // Create array to store recipe data
        array<ref SkillRecipeData> recipes = new array<ref SkillRecipeData>();
        
        // Get skill type from skill book type
        string skillType = GetSkillTypeFromBookType(skillBookType);
        if (skillType == "")
        {
            DebugLog("ERROR: Could not determine skill type from book: " + skillBookType);
            return recipes;
        }
        
        DebugLog("Determined skill type: " + skillType + " from book: " + skillBookType);
        
        // Scan recipe directories
        ScanRecipeDirectory("", skillBookType, skillType, recipes);
        
        // Scan skill-specific directory if it exists
        string skillDirName = GetSkillDirectoryName(skillType);
        if (skillDirName != "")
        {
            ScanRecipeDirectory(skillDirName, skillBookType, skillType, recipes);
        }
        
        DebugLog("Found " + recipes.Count() + " recipes for skill book: " + skillBookType);
        return recipes;
    }
    
    /**
     * Scan a specific recipe directory for recipes
     * @param dirPath The directory path to scan (relative to RECIPE_DIR_PATH)
     * @param skillBookType The skill book type to scan for
     * @param skillType The skill type associated with the book
     * @param recipes Array to store found recipes
     */
    private void ScanRecipeDirectory(string dirPath, string skillBookType, string skillType, array<ref SkillRecipeData> recipes)
    {
        string fullPath = RECIPE_DIR_PATH;
        if (dirPath != "")
        {
            fullPath = fullPath + "/" + dirPath;
        }
        
        DebugLog("Scanning directory: " + fullPath);
        
        // In a real implementation, we would use file system functions to scan the directory
        // Since we can't directly access the file system in script, we'll simulate this by
        // scanning all known recipe files in the mod
        
        // For now, we'll use the example recipe provided and add more as needed
        
        // This is where we would normally iterate through files in the directory
        // Instead, we'll use a hardcoded approach for demonstration
        
        // Example for the createGardenBox recipe
        if (skillType == SkillTypes.FARMING && ContainsSkillBook(skillBookType, "SausageCo_FarmersToolT1"))
        {
            ref SkillRecipeData gardenBoxRecipe = CreateRecipeFromFile("createGardenBox", skillType);
            if (gardenBoxRecipe)
            {
                recipes.Insert(gardenBoxRecipe);
            }
        }
        
        // Add more recipes here based on the skill type and book
        // This would be replaced by actual file scanning in a real implementation
        
        // For demonstration, let's add some more farming recipes if this is a farming book
        if (skillType == SkillTypes.FARMING && ContainsSkillBook(skillBookType, "SausageCo_FarmersToolT1"))
        {
            // These are placeholder recipes - in a real implementation, we would parse actual recipe files
            AddPlaceholderFarmingRecipes(recipes);
        }
        
        // Add placeholder recipes for other skill types
        if (skillType == SkillTypes.ENGINEERING && ContainsSkillBook(skillBookType, "SausageCo_EngineersTool"))
        {
            AddPlaceholderEngineeringRecipes(recipes);
        }
        
        if (skillType == SkillTypes.FIREARM && ContainsSkillBook(skillBookType, "SausageCo_FirearmsTool"))
        {
            AddPlaceholderFirearmRecipes(recipes);
        }
        
        if (skillType == SkillTypes.LEATHER && ContainsSkillBook(skillBookType, "SausageCo_LeatherWorkersTool"))
        {
            AddPlaceholderLeatherRecipes(recipes);
        }
        
        if (skillType == SkillTypes.MECHANIC && ContainsSkillBook(skillBookType, "SausageCo_MechanicsTool"))
        {
            AddPlaceholderMechanicRecipes(recipes);
        }
        
        if (skillType == SkillTypes.MEDIC && ContainsSkillBook(skillBookType, "SausageCo_MedicsTool"))
        {
            AddPlaceholderMedicRecipes(recipes);
        }
    }
    
    /**
     * Create a SkillRecipeData object from a recipe file
     * @param recipeFileName The name of the recipe file (without extension)
     * @param skillType The skill type associated with the recipe
     * @return SkillRecipeData object or null if parsing failed
     */
    private ref SkillRecipeData CreateRecipeFromFile(string recipeFileName, string skillType)
    {
        DebugLog("Creating recipe from file: " + recipeFileName);
        
        // Create a new recipe data object
        ref SkillRecipeData recipeData = new SkillRecipeData();
        
        // Set basic recipe information
        recipeData.recipeName = recipeFileName;
        recipeData.skillType = skillType;
        
        // For the garden box example
        if (recipeFileName == "createGardenBox")
        {
            recipeData.displayName = "Garden Box";
            recipeData.description = "Create a garden box for planting crops.";
            recipeData.requiredLevel = 1;
            
            // Add ingredients
            recipeData.ingredients.Insert(new Param2<string, int>("WoodenPlank", 20));
            recipeData.ingredients.Insert(new Param2<string, int>("SausageCo_FarmersToolT1", 1));
            
            // Add results
            recipeData.results.Insert(new Param2<string, int>("SausageCo_EmptyGardenBox", 1));
            
            recipeData.craftingTime = 10.0;
            recipeData.xpReward = 80;
            
            return recipeData;
        }
        
        // If we couldn't parse the recipe file, return null
        return null;
    }
    
    /**
     * Get the skill type from a skill book type
     * @param bookType The skill book type
     * @return The skill type or empty string if not found
     */
    private string GetSkillTypeFromBookType(string bookType)
    {
        string result = "";
        // Check for farming tools
        if (bookType.Contains("FarmersTool") || bookType.Contains("SkillBook_Farming"))
        {
            return SkillTypes.FARMING;
        }
        
        // Check for engineering tools
        if (bookType.Contains("EngineersTool") || bookType.Contains("SkillBook_Engineering"))
        {
            return SkillTypes.ENGINEERING;
        }
        
        // Check for firearm tools
        if (bookType.Contains("FirearmsTool") || bookType.Contains("SkillBook_Firearm"))
        {
            return SkillTypes.FIREARM;
        }
        
        // Check for leather tools
        if (bookType.Contains("LeatherWorkersTool") || bookType.Contains("SkillBook_Leather"))
        {
            return SkillTypes.LEATHER;
        }
        
        // Check for mechanic tools
        if (bookType.Contains("MechanicsTool") || bookType.Contains("SkillBook_Mechanic"))
        {
            return SkillTypes.MECHANIC;
        }
        
        // Check for medic tools
        if (bookType.Contains("MedicsTool") || bookType.Contains("SkillBook_Medic"))
        {
            return SkillTypes.MEDIC;
        }
        
        // Check for hunter tools
        if (bookType.Contains("HuntersTool") || bookType.Contains("SkillBook_Hunter"))
        {
            return SkillTypes.HUNTER;
        }
        
        // Check for cook tools
        if (bookType.Contains("CooksTool") || bookType.Contains("SkillBook_Cook"))
        {
            return SkillTypes.COOK;
        }
        
        return result;
    }
    
    /**
     * Get the directory name for a skill type
     * @param skillType The skill type
     * @return The directory name or empty string if not found
     */
    private string GetSkillDirectoryName(string skillType)
    {
		switch (skillType)
		{
			case SkillTypes.ENGINEERING:
				return "SkillEngineering";
			case SkillTypes.FARMING:
				return "SkillFarmer";
			case SkillTypes.FIREARM:
				return "SkillFireArms";
			case SkillTypes.LEATHER:
				return "SkillLeather";
			case SkillTypes.MECHANIC:
				return "SkillMechanic";
			case SkillTypes.MEDIC:
				return "SkillMedic";
			case SkillTypes.HUNTER:
				return "SkillHunter";
			case SkillTypes.COOK:
				return "SkillCook";
			default:
				return "";
		}
		return "";
		
    }
    
    /**
     * Check if a skill book type contains a specific skill book
     * @param bookType The skill book type to check
     * @param skillBook The skill book to check for
     * @return True if the book type contains the skill book, false otherwise
     */
    private bool ContainsSkillBook(string bookType, string skillBook)
    {
        return bookType == skillBook || bookType.Contains(skillBook);
    }
    
    /**
     * Add placeholder farming recipes for demonstration
     * @param recipes Array to add recipes to
     */
    private void AddPlaceholderFarmingRecipes(array<ref SkillRecipeData> recipes)
    {
        // Garden Plot recipe
        ref SkillRecipeData gardenPlotRecipe = new SkillRecipeData();
        gardenPlotRecipe.recipeName = "createGardenPlot";
        gardenPlotRecipe.displayName = "Garden Plot";
        gardenPlotRecipe.description = "Create a garden plot for planting crops.";
        gardenPlotRecipe.skillType = SkillTypes.FARMING;
        gardenPlotRecipe.requiredLevel = 1;
        gardenPlotRecipe.ingredients.Insert(new Param2<string, int>("Shovel", 1));
        gardenPlotRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_FarmersToolT1", 1));
        gardenPlotRecipe.results.Insert(new Param2<string, int>("SausageCo_GardenPlot", 1));
        gardenPlotRecipe.craftingTime = 15.0;
        gardenPlotRecipe.xpReward = 50;
        recipes.Insert(gardenPlotRecipe);
        
        // Compost Bin recipe
        ref SkillRecipeData compostBinRecipe = new SkillRecipeData();
        compostBinRecipe.recipeName = "createCompostBin";
        compostBinRecipe.displayName = "Compost Bin";
        compostBinRecipe.description = "Create a compost bin for making fertilizer.";
        compostBinRecipe.skillType = SkillTypes.FARMING;
        compostBinRecipe.requiredLevel = 2;
        compostBinRecipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 10));
        compostBinRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_FarmersToolT1", 1));
        compostBinRecipe.results.Insert(new Param2<string, int>("SausageCo_CompostBin", 1));
        compostBinRecipe.craftingTime = 20.0;
        compostBinRecipe.xpReward = 100;
        recipes.Insert(compostBinRecipe);
    }
    
    /**
     * Add placeholder engineering recipes for demonstration
     * @param recipes Array to add recipes to
     */
    private void AddPlaceholderEngineeringRecipes(array<ref SkillRecipeData> recipes)
    {
        // Workbench recipe
        ref SkillRecipeData workbenchRecipe = new SkillRecipeData();
        workbenchRecipe.recipeName = "createWorkbench";
        workbenchRecipe.displayName = "Workbench";
        workbenchRecipe.description = "Create a workbench for crafting items.";
        workbenchRecipe.skillType = SkillTypes.ENGINEERING;
        workbenchRecipe.requiredLevel = 1;
        workbenchRecipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 15));
        workbenchRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_EngineersTool", 1));
        workbenchRecipe.results.Insert(new Param2<string, int>("SausageCo_Workbench", 1));
        workbenchRecipe.craftingTime = 25.0;
        workbenchRecipe.xpReward = 120;
        recipes.Insert(workbenchRecipe);
    }
    
    /**
     * Add placeholder firearm recipes for demonstration
     * @param recipes Array to add recipes to
     */
    private void AddPlaceholderFirearmRecipes(array<ref SkillRecipeData> recipes)
    {
        // Ammunition Workbench recipe
        ref SkillRecipeData ammoWorkbenchRecipe = new SkillRecipeData();
        ammoWorkbenchRecipe.recipeName = "createAmmoWorkbench";
        ammoWorkbenchRecipe.displayName = "Ammunition Workbench";
        ammoWorkbenchRecipe.description = "Create a workbench for crafting ammunition.";
        ammoWorkbenchRecipe.skillType = SkillTypes.FIREARM;
        ammoWorkbenchRecipe.requiredLevel = 2;
        ammoWorkbenchRecipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 12));
        ammoWorkbenchRecipe.ingredients.Insert(new Param2<string, int>("MetalSheet", 4));
        ammoWorkbenchRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_FirearmsTool", 1));
        ammoWorkbenchRecipe.results.Insert(new Param2<string, int>("SausageCo_AmmoWorkbench", 1));
        ammoWorkbenchRecipe.craftingTime = 30.0;
        ammoWorkbenchRecipe.xpReward = 150;
        recipes.Insert(ammoWorkbenchRecipe);
    }
    
    /**
     * Add placeholder leather recipes for demonstration
     * @param recipes Array to add recipes to
     */
    private void AddPlaceholderLeatherRecipes(array<ref SkillRecipeData> recipes)
    {
        // Tanning Rack recipe
        ref SkillRecipeData tanningRackRecipe = new SkillRecipeData();
        tanningRackRecipe.recipeName = "createTanningRack";
        tanningRackRecipe.displayName = "Tanning Rack";
        tanningRackRecipe.description = "Create a rack for tanning hides.";
        tanningRackRecipe.skillType = SkillTypes.LEATHER;
        tanningRackRecipe.requiredLevel = 1;
        tanningRackRecipe.ingredients.Insert(new Param2<string, int>("WoodenStick", 8));
        tanningRackRecipe.ingredients.Insert(new Param2<string, int>("Rope", 4));
        tanningRackRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_LeatherWorkersTool", 1));
        tanningRackRecipe.results.Insert(new Param2<string, int>("SausageCo_TanningRack", 1));
        tanningRackRecipe.craftingTime = 20.0;
        tanningRackRecipe.xpReward = 100;
        recipes.Insert(tanningRackRecipe);
    }
    
    /**
     * Add placeholder mechanic recipes for demonstration
     * @param recipes Array to add recipes to
     */
    private void AddPlaceholderMechanicRecipes(array<ref SkillRecipeData> recipes)
    {
        // Vehicle Repair Kit recipe
        ref SkillRecipeData repairKitRecipe = new SkillRecipeData();
        repairKitRecipe.recipeName = "createVehicleRepairKit";
        repairKitRecipe.displayName = "Vehicle Repair Kit";
        repairKitRecipe.description = "Create a kit for repairing vehicles.";
        repairKitRecipe.skillType = SkillTypes.MECHANIC;
        repairKitRecipe.requiredLevel = 2;
        repairKitRecipe.ingredients.Insert(new Param2<string, int>("MetalSheet", 2));
        repairKitRecipe.ingredients.Insert(new Param2<string, int>("ElectricalWire", 4));
        repairKitRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_MechanicsTool", 1));
        repairKitRecipe.results.Insert(new Param2<string, int>("SausageCo_VehicleRepairKit", 1));
        repairKitRecipe.craftingTime = 15.0;
        repairKitRecipe.xpReward = 80;
        recipes.Insert(repairKitRecipe);
    }
    
    /**
     * Add placeholder medic recipes for demonstration
     * @param recipes Array to add recipes to
     */
    private void AddPlaceholderMedicRecipes(array<ref SkillRecipeData> recipes)
    {
        // Medical Station recipe
        ref SkillRecipeData medicalStationRecipe = new SkillRecipeData();
        medicalStationRecipe.recipeName = "createMedicalStation";
        medicalStationRecipe.displayName = "Medical Station";
        medicalStationRecipe.description = "Create a station for crafting medical supplies.";
        medicalStationRecipe.skillType = SkillTypes.MEDIC;
        medicalStationRecipe.requiredLevel = 2;
        medicalStationRecipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 10));
        medicalStationRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_MedicsTool", 1));
        medicalStationRecipe.results.Insert(new Param2<string, int>("SausageCo_MedicalStation", 1));
        medicalStationRecipe.craftingTime = 20.0;
        medicalStationRecipe.xpReward = 100;
        recipes.Insert(medicalStationRecipe);
    }
    
    /**
     * Debug logging
     * @param message The message to log
     */
    private void DebugLog(string message)
    {
        if (m_Debug)
        {
            Print("[RecipeScanner] " + message);
        }
    }
}