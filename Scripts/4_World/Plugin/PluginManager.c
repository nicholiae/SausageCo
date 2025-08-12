modded class PluginManager
{
    override void Init()
    {
        RegisterPlugin("PluginSausageCompanyProxiesConfig", true, true);
        RegisterPlugin("SausageMiningConfig", true, true);
        RegisterPlugin("PluginSausageCompanyCodelockConfig", true, true);
        RegisterPlugin("PluginSCSettingsConfig", true, true);
        super.Init();
    }
};