class SausageCo_Vehicle_Kit_Base extends ItemBase
{
	ref protected EffectSound 						m_DeployLoopSound;
	Object											SausageCo_Vehicle_Kit;
	
	// string slotTire;
	// string slotTire1;
	// string slotTire2;
	// string slotTire3;
	// string slotTire4;
	// string slotTire5;
	// string slotTire6;
	// string slotTire7;
	// string slotDoor;
	// string slotDoor1;
	// string slotDoor2;
	// string slotDoor3;
	// string slotDoor4;
	// string slotDoor5;
	// string slotEngine;
	// string slotEngine1;
	// string slotEngine2;
	// string slotEngine3;
	// string slotEngine4;

	// int slot_id;
	// int slot_id1;
	// int slot_id2;
	// int slot_id3;
	// int slot_id4;
	// int slot_id5;
	// int slot_id6;
	// int slot_id7;
	// int slot_id8;
	// int slot_id9;
	// int slot_id10;
	// int slot_id11;
	// int slot_id12;
	// int slot_id13;
	// int slot_id14;
	// int slot_id15;
	// int slot_id16;
	// int slot_id17;
	// int slot_id18;

	// ItemBase slotCast;
	// ItemBase slotCast2;
	// ItemBase slotCast3;
	// ItemBase slotCast4;
	// ItemBase slotCast5;
	// ItemBase slotCast6;
	// ItemBase slotCast7;
	// ItemBase slotCast8;
	// ItemBase slotCast9;
	// ItemBase slotCast10;
	// ItemBase slotCast11;
	// ItemBase slotCast12;
	// ItemBase slotCast13;
	// ItemBase slotCast14;
	// ItemBase slotCast15;
	// ItemBase slotCast16;
	// ItemBase slotCast17;
	// ItemBase slotCast18;
	
	void SausageCo_Vehicle_Kit_Base()
	{	
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}
	bool hasProperPrep()
	{
		return false;
	}
	string j_Vehicle()
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
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player );
		
		if ( GetGame().IsServer() && hasProperPrep() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );
			vector newPosition = player_base.GetLocalProjectionPosition();
			vector newOrientation = player_base.GetLocalProjectionOrientation();
				
			SausageCo_Vehicle_Kit = GetGame().CreateObject("", newPosition, false );
			SausageCo_Vehicle_Kit.SetPosition( newPosition );
			SausageCo_Vehicle_Kit.SetOrientation( newOrientation );
			
		}	
		
		SetIsDeploySound( true );
		this.Delete();
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
class SausageCo_Vehicle_SarkaBase_Kit extends SausageCo_Vehicle_Kit_Base
{	
	Car craftedCar;	
	
	string slotTire = "Sedan_02_Wheel_1_1";
	string slotTire1 = "Sedan_02_Wheel_1_2";
	string slotTire2 = "Sedan_02_Wheel_2_1";
	string slotTire3 = "Sedan_02_Wheel_2_2";
	
	string slotDoor = "Sedan_02_Hood";
	string slotDoor1 = "Sedan_02_Trunk";
	string slotDoor2 = "Sedan_02_Door_1_1";
	string slotDoor3 = "Sedan_02_Door_2_1";
	string slotDoor4 = "Sedan_02_Door_1_2";
	string slotDoor5 = "Sedan_02_Door_2_2";
	
	string slotEngine = "CarBattery";
	string slotEngine1 = "Reflector_1_1";
	string slotEngine2 = "Reflector_2_1";
	string slotEngine3 = "CarRadiator";
	string slotEngine4 = "SparkPlug";

	int slot_id;
	int slot_id1;
	int slot_id2;
	int slot_id3;
	int slot_id4;
	int slot_id5;
	int slot_id6;
	int slot_id7;
	int slot_id8;
	int slot_id9;
	int slot_id10;
	int slot_id11;
	int slot_id12;
	int slot_id13;
	int slot_id14;

	ItemBase slotCast;
	ItemBase slotCast2;
	ItemBase slotCast3;
	ItemBase slotCast4;
	ItemBase slotCast5;
	ItemBase slotCast6;
	ItemBase slotCast7;
	ItemBase slotCast8;
	ItemBase slotCast9;
	ItemBase slotCast10;
	ItemBase slotCast11;
	ItemBase slotCast12;
	ItemBase slotCast13;
	ItemBase slotCast14;
	ItemBase slotCast15;
	
