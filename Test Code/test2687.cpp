#include <iostream>
#include <cstring>

class currency {
public:
  void convert(const char* target_code, double amount) {
    double target_num = data::isonum2hash(target_code);
    double converted_amount = amount * (target_num / num_);
    converted_amount_ = converted_amount;
    std::strcpy(target_code_, target_code);
  }

  void display() {
    std::cout << "Currency Code: " << target_code_ << ", Amount: " << converted_amount_ << std::endl;
  }

  friend std::istream & operator >> (std::istream & is, currency & rhs);

private:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  void init(char const* code) {
    if (!data::code2isonum(code, &num_)) { num_ = ISO_XXX; }
  }

  double num_;
  char target_code_[4];
  double converted_amount_;
};
