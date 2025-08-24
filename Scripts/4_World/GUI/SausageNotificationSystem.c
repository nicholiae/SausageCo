
/**
 * SausageNotificationSystem.c
 * 
 * This file creates a standalone notification system for the SausageCo mod
 * without modifying the base game's NotificationUI class.
 */

// Notification types for our custom system
enum SausageNotificationType
{
    INFO,
    SUCCESS,
    WARNING,
    ERROR
}

// Individual notification message class
class SausageNotificationMessage
{
    protected string m_Text;
    protected SausageNotificationType m_Type;
    protected float m_Duration;
    protected float m_TimeRemaining;
    protected float m_Alpha;
    protected Widget m_RootWidget;
    protected TextWidget m_TextWidget;
    protected ImageWidget m_BackgroundWidget;
    protected ImageWidget m_IconWidget;
    
    void SausageNotificationMessage(string text, SausageNotificationType type, float duration)
    {
        m_Text = text;
        m_Type = type;
        m_Duration = duration;
        m_TimeRemaining = duration;
        m_Alpha = 0;
        
        // Create the notification widget
        CreateWidget();
    }
    
    void ~SausageNotificationMessage()
    {
        if (m_RootWidget)
        {
            m_RootWidget.Unlink();
        }
    }
    
    void CreateWidget()
    {
        // Get the game's UI manager
        if (!GetGame() || !GetGame().GetWorkspace())
            return;
        
        // Create the root widget
        m_RootWidget = GetGame().GetWorkspace().CreateWidgets("SausageCo/GUI/layouts/Notification.layout");
        if (!m_RootWidget)
            return;
        
        // Position the widget in the top-right corner
        float screenW, screenH;
        GetGame().GetWorkspace().GetScreenSize(screenW, screenH);
        
        // Set initial position off-screen (will slide in)
        m_RootWidget.SetPos(screenW, 100);
        m_RootWidget.SetSize(300, 80);
        
        // Get the text and background widgets
        m_TextWidget = TextWidget.Cast(m_RootWidget.FindAnyWidget("NotificationText"));
        m_BackgroundWidget = ImageWidget.Cast(m_RootWidget.FindAnyWidget("NotificationBackground"));
        m_IconWidget = ImageWidget.Cast(m_RootWidget.FindAnyWidget("NotificationIcon"));
        
        if (m_TextWidget)
        {
            m_TextWidget.SetText(m_Text);
        }
        
        if (m_BackgroundWidget)
        {
            // Set background color based on notification type
            switch (m_Type)
            {
                case SausageNotificationType.SUCCESS:
                    m_BackgroundWidget.SetColor(ARGB(200, 0, 150, 0)); // Green
                    break;
                case SausageNotificationType.WARNING:
                    m_BackgroundWidget.SetColor(ARGB(200, 200, 150, 0)); // Yellow
                    break;
                case SausageNotificationType.ERROR:
                    m_BackgroundWidget.SetColor(ARGB(200, 150, 0, 0)); // Red
                    break;
                default: // INFO
                    m_BackgroundWidget.SetColor(ARGB(200, 0, 100, 150)); // Blue
                    break;
            }
        }
        
        if (m_IconWidget)
        {
            // Set icon color based on notification type
            switch (m_Type)
            {
                case SausageNotificationType.SUCCESS:
                    m_IconWidget.SetColor(ARGB(255, 255, 255, 255)); // White
                    break;
                case SausageNotificationType.WARNING:
                    m_IconWidget.SetColor(ARGB(255, 255, 255, 0)); // Yellow
                    break;
                case SausageNotificationType.ERROR:
                    m_IconWidget.SetColor(ARGB(255, 255, 0, 0)); // Red
                    break;
                default: // INFO
                    m_IconWidget.SetColor(ARGB(255, 0, 200, 255)); // Blue
                    break;
            }
        }
        
        // Set initial alpha to 0 (invisible)
        m_RootWidget.SetAlpha(0);
    }
    
    bool Update(float timeslice)
    {
        if (!m_RootWidget)
            return false;
        
        // Update time remaining
        m_TimeRemaining -= timeslice;
        
        // Calculate target position
        float screenW, screenH;
        GetGame().GetWorkspace().GetScreenSize(screenW, screenH);
        float targetX = screenW - 320; // 20px margin from right edge
        
        // Get current position
        float currentX, currentY;
        m_RootWidget.GetPos(currentX, currentY);
        
        // Animation phases
        float newPosition;
        if (m_TimeRemaining > m_Duration - 0.5) // First 0.5 seconds: fade in and slide
        {
            // Fade in
            m_Alpha = Math.Min(1.0, m_Alpha + timeslice * 4); // Fade in over 0.25 seconds
            m_RootWidget.SetAlpha(m_Alpha);
            
            // Slide in
            newPosition = Math.Max(targetX, currentX - timeslice * 800); // Slide in over 0.5 seconds
            m_RootWidget.SetPos(newPosition, currentY);
        }
        else if (m_TimeRemaining < 0.5) // Last 0.5 seconds: fade out and slide
        {
            // Fade out
            m_Alpha = Math.Max(0.0, m_Alpha - timeslice * 4); // Fade out over 0.25 seconds
            m_RootWidget.SetAlpha(m_Alpha);
            
            // Slide out
            newPosition = Math.Min(screenW, currentX + timeslice * 800); // Slide out over 0.5 seconds
            m_RootWidget.SetPos(newPosition, currentY);
        }
        
        // Return true if the notification should be kept, false if it should be removed
        return m_TimeRemaining > 0;
    }
    
