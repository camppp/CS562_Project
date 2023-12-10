#include <iostream>
#include <QString>
#include <QList>

class TipsWidget {
private:
    QString _title;
    QList<QString> _tips;

public:
    TipsWidget(const QString& title, const QList<QString>& tips) : _title(title), _tips(tips) {}

    void displayTips() {
        std::cout << "Title: " << _title.toStdString() << std::endl;
        std::cout << "Tips:" << std::endl;
        for (const QString& tip : _tips) {
            std::cout << tip.toStdString() << std::endl;
        }
    }
};

int main() {
    QString title = "消费者本次消费:";
    QList<QString> tips;
    tips << "输入消费者的手机号码；";
    tips << "本次的消费额度（应付）；";
    tips << "若消费者为新用户，系统将会自动替该用户注册，并将注册信息通过短信发送到用户到手机；";

    TipsWidget tipsWidget(title, tips);
    tipsWidget.displayTips();

    return 0;
}
