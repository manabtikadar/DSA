// #include <bits/stdc++.h>
// using namespace std;


// // Diakstra's Algorithm to find the highest score from node 1 to node n falis in positve cycle graph
// // long long HighScore(int n, vector<vector<long long>>& edges)
// // {
// //     unordered_map<int, list<pair<long long,int>>> adjList;

// //     // prepare adjacency list
// //     for (auto &edge : edges)
// //     {
// //         int u = (int)edge[0];
// //         int v = (int)edge[1];
// //         long long wt = edge[2];
// //         adjList[u].push_back({wt, v});
// //     }

// //     vector<long long> score(n+1, LLONG_MIN);
// //     priority_queue<pair<long long,int>> pq; // max-heap
// //     score[1] = 0;
// //     pq.push({0, 1});

// //     while (!pq.empty())
// //     {
// //         int front_node = pq.top().second;
// //         long long Weight = pq.top().first;
// //         pq.pop();

// //         for (auto it : adjList[front_node])
// //         {
// //             int adjNode = it.second;
// //             long long adjWeight = it.first;

// //             if (Weight + adjWeight > score[adjNode])
// //             {
// //                 score[adjNode] = Weight + adjWeight;
// //                 pq.push({score[adjNode], adjNode});
// //             }
// //         }
// //     }

// //     return score[n];
// // }

// long long highestScoreBellmanFord(int n, vector<vector<long long>>& edges,int src)
// {
//   vector<long long> distance(n+1,LLONG_MIN);
//   distance[src]=0;

//   for(int i=0; i<n; i++)
//   {
//     for(auto edge:edges)
//     {
//       int u=edge[0];
//       int v=edge[1];
//       int wt=edge[2];

//       if(distance[u]!=INT_MIN && distance[u]+wt>distance[v])
//       {
//         distance[v]=distance[u]+wt;
//       }
//     }
//   }

//   for(auto edge:edges)
//   {
//     int u=edge[0];
//     int v=edge[1];
//     int wt=edge[2];

//     if(distance[u]!=INT_MIN && distance[u]+wt>distance[v])
//     {
//       if(distance[n]==INT_MIN)
//       {
//         return -1;
//       }
//     }
//   }

//   return distance[n];
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;

//     vector<vector<long long>> edges;
//     edges.reserve(m);

//     for (int i = 0; i < m; i++)
//     {
//         long long u, v, wt;
//         cin >> u >> v >> wt;
//         edges.push_back({u, v, wt});
//     }
    
//     long long ans = highestScoreBellmanFord(n,edges,1);

//     if (ans == LLONG_MIN) cout << -1 << "\n";  // unreachable
//     else cout << ans << "\n";

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long highestScoreBellmanFord(int n, vector<vector<long long>>& edges, int src) {
    vector<long long> dist(n+1, LLONG_MIN);
    dist[src] = 0;

    for (int i = 1; i <= n-1; i++) {
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            long long wt = edge[2];

            if (dist[u] != LLONG_MIN && dist[u] + wt > dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    vector<int> affected(n+1, 0);
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        long long wt = edge[2];

        if (dist[u] != LLONG_MIN && dist[u] + wt > dist[v]) {
            affected[v] = 1; 
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (affected[i]) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto &edge : edges) {
            if (edge[0] == node && !affected[edge[1]]) {
                affected[edge[1]] = 1;
                q.push(edge[1]);
            }
        }
    }

    // If node n is affected, score is infinite
    if (affected[n]) return -1;

    return dist[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> edges;
    edges.reserve(m);

    for (int i = 0; i < m; i++) {
        long long u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    long long ans = highestScoreBellmanFord(n, edges, 1);

    if (ans == LLONG_MIN) cout << -1 << "\n";  // unreachable (though problem guarantees path exists)
    else cout << ans << "\n";

    return 0;
}