    // Getter methods for protected members
    Widget GetRootWidget()
    {
        return m_RootWidget;
    }
    
    void SetPosition(float x, float y)
    {
        if (m_RootWidget)
        {
            m_RootWidget.SetPos(x, y);
        }
    }
    
    vector GetPosition()
    {
        if (m_RootWidget)
        {
            float x, y;
            m_RootWidget.GetPos(x, y);
            return Vector(x, y, 0);
        }
        return Vector(0, 0, 0);
    }
}

// Main notification system class
class SausageNotificationSystem
{
    // Singleton instance
    private static ref SausageNotificationSystem m_Instance;
    
    // Array of active notifications
    private ref array<ref SausageNotificationMessage> m_Notifications;
    
    // Maximum number of notifications to show at once
    private const int MAX_NOTIFICATIONS = 5;
    
    // Get singleton instance
    static SausageNotificationSystem GetInstance()
    {
        if (!m_Instance)
        {
            m_Instance = new SausageNotificationSystem();
        }
        return m_Instance;
    }
    
    void SausageNotificationSystem()
    {
        m_Notifications = new array<ref SausageNotificationMessage>();
        
        // Register for updates
        GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.Update, 0, true);
    }
    
    void ~SausageNotificationSystem()
    {
        // Unregister from updates
        GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.Update);
        
        // Clear notifications
        ClearNotifications();
    }
    
    void AddNotification(string text, SausageNotificationType type = SausageNotificationType.INFO, float duration = 5.0)
    {
        // Log to script log
        Print("[SausageNotification] " + text);
        
        // Check if notifications should be suppressed
        if (SkillBookMenu.AreNotificationsSuppressed())
        {
            Print("[SausageNotification] Notifications suppressed by SkillBookMenu");
            return;
        }
        
        // Limit the number of notifications
        if (m_Notifications.Count() >= MAX_NOTIFICATIONS)
        {
            // Remove the oldest notification
            m_Notifications.RemoveOrdered(0);
        }
        
        // Create and add the new notification
        SausageNotificationMessage notification = new SausageNotificationMessage(text, type, duration);
        m_Notifications.Insert(notification);
        
        // Reposition all notifications
        RepositionNotifications();
    }
    
    void ClearNotifications()
    {
        m_Notifications.Clear();
    }
    
    void Update()
    {
        float timeslice = 0.016; // Approximately 60 FPS
        
        // Update all notifications
        for (int i = m_Notifications.Count() - 1; i >= 0; i--)
        {
            SausageNotificationMessage notification = m_Notifications.Get(i);
            if (notification)
            {
                // Update the notification and remove it if it's finished
                if (!notification.Update(timeslice))
                {
                    m_Notifications.RemoveOrdered(i);
                    
                    // Reposition remaining notifications
                    RepositionNotifications();
                }
            }
        }
    }
    
    void RepositionNotifications()
    {
        if (!GetGame() || !GetGame().GetWorkspace())
            return;
        
        float screenW, screenH;
        GetGame().GetWorkspace().GetScreenSize(screenW, screenH);
        
        // Position each notification from top to bottom
        for (int i = 0; i < m_Notifications.Count(); i++)
        {
            SausageNotificationMessage notification = m_Notifications.Get(i);
            if (notification)
            {
                vector pos = notification.GetPosition();
                
                // Set Y position based on index (100px for first notification, +90px for each additional)
                notification.SetPosition(pos[0], 100 + (i * 90));
            }
        }
    }
}

// Global helper function to show notifications from anywhere
static void ShowNotification(string text, SausageNotificationType type = SausageNotificationType.INFO, float duration = 5.0)
{
    // Always use our custom notification system
    SausageNotificationSystem.GetInstance().AddNotification(text, type, duration);
}

// For backward compatibility with existing code
class SausageNotification
{
    // Constants for notification types
    const static int TYPE_INFO = 0;
    const static int TYPE_SUCCESS = 1;
    const static int TYPE_WARNING = 2;
    const static int TYPE_ERROR = 3;
    
    // Show a notification using our new system
    static void Show(string message, int type = TYPE_INFO, float duration = 5.0)
    {
        // Convert the old type to the new enum
        SausageNotificationType newType = SausageNotificationType.INFO;
        switch (type)
        {
            case TYPE_SUCCESS:
                newType = SausageNotificationType.SUCCESS;
                break;
            case TYPE_WARNING:
                newType = SausageNotificationType.WARNING;
                break;
            case TYPE_ERROR:
                newType = SausageNotificationType.ERROR;
                break;
        }
        
        // Show the notification using our new system
        ShowNotification(message, newType, duration);
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
        // Use our notification system
        SausageNotification.Show(message, type, duration);
    }
}

// Helper class to check if the skill book menu is open
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
        // Use our notification system
        SausageNotification.Show(message, type, duration);
    }
}
