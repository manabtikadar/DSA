#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int timer=1;
public:
    void preparedAdjList(vector<vector<int>>& connections, unordered_map<int,list<int>>& adjList)
    {
        for(auto it : connections)
        {
            int u=it[0];
            int v=it[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    void dfs(int node,unordered_map<int,list<int>>& adjList,vector<bool>& visited,vector<int>& parent,vector<int>& tin,vector<int>& low,vector<vector<int>>& bridges)
    {
        visited[node]=1;
        tin[node]=low[node]=timer;
        timer++;

        for(auto neighbour : adjList[node])
        {
            if(neighbour==parent[node]) continue;
            if(!visited[neighbour])
            {
                parent[neighbour]=node;
                dfs(neighbour,adjList,visited,parent,tin,low,bridges);
                low[node]=min(low[node],low[neighbour]);

                if(low[neighbour]>tin[node])
                {
                    bridges.push_back({node,neighbour});
                }
            }
            else
            {
                low[node]=min(low[node],low[neighbour]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>> adjList;
        preparedAdjList(connections, adjList);

        vector<bool> visited(n,false);
        vector<int> parent(n,-1);
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<vector<int>> bridges;

        dfs(0,adjList,visited,parent,tin,low,bridges);
        return bridges;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    int n = 4;

    vector<vector<int>> result = obj.criticalConnections(n, connections);
    
    for (const auto& bridge : result) {
        cout << "[" << bridge[0] << ", " << bridge[1] << "]" << endl;
    }

    return 0;
}