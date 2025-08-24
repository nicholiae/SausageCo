/**
• SausageCo Skills System
• Recipe Manager - Enhanced Version with Debug Logging
 */


class SausageSkillsRecipeManager
{
    // Recipe database
    private ref map<string, ref SkillRecipeData> m_Recipes;


	// Debug flags
	private bool m_Debug = true;
	private bool m_Initialized = false;

	void SausageSkillsRecipeManager()
	{
		m_Recipes = new map<string, ref SkillRecipeData>();
		DebugLog("SausageSkillsRecipeManager constructor called");
	}

	void Init()
	{
		DebugLog("Initializing Recipe Manager");
		
		// Create default recipes
		CreateDefaultRecipes();
		
		// Mark as initialized
		m_Initialized = true;
		
		// Log recipe count
		DebugLog("Recipe Manager initialized with " + m_Recipes.Count() + " recipes");
		
		// Log recipes per skill type
		LogRecipesPerSkillType();
	}

	void CreateDefaultRecipes()
	{
		// Engineering recipes
		CreateWoodenPlankRecipe();
		CreateBasicShelterRecipe();
		CreateImprovedShelterRecipe();
		CreateWoodenCrateRecipe();
		CreateMiningFurnaceRecipe();
		CreateWorkBenchRecipe();
		
		// Farming recipes
		CreatePlantTomatoRecipe();
		CreatePlantZucchiniRecipe();
		CreatePlantPumpkinRecipe();
		CreateImprovedCompostRecipe();
		
		// Firearm recipes
		CreateBasicAmmoRecipe();
		CreateWeaponCleaningRecipe();
		CreateImprovedAmmoRecipe();
		
		// Leather recipes
		CreateBasicTanningRecipe();
		CreateLeatherPouchRecipe();
		
		// Mechanic recipes
		CreateBasicRepairRecipe();
		CreateTireChangeRecipe();
		
		// Medic recipes
		CreateBasicBandageRecipe();
		CreateHerbalTeaRecipe();
		
		// Hunter recipes
		CreateBasicButcheringRecipe();
		CreateSimpleSnareRecipe();
		
		// Cook recipes
		CreateBasicCookingRecipe();
		CreateSimplePreservationRecipe();
		
		DebugLog("Created " + m_Recipes.Count() + " recipes");
	}

