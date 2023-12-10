#include "IAnimationGraphState.h"

class CMannequinAGExistanceQuery
{
public:
    CMannequinAGExistanceQuery(IAnimationGraphState* pAnimationGraphState)
    {
        m_pAnimationGraphState = pAnimationGraphState;
        assert(m_pAnimationGraphState != nullptr);
    }

    bool Exists()
    {
        return m_pAnimationGraphState->Exists();
    }

private:
    IAnimationGraphState* m_pAnimationGraphState;
};
