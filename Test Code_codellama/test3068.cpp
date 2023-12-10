#include <iostream>
#include <string>

class alertManager {
public:
    // Constructor
    alertManager() {
        ticker = 0;
    }

    // Dismiss an alert
    void dismiss(std::string alert) {
        // Implement dismissal logic here
        std::cout << "Dismissing alert: " << alert << std::endl;
    }

    // Increment the ticker
    void incrementTicker() {
        ticker++;
    }

private:
    // Ticker variable
    int ticker;
};
