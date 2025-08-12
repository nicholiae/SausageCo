class SausagePlank_Processor_Kit extends ItemBase
{	
	ref protected EffectSound 						m_DeployLoopSound;
	protected Object								SausagePlank_Processor_Kit1;	
	
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
				EntityAI kitItem = EntityAI.Cast(GetGame().CreateObjectEx("SausagePlank_Processor", position, ECE_PLACE_ON_SURFACE));
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

class SausagePlank_Processor_Holo extends ItemBase
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

class SausagePlank_Processor extends ItemBase
{ 	
	private bool				m_PlankProcessorState = false;

	//use common variables across functions and friendly names
	private int slotId_Logs;
	private int slotId_Planks;
	
	private ItemBase m_Logs;
	private ItemBase m_Planks;
	
	private int countLogs;
	private int countPlanks;
	
	// Processing configuration
	const int MAX_LOGS_CAPACITY = 30;     // Maximum logs capacity
	const int PLANKS_PER_LOG = 10;        // Planks produced per log
	const int PROCESS_BATCH_SIZE = 1;      // How many logs processed per cycle
	const float PROCESSOR_TIME = 0.85;     // Time in seconds between processing batches

	// Interaction configuration
	const float MAX_INTERACTION_DISTANCE = 1.3;  // Maximum distance for player interaction
	
	void SausagePlank_Processor()
	{
		RegisterNetSyncVariableBool("m_PlankProcessorState");
	}

	void ~SausagePlank_Processor()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName(this, "ProcessLogs"); 
	}

	void SwitchOnServer()
	{
		m_PlankProcessorState = true;	
		int ProcessorTime = PROCESSOR_TIME * 1000; // converting to milliseconds for Callback Queue
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( ProcessLogs, ProcessorTime, true );
	}

	void SwitchOffServer()
	{
		m_PlankProcessorState = false;
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName( this, "ProcessLogs"); 
	}

	bool IsPlankProcessorOn()
	{
		return m_PlankProcessorState;
	}

	override bool CanReleaseAttachment(EntityAI attachment)
	{
		return !m_PlankProcessorState;
	}

    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }
    
	override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }

	bool CanProcessLogs()
	{
		slotId_Logs = InventorySlots.GetSlotIdFromString("Material_L1_WoodenLogs");
		m_Logs = ItemBase.Cast( GetInventory().FindAttachment(slotId_Logs) );
		
		slotId_Planks = InventorySlots.GetSlotIdFromString("Material_Processor_WoodenPlanks");
		m_Planks = ItemBase.Cast(GetInventory().FindAttachment(slotId_Planks));

		if (m_Planks && m_Planks.GetQuantity() >= 300)
		{
			return false;
		}
		
		if (m_Logs)
		{
			countLogs = m_Logs.GetQuantity();
			return countLogs >= PROCESS_BATCH_SIZE;
		}
		return false;
	}

	void ProcessLogs()
	{
		if (GetGame().IsServer() && CanProcessLogs())  
		{
			if (m_Logs)
			{
				slotId_Planks = InventorySlots.GetSlotIdFromString("Material_Processor_WoodenPlanks");
				m_Planks = ItemBase.Cast(GetInventory().FindAttachment(slotId_Planks));

				if (!m_Planks)
				{
					GetInventory().CreateAttachmentEx("WoodenPlank", slotId_Planks);
					m_Planks = ItemBase.Cast(GetInventory().FindAttachment(slotId_Planks));
					m_Planks.SetQuantity(PROCESS_BATCH_SIZE);
					m_Logs.AddQuantity(-PROCESS_BATCH_SIZE);
				}
					
				if (m_Planks)
				{
					m_Planks.AddQuantity(PLANKS_PER_LOG * PROCESS_BATCH_SIZE);
					m_Logs.AddQuantity(-PROCESS_BATCH_SIZE);
				}
			}
			
			if (m_Logs.GetQuantity() == 0)
			{
				SwitchOffServer();
			}
		}
		
		if (!m_Logs)
			SwitchOffServer();
		
		if(!CanProcessLogs())
		{
			SwitchOffServer();
		}
	}

	void Base_Destroy()
	{
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
		AddAction(ActionTurnOnOffPlankProcessor);
    }
};