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
        // (implementation required)
        return new QWidget(); // Example: Replace with actual widget creation
    }

    // Method to update internal widgets
    void updateInternWigets()
    {
        // Update internal widgets as required
        // (implementation required)
        // Example: Update internal widgets logic
    }
};
