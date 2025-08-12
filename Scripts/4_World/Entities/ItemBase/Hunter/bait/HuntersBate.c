class HuntersBate extends ItemBase
{	
	ref protected EffectSound 						m_DeployLoopSound;
	Object											HuntersBateXP;
	
	int xpGained()
	{
		return 25;
	}
	
	override void EEInit()
	{
		super.EEInit();
	}
	
	override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged( old_owner, new_owner );
	}	
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( IsDeploySound() )
		{
			PlayDeploySound();
		}
				
		if ( CanPlayDeployLoopSound() )
		{
			PlayDeployLoopSound();
		}
					
		if ( m_DeployLoopSound && !CanPlayDeployLoopSound() )
		{
			StopDeployLoopSound();
		}
	}
	
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================			
	#ifdef DAYZ_1_09	
	override void OnPlacementComplete( Man player )
	{
		super.OnPlacementComplete( player );
		PlayerBase player_base = PlayerBase.Cast( player );
		vector position = player_base.GetLocalProjectionPosition();
		vector orientation = player_base.GetLocalProjectionOrientation();
	#else
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
	#endif
			if (GetGame().IsServer())
			{
				// for (int s=0;s<12;s++)
				// {
					// EntityAI animalAttr = EntityAI.Cast(GetGame().CreateObject("SausageCo_Experience_Hunter", position, ECE_PLACE_ON_SURFACE));
					// animalAttr.SetPosition(position);
					// animalAttr.SetOrientation(orientation);
				// };
					HuntersBateXP = GetGame().CreateObject("SausageCo_Experience_Hunter", position, false );
					HuntersBateXP.SetPosition( position );
					HuntersBateXP.SetOrientation( orientation );
					ItemBase.Cast(HuntersBateXP).SetQuantity(xpGained());
			}
		
			SetIsDeploySound( true );
			this.Delete();
	}
	
	override bool IsDeployable()
	{
		return true;
	}	
	
	override string GetDeploySoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "BarbedWire_Deploy_loop_SoundSet";
	}
	
	void PlayDeployLoopSound()
	{		
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{		
			m_DeployLoopSound = SEffectManager.PlaySound( GetLoopDeploySoundset(), GetPosition() );
		}
	}
	
	void StopDeployLoopSound()
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{	
			m_DeployLoopSound.SoundStop();
			delete m_DeployLoopSound;
		}
	}
}

class HuntersBate_Holo extends ItemBase
{
	override bool CanPutInCargo( EntityAI parent )
    {
        if( !super.CanPutInCargo(parent) ) {return false;}        
        if ( GetNumberOfItems() == 0)
        {
            return false;
        }
        return false;
    }
    
    override bool CanPutIntoHands(EntityAI parent)
    {
        if( !super.CanPutIntoHands( parent ) )
        {
            return false;
        }
        if ( GetNumberOfItems() == 0 )
        {
            return false;
        }
        return false;
    }
}
class HuntersBateT1 extends HuntersBate
{
	
	override int xpGained()
	{
		return 25;
	}
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================			
	#ifdef DAYZ_1_09	
	override void OnPlacementComplete( Man player )
	{
		super.OnPlacementComplete( player );
		PlayerBase player_base = PlayerBase.Cast( player );
		vector position = player_base.GetLocalProjectionPosition();
		vector orientation = player_base.GetLocalProjectionOrientation();
	#else
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
	#endif
			if (GetGame().IsServer())
			{
				EntityAI animalAttr = EntityAI.Cast(GetGame().CreateObject("Animal_CapraHircus_Black", position, false, true));
				animalAttr.SetPosition(position);
				animalAttr.SetOrientation(orientation);
				animalAttr.SetHealth("","",20);
				animalAttr.SetSynchDirty();
				// for (int s=0;s<6;s++)
				// {
					// EntityAI exp = EntityAI.Cast(GetGame().CreateObject("SausageCo_Experience_Hunter", position, ECE_PLACE_ON_SURFACE));
					// exp.SetPosition(position);
					// exp.SetOrientation(orientation);
				// };
				EntityAI exp = GetGame().CreateObject("SausageCo_Experience_Hunter", position, false );
				exp.SetPosition( position );
				exp.SetOrientation( orientation );
				ItemBase.Cast(exp).SetQuantity(xpGained());
			}
	
			SetIsDeploySound( true );
			this.Delete();
	}
};
class HuntersBateT2 extends HuntersBate
{
	
