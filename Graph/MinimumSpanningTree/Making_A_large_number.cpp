#include<bits/stdc++.h>

using namespace std;

class DisjointSet
{
public:
    vector<int> size,parent;
    DisjointSet(int n)
    {
        size.resize(n,1);
        parent.resize(n);
        for(int i=0; i<n; i++)
        {
            parent[i]=i;
        }
    }
    int findUpar(int u)
    {
        if(u==parent[u])
        {
            return u;
        }
        return parent[u]=findUpar(parent[u]);
    }
    void UnionBySize(int u,int v)
    {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);

        if(ulp_u==ulp_v)
        {
            return;
        }

        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

    int findsize(int u)
    {
        return size[u];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0) continue;
                
                int curr_node = i*n+j;

                vector<int> delrow={-1,0,+1,0};
                vector<int> delcol={0,+1,0,-1};
                for(int k=0; k<4; k++)
                {
                    int nrow=i+delrow[k];
                    int ncol=j+delcol[k];

                    int adjNode=nrow*n+ncol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {
                        ds.UnionBySize(curr_node,adjNode);
                    }
                }
                
            }
        }
        
        int ans=INT_MIN;
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col]==1) continue;
                
                int currNode=row*n+col;
                vector<int> delrow={-1,0,+1,0};
                vector<int> delcol={0,+1,0,-1};
                set<int> s;
                for(int i=0 ; i<4; i++)
                {
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                    
                    // if(grid[nrow][ncol]==0) continue; 
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {   int adjNode=nrow*n+ncol;

                        int ulp_adjNode=ds.findUpar(adjNode);
                        s.insert(ulp_adjNode);
                    }
                }
                int count=1;
                while(!s.empty())
                {
                    int val=*s.begin();
                    count += ds.findsize(val);
                    s.erase(s.begin());
                }

                ans=max(ans,count);
            }
        }
        
        for(int i=0; i<n*n; i++)
        {
            ans=max(ans, ds.size[ds.findUpar(i)]);
        }
        
        return ans;
    }
};

int main() {

    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0}, {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 0}
    };

    Solution obj;
    int ans = obj.largestIsland(grid);
    cout << "The largest group of connected 1s is of size: " << ans << endl;
    return 0;
}