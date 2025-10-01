#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

void floyd(int n, vector<vector<ll>>& d) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (d[i][k] >= INF) continue;            
            for (int j = 1; j <= n; ++j) {
                if (d[k][j] >= INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    vector<vector<ll>> d(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; ++i) d[i][i] = 0;

    for (int i = 0; i < m; ++i) {
        int u, v; ll w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w); 
        d[v][u] = min(d[v][u], w);
    }

    floyd(n, d);

    while (q--) {
        int u, v; cin >> u >> v;
        if (d[u][v] >= INF/2) cout << -1 << '\n';
        else cout << d[u][v] << '\n';
    }
    return 0;
}
