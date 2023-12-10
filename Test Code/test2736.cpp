class fusion_priority_t {
public:
    char *name;
    int num_pred;
    int meta_size;

    fusion_priority_t(char * const arg_name, const int arg_num_pred, const int arg_meta_size) {
        name = arg_name;
        num_pred = arg_num_pred;
        meta_size = arg_meta_size;
    }
};
