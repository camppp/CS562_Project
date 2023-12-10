update_client::ActivityDataService* ChromeUpdateClientConfig::GetActivityDataService() const {
  return activity_data_service_.get();
}

bool ChromeUpdateClientConfig::IsPerUserInstall() const {
  return component_updater::IsPerUserInstall();
}
