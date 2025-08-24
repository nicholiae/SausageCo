
/**
 * This file contains a complete replacement for all notification-related code in the SausageCo mod.
 * It provides a safe notification system that doesn't rely on the base game's NotificationUI.
 */

// Safe notification utility class
class SausageNotification
{
    // Constants for notification types
    const static int TYPE_INFO = 0;
    const static int TYPE_SUCCESS = 1;
    const static int TYPE_WARNING = 2;
    const static int TYPE_ERROR = 3;
    
    // Show a notification safely without using NotificationUI
    static void Show(string message, int type = TYPE_INFO, float duration = 5.0)
    {
        // Log to script log
        Print("[SausageCo] " + message);
        
        // Use the game's chat system to display messages to the player
        // This is a safe way to show messages without using NotificationUI
        string prefix = "";
        switch (type)
        {
            case TYPE_SUCCESS:
                prefix = "[SUCCESS] ";
                break;
            case TYPE_WARNING:
                prefix = "[WARNING] ";
                break;
            case TYPE_ERROR:
                prefix = "[ERROR] ";
                break;
            default:
                prefix = "[INFO] ";
                break;
        }
        
        GetGame().Chat(prefix + message, "");
    }
}

// Replace all instances of SausageSkillsNotification with this implementation
class SausageSkillsNotification
{
    // Constants instead of enum to avoid conflicts
    const static int NOTIFICATION_PLAIN = 0;
    const static int NOTIFICATION_SUCCESS = 1;
    const static int NOTIFICATION_WARNING = 2;
    const static int NOTIFICATION_ERROR = 3;
    
    static void AddNotification(int type, float duration, string message)
    {
        // Use our safe notification system instead
        SausageNotification.Show(message, type, duration);
    }
}

// Instead of modding NotificationSystem directly, we'll create a helper class to check if the skill book menu is open
class SausageNotificationHelper
{
    // Check if the skill book menu is open
    static bool IsSkillBookMenuOpen()
    {
        if (GetGame() && GetGame().GetUIManager())
        {
            return GetGame().GetUIManager().IsMenuOpen(MENU_SAUSAGE_SKILLBOOK);
        }
        return false;
    }
    
    // Safe way to show a notification
    static void ShowNotification(string message, int type = 0, float duration = 5.0)
    {
        // Always use our safe notification system
        SausageNotification.Show(message, type, duration);
    }
}
