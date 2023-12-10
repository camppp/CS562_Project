#include <iostream>
#include <string>

class MagicMonster {
private:
    std::string name;
    int powerLevel;
    static int activeMonsters;

public:
    MagicMonster(const std::string& monsterName, int level) : name(monsterName), powerLevel(level) {
        activeMonsters++;
    }

    ~MagicMonster() {
        std::cout << "Magical monster " << name << " with power level " << powerLevel << " is being destroyed." << std::endl;
        activeMonsters--;
    }

    static int getActiveMonsters() {
        return activeMonsters;
    }
};

int MagicMonster::activeMonsters = 0;

int main() {
    MagicMonster monster1("Gandalf", 100);
    MagicMonster monster2("Merlin", 150);

    std::cout << "Active magical monsters: " << MagicMonster::getActiveMonsters() << std::endl;

    return 0;
}
