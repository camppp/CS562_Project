int pMR::Backend::getLocalNumProcesses()
{
    int numProcesses;

    if (MPI_Comm_size(getLocalCommunicator(), &numProcesses) != MPI_SUCCESS)
    {
        throw std::runtime_error(
            "pMR: Unable to get local communicator size");
    }

    return numProcesses;
}
