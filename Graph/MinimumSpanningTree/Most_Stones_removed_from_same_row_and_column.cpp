#include<bits/stdc++.h>

using namespace std;

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
        if(node==parent[node])
        {
          return node;
        }

        return parent[node]=findUpar(parent[node]);
    }

    void UnionBySize(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u==ulp_v) return;

        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        
        for(auto it:stones)
        {
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }

        int m=maxrow+maxcol+2;
        DisjointSet ds(maxrow+maxcol+2);
        vector<int> stoneNodes(maxrow+maxcol+2);
        for(auto stone:stones)
        {
            int row=stone[0];
            int col=stone[1];

            int shifted_col=col+maxrow+1;

            ds.UnionBySize(row,shifted_col);
            stoneNodes[row]=1;
            stoneNodes[shifted_col]=1;
        }

        int count=0;
        for(int i=0; i<m; i++)
        {
            if(stoneNodes[i]==1 && ds.findUpar(i)==i)
            {
                count++;
            }
        }

        return n-count;
    }
};

int main()
{
  int n = 6;
  vector<vector<int>> stones = {
      {0, 0}, {0, 2},
      {1, 3}, {3, 1},
      {3, 2}, {4, 3}
  };

  Solution obj;
  int ans = obj.removeStones(stones);
  cout << "The maximum number of stones we can remove is: " << ans << endl;
  return 0;
}