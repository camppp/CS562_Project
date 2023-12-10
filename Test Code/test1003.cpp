#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>

class MainWindow : public QMainWindow {
public:
    MainWindow() {
        QPushButton *button = new QPushButton("Click me", this);
        connect(button, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    }

public slots:
    void handleButtonClick() {
        QMessageBox::information(this, "Button Clicked", "Button clicked!");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
