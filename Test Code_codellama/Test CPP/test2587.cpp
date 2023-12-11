class RequestCacheManager {
private:
    RequestCachePolicy* m_Policy;
    RequestCache m_RequestCache;

public:
    RequestCacheManager() {
        m_Policy = nullptr;
    }

    void SetRequestCachePolicy(RequestCachePolicy* policy) {
        m_Policy = policy;
    }
};
