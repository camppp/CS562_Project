c
unsigned char* deflate_memory(Bytef* src, unsigned src_len) {
	int ret = Z_STREAM_ERROR;
	z_stream strm;
	size_t dest_len = 262144;  // 256k chunk size as suggested by zlib doc

	// Initialize the zlib stream
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = src_len;
	strm.next_in = src;
	strm.avail_out = dest_len;
	strm.next_out = (Bytef*)malloc(dest_len);

	// Decompress the data
	ret = inflateInit(&strm);
	if (ret != Z_OK) {
		free(strm.next_out);
		return NULL;
	}
	ret = inflate(&strm, Z_NO_FLUSH);
	if (ret != Z_OK) {
		inflateEnd(&strm);
		free(strm.next_out);
		return NULL;
	}
	ret = inflateEnd(&strm);
	if (ret != Z_OK) {
		free(strm.next_out);
		return NULL;
	}

	// Add a trailing '\0' to the decompressed result
	strm.next_out[strm.total_out] = '\0';

	// Return the decompressed result
	return strm.next_out;
}
