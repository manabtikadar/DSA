#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int days = 0;
    int total_walk = 0;

    int z[3] = {a, b, c};
    int p = a + b + c;

    // Count full cycles of 3 days
    while (total_walk + p <= n) {
        days += 3;
        total_walk += p;
    }

    // Add remaining days to reach `n`
    for (int i = 0; i < 3 && total_walk < n; i++) {
        days++;
        total_walk += z[i];
    }

    cout << days << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
