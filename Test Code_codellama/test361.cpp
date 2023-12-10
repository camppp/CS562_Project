#include "IInputReceiver.h"

class engine_impl
{
public:
    engine_impl() : m_input_captured(false), m_input_receiver(nullptr) {}

    void captureInput()
    {
        m_input_captured = true;
    }

    void releaseInput()
    {
        m_input_captured = false;
    }

    void notifyInputEvent(const InputEvent& event)
    {
        if (m_input_receiver)
        {
            m_input_receiver->onInputEvent(event);
        }
    }

private:
    bool m_input_captured;
    IInputReceiver* m_input_receiver;
};
