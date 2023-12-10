#include <vector>
#include <utility>
#include <algorithm>

class Product {
public:
  virtual bool propagate(Scheduler& scheduler) = 0;
};

class ConstraintProduct : public Product {
public:
  ConstraintProduct(const std::vector<std::pair<DataType, DataType>>& domains, const DataType& constraint)
      : domains_(domains), constraint_(constraint) {}

  bool propagate(Scheduler& scheduler) override {
    // Update the domains based on the constraint
    for (auto& domain : domains_) {
      if (domain.first > constraint_) {
        domain.first = constraint_;
      }
      if (domain.second < constraint_) {
        domain.second = constraint_;
      }
    }

    // Update the scheduler with the updated domains
    scheduler.setDomains(domains_);

    return true;
  }

private:
  std::vector<std::pair<DataType, DataType>> domains_;
  DataType constraint_;
};
