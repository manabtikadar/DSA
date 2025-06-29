#include <bits/stdc++.h>

using namespace std;

void preparedAdjList(vector<vector<int>>& edges, map<int,set<int>>& adjList)
{
    for(auto edge:edges)
    {
        int u=edge[0];
        int v=edge[1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void printAdjList(map<int,set<int>>& adjList)
{
    for(auto i : adjList)
    {
        cout<<i.first<<"->";

        for(auto j:i.second)
        {
            cout<<j<<",";
        }
        cout<<endl;
    }
}
void Traverse(int node, vector<int>& component, map<int, set<int>>& adjList,unordered_map<int,bool>& visited)
{
    component.push_back(node);
    visited[node]=1;

    for(auto i:adjList[node])
    {
        if(!visited[i]==true)
        {
            Traverse(i,component,adjList,visited);
        }
    }
}
bool checkCompleteComponent(vector<int>& component, map<int, set<int>>& adjList) {
    int size = component.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (adjList[component[i]].find(component[j]) == adjList[component[i]].end()) {
                return false; 
            }
        }
    }
    return true; 
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {
    map<int, set<int>> adjList;
    preparedAdjList(edges,adjList);
    // while(adjList.size()!=n)
    // {
    //     adjList[adjList.size()].insert(-1);
    // }
    // printAdjList(adjList);
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    for(int i=0; i<n; i++)
    {
        if(!visited[i]==true)
        {
            vector<int> component;
            Traverse(i, component, adjList, visited);
            ans.push_back(component);
        }
    }
    for(auto i : ans)
    {
        cout<<"{";
        for(auto j : i)
        {
        cout<<j<<",";
        }
        cout<<"}"<<endl;
    }
    int completeCount = 0;
    for(auto component : ans)
    {
        if(checkCompleteComponent(component, adjList)) {
            completeCount++;
        }
    }
    return completeCount;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    int result = countCompleteComponents(n, edges);
    cout << "Number of components: " << result << endl;
    // Example usage                            
    return 0;
}