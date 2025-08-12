modded class AntiPestsSpray: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDisinfectPlantBit);
		AddAction(ActionDisinfectPlant);
		AddAction(ActionForceDrink);
		AddAction(ActionDrink);
	}
};
modded class CannabisSeeds : SeedBase {};
modded class PepperSeeds : SeedBase {};
modded class Plant_Cannabis : PlantBase {};
modded class Plant_Pepper : PlantBase {};
modded class Plant_Potato : PlantBase {};
modded class Plant_Pumpkin : PlantBase {};
modded class Plant_Tomato : PlantBase {};
modded class Plant_Zucchini : PlantBase {};
modded class PumpkinSeeds : SeedBase {};
modded class SeedBase : Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionPlantSeed);
	}
};
modded class TomatoSeeds : SeedBase {};
modded class ZucchiniSeeds : SeedBase {};
class SC_PotatoSeeds : SeedBase {};
class SC_PlumSeeds : SeedBase {};
class SC_AppleSeeds : SeedBase {};
class SC_OrangeSeeds : SeedBase {};
class SC_BananaSeeds : SeedBase {};
class SC_PearSeeds : SeedBase {};
class SC_CaninaBerrySeeds : SeedBase {};
class SC_SambucusBerrySeeds : SeedBase {};
class SC_KiwiSeeds : SeedBase {};
class egOCSds : SeedBase {};
class egOCSds1 : SeedBase {};
class egOCSds2 : SeedBase {};
class egOCSds3 : SeedBase {};
class egOCSds4 : SeedBase {};
class egOCSds5 : SeedBase {};
class SC_SausageSeeds : SeedBase {};
class SC_Cannabis_Alaskan_ThunderFuck_Seeds : SeedBase {};
class SC_Cannabis_GorillaGlue_Seeds : SeedBase {};
class SC_Cannabis_Trainwreck_Seeds : SeedBase {};
class SC_Cannabis_WhiteWidow_Seeds : SeedBase {};
class Plt_egOCPlt : PlantBase {};
class Plt_egOCPlt1 : PlantBase {};
class Plt_egOCPlt2 : PlantBase {};
class Plt_egOCPlt3 : PlantBase {};
class Plt_egOCPlt4 : PlantBase {};
class Plt_egOCPlt5 : PlantBase {};
class Plant_SC_Sausage : PlantBase {};
class Plant_SC_Potato : PlantBase {};
class Plant_SC_Banana : PlantBase {};
class Plant_SC_Orange : PlantBase {};
class Plant_SC_Pear : PlantBase {};
class Plant_SC_Apple : PlantBase {};
class Plant_SC_Plum : PlantBase {};
class Plant_SC_Kiwi : PlantBase {};
class Plant_SC_SambucusBerry : PlantBase {};
class Plant_SC_CaninaBerry : PlantBase {};
class Plant_SC_Cannabis_Alaskan_ThunderFuck : PlantBase {};
class Plant_SC_Cannabis_GorillaGlue : PlantBase {};
class Plant_SC_Cannabis_Trainwreck : PlantBase {};
class Plant_SC_Cannabis_WhiteWidow : PlantBase {};
