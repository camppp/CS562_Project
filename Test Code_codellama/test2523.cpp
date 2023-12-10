#include <iostream>

class AAFlyingBug {
public:
    void SetExternallyControlled(bool isExternallyControlled) {
        externallyControlled = isExternallyControlled;
    }

    void SetAttackStance(bool isAttackStance) {
        attackStance = isAttackStance;
    }

    // Other methods and members can be added as needed

private:
    bool externallyControlled;
    bool attackStance;
};
