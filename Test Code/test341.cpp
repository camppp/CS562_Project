#include <iostream>
#include <string>

class Query {
public:
    void bind(int index, const std::string& value) {
        // Implementation of bind function
        std::cout << "Binding parameter " << index << " to value: " << value << std::endl;
        // Actual binding logic would go here
    }
};

int main() {
    Query query;
    std::string sideDatabasePath = "example.db";
    query.bind(1, sideDatabasePath);
    return 0;
}
