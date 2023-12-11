bool IsDuplicateThemeName(const CStringA& strThemeName, CustomTree* pProjTree) {
    // Check if the current node's theme name is the same as the new theme name
    if (pProjTree->GetThemeName() == strThemeName) {
        return true;
    }

    // Recursively check the children of the current node
    for (int i = 0; i < pProjTree->GetNumChildren(); i++) {
        if (IsDuplicateThemeName(strThemeName, pProjTree->GetChild(i))) {
            return true;
        }
    }

    // If no duplicate is found, return false
    return false;
}