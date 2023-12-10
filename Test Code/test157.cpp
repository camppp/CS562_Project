#include <QWidget>
#include <Qt>

class CustomToolWidget : public QWidget {
public:
    CustomToolWidget(QWidget *parent) : QWidget(parent, Qt::Tool | Qt::FramelessWindowHint) {
        setAttribute(Qt::WA_ShowWithoutActivating); // Does not force focus changes upon showing
    }
};
