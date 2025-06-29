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
    int findUpar(int u)
    {
        if(u==parent[u])
        {
            return u;
        }

        return parent[u]=findUpar(parent[u]);
    }

    void UnionBySize(int u, int v)
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string, int> mapMailnode;

        DisjointSet ds(n);
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                string email=accounts[i][j];
                if(mapMailnode.find(email)==mapMailnode.end())
                {
                    mapMailnode[email]=i;
                }
                else
                {
                   ds.UnionBySize(mapMailnode[email],i);
                }
            }
        }

        unordered_map<int, set<string>> MergeMails;
        for(auto it : mapMailnode)
        {
            string mail=it.first;
            int node=it.second;

            int ulp_node=ds.findUpar(node);
            MergeMails[ulp_node].insert(mail);
        }

        vector<vector<string>> ans;
        for(auto i : MergeMails)
        {
            int u = i.first;
            vector<string> temp;
            temp.push_back(accounts[u][0]);

            for(auto j : i.second)
            {
                temp.push_back(j);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{

    vector<vector<string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };


    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);
    for (auto acc : ans) {
        cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++) {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
