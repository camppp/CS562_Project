class CollectorBuildResult {
public:
    CollectorBuildResult(aaoc::EntityCollector *collector, EntityType collectorType, const aslp::ParseResult& result)
        : collector(collector), collectorType(collectorType), result(result) {
        // Constructor implementation
    }
private:
    aaoc::EntityCollector *collector;
    EntityType collectorType;
    aslp::ParseResult result;
};