	// Engineering Recipes
	void CreateWoodenPlankRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "WoodenPlank";
		recipe.displayName = "Wooden Planks";
		recipe.description = "Process logs into wooden planks for building.";
		recipe.skillType = SkillTypes.ENGINEERING;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("WoodenLog", 1));
		recipe.results.Insert(new Param2<string, int>("WoodenPlank", 4));
		recipe.craftingTime = 5.0;
		recipe.xpReward = 15; // Added XP reward
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	// Added missing recipe methods
	void CreateBasicShelterRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "BasicShelter";
		recipe.displayName = "Basic Shelter";
		recipe.description = "Construct a simple shelter for protection.";
		recipe.skillType = SkillTypes.ENGINEERING;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 6));
		recipe.ingredients.Insert(new Param2<string, int>("Rope", 2));
		recipe.results.Insert(new Param2<string, int>("BasicShelter_Kit", 1));
		recipe.craftingTime = 15.0;
		recipe.xpReward = 30;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreateImprovedShelterRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "ImprovedShelter";
		recipe.displayName = "Improved Shelter";
		recipe.description = "Construct a more durable shelter with better protection.";
		recipe.skillType = SkillTypes.ENGINEERING;
		recipe.requiredLevel = 2;
		recipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 10));
		recipe.ingredients.Insert(new Param2<string, int>("Rope", 3));
		recipe.ingredients.Insert(new Param2<string, int>("Nail", 8));
		recipe.results.Insert(new Param2<string, int>("ImprovedShelter_Kit", 1));
		recipe.craftingTime = 25.0;
		recipe.xpReward = 50;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreateWoodenCrateRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "WoodenCrate";
		recipe.displayName = "Wooden Crate";
		recipe.description = "Craft a wooden crate for storage.";
		recipe.skillType = SkillTypes.ENGINEERING;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 4));
		recipe.ingredients.Insert(new Param2<string, int>("Nail", 6));
		recipe.results.Insert(new Param2<string, int>("WoodenCrate", 1));
		recipe.craftingTime = 10.0;
		recipe.xpReward = 20;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreateMiningFurnaceRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "MiningFurnace";
		recipe.displayName = "Mining Furnace";
		recipe.description = "Build a furnace for smelting ores.";
		recipe.skillType = SkillTypes.ENGINEERING;
		recipe.requiredLevel = 3;
		recipe.ingredients.Insert(new Param2<string, int>("Stone", 20));
		recipe.ingredients.Insert(new Param2<string, int>("Firewood", 5));
		recipe.results.Insert(new Param2<string, int>("MiningFurnace_Kit", 1));
		recipe.craftingTime = 30.0;
		recipe.xpReward = 60;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreateWorkBenchRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "WorkBench";
		recipe.displayName = "Work Bench";
		recipe.description = "Construct a work bench for crafting.";
		recipe.skillType = SkillTypes.ENGINEERING;
		recipe.requiredLevel = 2;
		recipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 8));
		recipe.ingredients.Insert(new Param2<string, int>("Nail", 12));
		recipe.ingredients.Insert(new Param2<string, int>("MetalSheet", 2));
		recipe.results.Insert(new Param2<string, int>("WorkBench_Kit", 1));
		recipe.craftingTime = 20.0;
		recipe.xpReward = 40;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	// Farming Recipes
	void CreatePlantTomatoRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "PlantTomato";
		recipe.displayName = "Plant Tomato";
		recipe.description = "Plant tomato seeds in a garden plot.";
		recipe.skillType = SkillTypes.FARMING;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("TomatoSeeds", 1));
		recipe.ingredients.Insert(new Param2<string, int>("GardenLime", 1));
		recipe.results.Insert(new Param2<string, int>("TomatoPlant", 1));
		recipe.craftingTime = 5.0;
		recipe.xpReward = 10;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreatePlantZucchiniRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "PlantZucchini";
		recipe.displayName = "Plant Zucchini";
		recipe.description = "Plant zucchini seeds in a garden plot.";
		recipe.skillType = SkillTypes.FARMING;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("ZucchiniSeeds", 1));
		recipe.ingredients.Insert(new Param2<string, int>("GardenLime", 1));
		recipe.results.Insert(new Param2<string, int>("ZucchiniPlant", 1));
		recipe.craftingTime = 5.0;
		recipe.xpReward = 10;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreatePlantPumpkinRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "PlantPumpkin";
		recipe.displayName = "Plant Pumpkin";
		recipe.description = "Plant pumpkin seeds in a garden plot.";
		recipe.skillType = SkillTypes.FARMING;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("PumpkinSeeds", 1));
		recipe.ingredients.Insert(new Param2<string, int>("GardenLime", 1));
		recipe.results.Insert(new Param2<string, int>("PumpkinPlant", 1));
		recipe.craftingTime = 5.0;
		recipe.xpReward = 10;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreateImprovedCompostRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "ImprovedCompost";
		recipe.displayName = "Improved Compost";
		recipe.description = "Create improved compost for better crop yields.";
		recipe.skillType = SkillTypes.FARMING;
		recipe.requiredLevel = 2;
		recipe.ingredients.Insert(new Param2<string, int>("Compost", 2));
		recipe.ingredients.Insert(new Param2<string, int>("PlantMaterial", 4));
		recipe.results.Insert(new Param2<string, int>("ImprovedCompost", 2));
		recipe.craftingTime = 15.0;
		recipe.xpReward = 25;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	// Firearm Recipes
	void CreateBasicAmmoRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "BasicAmmo";
		recipe.displayName = "Basic Ammunition";
		recipe.description = "Craft basic ammunition for firearms.";
		recipe.skillType = SkillTypes.FIREARM;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("GunPowder", 1));
		recipe.ingredients.Insert(new Param2<string, int>("MetalScrap", 1));
		recipe.results.Insert(new Param2<string, int>("Ammo_9x19", 10));
		recipe.craftingTime = 10.0;
		recipe.xpReward = 15;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreateWeaponCleaningRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "WeaponCleaning";
		recipe.displayName = "Weapon Cleaning";
		recipe.description = "Clean and maintain a firearm to improve its condition.";
		recipe.skillType = SkillTypes.FIREARM;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("WeaponCleaningKit", 1));
		recipe.ingredients.Insert(new Param2<string, int>("Rag", 2));
		recipe.results.Insert(new Param2<string, int>("CleanedWeapon", 1));
		recipe.craftingTime = 5.0;
		recipe.xpReward = 10;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreateImprovedAmmoRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "ImprovedAmmo";
		recipe.displayName = "Improved Ammunition";
		recipe.description = "Craft improved ammunition with better performance.";
		recipe.skillType = SkillTypes.FIREARM;
		recipe.requiredLevel = 2;
		recipe.ingredients.Insert(new Param2<string, int>("GunPowder", 2));
		recipe.ingredients.Insert(new Param2<string, int>("MetalScrap", 2));
		recipe.results.Insert(new Param2<string, int>("Ammo_308Win", 5));
		recipe.craftingTime = 15.0;
		recipe.xpReward = 25;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	// Leather Recipes
	void CreateBasicTanningRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "BasicTanning";
		recipe.displayName = "Basic Tanning";
		recipe.description = "Tan animal hides into leather.";
		recipe.skillType = SkillTypes.LEATHER;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("AnimalPelt", 1));
		recipe.ingredients.Insert(new Param2<string, int>("Lime", 1));
		recipe.results.Insert(new Param2<string, int>("Leather", 2));
		recipe.craftingTime = 20.0;
		recipe.xpReward = 20;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreateLeatherPouchRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "LeatherPouch";
		recipe.displayName = "Leather Pouch";
		recipe.description = "Craft a small leather pouch for storage.";
		recipe.skillType = SkillTypes.LEATHER;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("Leather", 2));
		recipe.ingredients.Insert(new Param2<string, int>("Rope", 1));
		recipe.results.Insert(new Param2<string, int>("LeatherPouch", 1));
		recipe.craftingTime = 10.0;
		recipe.xpReward = 15;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	// Mechanic Recipes
	void CreateBasicRepairRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "BasicRepair";
		recipe.displayName = "Basic Vehicle Repair";
		recipe.description = "Perform basic repairs on a vehicle.";
		recipe.skillType = SkillTypes.MECHANIC;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("MetalScrap", 2));
		recipe.ingredients.Insert(new Param2<string, int>("DuctTape", 1));
		recipe.results.Insert(new Param2<string, int>("RepairedVehiclePart", 1));
		recipe.craftingTime = 15.0;
		recipe.xpReward = 20;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreateTireChangeRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "TireChange";
		recipe.displayName = "Tire Change";
		recipe.description = "Change a vehicle's tire.";
		recipe.skillType = SkillTypes.MECHANIC;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("DamagedTire", 1));
		recipe.ingredients.Insert(new Param2<string, int>("TireRepairKit", 1));
		recipe.results.Insert(new Param2<string, int>("Tire", 1));
		recipe.craftingTime = 10.0;
		recipe.xpReward = 15;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	// Medic Recipes
	void CreateBasicBandageRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "BasicBandage";
		recipe.displayName = "Basic Bandage";
		recipe.description = "Craft a basic bandage for treating wounds.";
		recipe.skillType = SkillTypes.MEDIC;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("Rag", 4));
		recipe.ingredients.Insert(new Param2<string, int>("Disinfectant", 1));
		recipe.results.Insert(new Param2<string, int>("Bandage", 2));
		recipe.craftingTime = 5.0;
		recipe.xpReward = 10;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreateHerbalTeaRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "HerbalTea";
		recipe.displayName = "Herbal Tea";
		recipe.description = "Brew herbal tea with medicinal properties.";
		recipe.skillType = SkillTypes.MEDIC;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("PlantMaterial", 2));
		recipe.ingredients.Insert(new Param2<string, int>("Water", 1));
		recipe.results.Insert(new Param2<string, int>("HerbalTea", 1));
		recipe.craftingTime = 5.0;
		recipe.xpReward = 10;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	// Hunter Recipes
	void CreateBasicButcheringRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "BasicButchering";
		recipe.displayName = "Basic Butchering";
		recipe.description = "Butcher an animal carcass for meat.";
		recipe.skillType = SkillTypes.HUNTER;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("AnimalCarcass", 1));
		recipe.results.Insert(new Param2<string, int>("Meat", 4));
		recipe.results.Insert(new Param2<string, int>("AnimalPelt", 1));
		recipe.craftingTime = 10.0;
		recipe.xpReward = 20;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreateSimpleSnareRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "SimpleSnare";
		recipe.displayName = "Simple Snare";
		recipe.description = "Craft a simple snare trap for catching small animals.";
		recipe.skillType = SkillTypes.HUNTER;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("Rope", 1));
		recipe.ingredients.Insert(new Param2<string, int>("Stick", 2));
		recipe.results.Insert(new Param2<string, int>("SimpleSnare", 1));
		recipe.craftingTime = 5.0;
		recipe.xpReward = 10;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	// Cook Recipes
	void CreateBasicCookingRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "BasicCooking";
		recipe.displayName = "Basic Cooking";
		recipe.description = "Cook raw meat into a nutritious meal.";
		recipe.skillType = SkillTypes.COOK;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("Meat", 1));
		recipe.ingredients.Insert(new Param2<string, int>("Water", 1));
		recipe.results.Insert(new Param2<string, int>("CookedMeat", 1));
		recipe.craftingTime = 5.0;
		recipe.xpReward = 10;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	void CreateSimplePreservationRecipe()
	{
		ref SkillRecipeData recipe = new SkillRecipeData();
		recipe.recipeName = "SimplePreservation";
		recipe.displayName = "Simple Food Preservation";
		recipe.description = "Preserve food to extend its shelf life.";
		recipe.skillType = SkillTypes.COOK;
		recipe.requiredLevel = 1;
		recipe.ingredients.Insert(new Param2<string, int>("Meat", 1));
		recipe.ingredients.Insert(new Param2<string, int>("Salt", 1));
		recipe.results.Insert(new Param2<string, int>("DriedMeat", 1));
		recipe.craftingTime = 15.0;
		recipe.xpReward = 15;
		
		m_Recipes.Set(recipe.recipeName, recipe);
	}

	// Get a recipe by name
	ref SkillRecipeData GetRecipe(string recipeName)
	{
		// Check if initialized
		if (!m_Initialized)
		{
			DebugLog("WARNING: GetRecipe called before initialization, initializing now...");
			Init();
		}
		
		if (m_Recipes.Contains(recipeName))
		{
			return m_Recipes.Get(recipeName);
		}
		
		DebugLog("Recipe not found: " + recipeName);
		return null;
	}

	// Custom string conversion to lowercase
	private string ConvertToLowerCase(string input)
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

	// Get all recipes for a skill type
	array<ref SkillRecipeData> GetRecipesForSkill(string skillType)
	{
		// Check if initialized
		if (!m_Initialized)
		{
			DebugLog("WARNING: GetRecipesForSkill called before initialization, initializing now...");
			Init();
		}
		
		array<ref SkillRecipeData> recipes = new array<ref SkillRecipeData>();
		
		// Debug log
		DebugLog("Getting recipes for skill type: '" + skillType + "'");
		
		// Try case-sensitive match first
		int exactMatchCount = 0;
		foreach (string recipeNameExact, ref SkillRecipeData recipeExact : m_Recipes)
		{
			if (recipeExact.skillType == skillType)
			{
				recipes.Insert(recipeExact);
				exactMatchCount++;
			}
		}
		
		DebugLog("Found " + exactMatchCount + " recipes with exact match for skill type: '" + skillType + "'");
		
		// If no exact matches, try case-insensitive match
		if (exactMatchCount == 0)
		{
			DebugLog("No exact matches, trying case-insensitive match for: '" + skillType + "'");
			
			string lowerSkillTypeStr = ConvertToLowerCase(skillType);
			foreach (string recipeNameLower, ref SkillRecipeData recipeLower : m_Recipes)
			{
				string lowerRecipeSkillType = ConvertToLowerCase(recipeLower.skillType);
				if (lowerRecipeSkillType == lowerSkillTypeStr)
				{
					recipes.Insert(recipeLower);
					DebugLog("Found case-insensitive match: '" + recipeLower.skillType + "' for '" + skillType + "'");
				}
			}
			
			DebugLog("Found " + recipes.Count() + " recipes with case-insensitive match");
		}
		
		// Check if we found any recipes
		if (recipes.Count() == 0)
		{
			// Check if this is a valid skill type
			bool isValidSkillType = false;
			array<string> skillTypes = SkillTypes.GetAllTypes();
			foreach (string typeCheck : skillTypes)
			{
				if (typeCheck == skillType)
				{
					isValidSkillType = true;
					break;
				}
			}
			
			if (!isValidSkillType)
			{
				DebugLog("WARNING: Invalid skill type: '" + skillType + "'");
				DebugLog("Valid skill types are:");
				foreach (string typeList : skillTypes)
				{
					DebugLog("  - '" + typeList + "'");
				}
			}
		}
		
		return recipes;
	}

	// Get recipes for a specific skill level
	array<ref SkillRecipeData> GetRecipesForSkillLevel(string skillType, int level)
	{
		// Check if initialized
		if (!m_Initialized)
		{
			DebugLog("WARNING: GetRecipesForSkillLevel called before initialization, initializing now...");
			Init();
		}
		
		array<ref SkillRecipeData> recipes = new array<ref SkillRecipeData>();
		
		foreach (string recipeNameLevel, ref SkillRecipeData recipeLevel : m_Recipes)
		{
			if (recipeLevel.skillType == skillType && recipeLevel.requiredLevel == level)
			{
				recipes.Insert(recipeLevel);
			}
		}
		
		return recipes;
	}

	// Award XP for crafting a recipe
	void AwardRecipeXP(PlayerBase player, string recipeName)
	{
		if (!GetGame().IsServer() || !player)
			return;
			
		ref SkillRecipeData recipe = GetRecipe(recipeName);
		if (recipe)
		{
			// Use the XP events system to award XP
			SkillXPEvents.AwardRecipeXP(player, recipeName, recipe.xpReward, recipe.skillType);
		}
	}

	// Debug logging
	private void DebugLog(string message)
	{
		if (m_Debug)
		{
			Print("[SausageSkillsRecipeManager] " + message);
		}
	}

	// Log recipes per skill type
	private void LogRecipesPerSkillType()
	{
		if (!m_Debug)
			return;
			
		DebugLog("Logging recipes per skill type:");
		
		// Get all skill types
		array<string> skillTypes = SkillTypes.GetAllTypes();
		
		// Count recipes for each skill type
		foreach (string skillTypeLog : skillTypes)
		{
			int count = 0;
			foreach (string recipeNameCount, ref SkillRecipeData recipeCount : m_Recipes)
			{
				if (recipeCount.skillType == skillTypeLog)
				{
					count++;
				}
			}
			
			DebugLog("  - Skill type '" + skillTypeLog + "' has " + count + " recipes");
		}
	}

	// Check if initialized
	bool IsInitialized()
	{
		return m_Initialized;
	}

	// Get total recipe count
	int GetTotalRecipeCount()
	{
		return m_Recipes.Count();
	}

	// Force reinitialization
	void ForceReinit()
	{
		DebugLog("Forcing reinitialization of recipe manager");
		m_Recipes.Clear();
		m_Initialized = false;
		Init();
	}

}