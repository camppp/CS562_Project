if (condition)
{
    // code
}
else
{
    XLOGD("Error: Flicker parameters not found");
    return -1;
}

XLOGD("Flicker parameters found");
return 0;
