template<typename String>
void bind(const String& host, unsigned port, std::error_code& ec) noexcept
{
    // Convert the host parameter to a C-style string using the string_traits class
    const char* host_cstr = detail::string_traits<String>::to_c_string(host);

    // Call the binder function with the converted host, port, and error code
    binder(host_cstr, port, ec);
}
