#include<bits/stdc++.h>
using namespace std;

int bfs(int src,int n,int m,unordered_map<int,list<int>>& adjList,vector<int>& visited)
{
  visited[src]=1;

  queue<int> q;
  q.push(src);

  while(!q.empty())
  {
    int front_node=q.front();
    q.pop();

    for(auto neighbour : adjList[front_node])
    {
      if(!visited[neighbour])
      {
        q.push(neighbour);
        visited[neighbour]=1;
      }
    }
  }
  
  return src;
}
int numofRoadBuilding(int n,vector<vector<int>>& edges,vector<vector<int>>& citiesToBuild)
{
  int m=edges.size();
  unordered_map<int,list<int>> adjList;
  
  for(int i=0; i<m; i++)
  {
    int u=edges[i][0];
    int v=edges[i][1];

    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  vector<int> visited(n+1,0);
  int components=0;
  vector<int> cities;
  for(int i=1; i<=n; i++)
  {
    if(!visited[i])
    {
      int city=bfs(i,n,m,adjList,visited);
      cities.push_back(city);
      components++;
    }
  }
  int k=components-1;

  for(int i=0; i<k; i++)
  {
    citiesToBuild.push_back({cities[i],cities[i+1]});
  }
  
  return k;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>> edges(m,vector<int>(2));
  for(int i=0; i<m; i++)
  {
    cin>>edges[i][0]>>edges[i][1];
  }

  vector<vector<int>> citiesToBuild;
  int result=numofRoadBuilding(n,edges,citiesToBuild);
  cout<<result<<endl;
  if(result>0)
  {
     for(int i=0; i<citiesToBuild.size(); i++)
    {
      cout<<citiesToBuild[i][0]<<" "<<citiesToBuild[i][1]<<endl;
    }
  }
  return 0;
}