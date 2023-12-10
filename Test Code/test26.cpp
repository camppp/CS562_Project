__in ULONG_PTR AsmHandler,
__in ULONG_PTR AsmHandlerEnd)
{
    ASSERT(AsmHandlerEnd > AsmHandler);
    SIZE_T asmHandlerSize = AsmHandlerEnd - AsmHandler;

    ULONG_PTR pattern = 0xffffffffffffffff;

    for (ULONG_PTR* ptr = (ULONG_PTR*)AsmHandler; ptr < (ULONG_PTR*)AsmHandlerEnd; ptr++) {
        if (*ptr == pattern) {
            return (ULONG_PTR)ptr;
        }
    }

    return NULL;  // Pattern not found
}
