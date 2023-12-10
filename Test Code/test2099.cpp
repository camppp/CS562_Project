#include <random>
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <zcash/note.h>

using namespace std;

ZCNoteEncryption generateEncryptedNote() {
    // Generate a random 256-bit unsigned integer
    uint256_t hSig = random_uint256();

    // Generate a random unsigned char
    unsigned char nonce = random_uchar();

    // Create a ZCNoteEncryption object using the generated random integers
    ZCNoteEncryption noteEncryption(hSig, nonce);

    return noteEncryption;
}
