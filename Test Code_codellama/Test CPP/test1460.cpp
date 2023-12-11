#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/json/JsonValue.h>

class InitiateVaultLockResult
{
public:
    InitiateVaultLockResult() {}

    InitiateVaultLockResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
    {
        // Set the result based on the JsonValue
        if (result.IsSuccess())
        {
            // Parse the JsonValue and set the member variables
            JsonValue jsonValue = result.GetPayload();
            // Set the status
            m_status = jsonValue.GetString("Status");
            // Set the error messages
            m_errorMessages = jsonValue.GetArray("ErrorMessages");
        }
        else
        {
            // Set the error message
            m_errorMessage = result.GetError().GetMessage();
        }
    }

    // Getters and setters for the member variables
    const std::string& GetStatus() const { return m_status; }
    void SetStatus(const std::string& status) { m_status = status; }

    const std::vector<std::string>& GetErrorMessages() const { return m_errorMessages; }
    void SetErrorMessages(const std::vector<std::string>& errorMessages) { m_errorMessages = errorMessages; }

    const std::string& GetErrorMessage() const { return m_errorMessage; }
    void SetErrorMessage(const std::string& errorMessage) { m_errorMessage = errorMessage; }

private:
    std::string m_status;
    std::vector<std::string> m_errorMessages;
    std::string m_errorMessage;
};
