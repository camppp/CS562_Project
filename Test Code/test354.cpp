#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
  vector<int> sequence;
  unordered_map<int, int> indexMap;
  int num, query;

  // Input the sequence
  while (cin >> num && num >= 0) {
    sequence.push_back(num);
  }

  // Create a map of integer to its first occurrence index
  for (int i = 0; i < sequence.size(); i++) {
    if (indexMap.find(sequence[i]) == indexMap.end()) {
      indexMap[sequence[i]] = i;
    }
  }

  // Process the queries
  while (cin >> query && query >= 0) {
    if (indexMap.find(query) != indexMap.end()) {
      cout << indexMap[query] << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
