#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

// Define the parameters of the simulation
const int NUM_TELLERS = 5;
const double ARRIVAL_RATE = 10.0; // customers per minute
const double SERVICE_TIME = 5.0; // minutes
const int DURATION = 60; // minutes

// Define the queue data structure
struct Queue {
  vector<int> customers;
  int front = 0;
  int back = 0;
};

// Define the teller data structure
struct Teller {
  int id;
  int service_time;
  int waiting_time = 0;
};

// Define the simulation function
void simulate(int num_tellers, double arrival_rate, double service_time, int duration) {
  // Initialize the queue and tellers
  Queue queue;
  vector<Teller> tellers(num_tellers);
  for (int i = 0; i < num_tellers; i++) {
    tellers[i].id = i;
    tellers[i].service_time = service_time;
  }

  // Simulate the arrival and service of customers
  for (int i = 0; i < duration; i++) {
    // Arrival of customers
    for (int j = 0; j < arrival_rate; j++) {
      queue.customers.push_back(i);
    }

    // Service of customers
    for (int j = 0; j < num_tellers; j++) {
      if (queue.customers.size() > 0) {
        int customer = queue.customers.front();
        queue.customers.pop_front();
        tellers[j].waiting_time += (i - customer);
      }
    }
  }

  // Calculate the average waiting time for customers
  double total_waiting_time = 0;
  for (int i = 0; i < num_tellers; i++) {
    total_waiting_time += tellers[i].waiting_time;
  }
  double average_waiting_time = total_waiting_time / (double)num_tellers;

  // Print the results
  cout << "Average waiting time: " << average_waiting_time << " minutes" << endl;
}

int main() {
  simulate(NUM_TELLERS, ARRIVAL_RATE, SERVICE_TIME, DURATION);
  return 0;
}
