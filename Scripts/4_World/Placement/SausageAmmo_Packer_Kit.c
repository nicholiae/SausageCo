class SausageAmmo_Packer_Kit extends ItemBase
{	
	ref protected EffectSound 						m_DeployLoopSound;
	protected Object								SausageAmmo_Packer_Kit1;	
	
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
		vector positionChange = "0 0.75 0";
		vector position += positionChange;
	#else
	override void OnPlacementComplete(Man player, vector position = "0 0.75 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
	#endif
			if (GetGame().IsServer())
			{
				EntityAI kitItem = EntityAI.Cast(GetGame().CreateObjectEx("SausageAmmo_Packer", position, ECE_PLACE_ON_SURFACE));
				vector positionChange = "0 0.7 0";
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

class SausageAmmo_Packer_Holo extends ItemBase
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

class SausageAmmo_Packer extends ItemBase
{ 	
	SBSConfig sbs_config = GetDayZGame().getSBSGlobals();
	private bool				m_AmmoPackerState = false;

	//use common variables across functions and friendly names
	private int slotId_Magazine45ACP;
	private int slotId_Magazine22;
	private int slotId_Magazine357;
	private int slotId_Magazine9x39;
	private int slotId_Magazine9x19;
	private int slotId_Magazine380;
	private int slotId_Magazine545x39;
	private int slotId_Magazine556x45;
	private int slotId_Magazine762x39;
	private int slotId_Magazine762x54;
	private int slotId_Magazine308Win;
	private int slotId_Magazine45ACP_2;
	private int slotId_Magazine22_2;
	private int slotId_Magazine357_2;
	private int slotId_Magazine9x39_2;
	private int slotId_Magazine9x19_2;
	private int slotId_Magazine380_2;
	private int slotId_Magazine545x39_2;
	private int slotId_Magazine556x45_2;
	private int slotId_Magazine762x39_2;
	private int slotId_Magazine762x54_2;
	private int slotId_Magazine308Win_2;
	private int slotId_Ammo45ACP;
	private int slotId_Ammo22;
	private int slotId_Ammo357;
	private int slotId_Ammo9x39;
	private int slotId_Ammo9x19;
	private int slotId_Ammo380;
	private int slotId_Ammo545x39;
	private int slotId_Ammo556x45;
	private int slotId_Ammo762x39;
	private int slotId_Ammo762x54;
	private int slotId_Ammo308Win;
	
	private MagazineStorage m_Magazine45ACP;
	private MagazineStorage m_Magazine22;
	private MagazineStorage m_Magazine357;
	private MagazineStorage m_Magazine9x39;
	private MagazineStorage m_Magazine9x19;
	private MagazineStorage m_Magazine380;
	private MagazineStorage m_Magazine545x39;
	private MagazineStorage m_Magazine556x45;
	private MagazineStorage m_Magazine762x39;
	private MagazineStorage m_Magazine762x54;
	private MagazineStorage m_Magazine308Win;
	private MagazineStorage m_Magazine45ACP_2;
	private MagazineStorage m_Magazine22_2;
	private MagazineStorage m_Magazine357_2;
	private MagazineStorage m_Magazine9x39_2;
	private MagazineStorage m_Magazine9x19_2;
	private MagazineStorage m_Magazine380_2;
	private MagazineStorage m_Magazine545x39_2;
	private MagazineStorage m_Magazine556x45_2;
	private MagazineStorage m_Magazine762x39_2;
	private MagazineStorage m_Magazine762x54_2;
	private MagazineStorage m_Magazine308Win_2;
	
	private Ammunition_Base m_Ammo45ACP;
	private Ammunition_Base m_Ammo22;
	private Ammunition_Base m_Ammo357;
	private Ammunition_Base m_Ammo9x39;
	private Ammunition_Base m_Ammo9x19;
	private Ammunition_Base m_Ammo380;
	private Ammunition_Base m_Ammo545x39;
	private Ammunition_Base m_Ammo556x45;
	private Ammunition_Base m_Ammo762x39;
	private Ammunition_Base m_Ammo762x54;
	private Ammunition_Base m_Ammo308Win;
	
	private int countAmmo45ACP;
	private int countAmmo22;
	private int countAmmo357;
	private int countAmmo9x39;
	private int countAmmo9x19;
	private int countAmmo380;
	private int countAmmo545x39;
	private int countAmmo556x45;
	private int countAmmo762x39;
	private int countAmmo762x54;
	private int countAmmo308Win;
	private int countMagazine45ACP;
	private int countMagazine22;
	private int countMagazine357;
	private int countMagazine9x39;
	private int countMagazine9x19;
	private int countMagazine380;
	private int countMagazine545x39;
	private int countMagazine556x45;
	private int countMagazine762x39;
	private int countMagazine762x54;
	private int countMagazine308Win;
	
	private int ammoCount;
	
	private int percentageMagazine45ACP;
	private int percentageMagazine22;
	private int percentageMagazine357;
	private int percentageMagazine9x39;
	private int percentageMagazine9x19;
	private int percentageMagazine380;
	private int percentageMagazine545x39;
	private int percentageMagazine556x45;
	private int percentageMagazine762x39;
	private int percentageMagazine762x54;
	private int percentageMagazine308Win;
	
	private int countMagazine45ACP_2;
	private int countMagazine22_2;
	private int countMagazine357_2;
	private int countMagazine9x39_2;
	private int countMagazine9x19_2;
	private int countMagazine380_2;
	private int countMagazine545x39_2;
	private int countMagazine556x45_2;
	private int countMagazine762x39_2;
	private int countMagazine762x54_2;
	private int countMagazine308Win_2;
	
	private int percentageMagazine45ACP_2;
	private int percentageMagazine22_2;
	private int percentageMagazine357_2;
	private int percentageMagazine9x39_2;
	private int percentageMagazine9x19_2;
	private int percentageMagazine380_2;
	private int percentageMagazine545x39_2;
	private int percentageMagazine556x45_2;
	private int percentageMagazine762x39_2;
	private int percentageMagazine762x54_2;
	private int percentageMagazine308Win_2;

	
	

	
	void SausageAmmo_Packer()
	{
		//we register this to sync it on the network because on action we need to know on client if its on or not
		RegisterNetSyncVariableBool("m_AmmoPackerState");
	}

	void ~SausageAmmo_Packer()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName( this, "ProcessAmmunitionAndMagazines"); 
	}

	void SwitchOnServer()
	{
		m_AmmoPackerState = true;
		int SBSAmmo_PackerTime = 0.85;		
		int PackTime = SBSAmmo_PackerTime * 1000; // converting to milliseconds for Callback Queue
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( ProcessAmmunitionAndMagazines, PackTime, true );
	}

	void SwitchOffServer()
	{
		m_AmmoPackerState = false;
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName( this, "ProcessAmmunitionAndMagazines"); 
	}

	bool IsAmmoPackerOn()
	{
		return m_AmmoPackerState;
	}

	override bool CanReleaseAttachment(EntityAI attachment)
	{
		return !m_AmmoPackerState;
	}

    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }
    
	override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }

	
	bool CanProcessAmmo308Win()
	{
		slotId_Ammo308Win = InventorySlots.GetSlotIdFromString("Ammo308Win");// getting slot ID of Ammo308Win as defined in config.cpp for the SausageAmmo_Packer
		m_Ammo308Win = Ammunition_Base.Cast( GetInventory().FindAttachment(slotId_Ammo308Win) );// using slot ID to identify an entity in game to manipulate later, without we could not manipulate an item in game
		slotId_Magazine308Win = InventorySlots.GetSlotIdFromString("Magazine308Win");
		m_Magazine308Win = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine308Win) );
		slotId_Magazine308Win_2 = InventorySlots.GetSlotIdFromString("Magazine308Win_2");
		m_Magazine308Win_2 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine308Win_2) );
		
		
		if (m_Ammo308Win && m_Magazine308Win)
		{
			countAmmo308Win = m_Ammo308Win.GetQuantity(); //get stacksize of ammo
			// Print (countAmmo308Win.ToString() + "308Win ammo COUNT");
			countMagazine308Win = m_Magazine308Win.GetAmmoMax() - m_Magazine308Win.GetAmmoCount(); // count the remaining slots in the magazine
			// countMagazine308Win_2 = m_Magazine308Win_2.GetAmmoMax() - m_Magazine308Win_2.GetAmmoCount();  // count the remaining slots in the 2nd magazine
			// Print (countMagazine308Win.ToString() + "308Win Magazine COUNT");
			percentageMagazine308Win = m_Magazine308Win.GetAmmoCount() / m_Magazine308Win.GetAmmoMax(); // perecent filled magazine
			// Print (percentageMagazine308Win.ToString() + "308Win Magazine PERCENTAGE");
			if (m_Ammo308Win && m_Magazine308Win_2)
			{
				percentageMagazine308Win_2 = m_Magazine308Win_2.GetAmmoCount() / m_Magazine308Win_2.GetAmmoMax();
				if (percentageMagazine308Win_2 == 1)
				{
					return false;
				}
			}
			if (percentageMagazine308Win == 1)
			{
				return false;
			}
			return true; 
		}
		return false;
	}
	bool CanProcessAmmo762x54()
	{
		slotId_Ammo762x54 = InventorySlots.GetSlotIdFromString("Ammo762x54");// getting slot ID of Ammo762x54 as defined in config.cpp for the SausageAmmo_Packer
		m_Ammo762x54 = Ammunition_Base.Cast( GetInventory().FindAttachment(slotId_Ammo762x54) );// using slot ID to identify an entity in game to manipulate later, without we could not manipulate an item in game
		slotId_Magazine762x54 = InventorySlots.GetSlotIdFromString("Magazine762x54");
		m_Magazine762x54 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine762x54) );
		slotId_Magazine762x54_2 = InventorySlots.GetSlotIdFromString("Magazine762x54_2");
		m_Magazine762x54_2 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine762x54_2) );
		
		
		if (m_Ammo762x54 && m_Magazine762x54)
		{
			countAmmo762x54 = m_Ammo762x54.GetQuantity(); //get stacksize of ammo
			// Print (countAmmo762x54.ToString() + "762x54 ammo COUNT");
			countMagazine762x54 = m_Magazine762x54.GetAmmoMax() - m_Magazine762x54.GetAmmoCount(); // count the remaining slots in the magazine
			// countMagazine762x54_2 = m_Magazine762x54_2.GetAmmoMax() - m_Magazine762x54_2.GetAmmoCount();  // count the remaining slots in the 2nd magazine
			// Print (countMagazine762x54.ToString() + "762x54 Magazine COUNT");
			percentageMagazine762x54 = m_Magazine762x54.GetAmmoCount() / m_Magazine762x54.GetAmmoMax(); // perecent filled magazine
			// Print (percentageMagazine762x54.ToString() + "762x54 Magazine PERCENTAGE");
			if (m_Ammo762x54 && m_Magazine762x54_2)
			{
				percentageMagazine762x54_2 = m_Magazine762x54_2.GetAmmoCount() / m_Magazine762x54_2.GetAmmoMax();
				if (percentageMagazine762x54_2 == 1)
				{
					return false;
				}
			}
			if (percentageMagazine762x54 == 1)
			{
				return false;
			}
			return true; 
		}
		return false;
	}
	bool CanProcessAmmo762x39()
	{
		slotId_Ammo762x39 = InventorySlots.GetSlotIdFromString("Ammo762x39");// getting slot ID of Ammo762x39 as defined in config.cpp for the SausageAmmo_Packer
		m_Ammo762x39 = Ammunition_Base.Cast( GetInventory().FindAttachment(slotId_Ammo762x39) );// using slot ID to identify an entity in game to manipulate later, without we could not manipulate an item in game
		slotId_Magazine762x39 = InventorySlots.GetSlotIdFromString("Magazine762x39");
		m_Magazine762x39 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine762x39) );
		slotId_Magazine762x39_2 = InventorySlots.GetSlotIdFromString("Magazine762x39_2");
		m_Magazine762x39_2 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine762x39_2) );
		
		
		if (m_Ammo762x39 && m_Magazine762x39)
		{
			countAmmo762x39 = m_Ammo762x39.GetQuantity(); //get stacksize of ammo
			// Print (countAmmo762x39.ToString() + "762x39 ammo COUNT");
			countMagazine762x39 = m_Magazine762x39.GetAmmoMax() - m_Magazine762x39.GetAmmoCount(); // count the remaining slots in the magazine
			// countMagazine762x39_2 = m_Magazine762x39_2.GetAmmoMax() - m_Magazine762x39_2.GetAmmoCount();  // count the remaining slots in the 2nd magazine
			// Print (countMagazine762x39.ToString() + "762x39 Magazine COUNT");
			percentageMagazine762x39 = m_Magazine762x39.GetAmmoCount() / m_Magazine762x39.GetAmmoMax(); // perecent filled magazine
			// Print (percentageMagazine762x39.ToString() + "762x39 Magazine PERCENTAGE");
			if (m_Ammo762x39 && m_Magazine762x39_2)
			{
				percentageMagazine762x39_2 = m_Magazine762x39_2.GetAmmoCount() / m_Magazine762x39_2.GetAmmoMax();
				if (percentageMagazine762x39_2 == 1)
				{
					return false;
				}
			}
			if (percentageMagazine762x39 == 1)
			{
				return false;
			}
			return true; 
		}
		return false;
	}
	bool CanProcessAmmo556x45()
	{
		slotId_Ammo556x45 = InventorySlots.GetSlotIdFromString("Ammo556x45");// getting slot ID of Ammo556x45 as defined in config.cpp for the SausageAmmo_Packer
		m_Ammo556x45 = Ammunition_Base.Cast( GetInventory().FindAttachment(slotId_Ammo556x45) );// using slot ID to identify an entity in game to manipulate later, without we could not manipulate an item in game
		slotId_Magazine556x45 = InventorySlots.GetSlotIdFromString("Magazine556x45");
		m_Magazine556x45 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine556x45) );
		slotId_Magazine556x45_2 = InventorySlots.GetSlotIdFromString("Magazine556x45_2");
		m_Magazine556x45_2 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine556x45_2) );
		
		
		if (m_Ammo556x45 && m_Magazine556x45)
		{
			countAmmo556x45 = m_Ammo556x45.GetQuantity(); //get stacksize of ammo
			// Print (countAmmo556x45.ToString() + "556x45 ammo COUNT");
			countMagazine556x45 = m_Magazine556x45.GetAmmoMax() - m_Magazine556x45.GetAmmoCount(); // count the remaining slots in the magazine
			// countMagazine556x45_2 = m_Magazine556x45_2.GetAmmoMax() - m_Magazine556x45_2.GetAmmoCount();  // count the remaining slots in the 2nd magazine
			// Print (countMagazine556x45.ToString() + "556x45 Magazine COUNT");
			percentageMagazine556x45 = m_Magazine556x45.GetAmmoCount() / m_Magazine556x45.GetAmmoMax(); // perecent filled magazine
			// Print (percentageMagazine556x45.ToString() + "556x45 Magazine PERCENTAGE");
			if (m_Ammo556x45 && m_Magazine556x45_2)
			{
				percentageMagazine556x45_2 = m_Magazine556x45_2.GetAmmoCount() / m_Magazine556x45_2.GetAmmoMax();
				if (percentageMagazine556x45_2 == 1)
				{
					return false;
				}
			}
			if (percentageMagazine556x45 == 1)
			{
				return false;
			}
			return true; 
		}
		return false;
	}
	bool CanProcessAmmo545x39()
	{
		slotId_Ammo545x39 = InventorySlots.GetSlotIdFromString("Ammo545x39");// getting slot ID of Ammo545x39 as defined in config.cpp for the SausageAmmo_Packer
		m_Ammo545x39 = Ammunition_Base.Cast( GetInventory().FindAttachment(slotId_Ammo545x39) );// using slot ID to identify an entity in game to manipulate later, without we could not manipulate an item in game
		slotId_Magazine545x39 = InventorySlots.GetSlotIdFromString("Magazine545x39");
		m_Magazine545x39 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine545x39) );
		slotId_Magazine545x39_2 = InventorySlots.GetSlotIdFromString("Magazine545x39_2");
		m_Magazine545x39_2 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine545x39_2) );
		
		
		if (m_Ammo545x39 && m_Magazine545x39)
		{
			countAmmo545x39 = m_Ammo545x39.GetQuantity(); //get stacksize of ammo
			// Print (countAmmo545x39.ToString() + "545x39 ammo COUNT");
			countMagazine545x39 = m_Magazine545x39.GetAmmoMax() - m_Magazine545x39.GetAmmoCount(); // count the remaining slots in the magazine
			// countMagazine545x39_2 = m_Magazine545x39_2.GetAmmoMax() - m_Magazine545x39_2.GetAmmoCount();  // count the remaining slots in the 2nd magazine
			// Print (countMagazine545x39.ToString() + "545x39 Magazine COUNT");
			percentageMagazine545x39 = m_Magazine545x39.GetAmmoCount() / m_Magazine545x39.GetAmmoMax(); // perecent filled magazine
			// Print (percentageMagazine545x39.ToString() + "545x39 Magazine PERCENTAGE");
			if (m_Ammo545x39 && m_Magazine545x39_2)
			{
				percentageMagazine545x39_2 = m_Magazine545x39_2.GetAmmoCount() / m_Magazine545x39_2.GetAmmoMax();
				if (percentageMagazine545x39_2 == 1)
				{
					return false;
				}
			}
			if (percentageMagazine545x39 == 1)
			{
				return false;
			}
			return true; 
		}
		return false;
	}
	bool CanProcessAmmo380()
	{
		slotId_Ammo380 = InventorySlots.GetSlotIdFromString("Ammo380");// getting slot ID of Ammo380 as defined in config.cpp for the SausageAmmo_Packer
		m_Ammo380 = Ammunition_Base.Cast( GetInventory().FindAttachment(slotId_Ammo380) );// using slot ID to identify an entity in game to manipulate later, without we could not manipulate an item in game
		slotId_Magazine380 = InventorySlots.GetSlotIdFromString("Magazine380");
		m_Magazine380 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine380) );
		slotId_Magazine380_2 = InventorySlots.GetSlotIdFromString("Magazine380_2");
		m_Magazine380_2 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine380_2) );
		
		
		if (m_Ammo380 && m_Magazine380)
		{
			countAmmo380 = m_Ammo380.GetQuantity(); //get stacksize of ammo
			// Print (countAmmo380.ToString() + "380 ammo COUNT");
			countMagazine380 = m_Magazine380.GetAmmoMax() - m_Magazine380.GetAmmoCount(); // count the remaining slots in the magazine
			// countMagazine380_2 = m_Magazine380_2.GetAmmoMax() - m_Magazine380_2.GetAmmoCount();  // count the remaining slots in the 2nd magazine
			// Print (countMagazine380.ToString() + "380 Magazine COUNT");
			percentageMagazine380 = m_Magazine380.GetAmmoCount() / m_Magazine380.GetAmmoMax(); // perecent filled magazine
			// Print (percentageMagazine380.ToString() + "380 Magazine PERCENTAGE");
			if (m_Ammo380 && m_Magazine380_2)
			{
				percentageMagazine380_2 = m_Magazine380_2.GetAmmoCount() / m_Magazine380_2.GetAmmoMax();
				if (percentageMagazine380_2 == 1)
				{
					return false;
				}
			}
			if (percentageMagazine380 == 1)
			{
				return false;
			}
			return true; 
		}
		return false;
	}
	bool CanProcessAmmo9x19()
	{
		slotId_Ammo9x19 = InventorySlots.GetSlotIdFromString("Ammo9x19");// getting slot ID of Ammo9x19 as defined in config.cpp for the SausageAmmo_Packer
		m_Ammo9x19 = Ammunition_Base.Cast( GetInventory().FindAttachment(slotId_Ammo9x19) );// using slot ID to identify an entity in game to manipulate later, without we could not manipulate an item in game
		slotId_Magazine9x19 = InventorySlots.GetSlotIdFromString("Magazine9x19");
		m_Magazine9x19 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine9x19) );
		slotId_Magazine9x19_2 = InventorySlots.GetSlotIdFromString("Magazine9x19_2");
		m_Magazine9x19_2 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine9x19_2) );
		
		
		if (m_Ammo9x19 && m_Magazine9x19)
		{
			countAmmo9x19 = m_Ammo9x19.GetQuantity(); //get stacksize of ammo
			// Print (countAmmo9x19.ToString() + "9x19 ammo COUNT");
			countMagazine9x19 = m_Magazine9x19.GetAmmoMax() - m_Magazine9x19.GetAmmoCount(); // count the remaining slots in the magazine
			// countMagazine9x19_2 = m_Magazine9x19_2.GetAmmoMax() - m_Magazine9x19_2.GetAmmoCount();  // count the remaining slots in the 2nd magazine
			// Print (countMagazine9x19.ToString() + "9x19 Magazine COUNT");
			percentageMagazine9x19 = m_Magazine9x19.GetAmmoCount() / m_Magazine9x19.GetAmmoMax(); // perecent filled magazine
			// Print (percentageMagazine9x19.ToString() + "9x19 Magazine PERCENTAGE");
			if (m_Ammo9x19 && m_Magazine9x19_2)
			{
				percentageMagazine9x19_2 = m_Magazine9x19_2.GetAmmoCount() / m_Magazine9x19_2.GetAmmoMax();
				if (percentageMagazine9x19_2 == 1)
				{
					return false;
				}
			}
			if (percentageMagazine9x19 == 1)
			{
				return false;
			}
			return true; 
		}
		return false;
	}
	bool CanProcessAmmo9x39()
	{
		slotId_Ammo9x39 = InventorySlots.GetSlotIdFromString("Ammo9x39");// getting slot ID of Ammo9x39 as defined in config.cpp for the SausageAmmo_Packer
		m_Ammo9x39 = Ammunition_Base.Cast( GetInventory().FindAttachment(slotId_Ammo9x39) );// using slot ID to identify an entity in game to manipulate later, without we could not manipulate an item in game
		slotId_Magazine9x39 = InventorySlots.GetSlotIdFromString("Magazine9x39");
		m_Magazine9x39 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine9x39) );
		slotId_Magazine9x39_2 = InventorySlots.GetSlotIdFromString("Magazine9x39_2");
		m_Magazine9x39_2 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine9x39_2) );
		
		
		if (m_Ammo9x39 && m_Magazine9x39)
		{
			countAmmo9x39 = m_Ammo9x39.GetQuantity(); //get stacksize of ammo
			// Print (countAmmo9x39.ToString() + "9x39 ammo COUNT");
			countMagazine9x39 = m_Magazine9x39.GetAmmoMax() - m_Magazine9x39.GetAmmoCount(); // count the remaining slots in the magazine
			// countMagazine9x39_2 = m_Magazine9x39_2.GetAmmoMax() - m_Magazine9x39_2.GetAmmoCount();  // count the remaining slots in the 2nd magazine
			// Print (countMagazine9x39.ToString() + "9x39 Magazine COUNT");
			percentageMagazine9x39 = m_Magazine9x39.GetAmmoCount() / m_Magazine9x39.GetAmmoMax(); // perecent filled magazine
			// Print (percentageMagazine9x39.ToString() + "9x39 Magazine PERCENTAGE");
			if (m_Ammo9x39 && m_Magazine9x39_2)
			{
				percentageMagazine9x39_2 = m_Magazine9x39_2.GetAmmoCount() / m_Magazine9x39_2.GetAmmoMax();
				if (percentageMagazine9x39_2 == 1)
				{
					return false;
				}
			}
			if (percentageMagazine9x39 == 1)
			{
				return false;
			}
			return true; 
		}
		return false;
	}
	bool CanProcessAmmo357()
	{
		slotId_Ammo357 = InventorySlots.GetSlotIdFromString("Ammo357");// getting slot ID of Ammo357 as defined in config.cpp for the SausageAmmo_Packer
		m_Ammo357 = Ammunition_Base.Cast( GetInventory().FindAttachment(slotId_Ammo357) );// using slot ID to identify an entity in game to manipulate later, without we could not manipulate an item in game
		slotId_Magazine357 = InventorySlots.GetSlotIdFromString("Magazine357");
		m_Magazine357 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine357) );
		slotId_Magazine357_2 = InventorySlots.GetSlotIdFromString("Magazine357_2");
		m_Magazine357_2 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine357_2) );
		
		
		if (m_Ammo357 && m_Magazine357)
		{
			countAmmo357 = m_Ammo357.GetQuantity(); //get stacksize of ammo
			// Print (countAmmo357.ToString() + "357 ammo COUNT");
			countMagazine357 = m_Magazine357.GetAmmoMax() - m_Magazine357.GetAmmoCount(); // count the remaining slots in the magazine
			// countMagazine357_2 = m_Magazine357_2.GetAmmoMax() - m_Magazine357_2.GetAmmoCount();  // count the remaining slots in the 2nd magazine
			// Print (countMagazine357.ToString() + "357 Magazine COUNT");
			percentageMagazine357 = m_Magazine357.GetAmmoCount() / m_Magazine357.GetAmmoMax(); // perecent filled magazine
			// Print (percentageMagazine357.ToString() + "357 Magazine PERCENTAGE");
			if (m_Ammo357 && m_Magazine357_2)
			{
				percentageMagazine357_2 = m_Magazine357_2.GetAmmoCount() / m_Magazine357_2.GetAmmoMax();
				if (percentageMagazine357_2 == 1)
				{
					return false;
				}
			}
			if (percentageMagazine357 == 1)
			{
				return false;
			}
			return true; 
		}
		return false;
	}
	bool CanProcessAmmo22()
	{
		slotId_Ammo22 = InventorySlots.GetSlotIdFromString("Ammo22");// getting slot ID of Ammo22 as defined in config.cpp for the SausageAmmo_Packer
		m_Ammo22 = Ammunition_Base.Cast( GetInventory().FindAttachment(slotId_Ammo22) );// using slot ID to identify an entity in game to manipulate later, without we could not manipulate an item in game
		slotId_Magazine22 = InventorySlots.GetSlotIdFromString("Magazine22");
		m_Magazine22 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine22) );
		slotId_Magazine22_2 = InventorySlots.GetSlotIdFromString("Magazine22_2");
		m_Magazine22_2 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine22_2) );
		
		
		if (m_Ammo22 && m_Magazine22)
		{
			countAmmo22 = m_Ammo22.GetQuantity(); //get stacksize of ammo
			// Print (countAmmo22.ToString() + "22 ammo COUNT");
			countMagazine22 = m_Magazine22.GetAmmoMax() - m_Magazine22.GetAmmoCount(); // count the remaining slots in the magazine
			// countMagazine22_2 = m_Magazine22_2.GetAmmoMax() - m_Magazine22_2.GetAmmoCount();  // count the remaining slots in the 2nd magazine
			// Print (countMagazine22.ToString() + "22 Magazine COUNT");
			percentageMagazine22 = m_Magazine22.GetAmmoCount() / m_Magazine22.GetAmmoMax(); // perecent filled magazine
			// Print (percentageMagazine22.ToString() + "22 Magazine PERCENTAGE");
			if (m_Ammo22 && m_Magazine22_2)
			{
				percentageMagazine22_2 = m_Magazine22_2.GetAmmoCount() / m_Magazine22_2.GetAmmoMax();
				if (percentageMagazine22_2 == 1)
				{
					return false;
				}
			}
			if (percentageMagazine22 == 1)
			{
				return false;
			}
			return true; 
		}
		return false;
	}
	bool CanProcessAmmo45()
	{
		slotId_Ammo45ACP = InventorySlots.GetSlotIdFromString("Ammo45ACP");//getting slot ID of Ammo45ACP as defined in config.cpp for the SausageAmmo_Packer
		m_Ammo45ACP = Ammunition_Base.Cast( GetInventory().FindAttachment(slotId_Ammo45ACP) );//using that slot ID to identify an entity in game to manipulate late
		slotId_Magazine45ACP = InventorySlots.GetSlotIdFromString("Magazine45ACP");
		m_Magazine45ACP = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine45ACP) );
		slotId_Magazine45ACP_2 = InventorySlots.GetSlotIdFromString("Magazine45ACP_2");
		m_Magazine45ACP_2 = MagazineStorage.Cast( GetInventory().FindAttachment(slotId_Magazine45ACP_2) );
		
		
		if (m_Ammo45ACP && m_Magazine45ACP)
		{
			countAmmo45ACP = m_Ammo45ACP.GetQuantity(); //get stacksize of ammo
			// Print (countAmmo45ACP.ToString() + "45ACP ammo COUNT");
			countMagazine45ACP = m_Magazine45ACP.GetAmmoMax() - m_Magazine45ACP.GetAmmoCount(); // count the remaining slots in the magazine
			// countMagazine45ACP_2 = m_Magazine45ACP_2.GetAmmoMax() - m_Magazine45ACP_2.GetAmmoCount(); // count the remaining slots in the 2nd magazine
			// Print (countMagazine45ACP.ToString() + "45ACP Magazine COUNT");
			percentageMagazine45ACP = m_Magazine45ACP.GetAmmoCount() / m_Magazine45ACP.GetAmmoMax(); // perecent filled magazine
			// Print (percentageMagazine45ACP.ToString() + "45ACP Magazine PERCENTAGE");
			if (m_Ammo45ACP && m_Magazine45ACP_2)
			{
				percentageMagazine45ACP_2 = m_Magazine45ACP_2.GetAmmoCount() / m_Magazine45ACP_2.GetAmmoMax();
				if (percentageMagazine45ACP_2 == 1)
				{
					return false;
				}
			}
			if (percentageMagazine45ACP == 1)
			{
				return false;
			}
			return true; 
		}
		return false;
	}
	
	void ProcessAmmunitionAndMagazines()
	{
		int ammoCount = 1;
		
		if (GetGame().IsServer() && CanProcessAmmo45())  
		{
			
			percentageMagazine45ACP = m_Magazine45ACP.GetAmmoCount() / m_Magazine45ACP.GetAmmoMax();// perecent filled magazine
			if(m_Magazine45ACP_2)
			{
				percentageMagazine45ACP_2 = m_Magazine45ACP_2.GetAmmoCount() / m_Magazine45ACP_2.GetAmmoMax();// perecent filled 2nd magazine
			}
			if(m_Ammo45ACP.GetAmmoCount()==0)//Check to see if there is any ammo left in the stack
			{
				m_Ammo45ACP.Delete();//if not delete stack so we dont have 0 stacks
				SwitchOffServer();//if not turn off 
			}
			if(m_Magazine45ACP_2 && percentageMagazine45ACP_2 != 1)//check for a 2nd mag and that it is not full
			{
				m_Magazine45ACP_2.ServerAddAmmoCount(ammoCount);//if not full add 1 ammo to magazine
				m_Ammo45ACP.ServerAddAmmoCount(-ammoCount);//if not full minus 1 ammo from stack
			}
			if(!CanProcessAmmo45() || percentageMagazine45ACP == 1) //if we cannot process ammo OR mag 1 is full
			{
				SwitchOffServer();//turn off
			}
			m_Magazine45ACP.ServerAddAmmoCount(ammoCount);//if we have everything we need add ammo to magazine 1
			m_Ammo45ACP.ServerAddAmmoCount(-ammoCount);//if we have everything we need take way ammo from stack
		}
		
		
		if (GetGame().IsServer() && CanProcessAmmo22())  
		{
			percentageMagazine22 = m_Magazine22.GetAmmoCount() / m_Magazine22.GetAmmoMax();// perecent filled magazine
			if(m_Magazine22_2)
			{
				percentageMagazine22_2 = m_Magazine22_2.GetAmmoCount() / m_Magazine22_2.GetAmmoMax(); // perecent filled 2nd magazine
			}
			if(m_Ammo22.GetAmmoCount()==0)//Check to see if there is any ammo left in the stack
			{
				m_Ammo22.Delete();//if not delete stack so we dont have 0 stacks
				SwitchOffServer();//if not turn off 
			}
			if(m_Magazine22_2 && percentageMagazine22_2 != 1)//check for a 2nd mag and that it is not full
			{
				m_Magazine22_2.ServerAddAmmoCount(ammoCount);//if not full add 1 ammo to magazine
				m_Ammo22.ServerAddAmmoCount(-ammoCount);//if not full minus 1 ammo from stack
			}
			if(!CanProcessAmmo22() || percentageMagazine22 == 1)//if we cannot process ammo OR mag 1 is full
			{
				SwitchOffServer();//turn off
			}
			m_Magazine22.ServerAddAmmoCount(ammoCount);//if we have everything we need add ammo to magazine 1
			m_Ammo22.ServerAddAmmoCount(-ammoCount);//if we have everything we need take way ammo from stack
		}
		
		if (GetGame().IsServer() && CanProcessAmmo357())  
		{
			percentageMagazine357 = m_Magazine357.GetAmmoCount() / m_Magazine357.GetAmmoMax();// perecent filled magazine
			if(m_Magazine357_2)
			{
				percentageMagazine357_2 = m_Magazine357_2.GetAmmoCount() / m_Magazine357_2.GetAmmoMax(); // perecent filled 2nd magazine
			}
			if(m_Ammo357.GetAmmoCount()==0)//Check to see if there is any ammo left in the stack
			{
				m_Ammo357.Delete();//if not delete stack so we dont have 0 stacks
				SwitchOffServer();//if not turn off 
			}
			if(m_Magazine357_2 && percentageMagazine357_2 != 1)//check for a 2nd mag and that it is not full
			{
				m_Magazine357_2.ServerAddAmmoCount(ammoCount);//if not full add 1 ammo to magazine
				m_Ammo357.ServerAddAmmoCount(-ammoCount);//if not full minus 1 ammo from stack
			}
			if(!CanProcessAmmo357() || percentageMagazine357 == 1)//if we cannot process ammo OR mag 1 is full
			{
				SwitchOffServer();//turn off
			}
			m_Magazine357.ServerAddAmmoCount(ammoCount);//if we have everything we need add ammo to magazine 1
			m_Ammo357.ServerAddAmmoCount(-ammoCount);//if we have everything we need take way ammo from stack
		}
		if (GetGame().IsServer() && CanProcessAmmo9x39())   
		{
			percentageMagazine9x39 = m_Magazine9x39.GetAmmoCount() / m_Magazine9x39.GetAmmoMax();// perecent filled magazine
			if(m_Magazine9x39_2)
			{
				percentageMagazine9x39_2 = m_Magazine9x39_2.GetAmmoCount() / m_Magazine9x39_2.GetAmmoMax(); // perecent filled 2nd magazine
			}
			if(m_Ammo9x39.GetAmmoCount()==0)//Check to see if there is any ammo left in the stack
			{
				m_Ammo9x39.Delete();//if not delete stack so we dont have 0 stacks
				SwitchOffServer();//if not turn off 
			}
			if(m_Magazine9x39_2 && percentageMagazine9x39_2 != 1)//check for a 2nd mag and that it is not full
			{
				m_Magazine9x39_2.ServerAddAmmoCount(ammoCount);//if not full add 1 ammo to magazine
				m_Ammo9x39.ServerAddAmmoCount(-ammoCount);//if not full minus 1 ammo from stack
			}
			if(!CanProcessAmmo9x39() || percentageMagazine9x39 == 1)//if we cannot process ammo OR mag 1 is full
			{
				SwitchOffServer();//turn off
			}
			m_Magazine9x39.ServerAddAmmoCount(ammoCount);//if we have everything we need add ammo to magazine 1
			m_Ammo9x39.ServerAddAmmoCount(-ammoCount);//if we have everything we need take way ammo from stack
		}
		if (GetGame().IsServer() && CanProcessAmmo9x19())   
		{
			percentageMagazine9x19 = m_Magazine9x19.GetAmmoCount() / m_Magazine9x19.GetAmmoMax();// perecent filled magazine
			if(m_Magazine9x19_2)
			{
				percentageMagazine9x19_2 = m_Magazine9x19_2.GetAmmoCount() / m_Magazine9x19_2.GetAmmoMax(); // perecent filled 2nd magazine
			}
			if(m_Ammo9x19.GetAmmoCount()==0)//Check to see if there is any ammo left in the stack
			{
				m_Ammo9x19.Delete();//if not delete stack so we dont have 0 stacks
				SwitchOffServer();//if not turn off 
			}
			if(m_Magazine9x19_2 && percentageMagazine9x19_2 != 1)//check for a 2nd mag and that it is not full
			{
				m_Magazine9x19_2.ServerAddAmmoCount(ammoCount);//if not full add 1 ammo to magazine
				m_Ammo9x19.ServerAddAmmoCount(-ammoCount);//if not full minus 1 ammo from stack
			}
			if(!CanProcessAmmo9x19() || percentageMagazine9x19 == 1)//if we cannot process ammo OR mag 1 is full
			{
				SwitchOffServer();//turn off
			}
			m_Magazine9x19.ServerAddAmmoCount(ammoCount);//if we have everything we need add ammo to magazine 1
			m_Ammo9x19.ServerAddAmmoCount(-ammoCount);//if we have everything we need take way ammo from stack
		}
		if (GetGame().IsServer() && CanProcessAmmo380())   
		{
			percentageMagazine380 = m_Magazine380.GetAmmoCount() / m_Magazine380.GetAmmoMax();// perecent filled magazine
			if(m_Magazine380_2)
			{
				percentageMagazine380_2 = m_Magazine380_2.GetAmmoCount() / m_Magazine380_2.GetAmmoMax(); // perecent filled 2nd magazine
			}
			if(m_Ammo380.GetAmmoCount()==0)//Check to see if there is any ammo left in the stack
			{
				m_Ammo380.Delete();//if not delete stack so we dont have 0 stacks
				SwitchOffServer();//if not turn off 
			}
			if(m_Magazine380_2 && percentageMagazine380_2 != 1)//check for a 2nd mag and that it is not full
			{
				m_Magazine380_2.ServerAddAmmoCount(ammoCount);//if not full add 1 ammo to magazine
				m_Ammo380.ServerAddAmmoCount(-ammoCount);//if not full minus 1 ammo from stack
			}
			if(!CanProcessAmmo380() || percentageMagazine380 == 1)//if we cannot process ammo OR mag 1 is full
			{
				SwitchOffServer();//turn off
			}
			m_Magazine380.ServerAddAmmoCount(ammoCount);//if we have everything we need add ammo to magazine 1
			m_Ammo380.ServerAddAmmoCount(-ammoCount);//if we have everything we need take way ammo from stack
		}
		if (GetGame().IsServer() && CanProcessAmmo545x39())  
		{
			percentageMagazine545x39 = m_Magazine545x39.GetAmmoCount() / m_Magazine545x39.GetAmmoMax();// perecent filled magazine
			if(m_Magazine545x39_2)
			{
				percentageMagazine545x39_2 = m_Magazine545x39_2.GetAmmoCount() / m_Magazine545x39_2.GetAmmoMax(); // perecent filled 2nd magazine
			}
			if(m_Ammo545x39.GetAmmoCount()==0)//Check to see if there is any ammo left in the stack
			{
				m_Ammo545x39.Delete();//if not delete stack so we dont have 0 stacks
				SwitchOffServer();//if not turn off 
			}
			if(m_Magazine545x39_2 && percentageMagazine545x39_2 != 1)//check for a 2nd mag and that it is not full
			{
				m_Magazine545x39_2.ServerAddAmmoCount(ammoCount);//if not full add 1 ammo to magazine
				m_Ammo545x39.ServerAddAmmoCount(-ammoCount);//if not full minus 1 ammo from stack
			}
			if(!CanProcessAmmo545x39() || percentageMagazine545x39 == 1)//if we cannot process ammo OR mag 1 is full
			{
				SwitchOffServer();//turn off
			}
			m_Magazine545x39.ServerAddAmmoCount(ammoCount);//if we have everything we need add ammo to magazine 1
			m_Ammo545x39.ServerAddAmmoCount(-ammoCount);//if we have everything we need take way ammo from stack
		}
		if (GetGame().IsServer() && CanProcessAmmo556x45())  
		{
			percentageMagazine556x45 = m_Magazine556x45.GetAmmoCount() / m_Magazine556x45.GetAmmoMax();// perecent filled magazine
			if(m_Magazine556x45_2)
			{
				percentageMagazine556x45_2 = m_Magazine556x45_2.GetAmmoCount() / m_Magazine556x45_2.GetAmmoMax(); // perecent filled 2nd magazine
			}
			if(m_Ammo556x45.GetAmmoCount()==0)//Check to see if there is any ammo left in the stack
			{
				m_Ammo556x45.Delete();//if not delete stack so we dont have 0 stacks
				SwitchOffServer();//if not turn off 
			}
			if(m_Magazine556x45_2 && percentageMagazine556x45_2 != 1)//check for a 2nd mag and that it is not full
			{
				m_Magazine556x45_2.ServerAddAmmoCount(ammoCount);//if not full add 1 ammo to magazine
				m_Ammo556x45.ServerAddAmmoCount(-ammoCount);//if not full minus 1 ammo from stack
			}
			if(!CanProcessAmmo556x45() || percentageMagazine556x45 == 1)//if we cannot process ammo OR mag 1 is full
			{
				SwitchOffServer();//turn off
			}
			m_Magazine556x45.ServerAddAmmoCount(ammoCount);//if we have everything we need add ammo to magazine 1
			m_Ammo556x45.ServerAddAmmoCount(-ammoCount);//if we have everything we need take way ammo from stack
		}
		if (GetGame().IsServer() && CanProcessAmmo762x39())  
		{
			percentageMagazine762x39 = m_Magazine762x39.GetAmmoCount() / m_Magazine762x39.GetAmmoMax();// perecent filled magazine
			if(m_Magazine762x39_2)
			{
				percentageMagazine762x39_2 = m_Magazine762x39_2.GetAmmoCount() / m_Magazine762x39_2.GetAmmoMax(); // perecent filled 2nd magazine
			}
			if(m_Ammo762x39.GetAmmoCount()==0)//Check to see if there is any ammo left in the stack
			{
				m_Ammo762x39.Delete();//if not delete stack so we dont have 0 stacks
				SwitchOffServer();//if not turn off 
			}
			if(m_Magazine762x39_2 && percentageMagazine762x39_2 != 1)//check for a 2nd mag and that it is not full
			{
				m_Magazine762x39_2.ServerAddAmmoCount(ammoCount);//if not full add 1 ammo to magazine
				m_Ammo762x39.ServerAddAmmoCount(-ammoCount);//if not full minus 1 ammo from stack
			}
			if(!CanProcessAmmo762x39() || percentageMagazine762x39 == 1)//if we cannot process ammo OR mag 1 is full
			{
				SwitchOffServer();//turn off
			}
			m_Magazine762x39.ServerAddAmmoCount(ammoCount);//if we have everything we need add ammo to magazine 1
			m_Ammo762x39.ServerAddAmmoCount(-ammoCount);//if we have everything we need take way ammo from stack
		}
		if (GetGame().IsServer() && CanProcessAmmo762x54())   
		{
			percentageMagazine762x54 = m_Magazine762x54.GetAmmoCount() / m_Magazine762x54.GetAmmoMax();// perecent filled magazine
			if(m_Magazine762x54_2)
			{
				percentageMagazine762x54_2 = m_Magazine762x54_2.GetAmmoCount() / m_Magazine762x54_2.GetAmmoMax(); // perecent filled 2nd magazine
			}
			if(m_Ammo762x54.GetAmmoCount()==0)//Check to see if there is any ammo left in the stack
			{
				m_Ammo762x54.Delete();//if not delete stack so we dont have 0 stacks
				SwitchOffServer();//if not turn off 
			}
			if(m_Magazine762x54_2 && percentageMagazine762x54_2 != 1)//check for a 2nd mag and that it is not full
			{
				m_Magazine762x54_2.ServerAddAmmoCount(ammoCount);//if not full add 1 ammo to magazine
				m_Ammo762x54.ServerAddAmmoCount(-ammoCount);//if not full minus 1 ammo from stack
			}
			if(!CanProcessAmmo762x54() || percentageMagazine762x54 == 1)//if we cannot process ammo OR mag 1 is full
			{
				SwitchOffServer();//turn off
			}
			m_Magazine762x54.ServerAddAmmoCount(ammoCount);//if we have everything we need add ammo to magazine 1
			m_Ammo762x54.ServerAddAmmoCount(-ammoCount);//if we have everything we need take way ammo from stack
		}
		if (GetGame().IsServer() && CanProcessAmmo308Win())   
		{
			percentageMagazine308Win = m_Magazine308Win.GetAmmoCount() / m_Magazine308Win.GetAmmoMax();// perecent filled magazine
			if(m_Magazine308Win_2)
			{
				percentageMagazine308Win_2 = m_Magazine308Win_2.GetAmmoCount() / m_Magazine308Win_2.GetAmmoMax(); // perecent filled 2nd magazine
			}
			if(m_Ammo308Win.GetAmmoCount()==0)//Check to see if there is any ammo left in the stack
			{
				m_Ammo308Win.Delete();//if not delete stack so we dont have 0 stacks
				SwitchOffServer();//if not turn off 
			}
			if(m_Magazine308Win_2 && percentageMagazine308Win_2 != 1)//check for a 2nd mag and that it is not full
			{
				m_Magazine308Win_2.ServerAddAmmoCount(ammoCount);//if not full add 1 ammo to magazine
				m_Ammo308Win.ServerAddAmmoCount(-ammoCount);//if not full minus 1 ammo from stack
			}
			if(!CanProcessAmmo308Win() || percentageMagazine308Win == 1)//if we cannot process ammo OR mag 1 is full
			{
				SwitchOffServer();//turn off
			}
			m_Magazine308Win.ServerAddAmmoCount(ammoCount);//if we have everything we need add ammo to magazine 1
			m_Ammo308Win.ServerAddAmmoCount(-ammoCount);//if we have everything we need take way ammo from stack
		}
		//if we can't craft ANYTHING anymore turn it off
		if(!CanProcessAmmo9x39() && !CanProcessAmmo308Win() && !CanProcessAmmo762x54() && !CanProcessAmmo762x39() && !CanProcessAmmo556x45() && !CanProcessAmmo545x39() && !CanProcessAmmo380() && !CanProcessAmmo9x19() && !CanProcessAmmo22() && !CanProcessAmmo357() && !CanProcessAmmo45())
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
		AddAction(ActionTurnOnOffAmmoPacker);
    }
};
