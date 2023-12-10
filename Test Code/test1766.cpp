#include <vector>
#include <stdexcept>

class SwVbaDocument : public SwVbaDocument_BASE
{
private:
    std::vector<css::uno::Reference<css::text::XTextDocument>> documents;

public:
    void addDocument(css::uno::Reference<css::text::XTextDocument> document) {
        documents.push_back(document);
    }

    void removeDocument(css::uno::Reference<css::text::XTextDocument> document) {
        auto it = std::find(documents.begin(), documents.end(), document);
        if (it != documents.end()) {
            documents.erase(it);
        }
    }

    size_t getDocumentCount() {
        return documents.size();
    }

    css::uno::Reference<css::text::XTextDocument> getDocumentAtIndex(size_t index) {
        if (index < documents.size()) {
            return documents[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    void performDocumentOperation(size_t index, int operationIdentifier) {
        if (index < documents.size()) {
            // Perform operation on the document at the given index
            // Code for performing the operation goes here
        } else {
            throw std::out_of_range("Index out of range");
        }
    }
};
