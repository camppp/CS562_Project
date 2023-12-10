bool IsDuplicateThemeName(const CStringA& strThemeName, CustomTree* pProjTree)
{
    // Iterate through the project tree to check for duplicate theme names
    for (CustomTree* pNode = pProjTree; pNode != nullptr; pNode = pNode->GetNext())
    {
        // Check if the current node's theme name is the same as the new theme name
        if (pNode->GetThemeName() == strThemeName)
        {
            // If a duplicate is found, return true
            return true;
        }
    }

    // If no duplicate is found, return false
    return false;
}
