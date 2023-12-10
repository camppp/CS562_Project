#include <iostream>
#include <thread>

void producer(ThreadSafeWorkQueue<int>& workQueue) {
    for (int i = 0; i < 10; ++i) {
        workQueue.add(new int(i));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(ThreadSafeWorkQueue<int>& workQueue) {
    for (int i = 0; i < 5; ++i) {
        int* item = workQueue.get();
        std::cout << "Consumed: " << *item << std::endl;
        delete item;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main() {
    ThreadSafeWorkQueue<int> workQueue;

    std::thread producerThread(producer, std::ref(workQueue));
    std::thread consumerThread(consumer, std::ref(workQueue));

    producerThread.join();
    consumerThread.join();

    std::cout << "Remaining items in the queue: " << workQueue.available() << std::endl;

    return 0;
}
