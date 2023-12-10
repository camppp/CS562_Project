class Particle {
public:
    Particle() {
        initializeProperties();
    }

    void initializeProperties() {
        m_direction = vec2(RandomFloat(0.0f, 1.0f), RandomFloat(0.0f, 1.0f));
        m_alphaDelta = RandomFloat(0.0f, 1.0f);
        m_sizeDelta = RandomFloat(0.0f, 1.0f);
        m_rotationDelta = RandomFloat(0.0f, 1.0f);
    }

    vec2 m_direction;
    float m_alphaDelta;
    float m_sizeDelta;
    float m_rotationDelta;
};
