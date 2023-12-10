#include <iostream>
#include <string>

void set_titles(const std::string& last_file_name_used) {
    int count = 1;
    while (count <= 10) {
        std::string title = last_file_name_used + std::to_string(count);
        std::cout << "Setting title for file " << title << std::endl;
        count++;
    }
}

int main() {
    set_titles("report");
    return 0;
}
