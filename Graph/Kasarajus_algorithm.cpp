#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& visited,stack<int>& st)
    {
        visited[node]=1;
        
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                dfs(it,adj,visited,st);
            }
        }
        st.push(node);
    }
    void dfs2(int node,vector<int>& visited,vector<int> adjT[],vector<int>& Temp)
    {
        visited[node]=1;
        Temp.push_back(node);
        for(auto it:adjT[node])
        {
            if(!visited[it])
            {
                dfs2(it,visited,adjT,Temp);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int V=adj.size();
        vector<int> visited(V,0);
        stack<int> st;
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,st);
            }
        }
        
        vector<int> adjT[V];
        for(int i=0; i<V; i++)
        {
            visited[i]=0;
            for(auto it:adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        int scc=0;
        vector<vector<int>> ans;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            vector<int> temp;
            if(!visited[node])
            {
                scc++;
                dfs2(node,visited,adjT,temp);
                ans.push_back(temp);
            }
        }
        
        cout << "Strongly Connected Components:" << endl;
        for (const auto& component : ans) {
            cout << "{ ";
            for (int v : component) {
                cout << v << " ";
            }
            cout << "}" << endl;
        }
        return scc;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {
        {1, 2},
        {2, 3},
        {3, 0},
        {4, 5},
        {5, 6},
        {6, 4}
    };
    
    int sccCount = sol.kosaraju(graph);
    cout << "Number of strongly connected components: " << sccCount << endl;

    return 0;
}