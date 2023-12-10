#include "access_control.h"

enum class Result {
    Success,
    AccessDenied,
    AddressNotFound,
    WriteError,
    ReadError
};

Result secureDataAccess(const StlAddress &addr, const Key &key, bool isWriteOperation, const secure::string &buffer) {
    if (isWriteOperation) {
        if (acl_has_access(addr, key)) {
            return acl_write(addr, key, buffer);
        } else {
            return Result::AccessDenied;
        }
    } else {
        secure::string out_value;
        if (acl_read(addr, key, &out_value, true)) {
            // Process the read data if needed
            return Result::Success;
        } else {
            return Result::AccessDenied;
        }
    }
}
