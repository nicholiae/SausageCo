class SausageGarden_CompostBin_Kit extends ItemBase
{	
	ref protected EffectSound 						m_DeployLoopSound;
	protected Object								SausageGarden_CompostBin_Kit1;	
	
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
				EntityAI kitItem = EntityAI.Cast(GetGame().CreateObjectEx("SausageGarden_CompostBin", position, ECE_PLACE_ON_SURFACE));
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

class SausageGarden_CompostBin_Holo extends ItemBase
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

class SausageGarden_CompostBin extends ItemBase
{ 	
	SBSConfig sbs_config = GetDayZGame().getSBSGlobals();
	private bool				m_CompostBinState = false;

	//use common variables across functions and friendly names
	private int slotId_Lard;
	private int slotId_Guts;
	private int slotId_Plant;
	private ItemBase m_Lard;
	private ItemBase m_Guts;
	private ItemBase m_Plant;
	
	private int percentageLard;
	private int percentageGuts;
	private int percentagePlant;

	void SausageGarden_CompostBin()
	{
		//we register this to sync it on the network because on action we need to know on client if its on or not
		RegisterNetSyncVariableBool("m_CompostBinState");
	}

	void ~SausageGarden_CompostBin()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName( this, "ProcessAndCraftFertilizer"); 
	}

	void SwitchOnServer()
	{
		m_CompostBinState = true;
		int SBSGarden_CompostBinTime = 10;		
		int GardenTime = SBSGarden_CompostBinTime * 1000; // converting to milliseconds for Callback Queue
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( ProcessAndCraftFertilizer, GardenTime, true );
	}

	void SwitchOffServer()
	{
		m_CompostBinState = false;
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName( this, "ProcessAndCraftFertilizer"); 
	}

	bool IsCompostBinOn()
	{
		return m_CompostBinState;
	}

	override bool CanReleaseAttachment(EntityAI attachment)
	{
		return !m_CompostBinState;
	}

    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }
    
	override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }

	bool CanCraft()
	{
		slotId_Lard = InventorySlots.GetSlotIdFromString("Ingredient");
		m_Lard = ItemBase.Cast( GetInventory().FindAttachment(slotId_Lard) );
		slotId_Guts = InventorySlots.GetSlotIdFromString("Guts");
		m_Guts = ItemBase.Cast( GetInventory().FindAttachment(slotId_Guts) );
		slotId_Plant = InventorySlots.GetSlotIdFromString("Plant");
		m_Plant = ItemBase.Cast( GetInventory().FindAttachment(slotId_Plant) );
		//you can check for quantity but gotta take in account that each type it has different amounts of quantity.
		//here you'll have to decide how much of each item you need minimum to start processing
		//atm these only checks if there is any in the slots
		if (m_Lard && m_Guts && m_Plant)
		{
			percentageLard = m_Lard.GetQuantityMax() * 45 / 100;
			percentageGuts = m_Guts.GetQuantityMax() * 45 / 100;
			percentagePlant = m_Plant.GetQuantityMax() * 50 / 100;
			return m_Lard.GetQuantity() >= percentageLard && m_Guts.GetQuantity() >= percentageGuts && m_Plant.GetQuantity() >= percentagePlant;
		}
		return false;
	}

	void ProcessAndCraftFertilizer()
	{
		if (GetGame().IsServer() && CanCraft())  
		{
			//create in inventory of the bin so it doesn't get lost if they forget about it
			//checking that we did create them so in case it gets full we turn it off and not use up materials
			ItemBase fert1 = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageCompost_Fertilizer"));
			//ItemBase fert2 = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageCompost_Fertilizer"));			
			//if(!fert1 || !fert2)
			if(!fert1)
				SwitchOffServer();
			m_Lard.AddQuantity(-percentageLard);
			m_Guts.AddQuantity(-percentageGuts);
			m_Plant.AddQuantity(-percentagePlant);
		}
		//if we can't craft anymore turn it off
		if(!CanCraft())
			SwitchOffServer();
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
	
	bool HasProperDistance( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 1.3 )
			{
				return false;
			}
		}
		
		return true;
	}
	
	
    override void SetActions()
    {
		super.SetActions();
		AddAction(ActionTurnOnOffCompostBin);
    }
};
