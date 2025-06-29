#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
        vector<int> dist(n, INT32_MAX);
        dist[src]=0;
        
        // time complexity : V x E
        // V is the number of vertices and E is the number of edges
        for(int i=0; i<n-1; i++)
        {
            for(auto edge: edges)
            {
              int u=edge[0];
              int v=edge[1];
              int weight=edge[2];

              if(dist[u]!=INT32_MAX && dist[u]+weight < dist[v])
              {
                  dist[v]=dist[u]+weight;
              } 
            }
        }

        // Check for negative weight cycles
        for(auto edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            int weight=edge[2];

            if(dist[u]!=INT32_MAX && dist[u]+weight < dist[v])
            {
                cout << "Graph contains negative weight cycle" << endl;
                return {-1}; // Return an empty vector if a negative cycle is detected
            }
        }

        return dist;
    }
};

int main()
{
    Solution sol;
    int n = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    int src = 0; // Starting vertex

    vector<int> distances = sol.bellmanFord(n, edges, src);
    
    for (int i = 0; i < distances.size(); i++) {
        cout << "Distance from source to vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}