#include <iostream>

// Function to send GPS data to the FLP module
extern "C" void mtk_gps_ofl_send_flp_data(double latitude, double longitude, double altitude) {
    // Implementation of sending GPS data to FLP module
    std::cout << "Sending GPS data to FLP module - Lat: " << latitude << ", Long: " << longitude << ", Alt: " << altitude << std::endl;
}

// Function to send GPS data to FLP module
void send_gps_data_to_flp(double latitude, double longitude, double altitude) {
    // Call the mtk_gps_ofl_send_flp_data function to send GPS data to FLP module
    mtk_gps_ofl_send_flp_data(latitude, longitude, altitude);
}

int main() {
    // Example usage of send_gps_data_to_flp function
    send_gps_data_to_flp(37.7749, -122.4194, 0);
    return 0;
}
