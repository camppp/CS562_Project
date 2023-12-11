class ListVisitor : public PathVisitor {
public:
    void visitFile(const File& file) override {
        std::cout << file.getName() << std::endl;
    }

    void visitDirectory(const Directory& directory) override {
        std::cout << directory.getName() << std::endl;
    }
};

class SearchVisitor : public PathVisitor {
public:
    SearchVisitor(const std::string& searchTerm) : searchTerm_(searchTerm) {}

    void visitFile(const File& file) override {
        if (file.getName().find(searchTerm_) != std::string::npos) {
            std::cout << file.getName() << std::endl;
        }
    }

    void visitDirectory(const Directory& directory) override {
        if (directory.getName().find(searchTerm_) != std::string::npos) {
            std::cout << directory.getName() << std::endl;
        }
    }

private:
    std::string searchTerm_;
};
