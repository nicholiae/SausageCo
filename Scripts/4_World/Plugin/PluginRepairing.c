modded class PluginRepairing extends PluginBase
{	
	override bool Repair(PlayerBase player, ItemBase repair_kit, Object item, float specialty_weight, string damage_zone = "", bool use_kit_qty = true)
	{	
		switch ( item.GetHealthLevel(damage_zone) ) 
		{
			case GameConstants.STATE_PRISTINE:
				break;
			case GameConstants.STATE_RUINED:
				break;
			default:
				CalculateHealth( player, repair_kit, item, specialty_weight, damage_zone, use_kit_qty );
				break;
		}

		return true;
	}

	override void CalculateHealth( PlayerBase player, ItemBase kit, Object item, float specialty_weight, string damage_zone = "", bool use_kit_qty = true )
	{
		bool kit_has_quantity = kit.HasQuantity();
		float cur_kit_quantity = kit.GetQuantity();
		float kit_repair_cost_per_level = GetKitRepairCost( kit, item );
		float kit_repair_cost_adjusted; //used with specialty_weight, disconnected
		float new_quantity;
	
		
		//handles kit depletion; TODO: move to separate method.
		if ( cur_kit_quantity > kit_repair_cost_per_level )
		{
			kit_repair_cost_adjusted = kit_repair_cost_per_level; //TODO: removed speciality weight for now, it should affect speed only (?).
			//kit_repair_cost_adjusted = player.GetSoftSkillsManager().SubtractSpecialtyBonus( kit_repair_cost_per_level, specialty_weight );
			kit_repair_cost_adjusted = Math.Clamp( kit_repair_cost_adjusted, 0, 100 );
			if(use_kit_qty)
			{
				new_quantity = kit.GetQuantity() - kit_repair_cost_adjusted;
				kit.SetQuantity( new_quantity );
			}
		}
		else if (!kit_has_quantity) //"kit" without quantity (hammers and such) for your every day repairing needs
		{
		}
		else
		{
			if(use_kit_qty)
			{
				kit.SetQuantity( 0 );
			}
		}
		
		
		if (kit.GetQuantity() >= 0)
		{			
			//item.SetHealthMax("","Health");
			float health_coef = item.GetHealthLevelValue(GameConstants.STATE_PRISTINE,damage_zone);
			item.SetHealth01(damage_zone,"Health", health_coef);
		}

	}
	
	override bool CanRepair( ItemBase repair_kit, Object item, string damage_zone = "" )
	{
		int state = item.GetHealthLevel(damage_zone);
		
		if (state >= GameConstants.STATE_WORN)
		{
			int repair_kit_type = repair_kit.ConfigGetInt( "repairKitType" );
			
			ref array<int> repairable_with_types = new array<int>;
			item.ConfigGetIntArray( "repairableWithKits", repairable_with_types );	
			
			for ( int i = 0; i < repairable_with_types.Count(); i++ )
			{
				int repairable_with_type = repairable_with_types.Get(i);
				
				if ( IsRepairValid( repair_kit_type, repairable_with_type ) )
				{
					return true;
				}
			}
		}
		return false;
		
	}

}