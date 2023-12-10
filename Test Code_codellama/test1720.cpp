#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// Define the grammar structure
struct Grammar {
    set<string> N; // Set of non-terminal symbols
    set<string> T; // Set of terminal symbols
    string S; // Start symbol
    vector<vector<string>> P; // Set of production rules
};

// Define the function to calculate the set A
set<string> calculateAttributes(const Grammar& G) {
    set<string> A; // Set of attributes

    // Iterate over the non-terminal symbols in N
    for (const string& X : G.N) {
        // Calculate the synthesized attributes for X
        set<string> Syn(X);

        // Iterate over the production rules for X
        for (const vector<string>& rule : G.P) {
            // If the first element of the rule is X, add the second element to Syn
            if (rule[0] == X) {
                Syn.insert(rule[1]);
            }
        }

        // Calculate the inherited attributes for X
        set<string> Inh(X);

        // Iterate over the production rules for X
        for (const vector<string>& rule : G.P) {
            // If the second element of the rule is X, add the first element to Inh
            if (rule[1] == X) {
                Inh.insert(rule[0]);
            }
        }

        // Add the union of Syn and Inh to A
        A.insert(Syn.begin(), Syn.end());
        A.insert(Inh.begin(), Inh.end());
    }

    return A;
}

int main() {
    // Define the grammar
    Grammar G = {{"N1", "N2", "N3"}, {"T1", "T2"}, "S", {{"S", "N1"}, {"N1", "T1"}, {"N2", "T2"}}};

    // Calculate the set A
    set<string> A = calculateAttributes(G);

    // Print the set A
    for (const string& attr : A) {
        cout << attr << " ";
    }
    cout << endl;

    return 0;
}
