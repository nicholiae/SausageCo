class SausageFurnace_Kit extends ItemBase
{	
	ref protected EffectSound 						m_DeployLoopSound;
	protected Object								SausageFurnace_Kit1;	
	
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
				EntityAI kitItem = EntityAI.Cast(GetGame().CreateObjectEx("SausageFurnace", position, ECE_PLACE_ON_SURFACE));
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

class SausageFurnace_Holo extends ItemBase
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

class SausageFurnace extends ItemBase
{ 	
	//SBSConfig sbs_config = GetDayZGame().getSBSGlobals();
	private bool				m_FurnaceState = false;
	ref protected Effect 		m_Smoke;
	
	//use common variables across functions and friendly names
	private int slotId_Gold;
	private int slotId_Gold1;
	private int slotId_Gold2;
	private int slotId_Gold3;
	private int slotId_Silver;
	private int slotId_Silver1;
	private int slotId_Silver2;
	private int slotId_Silver3;
	private int slotId_Copper;
	private int slotId_Copper1;
	private int slotId_Copper2;
	private int slotId_Copper3;
	private int slotId_Base;
	private int slotId_Base1;
	private int slotId_Base2;
	private int slotId_Base3;
	private ItemBase m_Gold;
	private ItemBase m_Gold1;
	private ItemBase m_Gold2;
	private ItemBase m_Gold3;
	private ItemBase m_Silver;
	private ItemBase m_Silver1
	private ItemBase m_Silver2;
	private ItemBase m_Silver3;
	private ItemBase m_Copper;
	private ItemBase m_Copper1;
	private ItemBase m_Copper2;
	private ItemBase m_Copper3;
	private ItemBase m_Base;
	private ItemBase m_Base1;
	private ItemBase m_Base2;
	private ItemBase m_Base3;
	
	//NEW FUNCTIONS
	private int slotId_Jade;
	private int slotId_Jade1;
	private int slotId_Jade2;
	private int slotId_Jade3;
	private int slotId_Presem;
	private int slotId_Presem1;
	private int slotId_Presem2;
	private int slotId_Presem3;
	private int slotId_Blood;
	private int slotId_Blood1;
	private int slotId_Blood2;
	private int slotId_Blood3;
	private int slotId_Rune;
	private int slotId_Rune1;
	private int slotId_Rune2;
	private int slotId_Rune3;
	private ItemBase m_Jade;
	private ItemBase m_Jade1;
	private ItemBase m_Jade2;
	private ItemBase m_Jade3;
	private ItemBase m_Presem;
	private ItemBase m_Presem1
	private ItemBase m_Presem2;
	private ItemBase m_Presem3;
	private ItemBase m_Blood;
	private ItemBase m_Blood1;
	private ItemBase m_Blood2;
	private ItemBase m_Blood3;
	private ItemBase m_Rune;
	private ItemBase m_Rune1;
	private ItemBase m_Rune2;
	private ItemBase m_Rune3;

	void SausageFurnace()
	{
		//we register this to sync it on the network because on action we need to know on client if its on or not
		RegisterNetSyncVariableBool("m_FurnaceState");
	}

	void ~SausageFurnace()
	{
		SEffectManager.DestroyEffect(m_Smoke);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName( this, "ProcessAndCraftBars"); 
	}
	// Play the smoke
	void StartParticleEffect()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			if ( GetCompEM().IsWorking() )
			{
				// Particle
				vector local_pos = "0.3 0.21 0.4";
				vector local_ori = "270 0 0";
				m_Smoke = new EffGeneratorSmoke();
				SEffectManager.PlayOnObject(m_Smoke, this, local_pos, local_ori);
			}
		}
	}
	void SwitchOnServer()
	{
		m_FurnaceState = true;
		int SBSFurnaceTime = 3.0;		
		int SmeltTime = SBSFurnaceTime * 1000; // converting to milliseconds for Callback Queue
		SetSynchDirty();
		StartParticleEffect();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( ProcessAndCraftBars, SmeltTime, true );
	}

	void SwitchOffServer()
	{
		m_FurnaceState = false;
		// particle
		if (m_Smoke)
			SEffectManager.DestroyEffect(m_Smoke);
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName( this, "ProcessAndCraftBars"); 
	}

	bool IsFurnaceOn()
	{
		return m_FurnaceState;
	}

	override bool CanReleaseAttachment(EntityAI attachment)
	{
		return !m_FurnaceState;
	}

    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }
    
	override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }

	bool CanCraftRune()
	{
		slotId_Rune = InventorySlots.GetSlotIdFromString("SausageNugget_rune");
		m_Rune = ItemBase.Cast( GetInventory().FindAttachment(slotId_Rune) );
		slotId_Rune1 = InventorySlots.GetSlotIdFromString("SausageNugget_rune1");
		m_Rune1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Rune1) );
		slotId_Rune2 = InventorySlots.GetSlotIdFromString("SausageNugget_rune2");
		m_Rune2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Rune2) );
		slotId_Rune3 = InventorySlots.GetSlotIdFromString("SausageNugget_rune3");
		m_Rune3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Rune3) );
		
		if (m_Rune && m_Rune1 && m_Rune2 && m_Rune3)
		{
			return true;
		}
		return false;
	}
	bool CanCraftPresem()
	{
		slotId_Presem = InventorySlots.GetSlotIdFromString("SausageNugget_presem");
		m_Presem = ItemBase.Cast( GetInventory().FindAttachment(slotId_Presem) );
		slotId_Presem1 = InventorySlots.GetSlotIdFromString("SausageNugget_presem1");
		m_Presem1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Presem1) );
		slotId_Presem2 = InventorySlots.GetSlotIdFromString("SausageNugget_presem2");
		m_Presem2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Presem2) );
		slotId_Presem3 = InventorySlots.GetSlotIdFromString("SausageNugget_presem3");
		m_Presem3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Presem3) );
		
		if (m_Presem && m_Presem1 && m_Presem2 && m_Presem3)
		{
			return true;
		}
		return false;
	}
	bool CanCraftJade()
	{
		slotId_Jade = InventorySlots.GetSlotIdFromString("SausageNugget_jade");
		m_Jade = ItemBase.Cast( GetInventory().FindAttachment(slotId_Jade) );
		slotId_Jade1 = InventorySlots.GetSlotIdFromString("SausageNugget_jade1");
		m_Jade1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Jade1) );
		slotId_Jade2 = InventorySlots.GetSlotIdFromString("SausageNugget_jade2");
		m_Jade2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Jade2) );
		slotId_Jade3 = InventorySlots.GetSlotIdFromString("SausageNugget_jade3");
		m_Jade3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Jade3) );
		
		if (m_Jade && m_Jade1 && m_Jade2 && m_Jade3)
		{
			return true;
		}
		return false;
	}
	bool CanCraftBlood()
	{
		slotId_Blood = InventorySlots.GetSlotIdFromString("SausageNugget_blood");
		m_Blood = ItemBase.Cast( GetInventory().FindAttachment(slotId_Blood) );
		slotId_Blood1 = InventorySlots.GetSlotIdFromString("SausageNugget_blood1");
		m_Blood1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Blood1) );
		slotId_Blood2 = InventorySlots.GetSlotIdFromString("SausageNugget_blood2");
		m_Blood2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Blood2) );
		slotId_Blood3 = InventorySlots.GetSlotIdFromString("SausageNugget_blood3");
		m_Blood3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Blood3) );
		
		if (m_Blood && m_Blood1 && m_Blood2 && m_Blood3)
		{
			return true;
		}
		return false;
	}
	bool CanCraftBase()
	{
		slotId_Base = InventorySlots.GetSlotIdFromString("SausageNugget_base");
		m_Base = ItemBase.Cast( GetInventory().FindAttachment(slotId_Base) );
		slotId_Base1 = InventorySlots.GetSlotIdFromString("SausageNugget_base1");
		m_Base1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Base1) );
		slotId_Base2 = InventorySlots.GetSlotIdFromString("SausageNugget_base2");
		m_Base2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Base2) );
		slotId_Base3 = InventorySlots.GetSlotIdFromString("SausageNugget_base3");
		m_Base3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Base3) );
		
		if (m_Base && m_Base1 && m_Base2 && m_Base3)
		{
			return true;
		}
		return false;
	}
	bool CanCraftGold()
	{
		slotId_Gold = InventorySlots.GetSlotIdFromString("SausageNugget_gold");
		m_Gold = ItemBase.Cast( GetInventory().FindAttachment(slotId_Gold) );
		slotId_Gold1 = InventorySlots.GetSlotIdFromString("SausageNugget_gold1");
		m_Gold1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Gold1) );
		slotId_Gold2 = InventorySlots.GetSlotIdFromString("SausageNugget_gold2");
		m_Gold2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Gold2) );
		slotId_Gold3 = InventorySlots.GetSlotIdFromString("SausageNugget_gold3");
		m_Gold3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Gold3) );
		
		if (m_Gold && m_Gold1 && m_Gold2 && m_Gold3)
		{
			return true;
		}
		return false;
	}
	bool CanCraftSilver()
	{
		slotId_Silver = InventorySlots.GetSlotIdFromString("SausageNugget_silver");
		m_Silver = ItemBase.Cast( GetInventory().FindAttachment(slotId_Silver) );
		slotId_Silver1 = InventorySlots.GetSlotIdFromString("SausageNugget_silver1");
		m_Silver1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Silver1) );
		slotId_Silver2 = InventorySlots.GetSlotIdFromString("SausageNugget_silver2");
		m_Silver2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Silver2) );
		slotId_Silver3 = InventorySlots.GetSlotIdFromString("SausageNugget_silver3");
		m_Silver3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Silver3) );
		
		if (m_Silver && m_Silver1 && m_Silver2 && m_Silver3)
		{
			return true;
		}
		return false;
	}
	bool CanCraftCopper()
	{
		slotId_Copper = InventorySlots.GetSlotIdFromString("SausageNugget_copper");
		m_Copper = ItemBase.Cast( GetInventory().FindAttachment(slotId_Copper) );
		slotId_Copper1 = InventorySlots.GetSlotIdFromString("SausageNugget_copper1");
		m_Copper1 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Copper1) );
		slotId_Copper2 = InventorySlots.GetSlotIdFromString("SausageNugget_copper2");
		m_Copper2 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Copper2) );
		slotId_Copper3 = InventorySlots.GetSlotIdFromString("SausageNugget_copper3");
		m_Copper3 = ItemBase.Cast( GetInventory().FindAttachment(slotId_Copper3) );
		
		if (m_Copper && m_Copper1 && m_Copper2 && m_Copper3)
		{
			return true;
		}
		return false;
	}

	void ProcessAndCraftBars()
	{
		if (GetGame().IsServer() && CanCraftBlood())  
		{
			ItemBase blood = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageBar_blood"));
			if(blood) blood.SetQuantity(4);
			if(!blood) SwitchOffServer();
			m_Blood.AddQuantity(-1);
			m_Blood1.AddQuantity(-1);
			m_Blood2.AddQuantity(-1);
			m_Blood3.AddQuantity(-1);
		}
		if (GetGame().IsServer() && CanCraftPresem())  
		{
			ItemBase presem = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageBar_presem"));
			if(presem) presem.SetQuantity(4);
			if(!presem) SwitchOffServer();
			m_Presem.AddQuantity(-1);
			m_Presem1.AddQuantity(-1);
			m_Presem2.AddQuantity(-1);
			m_Presem3.AddQuantity(-1);
		}
		if (GetGame().IsServer() && CanCraftJade())  
		{
			ItemBase jade = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageBar_jade")); 
			if(jade) jade.SetQuantity(4);
			if(!jade) SwitchOffServer();
			m_Jade.AddQuantity(-1);
			m_Jade1.AddQuantity(-1);
			m_Jade2.AddQuantity(-1);
			m_Jade3.AddQuantity(-1);
		}
		if (GetGame().IsServer() && CanCraftRune())  
		{
			ItemBase rune = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageBar_rune"));
			if(rune) rune.SetQuantity(4);
			if(!rune) SwitchOffServer();
			m_Rune.AddQuantity(-1);
			m_Rune1.AddQuantity(-1);
			m_Rune2.AddQuantity(-1);
			m_Rune3.AddQuantity(-1);
		}
		if (GetGame().IsServer() && CanCraftBase())  
		{
			ItemBase base = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageBar_base"));
			if(base) base.SetQuantity(4);
			if(!base) SwitchOffServer();
			m_Base.AddQuantity(-1);
			m_Base1.AddQuantity(-1);
			m_Base2.AddQuantity(-1);
			m_Base3.AddQuantity(-1);
		}
		if (GetGame().IsServer() && CanCraftGold())  
		{
			ItemBase gold = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageBar_gold"));
			if(gold) gold.SetQuantity(4);
			if(!gold) SwitchOffServer();
			m_Gold.AddQuantity(-1);
			m_Gold1.AddQuantity(-1);
			m_Gold2.AddQuantity(-1);
			m_Gold3.AddQuantity(-1);
		}
		if (GetGame().IsServer() && CanCraftSilver())  
		{
			ItemBase silver = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageBar_silver"));
			if(silver) silver.SetQuantity(4);
			if(!silver) SwitchOffServer();
			m_Silver.AddQuantity(-1);
			m_Silver1.AddQuantity(-1);
			m_Silver2.AddQuantity(-1);
			m_Silver3.AddQuantity(-1);
		}
		if (GetGame().IsServer() && CanCraftCopper())  
		{
			ItemBase copper = ItemBase.Cast(this.GetInventory().CreateInInventory("SausageBar_copper"));
			if(copper) copper.SetQuantity(4);
			if(!copper) SwitchOffServer();
			m_Copper.AddQuantity(-1);
			m_Copper1.AddQuantity(-1);
			m_Copper2.AddQuantity(-1);
			m_Copper3.AddQuantity(-1);
		}
		//if we can't craft anymore turn it off
		if(!CanCraftBase() && !CanCraftCopper() && !CanCraftSilver() && !CanCraftGold() && !CanCraftBlood() && !CanCraftJade() && !CanCraftPresem() && !CanCraftRune() )
			SwitchOffServer();
	}
	
    override void SetActions()
    {
		super.SetActions();
		AddAction(ActionTurnOnOffFurnace);
    }
};

class SausageFurnace_Static extends SausageFurnace
{
	
}