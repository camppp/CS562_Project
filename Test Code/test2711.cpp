#include <so_5/all.hpp>

// Define the ping message type
struct ping : public so_5::message_t {};

// Define the pong message type
struct pong : public so_5::message_t {};

class ponger_t : public so_5::agent_t {
public:
    ponger_t(so_5::environment_t& env) : so_5::agent_t(env) {
        // Subscribe to handle incoming ping messages
        so_subscribe_self().event([this](const so_5::mhood_t<ping>&) {
            std::cout << "ping!" << std::endl;
            // Send a pong message back to the sender
            so_5::send<pong>(*this);
        });
    }
};

int main() {
    so_5::launch([](so_5::environment_t& env) {
        // Create an instance of the ponger agent
        env.introduce_coop([](so_5::coop_t& coop) {
            coop.make_agent<ponger_t>();
        });
    });

    return 0;
}
