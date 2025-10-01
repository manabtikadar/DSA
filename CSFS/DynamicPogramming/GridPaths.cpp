#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

void dfs(int n,int row,int col,vector<vector<char>>& Grid,int& count)
{
  if(row==n-1 && col==n-1)
  {
    count=(count+1)%mod;
    return;
  }
  vector<int> delrow={0,+1};
  vector<int> delcol={+1,0};

  for(int i=0; i<2; i++)
  {
    int nrow=row+delrow[i];
    int ncol=col+delcol[i];

    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && Grid[nrow][ncol]!='*')
    {
      dfs(n,nrow,ncol,Grid,count);
    }
  }
}

int GridPaths(int n,vector<vector<char>>& Grid)
{
  int count=0;
  dfs(n,0,0,Grid,count);

  return count%mod;
}

int GridPathsTab(int n,vector<vector<char>>& Grid)
{
  vector<vector<int>> dp(n,vector<int>(n,0));
  
  int i=0;
  while(i<n && Grid[i][0]!='*')
  {
    dp[i][0]=1;
    i++;
  }

  int j=0;
  while(j<n && Grid[0][j]!='*')
  {
    dp[0][j]=1;
    j++;
  }

  for(int i=1; i<n; i++)
  {
    for(int j=1; j<n; j++)
    {
      if(Grid[i][j]=='*')
      {
        dp[i][j]=0;
      }
      else
      {
        dp[i][j]=((dp[i-1][j]%mod)+(dp[i][j-1]%mod))%mod;
      }
    }
  }

  return (dp[n-1][n-1]%mod);
}

int main()
{
  int n;
  cin>>n;
  vector<vector<char>> Grid(n,vector<char>(n));
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      cin>>Grid[i][j];
    }
  }

  cout<<GridPathsTab(n,Grid);
  return 0;
}