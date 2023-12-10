#include <iostream>
#include <fstream>
#include "../third_party/json.hpp"

using json = nlohmann::json;

int main() {
    std::ifstream file("books.json");
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open the JSON file." << std::endl;
        return 1;
    }

    json bookData;
    try {
        file >> bookData;
    } catch (json::parse_error& e) {
        std::cerr << "Error: Invalid JSON format - " << e.what() << std::endl;
        return 1;
    }

    if (!bookData.contains("books")) {
        std::cerr << "Error: Invalid JSON format - 'books' key not found." << std::endl;
        return 1;
    }

    const auto& books = bookData["books"];
    std::cout << "Total number of books: " << books.size() << std::endl;

    std::string authorName;
    std::cout << "Enter author's name to list their books: ";
    std::cin >> authorName;

    std::cout << "Books by " << authorName << ":" << std::endl;
    for (const auto& book : books) {
        if (book["author"] == authorName) {
            std::cout << "- " << book["title"] << std::endl;
        }
    }

    auto oldestBook = *std::min_element(books.begin(), books.end(), 
        [](const auto& a, const auto& b) {
            return a["publication_year"] < b["publication_year"];
        }
    );
    std::cout << "Oldest book: " << oldestBook["title"] << std::endl;

    return 0;
}
