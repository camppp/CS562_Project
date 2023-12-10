#include <Windows.h>
#include <Windows.UI.Xaml.Controls.Primitives.h>

using namespace Windows::UI::Xaml::Controls::Primitives;

public ref class CustomToggleButton : ToggleButton
{
public:
    static property DependencyProperty^ CustomPropertyProperty
    {
        DependencyProperty^ get()
        {
            return customPropertyProperty;
        }
    }

    int get_CustomProperty()
    {
        return (int)GetValue(CustomPropertyProperty);
    }

    void set_CustomProperty(int value)
    {
        SetValue(CustomPropertyProperty, value);
    }

    virtual void OnToggle()
    {
        // Perform specific action when the control is toggled
    }

private:
    static DependencyProperty^ customPropertyProperty = DependencyProperty::Register(
        "CustomProperty",
        int::typeid,
        CustomToggleButton::typeid,
        ref new PropertyMetadata(0)
    );
};
