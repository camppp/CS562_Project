#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
    out << '[';
    if (!v.empty()) {
        auto it = v.begin();
        out << *it;
        ++it;
        while (it != v.end()) {
            out << ", " << *it;
            ++it;
        }
    }
    out << ']';
    return out;
}

class MaxPriorityQueue {
private:
    vector<pair<int, int>> heap;  // pair<item, priority>

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index].second > heap[parent].second) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;
            if (left < size && heap[left].second > heap[largest].second) {
                largest = left;
            }
            if (right < size && heap[right].second > heap[largest].second) {
                largest = right;
            }
            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int item, int priority) {
        heap.emplace_back(item, priority);
        heapifyUp(heap.size() - 1);
    }

    int popMax() {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty");
        }
        int maxItem = heap[0].first;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxItem;
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MaxPriorityQueue pq;
    pq.insert(5, 2);
    pq.insert(7, 4);
    pq.insert(3, 1);
    pq.insert(9, 3);
    cout << "Priority Queue: " << pq << endl;
    cout << "Max item: " << pq.popMax() << endl;
    cout << "Priority Queue after popMax: " << pq << endl;
    cout << "Is priority queue empty? " << (pq.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
