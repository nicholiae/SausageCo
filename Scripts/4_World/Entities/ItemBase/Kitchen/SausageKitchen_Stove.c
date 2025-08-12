class SausageKitchen_Stove extends ItemBase
{
	StoveLight	m_Light;
	
	protected const string FLAME_BUTANE_ON 			= "dz\\gear\\cooking\\data\\flame_butane_ca.paa";
	protected const string FLAME_BUTANE_OFF 		= "";
	typename ATTACHMENT_COOKING_POT 				= Pot;
	typename ATTACHMENT_FRYING_PAN 					= FryingPan;
	typename ATTACHMENT_CAULDRON	 				= Cauldron;
	
	//cooking
	protected const float PARAM_COOKING_TIME_INC_COEF			= 0.5;		//cooking time increase coeficient, can be used when balancing how fast a food can be cooked
	protected const float PARAM_COOKING_TARGET_TEMP				= 400;		//target temperature for general item heating
	
	private 		float m_TimeFactor;
	//
	ref Cooking m_CookingProcess;
	ItemBase m_CookingEquipment[4]; // Replace single variable with array
	
	//sound
	const string SOUND_BURNING 		= "portablegasstove_burn_SoundSet";
	const string SOUND_TURN_ON		= "portablegasstove_turn_on_SoundSet";
	const string SOUND_TURN_OFF		= "portablegasstove_turn_off_SoundSet";
	
	protected EffectSound m_SoundBurningLoop;
	protected EffectSound m_SoundTurnOn;
	protected EffectSound m_SoundTurnOff;
	
	protected ref UniversalTemperatureSource m_UTSource;
	protected ref UniversalTemperatureSourceSettings m_UTSSettings;
	protected ref UniversalTemperatureSourceLambdaConstant m_UTSLConst;
	
	//cooking equipment
	ItemBase GetCookingEquipment(int slot = 0)
	{
		return m_CookingEquipment[slot];
	}

	void SetCookingEquipment(ItemBase equipment, int slot = 0)
	{
		m_CookingEquipment[slot] = equipment;
	}

	void ClearCookingEquipment(ItemBase pItem, int slot = 0)
	{
		if (m_CookingProcess)
		{
			m_CookingProcess.TerminateCookingSounds(pItem);
		}
		
		SetCookingEquipment(null, slot);
	}

	//Destroy
	void DestroyFireplace()
	{
		//delete object
		GetGame().ObjectDelete(this);
	}
	
	override void EEInit()
	{		
		super.EEInit();
		
		if (m_CookingProcess == null)
			m_CookingProcess = new Cooking();
		m_CookingProcess.SetCookingUpdateTime(GetCompEM().GetUpdateInterval());
		
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
 			m_UTSSettings 						= new UniversalTemperatureSourceSettings();
			m_UTSSettings.m_ManualUpdate		= true;
			m_UTSSettings.m_TemperatureItemCap 	= GameConstants.ITEM_TEMPERATURE_NEUTRAL_ZONE_MIDDLE;
			m_UTSSettings.m_TemperatureCap		= 0;
			m_UTSSettings.m_RangeFull			= 0;
			m_UTSSettings.m_RangeMax			= 0;
			m_UTSSettings.m_IsWorldOverriden	= false;
			
			m_UTSLConst							= new UniversalTemperatureSourceLambdaConstant();
			m_UTSource							= new UniversalTemperatureSource(this, m_UTSSettings, m_UTSLConst);
		}		
	}
	
	//--- ATTACHMENTS
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		
		//cookware
		if (item.IsCookware())
		{
			int slot = -1;
			if (slot_name == "DirectCookingA" || slot_name == "CookingEquipment")
				slot = 0;
			else if (slot_name == "DirectCookingB")
				slot = 1;
			else if (slot_name == "DirectCookingC")
				slot = 2;
				
			if (slot >= 0)
			{
				SetCookingEquipment(ItemBase.Cast(item), slot);
				RefreshFlameVisual(m_EM.IsSwitchedOn(), true);
			}
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		//cookware
		if (item.IsCookware())
		{
			int slot = -1;
			if (slot_name == "DirectCookingA" || slot_name == "CookingEquipment")
				slot = 0;
			else if (slot_name == "DirectCookingB")
				slot = 1;
			else if (slot_name == "DirectCookingC")
				slot = 2;
				
			if (slot >= 0)
			{
				ClearCookingEquipment(ItemBase.Cast(item), slot);
				RefreshFlameVisual(m_EM.IsSwitchedOn(), false);
			}
		}
		
		//stop effects
		RemoveCookingAudioVisuals();
	}
	
	//--- POWER EVENTS
	override void OnSwitchOn()
	{
		super.OnSwitchOn();
		
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_UTSource.SetDefferedActive(true, 3.0);
		}
		
		//sound (client only)
		SoundTurnOn();
	}

	override void OnSwitchOff()
	{
		super.OnSwitchOff();
		
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_UTSource.SetDefferedActive(false, 5.0);
		}
		
		//sound (client only)
		SoundTurnOff();
		if (m_CookingProcess && GetCookingEquipment())
		{
			m_CookingProcess.TerminateCookingSounds(GetCookingEquipment());
		}
	}
	
	override void OnWorkStart()
	{
		super.OnWorkStart();

		#ifndef SERVER
		m_Light = StoveLight.Cast(ScriptedLightBase.CreateLight(StoveLight, "0 0 0"));
		m_Light.AttachOnMemoryPoint(this, "light");
		#endif
		
		//refresh visual
		RefreshFlameVisual(true, GetCookingEquipment() != null);
		
		//sound (client only)
		SoundBurningStart();
	}

	override void OnWork(float consumed_energy)
	{
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_UTSource.Update(m_UTSSettings, m_UTSLConst);
		}

		//manage cooking equipment for all slots
		for (int i = 0; i < 4; i++)
		{
			ItemBase item = GetCookingEquipment(i);
			if (item && item.CanHaveTemperature())
			{
				if (GetGame() && GetGame().IsServer())
				{
					float cook_equip_temp = item.GetTemperature();
					float target;
					if (!GetCookingTargetTemperature(target))
						target = PARAM_COOKING_TARGET_TEMP;
					
					float diff = target - cook_equip_temp;
					float heatPermCoef = item.GetHeatPermeabilityCoef();
					
					if (diff > 0)
						item.SetTemperatureEx(new TemperatureDataInterpolated(target, ETemperatureAccessTypes.ACCESS_FIREPLACE, GetCompEM().GetUpdateInterval(), GameConstants.TEMP_COEF_GAS_STOVE, heatPermCoef));
					
					m_TimeFactor = consumed_energy;
					CookWithEquipment(i);
					
					GetCookingEquipment(i).DecreaseHealth(GameConstants.FIRE_ATTACHMENT_DAMAGE_PER_SECOND * GetCompEM().GetUpdateInterval(), false);
				}
			}
		}
	}
	
	
	void CookWithEquipment(int slot = 0)
	{
		if (m_CookingProcess == null)
			m_CookingProcess = new Cooking();
		
		m_CookingProcess.CookWithEquipment(GetCookingEquipment(slot), PARAM_COOKING_TIME_INC_COEF * m_TimeFactor);
	}
	
	override bool GetCookingTargetTemperature(out float temperature)
	{
		temperature = PARAM_COOKING_TARGET_TEMP;
		return true;
	}

	protected void RefreshFlameVisual(bool working = false, bool hasAttachment = false)
	{
		if (!working)
		{
			SetObjectTexture(0, FLAME_BUTANE_OFF);
			SetObjectTexture(1, FLAME_BUTANE_OFF);

			return;
		}
		
		if (!hasAttachment)
		{
			//! full size flame selection
			SetObjectTexture(0, FLAME_BUTANE_ON);
			SetObjectTexture(1, FLAME_BUTANE_OFF);
		}
		else
		{
			//! shrinked flame selection
			SetObjectTexture(0, FLAME_BUTANE_OFF);
			SetObjectTexture(1, FLAME_BUTANE_ON);
		}
	}

	//================================================================
	// PARTICLES
	//================================================================	
	//cooking equipment steam
	protected void RemoveCookingAudioVisuals()
	{
		ItemBase cookEquipment;
		if (Class.CastTo(cookEquipment,GetCookingEquipment()) && (cookEquipment.IsCookware() || cookEquipment.IsLiquidContainer())) //also stops boiling effect on bottles
			cookEquipment.RemoveAudioVisualsOnClient();
	}
	//================================================================
	// SOUNDS
	//================================================================
	protected void SoundBurningStart()
	{
		PlaySoundSetLoop( m_SoundBurningLoop, SOUND_BURNING, 0.1, 0.3 );
	}
	
	protected void SoundBurningStop()
	{
		StopSoundSet( m_SoundBurningLoop );
	}	

	protected void SoundTurnOn()
	{
		PlaySoundSet( m_SoundTurnOn, SOUND_TURN_ON, 0.1, 0.1 );
	}
	
	protected void SoundTurnOff()
	{
		PlaySoundSet( m_SoundTurnOff, SOUND_TURN_OFF, 0.1, 0.1 );
	}		
		
	//================================================================
	// CONDITIONS
	//================================================================
	override bool IsSelfAdjustingTemperature() //prevents CE temperature updates in vicinity, does not really have its own temperature
	{
		return GetCompEM().IsWorking();
	}
	
	//this into/outo parent.Cargo
	override bool CanPutInCargo( EntityAI parent )
	{
		if ( !super.CanPutInCargo(parent) ) {return false;}
		if ( GetCompEM().IsSwitchedOn() )
		{
			return false;
		}
		
		return false;
	}

	override bool CanRemoveFromCargo( EntityAI parent )
	{
		return true;
	}
	
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		InventoryLocation loc = new InventoryLocation();
		EntityAI ent = this;
		EntityAI parent;
		while (ent)
		{
			if (ent.GetInventory().GetCurrentInventoryLocation(loc) && loc.IsValid())
			{
				if (loc.GetType() == InventoryLocationType.CARGO)
				{
					parent = ent.GetHierarchyParent();
					if (parent && parent.GetInventory().HasInventorySlot(slotId))
					{
						//Print("CanReceiveAttachment | parent " + parent + " matches in slot name: " + InventorySlots.GetSlotName(slotId) + " of " + this);
						return false;
					}
				}
			}
			
			ent = ent.GetHierarchyParent();
		}
		
		return super.CanReceiveAttachment(attachment, slotId);
	}
	
	override bool CanLoadAttachment(EntityAI attachment)
	{
		int slotId;
		for (int i = 0; i < attachment.GetInventory().GetSlotIdCount(); i++)
		{
			slotId = attachment.GetInventory().GetSlotId(i);
			if (GetInventory().HasAttachmentSlot(slotId))
			{
				InventoryLocation loc = new InventoryLocation();
				EntityAI ent = this;
				EntityAI parent;
				while (ent)
				{
					if (ent.GetInventory().GetCurrentInventoryLocation(loc) && loc.IsValid())
					{
						if (loc.GetType() == InventoryLocationType.CARGO)
						{
							parent = ent.GetHierarchyParent();
							if (parent.GetInventory().HasInventorySlot(slotId))
							{
								//Print("CanLoadAttachment | parent " + parent + " matches in slot name: " + InventorySlots.GetSlotName(slotId) + " of " + this);
								return false;
							}
						}
					}
					
					ent = ent.GetHierarchyParent();
				}
			}
		}
		
		return super.CanLoadAttachment(attachment);
	}
	
	//hands
	override bool CanPutIntoHands( EntityAI parent )
	{
		if ( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		if ( GetCompEM().IsSwitchedOn() )
		{
			return false;
		}
		
		return false;
	}	
	
	//================================================================
	// ITEM-TO-ITEM FIRE DISTRIBUTION
	//================================================================
	
	override bool IsIgnited()
	{
		return GetCompEM().IsWorking();
	}
	
	override bool CanIgniteItem(EntityAI ignite_target = NULL)
	{
		return GetCompEM().IsWorking();
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
		

		AddAction(ActionLightItemOnFire);
		AddAction(ActionTurnOnWhileOnGround);
		AddAction(ActionTurnOffWhileOnGround);
	}
}