	override bool hasProperPrep()
	{
		slot_id = InventorySlots.GetSlotIdFromString(slotTire);
		slot_id1 = InventorySlots.GetSlotIdFromString(slotTire1);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotTire2);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotTire3);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotDoor);
		slot_id5 = InventorySlots.GetSlotIdFromString(slotDoor1);
		slot_id6 = InventorySlots.GetSlotIdFromString(slotDoor2);
		slot_id7 = InventorySlots.GetSlotIdFromString(slotDoor3);
		slot_id8 = InventorySlots.GetSlotIdFromString(slotDoor4);
		slot_id9 = InventorySlots.GetSlotIdFromString(slotDoor5);
		slot_id10 = InventorySlots.GetSlotIdFromString(slotEngine);
		slot_id11 = InventorySlots.GetSlotIdFromString(slotEngine1);
		slot_id12 = InventorySlots.GetSlotIdFromString(slotEngine2);
		slot_id13 = InventorySlots.GetSlotIdFromString(slotEngine3);
		slot_id14 = InventorySlots.GetSlotIdFromString(slotEngine4);
		
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id1) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast5 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		slotCast6 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		slotCast7 = ItemBase.Cast( GetInventory().FindAttachment(slot_id6) );
		slotCast8 = ItemBase.Cast( GetInventory().FindAttachment(slot_id7) );
		slotCast9 = ItemBase.Cast( GetInventory().FindAttachment(slot_id8) );
		slotCast10 = ItemBase.Cast( GetInventory().FindAttachment(slot_id9) );
		slotCast11 = ItemBase.Cast( GetInventory().FindAttachment(slot_id10) );
		slotCast12 = ItemBase.Cast( GetInventory().FindAttachment(slot_id11) );
		slotCast13 = ItemBase.Cast( GetInventory().FindAttachment(slot_id12) );
		slotCast14 = ItemBase.Cast( GetInventory().FindAttachment(slot_id13) );
		slotCast15 = ItemBase.Cast( GetInventory().FindAttachment(slot_id14) );
		
		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL && slotCast5 != NULL && slotCast6 != NULL && slotCast7 != NULL && slotCast8 != NULL && slotCast9 != NULL && slotCast10 != NULL && slotCast11 != NULL && slotCast12 != NULL && slotCast13 != NULL && slotCast14 != NULL && slotCast15 != NULL)
		{
			return true;
		}
		return false;
		
	}
	override string j_Vehicle()
	{
		if ( hasProperPrep() )
		{
			return "Sedan_02";
		}
		return "SausageCo_Vehicle_SarkaBase_Kit";
	}	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player );
		
		if ( GetGame().IsServer() && hasProperPrep() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );
			vector newPosition = player_base.GetLocalProjectionPosition();
			vector newOrientation = player_base.GetLocalProjectionOrientation();
				
			EntityAI SausageCo_Vehicle_Kit = GetGame().CreateObjectEx(this.j_Vehicle(), newPosition, ECE_PLACE_ON_SURFACE );
			SausageCo_Vehicle_Kit.SetPosition( newPosition );
			SausageCo_Vehicle_Kit.SetOrientation( newOrientation );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Sedan_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Sedan_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Sedan_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Sedan_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Sedan_02_Hood" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Sedan_02_Trunk" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Sedan_02_Door_1_1" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Sedan_02_Door_2_1" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Sedan_02_Door_1_2" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Sedan_02_Door_2_2" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CarBattery" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HeadlightH7" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HeadlightH7" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CarRadiator" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "SparkPlug" );
			
			
		}	
		
		SetIsDeploySound( true );
		this.Delete();
	}
};
class SausageCo_Vehicle_OlgaBase_Kit extends SausageCo_Vehicle_Kit_Base
{	
	Car craftedCar;	
	
	string slotTire = "CivSedanWheel_1_1";
	string slotTire1 = "CivSedanWheel_1_2";
	string slotTire2 = "CivSedanWheel_2_1";
	string slotTire3 = "CivSedanWheel_2_2";
	
	string slotDoor = "CivSedanHood";
	string slotDoor1 = "CivSedanTrunk";
	string slotDoor2 = "CivSedanDriverDoors";
	string slotDoor3 = "CivSedanCoDriverDoors";
	string slotDoor4 = "CivSedanCargo1Doors";
	string slotDoor5 = "CivSedanCargo2Doors";
	
