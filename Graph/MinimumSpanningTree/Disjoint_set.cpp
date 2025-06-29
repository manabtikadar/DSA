#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;
public:
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    
    int findUpar(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]); // path compression
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionbySize(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u]<size[ulp_v])
        {
          parent[ulp_u]= ulp_v;
          size[ulp_v] += size[ulp_u];
        }
        else if(size[ulp_v]<size[ulp_u])
        {
          parent[ulp_v]=ulp_u;
          size[ulp_u] += size[ulp_v];
        }
        else
        {
          parent[ulp_v]=ulp_u;
          size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int n = 7; // increased to handle nodes 6 and 7
    DisjointSet ds(n);

    ds.unionbySize(1, 2);
    ds.unionbySize(2, 3);
    ds.unionbySize(4, 5);
    ds.unionbySize(6, 7);
    ds.unionbySize(5, 6); 

    if(ds.findUpar(3) == ds.findUpar(7))
    {
        cout << "3 and 7 are in the same component" << endl;
    }
    else
    {
        cout << "3 and 7 are in different components" << endl;
    }

    ds.unionbySize(3, 7);

    if(ds.findUpar(3) == ds.findUpar(7))
    {
        cout << "3 and 7 are in the same component" << endl;
    }
    else
    {
        cout << "3 and 7 are in different components" << endl;
    }


    return 0;
}
