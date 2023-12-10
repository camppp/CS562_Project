#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Key matrix for encryption and decryption
const int key_matrix[5][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};

// Cipher array for encryption and decryption
const int cipher_array[26] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25
};

// Encrypt the input file and write the encrypted content to the output file
void encrypt_file(string input_file_name, string output_file_name) {
    ifstream input_file(input_file_name, ios::in);
    ofstream output_file(output_file_name, ios::out);

    // Read the input file and encrypt each character
    char c;
    while (input_file.get(c)) {
        // Use the key matrix and cipher array to encrypt the character
        int key = key_matrix[c - 'A'][c - 'A'];
        int cipher = cipher_array[key];
        output_file << (char)cipher;
    }

    input_file.close();
    output_file.close();
}

// Decrypt the input file and write the decrypted content to the output file
void decrypt_file(string input_file_name, string output_file_name) {
    ifstream input_file(input_file_name, ios::in);
    ofstream output_file(output_file_name, ios::out);

    // Read the input file and decrypt each character
    char c;
    while (input_file.get(c)) {
        // Use the key matrix and cipher array to decrypt the character
        int key = key_matrix[c - 'A'][c - 'A'];
        int cipher = cipher_array[key];
        output_file << (char)(c - cipher);
    }

    input_file.close();
    output_file.close();
}

int main() {
    string input_file_name = "input.txt";
    string output_file_name = "output.txt";

    // Encrypt the input file
    encrypt_file(input_file_name, output_file_name);

    // Decrypt the encrypted file
    decrypt_file(output_file_name, input_file_name);

    return 0;
}
