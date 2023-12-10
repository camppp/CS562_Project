sharp
using System;

public class FormPropertiesManager
{
    private readonly Form _form;

    public FormPropertiesManager(Form form)
    {
        _form = form;
    }

    public void SetBool(string propertyName, bool value)
    {
        switch (propertyName)
        {
            case "MaximizeBox":
                _form.MaximizeBox = value;
                break;
            case "MinimizeBox":
                _form.MinimizeBox = value;
                break;
            case "Sizeable":
                _form.FormBorderStyle = value ? FormBorderStyle.Sizable : FormBorderStyle.FixedSingle;
                break;
            case "ToolWindow":
                _form.FormBorderStyle = value ? FormBorderStyle.FixedToolWindow : FormBorderStyle.Sizable;
                break;
            default:
                throw new ArgumentException("Invalid property name");
        }
    }

    public void SetFormName(string name)
    {
        _form.Text = name;
    }
}

// Usage example
Form form = new Form();
FormPropertiesManager propertiesManager = new FormPropertiesManager(form);
propertiesManager.SetBool("MaximizeBox", false);
propertiesManager.SetBool("MinimizeBox", false);
propertiesManager.SetBool("Sizeable", false);
propertiesManager.SetBool("ToolWindow", false);
propertiesManager.SetFormName("Noname");
