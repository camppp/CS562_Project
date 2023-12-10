public class FormProperties
{
    private bool _maximizeBox;
    private bool _minimizeBox;
    private bool _sizeable;
    private bool _toolWindow;
    private string _name;

    public FormProperties()
    {
        _maximizeBox = true;
        _minimizeBox = true;
        _sizeable = true;
        _toolWindow = false;
        _name = "My Form";
    }

    public bool MaximizeBox
    {
        get { return _maximizeBox; }
        set { _maximizeBox = value; }
    }

    public bool MinimizeBox
    {
        get { return _minimizeBox; }
        set { _minimizeBox = value; }
    }

    public bool Sizeable
    {
        get { return _sizeable; }
        set { _sizeable = value; }
    }

    public bool ToolWindow
    {
        get { return _toolWindow; }
        set { _toolWindow = value; }
    }

    public string Name
    {
        get { return _name; }
        set { _name = value; }
    }
}
