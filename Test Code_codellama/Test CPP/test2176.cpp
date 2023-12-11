#include <QDebug>

void MyWidget::launch_button_toggled(bool checked)
{
    if (checked) {
        qDebug() << "Launching process...";
    } else {
        qDebug() << "Process aborted.";
    }
}
