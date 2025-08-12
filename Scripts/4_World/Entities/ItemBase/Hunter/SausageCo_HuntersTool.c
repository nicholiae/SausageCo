class SausageCo_HuntersTool extends ItemBase
{
	ref protected EffectSound 						m_DeployLoopSound;
	Object											HuntersBateItem;
	Object											HuntersBateXP;
	
	string slotProtien = "protien";
	string slotVeges = "veges";
	string slotSeasoning = "seasoning";
	string slotPoison = "poison";

	int slot_id;
	int slot_id2;
	int slot_id3;
	int slot_id4;

	ItemBase slotCast;
	ItemBase slotCast2;
	ItemBase slotCast3;
	ItemBase slotCast4;

	int protienCost;
	int vegesCost;
	int seasoningCost;
	int poisonCost;

	int j_Count;
	int j_Count2;
	int j_Count3;
	int j_Count4;
	
	void SausageCo_HuntersTool()
	{	
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}
	
	bool hasProperPrep()
	{
		protienCost = 25;  // Fixed integer values
		vegesCost = 25;
		seasoningCost = 25;
		poisonCost = 25;
		
		slot_id = InventorySlots.GetSlotIdFromString(slotProtien);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotVeges);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotSeasoning);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotPoison);
		
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL)
		{
			j_Count = slotCast.GetQuantity();
			j_Count2 = slotCast2.GetQuantity();
			j_Count3 = slotCast3.GetQuantity();
			j_Count4 = slotCast4.GetQuantity();
			
			if(j_Count < protienCost) protienCost = j_Count;
			if(j_Count2 < vegesCost) vegesCost = j_Count2;
			if(j_Count3 < seasoningCost) seasoningCost = j_Count3;
			if(j_Count4 < poisonCost) poisonCost = j_Count4;
			
			if( j_Count >= protienCost && j_Count2 >= vegesCost && j_Count3 >= seasoningCost && j_Count4 >= poisonCost )
			{
				return true;
			}
		}
		return false;
	}
	
	int xpGained()
	{
		return 25;
	}
	
	string j_Cook()
	{
		return "Guts";
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
	override bool CanPutInCargo( EntityAI parent )
	{		
		if ( IsEmpty() )
		{
			return true;
		}
		return true;
	}
	override bool CanPutIntoHands(EntityAI parent)
	{
		return true;
	}
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		return true;
	}
	override bool CanReleaseCargo(EntityAI attachment)
	{
		return true;
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
		if ( GetGame().IsServer() && hasProperPrep() )
		{
			HuntersBateItem = GetGame().CreateObject(this.j_Cook(), position, false );
			HuntersBateItem.SetPosition( position );
			HuntersBateItem.SetOrientation( orientation );
			
			// for (int s=0;s<xpGained();s++)		 old method of creating experience
			// {
				// HuntersBateXP = GetGame().CreateObject("SausageCo_Experience_Hunter", position, false );
				// HuntersBateXP.SetPosition( position );
				// HuntersBateXP.SetOrientation( orientation );
			// };
			HuntersBateXP = GetGame().CreateObject("SausageCo_Experience_Hunter", position, false );
			HuntersBateXP.SetPosition( position );
			HuntersBateXP.SetOrientation( orientation );
			ItemBase.Cast(HuntersBateXP).SetQuantity(xpGained());
			
			slot_id = InventorySlots.GetSlotIdFromString(slotProtien);
			slot_id2 = InventorySlots.GetSlotIdFromString(slotVeges);
			slot_id3 = InventorySlots.GetSlotIdFromString(slotSeasoning);
			slot_id4 = InventorySlots.GetSlotIdFromString(slotPoison);
			slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
			slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
			slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
			slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
			
			slotCast.AddQuantity(-25);
			slotCast2.AddQuantity(-25);
			slotCast3.AddQuantity(-25);
			slotCast4.AddQuantity(-25);
			if (slotCast.GetQuantity()==0)
			{
				slotCast.Delete();
			}
			if (slotCast2.GetQuantity()==0)
			{
				slotCast2.Delete();
			}
			if (slotCast3.GetQuantity()==0)
			{
				slotCast3.Delete();
			}
			if (slotCast4.GetQuantity()==0)
			{
				slotCast4.Delete();
			}
		}	
		
		SetIsDeploySound( true );
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
	override bool IsContainer()
	{
		return true;
	}
	override void SetActions()
	{
		super.SetActions();
	
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}
};
class SausageCo_HuntersToolT1 extends SausageCo_HuntersTool
{	
	override string j_Cook()
	{
		if (hasProperPrep())
		{
			return "HuntersBateT1";
		}
		return "SausageCo_HuntersToolT1";
	}
};
class SausageCo_HuntersToolT2 extends SausageCo_HuntersTool
{	
	override int xpGained()
	{
		return 40;
	}
	override string j_Cook()
	{
		if (hasProperPrep())
		{
			return "HuntersBateT2";
		}
		return "SausageCo_HuntersToolT2";
	}
};
class SausageCo_HuntersToolT3 extends SausageCo_HuntersTool
{	
	override int xpGained()
	{
		return 65;
	}
	override string j_Cook()
	{
		if (hasProperPrep())
		{
			return "HuntersBateT3";
		}
		return "SausageCo_HuntersToolT3";
	}
};
class SausageCo_HuntersToolT4 extends SausageCo_HuntersTool
{	
	override int xpGained()
	{
		return 100;
	}
	override string j_Cook()
	{
		if (hasProperPrep())
		{
			return "HuntersBateT4";
		}
		return "SausageCo_HuntersToolT4";
	}
		
};
