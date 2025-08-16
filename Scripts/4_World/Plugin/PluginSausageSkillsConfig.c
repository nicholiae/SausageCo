/*
 * SausageCo Skills System
 * Skills Configuration Plugin
 */

class PluginSausageSkillsConfig extends PluginBase
{
    private const static string CONFIG_FOLDER = "$profile:Sausage\\Skills\\";
    private const static string CONFIG_FILE = CONFIG_FOLDER + "skills_config.json";
    
    ref map<string, ref SkillTypeConfig> m_SkillTypes;
    
    override void OnInit()
    {
        Print("[SausageSkills] PluginSausageSkillsConfig::OnInit()");
        
        // Initialize skill types
        m_SkillTypes = new map<string, ref SkillTypeConfig>();
        
        // Load or create config
        if (!FileExist(CONFIG_FILE))
        {
            // Create default config
            CreateDefaultConfig();
            SaveConfig();
        }
        else
        {
            // Load existing config
            LoadConfig();
        }
    }
    
    void CreateDefaultConfig()
    {
        Print("[SausageSkills] Creating default skills configuration");
        
        // Engineering skill
        ref SkillTypeConfig engineering = new SkillTypeConfig();
        engineering.displayName = "Engineering";
        engineering.description = "Building and construction skills. Craft structures, process materials, and build advanced items.";
        engineering.icon = "SausageCo\\GUI\\images\\skills\\engineering.paa";
        
        // XP requirements for each level (0-10)
        engineering.levelXpRequirements = {0, 1000, 2500, 4500, 7000, 10000, 15000, 21000, 28000, 36000, 45000};
        
        // Recipes unlocked at each level
        ref array<string> engLevel1 = {"WoodenPlank", "BasicShelter"};
        ref array<string> engLevel2 = {"ImprovedShelter", "WoodenCrate"};
        ref array<string> engLevel3 = {"MiningFurnace", "WorkBench"};
        ref array<string> engLevel4 = {"AdvancedWorkbench", "MetalStorage"};
        ref array<string> engLevel5 = {"GeneratorSystem", "ElectricalComponents"};
        
        engineering.levelRecipes = new map<int, ref array<string>>();
        engineering.levelRecipes.Set(1, engLevel1);
        engineering.levelRecipes.Set(2, engLevel2);
        engineering.levelRecipes.Set(3, engLevel3);
        engineering.levelRecipes.Set(4, engLevel4);
        engineering.levelRecipes.Set(5, engLevel5);
        
        m_SkillTypes.Set(SkillTypes.ENGINEERING, engineering);
        
        // Farming skill
        ref SkillTypeConfig farming = new SkillTypeConfig();
        farming.displayName = "Farming";
        farming.description = "Growing and harvesting crops. Increase yield, grow special plants, and create advanced fertilizers.";
        farming.icon = "SausageCo\\GUI\\images\\skills\\farming.paa";
        
        farming.levelXpRequirements = {0, 1000, 2500, 4500, 7000, 10000, 15000, 21000, 28000, 36000, 45000};
        
        ref array<string> farmLevel1 = {"PlantTomato", "PlantZucchini"};
        ref array<string> farmLevel2 = {"PlantPumpkin", "ImprovedCompost"};
        ref array<string> farmLevel3 = {"PlantCannabis", "AdvancedFertilizer"};
        ref array<string> farmLevel4 = {"PlantTobacco", "HydroponicSystem"};
        ref array<string> farmLevel5 = {"PlantMedicinalHerbs", "AutomatedIrrigation"};
        
        farming.levelRecipes = new map<int, ref array<string>>();
        farming.levelRecipes.Set(1, farmLevel1);
        farming.levelRecipes.Set(2, farmLevel2);
        farming.levelRecipes.Set(3, farmLevel3);
        farming.levelRecipes.Set(4, farmLevel4);
        farming.levelRecipes.Set(5, farmLevel5);
        
        m_SkillTypes.Set(SkillTypes.FARMING, farming);
        
        // Firearm skill
        ref SkillTypeConfig firearm = new SkillTypeConfig();
        firearm.displayName = "Firearms";
        firearm.description = "Weapon crafting and maintenance. Create ammunition, repair weapons, and craft weapon attachments.";
        firearm.icon = "SausageCo\\GUI\\images\\skills\\firearm.paa";
        
        firearm.levelXpRequirements = {0, 1000, 2500, 4500, 7000, 10000, 15000, 21000, 28000, 36000, 45000};
        
        ref array<string> firearmLevel1 = {"BasicAmmo", "WeaponCleaning"};
        ref array<string> firearmLevel2 = {"ImprovedAmmo", "BasicAttachments"};
        ref array<string> firearmLevel3 = {"AdvancedAmmo", "WeaponRepair"};
        ref array<string> firearmLevel4 = {"SpecialAmmo", "AdvancedAttachments"};
        ref array<string> firearmLevel5 = {"CustomAmmo", "WeaponModification"};
        
        firearm.levelRecipes = new map<int, ref array<string>>();
        firearm.levelRecipes.Set(1, firearmLevel1);
        firearm.levelRecipes.Set(2, firearmLevel2);
        firearm.levelRecipes.Set(3, firearmLevel3);
        firearm.levelRecipes.Set(4, firearmLevel4);
        firearm.levelRecipes.Set(5, firearmLevel5);
        
        m_SkillTypes.Set(SkillTypes.FIREARM, firearm);
        
        // Leather skill
        ref SkillTypeConfig leather = new SkillTypeConfig();
        leather.displayName = "Leatherworking";
        leather.description = "Processing animal hides and crafting leather items. Create clothing, storage, and specialized gear.";
        leather.icon = "SausageCo\\GUI\\images\\skills\\leather.paa";
        
        leather.levelXpRequirements = {0, 1000, 2500, 4500, 7000, 10000, 15000, 21000, 28000, 36000, 45000};
        
        ref array<string> leatherLevel1 = {"BasicTanning", "LeatherPouch"};
        ref array<string> leatherLevel2 = {"ImprovedTanning", "LeatherClothing"};
        ref array<string> leatherLevel3 = {"AdvancedTanning", "LeatherStorage"};
        ref array<string> leatherLevel4 = {"SpecializedLeather", "LeatherArmor"};
        ref array<string> leatherLevel5 = {"MasterLeatherwork", "SpecializedGear"};
        
        leather.levelRecipes = new map<int, ref array<string>>();
        leather.levelRecipes.Set(1, leatherLevel1);
        leather.levelRecipes.Set(2, leatherLevel2);
        leather.levelRecipes.Set(3, leatherLevel3);
        leather.levelRecipes.Set(4, leatherLevel4);
        leather.levelRecipes.Set(5, leatherLevel5);
        
        m_SkillTypes.Set(SkillTypes.LEATHER, leather);
        
        // Mechanic skill
        ref SkillTypeConfig mechanic = new SkillTypeConfig();
        mechanic.displayName = "Mechanics";
        mechanic.description = "Vehicle repair and modification. Maintain engines, improve performance, and craft vehicle parts.";
        mechanic.icon = "SausageCo\\GUI\\images\\skills\\mechanic.paa";
        
        mechanic.levelXpRequirements = {0, 1000, 2500, 4500, 7000, 10000, 15000, 21000, 28000, 36000, 45000};
        
        ref array<string> mechanicLevel1 = {"BasicRepair", "TireChange"};
        ref array<string> mechanicLevel2 = {"EngineRepair", "FuelEfficiency"};
        ref array<string> mechanicLevel3 = {"TransmissionRepair", "VehicleArmoring"};
        ref array<string> mechanicLevel4 = {"PerformanceTuning", "CustomParts"};
        ref array<string> mechanicLevel5 = {"VehicleModification", "SpecializedSystems"};
        
        mechanic.levelRecipes = new map<int, ref array<string>>();
        mechanic.levelRecipes.Set(1, mechanicLevel1);
        mechanic.levelRecipes.Set(2, mechanicLevel2);
        mechanic.levelRecipes.Set(3, mechanicLevel3);
        mechanic.levelRecipes.Set(4, mechanicLevel4);
        mechanic.levelRecipes.Set(5, mechanicLevel5);
        
        m_SkillTypes.Set(SkillTypes.MECHANIC, mechanic);
        
        // Medic skill
        ref SkillTypeConfig medic = new SkillTypeConfig();
        medic.displayName = "Medicine";
        medic.description = "Medical treatment and pharmaceutical crafting. Create medicines, treat injuries, and craft medical supplies.";
        medic.icon = "SausageCo\\GUI\\images\\skills\\medic.paa";
        
        medic.levelXpRequirements = {0, 1000, 2500, 4500, 7000, 10000, 15000, 21000, 28000, 36000, 45000};
        
        ref array<string> medicLevel1 = {"BasicBandage", "HerbalTea"};
        ref array<string> medicLevel2 = {"ImprovedBandage", "PainMedication"};
        ref array<string> medicLevel3 = {"AntibioticProduction", "BloodBagPreparation"};
        ref array<string> medicLevel4 = {"AdvancedMedication", "SurgicalKit"};
        ref array<string> medicLevel5 = {"SpecializedTreatment", "EmergencySupplies"};
        
        medic.levelRecipes = new map<int, ref array<string>>();
        medic.levelRecipes.Set(1, medicLevel1);
        medic.levelRecipes.Set(2, medicLevel2);
        medic.levelRecipes.Set(3, medicLevel3);
        medic.levelRecipes.Set(4, medicLevel4);
        medic.levelRecipes.Set(5, medicLevel5);
        
        m_SkillTypes.Set(SkillTypes.MEDIC, medic);
        
        // Hunter skill
        ref SkillTypeConfig hunter = new SkillTypeConfig();
        hunter.displayName = "Hunting";
        hunter.description = "Animal tracking and processing. Improve meat yield, craft hunting tools, and create specialized traps.";
        hunter.icon = "SausageCo\\GUI\\images\\skills\\hunter.paa";
        
        hunter.levelXpRequirements = {0, 1000, 2500, 4500, 7000, 10000, 15000, 21000, 28000, 36000, 45000};
        
        ref array<string> hunterLevel1 = {"BasicButchering", "SimpleSnare"};
        ref array<string> hunterLevel2 = {"ImprovedButchering", "HuntingKnife"};
        ref array<string> hunterLevel3 = {"AdvancedButchering", "ComplexTraps"};
        ref array<string> hunterLevel4 = {"TrophyCollection", "SpecializedBait"};
        ref array<string> hunterLevel5 = {"MasterButchering", "HuntingBlind"};
        
        hunter.levelRecipes = new map<int, ref array<string>>();
        hunter.levelRecipes.Set(1, hunterLevel1);
        hunter.levelRecipes.Set(2, hunterLevel2);
        hunter.levelRecipes.Set(3, hunterLevel3);
        hunter.levelRecipes.Set(4, hunterLevel4);
        hunter.levelRecipes.Set(5, hunterLevel5);
        
        m_SkillTypes.Set(SkillTypes.HUNTER, hunter);
        
        // Cook skill
        ref SkillTypeConfig cook = new SkillTypeConfig();
        cook.displayName = "Cooking";
        cook.description = "Food preparation and preservation. Create nutritious meals, preserve food, and craft specialized dishes.";
        cook.icon = "SausageCo\\GUI\\images\\skills\\cook.paa";
        
        cook.levelXpRequirements = {0, 1000, 2500, 4500, 7000, 10000, 15000, 21000, 28000, 36000, 45000};
        
        ref array<string> cookLevel1 = {"BasicCooking", "SimplePreservation"};
        ref array<string> cookLevel2 = {"ImprovedCooking", "AdvancedPreservation"};
        ref array<string> cookLevel3 = {"GourmetCooking", "Fermentation"};
        ref array<string> cookLevel4 = {"SpecializedDishes", "LongTermPreservation"};
        ref array<string> cookLevel5 = {"MasterCooking", "GourmetPreservation"};
        
        cook.levelRecipes = new map<int, ref array<string>>();
        cook.levelRecipes.Set(1, cookLevel1);
        cook.levelRecipes.Set(2, cookLevel2);
        cook.levelRecipes.Set(3, cookLevel3);
        cook.levelRecipes.Set(4, cookLevel4);
        cook.levelRecipes.Set(5, cookLevel5);
        
        m_SkillTypes.Set(SkillTypes.COOK, cook);
    }
    
