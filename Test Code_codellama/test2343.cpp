void UDPClient::ExclusiveAddressUse(bool value)
{
    // Check if the exclusive address use option is already set
    if (m_ExclusiveAddressUse != value)
    {
        // Set the exclusive address use option
        m_ExclusiveAddressUse = value;

        // Update the socket options
        if (m_ExclusiveAddressUse)
        {
            // Set the SO_REUSEADDR option to 0 to prevent other processes from binding to the same address and port
            int optval = 0;
            setsockopt(m_Socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
        }
        else
        {
            // Set the SO_REUSEADDR option to 1 to allow other processes to bind to the same address and port
            int optval = 1;
            setsockopt(m_Socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
        }
    }
}
