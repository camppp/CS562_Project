class DeclarationIterator {
public:
    DeclarationIterator(Scope* scope) : scope_(scope) {}

    bool hasNext() {
        return scope_->hasNext();
    }

    Declaration* next() {
        return scope_->next();
    }

    bool isComplete() {
        return !hasNext();
    }

    Declaration* current() {
        return scope_->current();
    }

private:
    Scope* scope_;
};
