#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Kernel information for the NMS algorithm
const int FAST_NMS_K = 3;
const int FAST_NMS_KN = 2;

// Function to perform NMS on a list of bounding boxes
vector<BoundingBox> nms(vector<BoundingBox> boxes, float threshold) {
    // Sort the bounding boxes based on their confidence scores in descending order
    sort(boxes.begin(), boxes.end(), [](const BoundingBox& a, const BoundingBox& b) {
        return a.confidence > b.confidence;
    });

    // Initialize an empty list to hold the selected bounding boxes
    vector<BoundingBox> selected;

    // Iterate through the sorted list of bounding boxes
    for (int i = 0; i < boxes.size(); i++) {
        // Calculate the area of overlap with all previously selected bounding boxes
        float overlap = 0.0f;
        for (int j = 0; j < selected.size(); j++) {
            overlap += calculateOverlap(boxes[i], selected[j]);
        }

        // If the overlap area exceeds the threshold, discard the current bounding box
        if (overlap > threshold) {
            continue;
        }

        // Otherwise, add the current bounding box to the selected list
        selected.push_back(boxes[i]);
    }

    return selected;
}

// Function to calculate the area of overlap between two bounding boxes
float calculateOverlap(const BoundingBox& a, const BoundingBox& b) {
    // Calculate the intersection area between the two bounding boxes
    float intersection = max(0.0f, min(a.x + a.w, b.x + b.w) - max(a.x, b.x)) *
                         max(0.0f, min(a.y + a.h, b.y + b.h) - max(a.y, b.y));

    // Calculate the union area between the two bounding boxes
    float union_ = (a.w * a.h) + (b.w * b.h) - intersection;

    // Return the overlap area as the intersection area over the union area
    return intersection / union_;
}
