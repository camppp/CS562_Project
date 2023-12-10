ULONG readFromFileStream(void* _pv, ULONG _cb) {
    try {
        this->mRstream.read(static_cast<char *>(_pv), _cb);
        return static_cast<ULONG>(this->mRstream.gcount());
    }
    catch (const std::ios_base::failure &) {
        return STG_E_ACCESSDENIED;
    }
    catch (const std::bad_alloc &) {
        return STG_E_OUTOFMEMORY;
    }
}
