BString BHttpResult::GetHeader(const BString& headerName) const
{
    // Check if the header exists in the fHeaders object
    if (fHeaders.HasHeader(headerName)) {
        // Return the value of the header
        return fHeaders.GetHeader(headerName);
    } else {
        // Return an empty string if the header is not found
        return "";
    }
}