	string slotEngine = "CarBattery";
	string slotEngine1 = "Reflector_1_1";
	string slotEngine2 = "Reflector_2_1";
	string slotEngine3 = "CarRadiator";
	string slotEngine4 = "SparkPlug";

	int slot_id;
	int slot_id1;
	int slot_id2;
	int slot_id3;
	int slot_id4;
	int slot_id5;
	int slot_id6;
	int slot_id7;
	int slot_id8;
	int slot_id9;
	int slot_id10;
	int slot_id11;
	int slot_id12;
	int slot_id13;
	int slot_id14;

	ItemBase slotCast;
	ItemBase slotCast2;
	ItemBase slotCast3;
	ItemBase slotCast4;
	ItemBase slotCast5;
	ItemBase slotCast6;
	ItemBase slotCast7;
	ItemBase slotCast8;
	ItemBase slotCast9;
	ItemBase slotCast10;
	ItemBase slotCast11;
	ItemBase slotCast12;
	ItemBase slotCast13;
	ItemBase slotCast14;
	ItemBase slotCast15;
	
	override bool hasProperPrep()
	{
		slot_id = InventorySlots.GetSlotIdFromString(slotTire);
		slot_id1 = InventorySlots.GetSlotIdFromString(slotTire1);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotTire2);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotTire3);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotDoor);
		slot_id5 = InventorySlots.GetSlotIdFromString(slotDoor1);
		slot_id6 = InventorySlots.GetSlotIdFromString(slotDoor2);
		slot_id7 = InventorySlots.GetSlotIdFromString(slotDoor3);
		slot_id8 = InventorySlots.GetSlotIdFromString(slotDoor4);
		slot_id9 = InventorySlots.GetSlotIdFromString(slotDoor5);
		slot_id10 = InventorySlots.GetSlotIdFromString(slotEngine);
		slot_id11 = InventorySlots.GetSlotIdFromString(slotEngine1);
		slot_id12 = InventorySlots.GetSlotIdFromString(slotEngine2);
		slot_id13 = InventorySlots.GetSlotIdFromString(slotEngine3);
		slot_id14 = InventorySlots.GetSlotIdFromString(slotEngine4);
		
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id1) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast5 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		slotCast6 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		slotCast7 = ItemBase.Cast( GetInventory().FindAttachment(slot_id6) );
		slotCast8 = ItemBase.Cast( GetInventory().FindAttachment(slot_id7) );
		slotCast9 = ItemBase.Cast( GetInventory().FindAttachment(slot_id8) );
		slotCast10 = ItemBase.Cast( GetInventory().FindAttachment(slot_id9) );
		slotCast11 = ItemBase.Cast( GetInventory().FindAttachment(slot_id10) );
		slotCast12 = ItemBase.Cast( GetInventory().FindAttachment(slot_id11) );
		slotCast13 = ItemBase.Cast( GetInventory().FindAttachment(slot_id12) );
		slotCast14 = ItemBase.Cast( GetInventory().FindAttachment(slot_id13) );
		slotCast15 = ItemBase.Cast( GetInventory().FindAttachment(slot_id14) );
		
		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL && slotCast5 != NULL && slotCast6 != NULL && slotCast7 != NULL && slotCast8 != NULL && slotCast9 != NULL && slotCast10 != NULL && slotCast11 != NULL && slotCast12 != NULL && slotCast13 != NULL && slotCast14 != NULL && slotCast15 != NULL)
		{
			return true;
		}
		return false;
		
	}
	override string j_Vehicle()
	{
		if ( hasProperPrep() )
		{
			return "CivilianSedan";
		}
		return "SausageCo_Vehicle_OlgaBase_Kit";
	}	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player );
		
		if ( GetGame().IsServer() && hasProperPrep() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );
			vector newPosition = player_base.GetLocalProjectionPosition();
			vector newOrientation = player_base.GetLocalProjectionOrientation();
				
			EntityAI SausageCo_Vehicle_Kit = GetGame().CreateObjectEx(this.j_Vehicle(), newPosition, ECE_PLACE_ON_SURFACE );
			SausageCo_Vehicle_Kit.SetPosition( newPosition );
			SausageCo_Vehicle_Kit.SetOrientation( newOrientation );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CivSedanWheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CivSedanWheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CivSedanWheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CivSedanWheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CivSedanHood" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CivSedanTrunk" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CivSedanDoors_Driver" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CivSedanDoors_CoDriver" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CivSedanDoors_BackLeft" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CivSedanDoors_BackRight" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CarBattery" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HeadlightH7" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HeadlightH7" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CarRadiator" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "SparkPlug" );
			
			
		}	
		
		SetIsDeploySound( true );
		this.Delete();
	}
};
class SausageCo_Vehicle_GunterBase_Kit extends SausageCo_Vehicle_Kit_Base
{	
	Car craftedCar;	
	
