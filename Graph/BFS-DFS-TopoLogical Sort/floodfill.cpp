#include<bits/stdc++.h>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};
void preparedAdjList(map<pair<int,int>,set<pair<int,int>>>& adjList, vector<vector<int>>& grid, int color)
{
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[0].size(); j++)
        {
            // if(grid[i][j]!=0)
            {
                if (i + 1 < grid.size() && grid[i + 1][j] == color) {
                    adjList[{i,j}].insert({i+1,j});
                }

                if (j + 1 < grid[0].size() && grid[i][j + 1] == color) {
                    adjList[{i,j}].insert({i,j+1});
                }

                if (i - 1 >= 0 && grid[i - 1][j] == color) {
                    adjList[{i,j}].insert({i-1,j});
                }

                if (j - 1 >= 0 && grid[i][j - 1] == color) {
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
void floodfill(pair<int,int> root_node,vector<vector<int>>& image,unordered_map<pair<int,int>,bool,pair_hash>& visited,map<pair<int,int>,set<pair<int,int>>>& adjList,int color)
{
    queue<pair<int,int>> q;
    q.push(root_node);
    image[root_node.first][root_node.second]=color;
    visited[root_node]=1;

    while(!q.empty())
    {
        pair<int,int> front_node = q.front();
        q.pop();

        for(auto i:adjList[front_node])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=1;
                image[i.first][i.second]=image[root_node.first][root_node.second];
            }
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m=image.size();
    int n=image[0].size();
    
    pair<int, int> root_node={sr,sc};
    map<pair<int,int>,set<pair<int,int>>> adjList;
    preparedAdjList(adjList,image,image[sr][sc]);
    cout<<"Adjacency List:"<<endl;
    printAdjList(adjList);
    
    unordered_map<pair<int,int>,bool,pair_hash> visited;
    floodfill(root_node,image,visited,adjList,color);
    return image;
}

int main()
{
  cout<<"Enter n & m respectively for n*m cross grid:"<<endl;
  int m;
  int n;
  cin>>m>>n;
  
  cout<<"Enter the grid values:"<<endl;
  vector<vector<int>> image(m, vector<int>(n));
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      int x;
      cin>>x;
      image[i][j]=x;
    }
  }

  cout<<"grid"<<endl;
  for(auto i:image)
  {
    cout<<"[";
    for(auto j:i)
    {
      cout<<j<<",";
    }
    cout<<"]"<<endl;
  }
  
  int sr;
  int sc;
  int color;

  cin>>sr>>sc>>color;

  image = floodFill(image,sr,sc,color);
  for(auto i:image)
  {
    cout<<"[";
    for(auto j:i)
    {
      cout<<j<<",";
    }
    cout<<"]"<<endl;
  }
  return 0;

}