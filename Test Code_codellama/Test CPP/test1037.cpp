void ActivateModuleAndCPV(int moduleNumber, bool fActiveModule[], bool fActiveCPV[]) {
    if (moduleNumber < 0 || moduleNumber > 5) {
        return;
    }
    fActiveModule[moduleNumber] = true;
    fActiveCPV[moduleNumber] = true;
}
