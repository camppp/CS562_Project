#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

char* calculateSHA512(const char* input) {
    unsigned char hash[SHA512_DIGEST_LENGTH];
    SHA512_CTX ctx;
    SHA512_Init(&ctx);
    SHA512_Update(&ctx, input, strlen(input));
    SHA512_Final(hash, &ctx);
    char* hexHash = (char*)malloc(SHA512_DIGEST_LENGTH * 2 + 1);
    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        sprintf(hexHash + i * 2, "%02x", hash[i]);
    }
    return hexHash;
}

int main() {
    const char* input = "Hello, World!";
    char* sha512Hash = calculateSHA512(input);
    printf("SHA-512 Hash: %s\n", sha512Hash);
    return 0;
}
