class TabStripModelObserver : public TabStripModelObserver {
 public:
  TabStripModelObserver() {}
  ~TabStripModelObserver() override {}

  void TabInsertedAt(TabStripModel* tab_strip_model,
                     content::WebContents* contents,
                     int index,
                     bool foreground) override {
    // Check if the window features have changed since the last observation.
    if (HasWindowFeaturesChanged()) {
      // Log the window metrics using the UKM system.
      LogWindowMetricsUkmEntry(GetWindowFeatures());
    }
  }

 private:
  // Data structure to store the last observed window features.
  std::optional<WindowFeatures> last_window_features_;

  // Method to check if the window features have changed since the last observation.
  bool HasWindowFeaturesChanged() {
    // Check if the window features have changed since the last observation.
    if (last_window_features_.has_value() &&
        GetWindowFeatures() != last_window_features_.value()) {
      return true;
    }
    return false;
  }

  // Method to get the current window features.
  WindowFeatures GetWindowFeatures() {
    // Get the current window features.
    WindowFeatures window_features = GetWindowFeaturesFromTabStripModel(tab_strip_model);
    return window_features;
  }

  // Method to log the window metrics using the UKM system.
  void LogWindowMetricsUkmEntry(const WindowFeatures& window_features) {
    // Create a new UKM entry.
    auto entry = ukm::builders::WindowMetrics();

    // Set the window features.
    entry.SetWindowFeatures(window_features);

    // Log the entry.
    ukm::LogEntry(entry);
  }
};
