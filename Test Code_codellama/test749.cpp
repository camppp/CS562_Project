#include <ace/Task.h>
#include <ace/Reactor.h>

class ReactorTask : public ACE_Task<ACE_MT_SYNCH> {
public:
    int svc() {
        // Initialize the ACE Reactor and run its event loop
        ACE_Reactor::instance()->owner(ACE_Thread::self());
        ACE_Reactor::instance()->run_reactor_event_loop();
        return 0;
    }
};
