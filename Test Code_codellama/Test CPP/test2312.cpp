#include <cstdint>

const uint32_t SCORE_MAX = 100;

uint32_t eval_seq() {
    uint32_t result = ...; // result of the evaluation
    uint32_t max_result = ...; // maximum possible result
    return SCORE_MAX * (result / max_result);
}
