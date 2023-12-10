#include <iostream>
#include <map>

void test(std::map<int, int> mp, std::map<int, int>::iterator it) {
  while (it != mp.end()) {
    std::cout << it->first << std::endl;
    it++;
  }
}

void modifyMap(std::map<int, int>& mp) {
  for (auto& pair : mp) {
    pair.second *= pair.second;
  }
}

int main() {
  std::map<int, int> myMap = {{1, 2}, {3, 4}, {5, 6}};
  test(myMap, myMap.begin());

  modifyMap(myMap);

  for (const auto& pair : myMap) {
    std::cout << pair.first << " : " << pair.second << std::endl;
  }

  return 0;
}
