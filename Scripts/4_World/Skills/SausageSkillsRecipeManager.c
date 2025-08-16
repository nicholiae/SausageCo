/*
 * SausageCo Skills System
 * Recipe Manager
 */

class SausageSkillsRecipeManager
{
    // Recipe database
    private ref map<string, ref SkillRecipeData> m_Recipes;
    
    void SausageSkillsRecipeManager()
    {
        m_Recipes = new map<string, ref SkillRecipeData>();
    }
    
    void Init()
    {
        Print("[SausageSkills] Initializing Recipe Manager");
        
        // Create default recipes
        CreateDefaultRecipes();
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
        
        Print("[SausageSkills] Created " + m_Recipes.Count() + " recipes");
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
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateBasicShelterRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "BasicShelter";
        recipe.displayName = "Basic Shelter";
        recipe.description = "A simple shelter for protection from the elements.";
        recipe.skillType = SkillTypes.ENGINEERING;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 6));
        recipe.ingredients.Insert(new Param2<string, int>("Rope", 2));
        recipe.results.Insert(new Param2<string, int>("ShelterKit", 1));
        recipe.craftingTime = 30.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateImprovedShelterRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "ImprovedShelter";
        recipe.displayName = "Improved Shelter";
        recipe.description = "A more durable shelter with better protection.";
        recipe.skillType = SkillTypes.ENGINEERING;
        recipe.requiredLevel = 2;
        recipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 10));
        recipe.ingredients.Insert(new Param2<string, int>("Rope", 3));
        recipe.ingredients.Insert(new Param2<string, int>("Nail", 20));
        recipe.results.Insert(new Param2<string, int>("ImprovedShelterKit", 1));
        recipe.craftingTime = 60.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateWoodenCrateRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "WoodenCrate";
        recipe.displayName = "Wooden Crate";
        recipe.description = "A storage container for your items.";
        recipe.skillType = SkillTypes.ENGINEERING;
        recipe.requiredLevel = 2;
        recipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 8));
        recipe.ingredients.Insert(new Param2<string, int>("Nail", 16));
        recipe.results.Insert(new Param2<string, int>("WoodenCrate", 1));
        recipe.craftingTime = 20.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateMiningFurnaceRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "MiningFurnace";
        recipe.displayName = "Mining Furnace";
        recipe.description = "A furnace for smelting ore into metal.";
        recipe.skillType = SkillTypes.ENGINEERING;
        recipe.requiredLevel = 3;
        recipe.ingredients.Insert(new Param2<string, int>("Stone", 20));
        recipe.ingredients.Insert(new Param2<string, int>("Firewood", 10));
        recipe.ingredients.Insert(new Param2<string, int>("MetalWire", 2));
        recipe.results.Insert(new Param2<string, int>("SausageFurnace", 1));
        recipe.craftingTime = 90.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateWorkBenchRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "WorkBench";
        recipe.displayName = "Work Bench";
        recipe.description = "A crafting station for advanced projects.";
        recipe.skillType = SkillTypes.ENGINEERING;
        recipe.requiredLevel = 3;
        recipe.ingredients.Insert(new Param2<string, int>("WoodenPlank", 12));
        recipe.ingredients.Insert(new Param2<string, int>("Nail", 24));
        recipe.ingredients.Insert(new Param2<string, int>("MetalPlate", 2));
        recipe.results.Insert(new Param2<string, int>("WorkBench", 1));
        recipe.craftingTime = 60.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    // Farming Recipes
    void CreatePlantTomatoRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "PlantTomato";
        recipe.displayName = "Tomato Seeds";
        recipe.description = "Seeds for growing tomato plants.";
        recipe.skillType = SkillTypes.FARMING;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("Tomato", 1));
        recipe.results.Insert(new Param2<string, int>("TomatoSeeds", 5));
        recipe.craftingTime = 5.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreatePlantZucchiniRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "PlantZucchini";
        recipe.displayName = "Zucchini Seeds";
        recipe.description = "Seeds for growing zucchini plants.";
        recipe.skillType = SkillTypes.FARMING;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("Zucchini", 1));
        recipe.results.Insert(new Param2<string, int>("ZucchiniSeeds", 5));
        recipe.craftingTime = 5.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreatePlantPumpkinRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "PlantPumpkin";
        recipe.displayName = "Pumpkin Seeds";
        recipe.description = "Seeds for growing pumpkin plants.";
        recipe.skillType = SkillTypes.FARMING;
        recipe.requiredLevel = 2;
        recipe.ingredients.Insert(new Param2<string, int>("Pumpkin", 1));
        recipe.results.Insert(new Param2<string, int>("PumpkinSeeds", 10));
        recipe.craftingTime = 5.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateImprovedCompostRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "ImprovedCompost";
        recipe.displayName = "Improved Compost";
        recipe.description = "Better fertilizer for your crops.";
        recipe.skillType = SkillTypes.FARMING;
        recipe.requiredLevel = 2;
        recipe.ingredients.Insert(new Param2<string, int>("Rags", 4));
        recipe.ingredients.Insert(new Param2<string, int>("PlantMaterial", 8));
        recipe.results.Insert(new Param2<string, int>("ImprovedCompost", 1));
        recipe.craftingTime = 30.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    // Firearm Recipes
    void CreateBasicAmmoRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "BasicAmmo";
        recipe.displayName = "Basic Ammunition";
        recipe.description = "Simple ammunition for firearms.";
        recipe.skillType = SkillTypes.FIREARM;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("GunPowder", 10));
        recipe.ingredients.Insert(new Param2<string, int>("MetalPlate", 1));
        recipe.results.Insert(new Param2<string, int>("Ammo_9x19", 20));
        recipe.craftingTime = 30.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateWeaponCleaningRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "WeaponCleaning";
        recipe.displayName = "Weapon Cleaning Kit";
        recipe.description = "A kit for maintaining your firearms.";
        recipe.skillType = SkillTypes.FIREARM;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("Rag", 4));
        recipe.ingredients.Insert(new Param2<string, int>("WaterBottle", 1));
        recipe.results.Insert(new Param2<string, int>("WeaponCleaningKit", 1));
        recipe.craftingTime = 15.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateImprovedAmmoRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "ImprovedAmmo";
        recipe.displayName = "Improved Ammunition";
        recipe.description = "Better ammunition with increased damage.";
        recipe.skillType = SkillTypes.FIREARM;
        recipe.requiredLevel = 2;
        recipe.ingredients.Insert(new Param2<string, int>("GunPowder", 15));
        recipe.ingredients.Insert(new Param2<string, int>("MetalPlate", 2));
        recipe.results.Insert(new Param2<string, int>("Ammo_308Win", 10));
        recipe.craftingTime = 45.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    // Leather Recipes
    void CreateBasicTanningRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "BasicTanning";
        recipe.displayName = "Basic Tanning";
        recipe.description = "Process animal hides into leather.";
        recipe.skillType = SkillTypes.LEATHER;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("AnimalPelt", 1));
        recipe.ingredients.Insert(new Param2<string, int>("WaterBottle", 1));
        recipe.results.Insert(new Param2<string, int>("Leather", 2));
        recipe.craftingTime = 60.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateLeatherPouchRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "LeatherPouch";
        recipe.displayName = "Leather Pouch";
        recipe.description = "A small container for storing items.";
        recipe.skillType = SkillTypes.LEATHER;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("Leather", 2));
        recipe.ingredients.Insert(new Param2<string, int>("Rope", 1));
        recipe.results.Insert(new Param2<string, int>("LeatherSack", 1));
        recipe.craftingTime = 20.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    // Mechanic Recipes
    void CreateBasicRepairRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "BasicRepair";
        recipe.displayName = "Basic Repair Kit";
        recipe.description = "A kit for basic vehicle repairs.";
        recipe.skillType = SkillTypes.MECHANIC;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("MetalPlate", 2));
        recipe.ingredients.Insert(new Param2<string, int>("Duct Tape", 1));
        recipe.results.Insert(new Param2<string, int>("RepairKit", 1));
        recipe.craftingTime = 30.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateTireChangeRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "TireChange";
        recipe.displayName = "Tire Repair Kit";
        recipe.description = "A kit for repairing damaged tires.";
        recipe.skillType = SkillTypes.MECHANIC;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("Duct Tape", 2));
        recipe.ingredients.Insert(new Param2<string, int>("Rubber", 1));
        recipe.results.Insert(new Param2<string, int>("TireRepairKit", 1));
        recipe.craftingTime = 20.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    // Medic Recipes
    void CreateBasicBandageRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "BasicBandage";
        recipe.displayName = "Basic Bandage";
        recipe.description = "A simple bandage for treating wounds.";
        recipe.skillType = SkillTypes.MEDIC;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("Rag", 4));
        recipe.ingredients.Insert(new Param2<string, int>("Disinfectant", 1));
        recipe.results.Insert(new Param2<string, int>("BandageDressing", 2));
        recipe.craftingTime = 10.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateHerbalTeaRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "HerbalTea";
        recipe.displayName = "Herbal Tea";
        recipe.description = "A medicinal tea that helps with minor ailments.";
        recipe.skillType = SkillTypes.MEDIC;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("PlantMaterial", 5));
        recipe.ingredients.Insert(new Param2<string, int>("WaterBottle", 1));
        recipe.results.Insert(new Param2<string, int>("HerbalTea", 1));
        recipe.craftingTime = 15.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    // Hunter Recipes
    void CreateBasicButcheringRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "BasicButchering";
        recipe.displayName = "Basic Butchering";
        recipe.description = "Efficiently process animal carcasses.";
        recipe.skillType = SkillTypes.HUNTER;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("AnimalCarcass", 1));
        recipe.results.Insert(new Param2<string, int>("Meat", 5));
        recipe.results.Insert(new Param2<string, int>("AnimalPelt", 1));
        recipe.craftingTime = 30.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateSimpleSnareRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "SimpleSnare";
        recipe.displayName = "Simple Snare";
        recipe.description = "A trap for catching small animals.";
        recipe.skillType = SkillTypes.HUNTER;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("Rope", 2));
        recipe.ingredients.Insert(new Param2<string, int>("WoodenStick", 3));
        recipe.results.Insert(new Param2<string, int>("RabbitSnare", 1));
        recipe.craftingTime = 15.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    // Cook Recipes
    void CreateBasicCookingRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "BasicCooking";
        recipe.displayName = "Basic Cooking";
        recipe.description = "Prepare a nutritious meal.";
        recipe.skillType = SkillTypes.COOK;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("Meat", 2));
        recipe.ingredients.Insert(new Param2<string, int>("Potato", 2));
        recipe.results.Insert(new Param2<string, int>("CookedMeal", 1));
        recipe.craftingTime = 20.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    void CreateSimplePreservationRecipe()
    {
        ref SkillRecipeData recipe = new SkillRecipeData();
        recipe.recipeName = "SimplePreservation";
        recipe.displayName = "Simple Preservation";
        recipe.description = "Preserve food for longer storage.";
        recipe.skillType = SkillTypes.COOK;
        recipe.requiredLevel = 1;
        recipe.ingredients.Insert(new Param2<string, int>("Meat", 3));
        recipe.ingredients.Insert(new Param2<string, int>("Salt", 1));
        recipe.results.Insert(new Param2<string, int>("DriedMeat", 3));
        recipe.craftingTime = 60.0;
        
        m_Recipes.Set(recipe.recipeName, recipe);
    }
    
    // Get a recipe by name
    ref SkillRecipeData GetRecipe(string recipeName)
    {
        if (m_Recipes.Contains(recipeName))
        {
            return m_Recipes.Get(recipeName);
        }
        
        return null;
    }
    
    // Get all recipes for a skill type
    array<ref SkillRecipeData> GetRecipesForSkill(string skillType)
    {
        array<ref SkillRecipeData> recipes = new array<ref SkillRecipeData>();
        
        foreach (string recipeName, ref SkillRecipeData recipe : m_Recipes)
        {
            if (recipe.skillType == skillType)
            {
                recipes.Insert(recipe);
            }
        }
        
        return recipes;
    }
    
    // Get recipes for a specific skill level
    array<ref SkillRecipeData> GetRecipesForSkillLevel(string skillType, int level)
    {
        array<ref SkillRecipeData> recipes = new array<ref SkillRecipeData>();
        
        foreach (string recipeName, ref SkillRecipeData recipe : m_Recipes)
        {
            if (recipe.skillType == skillType && recipe.requiredLevel == level)
            {
                recipes.Insert(recipe);
            }
        }
        
        return recipes;
    }
}