#include<bits/stdc++.h>

using namespace std;

void preparedAdjList(vector<vector<int>>& edges,unordered_map<int,list<pair<int,int>>>& adjList)
{
    for(auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        int value = edge[2];

        adjList[u].push_back({v,value});
    }
}
void dfsTopoLogicalSort(int node,unordered_map<int,list<pair<int,int>>>& adjList,unordered_map<int,bool>& visited,stack<int>& s)
{
    visited[node]=true;

    for(auto i : adjList[node])
    {
        if(!visited[i.first])
        {
            dfsTopoLogicalSort(i.first,adjList,visited,s);
        }
    }
    s.push(node);
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    unordered_map<int,list<pair<int,int>>> adjList;
    preparedAdjList(edges,adjList);

    stack<int> s;
    unordered_map<int,bool> visited;

    dfsTopoLogicalSort(0,adjList,visited,s);

    vector<int> distance(n,INT_MAX);
    distance[0]=0;

    while(!s.empty())
    {
      int front = s.top();
      s.pop();
      if(distance[front]!=INT_MAX)
      {
          for(auto i : adjList[front])
          {
              if((distance[front]+i.second)<distance[i.first])
              {
                  distance[i.first]=distance[front]+i.second;
              }
          }
      }
    }
    for(int i=0; i<n; i++)
    {
        if(distance[i]==INT_MAX)
        {
            distance[i]=-1;
        }
    }
    return distance;
}

int main()
{
    vector<vector<int>> edges = {{0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {1, 2, 2}, {2, 4, 4}, {2, 5, 2}, {2, 3, 7}, {3, 5, 1}, {4, 5, 2}};
    int n = 6; // number of vertices
    int m = edges.size(); // number of edges

    vector<int> result = shortestPathInDAG(n, m, edges);

    cout << "Shortest Path Distances: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
