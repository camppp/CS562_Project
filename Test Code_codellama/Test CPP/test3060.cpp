#include <cstdint>
#include <string>

// Global variables
uint64_t test_max_buf_size = 1024;
uint64_t test_total_written = 0;
std::string test_host_file_name = "";

void test_m5_write_file(const char* buffer, uint64_t length, uint64_t offset, const char* filename) {
  // Check if the length of the buffer exceeds the maximum buffer size
  if (length > test_max_buf_size) {
    length = test_max_buf_size;
  }

  // Update the total number of bytes written
  test_total_written += length;

  // Set the host file name if it is currently an empty string
  if (test_host_file_name.empty()) {
    test_host_file_name = filename;
  }

  // Write the buffer to the host file
  std::ofstream ofs(test_host_file_name, std::ios::binary | std::ios::app);
  ofs.seekp(offset);
  ofs.write(buffer, length);
  ofs.close();
}
