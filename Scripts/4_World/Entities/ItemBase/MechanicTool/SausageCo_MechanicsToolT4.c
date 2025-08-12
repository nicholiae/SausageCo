class SausageCo_MechanicsTool extends ItemBase
{
	const string SOUND_BURNING 		= "Blowtorch_Loop_SoundSet";
	
	protected BlowtorchLight	m_Light;
	
	protected EffectSound 		m_SoundBurningLoop;

	override void OnWorkStart()
	{
		super.OnWorkStart();

		
		SoundBurningStart();
	}
	
	override void OnWorkStop()
	{
		#ifndef SERVER
		if (m_Light)
		{
			m_Light.FadeOut();
		}
		#endif
		
		RefreshFlameVisual(false);
		SoundBurningStop();
	}
	
	protected void RefreshFlameVisual(bool working = false)
	{
	    
	}
	
	protected void SoundBurningStart()
	{
		PlaySoundSetLoop(m_SoundBurningLoop, SOUND_BURNING, 0.1, 0.0);
	}
	
	protected void SoundBurningStop()
	{
		StopSoundSet(m_SoundBurningLoop);
	}	
	
	override bool CanPutInCargo(EntityAI parent)
	{
		return true;
	}
	
	override bool CanRemoveFromCargo(EntityAI parent)
	{
		return true;
	}
	
	override bool IsIgnited()
	{
		return GetCompEM().IsWorking();
	}
	
	override void OnIgnitedTarget(EntityAI target_item)
	{
		
	}
	
	override bool CanIgniteItem(EntityAI ignite_target = NULL)
	{
		return true;
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionRepairWithMechSkillCarEngine);
		AddAction(ActionRepairWithMechSkillCarPart);
		AddAction(ActionRepairWithMechSkilItem);
		AddAction(ActionRepairWithMechSkillCarChassis);
		AddAction(ActionFillFuel);
		AddAction(ActionFillGeneratorTank);
	}
	
	protected EntityAI GetGasCanister()
	{
		if (GetInventory().AttachmentCount() != 0)
		{
			return GetInventory().GetAttachmentFromIndex(0);
		}
		
		return null;
	}
	
	bool HasEnoughEnergyForRepair(float pTime)
	{
		return true;
	}
	
	override void OnDebugSpawn()
	{
		
	}
}

class SausageCo_MechanicsToolT4 extends Bottle_Base
{
	void SausageCo_MechanicsToolT4()
	{
		m_LiquidEmptyRate = 5000;
	}
	
	void ~SausageCo_MechanicsToolT4()
	{

	}
	
	override bool IsContainer()
	{
		return true;
	}
	
	override string GetPouringSoundset()
	{
		return "emptyVessle_CanisterGasoline_SoundSet";
	}
	
	override string GetEmptyingLoopSoundsetHard()
	{
		return "pour_HardGround_GasolineCanister_SoundSet";
	}
	
	override string GetEmptyingLoopSoundsetSoft()
	{
		return "pour_SoftGround_GasolineCanister_SoundSet";
	}
	
	override string GetEmptyingLoopSoundsetWater()
	{
		return "pour_Water_GasolineCanister_SoundSet";
	}
	
	override string GetEmptyingEndSoundsetHard()
	{
		return "pour_End_HardGround_GasolineCanister_SoundSet";
	}
	
	override string GetEmptyingEndSoundsetSoft()
	{
		return "pour_End_SoftGround_GasolineCanister_SoundSet";
	}
	
	override string GetEmptyingEndSoundsetWater()
	{
		return "pour_End_Water_GasolineCanister_SoundSet";
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}	
		if ( !(parent.IsKindOf("SausageCo_MechanicsTool"))/* && !(parent.IsKindOf("Container_Base"))*/)
		{
			return true;
		}
		
		return false;
	}
	
	override bool IsOpen()
	{
		return true;
	}
/*
	override void SetActions()
	{
//		super.SetActions();

		AddAction(ActionWorldLiquidActionSwitch);
		AddAction(ActionFillCoolant);
		AddAction(ActionFillFuel);
		AddAction(ActionFillGeneratorTank);
		AddAction(ActionExtinguishFireplaceByLiquid);
		AddAction(ActionFillBottleBase);
		AddAction(ActionWaterGardenSlot);
		AddAction(ActionWaterPlant);
		AddAction(ActionForceDrink);
		AddAction(ActionEmptyBottleBase);
		AddAction(ActionDrink);
		
	}
*/
}