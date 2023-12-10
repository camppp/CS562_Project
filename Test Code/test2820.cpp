#include <memory>

// Define the Line and FactoryState classes if not already defined
class Line {};
class FactoryState {};

class ProductionLine {
private:
    const int _startY;
    const Line& _line;
    std::shared_ptr<const FactoryState> _factoryState;

public:
    ProductionLine(int startY, const Line& line, std::shared_ptr<const FactoryState> factoryState)
        : _startY(startY), _line(line), _factoryState(factoryState) {}

    void updateFactoryState(std::shared_ptr<const FactoryState> newFactoryState) {
        _factoryState = newFactoryState;
    }
};
