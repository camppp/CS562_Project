#include <windows.h>
#include <base/strings/utf_string_conversions.h>

const char kTerminateEventSuffix[] = "_terminate";

std::wstring GetServiceProcessTerminateEventName() {
  std::string event_name = "service_process_";
  event_name += kTerminateEventSuffix;
  return base::UTF8ToWide(event_name);
}
