#include <QWidget>

class medVector3DParameter
{
public:
    // Destructor
    ~medVector3DParameter()
    {
        // Release any resources held by the object
        // (if applicable)
    }

    // Method to retrieve the widget associated with the parameter
    QWidget* getWidget()
    {
        // Return the widget associated with the parameter
        return widget;
    }

    // Method to update internal widgets
    void updateInternWigets()
    {
        // Update internal widgets as required
        // (implementation required)
    }

private:
    QWidget* widget;
};
