void LimitEditor::updateActions()
{
    bool st = w_->pathView_->selectionModel()->hasSelection();
    if (st) {
        actionRemove_->setEnabled(true);
        actionRemoveAll_->setEnabled(true);
    } else {
        actionRemove_->setEnabled(false);
        actionRemoveAll_->setEnabled(false);
    }
}
