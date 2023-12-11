#include <iostream>
#include <string>
#include <vector>

struct VariableInfo {
    std::string type;
    std::string name;
};

struct ArrayInfo {
    std::string type;
    std::string name;
    std::string size;
};

void analyzeCodeSnippet(const std::string& codeSnippet) {
    std::vector<VariableInfo> variables;
    std::vector<ArrayInfo> arrays;

    // Tokenize the code snippet
    std::vector<std::string> tokens = tokenize(codeSnippet);

    // Iterate over the tokens and extract variable and array information
    for (const std::string& token : tokens) {
        if (token.find("int64_t") != std::string::npos) {
            variables.push_back({"int64_t", token});
        } else if (token.find("j2c_array< double >") != std::string::npos) {
            arrays.push_back({"j2c_array< double >", token});
        } else if (token.find("double") != std::string::npos) {
            variables.push_back({"double", token});
        } else if (token.find("bool") != std::string::npos) {
            variables.push_back({"bool", token});
        }
    }

    // Print the results
    std::cout << "Total number of variables: " << variables.size() << std::endl;
    std::cout << "Data types of variables: ";
    for (const VariableInfo& variable : variables) {
        std::cout << variable.type << ", ";
    }
    std::cout << std::endl;

    std::cout << "Total number of arrays: " << arrays.size() << std::endl;
    std::cout << "Sizes of arrays: ";
    for (const ArrayInfo& array : arrays) {
        std::cout << array.size << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::string codeSnippet = "int64_t ptempp; j2c_array< double >  _pa_rand_gen_arr; j2c_array< double >  pp_pa_rand_gen_arr_14p276; double SSAValue40pp2; j2c_array< double >  SSAValue0; j2c_array< double >  SSAValue1; int64_t SSAValue2; j2c_array< double >  SSAValue4; double SSAValue5; bool SSAValue6;";
    analyzeCodeSnippet(codeSnippet);
    return 0;
}
