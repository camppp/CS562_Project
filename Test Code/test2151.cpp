void DateRange::fromJson(const QJsonObject& js){
    if(js.contains("start_date") && js["start_date"].isString()){
        QString startStr = js["start_date"].toString();
        m_start_date = QDateTime::fromString(startStr, "yyyy-MM-ddThh:mm:ssZ");
    }
    if(js.contains("end_date") && js["end_date"].isString()){
        QString endStr = js["end_date"].toString();
        m_end_date = QDateTime::fromString(endStr, "yyyy-MM-ddThh:mm:ssZ");
    }
}
