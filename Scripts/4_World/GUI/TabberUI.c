/*
 * SausageCo Skills System
 * TabberUI Implementation
 */

class TabberUI extends ScriptedWidgetEventHandler
{
    protected Widget m_Root;
    protected ref array<ref TabberUITab> m_Tabs;
    protected int m_SelectedTab;
    
    void TabberUI(Widget root)
    {
        m_Root = root;
        m_Tabs = new array<ref TabberUITab>();
        m_SelectedTab = -1;
    }
    
    void AddTab(string name, Widget content)
    {
        TabberUITab tab = new TabberUITab(name, content);
        m_Tabs.Insert(tab);
        
        // Create tab button
        ButtonWidget tabButton = ButtonWidget.Cast(GetGame().GetWorkspace().CreateWidgets("SausageCo\\GUI\\layouts\\tab_button.layout", m_Root));
        tabButton.SetText(name);
        tabButton.SetUserID(m_Tabs.Count() - 1);
        
        // Position the button
        float buttonWidth = 1.0 / Math.Max(1, m_Tabs.Count());
        float buttonX = buttonWidth * (m_Tabs.Count() - 1);
        tabButton.SetPos(buttonX, 0);
        tabButton.SetSize(buttonWidth, 1);
        
        // Set handler
        tabButton.SetHandler(this);
        
        // Select first tab by default
        if (m_SelectedTab == -1)
        {
            SelectTab(0);
        }
    }
    
    void SelectTab(int index)
    {
        if (index < 0 || index >= m_Tabs.Count())
            return;
            
        if (m_SelectedTab != -1)
        {
            m_Tabs[m_SelectedTab].GetContent().Show(false);
        }
        
        m_SelectedTab = index;
        m_Tabs[m_SelectedTab].GetContent().Show(true);
    }
    
    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w.GetTypeName() == "ButtonWidget")
        {
            ButtonWidget tabButton = ButtonWidget.Cast(w);
            int tabIndex = tabButton.GetUserID();
            
            SelectTab(tabIndex);
            return true;
        }
        
        return false;
    }
}

class TabberUITab
{
    protected string m_Name;
    protected Widget m_Content;
    
    void TabberUITab(string name, Widget content)
    {
        m_Name = name;
        m_Content = content;
        m_Content.Show(false);
    }
    
    string GetName()
    {
        return m_Name;
    }
    
    Widget GetContent()
    {
        return m_Content;
    }
}