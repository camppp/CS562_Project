#include <iostream>
#include <string>

class BISModule {
public:
    BISModule() {
        // Initialize allowable responses
        allowableResponses = { "1", "2", "3", "4" };
        // Set questionnaire name
        questionnaireName = "BIS BAS";
    }

    ~BISModule() {
        // Destroy questionnaire
        questionnaireName = "";
    }

    void handleUserResponse(std::string response) {
        // Check if response is allowable
        if (allowableResponses.find(response) != allowableResponses.end()) {
            // Handle response
            handleAllowableResponse(response);
        } else {
            // Handle invalid response
            handleInvalidResponse(response);
        }
    }

    void handleAllowableResponse(std::string response) {
        // Handle allowable response
        switch (response) {
            case "1":
                // Handle response 1
                break;
            case "2":
                // Handle response 2
                break;
            case "3":
                // Handle response 3
                break;
            case "4":
                // Handle response 4
                break;
            default:
                // Handle invalid response
                handleInvalidResponse(response);
                break;
        }
    }

    void handleInvalidResponse(std::string response) {
        // Handle invalid response
        std::cout << "Invalid response: " << response << std::endl;
    }

private:
    std::set<std::string> allowableResponses;
    std::string questionnaireName;
};
