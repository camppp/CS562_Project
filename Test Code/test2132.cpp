#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <Windows.h>

class TicketSystem {
private:
    int totalTickets;
    HANDLE semaphore;

public:
    TicketSystem(int initialTickets) : totalTickets(initialTickets) {
        semaphore = CreateSemaphore(NULL, 0, 0x7FFFFFFF, NULL);
    }

    void AddTickets(int numTickets) {
        totalTickets += numTickets;
        ReleaseSemaphore(semaphore, numTickets, NULL);
    }

    bool BuyTickets(int numTickets) {
        if (WaitForSingleObject(semaphore, 0) == WAIT_OBJECT_0) {
            if (totalTickets >= numTickets) {
                totalTickets -= numTickets;
                return true;
            }
            ReleaseSemaphore(semaphore, 1, NULL);
        }
        return false;
    }
};

void SellerThread(TicketSystem& system, int numTickets) {
    system.AddTickets(numTickets);
}

void BuyerThread(TicketSystem& system, int numTickets) {
    if (system.BuyTickets(numTickets)) {
        std::cout << "Tickets purchased: " << numTickets << std::endl;
    } else {
        std::cout << "Tickets not available" << std::endl;
    }
}

int main() {
    TicketSystem ticketSystem(10);

    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(SellerThread, std::ref(ticketSystem), 3);
        threads.emplace_back(BuyerThread, std::ref(ticketSystem), 2);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Remaining tickets: " << ticketSystem.BuyTickets(0) << std::endl;

    return 0;
}
