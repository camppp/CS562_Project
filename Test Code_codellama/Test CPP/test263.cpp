c
long long RetrieveExpirationTime(void* Context, int GetExpirationTime)
{
    // Check if the GetExpirationTime flag is set to TRUE
    if (GetExpirationTime)
    {
        // Retrieve the expiration time from the context
        long long expirationTime = ((MyContext*)Context)->expirationTime;

        // Return the expiration time
        return expirationTime;
    }
    else
    {
        // Return a message indicating that the expiration time is not requested
        return "Expiration time not requested";
    }
}
