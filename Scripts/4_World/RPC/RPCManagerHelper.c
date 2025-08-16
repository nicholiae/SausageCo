
/*
 * SausageCo Skills System
 * RPC Manager Helper
 */

// This class provides access to the RPC manager without overriding base game functions
class SausageSkillsRPCManager
{
    // Reference to the RPC manager
    private static ref RPCManager m_RPCManager;
    
    // Get the RPC manager
    static RPCManager GetRPCManager()
    {
        if (!m_RPCManager)
        {
            // Use the existing GetRPCManager function instead of creating a new one
            m_RPCManager = ::GetRPCManager();
            
            // Register our RPC handlers
            RegisterRPCHandlers();
        }
        
        return m_RPCManager;
    }
    
    // Register our RPC handlers
    static void RegisterRPCHandlers()
    {
        // Register server-side RPC handlers
        if (GetGame().IsServer())
        {
            SausageSkillsRPC.RegisterServerRPCs();
        }
        
        // Register client-side RPC handlers
        if (GetGame().IsClient())
        {
            SausageSkillsRPC.RegisterClientRPCs();
        }
    }
    
    // Helper method to send RPC
    static void SendRPC(string rpc_name, string rpc_type, Param param_data, bool guaranteed = true, PlayerIdentity target = NULL)
    {
        if (m_RPCManager)
        {
            m_RPCManager.SendRPC("SausageSkills", rpc_type, param_data, guaranteed, target);
        }
        else
        {
            // Use the global GetRPCManager if our instance is not initialized
            ::GetRPCManager().SendRPC("SausageSkills", rpc_type, param_data, guaranteed, target);
        }
    }
}

// Initialize the RPC manager when the script is loaded
void InitSausageSkillsRPC()
{
    // Get the RPC manager to initialize it
    SausageSkillsRPCManager.GetRPCManager();
}
