#include <string>
#include <exception>

class CustomError : public std::exception {
public:
  CustomError(const std::string& error_table, const std::string& error_column)
      : error_table_(error_table), error_column_(error_column) {}

  std::string formatErrorMessage() {
    return "Error in table " + error_table_ + " at column " + error_column_;
  }

  virtual const char* what() const throw() {
    return formatErrorMessage().c_str();
  }

private:
  std::string error_table_;
  std::string error_column_;
};
