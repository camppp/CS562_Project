#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  // Open the JSON file
  std::ifstream file("books.json");
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file" << std::endl;
    return 1;
  }

  // Parse the JSON data
  json data;
  file >> data;
  if (file.fail()) {
    std::cerr << "Error: Could not parse JSON data" << std::endl;
    return 1;
  }

  // Calculate the total number of books
  int total_books = data["books"].size();
  std::cout << "Total number of books: " << total_books << std::endl;

  // Accept user input for an author's name
  std::string author_name;
  std::cout << "Enter an author's name: ";
  std::cin >> author_name;

  // Output a list of books written by that author
  json books_by_author = data["books"].find(author_name);
  if (books_by_author.is_array()) {
    for (const auto& book : books_by_author) {
      std::cout << book["title"] << " by " << book["author"] << std::endl;
    }
  } else {
    std::cout << "No books found by that author" << std::endl;
  }

  // Identify and output the title of the oldest book
  json oldest_book = data["books"].find(data["books"].begin(), data["books"].end(), [](const json& book) {
    return book["publication_year"] == data["books"].begin()->["publication_year"];
  });
  if (oldest_book.is_object()) {
    std::cout << "Oldest book: " << oldest_book["title"] << std::endl;
  } else {
    std::cout << "No books found" << std::endl;
  }

  return 0;
}
