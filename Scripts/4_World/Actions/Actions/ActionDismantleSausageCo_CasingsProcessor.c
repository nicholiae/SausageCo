class ActionDismantleSausageCo_CasingsProcessorCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.DEFAULT_DECONSTRUCT / 2 );
	}
};

class ActionDismantleSausageCo_CasingsProcessor: ActionContinuousBase
{
	void ActionDismantleSausageCo_CasingsProcessor()
	{
		m_CallbackClass = ActionDismantleSausageCo_CasingsProcessorCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}

	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( player )
		{
			return "Dismantle Ammo Packer";
		}
		
		return "";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject )
		{
			SausageCo_CasingsProcessor sausageco_casingsprocessor = SausageCo_CasingsProcessor.Cast( targetObject );
			if ( sausageco_casingsprocessor )
			{
				if ( sausageco_casingsprocessor.IsFacingBack( player, "dismantle_wall_interact" ) && sausageco_casingsprocessor.GetInventory().GetCargo().GetItemCount() == 0 && sausageco_casingsprocessor.GetInventory().AttachmentCount() == 0 )
                {
                    return true;
                }
				if ( sausageco_casingsprocessor.IsFacingFront( player, "dismantle_wall_interact" ) && sausageco_casingsprocessor.GetInventory().GetCargo().GetItemCount() == 0 && sausageco_casingsprocessor.GetInventory().AttachmentCount() == 0 )
                {
                    return true;
                }
			}
		}
		return false;
	}
		
	override void OnFinishProgressServer( ActionData action_data ) 
	{
		//target existing model
		SausageCo_CasingsProcessor sausageco_casingsprocessor = SausageCo_CasingsProcessor.Cast( action_data.m_Target.GetObject() );
		
		if ( sausageco_casingsprocessor ) 
		{	
			//delete existing model
			sausageco_casingsprocessor.Base_Destroy();
			
			//add damage to tool
			action_data.m_MainItem.DecreaseHealth( UADamageApplied.DISMANTLE, false );
			
			//return materials
			vector pos = action_data.m_Player.GetPosition();
			ItemBase Remaining_Planks = ItemBase.Cast( GetGame().CreateObject("SausageCo_CasingsProcessor_Kit", pos ) );
			int plank_quant = 1;
			Remaining_Planks.SetQuantity( Math.Round( action_data.m_Player.GetSoftSkillsManager().AddSpecialtyBonus( plank_quant, this.GetSpecialtyWeight() ) ), true );
		}
		action_data.m_Player.MessageStatus((sausageco_casingsprocessor.GetPosition()-action_data.m_Player.GetPosition()).ToString());
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
	
	//setup
	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{	
		if( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			SetBuildingAnimation( item );
			
			return true;
		}
		
		return false;
	}
	
	void SetBuildingAnimation( ItemBase item )
	{
		switch( item.Type() )
		{
			case Shovel:
			case FieldShovel:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
				break;
			case Pliers:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
				break;				
			default:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
				break;
		}
	}

//---------------------Function to test if the front direction of an object(base wall/fence) is facing the player or not---------------------//	 
	bool isFacingPlayer(PlayerBase player, Object object)
	{
		vector fence_pos = object.GetPosition();
		vector player_pos = player.GetPosition();
		vector ref_dir = object.GetDirection();
		
		vector fence_player_dir = player.GetDirection();
		fence_player_dir.Normalize();
		fence_player_dir[1] = 0; 	//ignore height
		
		ref_dir.Normalize();
		ref_dir[1] = 0;			//ignore height
		
		if ( ref_dir.Length() != 0 )
		{
			float angle = Math.Acos( fence_player_dir * ref_dir );
			
			if ( angle <= 0.2 )
			{
				return true;
			}
		}
			
		return false;
	}	
}
