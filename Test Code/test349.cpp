void CmdStatusResponse::updateStatus(const MasaNetStatus& newStatus)
{
    // Update the network status information in the CmdStatusResponse object
    status = newStatus;
}
