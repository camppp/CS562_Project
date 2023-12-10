base::string16 GetServiceProcessTerminateEventName() {
  return base::UTF8ToWide(
      GetServiceProcessScopedVersionedName(kTerminateEventSuffix));
}
