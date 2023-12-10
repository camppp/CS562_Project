#include <stdexcept>
#include <string>
#include <memory>

class Connection
{
public:
    Connection() : m_impl{std::make_unique<Impl>()} {}
    
    void MakeRequest(const std::string& method, const std::string& request, std::move(pack)) {
        // Check if the connection is closed
        if (IsClosed()) {
            throw std::runtime_error("Connection is closed");
        }

        // Send the request
        m_impl->SendRequest(method, request, std::move(pack));
    }

    bool IsClosed() const {
        // Check if the connection is closed
        return m_impl->IsClosed();
    }

private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};
