#include <iostream>

enum SysErr {
    SYS_ERR_OK,
    SYS_ERR_NO_ASSIGNED_DEVICE,
    SYS_ERR_BUS
};

class I2C {
public:
    int writeBytes(unsigned char address, unsigned char* data, int length) {
        // Implementation of writeBytes method
        // Return the number of bytes written or -1 on failure
        return 0;  // Placeholder return value
    }
};

class GI {
public:
    class Sensor {
    public:
        class Mpr121 {
        public:
            I2C* I2C;
            unsigned char IcNr;
            const unsigned char MPR121_ADDR = 0x5A;

            SysErr write(unsigned char reg, unsigned char data) {
                if (!I2C)
                    return SYS_ERR_NO_ASSIGNED_DEVICE;
                unsigned char tmp[2];
                tmp[0] = reg;
                tmp[1] = data;
                if (I2C->writeBytes(MPR121_ADDR | (IcNr & 0x03), tmp, 2) != 2)
                    return SYS_ERR_BUS;
                return SYS_ERR_OK;
            }
        };
    };
};

int main() {
    // Usage example
    GI::Sensor::Mpr121 sensor;
    I2C i2c;
    sensor.I2C = &i2c;
    sensor.IcNr = 0x01;
    SysErr result = sensor.write(0x10, 0x55);
    if (result == SYS_ERR_OK) {
        std::cout << "Write operation successful" << std::endl;
    } else {
        std::cout << "Write operation failed" << std::endl;
    }
    return 0;
}
