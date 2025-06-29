#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void preparedAdjList(vector<vector<int>>& edges,unordered_map<int,list<pair<int,int>>>& adjList)
  {
      for(auto edge : edges)
      {
          int u = edge[0];
          int v = edge[1];

          int value = edge[2];

          adjList[u].push_back({v,value});
          adjList[v].push_back({u,value});
      }
  }
  vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
      unordered_map<int,list<pair<int,int>>> adjList;
      preparedAdjList(vec,adjList);

      set<pair<int,int>> s;
      vector<int> distance(vertices,INT_MAX);

      distance[source]=0;
      s.insert({distance[source],source});

      while(!s.empty())
      {
          int top_node = (*s.begin()).second;
          int top_distance = (*s.begin()).first;
          
          s.erase({top_distance,top_node});

          for(auto i:adjList[top_node])
          {
            if((top_distance+i.second)<distance[i.first])
            {
                if(distance[i.first]!=INT_MAX)
                {
                    s.erase({distance[i.first],i.first});
                }
                distance[i.first]=top_distance+i.second;
                s.insert({distance[i.first],i.first});
            }
          }

      }
      return distance;
  }

  vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src, int end){
      unordered_map<int,list<pair<int,int>>> adjList;
      preparedAdjList(edges,adjList);

      // min Heap configuration for priority queue where the top element is the shortest element and the shorting is based on the first element of the pair
      // Create a priority queue for storing the nodes as a pair {dist,node}
      // where dist is the distance from source to the node.
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

      vector<int> distance(N, INT_MAX);
      vector<int> parent(N); // To store the parent of each node for path reconstruction

      for(int i=0; i<N; i++) {
          parent[i] = i; // Initialize parent to itself
      }

      distance[src] = 0;
      pq.push({0, src}); // Push the source node with distance 0

      while(!pq.empty())
      {
        auto it = pq.top();
        int dist = it.first;
        int node = it.second;

        pq.pop();

        for(auto i : adjList[node])
        {
            int adjNode = i.first;
            int edgeWeight = i.second;

            if(dist + edgeWeight < distance[adjNode])
            {
                distance[adjNode]= dist + edgeWeight;
                parent[adjNode] = node; // Update the parent of the adjacent node
                // If the node is already in the priority queue, we need to remove it first
                pq.push({distance[adjNode], adjNode});
            }
        }
      }

      if(distance[end] == INT_MAX) {
          return {-1}; // If the end node is unreachable, return -1
      }

      vector<int> path;
      int currentNode = end;
      while(parent[currentNode] != currentNode)
      {
          path.push_back(currentNode);
          currentNode = parent[currentNode];
      }
      path.push_back(src); // Add the source node at the end
      reverse(path.begin(), path.end()); // Reverse the path to get it from source to end     

      return path;
  }
};

int main() {
    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 1}, {1, 2, 2}, {1, 3, 5}, {2, 3, 8}, {2, 4, 10}, {3, 4, 2}};
    int vertices = 5; // number of vertices
    int edgesCount = edges.size(); // number of edges
    int source = 0; // starting node

    Solution sol;
    vector<int> result = sol.dijkstra(edges, vertices, edgesCount, source);
    vector<int> path = sol.shortestPath(edges, vertices, edgesCount, source, 4); // Example to find path from source to node 4

    cout << "Shortest distances from source node " << source << ": ";
    for (int i : result) {
        if (i == INT_MAX) {
            cout << "INF ";
        } else {
            cout << i << " ";
        }
    }
    cout << endl;
    
    cout << "Shortest path from source to node 4: "; 
    if (path.size() == 1 && path[0] == -1) {
        cout << "No path exists." << endl;
    } else {
        for (int i : path) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}