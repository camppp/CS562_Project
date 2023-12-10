#include <QWidget>
#include <QPainter>
#include <vector>

class HistogramWidget : public QWidget {
public:
  void renderViews(const std::vector<int>& inputData) {
    // Calculate histogram data based on the input data
    std::vector<int> histogram(10, 0);  // Assuming 10 bins for simplicity

    // Populate the histogram bins based on the input data
    for (int value : inputData) {
      if (value >= 0 && value < 10) {
        histogram[value]++;
      }
    }

    // Determine the maximum frequency for scaling the histogram bars
    int maxFrequency = *std::max_element(histogram.begin(), histogram.end());

    // Define the dimensions and positioning for the histogram visualization
    int barWidth = width() / histogram.size();
    int barSpacing = 2;
    int x = 0;

    // Render the histogram visualization using QPainter
    QPainter painter(this);
    painter.setBrush(Qt::blue);  // Set the color for the histogram bars

    for (int frequency : histogram) {
      int barHeight = static_cast<int>(static_cast<double>(frequency) / maxFrequency * height());
      painter.drawRect(x, height() - barHeight, barWidth - barSpacing, barHeight);
      x += barWidth;
    }
  }

  void showEvent(QShowEvent* event) override {
    QWidget::showEvent(event);
    // Example input data for testing
    std::vector<int> inputData = {1, 3, 5, 7, 2, 4, 6, 8, 9, 1, 3, 5, 7, 2, 4, 6, 8, 9, 0, 2, 4, 6, 8, 9};
    renderViews(inputData);
  }
};
