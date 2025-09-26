#include<bits/stdc++.h>
using namespace std;

bool numRoutes(int n,vector<vector<int>>& edges,int& noComputers, vector<int>& path)
{
  int m=edges.size();
  unordered_map<int,list<int>> adjList;
  for(auto edge:edges)
  {
    int u=edge[0];
    int v=edge[1];

    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  
  vector<int> visited(n+1,0);
  vector<int> parent(n+1,-1);
  int start=1;
  int end=n;
  queue<pair<int,int>> q;
  q.push({0,start});

  visited[start]=1;
  parent[start]=start;

  while(!q.empty())
  {
    int front_node=q.front().second;
    int dist = q.front().first;

    q.pop();
    
    if(front_node==n)
    {
      int node=front_node;
      while(node!=parent[node])
      {
        path.push_back(node);
        node=parent[node];
      }
      path.push_back(start);
      noComputers=path.size();
      reverse(path.begin(), path.end());
      return true;
    }

    for(auto neighbour:adjList[front_node])
    {
      if(!visited[neighbour])
      {
        visited[neighbour]=1;
        parent[neighbour]=front_node;
        q.push({dist+1,neighbour});
      }
    }
  }

  return false;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>> edges(m,vector<int>(2,0));
  for(int i=0; i<m; i++)
  {
    cin>>edges[i][0]>>edges[i][1];
  }

  vector<int> path;
  int noComputers=0;
  if(numRoutes(n,edges,noComputers,path))
  {
    cout<<noComputers<<endl;
    for(auto i:path)
    {
      cout<<i<<" ";
    }
    cout<<endl;
  }
  else
  {
    cout<<"IMPOSSIBLE"<<endl;
  }
  
  return 0;
}