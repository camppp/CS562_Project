#include <exception>
#include <boost/exception.hpp>

class my_exception : public std::exception {
public:
    my_exception(const std::string& message) : std::exception(message) {}
};

class my_exception2 : public std::exception, public boost::exception {
public:
    my_exception2(const std::string& message) : std::exception(message), boost::exception(message) {}
};
