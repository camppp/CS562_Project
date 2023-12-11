#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Define the syntax properties for each keyword
#define SYNTAX_PROPERTY 0x1
#define SYNTAX_NEW 0x2
#define SYNTAX_OLD 0x4

// Define the token types for each keyword
#define T_ASINH 0x1
#define T_ASSERT 0x2
#define T_SIMULATE 0x3
#define T_TANH 0x4
#define T_ACOSH 0x5
#define T_SCALAR 0x6

// Define the function to parse the keywords
map<string, vector<string>> parseKeywords(const string& input) {
  // Initialize the map to store the keywords and their syntax properties
  map<string, vector<string>> keywords;

  // Split the input into lines
  vector<string> lines = split(input, '\n');

  // Iterate over the lines
  for (const string& line : lines) {
    // Split the line into tokens
    vector<string> tokens = split(line, ',');

    // Check if the line contains a keyword
    if (tokens.size() == 3) {
      // Extract the keyword, token, and syntax properties
      string keyword = tokens[0];
      string token = tokens[1];
      string syntax_properties = tokens[2];

      // Add the keyword and its syntax properties to the map
      keywords[keyword] = {token, syntax_properties};
    }
  }

  return keywords;
}

// Define the function to split a string into tokens
vector<string> split(const string& input, char delimiter) {
  vector<string> tokens;
  string token;

  // Iterate over the characters in the input string
  for (char c : input) {
    // Check if the character is a delimiter
    if (c == delimiter) {
      // Add the token to the vector of tokens
      tokens.push_back(token);
      token = "";
    } else {
      // Add the character to the token
      token += c;
    }
  }

  // Add the last token to the vector of tokens
  tokens.push_back(token);

  return tokens;
}

int main() {
  // Define the input code snippet
  string input = "{\"asinh\",                  T_ASINH,        SYNTAX_PROPERTY | SYNTAX_NEW},\n"
                 "#line 39 \"keywords.gperf\"\n"
                 "{\"assert\",			T_ASSERT,	SYNTAX_NEW},\n"
                 "{\"\"},\n"
                 "#line 56 \"keywords.gperf\"\n"
                 "{\"simulate\",               T_SIMULATE,     SYNTAX_PROPERTY},\n"
                 "#line 95 \"keywords.gperf\"\n"
                 "{\"tanh\",                   T_TANH,         SYNTAX_PROPERTY | SYNTAX_NEW},\n"
                 "#line 97 \"keywords.gperf\"\n"
                 "{\"acosh\",                  T_ACOSH,        SYNTAX_PROPERTY | SYNTAX_NEW},\n"
                 "#line 52 \"keywords.gperf\"\n"
                 "{\"scalar\",			T_SCALAR,	SYNTAX_OLD | SYNTAX_NEW | SYNTAX_PROPERTY},\n"
                 "{\"\"},\n"
                 "#line 67 \"keywords.gperf\"\n";

  // Parse the keywords
  map<string, vector<string>> keywords = parseKeywords(input);

  // Print the keywords and their syntax properties
  for (const auto& keyword : keywords) {
    cout << keyword.first << ": ";
    for (const auto& syntax_property : keyword.second) {
      cout << syntax_property << " ";
    }
    cout << endl;
  }

  return 0;
}
