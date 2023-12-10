std::set<ParameterableElement*> parameterableElements() const override {
    std::set<ParameterableElement*> result;
    for (auto& ownedElement : ownedElements()) {
        if (ownedElement->isParameterable()) {
            result.insert(ownedElement);
        }
    }
    return result;
}
