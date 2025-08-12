class SC_Fridge_Base : SC_Openable_Base 
{
	//sound
	const string SOUND_HUMMING 		= "SC_RefrigeratorHumming_SoundSet";
	const string SOUND_TURN_ON		= "spotlight_turn_on_SoundSet";
	const string SOUND_TURN_OFF		= "spotlight_turn_off_SoundSet";
	
	protected EffectSound m_SoundHummingLoop;
	protected EffectSound m_SoundTurnOn;
	protected EffectSound m_SoundTurnOff;

	void SC_Fridge_Base()
	{
		m_AllowedSCCargo = {"SodaCan_ColorBase", "Bottle_Base", "Edible_Base"};
		m_SCCargoTagName = "isEdibleCargo";
	}

	//--- POWER EVENTS
	override void OnSwitchOn()
	{
		super.OnSwitchOn();
		
		//sound (client only)
		SoundTurnOn();
		
		//start preservation process
		StartPreservation();
	}

	override void OnSwitchOff()
	{
		super.OnSwitchOff();
		
		//sound (client only)
		SoundTurnOff();
		
		//stop preservation process
		StopPreservation();
	}
	
	override void OnWorkStart()
	{	
		//sound (client only)
		SoundHummingStart();
	}

	override void OnWorkStop()
	{		
		//sound (client only)
		SoundHummingStop();
	}

	override bool IsElectricAppliance()
	{
		return true;
	}

	override bool CanStoreCargo()
	{
		return false;
	}
	
	//================================================================
	// PRESERVATION SYSTEM
	//================================================================
	protected void StartPreservation()
	{
		if (!GetGame().IsServer())
			return;
			
		array<EntityAI> cargo_items = new array<EntityAI>;
		GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, cargo_items);
		
		foreach (EntityAI item : cargo_items)
		{
			Edible_Base food = Edible_Base.Cast(item);
			if (food)
			{
				// Reduce temperature if item has temperature system
				if (food.CanHaveTemperature())
				{
					float current_temp = food.GetTemperature();
					if (current_temp > 4) // Keep food at fridge temperature (4°C)
					{
						food.SetTemperature(Math.Max(4, current_temp - 10));
					}
				}
			}
		}
		
		// Schedule next update
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.StartPreservation, 10000, false); // Update every 10 seconds
	}
	
	protected void StopPreservation()
	{
		if (!GetGame().IsServer())
			return;
			
		// Clear the scheduled update
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.StartPreservation);
	}
	
	//================================================================
	// SOUNDS
	//================================================================
	protected void SoundHummingStart()
	{
		PlaySoundSetLoop( m_SoundHummingLoop, SOUND_HUMMING, 0.1, 0.3 );
	}
	
	protected void SoundHummingStop()
	{
		StopSoundSet( m_SoundHummingLoop );
	}	

	protected void SoundTurnOn()
	{
		PlaySoundSet( m_SoundTurnOn, SOUND_TURN_ON, 0, 0);
	}
	
	protected void SoundTurnOff()
	{
		PlaySoundSet( m_SoundTurnOff, SOUND_TURN_OFF, 0, 0);
	}

	override void SoundOpenPlay()
	{
	}
	
	override void SoundClosePlay()
	{
	}

	override void SetActions()
	{
		super.SetActions();		
		AddAction(ActionUnplugThisByCord);
		AddAction(ActionTurnOnWhileOnGround);
		AddAction(ActionTurnOffWhileOnGround);
	}
};