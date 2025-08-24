modded class ActionDeployObject
{
    override void OnEndServer(ActionData action_data)
    {
		super.OnEndServer(action_data);
		
		ref array<string> m_MyKits = 
		{
			"SausageCo_Vehicle_ADA4x4Base_Kit","SausageCo_Vehicle_OlgaBase_Kit","SausageCo_Vehicle_GunterBase_Kit","SausageCo_Vehicle_SarkaBase_Kit",
			"SausageCo_PrefabHouse2_Kit","SausageCo_PrefabHouse1_Kit","SausageCo_PrefabHouse3_Kit","SausageCo_PrefabHouse3_Camo_Kit","SausageCo_PrefabHouse5_Kit",
			"SausageAnvil_Kit","SausageFurnace_Kit","SausageCo_Vehicle_HummerBase_Kit","SausageCo_Vehicle_M3SBase_Kit",
			"SausageBuilding_Storage_Kit","SausageBuilding_VendMachine_Kit","SausageBuilding_Sign0_Kit","SausageBuilding_Sign1_Kit","SausageCrateWood1_Storage_Kit","SausageCrateWood2_Storage_Kit",
			"SausageCrateWood3_Storage_Kit","SausageGear_Storage_Kit","SausageDecor_Picture1_Kit","SausageStorage_Shed_Kit","SausageGarden_CompostBin_Kit",
			"SausageBuilding_Well_Kit","SausageBathroom_Toilet_Kit","SausageBathroom_Sink_Kit","SausageBathroom_Cabinet_Kit","SausageBathroom_Bath_Kit",
			"SausageBuilding_WatchTower_Kit","SausageBedroom_Dressor_Kit","SausageBedroom_BunkBed_Kit","SausageBedroom_NightStand_Kit","SausageBedroom_Hopechest_Kit",
			"SausageLivingroom_Shelf_Kit","SausageLivingroom_EndTable_Kit","SausageLivingroom_CoffeeTable_Kit","SausageLivingroom_Couch_Kit",
			"SausageOffice_Computer_Kit","SausageOffice_Chair_Kit","SausageOffice_Desk_Kit","SausageOffice_Shelves_Kit",
			"SausageKitchen_Cabinets_Kit","SausageKitchen_Sink_Kit","SausageKitchen_Fridge_Kit","SausageKitchen_Stove_Kit",
			"SausageGarage_TrashCan_Kit","SausageAmmo_Packer_Kit","SausageGarden_Plot_Kit","SausageLights_Torch_Kit","SausageMedical_Tent_Kit",
			"SausageGarage_Gunrack_Kit","SausageCo_CasingsProcessor_Kit","SausageBuilding_DyerHouse_Kit","SausageBuilding_Smokehouse_Kit","SausageBook_Storage_Kit","SausageHelipad_Single_Kit",
			"SausageBuilding_GasPump_Kit","SausageBuilding_SignKind_Kit","SC_SolarPanel_Kit","SC_DryingRack_Kit","SausageWeed_Processor_Kit","SausagePlank_Processor_Kit"
		}
		for (int i = 0; i < m_MyKits.Count(); i++)
		{
			PlaceObjectActionData poActionData;
			string mykits = m_MyKits[i];
			if (action_data.m_MainItem.IsKindOf(mykits))
			{
				poActionData = PlaceObjectActionData.Cast(action_data);
				if (!poActionData.m_AlreadyPlaced)
				{
					EntityAI entity_for_placing = action_data.m_MainItem;
					GetGame().ClearJuncture(action_data.m_Player, entity_for_placing);
					action_data.m_MainItem.SetIsBeingPlaced(false);
				
					if (GetGame().IsMultiplayer())
					{
						action_data.m_Player.PlacingCancelServer();
						action_data.m_MainItem.SoundSynchRemoteReset();
					}
					else
					{
						action_data.m_Player.PlacingCancelLocal();
						action_data.m_Player.LocalTakeEntityToHands(entity_for_placing);
					}
				}
				else
				{
					GetGame().ObjectDelete(action_data.m_MainItem);
					action_data.m_MainItem.SetIsDeploySound(false);
					action_data.m_MainItem.SetIsPlaceSound(false);
					action_data.m_MainItem.SoundSynchRemoteReset();
				}
			}
			else
			{
				super.OnEndServer(action_data);

			}
		}
    }
}