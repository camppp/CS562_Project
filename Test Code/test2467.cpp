void retrieveCategories(int parentCategoryId, int sort, int limit, int offset, Vector<Category>& ret) {
    try {
        // Acquire a database session
        std::unique_ptr<DataSession> session = this->session();

        // Construct and execute the database query
        Statement select(*session);
        select << (std::string)"SELECT ACat.* FROM (\
                SELECT _id FROM Category WHERE ifnull(_parent_id, 0)=?\
                ORDER BY _id " + (sort < 0 ? "ASC " : "DESC ") + "LIMIT ? OFFSET ?\
            ) AS L INNER JOIN Category AS ACat ON ACat._id=L._id\
            ORDER BY ACat._id " + (sort < 0 ? "ASC " : "DESC "),
            parentCategoryId, limit, offset;

        // Retrieve the results and populate the ret vector with categories
        Result result = select.query();
        while (result.next()) {
            Category category;
            // Populate category object with data from the result set
            // Assuming there is a method to retrieve category data from the result set
            // category.setId(result.get<int>("_id"));
            // category.setName(result.get<std::string>("name"));
            // Populate other category attributes as needed
            ret.push_back(category);
        }
    } catch (std::exception const& e) {
        // Handle any exceptions that occur during database interaction
        // Log or report the error as needed
    }
}
