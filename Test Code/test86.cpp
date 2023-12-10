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
        for (pugi::xml_node productNode : doc.select_nodes("//product")) {
            Product product;
            product.name = productNode.child_value("name");
            product.price = std::stod(productNode.child_value("price"));
            products.push_back(product);
        }
    }

    return products;
}
