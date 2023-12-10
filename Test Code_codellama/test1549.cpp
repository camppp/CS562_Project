c
void simplified_dsift_delete(DenseSift* sift) {
    if (sift != NULL) {
        if (sift->data != NULL) {
            free(sift->data);
        }
        free(sift);
    }
}
