c
void nms(int* keep_out, int* num_out, const float* boxes_host, int boxes_num,
         int boxes_dim, float nms_overlap_thresh, int device_id) {
  // Initialize the output arrays
  *num_out = 0;
  for (int i = 0; i < boxes_num; i++) {
    keep_out[i] = -1;
  }

  // Sort the bounding boxes by their confidence scores
  std::sort(boxes_host, boxes_host + boxes_num,
            [](const float* a, const float* b) {
              return a[4] > b[4];
            });

  // Iterate through the sorted bounding boxes
  for (int i = 0; i < boxes_num; i++) {
    // If the current box is not suppressed, add it to the output
    if (keep_out[i] == -1) {
      keep_out[i] = i;
      *num_out += 1;
    }

    // Iterate through the remaining bounding boxes
    for (int j = i + 1; j < boxes_num; j++) {
      // If the current box overlaps with the previous box, suppress the previous box
      if (overlap(boxes_host[i], boxes_host[j], nms_overlap_thresh)) {
        keep_out[j] = -1;
      }
    }
  }
}
