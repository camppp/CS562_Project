WeightClass calculateCostPrediction(const std::vector<Example>& examples, const Scorer& scorer, bool shared) {
  WeightClass wc;

  if (shared) {
    // Set class_index based on the condition for shared=true
    wc.class_index = examples.size() - 1;
  } else {
    // Calculate cost prediction using CB_ALGS::get_cost_pred function for shared=false
    wc.x = CB_ALGS::get_cost_pred<true>(scorer, nullptr, examples[0], 0, 2);
  }

  return wc;
}
