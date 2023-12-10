#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class SFMLTextureAtlasData {
public:
    // Constructor
    SFMLTextureAtlasData(const std::string& textureAtlasPath);

    // Destructor
    ~SFMLTextureAtlasData();

    // Load texture atlas data from file
    void loadTextureAtlasData(const std::string& textureAtlasPath);

    // Retrieve texture region for a given texture name
    sf::IntRect getTextureRegion(const std::string& textureName);

    // Clear texture atlas data
    void clearTextureAtlasData();

private:
    // Texture atlas data
    std::vector<sf::IntRect> textureRegions;
    std::vector<std::string> textureNames;
    std::string textureAtlasPath;
};

// Constructor
SFMLTextureAtlasData::SFMLTextureAtlasData(const std::string& textureAtlasPath) {
    this->textureAtlasPath = textureAtlasPath;
}

// Destructor
SFMLTextureAtlasData::~SFMLTextureAtlasData() {
    clearTextureAtlasData();
}

// Load texture atlas data from file
void SFMLTextureAtlasData::loadTextureAtlasData(const std::string& textureAtlasPath) {
    // Load texture atlas data from file
    sf::Texture textureAtlas;
    textureAtlas.loadFromFile(textureAtlasPath);

    // Get the number of textures in the atlas
    int numTextures = textureAtlas.getNumberOfTextures();

    // Loop through each texture and add it to the texture regions vector
    for (int i = 0; i < numTextures; i++) {
        // Get the texture region for the current texture
        sf::IntRect textureRegion = textureAtlas.getTextureRegion(i);

        // Add the texture region to the vector
        textureRegions.push_back(textureRegion);

        // Add the texture name to the vector
        textureNames.push_back(textureAtlas.getTextureName(i));
    }
}

// Retrieve texture region for a given texture name
sf::IntRect SFMLTextureAtlasData::getTextureRegion(const std::string& textureName) {
    // Find the index of the texture with the given name
    int index = -1;
    for (int i = 0; i < textureNames.size(); i++) {
        if (textureNames[i] == textureName) {
            index = i;
            break;
        }
    }

    // Return the texture region for the given texture name
    if (index != -1) {
        return textureRegions[index];
    } else {
        return sf::IntRect();
    }
}

// Clear texture atlas data
void SFMLTextureAtlasData::clearTextureAtlasData() {
    textureRegions.clear();
    textureNames.clear();
}
