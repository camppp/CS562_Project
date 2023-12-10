// Custom iterator class for iterating over declarations within a scope
class ScopeDeclarationIterator {
private:
    UTL_Scope* scope;
    size_t currentIndex;

public:
    // Constructor to initialize the iterator with the given scope
    ScopeDeclarationIterator(UTL_Scope* s) : scope(s), currentIndex(0) {}

    // Method to check if the iteration is complete
    bool is_done() {
        return currentIndex >= scope->get_declaration_count();
    }

    // Method to retrieve the current declaration item
    AST_Decl* item() {
        if (is_done()) {
            return nullptr; // Return null if iteration is complete
        }
        return scope->get_declaration_at(currentIndex);
    }

    // Method to move to the next declaration item
    void next() {
        currentIndex++;
    }
};

// Usage example
UTL_Scope* s = (UTL_Scope*)narrow((long) & UTL_Scope::type_id);
if (s) {
    ScopeDeclarationIterator* iterator = new ScopeDeclarationIterator(s);
    while (!iterator->is_done()) {
        AST_Decl* currentDeclaration = iterator->item();
        // Process the current declaration
        iterator->next(); // Move to the next declaration
    }
    delete iterator; // Clean up the iterator
}
