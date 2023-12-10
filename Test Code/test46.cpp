void LimitEditor::updateActions()
{
    bool st = w_->pathView_->selectionModel()->selectedIndexes().count() > 0;

    w_->actionRemove_->setEnabled(st);
    w_->actionRemoveAll_->setEnabled(st);
}

// Connect the slot to the appropriate signals in the constructor or initialization method
// For example:
// connect(w_->pathView_->selectionModel(), &QItemSelectionModel::selectionChanged, this, &LimitEditor::updateActions);
