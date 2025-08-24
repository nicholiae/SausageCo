
class ActionDeploySCVehicle: ActionDeployObject
{
    void ActionDeploySCVehicle()
    {
        m_Text = "#deploy_object";
    }
    
    override void OnEndServer(ActionData action_data)
    {
        if (!action_data || !action_data.m_MainItem || !action_data.m_MainItem.IsKindOf("SausageCo_Vehicle_Kit_Base"))
            return;
        
        // Cast first
        SausageCo_Vehicle_Kit_Base kit = SausageCo_Vehicle_Kit_Base.Cast(action_data.m_MainItem);
        
        if (!kit)
            return;
            
        // Store necessary information before deletion
        string vehicleType = kit.j_Vehicle();
        
        if (vehicleType == "" || vehicleType == "SausageCo_Vehicle_Kit_Base")
        {
            Error("[ActionDeploySCVehicle] Invalid vehicle type: " + vehicleType);
            return;
        }
        
        Print("[ActionDeploySCVehicle] Deploying vehicle: " + vehicleType);
        
        // Calculate position and orientation
        vector position = action_data.m_Player.GetPosition();
        vector direction = action_data.m_Player.GetDirection();
        position = position + (direction * 2); // 2 meters in front of player
        position[1] = GetGame().SurfaceY(position[0], position[2]) + 0.3; // Place slightly above ground
        
        vector orientation = action_data.m_Player.GetOrientation();
        
        // Delete the item
        GetGame().ObjectDelete(action_data.m_MainItem);
        
        // Create the vehicle using stored information
        Car vehicle = Car.Cast(GetGame().CreateObject(vehicleType, position, false, false, true));
        
        if (vehicle)
        {
            vehicle.SetOrientation(orientation);
            vehicle.SetHealth("", "", 1);
            vehicle.Fill(CarFluid.FUEL, vehicle.GetFluidCapacity(CarFluid.FUEL) * 0.2);
            Print("[ActionDeploySCVehicle] Successfully created vehicle: " + vehicleType);
        }
        else
        {
            Error("[ActionDeploySCVehicle] Failed to create vehicle: " + vehicleType);
        }
        
        // Call parent method for proper cleanup
        super.OnEndServer(action_data);
    }
}
