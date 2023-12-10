#include <iostream>
#include <map>
#include <vector>
#include <memory>

// Define the MapAgentIdListFloat type
using MapAgentIdListFloat = std::map<int, std::vector<float>>;

// Define the Params class
class Params {
public:
    virtual void SetMapAgentIdListFloat(const std::string& param_name,
                                        const MapAgentIdListFloat& value) = 0;
    virtual int operator[](const std::string& param_name) = 0;
    virtual std::shared_ptr<Params> AddChild(const std::string& name) = 0;
};

// Define the ConcreteParams class implementing the Params interface
class ConcreteParams : public Params {
private:
    std::map<std::string, MapAgentIdListFloat> agentIdListFloatMap;
    std::map<std::string, int> paramIntegerMap;
    std::map<std::string, std::shared_ptr<ConcreteParams>> childParamsMap;

public:
    void SetMapAgentIdListFloat(const std::string& param_name,
                                const MapAgentIdListFloat& value) override {
        agentIdListFloatMap[param_name] = value;
    }

    int operator[](const std::string& param_name) override {
        return paramIntegerMap[param_name];
    }

    std::shared_ptr<Params> AddChild(const std::string& name) override {
        auto child = std::make_shared<ConcreteParams>();
        childParamsMap[name] = child;
        return child;
    }
};

int main() {
    ConcreteParams concreteParams;
    MapAgentIdListFloat exampleMap = {{1, {1.1, 2.2, 3.3}}, {2, {4.4, 5.5}}};

    concreteParams.SetMapAgentIdListFloat("exampleParam", exampleMap);
    concreteParams["integerParam"] = 42;

    std::shared_ptr<Params> childParams = concreteParams.AddChild("child1");
    childParams->SetMapAgentIdListFloat("childParam", {{3, {6.6, 7.7}}});
    childParams->AddChild("grandchild1");

    return 0;
}
