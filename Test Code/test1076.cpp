#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

const std::string AUTH_CERT_PATH_ENV_NAME = "AUTH_CERT_PATH";
const std::string PROVISIONING_ENDPOINT_ENV_NAME = "PROVISIONING_ENDPOINT";
const std::string X_APIG_TOKEN_ENV_NAME = "X_APIG_TOKEN";

std::unordered_map<std::string, std::string> readConfigurationData() {
    std::unordered_map<std::string, std::string> configData;

    auto clientCertificatePath = getEnvOrExit(AUTH_CERT_PATH_ENV_NAME);
    auto provisioningEndpoint = getEnvOrExit(PROVISIONING_ENDPOINT_ENV_NAME);
    auto xApigToken = getEnvOrExit(X_APIG_TOKEN_ENV_NAME);

    configData[AUTH_CERT_PATH_ENV_NAME] = clientCertificatePath;
    configData[PROVISIONING_ENDPOINT_ENV_NAME] = provisioningEndpoint;
    configData[X_APIG_TOKEN_ENV_NAME] = xApigToken;

    return configData;
}
