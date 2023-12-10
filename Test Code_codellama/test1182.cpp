#define CREATE_DIRECTORY(name) \
    do { \
        std::string dir_name = name; \
        if (dir_name.empty()) { \
            std::cerr << "Error: directory name cannot be empty" << std::endl; \
            return; \
        } \
        std::filesystem::create_directory(dir_name); \
    } while (0)

#define CREATE_FILE(name, content) \
    do { \
        std::string file_name = name; \
        if (file_name.empty()) { \
            std::cerr << "Error: file name cannot be empty" << std::endl; \
            return; \
        } \
        std::ofstream file(file_name); \
        if (!file.is_open()) { \
            std::cerr << "Error: unable to create file " << file_name << std::endl; \
            return; \
        } \
        file << content; \
        file.close(); \
    } while (0)

#define LIST_CONTENTS \
    do { \
        std::filesystem::directory_iterator it(std::filesystem::current_path()); \
        for (; it != std::filesystem::directory_iterator(); ++it) { \
            std::cout << it->path().filename() << std::endl; \
        } \
    } while (0)

#define CHANGE_DIRECTORY(name) \
    do { \
        std::string dir_name = name; \
        if (dir_name.empty()) { \
            std::cerr << "Error: directory name cannot be empty" << std::endl; \
            return; \
        } \
        std::filesystem::current_path(dir_name); \
    } while (0)
