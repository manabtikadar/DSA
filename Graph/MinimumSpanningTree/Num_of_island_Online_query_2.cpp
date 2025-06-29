#include <bits/stdc++.h>

using namespace std;
// User function Template for C++
class DisjointSet
{
    vector<int> size,parent;
public:
    DisjointSet(int n)
    {
        size.resize(n,1);
        parent.resize(n);
        for(int i=0; i<n; i++)
        {
            parent[i]=i;
        }
    }
    int findUpar(int node)
    {
        if(node == parent[node])
        {
            return node;
        }
        
        return parent[node]=findUpar(parent[node]);
    }
    void UnionBySize(int u, int v)
    {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        
        if(ulp_u==ulp_v) return;
        
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>> visited(n,vector<int>(m,0));
        DisjointSet ds(n*m);
        vector<int> result;
        int k=operators.size();
        
        int count=0;
        
        for(auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            
            if(visited[row][col]==1)
            {
                result.push_back(count);
                continue;
            }
            
            visited[row][col]=1;
            count++;
            
            vector<int> delrow={-1,0,+1,0};
            vector<int> delcol={0,+1,0,-1};
            
            for(int i=0; i<4; i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m )
                {
                    if(visited[nrow][ncol])
                    {
                        int currNodeno=row*m+col;
                        int adjNodeno=nrow*m+ncol;
                        if(ds.findUpar(currNodeno)!=ds.findUpar(adjNodeno))
                        {
                            count--;
                            ds.UnionBySize(currNodeno,adjNodeno);
                        }
                    }
                    
                }
            }
            
            result.push_back(count);
        }
        
        
        return result;
    }
};

int main() {

    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };


    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
