ThreadData* findThreadByScriptName(ThreadArray* threadArray, const char* name) {
    for (int i = 0; i < MAX_THREADS; i++) {
        if (strcmp(threadArray->pData[i]->m_szScriptName, name) == 0) {
            return threadArray->pData[i];
        }
    }
    return NULL;
}
