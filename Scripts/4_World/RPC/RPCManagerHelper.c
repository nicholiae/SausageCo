/*
 * SausageCo Skills System
 * RPC Manager Helper
 */

// This class ensures that the RPC manager is properly initialized
class RPCManagerHelper
{
    // Reference to the RPC manager
    private static ref RPCManager m_RPCManager;
    
    // Get the RPC manager
    static RPCManager GetRPCManager()
    {
        if (!m_RPCManager)
        {
            m_RPCManager = new RPCManager();
        }
        
        return m_RPCManager;
    }
}

// Override the GetRPCManager function to use our helper
static RPCManager GetRPCManager()
{
    return RPCManagerHelper.GetRPCManager();
}