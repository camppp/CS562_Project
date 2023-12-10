c
void configureSPIMaster(SercomSpi *spi) {
    // Disable the SPI module
    spi->CTRLA &= ~SERCOM_SPI_CTRLA_ENABLE;

    // Wait for synchronization
    while (spi->SYNCBUSY & SERCOM_SPI_SYNCBUSY_ENABLE) {
        // Do nothing
    }

    // Set the mode to SPI master
    spi->CTRLA |= SERCOM_SPI_CTRLA_MODE_MASTER;
}
