int LogChangePathEntriesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent); // Avoid unused parameter warning

    return m_logChangePathEntries.size();
}
