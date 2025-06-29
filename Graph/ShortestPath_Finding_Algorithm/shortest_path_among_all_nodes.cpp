#include<bits/stdc++.h>

using namespace std;

class Solution{
 public:
  void preparedAdjList(vector<vector<int>>& edges, unordered_map<int, list<int>>& adjList)
  {
    for(auto edge : edges)
    {
      int u=edge[0];
      int v=edge[1];

      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
  }
  vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
  {
    unordered_map<int, list<int>> adjList;
	  preparedAdjList(edges,adjList);

	  unordered_map<int,bool> visited;
    vector<int> shortestPath(N, 0);

    queue<int> q;
    q.push(src);
    visited[src]=true;
    
    int level = 0;
    while(!q.empty())
    {
      int sz = q.size();
      for(int i=0; i<sz; i++)
      {
        int front = q.front();
        q.pop();

        shortestPath[front]=level;
        for(auto i:adjList[front])
        {
          if(!visited[i])
          {
            q.push(i);
            visited[i]=true;
          }
        }
      }
      level++;
    }
    
    for(int i=0; i<N; i++)
    {
      if(!visited[i])
      {
        shortestPath[i] = -1; // Node not reachable
      }
    }

    return shortestPath;
  }
  
  // optimized version of shortestPath
  vector<int> shortestPath2(vector<vector<int>>& edges, int N,int M, int src)
  {
    unordered_map<int, list<int>> adjList;
	  preparedAdjList(edges,adjList);

    vector<int> shortestPath(N, INT32_MAX);

    queue<int> q;
    q.push(src);
    shortestPath[src] = 0;

    while(!q.empty())
    {
      int front = q.front();
      q.pop();

      for(auto i:adjList[front])
      {
        if(shortestPath[front]+1 < shortestPath[i])
        {
          shortestPath[i] = shortestPath[front] + 1;
          q.push(i);
        }
      }
    }

    return shortestPath;
  }
};

int main(){

  int N=9, M=10;
  vector<vector<int>> edges= {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};

  Solution obj;
  vector<int> ans = obj.shortestPath2(edges,N,M,0);

  for(int i=0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }

  return 0;
}