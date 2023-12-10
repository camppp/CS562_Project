#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> extractLogInfo(const string& logEntry) {
    unordered_map<string, string> info;
    string type, triggerName, storyboardName, filename;

    // Extract the type of log entry
    type = logEntry.substr(0, logEntry.find('('));

    // Extract the trigger name
    triggerName = logEntry.substr(logEntry.find('"') + 1, logEntry.find('"', logEntry.find('"') + 1) - logEntry.find('"') - 1);

    // Extract the storyboard name
    storyboardName = logEntry.substr(logEntry.find('"', logEntry.find('"') + 1) + 1, logEntry.find('"', logEntry.find('"', logEntry.find('"') + 1) + 1) - logEntry.find('"', logEntry.find('"') + 1) - 1);

    // Extract the filename
    filename = logEntry.substr(logEntry.find('"', logEntry.find('"', logEntry.find('"') + 1) + 1) + 1, logEntry.find('"', logEntry.find('"', logEntry.find('"', logEntry.find('"') + 1) + 1) + 1) - logEntry.find('"', logEntry.find('"', logEntry.find('"', logEntry.find('"') + 1) + 1) + 1) - 1);

    // Add the extracted information to the map
    info["type"] = type;
    info["triggerName"] = triggerName;
    info["storyboardName"] = storyboardName;
    info["filename"] = filename;

    return info;
}
