#include <iostream>
#include <string>
#include <json/json.h>

class InsertValue {
public:
    InsertValue(const std::string& columnName, const Json::Value& jsonDocument)
        : m_columnName(columnName), m_jsonDocument(jsonDocument) {
    }

    std::string insertValue() {
        // Insert the JSON document into the specified column
        // ...

        // Convert the resulting JSON object to a string
        return m_jsonDocument.toStyledString();
    }

private:
    std::string m_columnName;
    Json::Value m_jsonDocument;
};
