class task_context {
private:
    int* m_pointer;

public:
    task_context(task_context&& rhs) noexcept : m_pointer(nullptr) {
        m_pointer = rhs.m_pointer;  // Transfer ownership of m_pointer
        rhs.m_pointer = nullptr;    // Set m_pointer of rhs to nullptr
    }
};
