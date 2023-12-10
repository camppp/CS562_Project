#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double valuePerWeight;
};

bool compareItems(const Item &a, const Item &b) {
    return a.valuePerWeight > b.valuePerWeight;
}

double knapsack(int n, int W, int w[], int v[]) {
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        items[i].weight = w[i];
        items[i].value = v[i];
        items[i].valuePerWeight = static_cast<double>(v[i]) / w[i];
    }

    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W >= items[i].weight) {
            totalValue += items[i].value;
            W -= items[i].weight;
        } else {
            totalValue += (static_cast<double>(W) / items[i].weight) * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int w[n], v[n];
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int W;
    cout << "Enter the knapsack Capacity: ";
    cin >> W;

    double maxValue = knapsack(n, W, w, v);
    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}
