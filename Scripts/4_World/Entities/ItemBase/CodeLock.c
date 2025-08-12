modded class CodeLock : ItemBase
{

    override void UnlockServer(notnull EntityAI player, EntityAI parent)
    {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
            return;

        SC_OpenableItem_Base baseItem = SC_OpenableItem_Base.Cast(parent);
        if (baseItem)
            baseItem.Open();

        super.UnlockServer(player, parent);
    }

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionAttachCodeLockToSC);
    }
};