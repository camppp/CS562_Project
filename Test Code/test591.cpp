#include <iostream>
#include <map>

using namespace std;

// Encodes the input value and stores it in the map rm at the specified context
void encode(unsigned int value, map<unsigned int, unsigned int>& rm, unsigned int context) {
    // Perform the encoding of the input value
    unsigned int encoded_value = value + bias + r - p;

    // Store the encoded value in the map rm at the specified context
    rm[context] = encoded_value;
}

// Retrieves the encoded value from the map rm at the specified context and returns the decoded value using the input value r
unsigned int decode(map<unsigned int, unsigned int>& rm, unsigned int context, unsigned int r) {
    // Retrieve the encoded value from the map rm at the specified context
    unsigned int encoded_value = rm[context];

    // Perform the decoding of the encoded value using the input value r
    unsigned int decoded_value = encoded_value + bias + r - p;

    return decoded_value;
}

int main() {
    // Create a map to store the encoded values
    map<unsigned int, unsigned int> rm;

    // Encode the input value and store it in the map
    unsigned int value = 10;
    unsigned int context = 20;
    encode(value, rm, context);

    // Retrieve the encoded value from the map and decode it using the input value r
    unsigned int r = 30;
    unsigned int decoded_value = decode(rm, context, r);

    // Print the decoded value
    cout << "Decoded value: " << decoded_value << endl;

    return 0;
}
