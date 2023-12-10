#include <iostream>
#include <queue>
#include <random>
#include <numeric>

struct Customer {
    int arrivalTime;
    int serviceTime;
};

double simulateQueueManagement(int numTellers, double arrivalRate, double serviceTime, int simulationDuration) {
    std::default_random_engine generator;
    std::exponential_distribution<double> arrivalDistribution(1.0 / arrivalRate);
    std::exponential_distribution<double> serviceDistribution(1.0 / serviceTime);

    std::queue<Customer> customerQueue;
    std::vector<int> tellerFinishTimes(numTellers, 0);

    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalCustomers = 0;

    while (currentTime < simulationDuration) {
        double nextArrival = arrivalDistribution(generator);
        currentTime += nextArrival;

        if (currentTime < simulationDuration) {
            Customer newCustomer;
            newCustomer.arrivalTime = currentTime;
            newCustomer.serviceTime = serviceDistribution(generator);
            customerQueue.push(newCustomer);
            totalCustomers++;

            for (int i = 0; i < numTellers; i++) {
                if (currentTime >= tellerFinishTimes[i] && !customerQueue.empty()) {
                    Customer nextCustomer = customerQueue.front();
                    customerQueue.pop();
                    totalWaitingTime += currentTime - nextCustomer.arrivalTime;
                    tellerFinishTimes[i] = currentTime + nextCustomer.serviceTime;
                }
            }
        }
    }

    double averageWaitingTime = static_cast<double>(totalWaitingTime) / totalCustomers;
    return averageWaitingTime;
}

int main() {
    int numTellers = 3;
    double arrivalRate = 10.0; // customers per minute
    double serviceTime = 5.0; // minutes
    int simulationDuration = 480; // 8 hours in minutes

    double averageWaitingTime = simulateQueueManagement(numTellers, arrivalRate, serviceTime, simulationDuration);
    std::cout << "Average waiting time for customers: " << averageWaitingTime << " minutes" << std::endl;

    return 0;
}
