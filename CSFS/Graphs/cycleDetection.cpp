#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

vector<int> find_negative_cycle(int n, const vector<array<ll,3>>& edges) {
    vector<ll> dist(n+1, 0);         // <- all zero: detect cycle anywhere
    vector<int> parent(n+1, -1);
    int x = -1;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (auto &e : edges) {
            int u = (int)e[0], v = (int)e[1];
            ll w = e[2];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) return {}; // no negative cycle

    // move x back n times to guarantee we are inside the cycle
    int y = x;
    for (int i = 0; i < n; ++i) y = parent[y];

    // reconstruct cycle starting from y
    vector<int> cycle;
    for (int cur = y;; cur = parent[cur]) {
        cycle.push_back(cur);
        if (cur == y && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());
    return cycle;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<array<ll,3>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u, v; ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    auto cycle = find_negative_cycle(n, edges);
    if (cycle.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }
    return 0;
}
