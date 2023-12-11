#include <set>
#include <iostream>

class PersonTracker {
public:
    PersonTracker(const std::set<int>* initial_ids = nullptr) {
        if (initial_ids != nullptr) {
            id_set = *initial_ids;
        }
    }

    void updateIds(const std::set<int>* new_ids) {
        if (id_set != nullptr) {
            delete id_set;
        }
        id_set = new_ids;
    }

    void updatePersonCount(int numPeopleInFrame, int totalPersonIncrements) {
        if (numPeopleInFrame != prevPeopleInFrame || totalPersonIncrements != prevPeopleTotal) {
            people_changed = true;
        }
        prevPeopleInFrame = numPeopleInFrame;
        prevPeopleTotal = totalPersonIncrements;
    }

    void notifyListener() {
        if (m_module_listener != nullptr) {
            m_module_listener->on_person_tracking_finished(id_set, people_changed);
        }
    }

private:
    std::set<int>* id_set;
    int prevPeopleInFrame;
    int prevPeopleTotal;
    bool people_changed;
    ModuleListener* m_module_listener;
};
