#include <QFont>
#include <QFontDatabase>

class Theme {
public:
    void addCustomFont(const QString& fontPath) {
        QFontDatabase::addApplicationFont(fontPath);
    }

    QFont sansFont(int size) {
        return QFont("Ubuntu", size);
    }

    QFont monoFont(int size) {
        return QFont("Monospace", size);
    }
};
