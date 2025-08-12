class SC_ZombieFemaleBase extends ZombieBase
{
	override bool IsMale()
	{
		return false;
	}
	
	override string CaptureSound()
	{
		return "ZmbSC_Normal_HeavyHit_SoundShader";
	}
	
	override string ReleaseSound()
	{
		return "ZmbSC_Normal_CallToArmsShort_SoundShader";
	}
};

class SC_ZmbF_Vurdalsk_Base extends SC_ZombieFemaleBase
{
};
class SC_ZmbF_FreshDead_Base extends SC_ZombieFemaleBase
{
};