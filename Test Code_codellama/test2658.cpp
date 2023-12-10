#include <QObject>
#include <QString>

class OrnApplication : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString version READ version WRITE setVersion NOTIFY versionChanged)
    Q_PROPERTY(QString developer READ developer WRITE setDeveloper NOTIFY developerChanged)

public:
    OrnApplication(QObject *parent = nullptr);
    ~OrnApplication();

    QString name() const;
    void setName(const QString &name);

    QString version() const;
    void setVersion(const QString &version);

    QString developer() const;
    void setDeveloper(const QString &developer);

    void install();
    void uninstall();

signals:
    void nameChanged(const QString &name);
    void versionChanged(const QString &version);
    void developerChanged(const QString &developer);

private:
    QString m_name;
    QString m_version;
    QString m_developer;
};
