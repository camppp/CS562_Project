ThreadData* findThreadByScriptName(ThreadArray* threadArray, const char* name) {
    int i = 0;
    ThreadData* ret = NULL;
    while (i < MAX_THREADS) {
        if (threadArray->pData[i] != NULL && threadArray->pData[i]->m_iThreadID) {
            if (strcmp(threadArray->pData[i]->m_szScriptName, name) == 0) {
                ret = threadArray->pData[i];
                break;
            }
        }
        ++i;
    }
    return ret;
}
