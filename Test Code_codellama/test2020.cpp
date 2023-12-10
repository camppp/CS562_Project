#include <iostream>

class _t {
public:
    void on_showQRCode_clicked();
    void on_scanQRCode_clicked();
    void on_generateQRCode_clicked();
};

int main() {
    int event;
    std::cin >> event;

    _t t;

    switch (event) {
        case 10:
            t.on_showQRCode_clicked();
            break;
        case 11:
            t.on_scanQRCode_clicked();
            break;
        case 12:
            t.on_generateQRCode_clicked();
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
    }

    return 0;
}
