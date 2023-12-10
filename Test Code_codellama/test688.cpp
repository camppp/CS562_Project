#include <iostream>
#include <stack>
#include <vector>

int main() {
    std::stack<int> s;
    s.push(1);
    int sz = 0;

    while (!s.empty()) {
        sz++;
        int val = s.top();
        s.pop();

        if (vis[val] == 1) {
            // Implement the logic here
        }
    }

    return 0;
}
