#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QVector>
#include <QDebug>

class HistogramWidget : public QWidget
{
    Q_OBJECT

public:
    HistogramWidget(QWidget* parent = nullptr);
    ~HistogramWidget();

    void renderViews();

private:
    QVector<int> m_data;
    QPen m_pen;
    QBrush m_brush;
    QRect m_rect;
};

HistogramWidget::HistogramWidget(QWidget* parent) : QWidget(parent)
{
    m_pen = QPen(Qt::black, 2);
    m_brush = QBrush(Qt::gray);
    m_rect = QRect(0, 0, 500, 500);
}

HistogramWidget::~HistogramWidget()
{
}

void HistogramWidget::renderViews()
{
    QPainter painter(this);
    painter.setPen(m_pen);
    painter.setBrush(m_brush);
    painter.drawRect(m_rect);

    // Calculate the histogram data
    QVector<int> histogramData;
    for (int i = 0; i < m_data.size(); i++) {
        int value = m_data[i];
        if (histogramData.contains(value)) {
            histogramData[value]++;
        } else {
            histogramData.append(value);
        }
    }

    // Draw the histogram
    int x = 0;
    int y = 0;
    int width = m_rect.width() / histogramData.size();
    int height = m_rect.height();
    for (int i = 0; i < histogramData.size(); i++) {
        int value = histogramData[i];
        int barWidth = width * value;
        painter.fillRect(x, y, barWidth, height, m_brush);
        x += barWidth;
    }
}
