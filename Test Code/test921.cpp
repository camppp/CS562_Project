void configureSPIMaster(SercomSpi *spi) {
    // Disable SERCOM to switch its role
    spi->CTRLA.bit.ENABLE = 0;
    SYNCBUSY_WAIT(spi, SERCOM_SPI_SYNCBUSY_ENABLE);  // Wait for synchronization

    // Set SERCOM to SPI Master mode
    spi->CTRLA.reg |= SERCOM_SPI_CTRLA_MODE(0x3);
}
