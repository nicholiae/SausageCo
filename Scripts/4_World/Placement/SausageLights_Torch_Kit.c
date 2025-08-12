class SausageLights_Torch_Kit extends ItemBase
{	
	ref protected EffectSound 						m_DeployLoopSound;
	protected Object								SausageLights_Torch_Kit1;	
	
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
				EntityAI kitItem = EntityAI.Cast(GetGame().CreateObjectEx("SausageLights_Torch", position, ECE_PLACE_ON_SURFACE));
				kitItem.SetPosition(position);
				kitItem.SetOrientation(orientation);
			}
			
			SetIsPlaceSound(true);
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

class SausageLights_Torch_Holo extends ItemBase
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
class SausageLights_Torch: FlammableBase
{
	//legacy vars which cannot be moved/removed
	static float 			m_BurnTimePerRag;
	static float 			m_BurnTimePerFullLard;
	static float 			m_BurnTimePerFullFuelDose;
	static float 			m_MaxConsumableLardQuantity;
	static float 			m_MaxConsumableFuelQuantity;
	static float 			m_WaterEvaporationByFireIntensity = 0.001;
	static int 				m_StartFadeOutOfLightAtQuantity = 50;
	
	void SausageLights_Torch()
	{
		m_ParticleLocalPos = Vector(0, 1.0, 0); // Adjust particle position 0.25 up on Y axis
	}

	override void Init()
	{
		super.Init();
		
		//for legacy reasons
		m_BurnTimePerRag = m_BurnTimePerRagEx;
		m_BurnTimePerFullLard = m_BurnTimePerFullLardEx;
		m_BurnTimePerFullFuelDose = m_BurnTimePerFullFuelDoseEx;
		m_MaxConsumableLardQuantity = m_MaxConsumableLardQuantityEx;
		m_MaxConsumableFuelQuantity = m_MaxConsumableFuelQuantityEx;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionUpgradeTorchFromGasPump);
		AddAction(ActionRefuelTorch);
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
	
	// !Called on CHILD when it's attached to parent.
	override void OnWasAttached( EntityAI parent, int slot_id )
	{
		super.OnWasAttached(parent, slot_id);
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
			LockRags(true);
	}
		
	// !Called on CHILD when it's detached from parent.
	override void OnWasDetached( EntityAI parent, int slot_id )
	{
		super.OnWasDetached(parent, slot_id);
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
			LockRags(false);
	}
	
	override bool CanBeIgnitedBy(EntityAI igniter = NULL)
    {
        if (!GetCompEM().CheckWetness())
            return false;
        
        if (!GetCompEM().CanWork())
            return false;
        
        PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
        if (player)
        {
            if (this != player.GetItemInHands())
            {
                return false;
            }
        }
        
        return true;
    }

    override void OnIgnitedThis(EntityAI fire_source)
    {
        GetCompEM().SwitchOn();
    }

    // Make sure you have these particle/light related functions:
    override string GetBurningMaterial()
    {
        return "dz\gear\cooking\data\flame_fireplace.rvmat";
    }
    
    override void UpdateParticle()
    {
        if (!m_FireParticle)
        {
            m_FireParticle = ParticleManager.GetInstance().PlayOnObject(ParticleList.TORCH_T2, this, m_ParticleLocalPos);
        }
    }
	
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		ctx.Write(m_ConsumeRagFlipFlop);
		ctx.Write(m_RagsUpgradedCount);
	}
	
	override bool ConsumeRag()
	{
		ItemBase rag = GetRag();
		
		if (rag)
		{
			// Don't reduce quantity or health of rag
			return true; // Return true to indicate success but don't actually consume
		}
		
		return false;
	}
	
	
	override void OnWork(float consumed_energy)
	{
		UpdateMaterial();
		
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			// Skip the energy consumption checks
			
			UpdateCheckForReceivingUpgrade();
			
			AddWet(-m_WaterEvaporationByFireIntensityEx * GetCompEM().GetUpdateInterval());
			
			Rag rag = GetRag();
			if (rag)
			{
				rag.AddWet(-m_WaterEvaporationByFireIntensityEx * GetCompEM().GetUpdateInterval());
			}
		}
		
		// if (!m_LoopSoundEntity && GetGame() && (!GetGame().IsDedicatedServer()))
		// {
			// m_LoopSoundEntity = PlaySoundLoop(GetSoundName(), 50);
		// }
		
		if (!GetGame().IsDedicatedServer())
		{
			UpdateLight();
			UpdateParticle();
		}
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if (!super.OnStoreLoad(ctx, version))
		{
			return false;
		}
		
		if (version >= 129)
		{
			if (!ctx.Read( m_ConsumeRagFlipFlop ))
			{
				return false;
			}
		
			if (!ctx.Read( m_RagsUpgradedCount ))
			{
				return false;
			}
		}
		UpdateCheckForReceivingUpgrade();
		return true;
	}
};

class SausageLights_TorchLambda : ReplaceItemWithNewLambdaBase
{
	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);

		ItemBase stick;
		FlammableBase flammable = FlammableBase.Cast(old_item);
		Class.CastTo(stick, new_item);
		if (stick && flammable)
		{
			flammable.ApplyResultModifications(stick);
		}
	}
};