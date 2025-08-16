// You are given N chocolates in positions 1 to N.
// Bruce flips a coin N-1 times. In each flip:

// Heads (H) → remove the leftmost chocolate.

// Tails (T) → remove the rightmost chocolate.

// After N-1 removals, only one chocolate remains.

// You're given a position K, and you need to determine how many sequences of coin flips will result in the K-th chocolate being the last one remaining.

#include <iostream>
#include <vector>
using namespace std;

long long dp[1001][1001]; // Assumes N ≤ 1000

long long count_ways(int n, int k) {
    if (k <= 0 || k > n) return 0;
    if (n == 1) return (k == 1) ? 1 : 0;

    if (dp[n][k] != -1) return dp[n][k];

    return dp[n][k] = count_ways(n - 1, k - 1) + count_ways(n - 1, k);
}

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            dp[i][j] = -1;

    cout << count_ways(N, K) << endl;
    return 0;
}
