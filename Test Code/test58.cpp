bool IsDuplicateThemeName(const CStringA& strThemeName, CustomTree* pProjTree) {
    // Initialize a flag to track duplicate theme names
    bool isDuplicate = false;

    // Get the handle to the themes node in the project tree
    HDMTREEITEM hThemes = pProjTree->m_hProjThemes;

    // Get the handle to the first child node of the themes node
    HDMTREEITEM hChild = pProjTree->GetChildItem(hThemes);

    // Iterate through the child nodes to check for duplicate theme names
    while (hChild) {
        // Get the data associated with the current child node
        DMXmlNodePtr pChildNode = (DMXmlNodePtr)pProjTree->GetItemData(hChild);

        // Extract the theme name from the child node data
        CStringA strOtherThemeName = pChildNode->Attribute(XML_NAME);

        // Compare the new theme name with the theme name from the current child node
        if (0 == strOtherThemeName.CompareNoCase(strThemeName)) {
            // Set the flag to true if a duplicate theme name is found
            isDuplicate = true;
            break;  // Exit the loop as soon as a duplicate is found
        }

        // Move to the next child node
        hChild = pProjTree->GetNextSiblingItem(hChild);
    }

    // Return the flag indicating whether a duplicate theme name was found
    return isDuplicate;
}