	string slotTire = "Hatchback_02_Wheel_1_1";
	string slotTire1 = "Hatchback_02_Wheel_1_2";
	string slotTire2 = "Hatchback_02_Wheel_2_1";
	string slotTire3 = "Hatchback_02_Wheel_2_2";
	
	string slotDoor = "Hatchback_02_Hood";
	string slotDoor1 = "Hatchback_02_Trunk";
	string slotDoor2 = "Hatchback_02_Door_1_1";
	string slotDoor3 = "Hatchback_02_Door_1_2";
	string slotDoor4 = "Hatchback_02_Door_2_1";
	string slotDoor5 = "Hatchback_02_Door_2_2";
	
	string slotEngine = "CarBattery";
	string slotEngine1 = "Reflector_1_1";
	string slotEngine2 = "Reflector_2_1";
	string slotEngine3 = "CarRadiator";
	string slotEngine4 = "SparkPlug";

	int slot_id;
	int slot_id1;
	int slot_id2;
	int slot_id3;
	int slot_id4;
	int slot_id5;
	int slot_id6;
	int slot_id7;
	int slot_id8;
	int slot_id9;
	int slot_id10;
	int slot_id11;
	int slot_id12;
	int slot_id13;
	int slot_id14;

	ItemBase slotCast;
	ItemBase slotCast2;
	ItemBase slotCast3;
	ItemBase slotCast4;
	ItemBase slotCast5;
	ItemBase slotCast6;
	ItemBase slotCast7;
	ItemBase slotCast8;
	ItemBase slotCast9;
	ItemBase slotCast10;
	ItemBase slotCast11;
	ItemBase slotCast12;
	ItemBase slotCast13;
	ItemBase slotCast14;
	ItemBase slotCast15;
	
	override bool hasProperPrep()
	{
		slot_id = InventorySlots.GetSlotIdFromString(slotTire);
		slot_id1 = InventorySlots.GetSlotIdFromString(slotTire1);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotTire2);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotTire3);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotDoor);
		slot_id5 = InventorySlots.GetSlotIdFromString(slotDoor1);
		slot_id6 = InventorySlots.GetSlotIdFromString(slotDoor2);
		slot_id7 = InventorySlots.GetSlotIdFromString(slotDoor3);
		slot_id8 = InventorySlots.GetSlotIdFromString(slotDoor4);
		slot_id9 = InventorySlots.GetSlotIdFromString(slotDoor5);
		slot_id10 = InventorySlots.GetSlotIdFromString(slotEngine);
		slot_id11 = InventorySlots.GetSlotIdFromString(slotEngine1);
		slot_id12 = InventorySlots.GetSlotIdFromString(slotEngine2);
		slot_id13 = InventorySlots.GetSlotIdFromString(slotEngine3);
		slot_id14 = InventorySlots.GetSlotIdFromString(slotEngine4);
		
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id1) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast5 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		slotCast6 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		slotCast7 = ItemBase.Cast( GetInventory().FindAttachment(slot_id6) );
		slotCast8 = ItemBase.Cast( GetInventory().FindAttachment(slot_id7) );
		slotCast9 = ItemBase.Cast( GetInventory().FindAttachment(slot_id8) );
		slotCast10 = ItemBase.Cast( GetInventory().FindAttachment(slot_id9) );
		slotCast11 = ItemBase.Cast( GetInventory().FindAttachment(slot_id10) );
		slotCast12 = ItemBase.Cast( GetInventory().FindAttachment(slot_id11) );
		slotCast13 = ItemBase.Cast( GetInventory().FindAttachment(slot_id12) );
		slotCast14 = ItemBase.Cast( GetInventory().FindAttachment(slot_id13) );
		slotCast15 = ItemBase.Cast( GetInventory().FindAttachment(slot_id14) );
		
		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL && slotCast5 != NULL && slotCast6 != NULL && slotCast7 != NULL && slotCast8 != NULL && slotCast9 != NULL && slotCast10 != NULL && slotCast11 != NULL && slotCast12 != NULL && slotCast13 != NULL && slotCast14 != NULL && slotCast15 != NULL)
		{
			return true;
		}
		return false;
		
	}
	override string j_Vehicle()
	{
		if ( hasProperPrep() )
		{
			return "Hatchback_02";
		}
		return "SausageCo_Vehicle_GunterBase_Kit";
	}	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player );
		
		if ( GetGame().IsServer() && hasProperPrep() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );
			vector newPosition = player_base.GetLocalProjectionPosition();
			vector newOrientation = player_base.GetLocalProjectionOrientation();
				
			EntityAI SausageCo_Vehicle_Kit = GetGame().CreateObjectEx(this.j_Vehicle(), newPosition, ECE_PLACE_ON_SURFACE );
			SausageCo_Vehicle_Kit.SetPosition( newPosition );
			SausageCo_Vehicle_Kit.SetOrientation( newOrientation );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Hatchback_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Hatchback_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Hatchback_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Hatchback_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Hatchback_02_Hood" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Hatchback_02_Trunk" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Hatchback_02_Door_1_1" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Hatchback_02_Door_1_2" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Hatchback_02_Door_2_1" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Hatchback_02_Door_2_2" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CarBattery" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HeadlightH7" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HeadlightH7" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CarRadiator" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "SparkPlug" );
			
			
		}	
		
		SetIsDeploySound( true );
		this.Delete();
	}
};
class SausageCo_Vehicle_ADA4x4Base_Kit extends SausageCo_Vehicle_Kit_Base
{	
	Car craftedCar;	
	
