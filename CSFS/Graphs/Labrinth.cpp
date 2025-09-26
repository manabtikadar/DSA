#include<bits/stdc++.h>
using namespace std;

bool bfs(pair<int,int>& start, pair<int,int>& end, vector<vector<char>>& map, vector<vector<int>>& visited, int& count, string& path)
{
  int n=map.size();
  int m=map[0].size();
  int start_row=start.first;
  int start_col=start.second;
  int end_row=end.first;
  int end_col=end.second;

  visited[start_row][start_col]=1;
  queue<pair<int,pair<int,int>>> q;
  q.push({0,{start_row,start_col}});

  vector<int> delrow={-1,0,+1,0};
  vector<int> delcol={0,+1,0,-1};
  vector<char> dir={'U','R','D','L'};
  
  vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
  parent[start_row][start_col]={start_row,start_col};
  vector<vector<char>> move(n,vector<char>(m,' '));

  while(!q.empty())
  {
      int front_row=q.front().second.first;
      int front_col=q.front().second.second;
      int dis=q.front().first;
      q.pop();

      if(front_row==end_row && front_col==end_col)
      {
        count = dis;
        int r=end_row;
        int c=end_col; 
        while(!(r==start_row && c==start_col))
        {
          path.push_back(move[r][c]);
          int pr=parent[r][c].first;
          int pc=parent[r][c].second;
          r=pr;
          c=pc;
        }
        reverse(path.begin(), path.end());
        return true;
      }
      
      for(int i=0; i<4; i++)
      {
        int nrow=front_row+delrow[i];
        int ncol=front_col+delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0)
        {      
          visited[nrow][ncol]=1;
          parent[nrow][ncol]={front_row,front_col};
          move[nrow][ncol]=dir[i];
          q.push({dis+1,{nrow,ncol}});
        }
      }
  }
  return false;
}

bool find_path(vector<vector<char>>& map, int& count, string& path)
{
  int n=map.size();
  int m=map[0].size();

  vector<vector<int>> visited(n,vector<int>(m,0));
  pair<int,int> start;
  pair<int,int> end;

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      if(map[i][j]=='#')
      {
        visited[i][j]=1;
      }
      else if(map[i][j]=='.')
      {
        visited[i][j]=0;
      }
      else if(map[i][j]=='A')
      {
        start={i,j};
      }
      else
      {
        end={i,j};
      }
    }
  }

  return bfs(start,end,map,visited,count,path);
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<char>> map(n,vector<char>(m));
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      cin>>map[i][j];
    }
  }

  int count=0;
  string path="";
  if(find_path(map,count,path))
  {
    cout<<"YES"<<endl;
    cout<<count<<endl;
    cout<<path<<endl;
  }
  else
  {
    cout<<"NO"<<endl;
  }

  return 0;
}