std::string generateMesh(const std::string& celltype) {
    Teuchos::RCP<panzer_stk::STK_MeshFactory> mesh_factory;

    if (celltype == "Hex") {
        mesh_factory = Teuchos::rcp(new panzer_stk::CubeHexMeshFactory);
        // Additional steps for mesh construction can be added here
        return "Hex mesh successfully created";
    } else if (celltype == "Tet") {
        mesh_factory = Teuchos::rcp(new panzer_stk::CubeTetMeshFactory);
        // Additional steps for mesh construction can be added here
        return "Tet mesh successfully created";
    } else {
        throw std::runtime_error("Unsupported cell type: try Hex or Tet");
    }
}
