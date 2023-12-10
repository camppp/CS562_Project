#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <bitset>

struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;
};

struct Compare {
    bool operator()(Node* const& a, Node* const& b) {
        return a->frequency > b->frequency;
    }
};

class Huffman {
public:
    Node* buildHuffmanTree(const std::string& text) {
        std::unordered_map<char, int> frequencyMap;
        for (char c : text) {
            frequencyMap[c]++;
        }

        std::priority_queue<Node*, std::vector<Node*>, Compare> minHeap;
        for (const auto& pair : frequencyMap) {
            Node* newNode = new Node{pair.first, pair.second, nullptr, nullptr};
            minHeap.push(newNode);
        }

        while (minHeap.size() != 1) {
            Node* left = minHeap.top();
            minHeap.pop();
            Node* right = minHeap.top();
            minHeap.pop();

            Node* parent = new Node{'\0', left->frequency + right->frequency, left, right};
            minHeap.push(parent);
        }

        return minHeap.top();
    }

    void encode(Node* root, std::string code, std::unordered_map<char, std::string>& encodings) {
        if (root == nullptr) {
            return;
        }
        if (!root->left && !root->right) {
            encodings[root->data] = code;
        }
        encode(root->left, code + "0", encodings);
        encode(root->right, code + "1", encodings);
    }

    std::string compress(const std::string& text, const std::unordered_map<char, std::string>& encodings) {
        std::string compressed;
        for (char c : text) {
            compressed += encodings.at(c);
        }
        return compressed;
    }

    std::string decompress(const std::string& compressed, Node* root) {
        std::string decompressed;
        Node* current = root;
        for (char bit : compressed) {
            if (bit == '0') {
                current = current->left;
            } else {
                current = current->right;
            }
            if (!current->left && !current->right) {
                decompressed += current->data;
                current = root;
            }
        }
        return decompressed;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    Huffman huffman;
    Node* root = huffman.buildHuffmanTree(text);

    std::unordered_map<char, std::string> encodings;
    huffman.encode(root, "", encodings);

    std::string compressed = huffman.compress(text, encodings);
    std::cout << "Compressed text: " << compressed << std::endl;

    std::string decompressed = huffman.decompress(compressed, root);
    std::cout << "Decompressed text: " << decompressed << std::endl;

    return 0;
}
