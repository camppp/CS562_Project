AppInfoFetcher::AppInfoFetcher()
    : appInfo({.binaryPath = ::android::procpartition::getExe(getpid()),
               .appPackageName = "",
               .appIsSystemApp = false}) {
}
