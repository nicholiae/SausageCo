class CfgPatches
{
	class SC_Weapons_Magazines
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
class CfgMagazines
{
	class DefaultMagazine;
	class Magazine_Base: DefaultMagazine
	{
		scope=0;
		storageCategory=1;
		inventorySlot[]=
		{
			"magazine",
			"magazine2",
			"magazine3"
		};
		repairableWithKits[]={1};
		repairCosts[]={25};
		handheld="true";
		armAction="Disarm";
		isMeleeWeapon=1;
		rotationFlags=17;
		quantityBar=0;
		itemSize[]={1,2};
		absorbency=0;
		recoilModifier[]={0.94999999,0.94999999,0.94999999};
		value=1;
		modelSpecial="";
		spawnDamageRange[]={0,0.60000002};
		enlargeInventoryView=0;
		useAction=0;
		useActionTitle="";
		reloadAction="";
		manipulationDamage=0.050000001;
		count=30;
		ammo="";
		ammoItems[]={};
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
		selectionFireAnim="zasleh";
		nameSound="magazine";
		soundUse="craft_rounds";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeFist";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeFist_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeFist_Heavy";
				range=2.8;
			};
		};
		class Reliability
		{
			ChanceToJam[]={0,0.0024999999,0.015,0.1,1};
		};
	};
	class SC_Mag_SCARL_100RndDrum: Magazine_Base
	{
		scope=2;
		displayName="SCAR-L 100Rnd Drum";
		descriptionShort="100Rnd Drum mag chambering 556x45 accepted by the SCAR-L";
		model="\DZ\weapons\attachments\magazine\magazine_akm_drum.p3d";
		rotationFlags=12;
		weight=14;
		itemSize[]={2,2};
		count=100;
		ammo="Bullet_762x39";
		inventorySlot[]=
		{
			"magazine",
			"magazine2",
			"magazine3",
			"Magazine556x45",
			"Magazine556x45_2"
		};
		ammoItems[]=
		{
			"Ammo_762x39",
			"Ammo_762x39Tracer"
		};
		tracersEvery=0;
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"DZ\weapons\attachments\data\magazine_drum_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\weapons\attachments\data\magazine_drum.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\attachments\data\magazine_drum.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\attachments\data\magazine_drum.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\attachments\data\magazine_drum_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\attachments\data\magazine_drum_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\attachments\data\magazine_drum_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet="MagRifle_fill_in_SoundSet";
					id=1;
				};
				class MagRifle_fill_loop
				{
					soundSet="MagRifle_fill_loop_SoundSet";
					id=2;
				};
				class MagRifle_fill_out
				{
					soundSet="MagRifle_fill_out_SoundSet";
					id=3;
				};
				class MagRifle_empty_in
				{
					soundSet="MagRifle_empty_in_SoundSet";
					id=4;
				};
				class MagRifle_empty_loop
				{
					soundSet="MagRifle_empty_loop_SoundSet";
					id=5;
				};
				class MagRifle_empty_out
				{
					soundSet="MagRifle_empty_out_SoundSet";
					id=6;
				};
				class MagPistol_fill_in
				{
					soundSet="MagPistol_fill_in_SoundSet";
					id=7;
				};
				class MagPistol_fill_loop
				{
					soundSet="MagPistol_fill_loop_SoundSet";
					id=8;
				};
				class MagPistol_fill_out
				{
					soundSet="MagPistol_fill_out_SoundSet";
					id=9;
				};
				class MagPistol_empty_in
				{
					soundSet="MagPistol_empty_in_SoundSet";
					id=10;
				};
				class MagPistol_empty_loop
				{
					soundSet="MagPistol_empty_loop_SoundSet";
					id=11;
				};
				class MagPistol_empty_out
				{
					soundSet="MagPistol_empty_out_SoundSet";
					id=12;
				};
			};
		};
	};
	class SC_Mag_SCARL_30Rnd: Magazine_Base
	{
		scope=2;
		displayName="SCAR-L 30Rnd Mag";
		descriptionShort="A 30Rnd Mag for the SCAR-L. Chambers in 556x45";
		model="SausageCo\Weapons\attachments\Magazine\SC_Mag_SCARL_30Rnd.p3d";
		weight=90;
		itemSize[]={1,1};
		count=30;
		ammo="Bullet_556x45";
		inventorySlot[]=
		{
			"magazine",
			"magazine2",
			"magazine3",
			"Magazine556x45",
			"Magazine556x45_2"
		};
		ammoItems[]=
		{
			"Ammo_556x45",
			"Ammo_556x45Tracer"
		};
		tracersEvery=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet="MagRifle_fill_in_SoundSet";
					id=1;
				};
				class MagRifle_fill_loop
				{
					soundSet="MagRifle_fill_loop_SoundSet";
					id=2;
				};
				class MagRifle_fill_out
				{
					soundSet="MagRifle_fill_out_SoundSet";
					id=3;
				};
				class MagRifle_empty_in
				{
					soundSet="MagRifle_empty_in_SoundSet";
					id=4;
				};
				class MagRifle_empty_loop
				{
					soundSet="MagRifle_empty_loop_SoundSet";
					id=5;
				};
				class MagRifle_empty_out
				{
					soundSet="MagRifle_empty_out_SoundSet";
					id=6;
				};
				class MagPistol_fill_in
				{
					soundSet="MagPistol_fill_in_SoundSet";
					id=7;
				};
				class MagPistol_fill_loop
				{
					soundSet="MagPistol_fill_loop_SoundSet";
					id=8;
				};
				class MagPistol_fill_out
				{
					soundSet="MagPistol_fill_out_SoundSet";
					id=9;
				};
				class MagPistol_empty_in
				{
					soundSet="MagPistol_empty_in_SoundSet";
					id=10;
				};
				class MagPistol_empty_loop
				{
					soundSet="MagPistol_empty_loop_SoundSet";
					id=11;
				};
				class MagPistol_empty_out
				{
					soundSet="MagPistol_empty_out_SoundSet";
					id=12;
				};
			};
		};
	};
	class SC_Mag_SCARL_60Rnd: Magazine_Base
	{
		scope=2;
		displayName="SCAR-L 60Rnd Mag";
		descriptionShort="60Rnd Drum mag chambering 556x45 accepted by the SCAR-L";
		model="SausageCo\Weapons\attachments\Magazine\SC_Mag_SCARL_60Rnd.p3d";
		weight=180;
		itemSize[]={1,2};
		count=60;
		ammo="Bullet_556x45";
		inventorySlot[]=
		{
			"magazine",
			"magazine2",
			"magazine3",
			"Magazine556x45",
			"Magazine556x45_2"
		};
		ammoItems[]=
		{
			"Ammo_556x45",
			"Ammo_556x45Tracer"
		};
		tracersEvery=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\attachments\data\m4_mag.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\attachments\data\m4_mag.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						},
						
						{
							0,
							
							{
								"SausageCo\Weapons\data\ScarL.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet="MagRifle_fill_in_SoundSet";
					id=1;
				};
				class MagRifle_fill_loop
				{
					soundSet="MagRifle_fill_loop_SoundSet";
					id=2;
				};
				class MagRifle_fill_out
				{
					soundSet="MagRifle_fill_out_SoundSet";
					id=3;
				};
				class MagRifle_empty_in
				{
					soundSet="MagRifle_empty_in_SoundSet";
					id=4;
				};
				class MagRifle_empty_loop
				{
					soundSet="MagRifle_empty_loop_SoundSet";
					id=5;
				};
				class MagRifle_empty_out
				{
					soundSet="MagRifle_empty_out_SoundSet";
					id=6;
				};
				class MagPistol_fill_in
				{
					soundSet="MagPistol_fill_in_SoundSet";
					id=7;
				};
				class MagPistol_fill_loop
				{
					soundSet="MagPistol_fill_loop_SoundSet";
					id=8;
				};
				class MagPistol_fill_out
				{
					soundSet="MagPistol_fill_out_SoundSet";
					id=9;
				};
				class MagPistol_empty_in
				{
					soundSet="MagPistol_empty_in_SoundSet";
					id=10;
				};
				class MagPistol_empty_loop
				{
					soundSet="MagPistol_empty_loop_SoundSet";
					id=11;
				};
				class MagPistol_empty_out
				{
					soundSet="MagPistol_empty_out_SoundSet";
					id=12;
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxySC_Mag_SCARL_30Rnd: ProxyAttachment
	{
		scope=2;
		inventorySlot="magazine";
		model="SausageCo\Weapons\attachments\SC_Mag_SCARL_30Rnd.p3d";
	};
	class ProxySC_Mag_SCARL_60Rnd: ProxyAttachment
	{
		scope=2;
		inventorySlot="magazine";
		model="SausageCo\Weapons\attachments\SC_Mag_SCARL_60Rnd.p3d";
	};
};
