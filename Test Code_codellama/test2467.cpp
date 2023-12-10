void retrieveCategories(int parentCategoryId, int sort, int limit, int offset, Vector<Category>& ret) {
    // Construct the database query
    Statement stmt = this->session()->createStatement("SELECT * FROM categories WHERE parent_id = ? ORDER BY sort_order LIMIT ? OFFSET ?");
    stmt.bind(1, parentCategoryId);
    stmt.bind(2, limit);
    stmt.bind(3, offset);

    // Execute the query and retrieve the categories
    stmt.execute();
    auto categories = stmt.fetchAll();

    // Populate the ret vector with the retrieved categories
    for (auto& category : categories) {
        ret.push_back(Category(category.getInt("id"), category.getString("name"), category.getInt("parent_id")));
    }
}
