#include <SFML/Graphics.hpp>

class Camera2D {
private:
    sf::RenderTargetPtr m_pRenderTarget;
    sf::View m_view;

public:
    Camera2D(sf::RenderTargetPtr renderTarget, float frustrumWidth, float frustrumHeight)
        : m_pRenderTarget(renderTarget) {
        m_view = m_pRenderTarget->getView();
        m_view.setViewport(sf::FloatRect(0, 0, frustrumWidth, frustrumHeight));
        resize(m_pRenderTarget->getSize());
        updateTarget();
    }

    void updateTarget() {
        m_pRenderTarget->setView(m_view);
    }

    void resize(sf::Vector2u size) {
        m_view.setSize(static_cast<float>(size.x), static_cast<float>(size.y));
    }
};
