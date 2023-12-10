#include <iostream>
#include <vector>

class crc32_ostream : public llvm::raw_ostream {
private:
    llvm::raw_ostream &underlying_stream;
    std::vector<uint8_t> data_buffer;
    const uint32_t MOD_ADLER = 65521;

public:
    crc32_ostream(llvm::raw_ostream &underlying) : underlying_stream(underlying) {}

    void write_impl(const char *Ptr, size_t Size) override {
        for (size_t i = 0; i < Size; i++) {
            data_buffer.push_back(Ptr[i]);
        }
    }

    void flush() override {
        uint32_t a = 1, b = 0;
        for (size_t i = 0; i < data_buffer.size(); i++) {
            a = (a + data_buffer[i]) % MOD_ADLER;
            b = (b + a) % MOD_ADLER;
        }
        uint32_t adler32_checksum = (b << 16) | a;
        underlying_stream.write((const char *)data_buffer.data(), data_buffer.size());
        data_buffer.clear();
    }
};
