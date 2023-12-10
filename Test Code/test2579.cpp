void SearchGeolocationDisclosureTabHelper::RecordPreDisclosureMetrics(const GURL& gurl) {
  PrefService* prefs = GetProfile()->GetPrefs();
  if (!prefs->GetBoolean(prefs::kSearchGeolocationPreDisclosureMetricsRecorded)) {
    // Retrieve the permission status for geolocation for the given URL
    blink::mojom::PermissionStatus status = PermissionManager::Get(GetProfile())
        ->GetPermissionStatus(content::PermissionType::GEOLOCATION, gurl, gurl);
    // Record the permission status in a histogram
    UMA_HISTOGRAM_ENUMERATION("GeolocationDisclosure.PreDisclosurePermission",
                              static_cast<int>(status),
                              blink::mojom::PermissionStatus::NUM_PERMISSION_STATUS);
  }
}
