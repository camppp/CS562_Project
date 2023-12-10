#include <iostream>
#include <vector>
#include <algorithm>

// Define a structure to represent a bounding box detection
struct BoundingBox {
    float x, y, width, height, score;
};

// Function to perform non-maximum suppression
std::vector<BoundingBox> nonMaximumSuppression(const std::vector<BoundingBox>& detections, float threshold) {
    // Sort the detections based on their scores in descending order
    std::vector<size_t> indices(detections.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(), [&detections](size_t i1, size_t i2) {
        return detections[i1].score > detections[i2].score;
    });

    // Initialize the suppression status of detections
    std::vector<bool> suppressed(detections.size(), false);

    // Apply non-maximum suppression
    for (size_t i = 0; i < detections.size(); ++i) {
        if (suppressed[indices[i]]) {
            continue;  // Skip suppressed detections
        }

        for (size_t j = i + 1; j < detections.size(); ++j) {
            if (suppressed[indices[j]]) {
                continue;  // Skip suppressed detections
            }

            // Calculate intersection over union (IoU) between bounding boxes
            float x1 = std::max(detections[indices[i]].x, detections[indices[j]].x);
            float y1 = std::max(detections[indices[i]].y, detections[indices[j]].y);
            float x2 = std::min(detections[indices[i]].x + detections[indices[i]].width, detections[indices[j]].x + detections[indices[j]].width);
            float y2 = std::min(detections[indices[i]].y + detections[indices[i]].height, detections[indices[j]].y + detections[indices[j]].height);
            float intersection = std::max(0.0f, x2 - x1) * std::max(0.0f, y2 - y1);
            float area1 = detections[indices[i]].width * detections[indices[i]].height;
            float area2 = detections[indices[j]].width * detections[indices[j]].height;
            float unionArea = area1 + area2 - intersection;
            float iou = intersection / unionArea;

            // Suppress overlapping detections
            if (iou > threshold) {
                suppressed[indices[j]] = true;
            }
        }
    }

    // Collect non-suppressed detections
    std::vector<BoundingBox> selectedDetections;
    for (size_t i = 0; i < detections.size(); ++i) {
        if (!suppressed[indices[i]]) {
            selectedDetections.push_back(detections[indices[i]]);
        }
    }

    return selectedDetections;
}

int main() {
    // Example usage
    std::vector<BoundingBox> detections = {
        {10, 10, 20, 20, 0.9},  // Example bounding box detections (x, y, width, height, score)
        {15, 15, 25, 25, 0.85},
        {8, 8, 18, 18, 0.95},
        {30, 30, 20, 20, 0.8}
    };

    float iouThreshold = 0.5;  // IoU threshold for non-maximum suppression
    std::vector<BoundingBox> selectedDetections = nonMaximumSuppression(detections, iouThreshold);

    // Output the selected detections after non-maximum suppression
    for (const auto& detection : selectedDetections) {
        std::cout << "Selected Detection: (x=" << detection.x << ", y=" << detection.y << ", width=" << detection.width << ", height=" << detection.height << ", score=" << detection.score << ")\n";
    }

    return 0;
}
