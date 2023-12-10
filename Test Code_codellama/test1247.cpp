#include <iostream>
#include <string>

class Vehicle {
public:
    Vehicle(std::string make, std::string model, int year) : make(make), model(model), year(year) {}

    std::string getMake() { return make; }
    std::string getModel() { return model; }
    int getYear() { return year; }

private:
    std::string make;
    std::string model;
    int year;
};

class Car : public Vehicle {
public:
    Car(std::string make, std::string model, int year, int numDoors) : Vehicle(make, model, year), numDoors(numDoors) {}

    int getNumDoors() { return numDoors; }

private:
    int numDoors;
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(std::string make, std::string model, int year, int engineDisplacement) : Vehicle(make, model, year), engineDisplacement(engineDisplacement) {}

    int getEngineDisplacement() { return engineDisplacement; }

private:
    int engineDisplacement;
};

int main() {
    Vehicle car("Toyota", "Camry", 2010);
    std::cout << "Make: " << car.getMake() << std::endl;
    std::cout << "Model: " << car.getModel() << std::endl;
    std::cout << "Year: " << car.getYear() << std::endl;

    Car car2("Toyota", "Camry", 2010, 4);
    std::cout << "Make: " << car2.getMake() << std::endl;
    std::cout << "Model: " << car2.getModel() << std::endl;
    std::cout << "Year: " << car2.getYear() << std::endl;
    std::cout << "Num Doors: " << car2.getNumDoors() << std::endl;

    Motorcycle motorcycle("Honda", "CBR600RR", 2015, 650);
    std::cout << "Make: " << motorcycle.getMake() << std::endl;
    std::cout << "Model: " << motorcycle.getModel() << std::endl;
    std::cout << "Year: " << motorcycle.getYear() << std::endl;
    std::cout << "Engine Displacement: " << motorcycle.getEngineDisplacement() << std::endl;

    return 0;
}
