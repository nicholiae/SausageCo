/*
 * SausageCo Skills System
 * XP Integration with Game Actions
 */

// Integration with crafting system
modded class PluginRecipesManager
{
    override void OnRecipeSelected(int recipe_id, PlayerBase player)
    {
        super.OnRecipeSelected(recipe_id, player);
        
        // Get the recipe
        Recipe recipe = GetRecipeByID(recipe_id);
        if (recipe && player)
        {
            // Get ingredients and results
            array<ItemBase> ingredients = new array<ItemBase>();
            array<ItemBase> results = new array<ItemBase>();
            
            // Collect ingredients
            for (int i = 0; i < recipe.GetIngredientsCount(); i++)
            {
                ItemBase ingredient = ItemBase.Cast(recipe.GetIngredientItem(i));
                if (ingredient)
                {
                    ingredients.Insert(ingredient);
                }
            }
            
            // Collect results
            for (int j = 0; j < recipe.GetResultsCount(); j++)
            {
                ItemBase result = ItemBase.Cast(recipe.GetResultItem(j));
                if (result)
                {
                    results.Insert(result);
                }
            }
            
            // Trigger XP event
            GetDayZGame().Event_OnRecipePerformed.Invoke(player, recipe_id, ingredients, results);
        }
    }
}

// Integration with building system
modded class Construction
{
    override void ConstructionComplete(int id, string part_name, PlayerBase player)
    {
        super.ConstructionComplete(id, part_name, player);
        
        // Trigger XP event
        GetDayZGame().Event_OnBuildPartPlaced.Invoke(player, part_name);
    }
    
    override void DeconstructionComplete(int id, string part_name, PlayerBase player)
    {
        super.DeconstructionComplete(id, part_name, player);
        
        // Trigger XP event
        GetDayZGame().Event_OnDismantleFinished.Invoke(player, part_name);
    }
}

// Integration with medical system
modded class ActionBandageBase
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        
        // Trigger XP event
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        PlayerBase target = PlayerBase.Cast(action_data.m_Target.GetObject());
        
        if (player && target)
        {
            GetDayZGame().Event_OnMedicalActionPerformed.Invoke(player, target, "bandage");
        }
    }
}

modded class ActionGiveSalineSelf
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        
        // Trigger XP event
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        
        if (player)
        {
            GetDayZGame().Event_OnMedicalActionPerformed.Invoke(player, player, "saline");
        }
    }
}

// Integration with hunting system
modded class Animal
{
    override void EEKilled(Object killer)
    {
        super.EEKilled(killer);
        
        // Trigger XP event
        GetDayZGame().Event_OnEntityKilled.Invoke(this, killer);
    }
}

modded class ActionButcherBody
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        
        // Trigger XP event
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        EntityAI target = EntityAI.Cast(action_data.m_Target.GetObject());
        
        if (player && target)
        {
            GetDayZGame().Event_OnItemButchered.Invoke(player, target);
        }
    }
}

// Integration with farming system
modded class ActionPlantSeed
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        
        // Trigger XP event
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        ItemBase seed = ItemBase.Cast(action_data.m_MainItem);
        ItemBase garden = ItemBase.Cast(action_data.m_Target.GetObject());
        
        if (player && seed && garden)
        {
            GetDayZGame().Event_OnPlantSeed.Invoke(player, seed, garden);
        }
    }
}

modded class ActionHarvestCrops
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        
        // Trigger XP event
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        ItemBase plant = ItemBase.Cast(action_data.m_Target.GetObject());
        
        if (player && plant)
        {
            GetDayZGame().Event_OnHarvestPlant.Invoke(player, plant);
        }
    }
}

// Integration with firearm system
modded class Weapon_Base
{
    override void OnFire(int muzzle_index)
    {
        super.OnFire(muzzle_index);
        
        // Trigger XP event
        PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
        
        if (player)
        {
            GetDayZGame().Event_OnWeaponFired.Invoke(player, this);
        }
    }
}

modded class ActionCleanWeapon
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        
        // Trigger XP event
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        Weapon_Base weapon = Weapon_Base.Cast(action_data.m_MainItem);
        
        if (player && weapon)
        {
            GetDayZGame().Event_OnWeaponCleaned.Invoke(player, weapon);
        }
    }
}

// Integration with mechanic system
modded class ActionRepairCarPart
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        
        // Trigger XP event
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        Transport vehicle = Transport.Cast(action_data.m_Target.GetParent());
        
        if (player && vehicle)
        {
            GetDayZGame().Event_OnVehicleRepaired.Invoke(player, vehicle);
        }
    }
}

modded class ActionAttachCarWheel
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        
        // Trigger XP event
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        Transport vehicle = Transport.Cast(action_data.m_Target.GetParent());
        
        if (player && vehicle)
        {
            GetDayZGame().Event_OnVehiclePartAttached.Invoke(player, vehicle, "wheel");
        }
    }
}

// Integration with leather system
modded class ActionTanPelt
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        
        // Trigger XP event
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        ItemBase hide = ItemBase.Cast(action_data.m_MainItem);
        ItemBase leather = ItemBase.Cast(action_data.m_Target.GetObject());
        
        if (player && hide && leather)
        {
            GetDayZGame().Event_OnItemTanned.Invoke(player, hide, leather);
        }
    }
}

// Integration with cooking system
modded class ActionCookOnStick
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        
        // Trigger XP event
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        ItemBase food = ItemBase.Cast(action_data.m_MainItem);
        
        if (player && food)
        {
            GetDayZGame().Event_OnItemCooked.Invoke(player, food);
        }
    }
}

modded class ActionCookOnStove
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        
        // Trigger XP event
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        ItemBase food = ItemBase.Cast(action_data.m_MainItem);
        
        if (player && food)
        {
            GetDayZGame().Event_OnItemCooked.Invoke(player, food);
        }
    }
}