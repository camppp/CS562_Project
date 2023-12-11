void modifyMap(std::map<int, int>& mp) {
  for (auto& pair : mp) {
    pair.second *= pair.second;
  }
}
