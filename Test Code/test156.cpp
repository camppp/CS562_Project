#include <QEvent>
#include <QWidget>
#include <QApplication>
#include <QMouseEvent>

class CustomEvent : public QEvent {
public:
    CustomEvent(int scrollAmount) : QEvent(static_cast<QEvent::Type>(QEvent::User + 1)), m_scrollAmount(scrollAmount) {}

    int scrollAmount() const { return m_scrollAmount; }

private:
    int m_scrollAmount;
};

class CustomWidget : public QWidget {
public:
    CustomWidget(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    bool event(QEvent *event) override {
        if (event->type() == static_cast<QEvent::Type>(QEvent::User + 1)) {
            CustomEvent *customEvent = static_cast<CustomEvent*>(event);
            int scrollAmount = customEvent->scrollAmount();
            // Update widget state based on scroll amount
            // ...
            return true; // Event handled
        }
        return QWidget::event(event);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CustomWidget customWidget;
    customWidget.show();

    // Simulate the occurrence of CMScrolled event with a random scroll amount
    int randomScrollAmount = 50; // Replace with actual random scroll amount generation
    CustomEvent customEvent(randomScrollAmount);
    QCoreApplication::sendEvent(&customWidget, &customEvent);

    return app.exec();
}
