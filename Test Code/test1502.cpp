#include "crypto/crypto_wrapper.h"
#include "configurations.h"
#include "extern_consts.h"

#define _default_response ""

char* encryptMessage(const char* message) {
    char* encryptedMessage = crypto_wrapper_encrypt(message, configurations, extern_consts);
    if (encryptedMessage == NULL) {
        return _default_response;
    }
    return encryptedMessage;
}
