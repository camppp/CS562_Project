#include <exception>
#include <boost/exception/exception.hpp>

class my_exception : public std::exception
{
    // Custom implementation for my_exception
};

class my_exception2 : public std::exception, public boost::exception
{
    // Custom implementation for my_exception2
};
