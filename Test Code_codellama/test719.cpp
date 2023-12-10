#include <iostream>
#include <string>
#include <vector>

// Define the ProofState and Goal classes
class ProofState {
 public:
  std::vector<std::string> hypotheses;
  std::vector<std::string> goals;
  std::vector<std::string> substitutions;
};

class Goal {
 public:
  std::string hypothesis;
  std::string goal;
};

// Define the revertTactic function
ProofState revertTactic(ProofState s, std::vector<Goal> goals, std::string n) {
  // Check if the hypothesis n exists in the current proof state
  if (std::find(s.hypotheses.begin(), s.hypotheses.end(), n) != s.hypotheses.end()) {
    // Create a new substitution new_subst by applying a new metavariable new_meta to the hypothesis h
    std::string new_meta = "new_meta";
    std::string new_subst = new_meta + " = " + n;

    // Construct a new proof state new_s with the updated goals and substitution
    ProofState new_s = s;
    new_s.substitutions.push_back(new_subst);
    new_s.goals.push_back(new_meta);

    return new_s;
  } else {
    // Throw a tactic exception with an error message if the hypothesis n does not exist in the current proof state
    std::string error_message = "Hypothesis " + n + " does not exist in the current proof state";
    throw TacticException(error_message);
  }
}

int main() {
  // Test the revertTactic function
  ProofState s;
  s.hypotheses = {"h1", "h2", "h3"};
  s.goals = {"g1", "g2", "g3"};
  s.substitutions = {"s1 = h1", "s2 = h2", "s3 = h3"};

  std::vector<Goal> goals;
  goals.push_back(Goal("g1", "h1"));
  goals.push_back(Goal("g2", "h2"));
  goals.push_back(Goal("g3", "h3"));

  ProofState new_s = revertTactic(s, goals, "h2");
  std::cout << "New proof state: " << new_s.hypotheses << std::endl;
  std::cout << "New proof state: " << new_s.goals << std::endl;
  std::cout << "New proof state: " << new_s.substitutions << std::endl;

  return 0;
}
