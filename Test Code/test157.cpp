#include <QWidget>

class CustomToolWidget : public QWidget
{
public:
    CustomToolWidget(QWidget *parent = nullptr) : QWidget(parent)
    {
        setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
        setAttribute(Qt::WA_NoFocusChangeOnShow);
    }
};
