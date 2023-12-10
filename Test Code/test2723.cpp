#include <iostream>

int main() {
    Printer printer;

    printer.addJob("Document 1");
    printer.addJob("Document 2");
    printer.addJob("Document 3");

    try {
        std::cout << "Printing: " << printer.print() << std::endl;
        std::cout << "Printing: " << printer.print() << std::endl;
        std::cout << "Printing: " << printer.print() << std::endl;
        std::cout << "Printing: " << printer.print() << std::endl;  // This will throw an exception
    } catch (const std::logic_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "Status: " << printer.reportStatus() << std::endl;

    return 0;
}
