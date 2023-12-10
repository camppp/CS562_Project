bool addMaterialToScene(aiScene* scene, int index, Material newMaterial) {
    if (index >= 0 && index < scene->mNumMaterials) {
        // Shift existing materials to make space for the new material
        for (int i = scene->mNumMaterials - 1; i >= index; i--) {
            scene->mMaterials[i + 1] = scene->mMaterials[i];
        }
        // Add the new material at the specified index
        scene->mMaterials[index] = newMaterial;
        scene->mNumMaterials++;  // Increment the total number of materials in the scene
        return true;  // Material added successfully
    }
    return false;  // Index is out of range
}
