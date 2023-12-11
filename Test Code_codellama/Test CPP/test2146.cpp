SysErr GI::Sensor::Mpr121::write(unsigned char reg, unsigned char data) {
    // Check if the I2C interface is available
    if (!I2C::isAvailable()) {
        return SYS_ERR_NO_ASSIGNED_DEVICE;
    }

    // Construct a two-byte array containing the register and data
    unsigned char tmp[2] = {reg, data};

    // Write the bytes to the sensor at the address MPR121_ADDR | (IcNr & 0x03)
    if (I2C::write(MPR121_ADDR | (IcNr & 0x03), tmp, 2) != 0) {
        return SYS_ERR_BUS;
    }

    return SYS_ERR_OK;
}
