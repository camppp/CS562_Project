class SkillCheckManager {
public:
    void draw(WindowManager& windowManager) {
        m_sc.drawBars(windowManager);
    }

private:
    SkillCheck m_sc;
};
