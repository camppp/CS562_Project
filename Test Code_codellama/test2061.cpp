#include <SFML/Graphics.hpp>

class Camera2D {
public:
    Camera2D(sf::RenderTargetPtr renderTarget, float frustrumWidth, float frustrumHeight) {
        m_pRenderTarget = renderTarget;
        m_view.setSize(frustrumWidth, frustrumHeight);
        m_view.setCenter(frustrumWidth / 2, frustrumHeight / 2);
        m_view.setViewport(sf::FloatRect(0, 0, 1, 1));
    }

    void updateTarget() {
        m_pRenderTarget->setView(m_view);
    }

    void resize(sf::Vector2u size) {
        m_view.setSize(size.x, size.y);
        m_view.setCenter(size.x / 2, size.y / 2);
        m_view.setViewport(sf::FloatRect(0, 0, 1, 1));
    }

private:
    sf::RenderTargetPtr m_pRenderTarget;
    sf::View m_view;
};
