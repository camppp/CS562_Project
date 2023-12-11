class CollectorBuildResult {
public:
    CollectorBuildResult(aaoc::EntityCollector *collector, EntityType collectorType, aslp::ParseResult result) {
        this->collector = collector;
        this->collectorType = collectorType;
        this->result = result;
    }
private:
    aaoc::EntityCollector *collector;
    EntityType collectorType;
    aslp::ParseResult result;
};
