void ModuleEditor::ShowFbxList(const uint& i)
{
    for (uint j = 0; j < resourceManager->fbxList.size(); j++)
    {
        std::string fbxFileName = resourceManager->fbxList[j];
        // Process the FBX file using the index i and the name of the FBX file
        // Processing logic for each FBX file can be added here
        // For example:
        if (i == 5)
        {
            // Process the FBX file using index 5 and the name of the FBX file
            // ...
        }
    }
}
