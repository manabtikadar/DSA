#include<bits/stdc++.h>

using namespace std;
class DisjointSet {
    vector<int> parent, rank, size;
public:
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    
    int findUpar(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]); // path compression
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionbySize(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u]<size[ulp_v])
        {
          parent[ulp_u]= ulp_v;
          size[ulp_v] += size[ulp_u];
        }
        else if(size[ulp_v]<size[ulp_u])
        {
          parent[ulp_v]=ulp_u;
          size[ulp_u] += size[ulp_v];
        }
        else
        {
          parent[ulp_v]=ulp_u;
          size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        vector<pair<int, pair<int, int>>> edges;
        // O(N+E)
        for(int i=0; i<V; i++)
        {
            for(auto it:adj[i])
            {
                //int node=it[0];
                int adjNode=it[0];
                int weight=it[1];
                int node = i;
                
                edges.push_back({weight,{node,adjNode}});
            }
        }
        
        DisjointSet ds(V);
        // O(MlogM)
        sort(edges.begin(),edges.end());
        int mnst=0;
        
        // O(M*4*alpha*2)
        for(auto edge:edges)
        {
            int w=edge.first;
            int u=edge.second.first;
            int v=edge.second.second;
            
            if(ds.findUpar(u) != ds.findUpar(v))
            {
                mnst += w;
                ds.unionByRank(u,v);
            }
            
        }
        
        return mnst;
    }
};

int main()
{
    int V = 5; // number of vertices
    vector<vector<int>> adj[V];
    
    // Example edges: {node1, node2, weight}
    adj[0] = {{1, 4}, {2, 1}};
    adj[1] = {{0, 4}, {2, 2}, {3, 5}};
    adj[2] = {{0, 1}, {1, 2}, {3, 8}, {4, 10}};
    adj[3] = {{1, 5}, {2, 8}, {4, 2}};
    adj[4] = {{2, 10}, {3, 2}};
    
    Solution sol;
    int result = sol.spanningTree(V, adj);
    
    cout << "Sum of weights of edges in the Minimum Spanning Tree: " << result << endl;
    
    return 0;
}