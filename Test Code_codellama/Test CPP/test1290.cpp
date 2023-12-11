secure::string secureDataAccess(const StlAddress &addr, const Key &key, bool isWriteOperation, const secure::string &buffer) {
  // Check if the key has access to the address
  if (!acl_has_access(addr, key)) {
    return "Access denied";
  }

  // If the operation is a write operation, check if the key has write access to the address
  if (isWriteOperation && !acl_has_write_access(addr, key)) {
    return "Write access denied";
  }

  // If the operation is a read operation, check if the address is publicly accessible
  if (!isWriteOperation && !acl_is_public(addr)) {
    return "Read access denied";
  }

  // If the access control checks pass, perform the data operation
  if (isWriteOperation) {
    return acl_write(addr, key, buffer);
  } else {
    secure::string value;
    acl_read(addr, key, &value, is_client_reader);
    return value;
  }
}
