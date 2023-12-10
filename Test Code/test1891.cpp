#include <iostream>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

class InsertValue {
private:
    std::string columnName;
    Document jsonDocument;

public:
    InsertValue(const std::string& column, const Document& doc) : columnName(column), jsonDocument(doc) {}

    std::string toJSON() const {
        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        writer.StartObject();
        writer.Key(columnName.c_str());
        jsonDocument.Accept(writer);
        writer.EndObject();
        return buffer.GetString();
    }
};

int main() {
    std::string expected("\"c1\" : {\"hello\":\"world\"}");

    Document doc;
    doc.Parse("{\"hello\":\"world\"}");
    InsertValue value("c1", doc);
    std::string result = value.toJSON();

    if (result.compare(expected) == 0) {
        std::cout << "Conversion to JSON string matches the expected value." << std::endl;
    } else {
        std::cout << "Conversion to JSON string does not match the expected value." << std::endl;
    }

    return 0;
}
