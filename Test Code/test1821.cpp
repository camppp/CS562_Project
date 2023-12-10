void TrafficLightPublishPanel::onSetTrafficLightState()
{
  const auto traffic_light_id = traffic_light_id_input_->value();
  const auto color = light_color_combo_->currentText();
  const auto shape = light_shape_combo_->currentText();
  const auto status = light_status_combo_->currentText();

  TrafficLight traffic_light;
  traffic_light.confidence = traffic_light_confidence_input_->value();

  if (color == "RED") {
    traffic_light.color = TrafficLight::RED;
  } else if (color == "GREEN") {
    traffic_light.color = TrafficLight::GREEN;
  } else if (color == "YELLOW") {
    traffic_light.color = TrafficLight::YELLOW;
  } else {
    // Handle invalid color input
    // For example, throw an exception or set a default color
  }

  if (shape == "CIRCLE") {
    traffic_light.shape = TrafficLight::CIRCLE;
  } else if (shape == "ARROW") {
    traffic_light.shape = TrafficLight::ARROW;
  } else if (shape == "SQUARE") {
    traffic_light.shape = TrafficLight::SQUARE;
  } else {
    // Handle invalid shape input
    // For example, throw an exception or set a default shape
  }

  if (status == "ON") {
    traffic_light.status = TrafficLight::ON;
  } else if (status == "OFF") {
    traffic_light.status = TrafficLight::OFF;
  } else {
    // Handle invalid status input
    // For example, throw an exception or set a default status
  }

  // Publish the traffic light's state
  publishTrafficLightState(traffic_light_id, traffic_light);
}
