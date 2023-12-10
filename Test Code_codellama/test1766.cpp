#include <vector>
#include <memory>
#include <string>

class SwVbaDocument_BASE {
public:
    virtual ~SwVbaDocument_BASE() = default;

    virtual void addDocument(const css::uno::Reference<css::text::XTextDocument>& document) = 0;
    virtual void removeDocument(const css::uno::Reference<css::text::XTextDocument>& document) = 0;
    virtual size_t getDocumentCount() const = 0;
    virtual css::uno::Reference<css::text::XTextDocument> getDocumentAtIndex(size_t index) const = 0;
    virtual void performDocumentOperation(size_t index, const std::string& operation) = 0;
};

class SwVbaDocument : public SwVbaDocument_BASE {
private:
    std::vector<css::uno::Reference<css::text::XTextDocument>> mxTextDocuments;

public:
    SwVbaDocument() = default;
    ~SwVbaDocument() override = default;

    void addDocument(const css::uno::Reference<css::text::XTextDocument>& document) override {
        mxTextDocuments.push_back(document);
    }

    void removeDocument(const css::uno::Reference<css::text::XTextDocument>& document) override {
        auto it = std::find(mxTextDocuments.begin(), mxTextDocuments.end(), document);
        if (it != mxTextDocuments.end()) {
            mxTextDocuments.erase(it);
        }
    }

    size_t getDocumentCount() const override {
        return mxTextDocuments.size();
    }

    css::uno::Reference<css::text::XTextDocument> getDocumentAtIndex(size_t index) const override {
        if (index >= mxTextDocuments.size()) {
            throw std::out_of_range("Index out of range");
        }
        return mxTextDocuments[index];
    }

    void performDocumentOperation(size_t index, const std::string& operation) override {
        if (index >= mxTextDocuments.size()) {
            throw std::out_of_range("Index out of range");
        }
        // Perform the operation on the document at the given index
    }
};
