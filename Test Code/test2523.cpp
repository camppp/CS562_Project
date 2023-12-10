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

int main() {
    AAFlyingBug bug;
    bug.SetExternallyControlled(true);
    bug.SetAttackStance(false);

    std::cout << "Externally Controlled: " << bug.externallyControlled << std::endl;
    std::cout << "Attack Stance: " << bug.attackStance << std::endl;

    return 0;
}
