/**
 * SausageCo Skills System
 * Forward declaration of SkillBookMenu for use in 4_World
 */

// Forward declaration of the SkillBookMenu class
class SkillBookMenu extends UIScriptedMenu
{
    // This is just a forward declaration to make the class visible to 4_World scripts
    // The actual implementation is in 5_Mission/GUI/SkillBookMenu.c
    
    void SetBookData(string skillType, string bookTitle, string bookDescription);
}