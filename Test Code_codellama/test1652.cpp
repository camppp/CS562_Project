bool addMaterialToScene(aiScene* scene, int index, Material newMaterial)
{
    // Check if the index is within the valid range of materials in the scene
    if (index >= 0 && index < scene->mNumMaterials)
    {
        // Add the new material at the specified index in the scene
        scene->mMaterials[index] = newMaterial;
        return true;
    }
    else
    {
        return false;
    }
}
