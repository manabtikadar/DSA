#include<bits/stdc++.h>

using namespace std;

class DisjointSet
{
  private:
    vector<int> parent;
    vector<int> size;
  public:
    DisjointSet(int n)
    {
      size.resize(n+1,1);
      parent.resize(n+1,1);
      for(int i=0; i<=n; i++)
      {
        parent[i]=i;
      }
    }
    
    int findUpar(int node)
    {
      if(parent[node]==node)
      {
        return node;
      }     
      return parent[node]=findUpar(parent[node]);
    }
    
    int connectedto(int node)
    {
      int ulp=findUpar(node);
      return size[ulp];
    }
    void UnionBySize(int u, int v)
    {
       int ulp_u=findUpar(u);
       int ulp_v=findUpar(v);

       if(ulp_u==ulp_v) return;

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
};

vector<int> findConnectedPeople(int connection_nodes, int connection_edges, vector<int> connection_from, vector<int> connection_to, vector<int> queries)
{
  DisjointSet ds(connection_nodes);
  for(int i=0; i<connection_edges; i++)
  {
    ds.UnionBySize(connection_from[i],connection_to[i]);
  }

  int n=queries.size();

  vector<int> result(n);
  for(int i=0; i<n; i++)
  {
    result[i]=ds.connectedto(queries[i]);
  }
  return result;
}

int main()
{
  int connection_nodes = 7;
  int connection_edges = 4;
  vector<int> connection_from = {1, 2, 3, 5};
  vector<int> connection_to = {2, 3, 4, 6};
  vector<int> queries = {1, 3, 5, 7};

  vector<int> result = findConnectedPeople(connection_nodes, connection_edges, connection_from, connection_to, queries);
  
  for(int count : result)
  {
    cout << count << " ";
  }
  
  cout << endl;
  
  return 0;
}