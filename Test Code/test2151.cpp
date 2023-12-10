void DateRange::fromJson(const QJsonObject& js)
{
    // Get the start and end dates from the JSON object
    QString start_date = js["start_date"].toString();
    QString end_date = js["end_date"].toString();

    // Convert the dates to QDateTime objects
    m_start_date = QDateTime::fromString(start_date, "yyyy-MM-ddThh:mm:ssZ");
    m_end_date = QDateTime::fromString(end_date, "yyyy-MM-ddThh:mm:ssZ");
}
