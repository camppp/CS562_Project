class task_context {
private:
    int* m_pointer;

public:
    task_context(task_context&& rhs) noexcept : m_pointer(nullptr) {
        m_pointer = rhs.m_pointer;
        rhs.m_pointer = nullptr;
    }
};
