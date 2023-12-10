// Implementation of JavascriptSIMDUint8x16::New method
JavascriptSIMDUint8x16* JavascriptSIMDUint8x16::New(const uint8_t* value, ScriptContext* requestContext)
{
    return RecyclerNew(requestContext->GetRecycler(), JavascriptSIMDUint8x16, value);
}

// Implementation of JavascriptSIMDUint8x16::GetFullBuiltinName method
const char16* JavascriptSIMDUint8x16::GetFullBuiltinName(char16** aBuffer, const char16* name)
{
    Assert(aBuffer && *aBuffer);
    swprintf_s(*aBuffer, SIMD_STRING_BUFFER_MAX, _u("SIMD.Uint8x16.%s"), name);
    return *aBuffer;
}

// Implementation of JavascriptSIMDUint8x16::Copy method
Var JavascriptSIMDUint8x16::Copy(ScriptContext* requestContext)
{
    return JavascriptSIMDUint8x16::New(this->value, requestContext);
}
