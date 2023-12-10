void TabResponseHeaders::populateHeaders(const QMap<QString, QString>& responseHeaders)
{
    // Clear any existing data in the table
    headersTable->clearContents();
    headersTable->setRowCount(responseHeaders.size());

    int row = 0;
    for (auto it = responseHeaders.constBegin(); it != responseHeaders.constEnd(); ++it) {
        QTableWidgetItem* nameItem = new QTableWidgetItem(it.key());
        QTableWidgetItem* valueItem = new QTableWidgetItem(it.value());

        headersTable->setItem(row, 0, nameItem);  // Set the name in the first column
        headersTable->setItem(row, 1, valueItem); // Set the value in the second column

        row++;
    }

    headersTable->resizeColumnsToContents();
}
