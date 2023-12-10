Status OptimizeDataFlow(Graph* graph) {
  // Initialize a map to store the device converters
  std::map<Device*, std::vector<Device*>> device_converters;

  // Iterate over the nodes in the graph
  for (auto&& node : graph->nodes) {
    // Check if the node has any outputs
    if (node.outputs.empty()) {
      continue;
    }

    // Iterate over the outputs of the node
    for (auto&& output : node.outputs) {
      // Check if the output is a dependency
      if (output.output_id == Node::kDependency) {
        continue;
      }

      // Get the source and destination devices for the output
      Device* src_device = node.arg.device;
      Device* dst_device = graph->nodes[output.node_id].arg.device;

      // Check if the source and destination devices are different
      if (src_device != dst_device) {
        // Check if a device converter already exists between the devices
        auto it = device_converters.find(src_device);
        if (it != device_converters.end() && it->second.contains(dst_device)) {
          // If a device converter already exists, use it
          output.device_converter = it->second[dst_device];
        } else {
          // Otherwise, create a new device converter
          XDL_CHECK_STATUS(CreateDeviceConverter(src_device, dst_device));
          output.device_converter = device_converters[src_device][dst_device];
        }
      }
    }
  }

  // Return the optimized graph
  return graph;
}
