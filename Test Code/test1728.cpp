void editFirstModbusRequestAndResponsePackets(PcapFileReaderDevice *reader, PcapFileWriterDevice *writer) {
    bool foundRequest = false;
    bool foundResponse = false;

    // Iterate through the packets in the input PCAP file
    while (true) {
        RawPacket rawPacket;
        if (!reader->getNextPacket(rawPacket)) {
            // No more packets in the input PCAP file
            break;
        }

        // Parse the packet to identify Modbus request and response packets
        ModbusPacket modbusPacket = parseModbusPacket(rawPacket);

        if (modbusPacket.type == ModbusPacketType::Request && !foundRequest) {
            // Modify the first Modbus request packet
            modifyModbusRequest(modbusPacket);
            foundRequest = true;
        } else if (modbusPacket.type == ModbusPacketType::Response && !foundResponse) {
            // Modify the first Modbus response packet
            modifyModbusResponse(modbusPacket);
            foundResponse = true;
        }

        // Write the modified or unmodified packet to the output PCAP file
        writer->writePacket(rawPacket);
    }

    if (!foundRequest || !foundResponse) {
        // No Modbus request or response packets found in the input PCAP file
        EXIT_WITH_ERROR("No Modbus request or response packets found");
    }
}
