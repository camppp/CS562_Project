#include <vector>

std::vector<int64_t> compareFieldValues(const KernelCopy& create_pre_save, const KernelCopy& create_post_save) {
    std::vector<int64_t> results;

    for (int i = BEGIN_FIELDS; i <= INT64_FIELDS_END; ++i) {
        int64_t pre_save_value = create_pre_save.ref((Int64Field)i);
        int64_t post_save_value = create_post_save.ref((Int64Field)i);

        if (i == TRANSACTION_VERSION) {
            pre_save_value += 1;
        }

        results.push_back(pre_save_value == post_save_value? 1 : 0);
    }

    return results;
}