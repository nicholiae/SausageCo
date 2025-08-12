class SausageCo_CasingsProcessor_Kit extends ItemBase
{	
	ref protected EffectSound 						m_DeployLoopSound;
	protected Object								SausageCo_CasingsProcessor_Kit1;	
	
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
		vector positionChange = "0 0.5 0";
		vector position += positionChange;
	#else
	override void OnPlacementComplete(Man player, vector position = "0 0.5 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
	#endif
			if (GetGame().IsServer())
			{
				EntityAI kitItem = EntityAI.Cast(GetGame().CreateObjectEx("SausageCo_CasingsProcessor", position, ECE_PLACE_ON_SURFACE));
				vector positionChange = "0 0.5 0";
				position = position + positionChange;
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

class SausageCo_CasingsProcessor_Holo extends ItemBase
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

class SausageCo_CasingsProcessor extends ItemBase
{ 	
	// SBSConfig sbs_config = GetDayZGame().getSBSGlobals();
	private bool				m_CasingsProcessorState = false;

	//use common variables across functions and friendly names
	private int slotId_Casings;
	private int slotId_Gunpowder;
	private int slotId_CasingsFilled;
	
	private ItemBase m_Casings;
	private ItemBase m_CasingsFilled;
	private ItemBase m_Gunpowder;
	
	private int countCasings;
	private int countCasingsFilled;
	private int percentageGunpowder;
	
	// Processing configuration
	const int MAX_CASINGS_CAPACITY = 200;  // Maximum filled casings capacity
	const int PROCESS_BATCH_SIZE = 2;      // How many casings processed per cycle
	const float PROCESSOR_TIME = 0.85;     // Time in seconds between processing batches

	// Interaction configuration
	const float MAX_INTERACTION_DISTANCE = 1.3;  // Maximum distance for player interaction
	
	void SausageCo_CasingsProcessor()
	{
		//we register this to sync it on the network because on action we need to know on client if its on or not
		RegisterNetSyncVariableBool("m_CasingsProcessorState");
	}

	void ~SausageCo_CasingsProcessor()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName(this, "ProcessCasings"); 
	}

	void SwitchOnServer()
	{
		m_CasingsProcessorState = true;	
		int ProcessorTime = PROCESSOR_TIME * 1000; // converting to milliseconds for Callback Queue
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( ProcessCasings, ProcessorTime, true );
	}

	void SwitchOffServer()
	{
		m_CasingsProcessorState = false;
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName( this, "ProcessCasings"); 
	}

	bool IsCasingsProcessorOn()
	{
		return m_CasingsProcessorState;
	}

	override bool CanReleaseAttachment(EntityAI attachment)
	{
		return !m_CasingsProcessorState;
	}

    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }
    
	override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }

	
	bool CanProcessCasings()
	{
		slotId_Casings = InventorySlots.GetSlotIdFromString("SCAS_casings");// getting slot ID of Casings as defined in config.cpp for the SausageCo_CasingsProcessor
		m_Casings = ItemBase.Cast( GetInventory().FindAttachment(slotId_Casings) );// using slot ID to identify an entity in game to manipulate later, without we could not manipulate an item in game
		
		slotId_Gunpowder = InventorySlots.GetSlotIdFromString("SCAS_gunpowder");// getting slot ID of Gunpowder as defined in config.cpp for the SausageCo_GunpowderProcessor
		m_Gunpowder = ItemBase.Cast( GetInventory().FindAttachment(slotId_Gunpowder) );// using slot ID to identify an entity in game to manipulate later, without we could not manipulate an item in game
		// First attempt to get and cast the casings
		slotId_CasingsFilled = InventorySlots.GetSlotIdFromString("SCAS_casingsFilled");
		m_CasingsFilled = ItemBase.Cast(GetInventory().FindAttachment(slotId_CasingsFilled));

		// If first attempt fails, try one more time
		if (m_CasingsFilled && m_CasingsFilled.GetQuantity() >= 200)
		{
			return false;
		}

		if (m_Casings && m_Gunpowder)
		{
			countCasings = m_Casings.GetQuantityMax() * PROCESS_BATCH_SIZE / MAX_CASINGS_CAPACITY;
			percentageGunpowder = m_Gunpowder.GetQuantityMax() * PROCESS_BATCH_SIZE / MAX_CASINGS_CAPACITY;
			return m_Casings.GetQuantity() >= countCasings && m_Gunpowder.GetQuantity() >= percentageGunpowder;
		}
		return false;
	}
	void ProcessCasings()
	{
		if (GetGame().IsServer() && CanProcessCasings())  
		{
			
			if (!m_CasingsFilled)
			{
				slotId_CasingsFilled = InventorySlots.GetSlotIdFromString("SCAS_casingsFilled");
				GetInventory().CreateAttachmentEx("SausageCo_BulletCasing_Filled", slotId_CasingsFilled);
				m_CasingsFilled = ItemBase.Cast(GetInventory().FindAttachment(slotId_CasingsFilled));
				m_CasingsFilled.SetQuantity(PROCESS_BATCH_SIZE);
				m_Gunpowder.AddQuantity(-PROCESS_BATCH_SIZE);
				m_Casings.AddQuantity(-PROCESS_BATCH_SIZE);
			}
				
			if (m_Gunpowder && m_Casings)
			{
				m_CasingsFilled.AddQuantity(PROCESS_BATCH_SIZE);
				m_Gunpowder.AddQuantity(-PROCESS_BATCH_SIZE);
				m_Casings.AddQuantity(-PROCESS_BATCH_SIZE);
			}
			
			if (m_CasingsFilled.GetQuantity() == MAX_CASINGS_CAPACITY)
			{
				SwitchOffServer();
			}
		}
		
		//if we can't craft ANYTHING anymore turn it off
		if (m_CasingsFilled.GetQuantity() == MAX_CASINGS_CAPACITY)
			SwitchOffServer();
		
		if (!m_Gunpowder || !m_Casings)
			SwitchOffServer();
		
		if(!CanProcessCasings())
		{
			SwitchOffServer();
		}
	}
	void Base_Destroy()
	{
		//delete object
		GetGame().ObjectDelete( this );
	}
	
	bool IsFacingFront( PlayerBase player, string selection )
    {
        vector metal_pos = GetPosition();
        vector player_pos = player.GetPosition();
        vector metal_dir = GetDirection();
        
        vector metal_player_dir = player_pos - metal_pos;
        metal_player_dir.Normalize();
        metal_dir.Normalize();
        
        if ( metal_dir.Length() != 0 )
        {
            float dot = vector.Dot( metal_player_dir, metal_dir );
            
            if ( dot > 0 )
            {
                return true;
            }
        }
        return false;
    }
    
    bool IsFacingBack( PlayerBase player, string selection )
    {
        return !IsFacingFront( player, selection );
    }
	
	bool HasProperDistance(string selection, PlayerBase player)
	{
		if (MemoryPointExists(selection))
		{
			vector selection_pos = ModelToWorld(GetMemoryPointPos(selection));
			float distance = vector.Distance(selection_pos, player.GetPosition());
			if (distance >= MAX_INTERACTION_DISTANCE)
			{
				return false;
			}
		}
		return true;
	}
	
	
    override void SetActions()
    {
		super.SetActions();
		AddAction(ActionTurnOnOffCasingsProcessor);
    }
};
