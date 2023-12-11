void LimitEditor::updateActions() {
    QModelIndexList selectedIndexes = w_->pathView_->selectionModel()->selectedIndexes();
    bool st =!selectedIndexes.isEmpty();

    actionRemove_->setEnabled(st);
    actionRemoveAll_->setEnabled(st);
}


LimitEditor::LimitEditor(QWidget *parent) : QWidget(parent) {
    //...
    connect(w_->pathView_->selectionModel(), &QItemSelectionModel::selectionChanged, this, &LimitEditor::updateActions);
    //...
}