#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
string print_array(const vector<T> &V) {
    stringstream ss;
    ss << "{";
    for (int i = 0; i < V.size(); i++) {
        if (i != 0) {
            ss << ", ";
        }
        ss << V[i];
    }
    ss << "}";
    return ss.str();
}

int main() {
    vector<int> intVector = {1, 2, 3, 4, 5};
    vector<string> stringVector = {"apple", "banana", "cherry", "date"};
    vector<CustomObject> customObjectVector = {CustomObject(), CustomObject()};

    cout << "Integer Vector: " << print_array(intVector) << endl;
    cout << "String Vector: " << print_array(stringVector) << endl;
    cout << "Custom Object Vector: " << print_array(customObjectVector) << endl;

    return 0;
}
