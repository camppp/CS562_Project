#include <iostream>
#include <string>
#include <google/protobuf/arena.h>

using namespace PROTOBUF_NAMESPACE_ID;

class LocaleMessage {
 public:
  // Constructor
  LocaleMessage(const std::string& locale) : locale_(locale) {}

  // Destructor
  ~LocaleMessage() {}

  // Setter function for error messages in different locales
  void SetErrorMessage(const std::string& locale, const std::string& message) {
    // Use the provided Arena to allocate memory for the error message
    Arena* arena = Arena::Create<std::string>(locale, message);
    // Store the error message in the map
    error_messages_[locale] = arena;
  }

  // Getter function for error messages in different locales
  std::string GetErrorMessage(const std::string& locale) {
    // Check if the error message exists for the given locale
    if (error_messages_.find(locale) == error_messages_.end()) {
      // If not, return an empty string
      return "";
    }
    // Return the error message for the given locale
    return error_messages_[locale]->Get<std::string>();
  }

  // Copy constructor
  LocaleMessage(const LocaleMessage& other) {
    // Copy the locale from the other object
    locale_ = other.locale_;
    // Copy the error messages from the other object
    for (const auto& [locale, message] : other.error_messages_) {
      // Use the provided Arena to allocate memory for the error message
      Arena* arena = Arena::Create<std::string>(locale, message);
      // Store the error message in the map
      error_messages_[locale] = arena;
    }
  }

  // Copy assignment operator
  LocaleMessage& operator=(const LocaleMessage& other) {
    // Check if the other object is the same as this object
    if (this == &other) {
      // If so, return a reference to this object
      return *this;
    }
    // Copy the locale from the other object
    locale_ = other.locale_;
    // Clear the error messages map
    error_messages_.clear();
    // Copy the error messages from the other object
    for (const auto& [locale, message] : other.error_messages_) {
      // Use the provided Arena to allocate memory for the error message
      Arena* arena = Arena::Create<std::string>(locale, message);
      // Store the error message in the map
      error_messages_[locale] = arena;
    }
    // Return a reference to this object
    return *this;
  }

 private:
  // Map to store error messages in different locales
  std::map<std::string, Arena*> error_messages_;
  // Locale of the error messages
  std::string locale_;
};
