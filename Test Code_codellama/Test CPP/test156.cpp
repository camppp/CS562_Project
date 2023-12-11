#include <QEvent>
#include <QWidget>

class CustomEvent : public QEvent
{
public:
    CustomEvent(int scrollAmount) : QEvent(QEvent::Type::CMScrolled), scrollAmount(scrollAmount) {}

    int scrollAmount() const { return scrollAmount; }

private:
    int scrollAmount;
};

class CustomWidget : public QWidget
{
public:
    CustomWidget(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void event(QEvent *event) override
    {
        if (event->type() == QEvent::Type::CMScrolled)
        {
            CustomEvent *customEvent = static_cast<CustomEvent *>(event);
            int scrollAmount = customEvent->scrollAmount();
            // Update widget's internal state based on scroll amount
            // ...
        }
    }
};
