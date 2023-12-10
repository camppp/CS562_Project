#include <string>
#include <iostream>

class MongoRequestHandler {
public:
    // Constructor
    MongoRequestHandler(bool needsMerge, bool allowDiskUse, bool bypassDocumentValidation,
                        const std::string& ns, const std::string& collation,
                        const std::string& ownedCollator, const std::string& resolvedNamespaces)
        : needsMerge(needsMerge), allowDiskUse(allowDiskUse), bypassDocumentValidation(bypassDocumentValidation),
          ns(ns), collation(collation), ownedCollator(ownedCollator), resolvedNamespaces(resolvedNamespaces) {}

    // Properties
    bool needsMerge;
    bool allowDiskUse;
    bool bypassDocumentValidation;
    std::string ns;
    std::string collation;
    std::string ownedCollator;
    std::string resolvedNamespaces;

    // Methods
    bool needsMerge() { return needsMerge; }
    bool shouldAllowDiskUse() { return allowDiskUse; }
    bool shouldBypassDocumentValidation() { return bypassDocumentValidation; }
    std::string getNamespaceString() { return ns; }
    std::string getCollation() { return collation; }
    void setProcessInterface(const std::string& processInterface) { this->mongoProcessInterface = processInterface; }
    void setCollator(const std::string& collator) { this->ownedCollator = collator; }
    void setResolvedNamespaces(const std::string& resolvedNamespaces) { this->resolvedNamespaces = resolvedNamespaces; }
};
