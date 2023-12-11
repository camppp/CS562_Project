#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using namespace std;

const int PORT = 8080;

class Server {
public:
  Server(io_context& io_context) : acceptor_(io_context, ip::tcp::endpoint(ip::tcp::v4(), PORT)) {
    do_accept();
  }

  void do_accept() {
    acceptor_.async_accept(
      [this](boost::system::error_code ec, ip::tcp::socket socket) {
        if (!ec) {
          std::cout << "New connection from " << socket.remote_endpoint() << std::endl;
          do_read(socket);
        }
      }
    );
  }

  void do_read(ip::tcp::socket& socket) {
    boost::asio::async_read(
      socket,
      boost::asio::buffer(read_buffer_),
      [this, &socket](boost::system::error_code ec, std::size_t bytes_transferred) {
        if (!ec) {
          std::cout << "Received message: " << read_buffer_ << std::endl;
          do_write(socket, read_buffer_);
        }
      }
    );
  }

  void do_write(ip::tcp::socket& socket, const std::string& message) {
    boost::asio::async_write(
      socket,
      boost::asio::buffer(message),
      [this, &socket](boost::system::error_code ec, std::size_t bytes_transferred) {
        if (!ec) {
          std::cout << "Sent message: " << message << std::endl;
          do_read(socket);
        }
      }
    );
  }

private:
  ip::tcp::acceptor acceptor_;
  std::array<char, 1024> read_buffer_;
};

int main() {
  io_context io_context;
  Server server(io_context);
  io_context.run();
  return 0;
}
