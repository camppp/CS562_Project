#include <iostream>
#include <Eigen/Dense>

Eigen::MatrixXf extract_batch_rois(int batch_idx, Eigen::MatrixXf gt_boxes, Eigen::MatrixXf all_rois) {
    // Count the number of ground truth boxes related to the current batch element
    auto batch_gt_boxes_count = (gt_boxes.col(0).array() == static_cast<float>(batch_idx)).count();

    // Create a matrix to store ground truth boxes related to the current batch element
    Eigen::MatrixXf batch_gt_boxes(batch_gt_boxes_count, gt_boxes.cols());
    for (Eigen::Index i = 0, j = 0; i < gt_boxes.rows(); ++i) {
        if (static_cast<int>(gt_boxes(i, 0)) == batch_idx)
            batch_gt_boxes.row(j++) = gt_boxes.row(i);
    }

    // Count the number of ROIs related to the current batch element
    auto batch_rois_count = (all_rois.col(0).array() == static_cast<float>(batch_idx)).count();

    // Create a matrix to store ROIs related to the current batch element
    Eigen::MatrixXf batch_rois(batch_rois_count, all_rois.cols() - 1);  // exclude batch index col
    for (Eigen::Index i = 0, j = 0; i < all_rois.rows(); ++i) {
        if (static_cast<int>(all_rois(i, 0)) == batch_idx)
            batch_rois.row(j++) = all_rois.row(i).rightCols(4);
    }

    return batch_rois;
}

int main() {
    Eigen::MatrixXf gt_boxes(5, 4);
    gt_boxes << 1, 2, 3, 4,
                2, 3, 4, 5,
                1, 2, 3, 4,
                2, 3, 4, 5,
                3, 4, 5, 6;

    Eigen::MatrixXf all_rois(8, 5);
    all_rois << 1, 10, 20, 30, 40,
                2, 15, 25, 35, 45,
                1, 12, 22, 32, 42,
                2, 17, 27, 37, 47,
                3, 11, 21, 31, 41,
                1, 14, 24, 34, 44,
                2, 19, 29, 39, 49,
                3, 16, 26, 36, 46;

    int batch_idx = 2;
    Eigen::MatrixXf batch_rois = extract_batch_rois(batch_idx, gt_boxes, all_rois);
    std::cout << "Batch ROIs related to batch index " << batch_idx << ":\n" << batch_rois << std::endl;

    return 0;
}