	string slotTire = "NivaWheel_1_1";
	string slotTire1 = "NivaWheel_1_2";
	string slotTire2 = "NivaWheel_2_1";
	string slotTire3 = "NivaWheel_2_2";
	string slotTire4 = "NivaWheel_Spare_1";
	
	string slotDoor = "NivaHood";
	string slotDoor1 = "NivaTrunk";
	string slotDoor2 = "NivaDriverDoors";
	string slotDoor3 = "NivaCoDriverDoors";
	
	string slotEngine = "CarBattery";
	string slotEngine1 = "Reflector_1_1";
	string slotEngine2 = "Reflector_2_1";
	string slotEngine3 = "CarRadiator";
	string slotEngine4 = "SparkPlug";

	int slot_id;
	int slot_id1;
	int slot_id2;
	int slot_id3;
	int slot_id4;
	int slot_id5;
	int slot_id6;
	int slot_id7;
	int slot_id8;
	int slot_id9;
	int slot_id10;
	int slot_id11;
	int slot_id12;
	int slot_id13;

	ItemBase slotCast;
	ItemBase slotCast2;
	ItemBase slotCast3;
	ItemBase slotCast4;
	ItemBase slotCast5;
	ItemBase slotCast6;
	ItemBase slotCast7;
	ItemBase slotCast8;
	ItemBase slotCast9;
	ItemBase slotCast10;
	ItemBase slotCast11;
	ItemBase slotCast12;
	ItemBase slotCast13;
	ItemBase slotCast14;
	
