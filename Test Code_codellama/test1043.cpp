void processFontAsset(pugi::xml_document& m_doc, const std::string& m_name, const std::string& m_path, AssetManager& acc)
{
    // Check if the font information has already been precompiled
    if (mark_progress(PRECOMPILED))
    {
        // If so, return early
        return;
    }

    // Extract font information from the XML document
    pugi::xml_node fontNode = m_doc.child("font");
    std::string fontName = fontNode.child_value("name");
    std::string fontPath = fontNode.child_value("path");

    // Create an asset for the game engine
    acc.m_assets.createFont(fontName, fontPath);
}