    void LoadConfig()
    {
        JsonFileLoader<PluginSausageSkillsConfig>.JsonLoadFile(CONFIG_FILE, this);
        Print("[SausageSkills] Loaded skills configuration with " + m_SkillTypes.Count() + " skill types");
    }
    
    void SaveConfig()
    {
        JsonFileLoader<PluginSausageSkillsConfig>.JsonSaveFile(CONFIG_FILE, this);
        Print("[SausageSkills] Saved skills configuration");
    }
    
    array<string> GetSkillTypes()
    {
        array<string> types = new array<string>();
        
        foreach (string skillType, SkillTypeConfig config : m_SkillTypes)
        {
            types.Insert(skillType);
        }
        
        return types;
    }
    
    int GetXpForLevel(string skillType, int level)
    {
        if (m_SkillTypes.Contains(skillType))
        {
            ref SkillTypeConfig config = m_SkillTypes.Get(skillType);
            
            if (level >= 0 && level < config.levelXpRequirements.Count())
            {
                return config.levelXpRequirements[level];
            }
        }
        
        // Default value if not found
        return level * 1000;
    }
    
    array<string> GetRecipesForLevel(string skillType, int level)
    {
        array<string> recipes = new array<string>();
        
        if (m_SkillTypes.Contains(skillType))
        {
            ref SkillTypeConfig config = m_SkillTypes.Get(skillType);
            
            if (config.levelRecipes.Contains(level))
            {
                recipes = config.levelRecipes.Get(level);
            }
        }
        
        return recipes;
    }
    
