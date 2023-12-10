#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string make;
    std::string model;
    int year;

public:
    Vehicle(const std::string& make, const std::string& model, int year)
        : make(make), model(model), year(year) {}

    std::string getMake() const {
        return make;
    }

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(const std::string& make, const std::string& model, int year, int numDoors)
        : Vehicle(make, model, year), numDoors(numDoors) {}

    int getNumDoors() const {
        return numDoors;
    }
};

class Motorcycle : public Vehicle {
private:
    int engineDisplacement;

public:
    Motorcycle(const std::string& make, const std::string& model, int year, int engineDisplacement)
        : Vehicle(make, model, year), engineDisplacement(engineDisplacement) {}

    int getEngineDisplacement() const {
        return engineDisplacement;
    }
};

int main() {
    Car car("Toyota", "Camry", 2022, 4);
    Motorcycle motorcycle("Honda", "CBR500R", 2021, 471);

    std::cout << "Car: " << car.getMake() << " " << car.getModel() << " " << car.getYear() << " " << car.getNumDoors() << " doors" << std::endl;
    std::cout << "Motorcycle: " << motorcycle.getMake() << " " << motorcycle.getModel() << " " << motorcycle.getYear() << " " << motorcycle.getEngineDisplacement() << " cc" << std::endl;

    return 0;
}
