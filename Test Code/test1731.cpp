std::string PathImpl::homeImpl()
{
    std::string result;
    if (EnvironmentImpl::hasImpl("USERPROFILE"))
    {
        result = EnvironmentImpl::getImpl("USERPROFILE");
    }
    else if (EnvironmentImpl::hasImpl("HOMEDRIVE") && EnvironmentImpl::hasImpl("HOMEPATH"))
    {
        result = EnvironmentImpl::getImpl("HOMEDRIVE") + EnvironmentImpl::getImpl("HOMEPATH");
    }
    return result;
}
