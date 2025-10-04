// #include<bits/stdc++.h>
// using namespace std;

// long long FlightDiscount(int n,vector<vector<int>> edges)
// {
//   vector<vector<pair<int,int>>> adjList(n+1), adjList_rev(n+1);
  
//   //prepared adjList;
//   for(auto edge:edges)
//   {
//     int u=edge[0];
//     int v=edge[1];
//     int wt=edge[2];

//     adjList[u].push_back({v,wt});
//     adjList_rev[v].push_back({u,wt});
//   }

//   int source=1;
//   int destination=n;
  
//   // Dijkstra Algorithm
//   vector<long long> dist(n+1,LLONG_MAX);
//   priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

//   dist[source]=0;
//   pq.push({0,source});

//   while(!pq.empty())
//   {
//     int node=pq.top().second;
//     long long cost=pq.top().first;

//     pq.pop();
//     for(auto it:adjList[node])
//     {
//       int adjNode=it.first;
//       int edgeWeight=it.second;

//       if(cost+edgeWeight<dist[adjNode])
//       {
//         dist[adjNode]=cost+edgeWeight;
//         pq.push({dist[adjNode],adjNode});
//       }
//     }
//   }

//   vector<long long> dist_rev(n+1,LLONG_MAX);
//   priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq_rev;

//   dist_rev[destination]=0;
//   pq_rev.push({0,destination});

//   while(!pq_rev.empty())
//   {
//     int node=pq_rev.top().second;
//     long long cost=pq_rev.top().first;
    
//     pq_rev.pop();
//     for(auto it:adjList_rev[node])
//     {
//       int adjNode=it.first;
//       int edgeWeight=it.second;

//       if(cost+edgeWeight<dist_rev[adjNode])
//       {
//         dist_rev[adjNode]=cost+edgeWeight;
//         pq_rev.push({dist_rev[adjNode],adjNode});
//       }
//     }
//   }

//   long long minCost=LLONG_MAX;
//   for(auto edge:edges)
//   {
//     int u=edge[0];
//     int v=edge[1];
//     int wt=edge[2];
    
//      if (dist[u] == LLONG_MAX || dist_rev[v] == LLONG_MAX) continue;
//     long long cost=dist[u]+dist_rev[v]+(wt/2);

//     minCost=min(minCost,cost);
//   }
  
//   return minCost;
// }

// int main()
// {
//   int n,m;
//   cin>>n>>m;
//   vector<vector<int>> edges(m,vector<int>(3,0));
//   for(int i=0; i<m; i++)
//   {
//     int u,v,wt;
//     cin>>u>>v>>wt;
//     edges[i][0]=u;
//     edges[i][1]=v;
//     edges[i][2]=wt;
//   }

//   cout<<FlightDiscount(n,edges)<<endl;

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector<long long> dijkstra(int n, int start, const vector<vector<pair<int,int>>>& adj) {
    vector<long long> dist(n+1, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();
        if (d > dist[node]) continue; // skip outdated entry

        for (auto [v, w] : adj[node]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

long long FlightDiscount(int n, vector<array<int,3>>& edges) {
    vector<vector<pair<int,int>>> adj(n+1), adj_rev(n+1);

    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj_rev[v].push_back({u, w});
    }

    // forward distances from 1
    auto dist = dijkstra(n, 1, adj);
    // backward distances from n
    auto dist_rev = dijkstra(n, n, adj_rev);

    long long ans = INF;
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] == INF || dist_rev[v] == INF) continue;
        ans = min(ans, dist[u] + (w / 2) + dist_rev[v]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<array<int,3>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << FlightDiscount(n, edges) << "\n";
}