	override bool hasProperPrep()
	{
		slot_id = InventorySlots.GetSlotIdFromString(slotTire);
		slot_id1 = InventorySlots.GetSlotIdFromString(slotTire1);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotTire2);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotTire3);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotTire4);
		slot_id5 = InventorySlots.GetSlotIdFromString(slotDoor);
		slot_id6 = InventorySlots.GetSlotIdFromString(slotDoor1);
		slot_id7 = InventorySlots.GetSlotIdFromString(slotDoor2);
		slot_id8 = InventorySlots.GetSlotIdFromString(slotDoor3);
		slot_id9 = InventorySlots.GetSlotIdFromString(slotEngine);
		slot_id10 = InventorySlots.GetSlotIdFromString(slotEngine1);
		slot_id11 = InventorySlots.GetSlotIdFromString(slotEngine2);
		slot_id12 = InventorySlots.GetSlotIdFromString(slotEngine3);
		slot_id13 = InventorySlots.GetSlotIdFromString(slotEngine4);
		
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id1) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast5 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		slotCast6 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		slotCast7 = ItemBase.Cast( GetInventory().FindAttachment(slot_id6) );
		slotCast8 = ItemBase.Cast( GetInventory().FindAttachment(slot_id7) );
		slotCast9 = ItemBase.Cast( GetInventory().FindAttachment(slot_id8) );
		slotCast10 = ItemBase.Cast( GetInventory().FindAttachment(slot_id9) );
		slotCast11 = ItemBase.Cast( GetInventory().FindAttachment(slot_id10) );
		slotCast12 = ItemBase.Cast( GetInventory().FindAttachment(slot_id11) );
		slotCast13 = ItemBase.Cast( GetInventory().FindAttachment(slot_id12) );
		slotCast14 = ItemBase.Cast( GetInventory().FindAttachment(slot_id13) );
		
		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL && slotCast5 != NULL && slotCast6 != NULL && slotCast7 != NULL && slotCast8 != NULL && slotCast9 != NULL && slotCast10 != NULL && slotCast11 != NULL && slotCast12 != NULL && slotCast13 != NULL && slotCast14 != NULL)
		{
			return true;
		}
		return false;
		
	}
	override string j_Vehicle()
	{
		if ( hasProperPrep() )
		{
			return "OffroadHatchback";
		}
		return "SausageCo_Vehicle_ADA4x4Base_Kit";
	}	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player );
		
		if ( GetGame().IsServer() && hasProperPrep() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );
			vector newPosition = player_base.GetLocalProjectionPosition();
			vector newOrientation = player_base.GetLocalProjectionOrientation();
				
			EntityAI SausageCo_Vehicle_Kit = GetGame().CreateObjectEx(this.j_Vehicle(), newPosition, ECE_PLACE_ON_SURFACE );
			SausageCo_Vehicle_Kit.SetPosition( newPosition );
			SausageCo_Vehicle_Kit.SetOrientation( newOrientation );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HatchbackWheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HatchbackWheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HatchbackWheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HatchbackWheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HatchbackHood" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HatchbackTrunk" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HatchbackDoors_Driver" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HatchbackDoors_CoDriver" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HatchbackWheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CarBattery" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HeadlightH7" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HeadlightH7" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CarRadiator" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "SparkPlug" );
			
			
		}	
		
		SetIsDeploySound( true );
		this.Delete();
	}
};
class SausageCo_Vehicle_M3SBase_Kit extends SausageCo_Vehicle_Kit_Base
{	
	Car craftedCar;	
	
	string slotTire = "Truck_01_Wheel_1_1";
	string slotTire1 = "Truck_01_Wheel_1_2";
	string slotTire2 = "Truck_01_Wheel_1_3";
	string slotTire3 = "Truck_01_Wheel_2_1";
	string slotTire4 = "Truck_01_Wheel_2_2";
	string slotTire5 = "Truck_01_Wheel_2_3";
	string slotTire6 = "Truck_01_Wheel_Spare_1";
	string slotTire7 = "Truck_01_Wheel_Spare_2";
	
	string slotDoor = "Truck_01_Door_1_1";
	string slotDoor1 = "Truck_01_Door_2_1";
	string slotDoor2 = "Truck_01_Hood";
	
	string slotEngine = "TruckBattery";
	string slotEngine1 = "Reflector_1_1";
	string slotEngine2 = "Reflector_2_1";

	int slot_id;
	int slot_id1;
	int slot_id2;
	int slot_id3;
	int slot_id4;
	int slot_id5;
	int slot_id6;
	int slot_id7;
	int slot_id8;
	int slot_id9;
	int slot_id10;
	int slot_id11;
	int slot_id12;
	int slot_id13;

	ItemBase slotCast;
	ItemBase slotCast2;
	ItemBase slotCast3;
	ItemBase slotCast4;
	ItemBase slotCast5;
	ItemBase slotCast6;
	ItemBase slotCast7;
	ItemBase slotCast8;
	ItemBase slotCast9;
	ItemBase slotCast10;
	ItemBase slotCast11;
	ItemBase slotCast12;
	ItemBase slotCast13;
	ItemBase slotCast14;
	
