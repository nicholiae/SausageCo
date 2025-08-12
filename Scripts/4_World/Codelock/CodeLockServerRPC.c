#ifdef CodeLock
modded class CodeLockServerRPC : PluginBase
{
    override void OpenTarget(ItemBase target)
    {
        TentBase tent = TentBase.Cast(target);
        if ((target.IsKindOf("SC_Openable_Base") || target.IsKindOf("SC_Openable_Placeable_Base") || target.IsKindOf("SC_Greenhouse_Base")) && !target.IsOpen())
            target.Open();
        super.OpenTarget(target);
    }
};
#endif