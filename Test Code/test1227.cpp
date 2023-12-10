void MaterialManager::destroyResource(Resource& resource)
{
    Material* material = static_cast<Material*>(&resource);
    
    // Release any resources associated with the material
    material->releaseResources();

    // Remove the material from internal data structures
    // Assuming m_materials is a container holding the materials
    auto it = std::find(m_materials.begin(), m_materials.end(), material);
    if (it != m_materials.end()) {
        m_materials.erase(it);
    }

    // Deallocate the memory for the material
    m_allocator.deleteObject(material);
}
