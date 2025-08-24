
/**
 * Combined NotificationSystem implementation
 * Includes both the base notification system and modifications for the SausageCo mod
 */

// Define NotificationType enum if it's not already defined in your mod
enum NotificationType
{
    NOTIFY_SUCCESS,
    NOTIFY_WARNING,
    NOTIFY_ERROR,
    NOTIFY_INFO
}

// Base NotificationSystem class implementation
class NotificationSystem
{
    protected ref array<ref NotificationMessage> m_Messages;
    protected float m_DisplayTime = 5.0; // Default display time in seconds
    
    void NotificationSystem()
    {
        m_Messages = new array<ref NotificationMessage>();
    }
    
    void ~NotificationSystem()
    {
        ClearMessages();
    }
    
    // Original AddNotification method for our custom notification system
    void AddNotification(string message, int type = 0, float displayTime = -1)
    {
        NotificationMessage notification = new NotificationMessage(message, type, displayTime > 0 ? displayTime : m_DisplayTime);
        m_Messages.Insert(notification);
    }
    
    // Method for the base game's notification format
    void AddNotification(NotificationType type, float show_time, string header, string text, string icon = "")
    {
        // Check if the skill book menu is open using our helper
        if (SausageNotificationHelper.IsSkillBookMenuOpen())
        {
            // Use our safe notification system instead
            string fullMessage = header;
            if (text != "")
            {
                fullMessage = fullMessage + ": " + text;
            }
            
            // Convert notification type
            int safeType = SausageNotification.TYPE_INFO;
            switch (type)
            {
                case NotificationType.NOTIFY_SUCCESS:
                    safeType = SausageNotification.TYPE_SUCCESS;
                    break;
                case NotificationType.NOTIFY_WARNING:
                    safeType = SausageNotification.TYPE_WARNING;
                    break;
                case NotificationType.NOTIFY_ERROR:
                    safeType = SausageNotification.TYPE_ERROR;
                    break;
            }
            
            // Show notification using our safe system
            SausageNotification.Show(fullMessage, safeType, show_time);
            return;
        }
        
        // If skill book menu is not open, handle the notification
        // This would normally call super.AddNotification in a modded class
        // For now, we'll convert it to our custom notification format
        string combinedMessage = header;
        if (text != "")
        {
            combinedMessage = combinedMessage + ": " + text;
        }
        
        int customType = 0; // Default to info
        switch (type)
        {
            case NotificationType.NOTIFY_SUCCESS:
                customType = SausageNotification.TYPE_SUCCESS;
                break;
            case NotificationType.NOTIFY_WARNING:
                customType = SausageNotification.TYPE_WARNING;
                break;
            case NotificationType.NOTIFY_ERROR:
                customType = SausageNotification.TYPE_ERROR;
                break;
        }
        
        // Use our custom notification method
        AddNotification(combinedMessage, customType, show_time);
    }
    
    void ClearMessages()
    {
        m_Messages.Clear();
    }
    
    array<ref NotificationMessage> GetMessages()
    {
        return m_Messages;
    }
    
    void Update(float timeslice)
    {
        for (int i = m_Messages.Count() - 1; i >= 0; i--)
        {
            NotificationMessage message = m_Messages.Get(i);
            if (message)
            {
                message.Update(timeslice);
                if (message.IsExpired())
                {
                    m_Messages.RemoveOrdered(i);
                }
            }
        }
    }
}

class NotificationMessage
{
    protected string m_Message;
    protected int m_Type;
    protected float m_DisplayTime;
    protected float m_RemainingTime;
    
    void NotificationMessage(string message, int type, float displayTime)
    {
        m_Message = message;
        m_Type = type;
        m_DisplayTime = displayTime;
        m_RemainingTime = displayTime;
    }
    
    string GetMessage()
    {
        return m_Message;
    }
    
    int GetType()
    {
        return m_Type;
    }
    
    float GetRemainingTime()
    {
        return m_RemainingTime;
    }
    
    float GetProgress()
    {
        return 1.0 - (m_RemainingTime / m_DisplayTime);
    }
    
    bool IsExpired()
    {
        return m_RemainingTime <= 0;
    }
    
    void Update(float timeslice)
    {
        m_RemainingTime -= timeslice;
        if (m_RemainingTime < 0)
            m_RemainingTime = 0;
    }
}

// Helper class for checking if skill book menu is open
class SausageNotificationHelper
{
    static bool IsSkillBookMenuOpen()
    {
        // Implement the logic to check if the skill book menu is open
        // For example:
        // return GetGame().GetUIManager().IsMenuOpen(MENU_SKILLBOOK);
        return false; // Placeholder - replace with actual implementation
    }
}

// Custom notification class for safe notifications
class SausageNotification
{
    // Notification types
    static const int TYPE_INFO = 0;
    static const int TYPE_SUCCESS = 1;
    static const int TYPE_WARNING = 2;
    static const int TYPE_ERROR = 3;
    
    // Static method to show a notification
    static void Show(string message, int type = TYPE_INFO, float displayTime = 5.0)
    {
        // Get the notification system instance
        NotificationSystem notificationSystem = GetNotificationSystem();
        if (notificationSystem)
        {
            // Add the notification to the system
            notificationSystem.AddNotification(message, type, displayTime);
        }
        else
        {
            // Fallback if notification system isn't available
            Print("[SausageNotification] " + message);
        }
    }
    
    // Helper method to get the notification system instance
    private static NotificationSystem GetNotificationSystem()
    {
        // This would need to be implemented based on how you store/access your notification system
        // For example:
        // return SausageCo.GetInstance().GetNotificationSystem();
        
        // For now, create a new instance if needed
        return new NotificationSystem();
    }
}
