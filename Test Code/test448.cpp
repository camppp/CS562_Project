#include <iostream>
#include <set>

class PersonTracker {
private:
    std::set<int>* id_set;
    int lastPersonCount;
    int prevPeopleInFrame;
    int prevPeopleTotal;
    bool people_changed;
    ModuleListener* m_module_listener;  // Assuming ModuleListener is a defined class

public:
    PersonTracker() : id_set(nullptr), lastPersonCount(0), prevPeopleInFrame(0), prevPeopleTotal(0), people_changed(false), m_module_listener(nullptr) {}

    ~PersonTracker() {
        delete id_set;
    }

    void updateIds(const std::set<int>* new_ids) {
        if (id_set != nullptr) {
            delete id_set;
        }
        id_set = new std::set<int>(*new_ids);
    }

    void updatePersonCount(int numPeopleInFrame, int totalPersonIncrements) {
        if (numPeopleInFrame != prevPeopleInFrame || totalPersonIncrements != prevPeopleTotal) {
            prevPeopleInFrame = numPeopleInFrame;
            prevPeopleTotal = totalPersonIncrements;
            people_changed = true;
        } else {
            people_changed = false;
        }
    }

    void notifyListener() {
        if (m_module_listener != nullptr) {
            m_module_listener->on_person_tracking_finished(*id_set, people_changed);
        }
    }
};
