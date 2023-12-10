class ConfigManager {
private:
    unsigned int maxUAVBarriers;
    unsigned int maxShaderArguments;
    unsigned int maxShaderSamplers;

public:
    ConfigManager() {
        maxUAVBarriers = 0;
        maxShaderArguments = 0;
        maxShaderSamplers = 0;
    }

    unsigned int getMaxUAVBarriers() {
        return maxUAVBarriers;
    }

    unsigned int getMaxShaderArguments() {
        return maxShaderArguments;
    }

    unsigned int getMaxShaderSamplers() {
        return maxShaderSamplers;
    }

    void updateMaxUAVBarriers(unsigned int newMaxUAVBarriers) {
        if (newMaxUAVBarriers > 0) {
            maxUAVBarriers = newMaxUAVBarriers;
        }
    }

    void updateMaxShaderArguments(unsigned int newMaxShaderArguments) {
        if (newMaxShaderArguments > 0) {
            maxShaderArguments = newMaxShaderArguments;
        }
    }

    void updateMaxShaderSamplers(unsigned int newMaxShaderSamplers) {
        if (newMaxShaderSamplers > 0) {
            maxShaderSamplers = newMaxShaderSamplers;
        }
    }
};
