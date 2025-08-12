class SC_DryingRack_Kit extends ItemBase
{	
	ref protected EffectSound 						m_DeployLoopSound;
	protected Object								SC_DryingRack_Kit1;	
	
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
		vector positionChange = "0 1.9 0";
		position += positionChange;
	#else
	override void OnPlacementComplete(Man player, vector position = "0 1.9 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
	#endif
			if (GetGame().IsServer())
			{
				EntityAI kitItem = EntityAI.Cast(GetGame().CreateObjectEx("SC_DryingRack", position, ECE_PLACE_ON_SURFACE));
				vector positionChange = "0 1.9 0";
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

class SC_DryingRack_Holo extends ItemBase
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


class SC_DryingRack extends Inventory_Base
{
    protected ref map<string, ref Timer> m_SlotTimers; // Store timers for each slot
    protected ref array<string> m_AttachmentSlots; // Add this declaration
    protected ref array<string> m_ProxySelections; // Add this declaration
    protected float m_DryingRate = 0.1;
    const float DRYING_TIME = 180; // 3 minutes in seconds

    void SC_DryingRack()
    {
        m_SlotTimers = new map<string, ref Timer>();
        
        // Initialize attachment slots as before
        m_AttachmentSlots = new array<string>;
        m_ProxySelections = new array<string>;
        
        // Initialize slots
        m_AttachmentSlots.Insert("Body");
        m_AttachmentSlots.Insert("Legs");
        m_AttachmentSlots.Insert("Feet");
        m_AttachmentSlots.Insert("Headgear");
        m_AttachmentSlots.Insert("Mask");
        m_AttachmentSlots.Insert("Gloves");
        m_AttachmentSlots.Insert("Back");
        m_AttachmentSlots.Insert("Hips");
        m_AttachmentSlots.Insert("Vest");
        
        // Initialize proxy selections as before...
        m_ProxySelections.Insert("proxy_body");
        m_ProxySelections.Insert("proxy_legs");
        m_ProxySelections.Insert("proxy_feet");
        m_ProxySelections.Insert("proxy_headgear");
        m_ProxySelections.Insert("proxy_mask");
        m_ProxySelections.Insert("proxy_gloves");
        m_ProxySelections.Insert("proxy_back");
        m_ProxySelections.Insert("proxy_hips");
        m_ProxySelections.Insert("proxy_vest");
    }

    // Called when an item is attached
    override void EEItemAttached(EntityAI item, string slot_name)
    {
        super.EEItemAttached(item, slot_name);
        
        if (item.IsClothing())
        {
            Clothing clothing = Clothing.Cast(item);
            if (clothing)
            {
                // Start drying process as before
                StartDryingProcess(clothing, slot_name);
                
                // Start timer for this slot
                if (GetGame().IsServer())
                {
                    StartSlotTimer(slot_name, item);
                }
            }
        }
    }

    // Called when an item is detached
    override void EEItemDetached(EntityAI item, string slot_name)
    {
        super.EEItemDetached(item, slot_name);
        
        // Cancel timer if item is manually removed
        if (GetGame().IsServer())
        {
            CancelSlotTimer(slot_name);
        }
    }

    protected void StartDryingProcess(Clothing clothing, string slot_name)
    {
        if (clothing.GetWet() > 0)
        {
            // Start drying timer
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DryClothing, 1000, true, clothing);
        }
    }
	
	protected void DryClothing(Clothing clothing)
	{   
		if (clothing && clothing.GetWet() > 0)
		{
			float currentWetness = clothing.GetWet();
			float newWetness = Math.Max(0, currentWetness - m_DryingRate);
			
			if (GetGame().IsServer()) // Can't Change variables client side but still need to end the drying on both client and server for item release
			{
				clothing.SetWet(newWetness);
			}

			// Check if item is now completely dry
			if (newWetness <= 0)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(DryClothing);

				// Drop the dried item if we're on server
				if (GetGame().IsServer())
				{
					vector pos = GetPosition();
					vector ori = GetOrientation();
					
					// Detach and drop slightly in front of the rack
					GetInventory().DropEntity(InventoryMode.SERVER, this, clothing);
					clothing.SetPosition(pos + (GetDirection() * 0.5)); // Drop 0.5 meters in front
					clothing.SetOrientation(ori);
				}
			}
		}
	}
	
    // Start timer for a specific slot
    protected void StartSlotTimer(string slot_name, EntityAI item)
    {
        // Cancel existing timer if there is one
        CancelSlotTimer(slot_name);
        
        // Create new timer
        Timer timer = new Timer(CALL_CATEGORY_GAMEPLAY);
        m_SlotTimers.Set(slot_name, timer);
        
        // Start timer with parameters
        timer.Run(DRYING_TIME, this, "OnSlotTimerComplete", new Param2<string, EntityAI>(slot_name, item));
    }

    // Cancel timer for a specific slot
    protected void CancelSlotTimer(string slot_name)
    {
        Timer timer = m_SlotTimers.Get(slot_name);
        if (timer)
        {
            timer.Stop();
            m_SlotTimers.Remove(slot_name);
        }
    }

    // Called when slot timer completes
    void OnSlotTimerComplete(string slot_name, EntityAI item)
    {
        if (GetGame().IsServer())
        {
            // Check if the item is still attached in this slot
            EntityAI attached_item = FindAttachmentBySlotName(slot_name);
            if (attached_item && attached_item == item)
            {
                // Drop the item
                vector pos = GetPosition();
                vector ori = GetOrientation();
                
                GetInventory().DropEntity(InventoryMode.SERVER, this, item);
                item.SetPosition(pos + (GetDirection() * 0.5));
                item.SetOrientation(ori);

            }
        }
        
        // Clean up timer
        CancelSlotTimer(slot_name);
    }

	bool IsFacingFront(PlayerBase player, string selection)
    {
        vector metal_pos = GetPosition();
        vector player_pos = player.GetPosition();
        vector metal_dir = GetDirection();
        
        vector metal_player_dir = player_pos - metal_pos;
        metal_player_dir.Normalize();
        metal_dir.Normalize();
        
        if (metal_dir.Length() != 0)
        {
            float dot = vector.Dot(metal_player_dir, metal_dir);
            
            if (dot > 0)
            {
                return true;
            }
        }
        return false;
    }
    
	void Base_Destroy()
	{
		GetGame().ObjectDelete(this);
	}
	
    bool IsFacingBack(PlayerBase player, string selection)
    {
        return !IsFacingFront(player, selection);
    }
	
	bool HasProperDistance(string selection, PlayerBase player)
	{
		if (MemoryPointExists(selection))
		{
			vector selection_pos = ModelToWorld(GetMemoryPointPos(selection));
			float distance = vector.Distance(selection_pos, player.GetPosition());
			Print("Distance for " + selection + ": " + distance); // Debug line
			if (distance >= 3.0)
			{
				return false;
			}
		}
		
		return true;
	}
	
    protected EntityAI GetAttachmentFromSlot(string slot_name)
    {
        return EntityAI.Cast(FindAttachmentBySlotName(slot_name));
    }
	
    protected vector GetAttachmentPosition(string slot_name)
    {
        // Get the memory point position for the attachment slot
        vector pos = GetMemoryPointPos(slot_name + "_attachment");
        return ModelToWorld(pos);
    }
	
	protected bool IsItemAttached(EntityAI item, string slot_name)
    {
        EntityAI attached_item = GetAttachmentFromSlot(slot_name);
        return attached_item && attached_item == item;
    }

    protected string GetAttachmentSlotForItem(EntityAI item)
    {
        for (int i = 0; i < m_AttachmentSlots.Count(); i++)
        {
            if (IsItemAttached(item, m_AttachmentSlots[i]))
            {
                return m_AttachmentSlots[i];
            }
        }
        return "";
    }

    override void OnVariablesSynchronized()
    {
        super.OnVariablesSynchronized();
        
        // Update visual state of attachments
        UpdateAttachmentProxies();
    }

    protected void UpdateAttachmentProxies()
    {
        for (int i = 0; i < m_AttachmentSlots.Count(); i++)
        {
            string slot = m_AttachmentSlots[i];
            EntityAI attachment = GetAttachmentFromSlot(slot);
            
            if (attachment)
            {
                // Show proxy for attached item
                ShowAttachmentProxy(slot, true);
            }
            else
            {
                // Hide proxy when no item is attached
                ShowAttachmentProxy(slot, false);
            }
        }
    }
	
	protected void ShowAttachmentProxy(string slot, bool show)
	{
		int index = m_AttachmentSlots.Find(slot);
		if (index != -1 && index < m_ProxySelections.Count())
		{
			// DayZ uses direct selection names instead of indices
			string proxyName = m_ProxySelections[index];
			if (proxyName != "")
			{
				// Use SetObjectTexture instead of SetSimpleHiddenSelectionState
				if (show)
				{
					ShowSelection(proxyName);
				}
				else
				{
					HideSelection(proxyName);
				}
			}
		}
	}
	
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
	
    // Clean up timers when rack is destroyed
    void ~SC_DryingRack()
    {
        
    }
}