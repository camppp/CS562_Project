void TabResponseHeaders::populateHeaders(QMap<QString, QString> headers)
{
    // Clear the current table data
    headersTable->clear();

    // Set the column names
    headersTable->setColumnCount(2);
    headersTable->setHorizontalHeaderLabels(QStringList() << "Name" << "Value");

    // Set the grid visibility
    headersTable->setGridVisible(true);

    // Populate the table with the response headers
    for (auto it = headers.begin(); it != headers.end(); ++it) {
        QString name = it.key();
        QString value = it.value();
        headersTable->insertRow(headersTable->rowCount());
        headersTable->setItem(headersTable->rowCount() - 1, 0, new QTableWidgetItem(name));
        headersTable->setItem(headersTable->rowCount() - 1, 1, new QTableWidgetItem(value));
    }
}
