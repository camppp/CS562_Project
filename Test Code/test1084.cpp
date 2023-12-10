#include <Windows.UI.Xaml.Controls.Primitives.h>

using namespace Windows::UI::Xaml::Controls::Primitives;

public ref class CustomToggleButton sealed : ToggleButton
{
public:
    CustomToggleButton()
    {
        InitializeComponent();
    }

    property int CustomProperty
    {
        int get() { return (int)GetValue(CustomPropertyProperty); }
        void set(int value) { SetValue(CustomPropertyProperty, value); }
    }

    void OnToggle(Object^ sender, RoutedEventArgs^ e)
    {
        // Perform specific action when control is toggled
        // ...
    }

private:
    static void OnCustomPropertyChanged(DependencyObject^ d, DependencyPropertyChangedEventArgs^ e)
    {
        CustomToggleButton^ control = (CustomToggleButton^)d;
        control->OnPropertyChanged(e);
    }

    static void OnCustomPropertyCoerceValue(DependencyObject^ d, DependencyPropertyChangedEventArgs^ e)
    {
        CustomToggleButton^ control = (CustomToggleButton^)d;
        control->OnCoerceValue(e);
    }
};
