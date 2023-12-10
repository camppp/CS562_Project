namespace uilib
{
    class AnimEffectAction
    {
    public:
        AnimEffectAction();
        void setSprite(Sprite* sprite);

    private:
        Sprite* m_animSprite;
    };

    AnimEffectAction::AnimEffectAction()
    {
        m_animSprite = 0;
    }

    void AnimEffectAction::setSprite(Sprite* sprite)
    {
        m_animSprite = sprite;
    }
}
