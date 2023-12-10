void serverUnflattenDecode(const void* pData, size_t dataSize, void* pClient, uint32_t payloadCount, void* pPayloads) {
    // Perform error checks
    if (pData == NULL || dataSize == 0 || pClient == NULL || payloadCount == 0 || pPayloads == NULL) {
        return;
    }

    // Decode the parameters
    pg_param_decode_params* params = (pg_param_decode_params*)pData;
    params->client = pClient;
    params->payloadCount = payloadCount;
    params->payloads = pPayloads;

    // Check if the client statistics handle is valid
    if (params->clientStatsHandle == NULL) {
        return;
    }

    // Unflatten the payloads
    for (uint32_t i = 0; i < payloadCount; i++) {
        pg_payload* payload = (pg_payload*)pPayloads;
        payload->payload = params->payloads[i];
        payload->payloadSize = params->payloadSizes[i];
        payload->payloadType = params->payloadTypes[i];
    }

    // Return the decoded parameters
    return params;
}
