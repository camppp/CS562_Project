class Simulator {
public:
    void DetachSim() {
        // Implementation of DetachSim method in Simulator class
    }
};

class Body {
private:
    Simulator* m_BodyRef;

public:
    void DetachSim() {
        if (m_BodyRef) {
            m_BodyRef->DetachSim();
        }
    }
};
