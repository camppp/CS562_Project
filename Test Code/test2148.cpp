#include "usage_stats/upload_util.h"

#include "base/logging.h"
#include "base/number_util.h"
#include "base/util.h"
#include "net/http_client.h"

namespace mozc {
namespace usage_stats {

double CalculateAverageResponseTime(const std::vector<double>& responseTimes) {
    double sum = 0.0;
    for (const auto& time : responseTimes) {
        sum += time;
    }
    return sum / responseTimes.size();
}

}  // namespace usage_stats
}  // namespace mozc