	override int xpGained()
	{
		return 50;
	}
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================			
	#ifdef DAYZ_1_09	
	override void OnPlacementComplete( Man player )
	{
		super.OnPlacementComplete( player );
		PlayerBase player_base = PlayerBase.Cast( player );
		vector position = player_base.GetLocalProjectionPosition();
		vector orientation = player_base.GetLocalProjectionOrientation();
	#else
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
	#endif
			if (GetGame().IsServer())
			{
				EntityAI animalAttr = EntityAI.Cast(GetGame().CreateObject("Animal_SusScrofa", position, false, true));
				animalAttr.SetPosition(position);
				animalAttr.SetOrientation(orientation);
				animalAttr.SetHealth("","",20);
				animalAttr.SetSynchDirty();
				// for (int s=0;s<12;s++)
				// {
					// EntityAI exp = EntityAI.Cast(GetGame().CreateObject("SausageCo_Experience_Hunter", position, ECE_PLACE_ON_SURFACE));
					// exp.SetPosition(position);
					// exp.SetOrientation(orientation);
				// };
				EntityAI exp = GetGame().CreateObject("SausageCo_Experience_Hunter", position, false );
				exp.SetPosition( position );
				exp.SetOrientation( orientation );
				ItemBase.Cast(exp).SetQuantity(xpGained());
			}
	
			SetIsDeploySound( true );
			this.Delete();
	}
};
class HuntersBateT3 extends HuntersBate
{
	
	override int xpGained()
	{
		return 75;
	}
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================			
	#ifdef DAYZ_1_09	
	override void OnPlacementComplete( Man player )
	{
		super.OnPlacementComplete( player );
		PlayerBase player_base = PlayerBase.Cast( player );
		vector position = player_base.GetLocalProjectionPosition();
		vector orientation = player_base.GetLocalProjectionOrientation();
	#else
	override void OnPlacementComplete(Man player, vector position = "5 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
	#endif
			if (GetGame().IsServer())
			{
				EntityAI animalAttr = EntityAI.Cast(GetGame().CreateObject("Animal_CanisLupus_White", position, false, true));
				animalAttr.SetPosition(position);
				animalAttr.SetOrientation(orientation);
				animalAttr.SetHealth("","",20);
				animalAttr.SetSynchDirty();
				// for (int s=0;s<18;s++)
				// {
					// EntityAI exp = EntityAI.Cast(GetGame().CreateObject("SausageCo_Experience_Hunter", position, ECE_PLACE_ON_SURFACE));
					// exp.SetPosition(position);
					// exp.SetOrientation(orientation);
				// };
				EntityAI exp = GetGame().CreateObject("SausageCo_Experience_Hunter", position, false );
				exp.SetPosition( position );
				exp.SetOrientation( orientation );
				ItemBase.Cast(exp).SetQuantity(xpGained());
			}
	
			SetIsDeploySound( true );
			this.Delete();
	}
};
class HuntersBateT4 extends HuntersBate
{
	
	override int xpGained()
	{
		return 100;
	}
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================			
	#ifdef DAYZ_1_09	
	override void OnPlacementComplete( Man player )
	{
		super.OnPlacementComplete( player );
		PlayerBase player_base = PlayerBase.Cast( player );
		vector position = player_base.GetLocalProjectionPosition();
		vector orientation = player_base.GetLocalProjectionOrientation();
	#else
	override void OnPlacementComplete(Man player, vector position = "10 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
	#endif
			if (GetGame().IsServer())
			{
				EntityAI animalAttr = EntityAI.Cast(GetGame().CreateObject("Animal_UrsusArctos", position, false, true));
				animalAttr.SetPosition(position);
				animalAttr.SetOrientation(orientation);
				animalAttr.SetHealth("","",20);
				animalAttr.SetSynchDirty();			
				EntityAI exp = GetGame().CreateObject("SausageCo_Experience_Hunter", position, false );
				exp.SetPosition( position );
				exp.SetOrientation( orientation );
				ItemBase.Cast(exp).SetQuantity(xpGained());

			}
	
			SetIsDeploySound( true );
			this.Delete();
	}
};
