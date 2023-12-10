void HipServer::HandleReceive(const boost::system::error_code& error, std::size_t numBytes)
{
	if ((!error || error == boost::asio::error::message_size))
	{
		LOGGER_DEBUG("** HANDLING INCOMING HIP PACKET **");

		try
		{
			m_context.m_buffer = std::make_shared<ByteBlock>
				(m_buffer.begin(), m_buffer.begin() + numBytes);

			LOGGER_DEBUG("Received bytes: ", *m_context.m_buffer);

			m_context.m_packet = HipPacketPtr(new HipPacket(*m_context.m_buffer)); // Create a HipPacket from the received data

			// Process the HipPacket to extract relevant information
			std::string sourceAddress = m_context.m_packet->GetSourceAddress();
			std::string destinationAddress = m_context.m_packet->GetDestinationAddress();
			// Extract other relevant information as needed

			// Log the received HIP packet information
			LOGGER_DEBUG("Source Address: ", sourceAddress);
			LOGGER_DEBUG("Destination Address: ", destinationAddress);
			// Log other relevant information as needed
		}
		catch (const std::exception& e)
		{
			LOGGER_ERROR("Error handling incoming HIP packet: ", e.what());
		}
	}
}
