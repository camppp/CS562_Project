#include <mpi.h>

namespace pMR {

class Backend {
public:
    int getLocalNumProcesses() {
        MPI_Comm localComm = getLocalCommunicator();
        int numProcesses = 0;
        MPI_Comm_size(localComm, &numProcesses);
        return numProcesses;
    }

private:
    MPI_Comm getLocalCommunicator() {
        // Implementation of the getLocalCommunicator function
        // is assumed to be provided in the larger codebase
        // for the parallel message passing library called pMR.
    }
};

} // namespace pMR
