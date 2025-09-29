#include<bits/stdc++.h>
using namespace std;

vector<long long> shortestPath(long long n, long long m, vector<vector<long long>>& edges)
{
  //unordered_map<long long,list<pair<long long,long long>>> adjList;

  vector<vector<pair<long long, long long>>> adjList(n+1);
  
  // prepared adjacency list
  for(auto edge:edges)
  {
    long long u=edge[0];
    long long v=edge[1];
    long long w=edge[2];

    adjList[u].push_back({v,w});
  }

  priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
  vector<long long> distance(n+1,LLONG_MAX);

  distance[1]=0;
  pq.push({0,1}); // {distance,node}

  while(!pq.empty())
  {
    long long dist=pq.top().first;
    long long node=pq.top().second;
    pq.pop();
    if (dist > distance[node]) continue;
    for(auto it:adjList[node])
    {
      long long adjNode=it.first;
      long long edgeWeight=it.second;

      if(dist+edgeWeight<distance[adjNode])
      {
        distance[adjNode]=dist+edgeWeight;
        pq.push({distance[adjNode],adjNode});
      }
    }
  }

  return distance;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m;
  cin>>n>>m;

  vector<vector<long long>> edges(m,vector<long long>(3));
  for(int i=0; i<m; i++)
  {
    cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
  }

  vector<long long> result=shortestPath(n,m,edges);
  for(long long i=1; i<=n; i++)
  {
      cout<<result[i]<<" ";
  }
  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<long long> shortestPath(int n, int m, vector<vector<long long>>& edges) {
//     vector<vector<pair<int,long long>>> adj(n+1);
//     for (auto &edge : edges) {
//         int u = edge[0], v = edge[1];
//         long long w = edge[2];
//         adj[u].push_back({v,w});
//     }

//     vector<long long> dist(n+1, LLONG_MAX);
//     priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

//     dist[1] = 0;
//     pq.push({0,1});

//     while (!pq.empty()) {
//         auto [d,u] = pq.top(); pq.pop();
//         if (d > dist[u]) continue;  // skip outdated

//         for (auto [v,w] : adj[u]) {
//             if (d + w < dist[v]) {
//                 dist[v] = d + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
//     return dist;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n,m;
//     cin >> n >> m;

//     vector<vector<long long>> edges(m, vector<long long>(3));
//     for (int i=0; i<m; i++) {
//         cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
//     }

//     vector<long long> result = shortestPath(n,m,edges);
//     for (int i=1; i<=n; i++) {
//         cout << result[i] << (i==n ? '\n' : ' ');
//     }
// }
