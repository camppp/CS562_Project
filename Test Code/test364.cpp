#include <stdexcept>
#include <string>
#include <memory>

class Connection
{
public:
    Connection() : m_impl{std::make_unique<Impl>()} {}
    
    void MakeRequest(const std::string& method, const std::string& request, /* missing parameter */) {
        if (!m_impl)
            throw std::runtime_error{"[Connection::MakeRequest] Connection is closed."};
        m_impl->MakeRequest(method, request, std::move(pack));
    }

    bool IsClosed() const {
        return !m_impl;
    }

private:
    struct Impl {
        void MakeRequest(const std::string& method, const std::string& request, /* missing parameter */) {
            // Implementation of MakeRequest method
        }
    };
    std::unique_ptr<Impl> m_impl;
};
