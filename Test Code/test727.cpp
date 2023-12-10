#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Function to build the DAWG from the lexicon
bool BuildDawg(istream& lexicon_stream, dawgdic::Dawg* dawg, const string& options) {
  // Read the lexicon from the input stream
  vector<string> lexicon;
  string word;
  while (lexicon_stream >> word) {
    lexicon.push_back(word);
  }

  // Construct the DAWG from the lexicon
  dawg->construct(lexicon, options);

  // Return success
  return true;
}

// Function to build the dictionary from the DAWG
bool BuildDictionary(dawgdic::Dawg& dawg, dawgdic::Dictionary* dic) {
  // Get the root node of the DAWG
  dawgdic::Node* root = dawg.get_root();

  // Iterate over the nodes in the DAWG
  for (auto it = root->begin(); it != root->end(); ++it) {
    // Get the current node
    dawgdic::Node* node = *it;

    // Check if the node is a word
    if (node->is_word()) {
      // Add the word to the dictionary
      dic->add_word(node->get_word());
    }
  }

  // Return success
  return true;
}

int main() {
  // Open the lexicon file
  ifstream lexicon_file("lexicon.txt");
  if (!lexicon_file) {
    cerr << "Error: unable to open lexicon file" << endl;
    return 1;
  }

  // Construct the DAWG from the lexicon
  dawgdic::Dawg dawg;
  if (!BuildDawg(lexicon_file, &dawg, "")) {
    cerr << "Error: unable to construct DAWG" << endl;
    return 1;
  }

  // Build the dictionary from the DAWG
  dawgdic::Dictionary dic;
  if (!BuildDictionary(dawg, &dic)) {
    cerr << "Error: unable to build dictionary" << endl;
    return 1;
  }

  // Print the dictionary
  for (auto it = dic.begin(); it != dic.end(); ++it) {
    cout << *it << endl;
  }

  // Return success
  return 0;
}
