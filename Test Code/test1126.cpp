void processCascadingDecay(int m_vUomCascDcyBrP[], int iCascDcyBrCcP[][MAX_SIZE], int m_vVNCascDcyBrCcP[], int nCcPCascDcyBr[], bool m_ccSwitch, int m_vICcCompCascDcyBrP[], int nAllPCascDcyBr[], int nPCascDcyBr[], int j, int _iCascDcyBrP) {
    if (m_ccSwitch == true) {
        if (m_vICcCompCascDcyBrP[j] != 0) {
            nAllPCascDcyBr[j] = nPCascDcyBr[j] + nCcPCascDcyBr[j];
        }
    }

    if (j < MAX_SIZE) {
        if (m_vUomCascDcyBrP[j][strCascDcyBrP] == _iCascDcyBrP) {
            // Perform some operation based on the condition
        } else {
            iCascDcyBrCcP[j][(unsigned int)(nCcPCascDcyBr[j])] = _iCascDcyBrP;
            m_vVNCascDcyBrCcP[j][_iCascDcyBrP]++;
        }
        nCcPCascDcyBr[j]++;
    }
}
