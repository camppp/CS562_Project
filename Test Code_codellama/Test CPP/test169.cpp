void processField(int nType, int nWhich) {
    if (nType == RES_DATEFLD) {
        // Perform specific actions for date fields
    } else if (nType == RES_TIMEFLD) {
        // Perform specific actions for time fields
    } else {
        // Resolve nWhich to RES_DATETIMEFLD and perform specific actions for datetime fields
        nWhich = RES_DATETIMEFLD;
    }
}
