#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Struct to represent a node in the Huffman tree
struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;
};

// Function to construct the Huffman tree
Node* constructHuffmanTree(vector<int>& freq) {
    // Create a priority queue to store the nodes
    priority_queue<Node*, vector<Node*>, greater<Node*>> pq;

    // Create a map to store the frequency of each character
    map<char, int> charFreq;
    for (int i = 0; i < freq.size(); i++) {
        charFreq[freq[i]]++;
    }

    // Create the root node and add it to the priority queue
    Node* root = new Node;
    root->data = ' ';
    root->freq = 0;
    root->left = NULL;
    root->right = NULL;
    pq.push(root);

    // Loop until the priority queue is empty
    while (!pq.empty()) {
        // Get the node with the highest frequency
        Node* node = pq.top();
        pq.pop();

        // If the node has no children, add it to the Huffman tree
        if (node->left == NULL && node->right == NULL) {
            // Add the node to the Huffman tree
            root->left = node;
            root->freq += node->freq;
            break;
        }

        // If the node has children, add them to the priority queue
        if (node->left != NULL) {
            pq.push(node->left);
        }
        if (node->right != NULL) {
            pq.push(node->right);
        }

        // Create a new node and add it to the priority queue
        Node* newNode = new Node;
        newNode->data = ' ';
        newNode->freq = 0;
        newNode->left = NULL;
        newNode->right = NULL;
        pq.push(newNode);
    }

    return root;
}

// Function to encode the input text using the Huffman tree
void encode(string input, Node* root) {
    // Create a vector to store the encoded data
    vector<char> encodedData;

    // Loop through each character in the input text
    for (int i = 0; i < input.size(); i++) {
        // Get the character and its frequency
        char c = input[i];
        int freq = charFreq[c];

        // Loop through each node in the Huffman tree
        Node* node = root;
        while (node != NULL) {
            // If the node has a child with the same frequency, add the child to the encoded data
            if (node->left != NULL && node->left->freq == freq) {
                encodedData.push_back('0');
                node = node->left;
            } else if (node->right != NULL && node->right->freq == freq) {
                encodedData.push_back('1');
                node = node->right;
            } else {
                // If the node does not have a child with the same frequency, add the node to the encoded data
                encodedData.push_back(node->data);
                node = NULL;
            }
        }
    }

    // Print the encoded data
    cout << "Encoded data: ";
    for (int i = 0; i < encodedData.size(); i++) {
        cout << encodedData[i];
    }
    cout << endl;
}

// Function to decode the encoded data using the Huffman tree
void decode(string encodedData, Node* root) {
    // Create a vector to store the decoded data
    vector<char> decodedData;

    // Loop through each character in the encoded data
    for (int i = 0; i < encodedData.size(); i++) {
        // Get the character and its frequency
        char c = encodedData[i];
        int freq = charFreq[c];

        // Loop through each node in the Huffman tree
        Node* node = root;
        while (node != NULL) {
            // If the node has a child with the same frequency, add the child to the decoded data
            if (node->left != NULL && node->left->freq == freq) {
                decodedData.push_back('0');
                node = node->left;
            } else if (node->right != NULL && node->right->freq == freq) {
                decodedData.push_back('1');
                node = node->right;
            } else {
                // If the node does not have a child with the same frequency, add the node to the decoded data
                decodedData.push_back(node->data);
                node = NULL;
            }
        }
    }

    // Print the decoded data
    cout << "Decoded data: ";
    for (int i = 0; i < decodedData.size(); i++) {
        cout << decodedData[i];
    }
    cout << endl;
}

int main() {
    // Read the input text file
    ifstream inputFile("input.txt");
    string input;
    getline(inputFile, input);

    // Construct the Huffman tree
    vector<int> freq(256);
    for (int i = 0; i < input.size(); i++) {
        freq[input[i]]++;
    }
    Node* root = constructHuffmanTree(freq);

    // Encode the input text
    encode(input, root);

    // Decode the encoded data
    decode(encodedData, root);

    return 0;
}
