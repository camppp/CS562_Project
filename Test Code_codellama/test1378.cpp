class CelestialBody
{
private:
    // Member variables
    int SpecialCelestialPointParamCount;

public:
    // Constructor
    CelestialBody(int celestialBodyParamCount)
    {
        SpecialCelestialPointParamCount = celestialBodyParamCount;
    }

    // Member functions
    void setSpecialCelestialPointParamCount(int count)
    {
        SpecialCelestialPointParamCount = count;
    }

    int getSpecialCelestialPointParamCount()
    {
        return SpecialCelestialPointParamCount;
    }
};
