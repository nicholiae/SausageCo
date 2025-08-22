/**
 * SausageCo Skills System
 * Skill Book Base Class
 */

class SausageCo_SkillBook_Base extends ItemBase
{
    protected string m_SkillType;
    protected string m_BookTitle;
    protected string m_BookDescription;
    
    void SausageCo_SkillBook_Base()
    {
        m_SkillType = "";
        m_BookTitle = "Unknown Skill Book";
        m_BookDescription = "This book contains knowledge about various crafting recipes.";
    }
    
    string GetSkillType()
    {
        return m_SkillType;
    }
    
    string GetBookTitle()
    {
        return m_BookTitle;
    }
    
    string GetBookDescription()
    {
        return m_BookDescription;
    }
    
    override void SetActions()
    {
        super.SetActions();
        
        // Add the read action to this item
        AddAction(ActionReadSkillBook);
    }
}

// Engineering Skill Book
class SausageCo_SkillBook_Engineering extends SausageCo_SkillBook_Base
{
    void SausageCo_SkillBook_Engineering()
    {
        m_SkillType = SkillTypes.ENGINEERING;
        m_BookTitle = "Engineering Manual";
        m_BookDescription = "This book contains detailed instructions for various engineering projects and structures.";
    }
}
class SausageCo_EngineersTool extends SausageCo_SkillBook_Base
{
    void SausageCo_EngineersTool()
    {
        m_SkillType = SkillTypes.ENGINEERING;
        m_BookTitle = "Engineering Manual";
        m_BookDescription = "This book contains detailed instructions for various engineering projects and structures.";
    }
}

// Farming Skill Book
class SausageCo_SkillBook_Farming extends SausageCo_SkillBook_Base
{
    void SausageCo_SkillBook_Farming()
    {
        m_SkillType = SkillTypes.FARMING;
        m_BookTitle = "Farming Guide";
        m_BookDescription = "This book contains information about planting, growing, and harvesting various crops.";
    }
}

// Firearm Skill Book
class SausageCo_SkillBook_Firearm extends SausageCo_SkillBook_Base
{
    void SausageCo_SkillBook_Firearm()
    {
        m_SkillType = SkillTypes.FIREARM;
        m_BookTitle = "Firearm Handbook";
        m_BookDescription = "This book contains information about firearm maintenance, ammunition crafting, and weapon modifications.";
    }
}
class SausageCo_FirearmsTool extends SausageCo_SkillBook_Base
{
    void SausageCo_FirearmsTool()
    {
        m_SkillType = SkillTypes.FIREARM;
        m_BookTitle = "Firearm Handbook";
        m_BookDescription = "This book contains information about firearm maintenance, ammunition crafting, and weapon modifications.";
    }
}

// Leather Skill Book
class SausageCo_SkillBook_Leather extends SausageCo_SkillBook_Base
{
    void SausageCo_SkillBook_Leather()
    {
        m_SkillType = SkillTypes.LEATHER;
        m_BookTitle = "Leatherworking Guide";
        m_BookDescription = "This book contains techniques for tanning hides and crafting leather items.";
    }
}
class SausageCo_LeatherWorkersTool extends SausageCo_SkillBook_Base
{
    void SausageCo_LeatherWorkersTool()
    {
        m_SkillType = SkillTypes.LEATHER;
        m_BookTitle = "Leatherworking Guide";
        m_BookDescription = "This book contains techniques for tanning hides and crafting leather items.";
    }
}

// Mechanic Skill Book
class SausageCo_SkillBook_Mechanic extends SausageCo_SkillBook_Base
{
    void SausageCo_SkillBook_Mechanic()
    {
        m_SkillType = SkillTypes.MECHANIC;
        m_BookTitle = "Mechanic's Manual";
        m_BookDescription = "This book contains information about vehicle repair, maintenance, and part fabrication.";
    }
}

// Medic Skill Book
class SausageCo_SkillBook_Medic extends SausageCo_SkillBook_Base
{
    void SausageCo_SkillBook_Medic()
    {
        m_SkillType = SkillTypes.MEDIC;
        m_BookTitle = "Medical Handbook";
        m_BookDescription = "This book contains information about treating injuries, crafting medical supplies, and disease management.";
    }
}
class SausageCo_MedicsTool extends SausageCo_SkillBook_Base
{
    void SausageCo_MedicsTool()
    {
        m_SkillType = SkillTypes.MEDIC;
        m_BookTitle = "Medical Handbook";
        m_BookDescription = "This book contains information about treating injuries, crafting medical supplies, and disease management.";
    }
}

// Hunter Skill Book
class SausageCo_SkillBook_Hunter extends SausageCo_SkillBook_Base
{
    void SausageCo_SkillBook_Hunter()
    {
        m_SkillType = SkillTypes.HUNTER;
        m_BookTitle = "Hunter's Guide";
        m_BookDescription = "This book contains information about tracking, trapping, and processing game animals.";
    }
}

// Cook Skill Book
class SausageCo_SkillBook_Cook extends SausageCo_SkillBook_Base
{
    void SausageCo_SkillBook_Cook()
    {
        m_SkillType = SkillTypes.COOK;
        m_BookTitle = "Cooking Manual";
        m_BookDescription = "This book contains recipes for preparing and preserving various foods.";
    }
}