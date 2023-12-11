#include <iostream>
#include <set>

class FileLinking {
public:
    // Member variables
    std::set<int> linked_fd_;

    // Member functions to be implemented
    void linkFiles(int fd1, int fd2) {
        linked_fd_.insert(fd1);
        linked_fd_.insert(fd2);
    }

    bool isLinked(int fd) {
        return linked_fd_.find(fd) != linked_fd_.end();
    }
};

int main() {
    FileLinking linking_fd;

    // Test the functionality
    linking_fd.linkFiles(1, 2);
    linking_fd.linkFiles(2, 3);

    std::cout << linking_fd.isLinked(1) << std::endl;  // Expected output: true
    std::cout << linking_fd.isLinked(4) << std::endl;  // Expected output: false

    return 0;
}
