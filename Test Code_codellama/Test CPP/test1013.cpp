string SerializePayload(const map<string, string>& payload) {
  string query_string;
  for (const auto& [key, value] : payload) {
    query_string += key + "=" + UrlEncode(value) + "&";
  }
  return query_string.substr(0, query_string.size() - 1);
}
