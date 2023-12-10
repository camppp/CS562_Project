int solve() {
    ll n;
    cin >> n; // Assuming input is read from standard input

    ll result = ((n % MOD) * ((n + 1) % MOD)) % MOD; // Calculate (n^2 + n) % MOD

    return result;
}
