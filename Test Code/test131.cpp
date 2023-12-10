#include <iostream>
#include <iomanip>
using namespace std;

float celsius(int fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    cout << "Fahrenheit\tCelsius" << endl;
    for (int count = 0; count <= 20; count++) {
        float C_temperature = celsius(count);
        cout << count << "\t\t";
        cout << fixed << showpoint << setprecision(2) << C_temperature << endl;
    }
    return 0;
}
