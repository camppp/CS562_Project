void enable_features(nRF24L01+ &module, std::vector<Feature> features) {
  // Enable no-acknowledgment functionality
  if (std::find(features.begin(), features.end(), Feature::no_ack) != features.end()) {
    module.set_no_ack(true);
  }

  // Enable dynamic payload length functionality
  if (std::find(features.begin(), features.end(), Feature::dynamic_payload) != features.end()) {
    module.set_dynamic_payload(true);
  }

  // Enable Enhanced ShockBurst (ESB) mode
  if (std::find(features.begin(), features.end(), Feature::ESB) != features.end()) {
    module.set_ESB(true);
  }

  // Enable auto retransmit functionality
  if (std::find(features.begin(), features.end(), Feature::auto_retransmit) != features.end()) {
    module.set_auto_retransmit(true);
  }
}
