class SausageCoDoorItemBase : ItemBase
{
	private bool m_IsLocked = false;
	protected ref OpenableBehaviour m_OpenableSC;

	string GetOpenSoundSet(){ return "DoorWoodTowerOpen_SoundSet"; }
	string GetCloseSoundSet(){ return "DoorWoodTowerOpen_SoundSet"; }

	override bool IsBuilding()
	{
		return true;
	}
	
	void SausageCoDoorItemBase()
	{
		m_OpenableSC = new OpenableBehaviour(false);
		RegisterNetSyncVariableBool("m_OpenableSC.m_IsOpened");
		if (GetAnimationPhase("Doors1") == 1.0 && !m_OpenableSC.IsOpened())
			Close();
	}

	override void EEItemAttached( EntityAI item, string slot_name )
    {
        super.EEItemAttached( item, slot_name );
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
		SoundSynchRemote();
		UpdateVisualState();
	}

	override void Close()
	{
		m_OpenableSC.Close();
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
        return false;
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
		return IsOpen();
	}
	
	
    override bool CanUseConstruction()
    {
        return true;
    }
	
	override bool DisableVicinityIcon()
	{
		return true;
	}
	
	override bool IsInventoryVisible()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		vector playerPos = player.GetPosition();
		float distanceToLocation = vector.Distance(playerPos, this.GetPosition());
		return distanceToLocation < 3.0;
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
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        return super.CanReceiveAttachment(attachment, slotId);
    }
	override void SetActions()
	{
		super.SetActions();
        AddAction(ActionOpenSCDoors);
        AddAction(ActionCloseSCDoors);
	}
};
class SausageStorage_Shed : SausageCoDoorItemBase{};
class SausageBook_Storage : SausageCoDoorItemBase{};
