/**
 * Parses the time offset from the configuration parameter and creates an AbsoluteTimeOffset object.
 * @param confParam The configuration parameter representing the time offset
 * @return AbsoluteTimeOffset object representing the parsed time offset
 */
public static AbsoluteTimeOffset parseFromConf(String confParam) {
    long timeMillis = TimeUtils.parseTimeMillis(confParam);
    return new AbsoluteTimeOffset(timeMillis);
}