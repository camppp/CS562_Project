#include <string>
#include <memory>
#include "CollectorFactory.hpp"
#include "ParseResult.hpp"

class HyperworksNodeCollectorFactory : public CollectorFactory {
public:
  HyperworksNodeCollectorFactory();
  ~HyperworksNodeCollectorFactory();

  virtual void Destroy() const;

  virtual axis::services::language::parsing::ParseResult TryParse(const std::string& input);

private:
  // Internal state and resources
  std::unique_ptr<ParseResult> _parseResult;
};

HyperworksNodeCollectorFactory::HyperworksNodeCollectorFactory() {
  // Initialize internal state and resources
  _parseResult = std::make_unique<ParseResult>();
}

HyperworksNodeCollectorFactory::~HyperworksNodeCollectorFactory() {
  // Release internal resources
  _parseResult.reset();
}

void HyperworksNodeCollectorFactory::Destroy() const {
  // Release any resources held by the factory
  _parseResult.reset();
}

axis::services::language::parsing::ParseResult HyperworksNodeCollectorFactory::TryParse(const std::string& input) {
  // Attempt to parse the input and return the result
  _parseResult->parse(input);
  return *_parseResult;
}
