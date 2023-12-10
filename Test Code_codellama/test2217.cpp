class SimpleString {
  public:
    SimpleString(const char* str) : p_(str) {}

    int length() const {
        return strlen(p_);
    }

    char at(int index) const {
        return p_[index];
    }

    SimpleString operator+(const SimpleString& other) const {
        SimpleString result;
        result.p_ = new char[strlen(p_) + strlen(other.p_) + 1];
        strcpy(result.p_, p_);
        strcat(result.p_, other.p_);
        return result;
    }

  private:
    const char* p_;
};
