#include <iostream>

class Employee {
private:
    int ventesDuMois;
    double tauxComm;

public:
    Employee(int ventesDuMois, double tauxComm) : ventesDuMois(ventesDuMois), tauxComm(tauxComm) {}

    void afficher() {
        std::cout << "Employee Information:" << std::endl;
        std::cout << "Ventes du mois = " << ventesDuMois << std::endl;
        std::cout << "Taux comm = " << tauxComm << std::endl;
    }

    int getVentesDuMois() {
        return ventesDuMois;
    }

    double getTauxComm() {
        return tauxComm;
    }
};
