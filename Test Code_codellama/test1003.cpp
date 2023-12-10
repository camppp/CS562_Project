#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void handleButtonClick();

private:
    QPushButton *button;
};

MainWindow::MainWindow()
{
    button = new QPushButton(this);
    button->setText("Click me!");
    connect(button, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
}

void MainWindow::handleButtonClick()
{
    QMessageBox::information(this, "Button clicked!", "The button was clicked.");
}
