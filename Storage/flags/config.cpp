class CfgPatches
{
	class SausageFlags_Storage
	{
		units[]=
		{
			
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Consumables",
			"DZ_Structures",
			"DZ_Scripts"
		};
	};
};
class CfgSlots
{
	
};
class CfgVehicles
{	
	class Inventory_Base;
	class Flag_Base: Inventory_Base
	{
		
	};
	class SausageFlag_Raven: Flag_Base
	{
		scope=2;
		displayName="The Raven Flag";
		descriptionShort="The Raven faction Flag";
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\storage\flags\RavenFlag\flag_Raven.paa"
		};
	};
	class SausageFlag_Killer: Flag_Base
	{
		scope=2;
		displayName="The Lost Flag";
		descriptionShort="The Lost faction Flag";
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\storage\flags\KillerFlag\flag_Killer.paa"
		};
	};
	class SausageFlag_Diman: Flag_Base
	{
		scope=2;
		displayName="The Diman Flag";
		descriptionShort="The Diman faction Flag";
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\storage\flags\DimanFlag\flag_Diman.paa"
		};
	};
	class SausageFlag_Smoke: Flag_Base
	{
		scope=2;
		displayName="The Smoke Flag";
		descriptionShort="The Smoke faction Flag";
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\storage\flags\SmokeFlag\flag_Smoke.paa"
		};
	};
	class SausageFlag_Calamity: Flag_Base
	{
		scope=2;
		displayName="The Celtic Alliance Flag";
		descriptionShort="The Celtic Alliance faction Flag";
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\storage\flags\CalamityFlag\flag_Calamity.paa"
		};
	};
	class SausageFlag_SausageCo: Flag_Base
	{
		scope=2;
		displayName="SausageCo Flag";
		descriptionShort="SausageCo official Flag";
		hiddenSelectionsTextures[]=
		{
			"\SausageCo\storage\flags\SausageFlag\flag_SausageCo.paa"
		};
	};
	class SausageCo_FlagCarrier: Inventory_Base
	{
		scope=2;
		displayName="SausageCo Flagpole";
		model="SausageCo\storage\flags\flagCarrier.p3d";
		itemSize[]={4,1};
		descriptionShort="SausageCo Flag Carrier Pole - run your heart out with this flag pole and be patriotic to what ever cause you choose with the flag attached!";
		attachments[]=
		{
			"Material_FPole_Flag",
			"SausageLight"
		};
		class GUIInventoryAttachmentsProps
		{
			class Flag
			{
				name="$STR_CfgVehicles_TerritoryFlag_Att_Category_Flag";
				description="";
				attachmentSlots[]=
				{
					"Material_FPole_Flag"
				};
				icon="tf_flag";
				selection="totem";
			};
			class Lights
			{
				name="Lights";
				description="";
				attachmentSlots[]=
				{
					"SausageLight"
				};
				icon="lightbulb";
				selection="light";
			};
		};
	};
};


class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxySausageCo_FlagCarrierFlag: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"Material_FPole_Flag"
		};
		model="SausageCo\storage\flags\proxies\SausageCo_FlagCarrierFlag.p3d";
		class AnimationSources
		{
			class folded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class unfolded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
	};
	class ProxySausageLight: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"SausageLight"
		};
		model="SausageCo\storage\flags\proxies\SausageLight.p3d";
	};
};