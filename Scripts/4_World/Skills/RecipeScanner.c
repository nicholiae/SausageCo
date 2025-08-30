
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
     * @param skillBookType The skill book type to scan for (e.g., "SausageCo_FarmersTool")
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
            
            // Also scan subdirectories for tiered recipes
            for (int tier = 1; tier <= 4; tier++)
            {
                string tierDirName = skillDirName + "/Farmer" + "T" + tier;
                ScanRecipeDirectory(tierDirName, skillBookType, skillType, recipes);
            }
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
        
        // IMPORTANT FIX: Use more flexible matching for skill book types
        if (skillType == SkillTypes.FARMING)
        {
            // Add farming recipes
            AddFarmingRecipes(recipes, skillBookType);
        }
        else if (skillType == SkillTypes.ENGINEERING)
        {
            // Add engineering recipes
            AddEngineeringRecipes(recipes, skillBookType);
        }
        else if (skillType == SkillTypes.FIREARM)
        {
            // Add firearm recipes
            AddFirearmRecipes(recipes, skillBookType);
        }
        else if (skillType == SkillTypes.LEATHER)
        {
            // Add leather recipes
            AddLeatherRecipes(recipes, skillBookType);
        }
        else if (skillType == SkillTypes.MECHANIC)
        {
            // Add mechanic recipes
            AddMechanicRecipes(recipes, skillBookType);
        }
        else if (skillType == SkillTypes.MEDIC)
        {
            // Add medic recipes
            AddMedicRecipes(recipes, skillBookType);
        }
        else if (skillType == SkillTypes.HUNTER)
        {
            // Add hunter recipes
            AddHunterRecipes(recipes, skillBookType);
        }
        else if (skillType == SkillTypes.COOK)
        {
            // Add cook recipes
            AddCookRecipes(recipes, skillBookType);
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
        // IMPORTANT FIX: Make this more flexible to handle different book types
        // Check if the book type exactly matches the skill book
        if (bookType == skillBook)
            return true;
        
        // Check if the book type contains the skill book
        if (bookType.Contains(skillBook))
            return true;
        
        // Check if the book type and skill book are related by skill type
        string bookSkillType = GetSkillTypeFromBookType(bookType);
        string skillBookSkillType = GetSkillTypeFromBookType(skillBook);
        
        if (bookSkillType != "" && skillBookSkillType != "" && bookSkillType == skillBookSkillType)
            return true;
        
        // Special case for tiered books
        if (bookType.Contains("FarmersTool") && skillBook.Contains("FarmersTool"))
            return true;
        if (bookType.Contains("EngineersTool") && skillBook.Contains("EngineersTool"))
            return true;
        if (bookType.Contains("FirearmsTool") && skillBook.Contains("FirearmsTool"))
            return true;
        if (bookType.Contains("LeatherWorkersTool") && skillBook.Contains("LeatherWorkersTool"))
            return true;
        if (bookType.Contains("MechanicsTool") && skillBook.Contains("MechanicsTool"))
            return true;
        if (bookType.Contains("MedicsTool") && skillBook.Contains("MedicsTool"))
            return true;
        
        return false;
    }
    
    /**
     * Add farming recipes for demonstration
     * @param recipes Array to add recipes to
     * @param skillBookType The skill book type
     */
    private void AddFarmingRecipes(array<ref SkillRecipeData> recipes, string skillBookType)
    {
        // Garden Box recipe
        ref SkillRecipeData gardenBoxRecipe = new SkillRecipeData();
        gardenBoxRecipe.recipeName = "createGardenBox";
        gardenBoxRecipe.displayName = "Garden Box";
        gardenBoxRecipe.description = "Create a garden box for planting crops.";
        gardenBoxRecipe.skillType = SkillTypes.FARMING;
        gardenBoxRecipe.requiredLevel = 1;
        gardenBoxRecipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 20));
        gardenBoxRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_FarmersToolT1", 1));
        gardenBoxRecipe.results.Insert(new Param2<string, int>("SausageCo_EmptyGardenBox", 1));
        gardenBoxRecipe.craftingTime = 10.0;
        gardenBoxRecipe.xpReward = 80;
        recipes.Insert(gardenBoxRecipe);
        
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
        
        // Add more farming recipes as needed
        // Seeds recipes
        ref SkillRecipeData seedsRecipe = new SkillRecipeData();
        seedsRecipe.recipeName = "createSeedsPack";
        seedsRecipe.displayName = "Seeds Pack";
        seedsRecipe.description = "Create a pack of seeds for planting.";
        seedsRecipe.skillType = SkillTypes.FARMING;
        seedsRecipe.requiredLevel = 1;
        seedsRecipe.ingredients.Insert(new Param2<string, int>("PlantMaterial", 5));
        seedsRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_FarmersToolT1", 1));
        seedsRecipe.results.Insert(new Param2<string, int>("SausageCo_SeedsPack", 1));
        seedsRecipe.craftingTime = 5.0;
        seedsRecipe.xpReward = 25;
        recipes.Insert(seedsRecipe);
    }
    
    /**
     * Add engineering recipes for demonstration
     * @param recipes Array to add recipes to
     * @param skillBookType The skill book type
     */
    private void AddEngineeringRecipes(array<ref SkillRecipeData> recipes, string skillBookType)
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
        
        // Storage Crate recipe
        ref SkillRecipeData storageRecipe = new SkillRecipeData();
        storageRecipe.recipeName = "createStorageCrate";
        storageRecipe.displayName = "Storage Crate";
        storageRecipe.description = "Create a storage crate for storing items.";
        storageRecipe.skillType = SkillTypes.ENGINEERING;
        storageRecipe.requiredLevel = 1;
        storageRecipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 10));
        storageRecipe.ingredients.Insert(new Param2<string, int>("Nail", 8));
        storageRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_EngineersTool", 1));
        storageRecipe.results.Insert(new Param2<string, int>("SausageCo_StorageCrate", 1));
        storageRecipe.craftingTime = 15.0;
        storageRecipe.xpReward = 80;
        recipes.Insert(storageRecipe);
    }
    
    /**
     * Add firearm recipes for demonstration
     * @param recipes Array to add recipes to
     * @param skillBookType The skill book type
     */
    private void AddFirearmRecipes(array<ref SkillRecipeData> recipes, string skillBookType)
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
        
        // Basic Ammo recipe
        ref SkillRecipeData basicAmmoRecipe = new SkillRecipeData();
        basicAmmoRecipe.recipeName = "createBasicAmmo";
        basicAmmoRecipe.displayName = "Basic Ammunition";
        basicAmmoRecipe.description = "Create basic ammunition for firearms.";
        basicAmmoRecipe.skillType = SkillTypes.FIREARM;
        basicAmmoRecipe.requiredLevel = 1;
        basicAmmoRecipe.ingredients.Insert(new Param2<string, int>("GunPowder", 1));
        basicAmmoRecipe.ingredients.Insert(new Param2<string, int>("MetalScrap", 1));
        basicAmmoRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_FirearmsTool", 1));
        basicAmmoRecipe.results.Insert(new Param2<string, int>("Ammo_9x19", 10));
        basicAmmoRecipe.craftingTime = 10.0;
        basicAmmoRecipe.xpReward = 50;
        recipes.Insert(basicAmmoRecipe);
    }
    
    /**
     * Add leather recipes for demonstration
     * @param recipes Array to add recipes to
     * @param skillBookType The skill book type
     */
    private void AddLeatherRecipes(array<ref SkillRecipeData> recipes, string skillBookType)
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
        
        // Leather Pouch recipe
        ref SkillRecipeData leatherPouchRecipe = new SkillRecipeData();
        leatherPouchRecipe.recipeName = "createLeatherPouch";
        leatherPouchRecipe.displayName = "Leather Pouch";
        leatherPouchRecipe.description = "Create a small leather pouch for storage.";
        leatherPouchRecipe.skillType = SkillTypes.LEATHER;
        leatherPouchRecipe.requiredLevel = 1;
        leatherPouchRecipe.ingredients.Insert(new Param2<string, int>("Leather", 2));
        leatherPouchRecipe.ingredients.Insert(new Param2<string, int>("Rope", 1));
        leatherPouchRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_LeatherWorkersTool", 1));
        leatherPouchRecipe.results.Insert(new Param2<string, int>("SausageCo_LeatherPouch", 1));
        leatherPouchRecipe.craftingTime = 10.0;
        leatherPouchRecipe.xpReward = 50;
        recipes.Insert(leatherPouchRecipe);
    }
    
    /**
     * Add mechanic recipes for demonstration
     * @param recipes Array to add recipes to
     * @param skillBookType The skill book type
     */
    private void AddMechanicRecipes(array<ref SkillRecipeData> recipes, string skillBookType)
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
        
        // Basic Vehicle Parts recipe
        ref SkillRecipeData partsRecipe = new SkillRecipeData();
        partsRecipe.recipeName = "createBasicVehicleParts";
        partsRecipe.displayName = "Basic Vehicle Parts";
        partsRecipe.description = "Create basic parts for vehicle repair.";
        partsRecipe.skillType = SkillTypes.MECHANIC;
        partsRecipe.requiredLevel = 1;
        partsRecipe.ingredients.Insert(new Param2<string, int>("MetalSheet", 1));
        partsRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_MechanicsTool", 1));
        partsRecipe.results.Insert(new Param2<string, int>("SausageCo_VehicleParts", 3));
        partsRecipe.craftingTime = 10.0;
        partsRecipe.xpReward = 40;
        recipes.Insert(partsRecipe);
    }
    
    /**
     * Add medic recipes for demonstration
     * @param recipes Array to add recipes to
     * @param skillBookType The skill book type
     */
    private void AddMedicRecipes(array<ref SkillRecipeData> recipes, string skillBookType)
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
        
        // Basic Bandage recipe
        ref SkillRecipeData bandageRecipe = new SkillRecipeData();
        bandageRecipe.recipeName = "createBasicBandage";
        bandageRecipe.displayName = "Basic Bandage";
        bandageRecipe.description = "Create a basic bandage for treating wounds.";
        bandageRecipe.skillType = SkillTypes.MEDIC;
        bandageRecipe.requiredLevel = 1;
        bandageRecipe.ingredients.Insert(new Param2<string, int>("Rag", 4));
        bandageRecipe.ingredients.Insert(new Param2<string, int>("Disinfectant", 1));
        bandageRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_MedicsTool", 1));
        bandageRecipe.results.Insert(new Param2<string, int>("Bandage", 2));
        bandageRecipe.craftingTime = 5.0;
        bandageRecipe.xpReward = 30;
        recipes.Insert(bandageRecipe);
    }
    
    /**
     * Add hunter recipes for demonstration
     * @param recipes Array to add recipes to
     * @param skillBookType The skill book type
     */
    private void AddHunterRecipes(array<ref SkillRecipeData> recipes, string skillBookType)
    {
        // Hunting Blind recipe
        ref SkillRecipeData huntingBlindRecipe = new SkillRecipeData();
        huntingBlindRecipe.recipeName = "createHuntingBlind";
        huntingBlindRecipe.displayName = "Hunting Blind";
        huntingBlindRecipe.description = "Create a hunting blind for concealment.";
        huntingBlindRecipe.skillType = SkillTypes.HUNTER;
        huntingBlindRecipe.requiredLevel = 2;
        huntingBlindRecipe.ingredients.Insert(new Param2<string, int>("WoodenStick", 10));
        huntingBlindRecipe.ingredients.Insert(new Param2<string, int>("Burlap", 4));
        huntingBlindRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_HuntersTool", 1));
        huntingBlindRecipe.results.Insert(new Param2<string, int>("SausageCo_HuntingBlind", 1));
        huntingBlindRecipe.craftingTime = 15.0;
        huntingBlindRecipe.xpReward = 80;
        recipes.Insert(huntingBlindRecipe);
        
        // Simple Snare recipe
        ref SkillRecipeData snareRecipe = new SkillRecipeData();
        snareRecipe.recipeName = "createSimpleSnare";
        snareRecipe.displayName = "Simple Snare";
        snareRecipe.description = "Create a simple snare trap for catching small animals.";
        snareRecipe.skillType = SkillTypes.HUNTER;
        snareRecipe.requiredLevel = 1;
        snareRecipe.ingredients.Insert(new Param2<string, int>("Rope", 1));
        snareRecipe.ingredients.Insert(new Param2<string, int>("Stick", 2));
        snareRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_HuntersTool", 1));
        snareRecipe.results.Insert(new Param2<string, int>("SausageCo_SimpleSnare", 1));
        snareRecipe.craftingTime = 5.0;
        snareRecipe.xpReward = 30;
        recipes.Insert(snareRecipe);
    }
    
    /**
     * Add cook recipes for demonstration
     * @param recipes Array to add recipes to
     * @param skillBookType The skill book type
     */
    private void AddCookRecipes(array<ref SkillRecipeData> recipes, string skillBookType)
    {
        // Cooking Station recipe
        ref SkillRecipeData cookingStationRecipe = new SkillRecipeData();
        cookingStationRecipe.recipeName = "createCookingStation";
        cookingStationRecipe.displayName = "Cooking Station";
        cookingStationRecipe.description = "Create a station for preparing meals.";
        cookingStationRecipe.skillType = SkillTypes.COOK;
        cookingStationRecipe.requiredLevel = 2;
        cookingStationRecipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 8));
        cookingStationRecipe.ingredients.Insert(new Param2<string, int>("MetalSheet", 2));
        cookingStationRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_CooksTool", 1));
        cookingStationRecipe.results.Insert(new Param2<string, int>("SausageCo_CookingStation", 1));
        cookingStationRecipe.craftingTime = 15.0;
        cookingStationRecipe.xpReward = 80;
        recipes.Insert(cookingStationRecipe);
        
        // Basic Cooking recipe
        ref SkillRecipeData cookingRecipe = new SkillRecipeData();
        cookingRecipe.recipeName = "createBasicCooking";
        cookingRecipe.displayName = "Basic Cooking";
        cookingRecipe.description = "Cook raw meat into a nutritious meal.";
        cookingRecipe.skillType = SkillTypes.COOK;
        cookingRecipe.requiredLevel = 1;
        cookingRecipe.ingredients.Insert(new Param2<string, int>("Meat", 1));
        cookingRecipe.ingredients.Insert(new Param2<string, int>("Water", 1));
        cookingRecipe.ingredients.Insert(new Param2<string, int>("SausageCo_CooksTool", 1));
        cookingRecipe.results.Insert(new Param2<string, int>("CookedMeat", 1));
        cookingRecipe.craftingTime = 5.0;
        cookingRecipe.xpReward = 20;
        recipes.Insert(cookingRecipe);
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
