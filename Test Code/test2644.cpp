vector<string> Wiki::getCategoryMembers(const string& category) {
  vector<string> members;
  CategoryMembersParams params;
  params.title = category;
  params.titlesOfMembers = &members;

  try {
    int numMembers = enumerateCategoryMembers(category, [&](const string& member) {
      members.push_back(member);
    });
    return members;
  } catch (WikiError& error) {
    error.addContext("Cannot enumerate members of '" + params.title + "'");
    throw;
  }
}
