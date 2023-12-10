void nms(int* keep_out, int* num_out, const float* boxes_host, int boxes_num,
         int boxes_dim, float nms_overlap_thresh, int device_id) {
    // Initialize an array to keep track of selected bounding boxes
    bool* selected = new bool[boxes_num];
    for (int i = 0; i < boxes_num; i++) {
        selected[i] = true;
    }

    // Sort the bounding boxes based on their confidence scores (in descending order)
    std::vector<int> sorted_indices(boxes_num);
    std::iota(sorted_indices.begin(), sorted_indices.end(), 0);
    std::sort(sorted_indices.begin(), sorted_indices.end(),
              [&boxes_host](int i, int j) { return boxes_host[i * boxes_dim + 4] > boxes_host[j * boxes_dim + 4]; });

    // Apply non-maximum suppression
    for (int i = 0; i < boxes_num; i++) {
        if (selected[sorted_indices[i]]) {
            for (int j = i + 1; j < boxes_num; j++) {
                if (selected[sorted_indices[j]]) {
                    float overlap = calculate_overlap(boxes_host, sorted_indices[i], sorted_indices[j]);
                    if (overlap > nms_overlap_thresh) {
                        selected[sorted_indices[j]] = false;
                    }
                }
            }
        }
    }

    // Store the indices of selected bounding boxes in keep_out
    int num_selected = 0;
    for (int i = 0; i < boxes_num; i++) {
        if (selected[i]) {
            keep_out[num_selected++] = i;
        }
    }

    // Update the number of selected bounding boxes
    *num_out = num_selected;

    // Clean up allocated memory
    delete[] selected;
}

// Function to calculate the overlap between two bounding boxes
float calculate_overlap(const float* boxes, int idx1, int idx2) {
    float x1 = std::max(boxes[idx1 * 5], boxes[idx2 * 5]);
    float y1 = std::max(boxes[idx1 * 5 + 1], boxes[idx2 * 5 + 1]);
    float x2 = std::min(boxes[idx1 * 5 + 2], boxes[idx2 * 5 + 2]);
    float y2 = std::min(boxes[idx1 * 5 + 3], boxes[idx2 * 5 + 3]);

    float intersection = std::max(0.0f, x2 - x1) * std::max(0.0f, y2 - y1);
    float area1 = (boxes[idx1 * 5 + 2] - boxes[idx1 * 5]) * (boxes[idx1 * 5 + 3] - boxes[idx1 * 5 + 1]);
    float area2 = (boxes[idx2 * 5 + 2] - boxes[idx2 * 5]) * (boxes[idx2 * 5 + 3] - boxes[idx2 * 5 + 1]);
    float union_area = area1 + area2 - intersection;

    return intersection / union_area;
}
