#include <pugixml.hpp>
#include <string>
#include <vector>

struct Product {
    std::string name;
    double price;
};

std::vector<Product> extractProductInfo(const std::string& xmlData) {
    std::vector<Product> products;

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(xmlData.c_str());

    if (result.status == pugi::status_ok) {
        // Iterate over all <product> tags in the document
        for (pugi::xml_node productNode : doc.select_nodes("//product")) {
            // Extract the name and price of the current product
            std::string name = productNode.child("name").text().as_string();
            double price = std::stod(productNode.child("price").text().as_string());

            // Add the product to the data structure
            products.push_back({name, price});
        }
    }

    return products;
}
