#include "IInputReceiver.h" // Assuming the header file for IInputReceiver is included

class engine_impl {
public:
    engine_impl() : m_input_receiver(nullptr), m_input_captured(false) {}

    void setInputReceiver(IInputReceiver* inputReceiver) {
        m_input_receiver = inputReceiver;
    }

    void captureInput() {
        m_input_captured = true;
    }

    void releaseInput() {
        m_input_captured = false;
    }

    void notifyInputEvent(InputEvent event) {
        if (m_input_receiver) {
            m_input_receiver->onInputEvent(event);
        }
    }

private:
    IInputReceiver* m_input_receiver;
    bool m_input_captured;
};
