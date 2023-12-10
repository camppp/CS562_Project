void OlapTableIndexSchema::sortIndexes(std::vector<OlapTableIndexSchema*>& _indexes) {
    // Sort the indexes in ascending order of indexName
    std::sort(_indexes.begin(), _indexes.end(),
        [](const OlapTableIndexSchema* a, const OlapTableIndexSchema* b) {
            return a->indexName < b->indexName;
        });

    // If two indexes have the same indexName, sort them based on the columnName in descending order
    std::sort(_indexes.begin(), _indexes.end(),
        [](const OlapTableIndexSchema* a, const OlapTableIndexSchema* b) {
            if (a->indexName == b->indexName) {
                return a->columnName > b->columnName;
            }
            return false;
        });

    // If both indexName and columnName are the same, sort them based on the isUnique flag in ascending order (false first, true later)
    std::sort(_indexes.begin(), _indexes.end(),
        [](const OlapTableIndexSchema* a, const OlapTableIndexSchema* b) {
            if (a->indexName == b->indexName && a->columnName == b->columnName) {
                return a->isUnique < b->isUnique;
            }
            return false;
        });
}
