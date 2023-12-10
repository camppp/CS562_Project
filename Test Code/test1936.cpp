#include <iostream>
using namespace std;

int main() {
    int V, T;
    
    // Prompt the user to enter the values of V and T
    cout << "Enter the initial velocity (V): ";
    cin >> V;
    cout << "Enter the time (T): ";
    cin >> T;
    
    // Calculate the displacement using the formula: displacement = velocity * time
    int displacement = V * T;
    
    // Output the calculated displacement
    cout << "The displacement is: " << displacement << endl;
    
    return 0;
}
