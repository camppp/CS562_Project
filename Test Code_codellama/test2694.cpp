#include <iostream>
#include <string>

// Function to generate a subscriber ID
std::string tatp_getSubscriberId(int threadId) {
  // Generate a random subscriber ID
  std::string subscriberId = "subscriber" + std::to_string(threadId);
  return subscriberId;
}

// Class to represent a TATP query
class tatp_query {
 public:
  // Constructor
  tatp_query(int threadId) {
    // Set the transaction type to GetSubscriberData
    transactionType = "GetSubscriberData";

    // Populate the arguments for the query
    subscriberId = tatp_getSubscriberId(threadId);
  }

  // Function to generate a subscriber data query
  std::string gen_get_subscriber_data() {
    // Return the query string
    return "SELECT * FROM subscribers WHERE subscriber_id = '" + subscriberId + "'";
  }

 private:
  // Transaction type
  std::string transactionType;

  // Subscriber ID
  std::string subscriberId;
};

int main() {
  // Create a new tatp_query object
  tatp_query query(1);

  // Generate a subscriber data query
  std::string queryString = query.gen_get_subscriber_data();

  // Print the query string
  std::cout << "Query string: " << queryString << std::endl;

  return 0;
}
