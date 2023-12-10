BString BHttpResult::GetHeader(const BString& headerName) const {
    return fHeaders.GetHeader(headerName); // Assuming fHeaders has a method GetHeader to retrieve the value based on the header name
}
