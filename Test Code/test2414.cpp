#include <QFile>
#include <QImage>
#include <QSvgRenderer>
#include <QPainter>

class ImageRotator : public QObject {
public:
    ImageRotator(const QString *pathToSourceSvg, const QString *pathToRendedImage, const QString *fileType, const QString *slash, const QString *svgType, QObject *parent)
        : QObject(parent)
        , m_file(new QFile())
        , m_pathToSourceSvgFolder(pathToSourceSvg)
        , m_pathToRendedImageFolder(pathToRendedImage)
        , m_fileType(fileType)
        , m_slash(slash)
        , m_svgType(svgType)
        , m_image(new QImage(497, 279, QImage::Format_RGB32))
        , m_renderer(new QSvgRenderer())
        , m_painter(new QPainter(m_image))
        , index(100)
        , m_previousCharInArray(' ')
    {
        // Constructor implementation
    }

    void loadSvgFile(const QString& fileName) {
        if (m_renderer->load(fileName)) {
            // Successfully loaded the SVG file
        } else {
            // Handle error: Unable to load the SVG file
        }
    }

    void renderImage() {
        m_painter->eraseRect(0, 0, m_image->width(), m_image->height());
        m_renderer->render(m_painter);
    }

    void rotateImage(int angle) {
        QTransform transform;
        transform.rotate(angle);
        *m_image = m_image->transformed(transform);
    }

    ~ImageRotator() {
        delete m_file;
        delete m_image;
        delete m_renderer;
        delete m_painter;
    }

private:
    QFile *m_file;
    QString *m_pathToSourceSvgFolder;
    QString *m_pathToRendedImageFolder;
    QString *m_fileType;
    QString *m_slash;
    QString *m_svgType;
    QImage *m_image;
    QSvgRenderer *m_renderer;
    QPainter *m_painter;
    int index;
    char m_previousCharInArray;
};
