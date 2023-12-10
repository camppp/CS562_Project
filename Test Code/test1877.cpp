// Clones the data structure with import and type declarations
DataStructure* CloneDataStructure(DataStructure* original) {
    DataStructure* clone = new DataStructure(); // Create a new instance for cloning

    // Clone import declarations
    clone->AllocateImportDeclarations(original->NumImportDeclarations());
    for (int i = 0; i < original->NumImportDeclarations(); i++) {
        clone->AddImportDeclaration((AstImportDeclaration*)original->ImportDeclaration(i)->Clone(ast_pool));
    }

    // Clone type declarations
    clone->AllocateTypeDeclarations(original->NumTypeDeclarations());
    for (int i = 0; i < original->NumTypeDeclarations(); i++) {
        clone->AddTypeDeclaration((TypeDeclaration*)original->GetTypeDeclaration(i)->Clone(ast_pool));
    }

    return clone; // Return the cloned data structure
}
