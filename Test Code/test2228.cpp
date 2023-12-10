#include <iostream>
using namespace std;

class Employee {
private:
    int ventesDuMois;
    double tauxComm;

public:
    Employee(int ventes, double taux) : ventesDuMois(ventes), tauxComm(taux) {}

    void afficher() {
        cout << "Employee Information:" << endl;
        cout << "Ventes du mois  = " << ventesDuMois << endl;
        cout << "Taux comm  = " << tauxComm << endl;
    }

    int getVentesDuMois() {
        return ventesDuMois;
    }

    double getTauxComm() {
        return tauxComm;
    }
};

int main() {
    Employee emp(5000, 0.1); // Monthly sales = 5000, Commission rate = 10%
    emp.afficher(); // Output employee information
    return 0;
}
