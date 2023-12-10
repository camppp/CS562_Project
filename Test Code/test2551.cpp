#include <string>

class AbstractEnumInterface {
public:
    virtual int getValue() const = 0;
    virtual std::string getName() const = 0;
};
