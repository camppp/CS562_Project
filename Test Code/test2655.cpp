#include "WindowManager.h" // Include necessary header file for WindowManager
#include "SkillCheck.h" // Include necessary header file for SkillCheck

class SkillCheckManager {
public:
    void draw(WindowManager& window) {
        m_sc.drawBars(window); // Call drawBars method of SkillCheck object m_sc
    }

private:
    SkillCheck m_sc; // SkillCheck object member variable
};
