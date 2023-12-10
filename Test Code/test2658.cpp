#include <QObject>
#include <QString>
#include <QDebug>

class OrnApplication : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString version READ version WRITE setVersion)
    Q_PROPERTY(QString developer READ developer WRITE setDeveloper)

public:
    QString name;
    QString version;
    QString developer;

    QString getName() const { return name; }
    void setName(const QString &appName) { name = appName; }

    QString getVersion() const { return version; }
    void setVersion(const QString &appVersion) { version = appVersion; }

    QString getDeveloper() const { return developer; }
    void setDeveloper(const QString &appDeveloper) { developer = appDeveloper; }

    Q_INVOKABLE void install() {
        qDebug() << "Installing " << name << " version " << version << " by " << developer;
        // Add installation logic here
    }

    Q_INVOKABLE void uninstall() {
        qDebug() << "Uninstalling " << name;
        // Add uninstallation logic here
    }
};
