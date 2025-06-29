#include<iostream>
#include<vector>

using namespace std;

int maximul_squre(vector<vector<int>> mat, int i, int j, int& maxi)
{
  //Base case
  if(i>=mat.size()||j>=mat[0].size())
  {
    return 0;
  }

  int right = maximul_squre(mat,i,j+1,maxi);
  int diagonal = maximul_squre(mat,i+1,j+1,maxi);
  int down = maximul_squre(mat,i+1,j,maxi);

  if(mat[i][j] == 1)
  {
    int ans = 1+min(right,min(diagonal,down));
    maxi=max(maxi,ans);
    return ans;
  }
  else
  {
    return 0;
  }
}

int maximul_squre_memoization(vector<vector<int>> mat, int i, int j, int& maxi, vector<vector<int>> dp)
{
  //Base case
  if(i>=mat.size()||j>=mat[0].size())
  {
    return 0;
  }

  if(dp[i][j] != -1)
  {
    return dp[i][j];
  }

  int right = maximul_squre_memoization(mat,i,j+1,maxi,dp);
  int diagonal = maximul_squre_memoization(mat,i+1,j+1,maxi,dp);
  int down = maximul_squre_memoization(mat,i+1,j,maxi,dp);

  if(mat[i][j] == 1)
  {
    dp[i][j] = 1+min(right,min(diagonal,down));
    maxi=max(maxi,dp[i][j]);
    return dp[i][j];
  }
  else
  {
    return 0;
  }
}

int maximul_squre_tabulation(vector<vector<int>> mat, int& maxi)
{
  int n1 = mat.size();
  int n2 = mat[0].size();
  vector<vector<int>> dp((n1+1),vector<int>((n2+1),0));

  for(int i=n1-1; i>=0; i--)
  {
    for(int j=n2-1; j>=0; j--)
    {
      int right = dp[i][j+1];
      int diagonal = dp[i+1][j+1];
      int down = dp[i+1][j];
      
      if(mat[i][j]==1)
      {
        dp[i][j]=1+min(right,min(diagonal,down));
        maxi = max(maxi,dp[i][j]);
      }
      else
      {
        dp[i][j]=0;
      }
    }
  }
  return dp[0][0];
}

void maximul_squre_spaceoptim(vector<vector<int>> mat,int& maxi)
{
  int n1 = mat.size();
  int n2 = mat[0].size();

  vector<int> curr(n2+1,0);
  vector<int> next(n2+1,0);

  for(int i=n1-1; i>=0; i--)
  {
    for(int j=n2-1; j>=0; j--)
    {
      int right = curr[j+1];
      int diagonal = next[j+1];
      int down = next[j];
      
      if(mat[i][j]==1)
      {
        curr[j]=1+min(right,min(diagonal,down));
        maxi = max(maxi,curr[j]);
      }
      else
      {
        curr[j]=0;
      }
    }
    next = curr;
  }
}

void maximul_more_spaceoptim(vector<vector<int>> mat,int& maxi)
{
  int n1 = mat.size();
  int n2 = mat[0].size();
  for(int i=n1-2; i>=0; i--)
  {
    for(int j=n2-2; j>=0; j--)
    {
      if(mat[i][j]==1)
      {
        mat[i][j]=1+min(mat[i][j+1],min(mat[i+1][j+1],mat[i+1][j]));
        maxi = max(maxi,mat[i][j]);
      }
      else
      {
        mat[i][j]=0;
      }
    }
  }
}


int main()
{
  int maxi = 0;
  vector<vector<int>> mat={{0,1},{1,0}};//{{1,0,1,0,0},{1,0,1,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
  int i=0;
  int j=0;
  vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(),-1));
  maximul_squre_memoization(mat,i,j,maxi,dp);
  cout<<maxi<<endl;
  maximul_more_spaceoptim(mat,maxi);
  cout<<maxi<<endl;
  return 0;
}