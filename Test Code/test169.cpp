void processField(int nType) {
    sal_uInt16 nWhich = nType;
    if (RES_DATEFLD == nType) {
        // Logic for processing date fields
        // Perform specific actions for date fields
    } else if (RES_TIMEFLD == nType) {
        // Logic for processing time fields
        // Perform specific actions for time fields
    } else {
        nWhich = RES_DATETIMEFLD;
        // Logic for processing datetime fields
        // Perform specific actions for datetime fields
    }
    // Additional common processing logic for all field types
}