	override bool hasProperPrep()
	{
		slot_id = InventorySlots.GetSlotIdFromString(slotTire);
		slot_id1 = InventorySlots.GetSlotIdFromString(slotTire1);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotTire2);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotTire3);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotTire4);
		slot_id5 = InventorySlots.GetSlotIdFromString(slotTire5);
		slot_id6 = InventorySlots.GetSlotIdFromString(slotTire6);
		slot_id7 = InventorySlots.GetSlotIdFromString(slotTire7);
		slot_id8 = InventorySlots.GetSlotIdFromString(slotDoor);
		slot_id9 = InventorySlots.GetSlotIdFromString(slotDoor1);
		slot_id10 = InventorySlots.GetSlotIdFromString(slotDoor2);
		slot_id11 = InventorySlots.GetSlotIdFromString(slotEngine);
		slot_id12 = InventorySlots.GetSlotIdFromString(slotEngine1);
		slot_id13 = InventorySlots.GetSlotIdFromString(slotEngine2);
		
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id1) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast5 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		slotCast6 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		slotCast7 = ItemBase.Cast( GetInventory().FindAttachment(slot_id6) );
		slotCast8 = ItemBase.Cast( GetInventory().FindAttachment(slot_id7) );
		slotCast9 = ItemBase.Cast( GetInventory().FindAttachment(slot_id8) );
		slotCast10 = ItemBase.Cast( GetInventory().FindAttachment(slot_id9) );
		slotCast11 = ItemBase.Cast( GetInventory().FindAttachment(slot_id10) );
		slotCast12 = ItemBase.Cast( GetInventory().FindAttachment(slot_id11) );
		slotCast13 = ItemBase.Cast( GetInventory().FindAttachment(slot_id12) );
		slotCast14 = ItemBase.Cast( GetInventory().FindAttachment(slot_id13) );
		
		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL && slotCast5 != NULL && slotCast6 != NULL && slotCast7 != NULL && slotCast8 != NULL && slotCast9 != NULL && slotCast10 != NULL && slotCast11 != NULL && slotCast12 != NULL && slotCast13 != NULL && slotCast14 != NULL)
		{
			return true;
		}
		return false;
		
	}
	override string j_Vehicle()
	{
		if ( hasProperPrep() )
		{
			return "SausageCo_Truck_Nomadic";
		}
		return "SausageCo_Vehicle_M3SBase_Kit";
	}	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player );
		
		if ( GetGame().IsServer() && hasProperPrep() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );
			vector newPosition = player_base.GetLocalProjectionPosition();
			vector newOrientation = player_base.GetLocalProjectionOrientation();
				
			EntityAI SausageCo_Vehicle_Kit = GetGame().CreateObjectEx(this.j_Vehicle(), newPosition, ECE_PLACE_ON_SURFACE );
			SausageCo_Vehicle_Kit.SetPosition( newPosition );
			SausageCo_Vehicle_Kit.SetOrientation( newOrientation );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Truck_01_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Truck_01_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Truck_01_WheelDouble" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Truck_01_WheelDouble" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Truck_01_WheelDouble" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Truck_01_WheelDouble" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Truck_01_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Truck_01_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Truck_01_Hood" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Truck_01_Door_2_1" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Truck_01_Door_1_1" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HeadlightH7" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HeadlightH7" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "TruckBattery" );
			
			
		}	
		
		SetIsDeploySound( true );
		this.Delete();
	}
};
class SausageCo_Vehicle_HummerBase_Kit extends SausageCo_Vehicle_Kit_Base
{	
	Car craftedCar;	
	
	string slotTire = "Offroad_02_Wheel_1_1";
	string slotTire1 = "Offroad_02_Wheel_1_2";
	string slotTire2 = "Offroad_02_Wheel_2_1";
	string slotTire3 = "Offroad_02_Wheel_2_2";
	string slotTire4 = "Offroad_02_Wheel_Spare_1";
	
	string slotDoor = "Offroad_02_Door_1_1";
	string slotDoor1 = "Offroad_02_Door_2_1";
	string slotDoor2 = "Offroad_02_Door_1_2";
	string slotDoor3 = "Offroad_02_Door_2_2";
	string slotDoor4 = "Offroad_02_Hood";
	string slotDoor5 = "Offroad_02_Trunk";
	
	string slotEngine = "CarBattery";
	string slotEngine1 = "Reflector_1_1";
	string slotEngine2 = "Reflector_2_1";
	string slotEngine3 = "GlowPlug";

	int slot_id;
	int slot_id1;
	int slot_id2;
	int slot_id3;
	int slot_id4;
	int slot_id5;
	int slot_id6;
	int slot_id7;
	int slot_id8;
	int slot_id9;
	int slot_id10;
	int slot_id11;
	int slot_id12;
	int slot_id13;
	int slot_id14;

