++
int CalculateTotalSize(GList* items, std::string* errStr) {
  if (items == NULL) {
    *errStr = "Input list is NULL";
    return -1;
  }

  int totalSize = 0;
  GError* error = NULL;

  GList* current = items;
  for (current = items; current != NULL; current = current->next) {
    SecretItem* item = reinterpret_cast<SecretItem*>(current->data);
    if (item == NULL) {
      *errStr = "Invalid item in the list";
      return -1;
    }
    if (item->size < 0) {
      *errStr = "Invalid size for an item";
      return -1;
    }
    totalSize += item->size;
  }

  g_clear_error(&error);  // Clear any previous error
  if (error != NULL) {
    *errStr = std::string(error->message);
    g_error_free(error);
    return -1;
  }

  return totalSize;
}
