#include "usage_stats/upload_util.h"

#include "base/logging.h"
#include "base/number_util.h"
#include "base/util.h"
#include "net/http_client.h"

namespace mozc {
namespace usage_stats {

double CalculateAverageResponseTime(const std::vector<double>& responseTimes) {
  if (responseTimes.empty()) {
    LOG(WARNING) << "Empty response times vector";
    return 0.0;
  }

  double sum = 0.0;
  for (const auto& responseTime : responseTimes) {
    sum += responseTime;
  }

  return sum / responseTimes.size();
}

}  // namespace usage_stats
}  // namespace mozc
