std::optional<RxEqualizerSettings> cmisRxEqualizerSettingOverride(const cfg::TransceiverOverrides& overrides) {
  // Check if CMIS transceiver overrides are present
  if (overrides.cmis_ref()) {
    // Check if Rx equalizer settings are available
    if (overrides.rxEqualizerSettings_ref()) {
      // Return Rx equalizer settings as an optional object
      return std::optional<RxEqualizerSettings>(overrides.rxEqualizerSettings_ref().value());
    }
  }

  // Return an empty optional object if Rx equalizer settings are not available
  return std::optional<RxEqualizerSettings>();
}
