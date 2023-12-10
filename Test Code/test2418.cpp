#include <unistd.h>

class FileTool {
public:
    int is_file_exist(const char* file_name) {
        return access(file_name, F_OK);
    }
};
