class CfgPatches
{
	class SC_sounds
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgSoundShaders
{
	class ZmbSC_Normal_Attack_SoundShader
	{
		samples[]=
		{
			
			{
				"SausageCo\zombies\sounds\Attack\attack",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\Attack\attack",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\Attack\attack",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\Attack\attack",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\Attack\attack",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\Attack\attack",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\Attack\attack",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\Attack\attack",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\Attack\attack",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\Attack\attack",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\Attack\attack",
				0.125
			}
		};
		volume=1;
		range=60;
	};
	class ZmbSC_Normal_LightHit_SoundShader
	{
		samples[]=
		{
			
			{
				"SausageCo\zombies\sounds\LightHit\lightHit",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\LightHit\lightHit",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\LightHit\lightHit",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\LightHit\lightHit",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\LightHit\lightHit",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\LightHit\lightHit",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\LightHit\lightHit",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\LightHit\lightHit",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\LightHit\lightHit",
				0.125
			}
		};
		volume=1;
		range=60;
	};
	class ZmbSC_Normal_HeavyHit_SoundShader
	{
		samples[]=
		{
			
			{
				"SausageCo\zombies\sounds\HeavyHit\heavy",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\HeavyHit\heavy",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\HeavyHit\heavy",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\HeavyHit\heavy",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\HeavyHit\heavy",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\HeavyHit\heavy",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\HeavyHit\heavy",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\HeavyHit\heavy",
				0.125
			}
		};
		volume=1;
		range=60;
	};
	class ZmbSC_Normal_CallToArmsShort_SoundShader
	{
		samples[]=
		{
			
			{
				"SausageCo\zombies\sounds\CTA\ES_Ghostly Howl",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\CTA\ES_Ghostly Howl",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\CTA\ES_Ghostly Howl",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\CTA\ES_Ghostly Howl",
				0.125
			},
			
			{
				"SausageCo\zombies\sounds\CTA\ES_Ghostly Howl",
				0.125
			}
		};
		volume=1;
		range=60;
	};
};
class CfgSoundSets
{
	class Zmb_VoiceFX_Base_SoundSet;
	class ZmbSC_Normal_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[]=
		{
			"ZmbSC_Normal_Attack_SoundShader"
		};
	};
	class ZmbSC_Normal_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[]=
		{
			"ZmbSC_Normal_CallToArmsShort_SoundShader"
		};
	};
	class ZmbSC_Normal_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[]=
		{
			"ZmbSC_Normal_HeavyHit_SoundShader"
		};
	};
	class ZmbSC_Normal_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[]=
		{
			"ZmbSC_Normal_LightHit_SoundShader"
		};
	};
};
