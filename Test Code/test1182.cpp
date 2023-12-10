#include <iostream>

#define CREATE_DIRECTORY(name) \
    void create_directory_##name() { \
        std::cout << "Created directory: " #name << std::endl; \
    }

#define CREATE_FILE(name, content) \
    void create_file_##name() { \
        std::cout << "Created file: " #name << std::endl; \
        std::cout << "Content: " << content << std::endl; \
    }

#define LIST_CONTENTS \
    void list_contents() { \
        std::cout << "Listing contents of current directory:" << std::endl; \
        // Add logic to list contents of current directory here
    }

#define CHANGE_DIRECTORY(name) \
    void change_directory_##name() { \
        std::cout << "Changed directory to: " #name << std::endl; \
    }

int main() {
    CREATE_DIRECTORY(docs)
    CREATE_FILE(readme, "This is the readme file content")
    LIST_CONTENTS
    CHANGE_DIRECTORY(docs)

    create_directory_docs();
    create_file_readme();
    list_contents();
    change_directory_docs();

    return 0;
}
