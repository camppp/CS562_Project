void OlapTableIndexSchema::sortIndexes(std::vector<OlapTableIndexSchema*>& _indexes) {
    std::sort(_indexes.begin(), _indexes.end(), [](const OlapTableIndexSchema* lhs, const OlapTableIndexSchema* rhs) {
        if (lhs->indexName != rhs->indexName) {
            return lhs->indexName < rhs->indexName;
        } else if (lhs->columnName != rhs->columnName) {
            return lhs->columnName > rhs->columnName;  // Sort in descending order
        } else {
            return lhs->isUnique < rhs->isUnique;
        }
    });
}
