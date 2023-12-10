class ProductionLine {
private:
    int _startY;
    Line& _line;
    shared_ptr<FactoryState> _factoryState;

public:
    ProductionLine(int startY, Line& line, shared_ptr<FactoryState> factoryState);
    void updateFactoryState(shared_ptr<FactoryState> newFactoryState);
};
