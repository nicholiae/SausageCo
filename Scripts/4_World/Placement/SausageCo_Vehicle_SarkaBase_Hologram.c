modded class Hologram
{	
	ItemBase FadedCollision()
	{
		vector center;
		vector relative_ofset;
		vector absolute_ofset = "0 2.0 0"; 
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		ref array<Object> excluded_objects = new array<Object>;
		ref array<Object> collided_objects = new array<Object>;
		
		m_Projection.GetCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2.4;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );

		if ( GetGame().IsBoxColliding( center, orientation, edge_length, excluded_objects, collided_objects ) )
		{	
			for( int i = 0; i < collided_objects.Count(); i++ )
			{
				Object obj_collided = collided_objects[i];
				if( obj_collided.IsInherited(WoodenCrate) )
				{
					WoodenCrate woodencrate = WoodenCrate.Cast(obj_collided);
					return woodencrate;
				}
			}
		}
		return null;
	}

	override string ProjectionBasedOnParent()
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		
		if (item_in_hands.IsInherited(SausageCo_Vehicle_SarkaBase_Kit))
			return "Sedan_02";
		
		return super.ProjectionBasedOnParent();
	}
    override EntityAI PlaceEntity( EntityAI entity_for_placing )
    {    
        ItemBase item_in_hands = ItemBase.Cast( m_Player.GetHumanInventory().GetEntityInHands() );
    
        if ( m_Projection.IsInherited( GardenPlotPlacing ) ) //garden plot
		{
			Class.CastTo(entity_for_placing, GetGame().CreateObjectEx( "GardenPlot", m_Projection.GetPosition(), ECE_OBJECT_SWAP )); //garden plot
			return entity_for_placing;
		}
            
        if( entity_for_placing.CanAffectPathgraph() )
        {        
            entity_for_placing.SetAffectPathgraph( true, false );
            
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, entity_for_placing);
        }
        
        return entity_for_placing;
    } 

    void EvaluateCollision(ItemBase action_item = null)
    {
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		ItemBase fortfloor = FadedCollision();
		
        
		if (item_in_hands.IsInherited(SausageCo_Vehicle_SarkaBase_Kit))
        {
            SetIsColliding(false);
            return;
        }
        super.EvaluateCollision();
    }
}