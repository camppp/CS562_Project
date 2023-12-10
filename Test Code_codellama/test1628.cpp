void HipServer::HandleReceive(const boost::system::error_code& error, std::size_t numBytes)
{
    // Check if there is no error or if the error is related to the message size
    if (!error || error.message().find("message size") != std::string::npos)
    {
        // Create a ByteBlock from the received data
        ByteBlock byteBlock(numBytes);

        // Create a HipPacketPtr from the received data
        HipPacketPtr hipPacketPtr(byteBlock);

        // Create a HipPacket object from the HipPacketPtr
        HipPacket hipPacket(hipPacketPtr);

        // Process the HipPacket to extract relevant information
        // ...

        // Log the received HIP packet information using the provided LOGGER_DEBUG function
        LOGGER_DEBUG("Received HIP packet: " + hipPacket.ToString());
    }
}
