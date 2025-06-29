#include <bits/stdc++.h> 

using namespace std;

void preparedAdjList(vector<vector<int>>& edges, unordered_map<int,list<int>>& adjList)
{
    for(auto edge:edges)
    {
        int u=edge[0];
        int v=edge[1];

        adjList[u].push_back(v);
    }
}
void print(unordered_map<int,list<int>>& adjList)
{
    for(auto i : adjList)
    {
        cout<<i.first<<"->";
        for(auto j : i.second)
        {
            cout<<j<<",";
        }
        cout<<endl;
    }
}
void dfsTopologicalSort(int node, unordered_map<int,list<int>>& adjList,stack<int>& ans,vector<bool>& visited)
{
    visited[node]=true;

    for(auto i: adjList[node])
    {
        if(!visited[i])
        {
            dfsTopologicalSort(i,adjList,ans,visited);
        }
    }
    ans.push(node);   
}
vector<int> topologicalSortDFS(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adjList;
    preparedAdjList(edges,adjList);
    print(adjList);

    stack<int> ans;
    vector<bool> visited(v,false);
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        {
         dfsTopologicalSort(i,adjList,ans,visited);
        }
    }
    vector<int> ans1;
    while(!ans.empty())
    {
        ans1.push_back(ans.top());
        ans.pop();
    }
    cout<<endl;
    for(int i=0; i<v; i++)
    {
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    return ans1;
}

// khan's algorithm for topological sort using BFS
// This algorithm is also known as Kahn's algorithm for topological sorting.
vector<int> topologicalSortBFS(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adjList;
    preparedAdjList(edges,adjList);
    //print(adjList);
    

    // find indegree of all nodes 
    vector<int> indegree(v,0);
    for(auto i:adjList)
    {
        for(auto j:i.second)
        {
            indegree[j]++;
        }
    }
    
    // insert all 0 indegree nodes into queue
    queue<int> q;
    for(int i=0; i<v; i++)
    {
        if(indegree[i]==0)
        {
          q.push(i);
        }
    }
    
    vector<int> ans;
    while(!q.empty())
    {
        int front = q.front();

        q.pop();
        
        ans.push_back(front);

        for(auto i : adjList[front])
        {
            indegree[i]--;
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
    }
    
    return ans;
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {4, 5}};
    int v = 6; // number of vertices
    int e = edges.size(); // number of edges

    vector<int> result = topologicalSortBFS(edges, v, e);
    
    cout << "Topological Sort: ";
    for (int i : result) {
      //if(i==0) continue; // Skip 0 if it's not part of the graph
      cout << i << " ";
    }
    cout << endl;

    return 0;
}