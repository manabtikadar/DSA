#include<bits/stdc++.h>

using namespace std;

void preparedAdjList(vector<vector<int>>& edges, map<int,set<int>>& adjList)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);

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
bool isCycleBfs(int node,map<int,set<int>>& adjList,unordered_map<int,bool>& visited)
{
    unordered_map<int,int> parent;
    queue<int> q;

    q.push(node);
    parent[node]=-1;
    visited[node]=1;

    while(!q.empty())
    {
        int front_node=q.front();
        q.pop();

        for(auto i : adjList[front_node])
        {
            if(!visited[i] && parent[front_node]!=i)
            {
                q.push(i);
                visited[i]=1;
                parent[i]=front_node;
            }
            else if(visited[i] && parent[front_node]!=i)
            {
                return true;
            }
            else
            {
                continue;
            }
        }
    }
    return false;
}
bool isCycleDfs(int node,map<int,set<int>>& adjList,unordered_map<int,bool>& visited,int parent)
{
    visited[node]=true;

    for(auto i : adjList[node])
    {
        if(!visited[i])
        {
            bool cycleDetected = isCycleDfs(i,adjList,visited,node);
            if(cycleDetected)
            {
                return true;
            }
        }
        else if(visited[i] && i!=parent)
        {
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    map<int,set<int>> adjList;
    preparedAdjList(edges,adjList);
    //printAdjList(adjList);

    unordered_map<int,bool> visited;

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            bool ans = isCycleDfs(i,adjList,visited,-1);

            if (ans==1)
              return "Yes";
        }
    }
    
    return "No";
}

int main()
{
  int n;
  int m;
   
  cout<<"Enter no of nodes and edges:"<<endl;
  cin>>n>>m;
  
  cout<<"Enter Edges:"<<endl;
  vector<vector<int>> edges(m,vector<int>(2,0));
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<2; j++)
    {
      int x;
      cin>>x;
      edges[i][j]=x;
    }
  }

  cout<<"cycle detected:"<<cycleDetection(edges,n,m)<<endl;
  return 0;
}