#include<bits/stdc++.h>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};
void preparedAdjList(map<pair<int,int>,set<pair<int,int>>>& adjList, vector<vector<int>>& grid, vector<pair<int,int>>& root_nodes)
{
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[0].size(); j++)
        {
            if(grid[i][j]!=0)
            {
                if (i + 1 < grid.size() && grid[i + 1][j] != 0) {
                    adjList[{i,j}].insert({i+1,j});
                }

                if (j + 1 < grid[0].size() && grid[i][j + 1] != 0) {
                    adjList[{i,j}].insert({i,j+1});
                }

                if (i - 1 >= 0 && grid[i - 1][j] != 0) {
                    adjList[{i,j}].insert({i-1,j});
                }

                if (j - 1 >= 0 && grid[i][j - 1] != 0) {
                    adjList[{i,j}].insert({i,j-1});
                }
            }
        }
    }
}
void printAdjList(map<pair<int,int>,set<pair<int,int>>>& adjList)
{
    for(auto i:adjList)
    {
        cout<<"("<<i.first.first<<","<<i.first.second<<")"<<"->";
        for(auto j:i.second)
        {
            cout<<"("<<j.first<<","<<j.second<<")"<<",";
        }
        cout<<endl;
    }
}

int minuteToRotten(vector<pair<int,int>>& root_nodes,map<pair<int,int>,set<pair<int,int>>>& adjList,unordered_map<pair<int,int>,bool,pair_hash>& visited,vector<pair<int,int>>& ans,int&total_freshOrange)
{
    queue<pair<int,int>> q;
    for(auto node : root_nodes)
    {
        q.push(node);
        visited[node]=1;
    }
    int count=0;
    while(!q.empty())
    {
        int sz=q.size();
        int flag = 0;
        for(int i=0; i<sz; i++)
        {
            pair<int,int> frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);
            for(auto i:adjList[frontNode])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=1;
                    total_freshOrange--;
                    flag=1;
                }
            }
        }
        if(flag==1)
        {
            count++;
        }
    }
    return count;
}
int orangesRotting(vector<vector<int>>& grid) {
    vector<pair<int,int>> root_nodes;
    int total_freshOrange=0;
    int total_rottenOrange=0;
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[0].size(); j++)
        {
            if(grid[i][j]==2)
            {
                root_nodes.push_back({i,j});
                total_rottenOrange++;
            }
            if(grid[i][j]==1)
            {
                total_freshOrange++;
            }
        }
    }
    if(total_freshOrange==0 && total_rottenOrange!=0)
    {
        return 0;
    }
    if(total_freshOrange!=0 && total_rottenOrange==0)
    {
        return -1;
    }
    if(total_freshOrange==0 && total_rottenOrange==0)
    {
        return 0;
    }
    map<pair<int,int>,set<pair<int,int>>> adjList;
    preparedAdjList(adjList,grid,root_nodes);
    cout<<"Adjacency List:";
    printAdjList(adjList);
    // if(adjList.size()!=total_freshOrange+total_rottenOrange)
    // {
    //     return -1;
    // }
    unordered_map<pair<int,int>,bool,pair_hash> visited;
    vector<pair<int,int>> ans;
    
    int time=minuteToRotten(root_nodes,adjList,visited,ans,total_freshOrange);
    
    if(total_freshOrange!=0)
    {
        return -1;
    }
    return time;
}

int main()
{
  cout<<"Enter n & m respectively for n*m cross grid:"<<endl;
  int n;
  int m;
  cin>>n>>m;
  
  cout<<"Enter the grid values:"<<endl;
  vector<vector<int>> grid(n, vector<int>(m));
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      int x;
      cin>>x;
      grid[i][j]=x;
    }
  }

  cout<<"grid"<<endl;
  for(auto i:grid)
  {
    cout<<"[";
    for(auto j:i)
    {
      cout<<j<<",";
    }
    cout<<"]"<<endl;
  }

  cout<<" minimum number of minutes that must elapse until no cell has a fresh orange:"<<orangesRotting(grid);

  return 0;

}