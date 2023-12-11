LPVOID ConvertToCallback(CLRTYPE clrValue)
{
    // Check if the CLRTYPE is a managed delegate
    if (clrValue.IsManagedDelegate())
    {
        // Get the managed delegate object
        ManagedDelegate* delegate = clrValue.GetManagedDelegate();

        // Get the unmanaged function pointer from the managed delegate
        LPVOID unmanagedFunctionPointer = delegate->GetUnmanagedFunctionPointer();

        // Return the unmanaged function pointer
        return unmanagedFunctionPointer;
    }
    else
    {
        // The CLRTYPE is not a managed delegate, return nullptr
        return nullptr;
    }
}
