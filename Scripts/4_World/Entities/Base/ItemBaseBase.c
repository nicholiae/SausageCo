class SC_ItemBase : Container_Base
{
	protected ref array<string> m_AllowedSCCargo = { };
	protected string m_SCCargoTagName = "isMedicalItem";
	protected vector m_SCAdjustedPlacingPosition = "0 0 0";
	protected vector m_SCAdjustedPlacingOrientation = "0 0 0";
	protected vector m_HalfExtents;

	//synched vars
	protected bool m_HasStoredCargo = false;
	protected bool m_PrevHasStoredCargo = false;
	protected bool m_HasAutoStoreEnabled = false;
	protected bool m_HasAutoStoreOnCloseEnabled = false;
	protected bool m_VSInProgress = false;
	protected bool m_SCCanBeOpenedOrRestored = true;

	ref SC_Inventory m_SCInventory;
	protected bool m_StoreIsDirty = false;
	protected float m_LastCargoStoreUnixTime = 0;
    protected int m_AutoStoreTimerInSeconds = -1;
	protected bool m_HasAutoCloseEnabled = false;
    protected int m_AutoCloseTimerInSeconds = -1;
	protected float m_VSSCCheckTimer = 2000;
	protected PluginSCSettingsConfig SCSettings;

	void SC_ItemBase()
	{		
		RegisterNetSyncVariableBool("m_HasStoredCargo");
		RegisterNetSyncVariableBool("m_PrevHasStoredCargo");
		RegisterNetSyncVariableBool("m_HasAutoStoreEnabled");
		RegisterNetSyncVariableBool("m_HasAutoStoreOnCloseEnabled");
		RegisterNetSyncVariableBool("m_VSInProgress");
		RegisterNetSyncVariableBool("m_SCCanBeOpenedOrRestored");
		SC_DisableContainerDamage();
		m_HalfExtents = Vector(0.2,0.5,0.4);
	}

	void SC_DisableContainerDamage()
	{
		ProcessInvulnerabilityCheck(GetInvulnerabilityTypeString());
	}
	
	override string GetInvulnerabilityTypeString()
	{
		return "disableContainerDamage";
	}

	override void EEInit()
	{
		super.EEInit();
		
		SCSettings = PluginSCSettingsConfig.Cast(GetPlugin(PluginSCSettingsConfig));
		if(ConfigIsExisting("hasProxiesToHide") && ConfigGetBool("hasProxiesToHide"))
		{
			if(GetGame().IsClient())
			{
				if(GetSausageCompanyProxiesConfig())
				{
					// ShowHideSCProxies();
				}
				else
				{
					// GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.ShowHideSCProxies, 3000, true);	
				}
			}
			else
			{
				// ShowHideSCProxies();
			}	
		}
		#ifdef SERVER
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.LoadSCStoreVariables, 3000, false);
		#endif
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		#ifdef SERVER
		DeleteSCInventoryFile();
		#endif
	}

	void LoadSCStoreData()
	{
		if(IsSCVirtualStorageEnabled())
		{
			InitializeSCInventory();
		}
		else
		{			
			//restore after disabling it
			if(LoadSCInventoryFile())
			{				
				if(!m_HasStoredCargo)
				{
					m_PrevHasStoredCargo = true;
					m_HasStoredCargo = true;
					RestoreSCInventory(NULL);
				}
			}
		}
	}

	void LoadSCStoreVariables()
	{
		if(IsSCVirtualStorageEnabled())
		{
			SC_VirtualStorage_Settings vsSettings = SCSettings.GetSettings().VirtualStorage;
			if(vsSettings)
			{
				m_HasAutoStoreEnabled =  vsSettings.EnableAutoStoreTimer;
				m_AutoStoreTimerInSeconds = vsSettings.AutoStoreTimerInSeconds;
				SetSynchDirty();
			}			
		}
	}
	
    override bool CanPutIntoHands(EntityAI parent)
	{
		if (!super.CanPutIntoHands(parent))
		{
			return false;
		}
		if(HasStoredCargo())
		{
			return false;
		}

		return true;
    }
	
	override bool NameOverride(out string output)
	{
		if(HasStoredCargo())
		{
			string DisplayName;
			GetGame().ObjectGetDisplayName(this, DisplayName);	
			output = DisplayName + " [Stored]";
			return true;
		}
		return super.NameOverride(output);
	}
	
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		super.EEHealthLevelChanged(oldLevel,newLevel,zone);
		
		if (newLevel == GameConstants.STATE_RUINED && !GetHierarchyParent())
			MiscGameplayFunctions.DropAllItemsInInventoryInBounds(this, m_HalfExtents);
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		if (!super.CanPutInCargo(parent))
			return false;

		if (parent && (parent == this || (this.GetType() == parent.GetType())))
			return false;

		if(HasStoredCargo())
			return false;
		
		return true;
	}

	override bool CanReceiveItemIntoCargo (EntityAI item)
	{
		if (!super.CanReceiveItemIntoCargo(item))
			return false;

		if(HasStoredCargo())
			return false;

		if(IsOpen() && !GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT ))
		{
			if(ConfigIsExisting("hasCargoRestrictions") && ConfigGetBool("hasCargoRestrictions"))
			{
				return IsAllowedSCCargo(item) && super.CanReceiveItemIntoCargo(item);
			}
			return true;
		}

		return false;
	}
	
	override bool CanSwapItemInCargo(EntityAI child_entity, EntityAI new_entity)
	{
		if (!super.CanSwapItemInCargo(child_entity,new_entity))
			return false;

		if(HasStoredCargo())
			return false;

		if(ConfigIsExisting("hasCargoRestrictions") && ConfigGetBool("hasCargoRestrictions"))
		{
			if(IsAllowedSCCargo(child_entity) && IsAllowedSCCargo(new_entity))	
			{
				return true;
			}		
			return false;	
		}
		return true;
	}

	bool IsAllowedSCCargo(EntityAI item)
	{
		if(item.ConfigIsExisting(m_SCCargoTagName) && item.ConfigGetBool(m_SCCargoTagName))
		{
			return true;
		}
		
		return SC_Helper.IsAnyKindOf(item, m_AllowedSCCargo);
	}

	bool SC_CanBeOpenedOrRestored()
	{
		return m_SCCanBeOpenedOrRestored;
	}

	void DisableOpenOrRestore()
	{
		if(IsSCVirtualStorageEnabled())
		{
			m_SCCanBeOpenedOrRestored = false;	
			SetSynchDirty();	
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ResetCanBeOpenedOrRestored, m_VSSCCheckTimer, false);
		}
	}	

	void ResetCanBeOpenedOrRestored()
	{
		if(!m_SCCanBeOpenedOrRestored)
		{
			m_SCCanBeOpenedOrRestored = true;
			SetSynchDirty();
		}
	}

    bool IsSCFacingPlayer( PlayerBase player)
	{
		vector fence_pos = GetPosition();
		vector player_pos = player.GetPosition();
		vector ref_dir = GetDirection();
		
		//vector fence_player_dir = player_pos - fence_pos;
		vector fence_player_dir = player.GetDirection();
		fence_player_dir.Normalize();
		fence_player_dir[1] = 0; 	//ignore height
		
		ref_dir.Normalize();
		ref_dir[1] = 0;			//ignore height
		
		if ( ref_dir.Length() != 0 )
		{
			float angle = Math.Acos( fence_player_dir * ref_dir );
			
			if ( angle >= 1.3 )
			{
				return true;
			}
		}
		
		return false;
	}
		
	void ShowHideSCProxies()
	{		
		//Print("ShowHideSCProxies: called " + this);
		if(GetSausageCompanyProxiesConfig())
		{
			//Simple hidden selection state; 0 == hidden -> false == hidden		
			if(GetSausageCompanyProxiesConfig().HideAllProxiesWhenClosed && !IsOpen())
			{
				// SetSimpleHiddenSelectionState(0, false);
				// SetSimpleHiddenSelectionState(1, false);
				// SetSimpleHiddenSelectionState(2, false);
			}
			else
			{
				// SetSimpleHiddenSelectionState(0, ShouldHideWeaponsProxies());
				// SetSimpleHiddenSelectionState(1, ShouldHideClothesProxies());
				// SetSimpleHiddenSelectionState(2, ShouldHideOtherProxies());
			}
			
			//Print("ShowHideSCProxies: Config good " + this);
			if(GetGame().IsClient())
			{
				// GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(this.ShowHideSCProxies);
			}
		}
		else
		{						
			//Print("ShowHideSCProxies: Config bad " + this);
			// SetSimpleHiddenSelectionState(0, false);
			// SetSimpleHiddenSelectionState(1, false);
			// SetSimpleHiddenSelectionState(2, false);
		}
	}

	bool ShouldHideWeaponsProxies()
	{
		return !GetSausageCompanyProxiesConfig().HideWeaponProxies;
	}
	bool ShouldHideClothesProxies()
	{
		return !GetSausageCompanyProxiesConfig().HideClothingProxies;		
	}
	bool ShouldHideOtherProxies()
	{		
		return !GetSausageCompanyProxiesConfig().HideOtherProxies;
	}

    string GetNextInterchangeableItem()
    {
        return "";
    }
	bool SCSnapToCeiling()
	{
		return false;
	}

	float GetSCCeilingSnapPos()
	{
		return 0.0;
	}

	bool SCSnapToWall()
	{
		return false;
	}

	vector Get_ItemAdjustedPlacingPos()
	{	
		return m_SCAdjustedPlacingPosition;
	}
	
	void Set_ItemAdjustedPlacingPos(vector adjustedVector)
	{	
		m_SCAdjustedPlacingPosition = adjustedVector;
	}

	vector Get_ItemAdjustedPlacingOrientation()
	{
		return m_SCAdjustedPlacingOrientation;
	}

	void Set_ItemAdjustedPlacingOrientation(vector adjustedVector)
	{
		m_SCAdjustedPlacingOrientation = adjustedVector;
	}

	#ifdef RA_BASEBUILDING
    override float GetCostToUpkeep()
	{
		return 0.00001;
	}
	#endif

	override void OnStoreSave(ParamsWriteContext ctx)
    {
        super.OnStoreSave(ctx);
		//call store m_SCInventory
		if(m_StoreIsDirty && m_PrevHasStoredCargo != m_HasStoredCargo)
		{
			m_StoreIsDirty = false;
			//if prev we had cargo means we restored 
			if(m_PrevHasStoredCargo == true)
			{				
				DeleteSCInventoryFile();
				m_HasStoredCargo = false;
				m_PrevHasStoredCargo = false;
				m_LastCargoStoreUnixTime = 0;
				delete m_SCInventory;
				SetSynchDirty();
				return;
			}
			// if prev is false means we stored
			if(m_PrevHasStoredCargo == false)
			{
				SaveSCInventoryFile();
				m_HasStoredCargo = true;
				m_PrevHasStoredCargo = true;				
				m_LastCargoStoreUnixTime = 0;
			}
			delete m_SCInventory;
			SetSynchDirty();
		}
    }
	
	override void AfterStoreLoad()
	{
		super.AfterStoreLoad();
		LoadSCStoreData();
	}

	override void OnCEUpdate()
	{
		super.OnCEUpdate();
		AutoStoreSCCargo();
	}

	void ResetAutoSCTimer()
	{		
		m_LastCargoStoreUnixTime = 0;
	}

	void AutoStoreSCCargo()
	{
		if(IsSCAutoStoreOnCloseEnabled() && IsSCAutoCloseTimerEnabled())
		{
			return;
		}
		if(m_HasAutoStoreEnabled && CanStoreCargo())
		{
			m_LastCargoStoreUnixTime += m_ElapsedSinceLastUpdate;
			if(m_LastCargoStoreUnixTime >= m_AutoStoreTimerInSeconds)
			{
				ResetAutoSCTimer();
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StoreSCInventory, 0.02, false);
			}
		} 
		else
		{
			m_LastCargoStoreUnixTime = 0;
		}
	}

	void SC_LockInventory()
	{
		if(!SC_IsLocked())
		{
			GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
		}
	}

	void SC_UnlockInventory()
	{
		if(SC_IsLocked())
		{
			GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		}
	}

	bool SC_IsLocked()
	{
		return GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT );
	}

	//Virtual Storage
	bool IsSCVirtualStorageEnabled()
	{
		if(SCSettings && SCSettings.GetSettings())
		{
			SC_VirtualStorage_Settings settings = SCSettings.GetSettings().VirtualStorage;
			if(settings)
			{
				return settings.EnableVirtualStorage;
			}
		}
		return false;
	}

	bool IsSCAutoStoreOnCloseEnabled()
	{
		if(!IsSCVirtualStorageEnabled())
		{
			return false;
		}
		return m_HasAutoStoreOnCloseEnabled;
	}

	bool IsSCAutoCloseTimerEnabled()
	{
		return m_HasAutoCloseEnabled && !m_HasAutoStoreEnabled;
	}

	bool HasStoredCargo()
	{
		return m_HasStoredCargo;
	}

	bool CanStoreCargo()
	{
		if(GetInventory().IsInCargo())
		{
			return false;
		}
		if(IsVSBlackListed())
		{
			return false;
		}
		
		return !HasStoredCargo() && !IsSCInvEmpty();
	}

	protected bool IsVSBlackListed()
	{
		if(SCSettings && SCSettings.GetSettings())
		{
			SC_VirtualStorage_Settings settings = SCSettings.GetSettings().VirtualStorage;
			if(settings)
			{
				array<string> ContainerBlacklist = settings.ContainerBlacklist;
				return SC_Helper.IsAnyKindOf(this, ContainerBlacklist);
			}
		}
		return false;
	}

	bool CanDoVSStoreAction()
	{
		if(IsSCVirtualStorageEnabled())
		{
			if(HasStoredCargo())
			{
				return false;
			}
			if(m_HasAutoStoreOnCloseEnabled)
			{
				return false;
			}
			return true;
		}
		return false;
	}

	bool CanDoVSRestoreAction()
	{
		if(IsSCVirtualStorageEnabled())
		{
			if(HasStoredCargo() && IsOpen())
			{
				return true;
			}
		}
		return false;
	}

	override bool IsSCDismantleAllowed()
	{   
		if(super.IsSCDismantleAllowed())
		{
			return !HasStoredCargo();
		}
		return false;
	}	

	void StoreSCInventory(PlayerBase player = null) 
	{	
		if(HasStoredCargo())
		{
			return;
		}
		m_VSInProgress = true;
		SetSynchDirty();
		ref array<string> blacklist;
		SC_VirtualStorage_Settings vsSettings = SCSettings.GetSettings().VirtualStorage;
		if(vsSettings)
		{
			blacklist = vsSettings.ItemsBlacklist;
		}
		string item = "";
		if(!SC_Helper.CheckItemInventory(this, blacklist, item))
		{
			string reason = SC_Helper.GetDate() + ": The item has the following blacklisted item in inventory." + " " + item;
			if(player)
			{
				SC_Helper.SendMessageToClient(player, reason);
			}
			else
			{
				reason = SC_Helper.GetDate() + ": The item " + this + " has the following blacklisted item in inventory." + " " + item;
				//Print(reason);
			}
			
			return;
		}
		DisableOpenOrRestore();
		m_SCInventory = new SC_Inventory();
		if(m_SCInventory.Store(this))
		{
			m_StoreIsDirty = true;
			SC_Helper.RemoveItemsInCargo(this);
			m_PrevHasStoredCargo = false;
			m_HasStoredCargo = true;
			if(IsOpen())
			{
				Close();
			}
			SC_LockInventory();
		}
		m_VSInProgress = false;
		SetSynchDirty();
	}

	
	override bool CanDisplayCargo()
	{
		if(m_VSInProgress)
		{
			return false;
		}
		return super.CanDisplayCargo();
	}

	void SetContainerAsStored()
	{
		m_PrevHasStoredCargo = true;
		m_HasStoredCargo = true;
		if(IsOpen())
		{
			Close();
		}
		SC_LockInventory();
		SetSynchDirty();
	}

	void RestoreSCInventory(PlayerBase player)
	{	
		if(!HasStoredCargo())
		{
			return;
		}
		m_VSInProgress = true;
		SetSynchDirty();
		if(!m_StoreIsDirty)
		{
			LoadSCInventoryFile();
		}
		if(m_SCInventory)
		{
			SC_UnlockInventory();
			if(m_SCInventory)
			{
				//added this here to ensure items get deleted if for some reason they remained in inventory on store.
				//to avoid dupes
				SC_Helper.RemoveItemsInCargo(this);
				if(!m_SCInventory.Restore(this, player) && player)
				{
					GetGame().RPCSingleParam(player, SausageCompany_RPC.RPC_CLIENT_SHOWWARNINGUI, null, true, player.GetIdentity());
					string reason = string.Format("[SausageFramework] %1 (%2) One or multiple items have been dropped on the ground because they couldn't be restored in the inventory.", Object.GetDebugName(this), GetPosition());
					Error(reason);
				}
				m_PrevHasStoredCargo = true;
				m_HasStoredCargo = false;
				m_StoreIsDirty = true;
				if(IsOpen())
				{
					SC_UnlockInventory();
				}
				else
				{
					SC_LockInventory();
				}
				m_VSInProgress = false;
				SetSynchDirty();
				return;
			}
			SC_Helper.RemoveItemsInCargo(this);
			m_VSInProgress = false;
			SetSynchDirty();
			return;
		}
		m_VSInProgress = false;
		SetSynchDirty();
		delete m_SCInventory;
	}

	void InitializeSCInventory()
	{
		if(LoadSCInventoryFile())
		{				
			if(!m_HasStoredCargo)
			{
				m_PrevHasStoredCargo = true;
				m_HasStoredCargo = true;
				if(IsOpen())
				{
					Close();
				}
				SC_LockInventory();

				if(GetInventory().IsInCargo() || IsVSBlackListed())
				{
					RestoreSCInventory(NULL);
					return;
				}
				SetSynchDirty();
			}
		}
	}

	protected string GetFileName() 
	{
		int b1;
		int b2;
		int b3;
		int b4;
		string filename;
		GetPersistentID(b1, b2, b3, b4);
		filename = GetType()+ "_"+b1+"_"+b2+"_"+b3+"_"+b4;
		string folder = SC_Constants.ProfileFolder + SC_Constants.VSFolder + SC_Constants.VSEntityFolder;
		if (!FileExist(SC_Constants.ProfileFolder + SC_Constants.VSFolder))
			MakeDirectory(SC_Constants.ProfileFolder + SC_Constants.VSFolder);
		if (!FileExist(folder))
			MakeDirectory(folder);
		return folder + "/" + filename + ".json";
	}

	bool LoadSCInventoryFile() 
	{
		string filename = GetFileName();
		if(!FileExist(filename))
		{
			return false;
		}
		m_SCInventory = new SC_Inventory();
		JsonFileLoader<SC_Inventory>.JsonLoadFile(filename, m_SCInventory);
		return true;
	}

	void SaveSCInventoryFile() 
	{
		SC_Helper.RemoveItemsInCargo(this);
		JsonFileLoader<SC_Inventory>.JsonSaveFile(GetFileName(), m_SCInventory);
	}

	void DeleteSCInventoryFile()
	{
		string fileName = GetFileName();
		if (FileExist(fileName))
		{
			DeleteFile(fileName);
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)	
	{
		super.EEItemAttached(item, slot_name);
		ResetAutoSCTimer();
	}	
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		ResetAutoSCTimer();
	}	

	override void EECargoIn(EntityAI item)
	{
		super.EECargoIn(item);
		ResetAutoSCTimer();
	}

	override void EECargoOut(EntityAI item)
	{
		super.EECargoOut(item);
		ResetAutoSCTimer();
	}

	override void EECargoMove(EntityAI item)
	{
		super.EECargoMove(item);
		ResetAutoSCTimer();
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionSCVSStoreContents);
		AddAction(ActionSCVSRestoreContents);
	}
};