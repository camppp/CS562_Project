int compareVersions(int major1, int minor1, int patch1, int major2, int minor2, int patch2) {
    if (major1 < major2) {
        return -1;
    } else if (major1 > major2) {
        return 1;
    } else {
        if (minor1 < minor2) {
            return -1;
        } else if (minor1 > minor2) {
            return 1;
        } else {
            if (patch1 < patch2) {
                return -1;
            } else if (patch1 > patch2) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}
