#include <iostream>
#include <string>
#include <vector>

class CryptoHandler {
public:
    CryptoHandler(const std::string& cryptoPluginName, const std::string& key, const std::string& blockMode, const std::string& padding, const std::string& authenticationData, const std::vector<std::string>& customParameters)
        : m_cryptoPluginName(cryptoPluginName), m_key(key), m_blockMode(blockMode), m_padding(padding), m_authenticationData(authenticationData), m_customParameters(customParameters) {}

    std::string encrypt(const std::string& plaintext) {
        // Load the cryptographic plugin
        auto plugin = loadPlugin(m_cryptoPluginName);

        // Set the encryption parameters
        plugin->setKey(m_key);
        plugin->setBlockMode(m_blockMode);
        plugin->setPadding(m_padding);
        plugin->setAuthenticationData(m_authenticationData);
        plugin->setCustomParameters(m_customParameters);

        // Encrypt the plaintext
        auto ciphertext = plugin->encrypt(plaintext);

        // Check for errors
        if (plugin->hasError()) {
            std::cout << "Error: " << plugin->getErrorMessage() << std::endl;
            return "";
        }

        return ciphertext;
    }

    std::string decrypt(const std::string& ciphertext) {
        // Load the cryptographic plugin
        auto plugin = loadPlugin(m_cryptoPluginName);

        // Set the decryption parameters
        plugin->setKey(m_key);
        plugin->setBlockMode(m_blockMode);
        plugin->setPadding(m_padding);
        plugin->setAuthenticationData(m_authenticationData);
        plugin->setCustomParameters(m_customParameters);

        // Decrypt the ciphertext
        auto plaintext = plugin->decrypt(ciphertext);

        // Check for errors
        if (plugin->hasError()) {
            std::cout << "Error: " << plugin->getErrorMessage() << std::endl;
            return "";
        }

        return plaintext;
    }

private:
    std::string m_cryptoPluginName;
    std::string m_key;
    std::string m_blockMode;
    std::string m_padding;
    std::string m_authenticationData;
    std::vector<std::string> m_customParameters;

    // Load the cryptographic plugin
    std::shared_ptr<CryptoPlugin> loadPlugin(const std::string& pluginName) {
        // Load the plugin using the plugin manager
        auto pluginManager = std::make_shared<PluginManager>();
        auto plugin = pluginManager->loadPlugin(pluginName);

        // Check for errors
        if (!plugin) {
            std::cout << "Error: Failed to load plugin " << pluginName << std::endl;
            return nullptr;
        }

        return plugin;
    }
};
