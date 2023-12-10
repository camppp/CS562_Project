#include <iostream>
#include <cstdint>

class CQuadratureCounter_TIM4 {
public:
    static CQuadratureCounter_TIM4& getInstance() {
        static CQuadratureCounter_TIM4 instance;
        return instance;
    }

    void reset() {
        // Reset the position to zero
        position = 0;
    }

    uint32_t getCount() {
        return position;
    }

private:
    CQuadratureCounter_TIM4() {}

    uint32_t position = 0;
};
