modded class ActionBuildPartCB
{
    override void CreateActionComponent()
    {
        ItemBase item = m_ActionData.m_MainItem;

        if (item && item.isSCSAdminTool())
        {
            m_ActionData.m_ActionComponent = new CAContinuousTime(0.25);
            return;
        }

        super.CreateActionComponent();
    }
}

modded class ActionBuildPart
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		//super.OnFinishProgressServer(action_data);
		
		BaseBuildingBase base_building = BaseBuildingBase.Cast( action_data.m_Target.GetObject() );
		Construction construction = base_building.GetConstruction();
		
		string part_name = BuildPartActionData.Cast(action_data).m_PartType;
		
		#ifdef DAYZ_1_09
		if ( action_data.m_MainItem.isSCSAdminTool() )
        {
            //build
			construction.AdminBuildPartServer( part_name, AT_BUILD_PART );
        }
		
		if ( !construction.IsColliding( part_name ) && construction.CanBuildPart( part_name, action_data.m_MainItem ) )
		{
			//build
			construction.BuildPartServer( part_name, AT_BUILD_PART );
			
			//add damage to tool - NOT COMPILING
			//float alternate_damage;
			//if ( action_data.m_MainItem.GetSpecialUserActionDamage(alternate_damage) )
			//{
			//	action_data.m_MainItem.DecreaseHealth( alternate_damage, false );
			//}
			//else
			//{
				action_data.m_MainItem.DecreaseHealth( UADamageApplied.BUILD, false );
			//}
		}
		#else
		if ( action_data.m_MainItem.isSCSAdminTool() )
        {
            //build
			construction.AdminBuildPartServer( action_data.m_Player, part_name, AT_BUILD_PART );
        }

		if ( !construction.IsColliding( part_name ) && construction.CanBuildPart( part_name, action_data.m_MainItem, true ) )
		{
			//build
			construction.BuildPartServer( action_data.m_Player, part_name, AT_BUILD_PART );
			
			//add damage to tool - NOT COMPILING
			//float alternate_damage;
			//if ( action_data.m_MainItem.GetSpecialUserActionDamage(alternate_damage) )
			//{
			//	action_data.m_MainItem.DecreaseHealth( alternate_damage, false );
			//}
			//else
			//{
				action_data.m_MainItem.DecreaseHealth( UADamageApplied.BUILD, false );
			//}
		}
		#endif
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
}
