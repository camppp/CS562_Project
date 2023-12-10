#include "SFMLTextureData.h"

DRAGONBONES_NAMESPACE_BEGIN

class SFMLTextureAtlasData
{
private:
    // Member variables to store texture atlas data
    std::map<std::string, sf::Texture> textures; // Map to store textures with their paths
    std::map<std::string, sf::IntRect> textureRegions; // Map to store texture regions with their names

public:
    SFMLTextureAtlasData()
    {
        _onClear();
    }

    ~SFMLTextureAtlasData()
    {
        _onClear();
    }

    // Method to load texture atlas data from files
    void loadTexture(const std::string& path, const std::string& name)
    {
        sf::Texture texture;
        if (texture.loadFromFile(path))
        {
            textures[name] = texture;
        }
    }

    // Method to retrieve texture region
    sf::IntRect getTextureRegion(const std::string& regionName)
    {
        if (textureRegions.find(regionName) != textureRegions.end())
        {
            return textureRegions[regionName];
        }
        else
        {
            // Handle error or return default region
            return sf::IntRect(0, 0, 0, 0);
        }
    }

    // Method to clear the texture atlas data
    void _onClear()
    {
        textures.clear();
        textureRegions.clear();
    }
};

DRAGONBONES_NAMESPACE_END
