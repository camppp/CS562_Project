#include <iostream>
#include <exception>
#include <string>
#include <sstream>

class CustomError : public std::exception {
public:
  CustomError(const std::string& error_table, const std::string& error_column)
      : error_table_(error_table), error_column_(error_column) {}

  std::string formatErrorMessage() {
    std::stringstream ss;
    ss << "Error in table: " << error_table_ << ", column: " << error_column_;
    return ss.str();
  }

  virtual const char* what() const throw() {
    return formatErrorMessage().c_str();
  }

private:
  std::string error_table_;
  std::string error_column_;
};

int main() {
  try {
    throw CustomError("Table1", "Column5");
  } catch (const std::exception& e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
  }
  return 0;
}
