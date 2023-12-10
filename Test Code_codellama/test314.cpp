#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <cassert>

#include "token_stream.h"

namespace analyzers {
namespace filters {

class porter2_filter {
public:
    porter2_filter(std::unique_ptr<token_stream> source) : source_(std::move(source)) {}

    std::string next_token() {
        // Apply the Porter2 stemming algorithm to the next token in the input stream
        std::string token = source_->next_token();
        std::string stem = porter2_stem(token);
        return stem;
    }

private:
    std::unique_ptr<token_stream> source_;
};

} // namespace filters
} // namespace analyzers
