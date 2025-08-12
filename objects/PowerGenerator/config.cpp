class CfgPatches
{
	class SC_PowerGeneration
	{
		units[]=
		{
			"SC_SolarPanel"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
    class Inventory_Base;
    class SC_SolarPanel: Inventory_Base
    {
        scope=2;
        displayName="SausageCo Solar Panel";
        descriptionShort="A solar-powered electrical generator that requires direct sunlight to function.";
        model="\SausageCo\objects\PowerGenerator\SC_SolarPanel.p3d";
        rotationFlags=2;
        slopeTolerance=0.4;
        yawPitchRollLimit[]={45,45,45};
        weight=45000;
        itemSize[]={10,10};
        itemBehaviour=0;
        attachments[]=
        {
            "CarBattery"
        };
        carveNavmesh=1;
        heavyItem=1;
        hiddenSelections[]=
        {
            "socket_1_plugged",
            "socket_2_plugged",
            "socket_3_plugged",
            "socket_4_plugged",
            "battery_installed",
            "placing"
        };
        hiddenSelectionsTextures[]=
        {
            "dz\gear\camping\data\plug_black_CO.paa",
            "dz\gear\camping\data\plug_yellow_CO.paa",
            "dz\gear\camping\data\plug_white_CO.paa",
            "dz\gear\camping\data\plug_orange_CO.paa",
            "\SausageCo\objects\PowerGenerator\Data\solarpanel_co.paa",
            "\SausageCo\objects\PowerGenerator\Data\solarpanel_co.paa"
        };
        hiddenSelectionsMaterials[]=
        {
            "dz\gear\camping\data\plug.rvmat",
            "dz\gear\camping\data\plug.rvmat",
            "dz\gear\camping\data\plug.rvmat",
            "dz\gear\camping\data\plug.rvmat",
            "\SausageCo\objects\PowerGenerator\Data\solarpanel.rvmat",
            "\SausageCo\objects\PowerGenerator\Data\solarpanel.rvmat"
        };
        hologramMaterial="power_generator";
        hologramMaterialPath="dz\gear\camping\data";
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=200;
                    healthLevels[]=
                    {
                        {
                            1,
                            {
                                "\SausageCo\objects\PowerGenerator\Data\solarpanel.rvmat"
                            }
                        },
                        {
                            0.7,
                            {
                                "\SausageCo\objects\PowerGenerator\Data\solarpanel.rvmat"
                            }
                        },
                        {
                            0.5,
                            {
                                "\SausageCo\objects\PowerGenerator\Data\solarpanel_damage.rvmat"
                            }
                        },
                        {
                            0.3,
                            {
                                "\SausageCo\objects\PowerGenerator\Data\solarpanel_damage.rvmat"
                            }
                        },
                        {
                            0,
                            {
                                "\SausageCo\objects\PowerGenerator\Data\solarpanel_destruct.rvmat"
                            }
                        }
                    };
                };
            };
        };
        class EnergyManager
        {
            hasIcon=1;
            autoSwitchOff=1;
            energyStorageMax=10000;
            energyUsagePerSecond=0.1;
            energyAtSpawn=5000;
            powerSocketsCount=4;
            compatiblePlugTypes[]={2,6};
        };
        class AnimationSources
        {
            class socket_1_plugged
            {
                source="user";
                animPeriod=0.01;
                initPhase=1;
            };
            class socket_2_plugged
            {
                source="user";
                animPeriod=0.01;
                initPhase=1;
            };
            class socket_3_plugged
            {
                source="user";
                animPeriod=0.01;
                initPhase=1;
            };
            class socket_4_plugged
            {
                source="user";
                animPeriod=0.01;
                initPhase=1;
            };
            class battery_installed
            {
                source="user";
                animPeriod=0.01;
                initPhase=1;
            };
            class placing
            {
                source="user";
                animPeriod=0.01;
                initPhase=0;
            };
        };
    };
	class SC_SolarPanel_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "SolarPanel HOLO";
		model="SausageCo\Objects\PowerGenerator\solarpanel.p3d";
	};
};