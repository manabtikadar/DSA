#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<char>>& Map, vector<vector<int>>& visited)
{
  int n=Map.size();
  int m=Map[0].size();
  visited[row][col]=1;
  
  queue<pair<int,int>> q;
  q.push({row,col});
  vector<int> delrow={-1,0,+1,0};
  vector<int> delcol={0,+1,0,-1};

  while(!q.empty())
  {
    auto front=q.front();
    int per_row=front.first;
    int per_col=front.second;
    q.pop();

    for(int i=0; i<4; i++)
    {
      int nrow=per_row+delrow[i];
      int ncol=per_col+delcol[i];

      if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && Map[nrow][ncol]=='.' && !visited[nrow][ncol])
      {
        visited[nrow][ncol]=1;
        q.push({nrow,ncol});
      }
    }
  }
}

int numRooms(vector<vector<char>>& Map)
{
  int n=Map.size();
  int m=Map[0].size();

  vector<vector<int>> visited(n,vector<int>(m,0));
  
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      if(Map[i][j]=='#')
      {
        visited[i][j]=1;
      }
      else if(Map[i][j]=='.')
      {
        visited[i][j]=0;
      }
    }
  }
  
  int count=0;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      if(Map[i][j]=='.' && !visited[i][j])
      {
        bfs(i,j,Map,visited);
        count++;
      }
    }
  }

  return count;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<char>> Map(n,vector<char>(m));
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      cin>>Map[i][j];
    }
  }

  cout<<numRooms(Map)<<endl;

  return 0;
}