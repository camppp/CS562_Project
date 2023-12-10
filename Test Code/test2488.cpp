#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

char* calculateSHA512(const char* input) {
    unsigned char hash[SHA512_DIGEST_LENGTH];
    SHA512_CTX sha512;
    SHA512_Init(&sha512);
    SHA512_Update(&sha512, input, strlen(input));
    SHA512_Final(hash, &sha512);

    char* hexHash = malloc(SHA512_DIGEST_LENGTH * 2 + 1);
    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        sprintf(&hexHash[i * 2], "%02x", hash[i]);
    }
    hexHash[SHA512_DIGEST_LENGTH * 2] = '\0';

    return hexHash;
}

int main() {
    const char* input = "Hello, World!";
    char* sha512Hash = calculateSHA512(input);
    printf("SHA-512 Hash: %s\n", sha512Hash);
    free(sha512Hash);
    return 0;
}
