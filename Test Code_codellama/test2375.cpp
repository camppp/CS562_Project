void manageResource(void* resource)
{
    SAFE_RELEASE(resource);
    resource = nullptr;
}
