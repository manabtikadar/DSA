#include<bits/stdc++.h>
using namespace std;

bool isPossible(int node, vector<int>& visited, unordered_map<int,list<int>>& adjList,vector<int>& ans)
{
  queue<pair<int,int>> q;
  visited[node]=1;
  q.push({0,node});
  ans[node]=0;

  while(!q.empty())
  {
    int front_node=q.front().second;
    bool team=q.front().first;
    q.pop();

    for(auto neighbour:adjList[front_node])
    {
      if(!visited[neighbour])
      {
        visited[neighbour]=1;
        ans[neighbour]=(!team);
        q.push({(!team),neighbour});
      }
      else
      {
        if(ans[neighbour]==team)
        {
          return false;
        }
      }
    }
  }

  return true;
}

vector<int> BuildTeams(int n, int m, vector<vector<int>>& edges)
{
  unordered_map<int,list<int>> adjList;

  // prepared adjList
  for(auto edge : edges)
  {
    int u=edge[0];
    int v=edge[1];

    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  vector<int> visited(n+1,0);
  vector<int> ans(n+1);

  for(int i=1; i<=n; i++)
  {
    if(!visited[i])
    {
      bool Possible=isPossible(i,visited,adjList,ans);

      if(!Possible)
      {
        return {};
      }
    }
  }

  // no cycle detected --> the members can split into two groups
  for(int i=0; i<=n; i++)
  {
    ans[i]++;
  }

  return ans;
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

  vector<int> ans=BuildTeams(n,m,edges);
  if(ans.size()==0)
  {
    cout<<"IMPOSSIBLE"<<endl;
  }
  else
  {
    for(int i=1; i<=n; i++)
    {
      cout<<ans[i]<<" ";
    }
    cout<<endl;
  }
}