#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;

class TCPServer {
public:
    TCPServer(io_service& io_service, short port)
        : acceptor_(io_service, ip::tcp::endpoint(ip::tcp::v4(), port)),
          socket_(io_service) {
        startAccept();
    }

private:
    void startAccept() {
        acceptor_.async_accept(socket_,
            [this](boost::system::error_code ec) {
                if (!ec) {
                    std::cout << "Client connected: " << socket_.remote_endpoint() << std::endl;
                    startRead();
                }
                startAccept();
            });
    }

    void startRead() {
        async_read(socket_, buffer(data_),
            [this](boost::system::error_code ec, std::size_t length) {
                if (!ec) {
                    std::cout << "Received message from client: " << data_ << std::endl;
                    startWrite(length);
                }
            });
    }

    void startWrite(std::size_t length) {
        async_write(socket_, buffer(data_, length),
            [this](boost::system::error_code ec, std::size_t /*length*/) {
                if (!ec) {
                    startRead();
                }
            });
    }

    ip::tcp::acceptor acceptor_;
    ip::tcp::socket socket_;
    std::string data_;
};

int main() {
    try {
        io_service io_service;
        TCPServer server(io_service, 12345);
        io_service.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
