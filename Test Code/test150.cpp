#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <json/json.h>

using namespace std;

class JsonReporter {
public:
    JsonReporter(const vector<BenchmarkData>& data) {
        this->data = data;
    }

    void report() {
        Json::Value root;
        root["benchmarks"] = Json::Value(Json::arrayValue);

        for (const auto& benchmark : data) {
            Json::Value benchmark_json;
            benchmark_json["name"] = benchmark.name;
            benchmark_json["mean"] = benchmark.mean;
            benchmark_json["median"] = benchmark.median;
            benchmark_json["standard_deviation"] = benchmark.standard_deviation;
            root["benchmarks"].append(benchmark_json);
        }

        Json::StyledWriter writer;
        string json_string = writer.write(root);
        cout << json_string << endl;
    }

private:
    vector<BenchmarkData> data;
};
