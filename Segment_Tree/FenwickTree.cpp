#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
public:
    vector<int> fen;

    // Constructor: builds a tree for size n (1-based indexing)
    FenwickTree(int n) {
        fen.resize(n + 1, 0); // index 0 is unused
    }

    // Point update: add 'add' to index i
    void update(int i, int add) {
        while (i < fen.size()) {
            fen[i] += add;
            i = i + (i & -i);
        }
    }

    // Prefix sum query: sum of elements from 1 to i
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += fen[i];
            i = i - (i & -i);
        }
        return s;
    }

    // Range sum query: sum of elements from l to r (inclusive)
    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
