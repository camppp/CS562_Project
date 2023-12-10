#include <thread>
#include <unordered_map>

class CThreadLocalStorage
{
public:
    CThreadLocalStorage() : m_tlsMap() {}

    ~CThreadLocalStorage()
    {
        for (auto& pair : m_tlsMap)
        {
            delete pair.second;
        }
    }

    template <typename T>
    void Set(T* value)
    {
        std::thread::id this_id = std::this_thread::get_id();
        m_tlsMap[this_id] = value;
    }

    template <typename T>
    T* Get()
    {
        std::thread::id this_id = std::this_thread::get_id();
        auto it = m_tlsMap.find(this_id);
        if (it != m_tlsMap.end())
        {
            return static_cast<T*>(it->second);
        }
        return nullptr;
    }

private:
    std::unordered_map<std::thread::id, void*> m_tlsMap;
};
