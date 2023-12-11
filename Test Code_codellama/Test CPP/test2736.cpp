fusion_priority_t(char * const arg_name, const int arg_num_pred, const int arg_meta_size)
{
    // Initialize the name of the node
    name = arg_name;

    // Initialize the number of predecessors for the node
    num_pred = arg_num_pred;

    // Initialize the size of the metadata associated with the node
    meta_size = arg_meta_size;
}
