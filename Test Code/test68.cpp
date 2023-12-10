std::vector<int64_t> compareFieldValues() {
    std::vector<int64_t> results;
    for (int i = BEGIN_FIELDS; i <= INT64_FIELDS_END; i++) {
        int64_t pre_value = create_pre_save.ref((Int64Field)i);
        int64_t post_value = create_post_save.ref((Int64Field)i);
        if (i == TRANSACTION_VERSION) {
            pre_value++;
        }
        EXPECT_EQ(pre_value, post_value);
        results.push_back(pre_value);
    }
    return results;
}
