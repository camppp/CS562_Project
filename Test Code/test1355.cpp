c++
int CalculateTotalSize(GList* items, std::string* errStr) {
  int totalSize = 0;
  for (GList* item = items; item != NULL; item = item->next) {
    SecretItem* secretItem = (SecretItem*)item->data;
    if (secretItem == NULL) {
      *errStr = "Invalid secret item";
      return -1;
    }
    totalSize += secretItem->size;
  }
  return totalSize;
}
