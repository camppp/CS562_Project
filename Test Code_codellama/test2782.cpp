#include <android/procpartition.h>
#include <unistd.h>

namespace android {

struct PackageInfo {
    bool appIsOnProductImage;
    // Other package info members
};

struct AppInfo {
    std::string binaryPath;
    std::string appPackageName;
    bool appIsSystemApp;
    // Other app info members
};

class AppInfoFetcher {
public:
    AppInfoFetcher();

private:
    AppInfo appInfo;
};

AppInfoFetcher::AppInfoFetcher()
    : appInfo({.binaryPath = ::android::procpartition::getExe(getpid()),
               .appPackageName = "",
               .appIsSystemApp = false}) {
}

}  // namespace
