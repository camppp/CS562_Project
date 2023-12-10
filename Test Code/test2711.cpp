#include <so_5/all.hpp>

using namespace so_5;

// Define a ping message type
struct ping : public message_t {};

// Define a pong message type
struct pong : public message_t {};

// Implement the handling of the "ping" message in the ponger_t class
class ponger_t : public agent_t
{
public:
    ponger_t(environment_t & env) : agent_t(env) {}

    void so_define_agent() override
    {
        // Handle the "ping" message
        so_subscribe_self().event(&ponger_t::on_ping);
    }

    void so_evt_start() override
    {
        // Send a "ping" message to the ponger_t agent
        so_5::send<ping>(*this);
    }

private:
    void on_ping(mhood_t<ping>)
    {
        // Print "ping!" to the console
        std::cout << "ping!" << std::endl;

        // Send a "pong" message back to the sender
        so_5::send<pong>(*this);
    }
};
