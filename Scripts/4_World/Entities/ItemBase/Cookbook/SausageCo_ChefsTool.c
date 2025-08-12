class SausageCo_ChefsTool extends ItemBase
{
	ref protected EffectSound 						m_DeployLoopSound;
	Object											ChefsMealTest;
	Object											exp;
	
	string slotProtien = "protien";
	string slotVeges = "veges";
	string slotSeasoning = "seasoning";
	string slotLiquid = "liquid";
	
	
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
	int liquidCost;

	int j_Count;
	int j_Count2;
	int j_Count3;
	int j_Count4;
	
	void SausageCo_ChefsTool()
	{	
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}
	bool hasProperPrep()
	{
		protienCost = 25/100;
		vegesCost = 25/100;
		seasoningCost = 25/100;
		liquidCost = 25/100;
		
		slot_id = InventorySlots.GetSlotIdFromString(slotProtien);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotVeges);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotSeasoning);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotLiquid);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );

		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();
		j_Count3 = slotCast3.GetQuantity();
		j_Count4 = slotCast4.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL)
		{
			if( j_Count >= protienCost && j_Count2 >= vegesCost && j_Count3 >= seasoningCost && j_Count4 >= liquidCost )
			{
				return true;
			}
			return false;
		}
		return false;
		
	}
	int xpGained()
	{
		return 0;
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
			ChefsMealTest = GetGame().CreateObject(this.j_Cook(), position, false );
			ChefsMealTest.SetPosition( position );
			ChefsMealTest.SetOrientation( orientation );
			// for (int s=0;s<xpGained();s++)
			// {
				// ChefsMealTest = GetGame().CreateObject("SausageCo_Experience_Cook", position, false );
				// ChefsMealTest.SetPosition( position );
				// ChefsMealTest.SetOrientation( orientation );
			// };
			exp = GetGame().CreateObject("SausageCo_Experience_Cook", position, false );
			exp.SetPosition( position );
			exp.SetOrientation( orientation );
			ItemBase.Cast(exp).SetQuantity(xpGained());

			slot_id = InventorySlots.GetSlotIdFromString(slotProtien);
			slot_id2 = InventorySlots.GetSlotIdFromString(slotVeges);
			slot_id3 = InventorySlots.GetSlotIdFromString(slotSeasoning);
			slot_id4 = InventorySlots.GetSlotIdFromString(slotLiquid);
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
class SausageCo_ChefsToolT1 extends SausageCo_ChefsTool
{	
	override int xpGained()
	{
		return 25;
	}
	override string j_Cook()
	{
		if ( hasProperPrep() )
		{
			return "ChefsMealT1";
		}
		return "SausageCo_ChefsToolT1";
	}
};
class SausageCo_ChefsToolT2 extends SausageCo_ChefsTool
{	
	override int xpGained()
	{
		return 50;
	}
	override string j_Cook()
	{
		if ( hasProperPrep() )
		{
			return "ChefsMealT2";
		}
		return "SausageCo_ChefsToolT2";
	}
};
class SausageCo_ChefsToolT3 extends SausageCo_ChefsTool
{	
	override int xpGained()
	{
		return 75;
	}
	override string j_Cook()
	{
		if ( hasProperPrep() )
		{
			return "ChefsMealT3";
		}
		return "SausageCo_ChefsToolT3";
	}
};
class SausageCo_ChefsToolT4 extends SausageCo_ChefsTool
{	
	override int xpGained()
	{
		return 100;
	}
	
	override string j_Cook()
	{
		if ( hasProperPrep() )
		{
			return "ChefsMealT4";
		}
		return "SausageCo_ChefsToolT4";
	}
		
};
