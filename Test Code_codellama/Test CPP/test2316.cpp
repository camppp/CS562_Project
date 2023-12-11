void Parse(QueryResults* results, int idx, Labels* lset, vector<Labels>* lsets, uint64_t* id, vector<vector<int64_t>>* t, vector<vector<double>>* v) {
  // Extract the time-series data and labels from the query results
  auto& data = results->data[idx];
  auto& labels = results->labels[idx];

  // Populate the provided data structures with the extracted information
  *id = data.id;
  *t = data.t;
  *v = data.v;
  *lset = labels.set;
  *lsets = labels.sets;
}
