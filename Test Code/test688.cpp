stack<ll> s;
s.push(1);
ll sz = 0;
vector<int> vis(MAX_VAL, 0); // Assuming MAX_VAL is the maximum value that can be pushed onto the stack
while (!s.empty()) {
    sz++;
    ll val = s.top();
    s.pop();
    if (vis[val] == 0) {
        vis[val] = 1; // Marking val as visited
        // Add logic for processing val here
    }
}
