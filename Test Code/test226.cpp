#include <stdint.h>

uint32_t txns_processed = 0;

void processTransaction() {
    txns_processed = (txns_processed + 1) % (UINT32_MAX + 1);
}
