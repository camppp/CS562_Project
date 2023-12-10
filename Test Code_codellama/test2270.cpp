#include <xchain/contract.h>

struct ShortContentDeposit : public ShortContentDepositBasic, public xchain::Contract {
    // ...

    virtual std::vector<ShortContent> queryByTitle(const std::string& title, const std::string& username) {
        // Implement query logic based on title
        // ...
    }

    virtual std::vector<ShortContent> queryByTopic(const std::string& topic, const std::string& username) {
        // Implement query logic based on topic
        // ...
    }
};
