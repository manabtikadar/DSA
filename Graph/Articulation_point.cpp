#include<bits/stdc++.h>

using namespace std;

class Solution {
  private:
    int Timer=0;
  public:
    void dfs(int node, vector<int> adj[],vector<bool>& visited,vector<int>& parent,vector<int>& tin,vector<int>& low,vector<int>& mark)
    {
        visited[node]=1;
        tin[node]=low[node]=Timer;
        Timer++;
        int child=0;
        for(auto it:adj[node])
        {
            if(parent[node] == it) continue;
            if(!visited[it])
            {
                parent[it]=node;
                dfs(it,adj,visited,parent,tin,low,mark);
                low[node]=min(low[node],low[it]);
                
                if(low[it]>=tin[node] && parent[node]!=-1)
                {
                    mark[node]=1;
                }
                child++;
            }
            else
            {
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child>1 && parent[node]==-1)
        {
            mark[node]=1;
        }
    }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        vector<int> parent(V,-1);
        vector<int> tin(V,-1);
        vector<int> low(V,-1);
        
        vector<int> mark(V,0); // Mark which are articulation point
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                dfs(0,adj,visited,parent,tin,low,mark);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<V; i++)
        {
            if(mark[i]==1)
            {
                ans.push_back(i);
            }
        }
        
        if(ans.size()==0) return {-1};
        return ans;
    }
};

int main() {
    // Example usage
    Solution sol;
    int V = 5; // Number of vertices
    vector<int> adj[V];
    
    // Example edges (0-based indexing)
    adj[0] = {1, 2};
    adj[1] = {0, 2, 3};
    adj[2] = {0, 1};
    adj[3] = {1, 4};
    adj[4] = {3};

    vector<int> articulationPoints = sol.articulationPoints(V, adj);
    
    for(int point : articulationPoints) {
        cout << point << " ";
    }
    
    return 0;
}