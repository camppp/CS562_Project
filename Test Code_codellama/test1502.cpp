#include <crypto_wrapper.h>
#include <configurations.h>
#include <extern_consts.h>

#define _default_response "Error: Encryption failed"

char* encryptMessage(const char* message) {
    // Initialize the cryptographic algorithm
    crypto_init();

    // Set the encryption key
    crypto_set_key(ENCRYPTION_KEY);

    // Encrypt the message
    char* encrypted_message = crypto_encrypt(message);

    // Check for errors
    if (encrypted_message == NULL) {
        return _default_response;
    }

    // Return the encrypted message
    return encrypted_message;
}
