#include <iostream>
#include <string>
#include <vector>

class TrafficLight {
public:
    TrafficLight(std::string id, std::string color, std::string shape, std::string status, double confidence)
        : id_(id), color_(color), shape_(shape), status_(status), confidence_(confidence) {}

    std::string id_;
    std::string color_;
    std::string shape_;
    std::string status_;
    double confidence_;
};

class TrafficLightPublishPanel {
public:
    void onSetTrafficLightState() {
        std::string traffic_light_id = traffic_light_id_input_->value();
        std::string light_color = light_color_combo_->currentText();
        std::string light_shape = light_shape_combo_->currentText();
        std::string light_status = light_status_combo_->currentText();
        double traffic_light_confidence = traffic_light_confidence_input_->value();

        TrafficLight traffic_light(traffic_light_id, light_color, light_shape, light_status, traffic_light_confidence);

        // Set the shape and status of the traffic light based on the input
        if (light_shape == "circle") {
            traffic_light.shape_ = "circle";
        } else if (light_shape == "square") {
            traffic_light.shape_ = "square";
        } else if (light_shape == "triangle") {
            traffic_light.shape_ = "triangle";
        }

        if (light_status == "green") {
            traffic_light.status_ = "green";
        } else if (light_status == "yellow") {
            traffic_light.status_ = "yellow";
        } else if (light_status == "red") {
            traffic_light.status_ = "red";
        }

        // Publish the traffic light's state
        std::cout << "Traffic light state: " << traffic_light.id_ << " " << traffic_light.color_ << " " << traffic_light.shape_ << " " << traffic_light.status_ << " " << traffic_light.confidence_ << std::endl;
    }

private:
    std::string traffic_light_id_input_;
    std::string light_color_combo_;
    std::string light_shape_combo_;
    std::string light_status_combo_;
    double traffic_light_confidence_input_;
};
