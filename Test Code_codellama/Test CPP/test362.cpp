#include <QString>
#include <QList>

class TipsWidget {
public:
    TipsWidget(const QString &title, const QList<QString> &tips);
    void displayTips();

private:
    QString m_title;
    QList<QString> m_tips;
};

TipsWidget::TipsWidget(const QString &title, const QList<QString> &tips) :
    m_title(title),
    m_tips(tips)
{
}

void TipsWidget::displayTips() {
    // Display the title and tips in the user interface
    qDebug() << m_title;
    for (const QString &tip : m_tips) {
        qDebug() << tip;
    }
}

int main() {
    QList<QString> tips;
    tips << "输入消费者的手机号码；"
         << "本次的消费额度（应付）；"
         << "若消费者为新用户，系统将会自动替该用户注册，并将注册信息通过短信发送到用户到手机；";

    TipsWidget tipsWidget("消费者本次消费:", tips);
    tipsWidget.displayTips();

    return 0;
}
