void BboxDrawer::DrawLabeledBox(cv::Mat image, const cnstream::CNInferObject &object,
                                 const std::string &label_text, const cv::Scalar &box_color) const {
  // Get the bounding box corners
  std::pair<cv::Point, cv::Point> bbox_corners = GetBboxCorner(object, image.cols, image.rows);
  
  // Draw the bounding box
  DrawBox(image, bbox_corners.first, bbox_corners.second, box_color);
  
  // Draw the label text
  cv::Point text_position(bbox_corners.first.x, bbox_corners.second.y);
  DrawText(image, text_position, label_text, box_color, text_scale_);
}
