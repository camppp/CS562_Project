std::vector<int64_t> compareFieldValues() {
    std::vector<int64_t> comparisonResults;
    create_post_save = create.GetKernelCopy();
    update_post_save = update.GetKernelCopy();

    int i = BEGIN_FIELDS;
    for (; i < INT64_FIELDS_END; ++i) {
        int64_t preValue = create_pre_save.ref((Int64Field)i);
        int64_t postValue = create_post_save.ref((Int64Field)i);
        if (i == TRANSACTION_VERSION) {
            preValue += 1;
        }
        comparisonResults.push_back(preValue == postValue ? 1 : 0);
    }

    return comparisonResults;
}
