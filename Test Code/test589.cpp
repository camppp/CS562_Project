#include <cassert>

// Forward declaration of IAnimationGraphState interface
class IAnimationGraphState;

class CMannequinAGExistanceQuery {
private:
    IAnimationGraphState* m_pAnimationGraphState;

public:
    // Constructor to initialize m_pAnimationGraphState and perform NULL check
    CMannequinAGExistanceQuery(IAnimationGraphState* pAnimationGraphState) : m_pAnimationGraphState(pAnimationGraphState) {
        assert(m_pAnimationGraphState != nullptr);
    }

    // Method to perform the existence query for a specific animation graph state
    bool DoesStateExist(const char* stateName) {
        // Assuming the existence query logic involves checking the stateName against available animation graph states
        // Implement the logic based on the game engine's animation graph state management
        // Return true if the state exists, false otherwise
        // Example:
        // return m_pAnimationGraphState->CheckStateExistence(stateName);
    }
};
