DataStructure* CloneDataStructure(DataStructure* original) {
    DataStructure* clone = new DataStructure();

    // Allocate memory for import declarations
    AllocateImportDeclarations(clone, original->NumImportDeclarations());

    // Clone each import declaration
    for (int i = 0; i < original->NumImportDeclarations(); i++) {
        AstImportDeclaration* importDeclaration = original->GetImportDeclaration(i);
        AstImportDeclaration* clonedImportDeclaration = importDeclaration->Clone(ast_pool);
        clone->AddImportDeclaration(clonedImportDeclaration);
    }

    // Allocate memory for type declarations
    AllocateTypeDeclarations(clone, original->NumTypeDeclarations());

    // Clone each type declaration
    for (int i = 0; i < original->NumTypeDeclarations(); i++) {
        TypeDeclaration* typeDeclaration = original->GetTypeDeclaration(i);
        TypeDeclaration* clonedTypeDeclaration = typeDeclaration->Clone(ast_pool);
        clone->AddTypeDeclaration(clonedTypeDeclaration);
    }

    return clone;
}
