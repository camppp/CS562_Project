def parse_data_packet(packet: bytes) -> List[float]:
    # Extract the 10-bit sensor readings from the data packet
    readings = []
    for i in range(len(packet) // 2):
        reading = packet[i * 2]
        reading = (reading << 8) | packet[i * 2 + 1]
        readings.append(reading >> 2)

    # Convert the 10-bit readings to voltage values
    voltages = []
    for reading in readings:
        voltage = reading * 0.1 / 1024
        voltages.append(voltage)

    return voltages