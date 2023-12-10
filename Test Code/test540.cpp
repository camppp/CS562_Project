#include <iostream>

class Population {
private:
    bool mIsParsed;
    int mYear;
    int mTotalPop;

public:
    //! Default constructor.
    Population():
        mIsParsed(true),
        mYear(-1),
        mTotalPop(-1) {}

    //! Method to set the year and total population for the population data.
    void setPopulationData(int year, int totalPop) {
        mYear = year;
        mTotalPop = totalPop;
    }

    //! Method to get the year for the population data.
    int getYear() const {
        return mYear;
    }

    //! Method to get the total population for the population data.
    int getTotalPopulation() const {
        return mTotalPop;
    }
};

int main() {
    // Create an instance of the Population class
    Population populationData;

    // Set the population data for the year 2021 with a total population of 8000000
    populationData.setPopulationData(2021, 8000000);

    // Retrieve and print the population data
    std::cout << "Population data for year " << populationData.getYear() << ": " << populationData.getTotalPopulation() << std::endl;

    return 0;
}
