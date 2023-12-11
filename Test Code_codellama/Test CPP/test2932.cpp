#include <iostream>
#include <string>
#include <cstdint>

class WelcomeNotificationPreferenceManager {
 public:
  // Setters
  void setWelcomeNotificationDismissed(bool dismissed) {
    dismissed_ = dismissed;
  }

  void setWelcomeNotificationDismissedLocal(bool dismissedLocal) {
    dismissedLocal_ = dismissedLocal;
  }

  void setWelcomeNotificationPreviouslyPoppedUp(bool previouslyPoppedUp) {
    previouslyPoppedUp_ = previouslyPoppedUp;
  }

  void setWelcomeNotificationExpirationTimestamp(long expirationTimestamp) {
    expirationTimestamp_ = expirationTimestamp;
  }

  // Getters
  bool getWelcomeNotificationDismissed() {
    return dismissed_;
  }

  bool getWelcomeNotificationDismissedLocal() {
    return dismissedLocal_;
  }

  bool getWelcomeNotificationPreviouslyPoppedUp() {
    return previouslyPoppedUp_;
  }

  long getWelcomeNotificationExpirationTimestamp() {
    return expirationTimestamp_;
  }

 private:
  bool dismissed_ = false;
  bool dismissedLocal_ = false;
  bool previouslyPoppedUp_ = false;
  long expirationTimestamp_ = 0;
};
