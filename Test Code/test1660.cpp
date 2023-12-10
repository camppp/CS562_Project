#include <stdlib.h>

z_stream* myInflateInit2() {
    z_stream* s = (z_stream*)malloc(sizeof(z_stream));
    if (s == NULL) {
        return NULL;  // Memory allocation failed
    }

    s->inbuf = (Byte*)malloc(Z_BUFSIZE);
    if (s->inbuf == NULL) {
        free(s);
        return NULL;  // Memory allocation failed
    }

    s->next_in = s->inbuf;
    s->avail_out = Z_BUFSIZE;

    int err = inflateInit2(s, -MAX_WBITS);
    if (err != Z_OK) {
        free(s->inbuf);
        free(s);
        return NULL;  // Initialization failed
    }

    return s;  // Initialization successful
}
