#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

MatrixXf extract_batch_rois(int batch_idx, MatrixXf gt_boxes, MatrixXf all_rois) {
  // Initialize the output matrix
  MatrixXf batch_rois(0, 5);

  // Iterate over all ROIs
  for (int i = 0; i < all_rois.rows(); i++) {
    // Check if the current ROI belongs to the specified batch index
    if (all_rois(i, 0) == batch_idx) {
      // Add the ROI to the output matrix
      batch_rois.conservativeResize(batch_rois.rows() + 1, 5);
      batch_rois(batch_rois.rows() - 1, 0) = all_rois(i, 0);
      batch_rois(batch_rois.rows() - 1, 1) = all_rois(i, 1);
      batch_rois(batch_rois.rows() - 1, 2) = all_rois(i, 2);
      batch_rois(batch_rois.rows() - 1, 3) = all_rois(i, 3);
      batch_rois(batch_rois.rows() - 1, 4) = all_rois(i, 4);
    }
  }

  return batch_rois;
}
