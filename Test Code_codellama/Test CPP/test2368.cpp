class Param {
public:
    Param(const string& name, unsigned int type, float value)
        : name(name), type(type), value(value) {}

    void SetValue(float v) {
        value = v;
    }

    float GetValue() const {
        return value;
    }

private:
    string name;
    unsigned int type;
    float value;
};
