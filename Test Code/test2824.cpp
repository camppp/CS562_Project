// Handle user's response to the QMessageBox dialog
switch (userResponse) {
    case QMessageBox::Yes:
        // Save the edited cache window size and reopen the application
        saveAndReopen();
        break;
    case QMessageBox::No:
        // Update the cache window size with the user's edited value
        m_cacheWindowSizeBeforeEdit = ui.lineEditCacheWindow->text().toUInt();
        break;
    case QMessageBox::Cancel:
        // Revert the cache window size to the original value before any edits
        ui.lineEditCacheWindow->setText(QString::number(m_cacheWindowSizeBeforeEdit));
        break;
    default:
        // Handle any other cases or do nothing
        break;
}
