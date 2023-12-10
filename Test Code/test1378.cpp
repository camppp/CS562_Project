class CelestialBody {
public:
    // Constructor
    CelestialBody(int paramCount) : CelestialBodyParamCount(paramCount), SpecialCelestialPointParamCount(paramCount) {}

    // Method to retrieve the parameter count
    int getParameterCount() const {
        return CelestialBodyParamCount;
    }

    // Method to set the parameter count
    void setParameterCount(int count) {
        CelestialBodyParamCount = count;
    }

    // Method to retrieve the special celestial point parameter count
    int getSpecialParameterCount() const {
        return SpecialCelestialPointParamCount;
    }

private:
    int CelestialBodyParamCount; // Member variable to store the parameter count
    int SpecialCelestialPointParamCount; // Member variable to store the special celestial point parameter count
};
