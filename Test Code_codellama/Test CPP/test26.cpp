c
ULONG_PTR FindPattern(ULONG_PTR AsmHandler, ULONG_PTR AsmHandlerEnd, ULONG_PTR pattern)
{
    ASSERT(AsmHandlerEnd > AsmHandler);
    SIZE_T asmHandlerSize = AsmHandlerEnd - AsmHandler;

    for (ULONG_PTR i = AsmHandler; i < AsmHandlerEnd; i++)
    {
        if (*(ULONG_PTR*)i == pattern)
        {
            return i;
        }
    }

    return NULL;
}
