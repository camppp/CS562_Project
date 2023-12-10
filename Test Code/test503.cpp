PVOID RuntimeLoader::GetFunctionAddress(LPCSTR funcName)
{
    PVOID address = NULL;
    const auto iter = funcs.find(funcName);
    if (iter != funcs.end()) {
        address = iter->second;
    }
    return address;
}
