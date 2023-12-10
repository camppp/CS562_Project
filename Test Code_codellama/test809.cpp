class CSGPseudoPrimitive : public SBase {
public:
    // Constructor
    CSGPseudoPrimitive(const string& name, const string& symbol, const string& description) : SBase(name, symbol, description) {}

    // Override writeElements method
    void writeElements(ostream& out) const override {
        out << "PseudoPrimitive: " << getName() << endl;
        out << "Symbol: " << getSymbol() << endl;
        out << "Description: " << getDescription() << endl;
    }

    // Override writeExtensionElements method
    void writeExtensionElements(ostream& out) const override {
        out << "PseudoPrimitive: " << getName() << endl;
        out << "Symbol: " << getSymbol() << endl;
        out << "Description: " << getDescription() << endl;
    }

    // Define any necessary attributes and methods specific to the CSGPseudoPrimitive class
    string getPseudoPrimitiveType() const { return "PseudoPrimitive"; }
    void setPseudoPrimitiveType(const string& type) { pseudoPrimitiveType = type; }

private:
    string pseudoPrimitiveType;
};
