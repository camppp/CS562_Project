#include <aws/core/utils/json/JsonSerializer.h>

class InitiateVaultLockResult {
private:
    // Member variables to store the result data
    bool success;
    std::string errorMessage;

public:
    // Default constructor
    InitiateVaultLockResult() : success(false), errorMessage("") {}

    // Constructor that takes an Aws::AmazonWebServiceResult<JsonValue> as a parameter
    InitiateVaultLockResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result) {
        *this = result;
    }

    // Method to set the result based on the Aws::AmazonWebServiceResult<JsonValue> parameter
    void operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result) {
        if (result.IsSuccess()) {
            success = true;
            errorMessage = "";
        } else {
            success = false;
            errorMessage = "Error: " + result.GetError().GetMessage();
        }
    }

    // Additional methods or member variables necessary to handle the result of initiating a vault lock
    bool isSuccess() const {
        return success;
    }

    std::string getErrorMessage() const {
        return errorMessage;
    }
};
