#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

unsigned char* deflate_memory(Bytef* src, unsigned src_len) {
    int ret;
    z_stream strm;
    size_t dest_len = 262144;  // 256k chunk size as suggested by zlib doc
    unsigned char* dest = (unsigned char*)malloc(dest_len);

    if (dest == NULL) {
        return NULL;  // Memory allocation failed
    }

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = src_len;
    strm.next_in = src;
    strm.avail_out = dest_len;
    strm.next_out = dest;

    ret = inflateInit(&strm);
    if (ret != Z_OK) {
        free(dest);
        return NULL;  // Inflate initialization failed
    }

    ret = inflate(&strm, Z_FINISH);
    if (ret != Z_STREAM_END) {
        inflateEnd(&strm);
        free(dest);
        return NULL;  // Inflate failed
    }

    ret = inflateEnd(&strm);
    if (ret != Z_OK) {
        free(dest);
        return NULL;  // Inflate end failed
    }

    dest[strm.total_out] = '\0';  // Add trailing '\0'
    return dest;
}
