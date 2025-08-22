
class SC_SolarPanel_Kit extends ItemBase
{	
	ref protected EffectSound 					m_DeployLoopSound;
	protected Object							SC_SolarPanel_Kit1;	
	
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
		vector positionChange = "0 1.0 0";
		position += positionChange;
	#else
	override void OnPlacementComplete(Man player, vector position = "0 1.0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
	#endif
			if (GetGame().IsServer())
			{
				EntityAI kitItem = EntityAI.Cast(GetGame().CreateObjectEx("SC_SolarPanel", position, ECE_PLACE_ON_SURFACE));
				vector positionChange = "0 1.0 0";
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

class SC_SolarPanel_Holo extends ItemBase
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

class SC_SolarPanel extends PowerGenerator
{
    // Model selections
	static protected const string SEL_CLIPS_CAR			= "clips_car_battery";
	static protected const string SEL_CLIPS_TRUCK		= "clips_truck_battery";
	static protected const string SEL_CLIPS_DETACHED	= "clips_detached";
	static protected const string SEL_CLIPS_FOLDED		= "clips_folded";
	static protected const string SEL_SWITCH_ON			= "switch_on";
	static protected const string SEL_SWITCH_OFF		= "switch_off";
	static protected const string SEL_CORD_PLUGGED		= "cord_plugged";
	static protected const string SEL_CORD_FOLDED		= "cord_folded";
	static protected const string SEL_LIGHT_STATE_1		= "light_stand_by";
	static protected const string SEL_LIGHT_STATE_2		= "light_charging";
	static protected const string SEL_LIGHT_STATE_3		= "light_charged";
	
	// glow materials
	static protected const string RED_LIGHT_GLOW		= "dz\\gear\\camping\\data\\battery_charger_light_r.rvmat";
	static protected const string GREEN_LIGHT_GLOW		= "dz\\gear\\camping\\data\\battery_charger_light_g.rvmat";
	static protected const string YELLOW_LIGHT_GLOW		= "dz\\gear\\camping\\data\\battery_charger_light_y.rvmat";
	static protected const string SWITCH_LIGHT_GLOW		= "dz\\gear\\camping\\data\\battery_charger_light_switch_on.rvmat";
	static protected const string DEFAULT_MATERIAL 		= "dz\\gear\\camping\\data\\battery_charger.rvmat";
	
	protected const string 	ATTACHED_CLIPS_STATES[] 		= {SEL_CLIPS_CAR, SEL_CLIPS_TRUCK}; // TO DO: If it's required by design, add helicopter battery here and register its selection names.
	protected const int 	ATTACHED_CLIPS_STATES_COUNT		= 2; // Reffers to this ^ array
	
	int 					m_BatteryEnergy0To100;
	protected float 		m_ChargeEnergyPerSecond;
	
	static protected 	float 	m_BlinkingStatusLightInterval = 0.4; // How often the lights blink
	ref 				Timer 	m_UpdateStatusLightsTimer;
	protected 			bool 	m_BlinkingStatusLightIsOn = false;	// Status of one blinking light

	protected int				SolarCheckTime;
	protected bool              m_IsNight;
	protected bool              m_IsUnderRoof;
	
	void SC_SolarPanel()
	{
		m_ChargeEnergyPerSecond = GetGame().ConfigGetFloat ("CfgVehicles " + GetType() + " ChargeEnergyPerSecond");
		m_UpdateStatusLightsTimer = new Timer( CALL_CATEGORY_SYSTEM );
		SwitchLightOff();
		RegisterNetSyncVariableInt("m_BatteryEnergy0To100");
		//RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		//RegisterNetSyncVariableBool("m_IsPlaceSound");
		SetEventMask(EntityEvent.INIT); // Enable EOnInit event
		m_IsNight = false;
		m_IsUnderRoof = false;
	}

	void ~SC_SolarPanel()
	{
	}

	// Init
	override void OnInitEnergy()
	{
		
	}
	
	override void EOnInit( IEntity other, int extra)
	{
		if ( GetGame().IsServer() )
		{
			//Switch charger on or off
			if ( HasBattery() )
			{
				if ( !GetCompEM().IsSwitchedOn() )
				{
					GetCompEM().SwitchOn();
				}
			}
			else
			{
				if ( GetCompEM().CanSwitchOff() )
				{
					GetCompEM().SwitchOff();
				}
			}
			SetSynchDirty();
		}
	}

	override bool IsHeavyBehaviour() 
    {
        return true;
    }
    
    override bool IsTwoHandedBehaviour() 
    {
        return true;
    }

	bool HasBattery()
	{
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("CarBattery");
		ItemBase battery = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		// If battery is not ruined
		if ( battery && !battery.IsRuined() )
		{
			return true;
		}
		return false;
	}
	
	bool HasWorkingBattery()
	{
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("CarBattery");
		ItemBase battery = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		// If battery is not dead or ruined
		if ( battery && !battery.IsRuined() && battery.GetCompEM().GetEnergy() > 0.1 )
		{
			return true;
		}
		return false;
	}
	
	override bool IsElectricAppliance()
	{
		return true;
	}

	bool IsRoofAbove()
    {
		return MiscGameplayFunctions.IsUnderRoof( this );
    }

	void BeginChargingBattery()
	{
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("CarBattery");
		ItemBase battery = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		// If battery is dead but not ruined
		if ( battery && !battery.IsRuined() && battery.GetCompEM().GetEnergy() < 0.1 ) // If battery is depleted and not ruined
		{
			battery.GetCompEM().AddEnergy(1.0); // Add some energy to kickstart charging
		}
	}

	bool GetSun()
	{
		if ( !GetGame().GetWorld().IsNight()) // Sun is visible
		{
			return true;
		}
		return false;
	}

	override void OnWork( float consumed_energy )
	{
		// Charge and drain functionality
		int slot_id_battery;
		ItemBase battery;
		slot_id_battery = InventorySlots.GetSlotIdFromString("CarBattery");
		battery = GetInventory().FindAttachment( slot_id_battery );
		
		if ( battery )
		{
			if ( GetGame().IsServer() )
			{
				// Update environment state
				m_IsNight = GetGame().GetWorld().IsNight();
				m_IsUnderRoof = IsRoofAbove();
				
				// Charge or drain battery
				float battery_capacity = battery.GetCompEM().GetEnergyMax();
				if ( !battery.IsRuined() ) // If battery is not ruined
				{
					// Heat up the items so players know they are working, but not too hot
					this.SetTemperature(40); 
					battery.SetTemperature(40);
					
					float charger_health = GetHealth("", "");
					float energy_add = m_ChargeEnergyPerSecond * ( consumed_energy / GetCompEM().GetEnergyUsage() );
					float energy_consume = 0;
					int getAppliances = GetCompEM().GetPoweredDevices().Count();
					float poweredAppliances = getAppliances / 20; // Reduced impact of appliances
					
					if ( battery ) // Bypass power source energy check
					{
						if ( GetCompEM().GetPluggedDevicesCount() <= 1 ) // Just battery attached
						{
							if ( m_IsNight || m_IsUnderRoof ) // If no sun present
							{
								energy_add = 0; // Don't add energy
								energy_consume = 0.01; // Minimal standby drain
							}
							else // There is enough energy to use
							{
								energy_add = energy_add * ( 0.5 + charger_health*0.005 ); // Improved efficiency
							}
						}
						if ( GetCompEM().GetPluggedDevicesCount() == 2 ) // 1 appliance attached
						{
							if ( m_IsNight || m_IsUnderRoof ) // If no sun present
							{
								energy_add = 0;
								energy_consume = 0.05 + poweredAppliances; // Reduced drain
							}
							else // There is enough energy to use
							{
								energy_add = energy_add * ( 0.4 + charger_health*0.005 ); // Slightly less efficient with appliance
							}
						}
						if ( GetCompEM().GetPluggedDevicesCount() == 3 ) // 2 appliances attached
						{
							if ( m_IsNight || m_IsUnderRoof ) // If no sun present
							{
								energy_add = 0;
								energy_consume = 0.1 + poweredAppliances; // Reduced drain
							}
							else // There is enough energy to use
							{
								energy_add = energy_add * ( 0.3 + charger_health*0.005 ); // Less efficient with more appliances
							}
						}
						if ( GetCompEM().GetPluggedDevicesCount() == 4 ) // 3 appliances attached
						{
							if ( m_IsNight || m_IsUnderRoof ) // If no sun present
							{
								energy_add = 0;
								energy_consume = 0.15 + poweredAppliances; // Reduced drain
							}
							else // There is enough energy to use
							{
								energy_add = energy_add * ( 0.2 + charger_health*0.005 ); // Less efficient with more appliances
							}
						}
						if ( GetCompEM().GetPluggedDevicesCount() > 4 ) // More than 3 appliances attached
						{
							if ( m_IsNight || m_IsUnderRoof ) // If no sun present
							{
								energy_add = 0;
								energy_consume = 0.2 + poweredAppliances; // Reduced drain
							}
							else // There is some energy to use
							{
								energy_add = energy_add * ( 0.1 + charger_health*0.005 ); // Much less efficient with many appliances
							}
						}
					}
					if ( (battery.GetCompEM().GetEnergy() + energy_add) < battery_capacity ) // If battery has capacity
					{
						battery.GetCompEM().AddEnergy( energy_add ); // Charge
					}
					if ( (battery.GetCompEM().GetEnergy() - energy_consume) > 0 ) // If battery is not dead
					{
						battery.GetCompEM().ConsumeEnergy( energy_consume ); // Deplete
					}
				}

				if ( battery.IsRuined() ) // If battery is ruined
				{
					// Kill power
					if ( GetCompEM().CanSwitchOff() )
					{
						GetCompEM().SwitchOff();
					}
				}
				
				if ( battery.GetCompEM().GetEnergy() < 0.1 ) // If battery is depleted (less than 10%)
				{
					if ( m_IsNight || m_IsUnderRoof ) // If no sun present
					{
						// Kill power
						if ( GetCompEM().CanSwitchOff() )
						{
							GetCompEM().SwitchOff();
						}
						SolarLightBlink();
					}
					else
					{
						SetFuel(GetMaxFuel());
						if ( !GetCompEM().IsSwitchedOn() )
						{
							GetCompEM().SwitchOn();
						}
						BeginChargingBattery();
					}
				}
				m_BatteryEnergy0To100 = battery.GetCompEM().GetEnergy0To100();
				SetSynchDirty();
			}
		}
	}

	
	void SolarLightBlink()
	{
		if (m_BlinkingStatusLightIsOn)
			RedLightOn();
		else
			RedLightOff();
		
		m_BlinkingStatusLightIsOn = !m_BlinkingStatusLightIsOn;
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( SolarCallBack, 5000, false ); // Reduced to 5 seconds
	}

	void SolarCallBack()
	{
		RedLightOff();
		int SCSolarCheckTime = 120; // Reduced to 2 minutes
		SolarCheckTime = SCSolarCheckTime; // time in seconds it will take to produce a cement block.
		int SolarTime = SolarCheckTime * 1000; // converting to milliseconds for Callback Queue
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( SunCheck, SolarTime, false );
	}
	
	void SunCheck()
	{
		if ( GetSun() && !IsRoofAbove() )
		{
			SetFuel(GetMaxFuel());
			if ( !GetCompEM().IsSwitchedOn() )
			{
				GetCompEM().SwitchOn();
			}
			BeginChargingBattery();
		}
		else 
		{
			SolarLightBlink();
		}
	}

	override void OnWorkStart()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			UpdateStatusLights();
			m_UpdateStatusLightsTimer.Run( m_BlinkingStatusLightInterval/2 , this, "UpdateStatusLights", NULL, true);
		}
	}
		
	override void OnWorkStop()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			UpdateStatusLights();
			m_UpdateStatusLightsTimer.Stop();
		}
	}

	override void EEItemAttached ( EntityAI item, string slot_name )
	{
		super.EEItemAttached ( item, slot_name );
		ItemBase item_IB = ItemBase.Cast( item );
		if ( item_IB && (item_IB.IsKindOf("TruckBattery") || item_IB.IsKindOf("CarBattery")) )
		{
			// Add fuel
			SetFuel(GetMaxFuel());
			if ( item_IB.GetCompEM().GetEnergy() < 0.1 ) // If battery is depleted
			{
				item_IB.GetCompEM().AddEnergy(0.5); // Add some energy to kickstart charging
			}
			// Power on
			if ( !GetCompEM().IsSwitchedOn() )
			{
				GetCompEM().SwitchOn();
			}
			item_IB.GetCompEM().PlugThisInto(this);
			OnWork(0.1);
			UpdateStatusLights();
		}
	}
	
	override void EEItemDetached ( EntityAI item, string slot_name )
	{
		super.EEItemDetached ( item, slot_name );
		ItemBase item_IB = ItemBase.Cast( item );
		if ( item_IB && (item_IB.IsKindOf("TruckBattery") || item_IB.IsKindOf("CarBattery")) )
		{
			// Kill power
			SetFuel(GetMaxFuel());
			if ( GetCompEM().CanSwitchOff() )
			{
				GetCompEM().SwitchOff();
			}
			item_IB.GetCompEM().UnplugThis();
			GetCompEM().UnplugAllDevices();
			UpdateStatusLights();
		}
	}

	override void AfterStoreLoad()
	{
		// Begin charging if battery is attached
		if ( HasBattery() )
		{
			SetFuel(GetMaxFuel());
			if ( !GetCompEM().IsSwitchedOn() )
			{
				GetCompEM().SwitchOn();
			}
			BeginChargingBattery();
			OnWork(0.1);
			UpdateStatusLights();
		}
		super.AfterStoreLoad();
	}
	
	void UpdateStatusLights()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			if (GetCompEM().IsWorking())
			{
				SwitchLightOn();
				ItemBase battery = ItemBase.Cast( GetCompEM().GetPluggedDevice() );
				
				if (battery)
				{
					RedLightOff();
					
					if (m_BatteryEnergy0To100 <= 33)
					{
						// Less than 1/3 charged, yellow status light must repeatedly blink
						if (m_BlinkingStatusLightIsOn)
							YellowLightOn();
						else
							YellowLightOff();
						
						m_BlinkingStatusLightIsOn = !m_BlinkingStatusLightIsOn;
					}
					else if (m_BatteryEnergy0To100 > 33  &&  m_BatteryEnergy0To100 <= 66)
					{
						// Less than 2/3 charged, yellow status light must glow
						YellowLightOn();
					}
					else if (m_BatteryEnergy0To100 > 66  &&  m_BatteryEnergy0To100 < 100)
					{
						// Less than 3/3 charged, yellow status light must glow, green light must blink
						YellowLightOn();
						
						if (m_BlinkingStatusLightIsOn)
							GreenLightOn();
						else
							GreenLightOff();
						
						m_BlinkingStatusLightIsOn = !m_BlinkingStatusLightIsOn;
					}
					else if (m_BatteryEnergy0To100 >= 100)
					{
						// Fully charged, green light must glow
						YellowLightOff();
						GreenLightOn();
					}
				}
				else
				{
					if (m_BlinkingStatusLightIsOn)
						RedLightOn();
					else
						RedLightOff();
					
					m_BlinkingStatusLightIsOn = !m_BlinkingStatusLightIsOn;
					
					GreenLightOff();
					YellowLightOff();
				}
			}
			else
			{
				SwitchLightOff();
				GreenLightOff();
				RedLightOff();
				YellowLightOff();
			}
		}
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}

	override bool CanPutIntoHands( EntityAI player ) 
	{
		return false;
	}

	override void OnOwnSocketTaken( EntityAI device )
	{
		string att_type = device.GetType();
		
		if ( att_type == "CarBattery" )
		{
			HideAttachedClipsStates();
			ShowSelection(SEL_CLIPS_CAR);
		}
		
		if ( att_type == "TruckBattery" )
		{
			HideAttachedClipsStates();
			ShowSelection(SEL_CLIPS_TRUCK);
		}
		
		HideSelection(SEL_CLIPS_DETACHED);
		HideSelection(SEL_CLIPS_FOLDED);
	}

	override void OnOwnSocketReleased( EntityAI device )
	{
		HideAttachedClipsStates();
		ShowSelection(SEL_CLIPS_DETACHED);
	}

	//Disallow detaching battery with appliances connected
	/*bool CanReleaseAttachment (EntityAI attachment)
	{
		if ( GetCompEM().GetPluggedDevicesCount() <= 1 )
		{
			return true;
		}
		return false;
	}

	override bool CanDetachAttachment( EntityAI parent )
	{
		if ( GetCompEM().GetPluggedDevicesCount() <= 1 )
		{
			return true;
		}
		return false;
	}*/
	
	override bool CanReceiveAttachment( EntityAI attachment, int slotId ) 
	{
		if ( !super.CanReceiveAttachment(attachment, slotId) )
			return false;
		
		ItemBase ibase;
		Class.CastTo(ibase, attachment);
		
		// No attaching if the charger is in inventory!
		PlayerBase charger_owner = PlayerBase.Cast( GetHierarchyRootPlayer() );
		if ( charger_owner )
			return false;
		
		// Only one attachment allowed
		if ( GetCompEM().GetPluggedDevice() )
			return false;
		
		if ( ibase.HasEnergyManager()  &&  ibase.GetCompEM().GetPluggedDevicesCount() >= 1 ) // Make sure nothing is plugged into the battery
			return false;
		
		return true;
	}
	
	override bool CanLoadAttachment( EntityAI attachment) 
	{
		if ( !super.CanLoadAttachment(attachment) )
			return false;
		
		ItemBase ibase;
		Class.CastTo(ibase, attachment);
		
		// Only one attachment allowed
		if ( GetCompEM().GetPluggedDevice() )
			return false;
		
		if ( ibase.HasEnergyManager()  &&  ibase.GetCompEM().GetPluggedDevicesCount() >= 1 ) // Make sure nothing is plugged into the battery
			return false;
		
		return true;
	}
	
	void HideAttachedClipsStates()
	{
		for ( int i = 0; i < ATTACHED_CLIPS_STATES_COUNT; i++ )
		{
			string selection = ATTACHED_CLIPS_STATES[i];
			HideSelection(selection);
		}
	}
	
	// Control of status lights
	// ON
	void RedLightOn()
	{
		SetObjectMaterial( 0, RED_LIGHT_GLOW );
	}
	void GreenLightOn()
	{
		SetObjectMaterial( 2, GREEN_LIGHT_GLOW );
	}
	void YellowLightOn()
	{
		SetObjectMaterial( 1, YELLOW_LIGHT_GLOW );
	}
	void SwitchLightOn()
	{
		SetObjectMaterial( 3, SWITCH_LIGHT_GLOW );
	}
	// OFF
	void RedLightOff()
	{
		SetObjectMaterial( 0, DEFAULT_MATERIAL );
	}
	void GreenLightOff()
	{
		SetObjectMaterial( 2, DEFAULT_MATERIAL );
	}
	void YellowLightOff()
	{
		SetObjectMaterial( 1, DEFAULT_MATERIAL );
	}
	void SwitchLightOff()
	{
		SetObjectMaterial( 3, DEFAULT_MATERIAL );
	}
	
	override void OnSwitchOn()
	{
		HideSelection(SEL_SWITCH_OFF);
		ShowSelection(SEL_SWITCH_ON);
	}
	
	override void OnSwitchOff()
	{
		HideSelection(SEL_SWITCH_ON);
		ShowSelection(SEL_SWITCH_OFF);
	}
	
	// Inventory manipulation
	override void OnInventoryExit(Man player)
	{
		super.OnInventoryExit(player);
		HideAttachedClipsStates();
		HideSelection(SEL_CLIPS_FOLDED);
		ShowSelection(SEL_CLIPS_DETACHED);
	}
	
	override void OnInventoryEnter(Man player)
	{
		super.OnInventoryEnter(player);
		HideAttachedClipsStates();
		HideSelection(SEL_CLIPS_DETACHED);
		ShowSelection(SEL_CLIPS_FOLDED);
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		if ( IsPlaceSound() )
		{
			PlayPlaceSound();
		}
	}
	
	// override void RefreshPhysics()
	// {
		// super.RefreshPhysics();
		// if ( GetAttachmentByType(CarBattery) )
		// {
			// RemoveProxyPhysics( "battery" );
			// AddProxyPhysics( "battery" );
		// }
		// else
			// RemoveProxyPhysics( "battery" );
	// }
	
	override string GetPlaceSoundset()
	{
		return "placeBatteryCharger_SoundSet";
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionPlugIn);
		AddAction(ActionUnplugThisByCord);
		AddAction(ActionPullOutPlug);
		RemoveAction(ActionTurnOnSolarPanel);
		RemoveAction(ActionTurnOffSolarPanel);
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
	
}
