#include <cstdint>
#include <cstddef>
#include <cstring>
#include <llvm/Support/raw_ostream.h>

class crc32_ostream : public llvm::raw_ostream {
public:
    crc32_ostream(llvm::raw_ostream& os) : os_(os) {}

    void write_impl(const char* data, size_t len) override {
        // Compute the Adler32 CRC checksum for the data being written
        uint32_t a = 1, b = 0;
        for (size_t i = 0; i < len; i++) {
            a = (a + data[i]) % MOD_ADLER;
            b = (b + a) % MOD_ADLER;
        }

        // Write the data to the underlying output stream
        os_.write(data, len);

        // Update the CRC checksum with the data being written
        crc_ = (crc_ + a) % MOD_ADLER;
        crc_ = (crc_ + b) % MOD_ADLER;
    }

    void flush() override {
        // Pass the data along to the underlying output stream
        os_.flush();
    }

private:
    llvm::raw_ostream& os_;
    uint32_t crc_ = 1;
    const uint32_t MOD_ADLER = 65521;
};
