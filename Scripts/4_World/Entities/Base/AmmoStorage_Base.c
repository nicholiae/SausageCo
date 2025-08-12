class SC_AmmoStorage_Base : SC_Storage_Base 
{	
	void SC_AmmoStorage_Base()
	{
		m_AllowedSCCargo = {"Box_Base","Ammunition_Base"};
		m_SCCargoTagName = "isAmmunitionCargo";
	}
};