#include<bits/stdc++.h>

using namespace std;

void preparedAdjList(vector<pair<int,int>>& edges, map<int,set<int>>& adjList)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;

        adjList[u].insert(v);

    }
}
void printAdjList(map<int,set<int>>& adjList)
{
    for(auto i:adjList)
    {
        cout<<i.first<<"->";
        for(auto j : i.second)
        {
            cout<<j<<",";
        }
        cout<<endl;
    }
}
bool isCycleDirectedDfs(int node,map<int,set<int>>& adjList,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsvisited)
{
  visited[node]=true;
  dfsvisited[node]=true;

  for(auto neighbour : adjList[node])
  {
    if(!visited[neighbour])
    {
      bool cycleDetected = isCycleDirectedDfs(neighbour,adjList,visited,dfsvisited);
      if(cycleDetected)
         return true;
    }
    else if(dfsvisited[neighbour])
    {
      return true;
    }
  }

  dfsvisited[node]=false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   
    map<int,set<int>> adjList;
    preparedAdjList(edges,adjList);
    //printAdjList(adjList);

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            bool ans=isCycleDirectedDfs(i,adjList,visited,dfsvisited);

            if(ans)
            {
              return 1;
            }
        }
    }
    return 0;
}

int detectCycleInDirectedGraphBFS(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int>> adjList;
    preparedAdjList(edges,adjList);
    //print(adjList);
    

    // find indegree of all nodes 
    vector<int> indegree(n,0);
    for(auto i:adjList)
    {
        for(auto j:i.second)
        {
            indegree[j]++;
        }
    }
    
    // insert all 0 indegree nodes into queue
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        if(indegree[i]==0)
        {
          q.push(i);
        }
    }
    
    int count=0;
    while(!q.empty())
    {
        int front = q.front();

        q.pop();
        
        count++;

        for(auto i : adjList[front])
        {
            indegree[i]--;
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
    }
    
    if(count==n)
    {
        return 0;
    }
    return 1;
}

int main()
{
  int n;
  int m;
   
  cout<<"Enter no of nodes and edges:"<<endl;
  cin>>n>>m;
  
  cout<<"Enter Edges:"<<endl;
  vector<pair<int,int>> edges(m);
  for(int i=0; i<m; i++)
  {
    
      int x;
      int y;
      cin>>x>>y;
      edges[i].first=x;
      edges[i].second=y;
  
  }

  cout<<"cycle detected:"<<detectCycleInDirectedGraph(n,edges)<<endl;
  return 0;
}