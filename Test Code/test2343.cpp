void UdpClient::ExclusiveAddressUse(bool value) {
    int optionValue = value ? 1 : 0;
    if (setsockopt(socketDescriptor, SOL_SOCKET, SO_REUSEADDR, &optionValue, sizeof(optionValue)) < 0) {
        // Handle error: failed to set exclusive address use option
        // You can throw an exception, log an error, or handle it based on the application's requirements
    }
}
