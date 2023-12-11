void BboxDrawer::DrawLabeledBox(cv::Mat image, const cnstream::CNInferObject &object, const std::string &label_text,
                                const cv::Scalar &box_color) const {
  // Get the bounding box corner points
  std::pair<cv::Point, cv::Point> bbox_corners = GetBboxCorner(object, image.cols, image.rows);

  // Check if the label is found
  if (!LabelIsFound(object.label_id)) {
    return;
  }

  // Get the label ID
  int label_id = GetLabelId(object.label_id);

  // Calculate the thickness of the box
  int box_thickness = CalcThickness(image.cols, box_thickness_);

  // Draw the bounding box
  DrawBox(image, bbox_corners.first, bbox_corners.second, box_color, box_thickness);

  // Calculate the scale of the text
  double text_scale = CalcScale(image.cols, text_scale_);

  // Draw the label text
  int text_height = 0;
  DrawText(image, bbox_corners.second, label_text, box_color, text_scale, &text_height);

  // Draw the label text background
  cv::Rect text_rect(bbox_corners.second.x, bbox_corners.second.y - text_height,
                     text_scale * label_text.length(), text_height);
  cv::rectangle(image, text_rect, box_color, -1);
}
