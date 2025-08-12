class SausageWeed_Processor_Kit extends ItemBase
{	
	ref protected EffectSound 						m_DeployLoopSound;
	protected Object								SausageWeed_Processor_Kit1;	
	
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
		AddAction(ActionDeployObject);
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
				EntityAI kitItem = EntityAI.Cast(GetGame().CreateObjectEx("SausageWeed_Processor", position, ECE_PLACE_ON_SURFACE));
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

class SausageWeed_Processor_Holo extends ItemBase
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

class SausageWeed_Processor extends ItemBase
{ 	
	private bool				m_WeedProcessorState = false;

	//
	private int slotId_BasicCannabis;
	private int slotId_BasicCannabis1;
	private int slotId_BasicCannabis2;
	private int slotId_BasicCannabis3;
	private int slotId_BasicCannabis4;
	private int slotId_BasicCannabis5;
	private int slotId_BasicCannabis6;
	private int slotId_BasicCannabis7;
	private int slotId_BasicCannabisOunce;
	
	private ItemBase m_BasicCannabis;
	private ItemBase m_BasicCannabis1;
	private ItemBase m_BasicCannabis2;
	private ItemBase m_BasicCannabis3;
	private ItemBase m_BasicCannabis4;
	private ItemBase m_BasicCannabis5;
	private ItemBase m_BasicCannabis6;
	private ItemBase m_BasicCannabis7;
	private ItemBase m_BasicCannabisOunce;
	//
	private int slotId_AlaskanThunderFuckCannabis;
	private int slotId_AlaskanThunderFuckCannabis1;
	private int slotId_AlaskanThunderFuckCannabis2;
	private int slotId_AlaskanThunderFuckCannabis3;
	private int slotId_AlaskanThunderFuckCannabis4;
	private int slotId_AlaskanThunderFuckCannabis5;
	private int slotId_AlaskanThunderFuckCannabis6;
	private int slotId_AlaskanThunderFuckCannabis7;
	private int slotId_AlaskanThunderFuckCannabisOunce;
	
	private ItemBase m_AlaskanThunderFuckCannabis;
	private ItemBase m_AlaskanThunderFuckCannabis1;
	private ItemBase m_AlaskanThunderFuckCannabis2;
	private ItemBase m_AlaskanThunderFuckCannabis3;
	private ItemBase m_AlaskanThunderFuckCannabis4;
	private ItemBase m_AlaskanThunderFuckCannabis5;
	private ItemBase m_AlaskanThunderFuckCannabis6;
	private ItemBase m_AlaskanThunderFuckCannabis7;
	private ItemBase m_AlaskanThunderFuckCannabisOunce;
	//
	private int slotId_FireCrotchCannabis;
	private int slotId_FireCrotchCannabis1;
	private int slotId_FireCrotchCannabis2;
	private int slotId_FireCrotchCannabis3;
	private int slotId_FireCrotchCannabis4;
	private int slotId_FireCrotchCannabis5;
	private int slotId_FireCrotchCannabis6;
	private int slotId_FireCrotchCannabis7;
	private int slotId_FireCrotchCannabisOunce;
	
	private ItemBase m_FireCrotchCannabis;
	private ItemBase m_FireCrotchCannabis1;
	private ItemBase m_FireCrotchCannabis2;
	private ItemBase m_FireCrotchCannabis3;
	private ItemBase m_FireCrotchCannabis4;
	private ItemBase m_FireCrotchCannabis5;
	private ItemBase m_FireCrotchCannabis6;
	private ItemBase m_FireCrotchCannabis7;
	private ItemBase m_FireCrotchCannabisOunce;
	//
	private int slotId_BlueDreamCannabis;
	private int slotId_BlueDreamCannabis1;
	private int slotId_BlueDreamCannabis2;
	private int slotId_BlueDreamCannabis3;
	private int slotId_BlueDreamCannabis4;
	private int slotId_BlueDreamCannabis5;
	private int slotId_BlueDreamCannabis6;
	private int slotId_BlueDreamCannabis7;
	private int slotId_BlueDreamCannabisOunce;
	
	private ItemBase m_BlueDreamCannabis;
	private ItemBase m_BlueDreamCannabis1;
	private ItemBase m_BlueDreamCannabis2;
	private ItemBase m_BlueDreamCannabis3;
	private ItemBase m_BlueDreamCannabis4;
	private ItemBase m_BlueDreamCannabis5;
	private ItemBase m_BlueDreamCannabis6;
	private ItemBase m_BlueDreamCannabis7;
	private ItemBase m_BlueDreamCannabisOunce;
	//
	private int slotId_WhiteWidowCannabis;
	private int slotId_WhiteWidowCannabis1;
	private int slotId_WhiteWidowCannabis2;
	private int slotId_WhiteWidowCannabis3;
	private int slotId_WhiteWidowCannabis4;
	private int slotId_WhiteWidowCannabis5;
	private int slotId_WhiteWidowCannabis6;
	private int slotId_WhiteWidowCannabis7;
	private int slotId_WhiteWidowCannabisOunce;
	
	private ItemBase m_WhiteWidowCannabis;
	private ItemBase m_WhiteWidowCannabis1;
	private ItemBase m_WhiteWidowCannabis2;
	private ItemBase m_WhiteWidowCannabis3;
	private ItemBase m_WhiteWidowCannabis4;
	private ItemBase m_WhiteWidowCannabis5;
	private ItemBase m_WhiteWidowCannabis6;
	private ItemBase m_WhiteWidowCannabis7;
	private ItemBase m_WhiteWidowCannabisOunce;
	//
	private int slotId_TrainwreckCannabis;
	private int slotId_TrainwreckCannabis1;
	private int slotId_TrainwreckCannabis2;
	private int slotId_TrainwreckCannabis3;
	private int slotId_TrainwreckCannabis4;
	private int slotId_TrainwreckCannabis5;
	private int slotId_TrainwreckCannabis6;
	private int slotId_TrainwreckCannabis7;
	private int slotId_TrainwreckCannabisOunce;
	
	private ItemBase m_TrainwreckCannabis;
	private ItemBase m_TrainwreckCannabis1;
	private ItemBase m_TrainwreckCannabis2;
	private ItemBase m_TrainwreckCannabis3;
	private ItemBase m_TrainwreckCannabis4;
	private ItemBase m_TrainwreckCannabis5;
	private ItemBase m_TrainwreckCannabis6;
	private ItemBase m_TrainwreckCannabis7;
	private ItemBase m_TrainwreckCannabisOunce;
	//
	private int slotId_PineappleExpressCannabis;
	private int slotId_PineappleExpressCannabis1;
	private int slotId_PineappleExpressCannabis2;
	private int slotId_PineappleExpressCannabis3;
	private int slotId_PineappleExpressCannabis4;
	private int slotId_PineappleExpressCannabis5;
	private int slotId_PineappleExpressCannabis6;
	private int slotId_PineappleExpressCannabis7;
	private int slotId_PineappleExpressCannabisOunce;
	
	private ItemBase m_PineappleExpressCannabis;
	private ItemBase m_PineappleExpressCannabis1;
	private ItemBase m_PineappleExpressCannabis2;
	private ItemBase m_PineappleExpressCannabis3;
	private ItemBase m_PineappleExpressCannabis4;
	private ItemBase m_PineappleExpressCannabis5;
	private ItemBase m_PineappleExpressCannabis6;
	private ItemBase m_PineappleExpressCannabis7;
	private ItemBase m_PineappleExpressCannabisOunce;
	//
	private int slotId_GorillaGlueCannabis;
	private int slotId_GorillaGlueCannabis1;
	private int slotId_GorillaGlueCannabis2;
	private int slotId_GorillaGlueCannabis3;
	private int slotId_GorillaGlueCannabis4;
	private int slotId_GorillaGlueCannabis5;
	private int slotId_GorillaGlueCannabis6;
	private int slotId_GorillaGlueCannabis7;
	private int slotId_GorillaGlueCannabisOunce;
	
	private ItemBase m_GorillaGlueCannabis;
	private ItemBase m_GorillaGlueCannabis1;
	private ItemBase m_GorillaGlueCannabis2;
	private ItemBase m_GorillaGlueCannabis3;
	private ItemBase m_GorillaGlueCannabis4;
	private ItemBase m_GorillaGlueCannabis5;
	private ItemBase m_GorillaGlueCannabis6;
	private ItemBase m_GorillaGlueCannabis7;
	private ItemBase m_GorillaGlueCannabisOunce;
	//
	private int slotId_SourDieselCannabis;
	private int slotId_SourDieselCannabis1;
	private int slotId_SourDieselCannabis2;
	private int slotId_SourDieselCannabis3;
	private int slotId_SourDieselCannabis4;
	private int slotId_SourDieselCannabis5;
	private int slotId_SourDieselCannabis6;
	private int slotId_SourDieselCannabis7;
	private int slotId_SourDieselCannabisOunce;
	
	private ItemBase m_SourDieselCannabis;
	private ItemBase m_SourDieselCannabis1;
	private ItemBase m_SourDieselCannabis2;
	private ItemBase m_SourDieselCannabis3;
	private ItemBase m_SourDieselCannabis4;
	private ItemBase m_SourDieselCannabis5;
	private ItemBase m_SourDieselCannabis6;
	private ItemBase m_SourDieselCannabis7;
	private ItemBase m_SourDieselCannabisOunce;
	

	void SausageWeed_Processor()
	{
		//we register this to sync it on the network because on action we need to know on client if its on or not
		RegisterNetSyncVariableBool("m_WeedProcessorState");
	}

	void ~SausageWeed_Processor()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName( this, "ProcessWeed"); 
	}

	void SwitchOnServer()
	{
		m_WeedProcessorState = true;
		int SBSWeed_ProcessorTime = 0.75;		
		int PackTime = SBSWeed_ProcessorTime * 1000; // converting to milliseconds for Callback Queue
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( ProcessWeed, PackTime, true );
	}

	void SwitchOffServer()
	{
		m_WeedProcessorState = false;
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName( this, "ProcessWeed"); 
	}

	bool IsWeedProcessorOn()
	{
		return m_WeedProcessorState;
	}

	override bool CanReleaseAttachment(EntityAI attachment)
	{
		return !m_WeedProcessorState;
	}

    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }
    
	override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }
	bool CanProcessWeed()
	{
		slotId_BasicCannabis = InventorySlots.GetSlotIdFromString("cannabisT11");
		m_BasicCannabis = ItemBase.Cast( GetInventory().FindAttachment(slotId_BasicCannabis) );
		slotId_BasicCannabis1 = InventorySlots.GetSlotIdFromString("cannabisT12");
		m_BasicCannabis1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_BasicCannabis1) );
		slotId_BasicCannabis2 = InventorySlots.GetSlotIdFromString("cannabisT13");
		m_BasicCannabis2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_BasicCannabis2) );
		slotId_BasicCannabis3 = InventorySlots.GetSlotIdFromString("cannabisT14");
		m_BasicCannabis3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_BasicCannabis3) );
		slotId_BasicCannabis4 = InventorySlots.GetSlotIdFromString("cannabisT15");
		m_BasicCannabis4 = ItemBase.Cast( GetInventory().FindAttachment(slotId_BasicCannabis4) );
		slotId_BasicCannabis5 = InventorySlots.GetSlotIdFromString("cannabisT16");
		m_BasicCannabis5 = ItemBase.Cast( GetInventory().FindAttachment(slotId_BasicCannabis5) );
		slotId_BasicCannabis6 = InventorySlots.GetSlotIdFromString("cannabisT17");
		m_BasicCannabis6= ItemBase.Cast( GetInventory().FindAttachment(slotId_BasicCannabis6) );
		slotId_BasicCannabis7 = InventorySlots.GetSlotIdFromString("cannabisT18");
		m_BasicCannabis7 = ItemBase.Cast( GetInventory().FindAttachment(slotId_BasicCannabis7) );
		
		if (m_BasicCannabis && m_BasicCannabis1 && m_BasicCannabis2 && m_BasicCannabis3 && m_BasicCannabis4 && m_BasicCannabis5 && m_BasicCannabis6 && m_BasicCannabis7)
		{
			return true;
		}
		return false;
	}
	bool CanProcessPounds()
	{
		slotId_BasicCannabisOunce = InventorySlots.GetSlotIdFromString("BasicCannabisOunce");
		m_BasicCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_BasicCannabisOunce) );
		if(!m_BasicCannabisOunce)
		{
			return false;
		}
		if(m_BasicCannabisOunce.GetQuantity() == 16)
		{
			return true;
		}
		return false;
	}
	bool CanProcessWeedT2()
	{
		slotId_AlaskanThunderFuckCannabis = InventorySlots.GetSlotIdFromString("cannabisT21");
		m_AlaskanThunderFuckCannabis = ItemBase.Cast( GetInventory().FindAttachment(slotId_AlaskanThunderFuckCannabis) );
		slotId_AlaskanThunderFuckCannabis1 = InventorySlots.GetSlotIdFromString("cannabisT22");
		m_AlaskanThunderFuckCannabis1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_AlaskanThunderFuckCannabis1) );
		slotId_AlaskanThunderFuckCannabis2 = InventorySlots.GetSlotIdFromString("cannabisT23");
		m_AlaskanThunderFuckCannabis2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_AlaskanThunderFuckCannabis2) );
		slotId_AlaskanThunderFuckCannabis3 = InventorySlots.GetSlotIdFromString("cannabisT24");
		m_AlaskanThunderFuckCannabis3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_AlaskanThunderFuckCannabis3) );
		slotId_AlaskanThunderFuckCannabis4 = InventorySlots.GetSlotIdFromString("cannabisT25");
		m_AlaskanThunderFuckCannabis4 = ItemBase.Cast( GetInventory().FindAttachment(slotId_AlaskanThunderFuckCannabis4) );
		slotId_AlaskanThunderFuckCannabis5 = InventorySlots.GetSlotIdFromString("cannabisT26");
		m_AlaskanThunderFuckCannabis5 = ItemBase.Cast( GetInventory().FindAttachment(slotId_AlaskanThunderFuckCannabis5) );
		slotId_AlaskanThunderFuckCannabis6 = InventorySlots.GetSlotIdFromString("cannabisT27");
		m_AlaskanThunderFuckCannabis6= ItemBase.Cast( GetInventory().FindAttachment(slotId_AlaskanThunderFuckCannabis6) );
		slotId_AlaskanThunderFuckCannabis7 = InventorySlots.GetSlotIdFromString("cannabisT28");
		m_AlaskanThunderFuckCannabis7 = ItemBase.Cast( GetInventory().FindAttachment(slotId_AlaskanThunderFuckCannabis7) );
		
		if (m_AlaskanThunderFuckCannabis && m_AlaskanThunderFuckCannabis1 && m_AlaskanThunderFuckCannabis2 && m_AlaskanThunderFuckCannabis3 && m_AlaskanThunderFuckCannabis4 && m_AlaskanThunderFuckCannabis5 && m_AlaskanThunderFuckCannabis6 && m_AlaskanThunderFuckCannabis7)
		{
			return true;
		}
		return false;
	}
	bool CanProcessPoundsT2()
	{
		slotId_AlaskanThunderFuckCannabisOunce = InventorySlots.GetSlotIdFromString("AlaskanThunderFuckCannabisOunce");
		m_AlaskanThunderFuckCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_AlaskanThunderFuckCannabisOunce) );
		if(!m_AlaskanThunderFuckCannabisOunce)
		{
			return false;
		}
		if(m_AlaskanThunderFuckCannabisOunce.GetQuantity() == 16)
		{
			return true;
		}
		return false;
	}
	bool CanProcessWeedT3()
	{
		slotId_FireCrotchCannabis = InventorySlots.GetSlotIdFromString("cannabisT31");
		m_FireCrotchCannabis = ItemBase.Cast( GetInventory().FindAttachment(slotId_FireCrotchCannabis) );
		slotId_FireCrotchCannabis1 = InventorySlots.GetSlotIdFromString("cannabisT32");
		m_FireCrotchCannabis1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_FireCrotchCannabis1) );
		slotId_FireCrotchCannabis2 = InventorySlots.GetSlotIdFromString("cannabisT33");
		m_FireCrotchCannabis2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_FireCrotchCannabis2) );
		slotId_FireCrotchCannabis3 = InventorySlots.GetSlotIdFromString("cannabisT34");
		m_FireCrotchCannabis3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_FireCrotchCannabis3) );
		slotId_FireCrotchCannabis4 = InventorySlots.GetSlotIdFromString("cannabisT35");
		m_FireCrotchCannabis4 = ItemBase.Cast( GetInventory().FindAttachment(slotId_FireCrotchCannabis4) );
		slotId_FireCrotchCannabis5 = InventorySlots.GetSlotIdFromString("cannabisT36");
		m_FireCrotchCannabis5 = ItemBase.Cast( GetInventory().FindAttachment(slotId_FireCrotchCannabis5) );
		slotId_FireCrotchCannabis6 = InventorySlots.GetSlotIdFromString("cannabisT37");
		m_FireCrotchCannabis6= ItemBase.Cast( GetInventory().FindAttachment(slotId_FireCrotchCannabis6) );
		slotId_FireCrotchCannabis7 = InventorySlots.GetSlotIdFromString("cannabisT38");
		m_FireCrotchCannabis7 = ItemBase.Cast( GetInventory().FindAttachment(slotId_FireCrotchCannabis7) );
		
		if (m_FireCrotchCannabis && m_FireCrotchCannabis1 && m_FireCrotchCannabis2 && m_FireCrotchCannabis3 && m_FireCrotchCannabis4 && m_FireCrotchCannabis5 && m_FireCrotchCannabis6 && m_FireCrotchCannabis7)
		{
			return true;
		}
		return false;
	}
	bool CanProcessPoundsT3()
	{
		slotId_FireCrotchCannabisOunce = InventorySlots.GetSlotIdFromString("FireCrotchCannabisOunce");
		m_FireCrotchCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_FireCrotchCannabisOunce) );
		if(!m_FireCrotchCannabisOunce)
		{
			return false;
		}
		if(m_FireCrotchCannabisOunce.GetQuantity() == 16)
		{
			return true;
		}
		return false;
	}
	bool CanProcessWeedT4()
	{
		slotId_BlueDreamCannabis = InventorySlots.GetSlotIdFromString("cannabisT41");
		m_BlueDreamCannabis = ItemBase.Cast( GetInventory().FindAttachment(slotId_BlueDreamCannabis) );
		slotId_BlueDreamCannabis1 = InventorySlots.GetSlotIdFromString("cannabisT42");
		m_BlueDreamCannabis1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_BlueDreamCannabis1) );
		slotId_BlueDreamCannabis2 = InventorySlots.GetSlotIdFromString("cannabisT43");
		m_BlueDreamCannabis2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_BlueDreamCannabis2) );
		slotId_BlueDreamCannabis3 = InventorySlots.GetSlotIdFromString("cannabisT44");
		m_BlueDreamCannabis3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_BlueDreamCannabis3) );
		slotId_BlueDreamCannabis4 = InventorySlots.GetSlotIdFromString("cannabisT45");
		m_BlueDreamCannabis4 = ItemBase.Cast( GetInventory().FindAttachment(slotId_BlueDreamCannabis4) );
		slotId_BlueDreamCannabis5 = InventorySlots.GetSlotIdFromString("cannabisT46");
		m_BlueDreamCannabis5 = ItemBase.Cast( GetInventory().FindAttachment(slotId_BlueDreamCannabis5) );
		slotId_BlueDreamCannabis6 = InventorySlots.GetSlotIdFromString("cannabisT47");
		m_BlueDreamCannabis6= ItemBase.Cast( GetInventory().FindAttachment(slotId_BlueDreamCannabis6) );
		slotId_BlueDreamCannabis7 = InventorySlots.GetSlotIdFromString("cannabisT48");
		m_BlueDreamCannabis7 = ItemBase.Cast( GetInventory().FindAttachment(slotId_BlueDreamCannabis7) );
		
		if (m_BlueDreamCannabis && m_BlueDreamCannabis1 && m_BlueDreamCannabis2 && m_BlueDreamCannabis3 && m_BlueDreamCannabis4 && m_BlueDreamCannabis5 && m_BlueDreamCannabis6 && m_BlueDreamCannabis7)
		{
			return true;
		}
		return false;
	}
	bool CanProcessPoundsT4()
	{
		slotId_BlueDreamCannabisOunce = InventorySlots.GetSlotIdFromString("BlueDreamCannabisOunce");
		m_BlueDreamCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_BlueDreamCannabisOunce) );
		if(!m_BlueDreamCannabisOunce)
		{
			return false;
		}
		if(m_BlueDreamCannabisOunce.GetQuantity() == 16)
		{
			return true;
		}
		return false;
	}
	bool CanProcessWeedT5()
	{
		slotId_WhiteWidowCannabis = InventorySlots.GetSlotIdFromString("cannabisT51");
		m_WhiteWidowCannabis = ItemBase.Cast( GetInventory().FindAttachment(slotId_WhiteWidowCannabis) );
		slotId_WhiteWidowCannabis1 = InventorySlots.GetSlotIdFromString("cannabisT52");
		m_WhiteWidowCannabis1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_WhiteWidowCannabis1) );
		slotId_WhiteWidowCannabis2 = InventorySlots.GetSlotIdFromString("cannabisT53");
		m_WhiteWidowCannabis2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_WhiteWidowCannabis2) );
		slotId_WhiteWidowCannabis3 = InventorySlots.GetSlotIdFromString("cannabisT54");
		m_WhiteWidowCannabis3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_WhiteWidowCannabis3) );
		slotId_WhiteWidowCannabis4 = InventorySlots.GetSlotIdFromString("cannabisT55");
		m_WhiteWidowCannabis4 = ItemBase.Cast( GetInventory().FindAttachment(slotId_WhiteWidowCannabis4) );
		slotId_WhiteWidowCannabis5 = InventorySlots.GetSlotIdFromString("cannabisT56");
		m_WhiteWidowCannabis5 = ItemBase.Cast( GetInventory().FindAttachment(slotId_WhiteWidowCannabis5) );
		slotId_WhiteWidowCannabis6 = InventorySlots.GetSlotIdFromString("cannabisT57");
		m_WhiteWidowCannabis6= ItemBase.Cast( GetInventory().FindAttachment(slotId_WhiteWidowCannabis6) );
		slotId_WhiteWidowCannabis7 = InventorySlots.GetSlotIdFromString("cannabisT58");
		m_WhiteWidowCannabis7 = ItemBase.Cast( GetInventory().FindAttachment(slotId_WhiteWidowCannabis7) );
		
		if (m_WhiteWidowCannabis && m_WhiteWidowCannabis1 && m_WhiteWidowCannabis2 && m_WhiteWidowCannabis3 && m_WhiteWidowCannabis4 && m_WhiteWidowCannabis5 && m_WhiteWidowCannabis6 && m_WhiteWidowCannabis7)
		{
			return true;
		}
		return false;
	}
	bool CanProcessPoundsT5()
	{
		slotId_WhiteWidowCannabisOunce = InventorySlots.GetSlotIdFromString("WhiteWidowCannabisOunce");
		m_WhiteWidowCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_WhiteWidowCannabisOunce) );
		if(!m_WhiteWidowCannabisOunce)
		{
			return false;
		}
		if(m_WhiteWidowCannabisOunce.GetQuantity() == 16)
		{
			return true;
		}
		return false;
	}
	bool CanProcessWeedT6()
	{
		slotId_TrainwreckCannabis = InventorySlots.GetSlotIdFromString("cannabisT61");
		m_TrainwreckCannabis = ItemBase.Cast( GetInventory().FindAttachment(slotId_TrainwreckCannabis) );
		slotId_TrainwreckCannabis1 = InventorySlots.GetSlotIdFromString("cannabisT62");
		m_TrainwreckCannabis1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_TrainwreckCannabis1) );
		slotId_TrainwreckCannabis2 = InventorySlots.GetSlotIdFromString("cannabisT63");
		m_TrainwreckCannabis2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_TrainwreckCannabis2) );
		slotId_TrainwreckCannabis3 = InventorySlots.GetSlotIdFromString("cannabisT64");
		m_TrainwreckCannabis3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_TrainwreckCannabis3) );
		slotId_TrainwreckCannabis4 = InventorySlots.GetSlotIdFromString("cannabisT65");
		m_TrainwreckCannabis4 = ItemBase.Cast( GetInventory().FindAttachment(slotId_TrainwreckCannabis4) );
		slotId_TrainwreckCannabis5 = InventorySlots.GetSlotIdFromString("cannabisT66");
		m_TrainwreckCannabis5 = ItemBase.Cast( GetInventory().FindAttachment(slotId_TrainwreckCannabis5) );
		slotId_TrainwreckCannabis6 = InventorySlots.GetSlotIdFromString("cannabisT67");
		m_TrainwreckCannabis6= ItemBase.Cast( GetInventory().FindAttachment(slotId_TrainwreckCannabis6) );
		slotId_TrainwreckCannabis7 = InventorySlots.GetSlotIdFromString("cannabisT68");
		m_TrainwreckCannabis7 = ItemBase.Cast( GetInventory().FindAttachment(slotId_TrainwreckCannabis7) );
		
		if (m_TrainwreckCannabis && m_TrainwreckCannabis1 && m_TrainwreckCannabis2 && m_TrainwreckCannabis3 && m_TrainwreckCannabis4 && m_TrainwreckCannabis5 && m_TrainwreckCannabis6 && m_TrainwreckCannabis7)
		{
			return true;
		}
		return false;
	}
	bool CanProcessPoundsT6()
	{
		slotId_TrainwreckCannabisOunce = InventorySlots.GetSlotIdFromString("TrainwreckCannabisOunce");
		m_TrainwreckCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_TrainwreckCannabisOunce) );
		if(!m_TrainwreckCannabisOunce)
		{
			return false;
		}
		if(m_TrainwreckCannabisOunce.GetQuantity() == 16)
		{
			return true;
		}
		return false;
	}
	bool CanProcessWeedT7()
	{
		slotId_PineappleExpressCannabis = InventorySlots.GetSlotIdFromString("cannabisT71");
		m_PineappleExpressCannabis = ItemBase.Cast( GetInventory().FindAttachment(slotId_PineappleExpressCannabis) );
		slotId_PineappleExpressCannabis1 = InventorySlots.GetSlotIdFromString("cannabisT72");
		m_PineappleExpressCannabis1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_PineappleExpressCannabis1) );
		slotId_PineappleExpressCannabis2 = InventorySlots.GetSlotIdFromString("cannabisT73");
		m_PineappleExpressCannabis2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_PineappleExpressCannabis2) );
		slotId_PineappleExpressCannabis3 = InventorySlots.GetSlotIdFromString("cannabisT74");
		m_PineappleExpressCannabis3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_PineappleExpressCannabis3) );
		slotId_PineappleExpressCannabis4 = InventorySlots.GetSlotIdFromString("cannabisT75");
		m_PineappleExpressCannabis4 = ItemBase.Cast( GetInventory().FindAttachment(slotId_PineappleExpressCannabis4) );
		slotId_PineappleExpressCannabis5 = InventorySlots.GetSlotIdFromString("cannabisT76");
		m_PineappleExpressCannabis5 = ItemBase.Cast( GetInventory().FindAttachment(slotId_PineappleExpressCannabis5) );
		slotId_PineappleExpressCannabis6 = InventorySlots.GetSlotIdFromString("cannabisT77");
		m_PineappleExpressCannabis6= ItemBase.Cast( GetInventory().FindAttachment(slotId_PineappleExpressCannabis6) );
		slotId_PineappleExpressCannabis7 = InventorySlots.GetSlotIdFromString("cannabisT78");
		m_PineappleExpressCannabis7 = ItemBase.Cast( GetInventory().FindAttachment(slotId_PineappleExpressCannabis7) );
		
		if (m_PineappleExpressCannabis && m_PineappleExpressCannabis1 && m_PineappleExpressCannabis2 && m_PineappleExpressCannabis3 && m_PineappleExpressCannabis4 && m_PineappleExpressCannabis5 && m_PineappleExpressCannabis6 && m_PineappleExpressCannabis7)
		{
			return true;
		}
		return false;
	}
	bool CanProcessPoundsT7()
	{
		slotId_PineappleExpressCannabisOunce = InventorySlots.GetSlotIdFromString("PineappleExpressCannabisOunce");
		m_PineappleExpressCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_PineappleExpressCannabisOunce) );
		if(!m_PineappleExpressCannabisOunce)
		{
			return false;
		}
		if(m_PineappleExpressCannabisOunce.GetQuantity() == 16)
		{
			return true;
		}
		return false;
	}
	bool CanProcessWeedT8()
	{
		slotId_GorillaGlueCannabis = InventorySlots.GetSlotIdFromString("cannabisT81");
		m_GorillaGlueCannabis = ItemBase.Cast( GetInventory().FindAttachment(slotId_GorillaGlueCannabis) );
		slotId_GorillaGlueCannabis1 = InventorySlots.GetSlotIdFromString("cannabisT82");
		m_GorillaGlueCannabis1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_GorillaGlueCannabis1) );
		slotId_GorillaGlueCannabis2 = InventorySlots.GetSlotIdFromString("cannabisT83");
		m_GorillaGlueCannabis2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_GorillaGlueCannabis2) );
		slotId_GorillaGlueCannabis3 = InventorySlots.GetSlotIdFromString("cannabisT84");
		m_GorillaGlueCannabis3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_GorillaGlueCannabis3) );
		slotId_GorillaGlueCannabis4 = InventorySlots.GetSlotIdFromString("cannabisT85");
		m_GorillaGlueCannabis4 = ItemBase.Cast( GetInventory().FindAttachment(slotId_GorillaGlueCannabis4) );
		slotId_GorillaGlueCannabis5 = InventorySlots.GetSlotIdFromString("cannabisT86");
		m_GorillaGlueCannabis5 = ItemBase.Cast( GetInventory().FindAttachment(slotId_GorillaGlueCannabis5) );
		slotId_GorillaGlueCannabis6 = InventorySlots.GetSlotIdFromString("cannabisT87");
		m_GorillaGlueCannabis6= ItemBase.Cast( GetInventory().FindAttachment(slotId_GorillaGlueCannabis6) );
		slotId_GorillaGlueCannabis7 = InventorySlots.GetSlotIdFromString("cannabisT88");
		m_GorillaGlueCannabis7 = ItemBase.Cast( GetInventory().FindAttachment(slotId_GorillaGlueCannabis7) );
		
		if (m_GorillaGlueCannabis && m_GorillaGlueCannabis1 && m_GorillaGlueCannabis2 && m_GorillaGlueCannabis3 && m_GorillaGlueCannabis4 && m_GorillaGlueCannabis5 && m_GorillaGlueCannabis6 && m_GorillaGlueCannabis7)
		{
			return true;
		}
		return false;
	}
	bool CanProcessPoundsT8()
	{
		slotId_GorillaGlueCannabisOunce = InventorySlots.GetSlotIdFromString("GorillaGlueCannabisOunce");
		m_GorillaGlueCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_GorillaGlueCannabisOunce) );
		if(!m_GorillaGlueCannabisOunce)
		{
			return false;
		}
		if(m_GorillaGlueCannabisOunce.GetQuantity() == 16)
		{
			return true;
		}
		return false;
	}
	bool CanProcessWeedT9()
	{
		slotId_SourDieselCannabis = InventorySlots.GetSlotIdFromString("cannabisT91");
		m_SourDieselCannabis = ItemBase.Cast( GetInventory().FindAttachment(slotId_SourDieselCannabis) );
		slotId_SourDieselCannabis1 = InventorySlots.GetSlotIdFromString("cannabisT92");
		m_SourDieselCannabis1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_SourDieselCannabis1) );
		slotId_SourDieselCannabis2 = InventorySlots.GetSlotIdFromString("cannabisT93");
		m_SourDieselCannabis2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_SourDieselCannabis2) );
		slotId_SourDieselCannabis3 = InventorySlots.GetSlotIdFromString("cannabisT94");
		m_SourDieselCannabis3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_SourDieselCannabis3) );
		slotId_SourDieselCannabis4 = InventorySlots.GetSlotIdFromString("cannabisT95");
		m_SourDieselCannabis4 = ItemBase.Cast( GetInventory().FindAttachment(slotId_SourDieselCannabis4) );
		slotId_SourDieselCannabis5 = InventorySlots.GetSlotIdFromString("cannabisT96");
		m_SourDieselCannabis5 = ItemBase.Cast( GetInventory().FindAttachment(slotId_SourDieselCannabis5) );
		slotId_SourDieselCannabis6 = InventorySlots.GetSlotIdFromString("cannabisT97");
		m_SourDieselCannabis6= ItemBase.Cast( GetInventory().FindAttachment(slotId_SourDieselCannabis6) );
		slotId_SourDieselCannabis7 = InventorySlots.GetSlotIdFromString("cannabisT98");
		m_SourDieselCannabis7 = ItemBase.Cast( GetInventory().FindAttachment(slotId_SourDieselCannabis7) );
		
		
		if(m_SourDieselCannabis && m_SourDieselCannabis1 && m_SourDieselCannabis2 && m_SourDieselCannabis3 && m_SourDieselCannabis4 && m_SourDieselCannabis5 && m_SourDieselCannabis6 && m_SourDieselCannabis7)
		{
			return true;
		}
		return false;
	}
	bool CanProcessPoundsT9()
	{
		slotId_SourDieselCannabisOunce = InventorySlots.GetSlotIdFromString("SourDieselCannabisOunce");
		m_SourDieselCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_SourDieselCannabisOunce) );
		if(!m_SourDieselCannabisOunce)
		{
			return false;
		}
		if(m_SourDieselCannabisOunce.GetQuantity() == 16)
		{
			return true;
		}
		return false;
	}
	void ProcessWeed()
	{
		if (GetGame().IsServer() && CanProcessWeed())  
		{
			slotId_BasicCannabisOunce = InventorySlots.GetSlotIdFromString("BasicCannabisOunce");
			m_BasicCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_BasicCannabisOunce) );
			//create in inventory of the bin so it doesn't get lost if they forget about it
			//checking that we did create them so in case it gets full we turn it off and not use up materials
			if(!m_BasicCannabisOunce || m_BasicCannabisOunce.GetQuantity() >= 15)
			{
				ItemBase bag = ItemBase.Cast(this.GetInventory().CreateInInventory("BasicCannabisOuncebag"));
				ItemBase bag0 = ItemBase.Cast(this.GetInventory().CreateInInventory("BasicCannabisOuncebag"));
			}
			else
			{
				m_BasicCannabisOunce.AddQuantity(1);
				m_BasicCannabisOunce.AddQuantity(1);
			}
			//ItemBase fert2 = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageCompost_Fertilizer"));			
			//if(!fert1 || !fert2)
			if(!bag || !bag0)
				SwitchOffServer();
			m_BasicCannabis.Delete();
			m_BasicCannabis1.Delete();
			m_BasicCannabis2.Delete();
			m_BasicCannabis3.Delete();
			m_BasicCannabis4.Delete();
			m_BasicCannabis5.Delete();
			m_BasicCannabis6.Delete();
			m_BasicCannabis7.Delete();
		}
		if (GetGame().IsServer() && CanProcessPounds())
		{
			ItemBase pound = ItemBase.Cast(this.GetInventory().CreateInInventory("BasicCannabisPoundbag"));
			if(!pound)
				SwitchOffServer();
			m_BasicCannabisOunce.Delete();
			SwitchOffServer();
		}
		if (GetGame().IsServer() && CanProcessWeedT2())  
		{
			slotId_AlaskanThunderFuckCannabisOunce = InventorySlots.GetSlotIdFromString("AlaskanThunderFuckCannabisOunce");
			m_AlaskanThunderFuckCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_AlaskanThunderFuckCannabisOunce) );
			//create in inventory of the bin so it doesn't get lost if they forget about it
			//checking that we did create them so in case it gets full we turn it off and not use up materials
			if(!m_AlaskanThunderFuckCannabisOunce || m_AlaskanThunderFuckCannabisOunce.GetQuantity() >= 15)
			{
				ItemBase bag1 = ItemBase.Cast(this.GetInventory().CreateInInventory("AlaskanThunderFuckOuncebag"));
				ItemBase bag11 = ItemBase.Cast(this.GetInventory().CreateInInventory("AlaskanThunderFuckOuncebag"));
			}
			else
			{
				m_AlaskanThunderFuckCannabisOunce.AddQuantity(1);
				m_AlaskanThunderFuckCannabisOunce.AddQuantity(1);
			}
			//ItemBase fert2 = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageCompost_Fertilizer"));			
			//if(!fert1 || !fert2)
			if(!bag1 || !bag11)
				SwitchOffServer();
			m_AlaskanThunderFuckCannabis.Delete();
			m_AlaskanThunderFuckCannabis1.Delete();
			m_AlaskanThunderFuckCannabis2.Delete();
			m_AlaskanThunderFuckCannabis3.Delete();
			m_AlaskanThunderFuckCannabis4.Delete();
			m_AlaskanThunderFuckCannabis5.Delete();
			m_AlaskanThunderFuckCannabis6.Delete();
			m_AlaskanThunderFuckCannabis7.Delete();
		}
		if (GetGame().IsServer() && CanProcessPoundsT2())
		{
				ItemBase pound1 = ItemBase.Cast(this.GetInventory().CreateInInventory("AlaskanThunderFuckPoundbag"));
				if(!pound1)
					SwitchOffServer();
				m_AlaskanThunderFuckCannabisOunce.Delete();
				SwitchOffServer();
		}
		if (GetGame().IsServer() && CanProcessWeedT3())  
		{
			slotId_FireCrotchCannabisOunce = InventorySlots.GetSlotIdFromString("FireCrotchCannabisOunce");
			m_FireCrotchCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_FireCrotchCannabisOunce) );
			//create in inventory of the bin so it doesn't get lost if they forget about it
			//checking that we did create them so in case it gets full we turn it off and not use up materials
			if(!m_FireCrotchCannabisOunce || m_FireCrotchCannabisOunce.GetQuantity() >= 15)
			{
				ItemBase bag2 = ItemBase.Cast(this.GetInventory().CreateInInventory("FireCrotchOuncebag"));
				ItemBase bag22 = ItemBase.Cast(this.GetInventory().CreateInInventory("FireCrotchOuncebag"));
			}
			else
			{
				m_FireCrotchCannabisOunce.AddQuantity(1);
				m_FireCrotchCannabisOunce.AddQuantity(1);
			}
			//ItemBase fert2 = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageCompost_Fertilizer"));			
			//if(!fert1 || !fert2)
			if(!bag2 || !bag22)
				SwitchOffServer();
			m_FireCrotchCannabis.Delete();
			m_FireCrotchCannabis1.Delete();
			m_FireCrotchCannabis2.Delete();
			m_FireCrotchCannabis3.Delete();
			m_FireCrotchCannabis4.Delete();
			m_FireCrotchCannabis5.Delete();
			m_FireCrotchCannabis6.Delete();
			m_FireCrotchCannabis7.Delete();
		}
		if (GetGame().IsServer() && CanProcessPoundsT3())
		{
				ItemBase pound2 = ItemBase.Cast(this.GetInventory().CreateInInventory("FireCrotchPoundbag"));
				if(!pound2)
					SwitchOffServer();
				m_FireCrotchCannabisOunce.Delete();
				SwitchOffServer();
		}
		if (GetGame().IsServer() && CanProcessWeedT4())  
		{
			slotId_BlueDreamCannabisOunce = InventorySlots.GetSlotIdFromString("BlueDreamCannabisOunce");
			m_BlueDreamCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_BlueDreamCannabisOunce) );
			//create in inventory of the bin so it doesn't get lost if they forget about it
			//checking that we did create them so in case it gets full we turn it off and not use up materials
			if(!m_BlueDreamCannabisOunce || m_BlueDreamCannabisOunce.GetQuantity() >= 15)
			{
				ItemBase bag3 = ItemBase.Cast(this.GetInventory().CreateInInventory("BlueDreamOuncebag"));
				ItemBase bag33 = ItemBase.Cast(this.GetInventory().CreateInInventory("BlueDreamOuncebag"));
			}
			else
			{
				m_BlueDreamCannabisOunce.AddQuantity(1);
				m_BlueDreamCannabisOunce.AddQuantity(1);
			}
			//ItemBase fert2 = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageCompost_Fertilizer"));			
			//if(!fert1 || !fert2)
			if(!bag3 || !bag33)
				SwitchOffServer();
			m_BlueDreamCannabis.Delete();
			m_BlueDreamCannabis1.Delete();
			m_BlueDreamCannabis2.Delete();
			m_BlueDreamCannabis3.Delete();
			m_BlueDreamCannabis4.Delete();
			m_BlueDreamCannabis5.Delete();
			m_BlueDreamCannabis6.Delete();
			m_BlueDreamCannabis7.Delete();
		}
		if (GetGame().IsServer() && CanProcessPoundsT4())
		{
				ItemBase pound3 = ItemBase.Cast(this.GetInventory().CreateInInventory("BlueDreamPoundbag"));
				if(!pound3)
					SwitchOffServer();
				m_BlueDreamCannabisOunce.Delete();
				SwitchOffServer();
		}
		if (GetGame().IsServer() && CanProcessWeedT5())  
		{
			slotId_WhiteWidowCannabisOunce = InventorySlots.GetSlotIdFromString("WhiteWidowCannabisOunce");
			m_WhiteWidowCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_WhiteWidowCannabisOunce) );
			//create in inventory of the bin so it doesn't get lost if they forget about it
			//checking that we did create them so in case it gets full we turn it off and not use up materials
			if(!m_WhiteWidowCannabisOunce || m_WhiteWidowCannabisOunce.GetQuantity() >= 15)
			{
				ItemBase bag4 = ItemBase.Cast(this.GetInventory().CreateInInventory("WhiteWidowOuncebag"));
				ItemBase bag44 = ItemBase.Cast(this.GetInventory().CreateInInventory("WhiteWidowOuncebag"));
			}
			else
			{
				m_WhiteWidowCannabisOunce.AddQuantity(1);
				m_WhiteWidowCannabisOunce.AddQuantity(1);
			}
			//ItemBase fert2 = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageCompost_Fertilizer"));			
			//if(!fert1 || !fert2)
			if(!bag4 || !bag44)
				SwitchOffServer();
			m_WhiteWidowCannabis.Delete();
			m_WhiteWidowCannabis1.Delete();
			m_WhiteWidowCannabis2.Delete();
			m_WhiteWidowCannabis3.Delete();
			m_WhiteWidowCannabis4.Delete();
			m_WhiteWidowCannabis5.Delete();
			m_WhiteWidowCannabis6.Delete();
			m_WhiteWidowCannabis7.Delete();
		}
		if (GetGame().IsServer() && CanProcessPoundsT5())
		{
				ItemBase pound4 = ItemBase.Cast(this.GetInventory().CreateInInventory("WhiteWidowPoundbag"));
				if(!pound4)
					SwitchOffServer();
				m_WhiteWidowCannabisOunce.Delete();
				SwitchOffServer();
		}
		if (GetGame().IsServer() && CanProcessWeedT6())  
		{
			slotId_TrainwreckCannabisOunce = InventorySlots.GetSlotIdFromString("TrainwreckCannabisOunce");
			m_TrainwreckCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_TrainwreckCannabisOunce) );
			//create in inventory of the bin so it doesn't get lost if they forget about it
			//checking that we did create them so in case it gets full we turn it off and not use up materials
			if(!m_TrainwreckCannabisOunce || m_TrainwreckCannabisOunce.GetQuantity() >= 15)
			{
				ItemBase bag5 = ItemBase.Cast(this.GetInventory().CreateInInventory("TrainwreckOuncebag"));
				ItemBase bag55 = ItemBase.Cast(this.GetInventory().CreateInInventory("TrainwreckOuncebag"));
			}
			else
			{
				m_TrainwreckCannabisOunce.AddQuantity(1);
				m_TrainwreckCannabisOunce.AddQuantity(1);
			}
			//ItemBase fert2 = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageCompost_Fertilizer"));			
			//if(!fert1 || !fert2)
			if(!bag5 || !bag55)
				SwitchOffServer();
			m_TrainwreckCannabis.Delete();
			m_TrainwreckCannabis1.Delete();
			m_TrainwreckCannabis2.Delete();
			m_TrainwreckCannabis3.Delete();
			m_TrainwreckCannabis4.Delete();
			m_TrainwreckCannabis5.Delete();
			m_TrainwreckCannabis6.Delete();
			m_TrainwreckCannabis7.Delete();
		}
		if (GetGame().IsServer() && CanProcessPoundsT6())
		{
				ItemBase pound5 = ItemBase.Cast(this.GetInventory().CreateInInventory("TrainwreckPoundbag"));
				if(!pound5)
					SwitchOffServer();
				m_TrainwreckCannabisOunce.Delete();
				SwitchOffServer();
		}
		if (GetGame().IsServer() && CanProcessWeedT7())  
		{
			slotId_PineappleExpressCannabisOunce = InventorySlots.GetSlotIdFromString("PineappleExpressCannabisOunce");
			m_PineappleExpressCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_PineappleExpressCannabisOunce) );
			//create in inventory of the bin so it doesn't get lost if they forget about it
			//checking that we did create them so in case it gets full we turn it off and not use up materials
			if(!m_PineappleExpressCannabisOunce || m_PineappleExpressCannabisOunce.GetQuantity() >= 15)
			{
				ItemBase bag6 = ItemBase.Cast(this.GetInventory().CreateInInventory("PineappleExpressOuncebag"));
				ItemBase bag66 = ItemBase.Cast(this.GetInventory().CreateInInventory("PineappleExpressOuncebag"));
			}
			else
			{
				m_PineappleExpressCannabisOunce.AddQuantity(1);
				m_PineappleExpressCannabisOunce.AddQuantity(1);
			}
			//ItemBase fert2 = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageCompost_Fertilizer"));			
			//if(!fert1 || !fert2)
			if(!bag6 || !bag66)
				SwitchOffServer();
			m_PineappleExpressCannabis.Delete();
			m_PineappleExpressCannabis1.Delete();
			m_PineappleExpressCannabis2.Delete();
			m_PineappleExpressCannabis3.Delete();
			m_PineappleExpressCannabis4.Delete();
			m_PineappleExpressCannabis5.Delete();
			m_PineappleExpressCannabis6.Delete();
			m_PineappleExpressCannabis7.Delete();
		}
		if (GetGame().IsServer() && CanProcessPoundsT7())
		{
				ItemBase pound6 = ItemBase.Cast(this.GetInventory().CreateInInventory("PineappleExpressPoundbag"));
				if(!pound6)
					SwitchOffServer();
				m_PineappleExpressCannabisOunce.Delete();
				SwitchOffServer();
		}
		if (GetGame().IsServer() && CanProcessWeedT8())  
		{
			slotId_GorillaGlueCannabisOunce = InventorySlots.GetSlotIdFromString("GorillaGlueCannabisOunce");
			m_GorillaGlueCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_GorillaGlueCannabisOunce) );
			//create in inventory of the bin so it doesn't get lost if they forget about it
			//checking that we did create them so in case it gets full we turn it off and not use up materials
			if(!m_GorillaGlueCannabisOunce || m_GorillaGlueCannabisOunce.GetQuantity() >= 15)
			{
				ItemBase bag7 = ItemBase.Cast(this.GetInventory().CreateInInventory("GorillaGlueOuncebag"));
				ItemBase bag77 = ItemBase.Cast(this.GetInventory().CreateInInventory("GorillaGlueOuncebag"));
			}
			else
			{
				m_GorillaGlueCannabisOunce.AddQuantity(1);
				m_GorillaGlueCannabisOunce.AddQuantity(1);
			}
			//ItemBase fert2 = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageCompost_Fertilizer"));			
			//if(!fert1 || !fert2)
			if(!bag7 || !bag77)
				SwitchOffServer();
			m_GorillaGlueCannabis.Delete();
			m_GorillaGlueCannabis1.Delete();
			m_GorillaGlueCannabis2.Delete();
			m_GorillaGlueCannabis3.Delete();
			m_GorillaGlueCannabis4.Delete();
			m_GorillaGlueCannabis5.Delete();
			m_GorillaGlueCannabis6.Delete();
			m_GorillaGlueCannabis7.Delete();
		}
		if (GetGame().IsServer() && CanProcessPoundsT8())
		{
			ItemBase pound7 = ItemBase.Cast(this.GetInventory().CreateInInventory("GorillaGluePoundbag"));
				if(!pound7)
					SwitchOffServer();
				m_GorillaGlueCannabisOunce.Delete();
				SwitchOffServer();
		}
		if (GetGame().IsServer() && CanProcessWeedT9())  
		{
			slotId_SourDieselCannabisOunce = InventorySlots.GetSlotIdFromString("SourDieselCannabisOunce");
			m_SourDieselCannabisOunce = ItemBase.Cast( GetInventory().FindAttachment(slotId_SourDieselCannabisOunce) );
			//create in inventory of the bin so it doesn't get lost if they forget about it
			//checking that we did create them so in case it gets full we turn it off and not use up materials
			
			if(!m_SourDieselCannabisOunce || m_SourDieselCannabisOunce.GetQuantity() >= 15)
			{
				ItemBase bag8 = ItemBase.Cast(this.GetInventory().CreateInInventory("SourDieselOuncebag"));
				ItemBase bag88 = ItemBase.Cast(this.GetInventory().CreateInInventory("SourDieselOuncebag"));
			}
			else
			{
				m_SourDieselCannabisOunce.AddQuantity(1);
				m_SourDieselCannabisOunce.AddQuantity(1);
			}
			//ItemBase fert2 = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageCompost_Fertilizer"));			
			//if(!fert1 || !fert2)
			if(!bag8 || !bag88)
				SwitchOffServer();
			m_SourDieselCannabis.Delete();
			m_SourDieselCannabis1.Delete();
			m_SourDieselCannabis2.Delete();
			m_SourDieselCannabis3.Delete();
			m_SourDieselCannabis4.Delete();
			m_SourDieselCannabis5.Delete();
			m_SourDieselCannabis6.Delete();
			m_SourDieselCannabis7.Delete();
		}
		if (GetGame().IsServer() && CanProcessPoundsT9())
		{
			ItemBase pound8 = ItemBase.Cast(this.GetInventory().CreateInInventory("SourDieselPoundbag"));
			if(!pound8)
				SwitchOffServer();
			m_SourDieselCannabisOunce.Delete();
			SwitchOffServer();
		}
		//if we can't craft ANYTHING anymore turn it off
		if(!CanProcessWeed() && !CanProcessWeedT2() && !CanProcessWeedT3() && !CanProcessWeedT4() && !CanProcessWeedT5() && !CanProcessWeedT6() && !CanProcessWeedT7() && !CanProcessWeedT8() && !CanProcessWeedT9())
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
		AddAction(ActionTurnOnOffWeedProcessor);
    }
};
