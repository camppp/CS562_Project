#include <QPushButton>
#include <QDialogButtonBox>

class MyWidget : public QWidget {
public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // Create the buttons and button box
        QPushButton *btn_deleteMeth = new QPushButton("Delete Method", this);
        QDialogButtonBox *btnbx = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);

        // Connect the button box's accepted signal to the handleAccept() method
        connect(btnbx, &QDialogButtonBox::accepted, this, &MyWidget::handleAccept);

        // Disable the btn_deleteMeth button when the button box is accepted
        connect(btnbx, &QDialogButtonBox::accepted, btn_deleteMeth, &QPushButton::setEnabled, false);
    }

    void handleAccept() {
        // Handle the button box's accepted signal
        qDebug() << "Button box accepted";
    }
};
