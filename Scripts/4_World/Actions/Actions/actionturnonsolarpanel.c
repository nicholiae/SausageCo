class ActionTurnOnSolarPanel: ActionInteractBase
{
    void ActionTurnOnSolarPanel()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_Text = "Turn On";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        SC_SolarPanel solarPanel = SC_SolarPanel.Cast(target.GetObject());
        if (!solarPanel)
            return false;
            
        return !solarPanel.GetCompEM().IsSwitchedOn() && solarPanel.HasSparkplug();
    }

    override void OnExecuteServer(ActionData action_data)
    {
        SC_SolarPanel solarPanel = SC_SolarPanel.Cast(action_data.m_Target.GetObject());
        if (solarPanel)
        {
            solarPanel.GetCompEM().SwitchOn();
        }
    }
}