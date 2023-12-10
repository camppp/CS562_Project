#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

class DataBranch {
public:
    std::unordered_map<std::string, std::string> data;
    std::vector<DataBranch> children;

    void addData(const std::string& key, const std::string& value) {
        data[key] = value;
    }

    void addChild(const DataBranch& child) {
        children.push_back(child);
    }
};

class JsonParser {
public:
    JsonParser(const std::string& source) : _source(source), _str(), _it(0), _fileLoaded(false) {}

    void parse() {
        if (!_fileLoaded) {
            _fileLoaded = true;
            _str = _source;
            _it = 0;
        }

        parseObject();
    }

    void parseObject(DataBranch* dataBranch) {
        // Parse the opening curly brace
        if (_str[_it] != '{') {
            throw std::runtime_error("Invalid JSON object");
        }
        _it++;

        // Parse the key-value pairs
        while (_str[_it] != '}') {
            std::string key = parseString();
            if (_str[_it] != ':') {
                throw std::runtime_error("Invalid JSON object");
            }
            _it++;
            std::string value = parseString();
            dataBranch->addData(key, value);
        }

        // Parse the closing curly brace
        if (_str[_it] != '}') {
            throw std::runtime_error("Invalid JSON object");
        }
        _it++;
    }

    void parseArray(DataBranch* dataBranch) {
        // Parse the opening square bracket
        if (_str[_it] != '[') {
            throw std::runtime_error("Invalid JSON array");
        }
        _it++;

        // Parse the elements
        while (_str[_it] != ']') {
            std::string value = parseString();
            dataBranch->addData(value);
        }

        // Parse the closing square bracket
        if (_str[_it] != ']') {
            throw std::runtime_error("Invalid JSON array");
        }
        _it++;
    }

private:
    std::string _source;
    std::string _str;
    unsigned int _it;
    bool _fileLoaded;

    std::string parseString() {
        // Parse the opening quote
        if (_str[_it] != '"') {
            throw std::runtime_error("Invalid JSON string");
        }
        _it++;

        // Parse the string contents
        std::string str;
        while (_str[_it] != '"') {
            str += _str[_it];
            _it++;
        }

        // Parse the closing quote
        if (_str[_it] != '"') {
            throw std::runtime_error("Invalid JSON string");
        }
        _it++;

        return str;
    }
};
