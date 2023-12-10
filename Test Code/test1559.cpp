#include <rclcpp_components/register_node_macro.hpp>
#include "custom_node_component.hpp"  // Include the header file for CustomNodeComponent

// Define the C++ macro for registering the CustomNodeComponent
#define REGISTER_CUSTOM_NODE_COMPONENT(namespace, component_name) \
RCLCPP_COMPONENTS_REGISTER_NODE(namespace::component_name)

// Usage of the macro to register the CustomNodeComponent
REGISTER_CUSTOM_NODE_COMPONENT(custom_node_namespace, CustomNodeComponent)
