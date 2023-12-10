void processFontAsset(pugi::xml_document& m_doc, const std::string& m_name, const std::string& m_path, AssetManager& acc) {
    if (mark_progress(PRECOMPILED)) return;  // Check if font information has been precompiled

    // Access the game engine's asset manager to add the font asset
    asset::AssetFont* af = acc.m_assets->add_asset<asset::AssetFont>(m_name.c_str());
    af->m_path = m_path;  // Set the font file path for the asset

    pugi::xml_node node_font = m_doc.child("font");  // Access the font node in the XML document

    // Extract font information from the XML node and process as needed
    // Example: Extract font properties like size, style, etc., and set them for the font asset

    // Create the font asset in the game engine using the extracted information
    // Example: Set the font properties for the asset and finalize the asset creation
}
