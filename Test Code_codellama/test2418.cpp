#include <unistd.h>

class FileTool {
public:
    int is_file_exist(const char* file_name) {
        if (access(file_name, F_OK) == 0) {
            return 0;
        } else {
            return -1;
        }
    }
};