	ItemBase slotCast;
	ItemBase slotCast1;
	ItemBase slotCast2;
	ItemBase slotCast3;
	ItemBase slotCast4;
	ItemBase slotCast5;
	ItemBase slotCast6;
	ItemBase slotCast7;
	ItemBase slotCast8;
	ItemBase slotCast9;
	ItemBase slotCast10;
	ItemBase slotCast11;
	ItemBase slotCast12;
	ItemBase slotCast13;
	ItemBase slotCast14;
	
	override bool hasProperPrep()
	{
		slot_id = InventorySlots.GetSlotIdFromString(slotTire);
		slot_id1 = InventorySlots.GetSlotIdFromString(slotTire1);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotTire2);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotTire3);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotTire4);
		slot_id5 = InventorySlots.GetSlotIdFromString(slotDoor);
		slot_id6 = InventorySlots.GetSlotIdFromString(slotDoor1);
		slot_id7 = InventorySlots.GetSlotIdFromString(slotDoor2);
		slot_id8 = InventorySlots.GetSlotIdFromString(slotDoor3);
		slot_id9 = InventorySlots.GetSlotIdFromString(slotDoor4);
		slot_id10 = InventorySlots.GetSlotIdFromString(slotDoor5);
		slot_id11 = InventorySlots.GetSlotIdFromString(slotEngine);
		slot_id12 = InventorySlots.GetSlotIdFromString(slotEngine1);
		slot_id13 = InventorySlots.GetSlotIdFromString(slotEngine2);
		slot_id14 = InventorySlots.GetSlotIdFromString(slotEngine3);
		
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast1 = ItemBase.Cast( GetInventory().FindAttachment(slot_id1) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		slotCast5 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		slotCast6 = ItemBase.Cast( GetInventory().FindAttachment(slot_id6) );
		slotCast7 = ItemBase.Cast( GetInventory().FindAttachment(slot_id7) );
		slotCast8 = ItemBase.Cast( GetInventory().FindAttachment(slot_id8) );
		slotCast9 = ItemBase.Cast( GetInventory().FindAttachment(slot_id9) );
		slotCast10 = ItemBase.Cast( GetInventory().FindAttachment(slot_id10) );
		slotCast11 = ItemBase.Cast( GetInventory().FindAttachment(slot_id11) );
		slotCast12 = ItemBase.Cast( GetInventory().FindAttachment(slot_id12) );
		slotCast13 = ItemBase.Cast( GetInventory().FindAttachment(slot_id13) );
		slotCast14 = ItemBase.Cast( GetInventory().FindAttachment(slot_id14) );
		
		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL && slotCast5 != NULL && slotCast6 != NULL && slotCast7 != NULL && slotCast8 != NULL && slotCast9 != NULL && slotCast10 != NULL && slotCast11 != NULL && slotCast12 != NULL && slotCast13 != NULL && slotCast14 != NULL)
		{
			return true;
		}
		return false;
		
	}
	override string j_Vehicle()
	{
		if ( hasProperPrep() )
		{
			return "Offroad_02";
		}
		return "SausageCo_Vehicle_HummerBase_Kit";
	}	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		// super.OnPlacementComplete( player );
		
		if ( GetGame().IsServer() && hasProperPrep() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );
			vector newPosition = player_base.GetLocalProjectionPosition();
			vector newOrientation = player_base.GetLocalProjectionOrientation();
				
			EntityAI SausageCo_Vehicle_Kit = GetGame().CreateObjectEx(this.j_Vehicle(), newPosition, ECE_PLACE_ON_SURFACE );
			SausageCo_Vehicle_Kit.SetPosition( newPosition );
			SausageCo_Vehicle_Kit.SetOrientation( newOrientation );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Offroad_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Offroad_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Offroad_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Offroad_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Offroad_02_Hood" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Offroad_02_Trunk" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Offroad_02_Door_1_1" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Offroad_02_Door_2_1" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Offroad_02_Door_2_2" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Offroad_02_Door_1_2" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "Offroad_02_Wheel" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "CarBattery" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HeadlightH7" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "HeadlightH7" );
			SausageCo_Vehicle_Kit.GetInventory().CreateAttachment( "GlowPlug" );
			
			
		}	
		
		SetIsDeploySound( true );
		this.Delete();
	}
};
