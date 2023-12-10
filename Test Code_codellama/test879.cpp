template <typename RV>
RV unloadLibrary(HMODULE handle) {
    BOOL r = ::FreeLibrary(handle);
    return r ? RV() : BasicError::bad_system_call();
}
