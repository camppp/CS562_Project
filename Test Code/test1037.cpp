void ActivateModuleAndCPV(int moduleNumber, bool fActiveModule[], bool fActiveCPV[]) {
    if (moduleNumber >= 0 && moduleNumber < 6) {
        fActiveModule[moduleNumber] = true;
        fActiveCPV[moduleNumber] = true;
    }
}
