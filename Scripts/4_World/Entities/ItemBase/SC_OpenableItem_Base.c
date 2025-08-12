class SC_OpenableItem_Base : ItemBase
{
	private bool m_IsLocked = false;
	protected ref OpenableBehaviour m_OpenableSC;

	string GetOpenSoundSet(){ return "DoorWoodTowerOpen_SoundSet"; }
	string GetCloseSoundSet(){ return "DoorWoodTowerOpen_SoundSet"; }

	override bool IsContainer()
	{
        return true;
	}
	void SC_OpenableItem_Base()
	{
		m_OpenableSC = new OpenableBehaviour(false);
		RegisterNetSyncVariableBool("m_OpenableSC.m_IsOpened");
		if (GetAnimationPhase("Doors1") == 1.0 && !m_OpenableSC.IsOpened())
			Close();
	}

	override void EEItemAttached( EntityAI item, string slot_name )
    {
        super.EEItemAttached( item, slot_name );
        
        if ( item.IsInherited( SC_Padlock ) )
        {
            SC_Padlock sc_padlock = SC_Padlock.Cast( item );
            sc_padlock.Lock( this );
            Close();
        }
    }

	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
		
		ctx.Write( m_OpenableSC.IsOpened() );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		bool opened;
		if (!ctx.Read( opened ) )
		{
			Close();
			return false;
		}
		
		if ( opened )
		{
			Open();
		}
		else
		{
			Close();
		}
		
		return true;
	}

	override void Open()
	{
		m_OpenableSC.Open();
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		SoundSynchRemote();
		UpdateVisualState();
	}

	override void Close()
	{
		m_OpenableSC.Close();
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
		SoundSynchRemote();
		UpdateVisualState();		
	}

	override bool IsOpen()
	{
		return m_OpenableSC.IsOpened();
	}

	protected void UpdateVisualState()
    {
        if ( IsOpen() )
        {
            SetAnimationPhase("Doors1",1);
        }
        else
        {
            SetAnimationPhase("Doors1",0);
        }
    }

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		if ( IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
		{
			OpenSoundPlay();
		}
		
		if ( !IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
		{
			CloseSoundPlay();
		}
		
		UpdateVisualState();
	}
	
	void OpenSoundPlay()
	{		
        EffectSound sound = SEffectManager.PlaySound( GetOpenSoundSet() , GetPosition() );
		sound.SetSoundAutodestroy( true );
	}

	void CloseSoundPlay()
	{		
        EffectSound sound = SEffectManager.PlaySound( GetCloseSoundSet() , GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
    override bool CanPutInCargo( EntityAI parent )
	{
        return false;
    }
    override bool CanPutIntoHands( EntityAI parent )
    {
        return !IsLocked() && !IsOpen();
    }
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		return IsOpen();
	}
	
	override bool CanReleaseCargo(EntityAI attachment)
	{
		return IsOpen();
	}

    override bool CanDisplayAttachmentSlot(string slot_name)
	{		
		return true;
	}

	bool IsLocked()
    {
        SC_Padlock padlock = GetSC_Padlock();
        if ( padlock && padlock.IsLockedOnSC_OpenableItem_Base() )
        {            
            return true;
        }
        
        return false;
    }

	SC_Padlock GetSC_Padlock()
    {
        SC_Padlock padlock = SC_Padlock.Cast( FindAttachmentBySlotName( "Att_CombinationLock" ) );
        return padlock;
    }
	
    override bool CanUseConstruction()
    {
        return true;
    }
	
	override bool DisableVicinityIcon()
	{
		return true;
	}
	
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        CodeLock c_Lock;
        if (Class.CastTo(c_Lock, attachment))
            return true;

        return super.CanReceiveAttachment(attachment, slotId);
    }
	
	override bool IsInventoryVisible()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		vector playerPos = player.GetPosition();
		float distanceToLocation = vector.Distance(playerPos, this.GetPosition());
		return distanceToLocation && !IsLocked();
	}

	override void SetActions()
	{
		super.SetActions();
        AddAction(ActionOpenBuildingDoors);
        AddAction(ActionCloseBuildingDoors);
        AddAction(ActionInteractLockOnSC);
        AddAction(ActionManageLockOnSC);
        AddAction(ActionLockAdminOnSC);
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
};

class SC_LargeSafe : SC_OpenableItem_Base
{
	
};
class SC_SmallSafe : SC_OpenableItem_Base
{
	
};
class SC_AnimatedSafe : SC_OpenableItem_Base
{
	
};