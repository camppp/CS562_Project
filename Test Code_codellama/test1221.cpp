template <typename T>
class CustomSharedPtr
{
public:
    // Constructor
    CustomSharedPtr(T* ptr) : m_ptr(ptr), m_refCount(new int(1)) {}

    // Copy constructor
    CustomSharedPtr(const CustomSharedPtr<T>& other) : m_ptr(other.m_ptr), m_refCount(other.m_refCount)
    {
        (*m_refCount)++;
    }

    // Destructor
    ~CustomSharedPtr()
    {
        (*m_refCount)--;
        if (*m_refCount == 0)
        {
            delete m_ptr;
            delete m_refCount;
        }
    }

    // Assignment operator
    CustomSharedPtr<T>& operator=(const CustomSharedPtr<T>& other)
    {
        if (this != &other)
        {
            (*m_refCount)--;
            if (*m_refCount == 0)
            {
                delete m_ptr;
                delete m_refCount;
            }
            m_ptr = other.m_ptr;
            m_refCount = other.m_refCount;
            (*m_refCount)++;
        }
        return *this;
    }

    // Dereferencing operator
    T& operator*() const
    {
        return *m_ptr;
    }

    // Member access operator
    T* operator->() const
    {
        return m_ptr;
    }

private:
    T* m_ptr;
    int* m_refCount;
};
