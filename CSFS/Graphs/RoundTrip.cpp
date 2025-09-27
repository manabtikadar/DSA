#include<bits/stdc++.h>
using namespace std;

vector<int> RoundTrip(int n,int m,vector<vector<int>& edges)
{
  unordered_map<int,list<int>> adjList;

  for(auto edge:edges)
  {
    int u=edge[0];
    int v=edge[1];

    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
}