modded class MissionServer {
    SausageMiningConfig m_SausageMiningConfig;

    override void OnInit() {
        super.OnInit();

        this.m_SausageMiningConfig = SausageMiningConfig.Cast(GetPlugin(SausageMiningConfig));
        if (this.m_SausageMiningConfig) {
            this.m_SausageMiningConfig.LoadConfig();
            Print("[MissionServer] SausageMiningConfig initialized and loaded.");
        } else {
            Print("[MissionServer] ERROR: Failed to initialize SausageMiningConfig.");
        }
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
        super.InvokeOnConnect(player, identity);

        if (m_SausageMiningConfig) {
            m_SausageMiningConfig.sendToClient(identity);
            Print("[MissionServer] Sent mining configuration to client: " + identity.GetName());
        } else {
            Print("[MissionServer] ERROR: Failed to send mining configuration to client: " + identity.GetName());
        }
		
		#ifdef SERVER
			PluginSausageCompanyProxiesConfig proxies_config = PluginSausageCompanyProxiesConfig.Cast(GetPlugin(PluginSausageCompanyProxiesConfig));
			if(proxies_config)
			{
				proxies_config.Server_SendConfigToClient(player, identity);
			}
			PluginSausageCompanyCodelockConfig codelock_config = PluginSausageCompanyCodelockConfig.Cast(GetPlugin(PluginSausageCompanyCodelockConfig));
			if(codelock_config)
			{
				codelock_config.Server_SendConfigToClient(player, identity);
			}
			PluginSCSettingsConfig settings_config = PluginSCSettingsConfig.Cast(GetPlugin(PluginSCSettingsConfig));
			if(settings_config)
			{
				settings_config.Server_SendConfigToClient(player, identity);
			}
		#endif
    }
}