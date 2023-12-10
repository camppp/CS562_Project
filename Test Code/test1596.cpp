#include <iostream>
#include <string>
#include <openssl/sha.h>

int main() {
    std::string input = "hello world";
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input.c_str(), input.size());
    SHA256_Final(hash, &ctx);
    std::cout << "SHA-256 hash: " << hash << std::endl;
    std::cout << "Size in bytes: " << SHA256_DIGEST_LENGTH << std::endl;
    return 0;
}
