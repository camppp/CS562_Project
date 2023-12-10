#include <iostream>
#include <string>
#include <vector>
#include <map>

// Define a struct to represent a state in the NFA
struct NFAState {
    int id;
    std::vector<NFAState*> transitions;
    bool isAccepting;
};

// Define a struct to represent the NFA
struct NFA {
    std::vector<NFAState*> states;
    std::vector<char> inputSymbols;
    std::map<NFAState*, std::vector<NFAState*>> transitionFunction;
    NFAState* startState;
    std::vector<NFAState*> acceptingStates;
};

// Define a function to compile a regular expression into an NFA
NFA compileRegex(std::string regex) {
    // Initialize the NFA
    NFA nfa;
    nfa.states.push_back(new NFAState());
    nfa.startState = nfa.states[0];
    nfa.acceptingStates.push_back(nfa.states[0]);

    // Parse the regular expression
    int i = 0;
    while (i < regex.size()) {
        char c = regex[i];
        if (c == '(') {
            // Parse a concatenation
            std::string concat = "";
            while (i < regex.size() && regex[i] != ')') {
                concat += regex[i];
                i++;
            }
            i++;
            NFAState* state = new NFAState();
            nfa.states.push_back(state);
            nfa.transitionFunction[nfa.startState].push_back(state);
            nfa.startState = state;
            nfa.acceptingStates.push_back(state);
        } else if (c == '|') {
            // Parse an alternation
            std::string alt = "";
            while (i < regex.size() && regex[i] != '|') {
                alt += regex[i];
                i++;
            }
            i++;
            NFAState* state = new NFAState();
            nfa.states.push_back(state);
            nfa.transitionFunction[nfa.startState].push_back(state);
            nfa.startState = state;
            nfa.acceptingStates.push_back(state);
        } else if (c == '*') {
            // Parse a Kleene star
            NFAState* state = new NFAState();
            nfa.states.push_back(state);
            nfa.transitionFunction[nfa.startState].push_back(state);
            nfa.startState = state;
            nfa.acceptingStates.push_back(state);
        } else {
            // Parse a literal
            NFAState* state = new NFAState();
            nfa.states.push_back(state);
            nfa.transitionFunction[nfa.startState].push_back(state);
            nfa.startState = state;
            nfa.acceptingStates.push_back(state);
        }
    }

    // Return the NFA
    return nfa;
}

// Define a function to print the NFA
void printNFA(NFA nfa) {
    for (int i = 0; i < nfa.states.size(); i++) {
        std::cout << "State " << i << ": ";
        for (int j = 0; j < nfa.transitionFunction[nfa.states[i]].size(); j++) {
            std::cout << nfa.transitionFunction[nfa.states[i]][j]->id << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Compile a regular expression into an NFA
    NFA nfa = compileRegex("a(b|c)*");

    // Print the NFA
    printNFA(nfa);

    return 0;
}
