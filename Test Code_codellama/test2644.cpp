vector<string> Wiki::getCategoryMembers(const string& category) {
  vector<string> members;
  CategoryMembersParams params;
  params.title = category;
  params.titlesOfMembers = &members;
  enumerateCategoryMembers(params);
  return members;
}