    string GetSkillDisplayName(string skillType)
    {
        if (m_SkillTypes.Contains(skillType))
        {
            return m_SkillTypes.Get(skillType).displayName;
        }
        
        return skillType;
    }
    
    string GetSkillDescription(string skillType)
    {
        if (m_SkillTypes.Contains(skillType))
        {
            return m_SkillTypes.Get(skillType).description;
        }
        
        return "";
    }
    
    string GetSkillIcon(string skillType)
    {
        if (m_SkillTypes.Contains(skillType))
        {
            return m_SkillTypes.Get(skillType).icon;
        }
        
        return "";
    }
    
    // Get all recipes for a skill type
    array<string> GetAllRecipesForSkill(string skillType)
    {
        array<string> allRecipes = new array<string>();
        
        if (m_SkillTypes.Contains(skillType))
        {
            ref SkillTypeConfig config = m_SkillTypes.Get(skillType);
            
            foreach (int level, array<string> recipes : config.levelRecipes)
            {
                foreach (string recipe : recipes)
                {
                    allRecipes.Insert(recipe);
                }
            }
        }
        
        return allRecipes;
    }
    
    // Get the level at which a recipe is unlocked
    int GetRecipeLevel(string skillType, string recipeName)
    {
        if (m_SkillTypes.Contains(skillType))
        {
            ref SkillTypeConfig config = m_SkillTypes.Get(skillType);
            
            foreach (int level, array<string> recipes : config.levelRecipes)
            {
                if (recipes.Find(recipeName) != -1)
                {
                    return level;
                }
            }
        }
        
        return -1;
    }
}