#include <iostream>
#include <string>

class VehicleBase {
protected:
    int id;
    std::string brand;
    std::string model;
    double rentalPricePerDay;

public:
    virtual double calculateRentalCost(int numDays) = 0;
};

class Car : public VehicleBase {
private:
    int numSeats;

public:
    Car(int id, const std::string& brand, const std::string& model, double rentalPricePerDay, int numSeats)
        : numSeats(numSeats) {
        this->id = id;
        this->brand = brand;
        this->model = model;
        this->rentalPricePerDay = rentalPricePerDay;
    }

    double calculateRentalCost(int numDays) override {
        return rentalPricePerDay * numDays + (numSeats > 5 ? 20 : 0);
    }
};

class Motorcycle : public VehicleBase {
private:
    bool hasSideCar;

public:
    Motorcycle(int id, const std::string& brand, const std::string& model, double rentalPricePerDay, bool hasSideCar)
        : hasSideCar(hasSideCar) {
        this->id = id;
        this->brand = brand;
        this->model = model;
        this->rentalPricePerDay = rentalPricePerDay;
    }

    double calculateRentalCost(int numDays) override {
        return rentalPricePerDay * numDays + (hasSideCar ? 15 : 0);
    }
};

class Truck : public VehicleBase {
private:
    double cargoCapacityTons;

public:
    Truck(int id, const std::string& brand, const std::string& model, double rentalPricePerDay, double cargoCapacityTons)
        : cargoCapacityTons(cargoCapacityTons) {
        this->id = id;
        this->brand = brand;
        this->model = model;
        this->rentalPricePerDay = rentalPricePerDay;
    }

    double calculateRentalCost(int numDays) override {
        return rentalPricePerDay * numDays + (cargoCapacityTons * 10);
    }
};

int main() {
    Car car(1, "Toyota", "Camry", 50.0, 5);
    Motorcycle motorcycle(2, "Honda", "CBR500R", 30.0, true);
    Truck truck(3, "Ford", "F-150", 80.0, 3.5);

    std::cout << "Car rental cost for 3 days: $" << car.calculateRentalCost(3) << std::endl;
    std::cout << "Motorcycle rental cost for 5 days: $" << motorcycle.calculateRentalCost(5) << std::endl;
    std::cout << "Truck rental cost for 2 days: $" << truck.calculateRentalCost(2) << std::endl;

    return 0;
}
