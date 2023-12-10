bool IPCIntelPGParam::serverUnflattenDecode(void* pData, int dataSize, uintptr_t* client,
                                            int32_t* payloadCount, ia_binary_data** payloads) {
    // Check for null pointer in pData
    CheckError(!pData, false, "@%s, pData is nullptr", __func__);

    // Check if the size of the data is smaller than the size of pg_param_decode_params
    CheckError(dataSize < sizeof(pg_param_decode_params), false, "@%s, size is small", __func__);

    // Check for null client pointer
    CheckError(!client, false, "@%s, nullptr client", __func__);

    // Check for null payloadCount pointer
    CheckError(!payloadCount, false, "%s, payloadCount is nullptr", __func__);

    // Cast pData to pg_param_decode_params pointer
    pg_param_decode_params* params = static_cast<pg_param_decode_params*>(pData);

    // Assign client pointer to the client field in params
    *client = params->client;

    // Assign payloadCount pointer to the payloadCount field in params
    *payloadCount = params->payloadCount;

    // Copy payloads from params to the provided payloads pointer
    *payloads = new ia_binary_data[params->payloadCount];
    for (int i = 0; i < params->payloadCount; i++) {
        (*payloads)[i] = params->payloads[i];
    }

    // Assign statsHandle to the clientStatsHandle field in params
    // Assuming statsHandle is a member variable or a global variable
    params->clientStatsHandle = statsHandle;

    return true;
}
