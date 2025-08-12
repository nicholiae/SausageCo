modded class DayZGame
{
    protected ref SBSConfig m_CheckSBSConfig;

    void setSBSGlobals(SBSConfig config)
    {
        m_CheckSBSConfig = config;
    }

    SBSConfig getSBSGlobals()
    {
        return m_CheckSBSConfig;
    }

};