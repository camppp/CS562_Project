#include <ace/Task.h>
#include <ace/Reactor.h>

class ReactorTask : public ACE_Task<ACE_MT_SYNCH> {
public:
	int svc() {
		ACE_Reactor::instance()->owner(ACE_Thread::self());
		ACE_Reactor::instance()->run_reactor_event_loop();
		return 0;
	}
};

int main() {
	ReactorTask reactorTask;
	reactorTask.activate();
	reactorTask.wait();
	return 0;
}
