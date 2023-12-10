#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

const std::string AUTH_CERT_PATH_ENV_NAME = "AUTH_CERT_PATH";
const std::string PROVISIONING_ENDPOINT_ENV_NAME = "PROVISIONING_ENDPOINT";
const std::string X_APIG_TOKEN_ENV_NAME = "X_APIG_TOKEN";

std::unordered_map<std::string, std::string> readConfigurationData() {
    std::unordered_map<std::string, std::string> configData;

    // Read the AUTH_CERT_PATH environment variable
    std::string authCertPath = getEnvOrExit(AUTH_CERT_PATH_ENV_NAME);
    configData[AUTH_CERT_PATH_ENV_NAME] = authCertPath;

    // Read the PROVISIONING_ENDPOINT environment variable
    std::string provisioningEndpoint = getEnvOrExit(PROVISIONING_ENDPOINT_ENV_NAME);
    configData[PROVISIONING_ENDPOINT_ENV_NAME] = provisioningEndpoint;

    // Read the X_APIG_TOKEN environment variable
    std::string xApiGToken = getEnvOrExit(X_APIG_TOKEN_ENV_NAME);
    configData[X_APIG_TOKEN_ENV_NAME] = xApiGToken;

    return configData;
}
