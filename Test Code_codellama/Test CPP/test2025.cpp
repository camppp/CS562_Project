#include <vector>
#include <algorithm>

class PileupJetIdentifier {
 public:
  PileupJetIdentifier() {}

  void identifyPileupJets(const std::vector<Jet>& allJets) {
    // Iterate over all jets and identify pileup jets based on criteria
    for (const auto& jet : allJets) {
      if (isPileupJet(jet)) {
        // Add jet to pileup jet vector
        pileupJets_.push_back(jet);
      }
    }
  }

  // Getter for pileup jet vector
  const std::vector<Jet>& getPileupJets() const {
    return pileupJets_;
  }

 private:
  // Vector to store pileup jets
  std::vector<Jet> pileupJets_;

  // Criteria for identifying pileup jets
  bool isPileupJet(const Jet& jet) {
    // Check if jet has a certain energy threshold
    if (jet.energy() < 100) {
      return false;
    }

    // Check if jet has a certain momentum threshold
    if (jet.momentum().mag() < 10) {
      return false;
    }

    // Check if jet has a certain number of constituents
    if (jet.constituents().size() < 5) {
      return false;
    }

    // Check if jet has a certain type of constituent
    if (jet.constituents()[0].type() != "proton") {
      return false;
    }

    return true;
  }
};
