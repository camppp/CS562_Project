#include <QFile>
#include <QString>
#include <QImage>
#include <QSvgRenderer>
#include <QPainter>

class ImageRotator {
public:
    ImageRotator(const QString& pathToSourceSvgFolder, const QString& pathToRendedImageFolder, const QString& fileType, const QString& slash, const QString& svgType)
        : m_file(nullptr), m_pathToSourceSvgFolder(pathToSourceSvgFolder), m_pathToRendedImageFolder(pathToRendedImageFolder), m_fileType(fileType), m_slash(slash), m_svgType(svgType), m_image(QImage(497, 279, QImage::Format_RGB32)), m_renderer(nullptr), m_painter(nullptr), index(100), m_previousCharInArray(' ') {}

    ~ImageRotator() {
        if (m_file) {
            m_file->close();
        }
    }

    void loadSvgFile(const QString& fileName) {
        if (m_file) {
            m_file->close();
        }

        m_file = new QFile(fileName);
        if (!m_file->open(QIODevice::ReadOnly)) {
            qDebug() << "Error: Failed to open file" << fileName;
            return;
        }

        m_renderer = new QSvgRenderer(m_file->readAll());
        if (!m_renderer) {
            qDebug() << "Error: Failed to create renderer for file" << fileName;
            return;
        }
    }

    void renderImage() {
        if (!m_renderer) {
            qDebug() << "Error: No renderer available";
            return;
        }

        m_painter = new QPainter(&m_image);
        m_renderer->render(m_painter);
        m_painter->end();
    }

    void rotateImage(int angle) {
        if (!m_image.isNull()) {
            QImage rotatedImage = m_image.transformed(QTransform().rotate(angle));
            m_image = rotatedImage;
        }
    }

private:
    QFile* m_file;
    QString* m_pathToSourceSvgFolder;
    QString* m_pathToRendedImageFolder;
    QString* m_fileType;
    QString* m_slash;
    QString* m_svgType;
    QImage m_image;
    QSvgRenderer* m_renderer;
    QPainter* m_painter;
    int index;
    char m_previousCharInArray;
};
