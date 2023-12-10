void BranchDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  ReferenceList *refs = qobject_cast<ReferenceList *>(editor);
  if (!refs) {
    QStyledItemDelegate::setEditorData(editor, index);
    return;
  }

  // Search for the matching item.
  QVariant data = index.data(Qt::EditRole);  // Get the data for the given index
  QString referenceName = data.toString();   // Assuming the data represents the reference name

  // Search for the matching item in the ReferenceList
  for (int i = 0; i < refs->rowCount(); ++i) {
    QModelIndex refIndex = refs->index(i, 0);  // Assuming the reference name is in the first column
    QVariant refData = refIndex.data(Qt::DisplayRole);
    if (refData.toString() == referenceName) {
      refs->setCurrentIndex(refIndex);  // Set the current index in the ReferenceList
      break;
    }
  }
}
