class CDM {
public:
    CDM(Private* private) : m_private(private) {}

    bool supportsInitData(InitDataType initDataType, const InitData& initData) {
        return m_private->supportsInitData(initDataType, initData);
    }

    RefPtr<SharedBuffer> sanitizeResponse(const SharedBuffer& response) {
        return m_private->sanitizeResponse(response);
    }

private:
    Private* m_private;
};
