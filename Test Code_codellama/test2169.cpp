#include <iostream>
#include <string>

class VehicleBase {
public:
    int id;
    std::string brand;
    std::string model;
    double rentalPricePerDay;

    VehicleBase(int id, std::string brand, std::string model, double rentalPricePerDay) : id(id), brand(brand), model(model), rentalPricePerDay(rentalPricePerDay) {}

    virtual double calculateRentalCost(int numDays) {
        return rentalPricePerDay * numDays;
    }
};

class Car : public VehicleBase {
public:
    int numSeats;

    Car(int id, std::string brand, std::string model, double rentalPricePerDay, int numSeats) : VehicleBase(id, brand, model, rentalPricePerDay), numSeats(numSeats) {}

    double calculateRentalCost(int numDays) {
        return VehicleBase::calculateRentalCost(numDays) + (numSeats * 100);
    }
};

class Motorcycle : public VehicleBase {
public:
    bool hasSideCar;

    Motorcycle(int id, std::string brand, std::string model, double rentalPricePerDay, bool hasSideCar) : VehicleBase(id, brand, model, rentalPricePerDay), hasSideCar(hasSideCar) {}

    double calculateRentalCost(int numDays) {
        return VehicleBase::calculateRentalCost(numDays) + (hasSideCar ? 100 : 0);
    }
};

class Truck : public VehicleBase {
public:
    double cargoCapacityTons;

    Truck(int id, std::string brand, std::string model, double rentalPricePerDay, double cargoCapacityTons) : VehicleBase(id, brand, model, rentalPricePerDay), cargoCapacityTons(cargoCapacityTons) {}

    double calculateRentalCost(int numDays) {
        return VehicleBase::calculateRentalCost(numDays) + (cargoCapacityTons * 100);
    }
};

int main() {
    Car car1(1, "Toyota", "Camry", 100, 5);
    Motorcycle motorcycle1(2, "Harley-Davidson", "Softail", 150, false);
    Truck truck1(3, "Ford", "F-150", 200, 2);

    std::cout << "Car 1 rental cost: " << car1.calculateRentalCost(3) << std::endl;
    std::cout << "Motorcycle 1 rental cost: " << motorcycle1.calculateRentalCost(3) << std::endl;
    std::cout << "Truck 1 rental cost: " << truck1.calculateRentalCost(3) << std::endl;

    return 0;
}
