#include <QString>
#include <QFileInfo>

class ini_class {
public:
    bool file_exists(const QString &_file_path);
};

bool ini_class::file_exists(const QString &_file_path) {
    QFileInfo fileInfo(_file_path);
    return fileInfo.exists();
}
