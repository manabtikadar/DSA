#include<iostream>
#include<vector>

using namespace std;

// Number of ways of Triangulation ---> Catelan Numbers
int Triangulation(int n) {
  n=n-2;
  if (n <= 1) 
      return 1;

  int ans = 0;
  for (int i = 0; i<n; i++) {
      ans += Triangulation(i+2) * Triangulation(n-i+1);
  }
  return ans;
}

int Triangulation2(int n) {
  if (n <= 3) 
      return 1;

  int ans = 0;
  for (int i = 2,j = n-1; i<n,j>=2; i++,j--) {
      ans += Triangulation(i) * Triangulation(j);
  }
  return ans;
}

int MinScore_triangulation(vector<int> values, int i, int j)
{
  if(i+1==j)
  {
    return 0;
  }

  int ans = INT16_MAX;
  for(int k=i+1;k<j;k++)
  {
    ans = min(ans,(values[i]*values[j]*values[k]+MinScore_triangulation(values,i,k)+MinScore_triangulation(values,k,j)));
  }
  return ans;
}

int MinScore_triangulation_memoization(vector<int> values, int i, int j,vector<vector<int>> dp)
{
  if(i+1==j)
  {
    return 0;
  }
  if(dp[i][j]!=-1)
  {
    return dp[i][j];
  }

  int ans = INT16_MAX;
  for(int k=i+1;k<j;k++)
  {
    ans = min(ans,(values[i]*values[j]*values[k]+MinScore_triangulation_memoization(values,i,k,dp)+MinScore_triangulation_memoization(values,k,j,dp)));
  }
  dp[i][j]=ans;
  return dp[i][j];
}

int MinScore_triangulation_tabulation(vector<int>& values)
{
  int n = values.size();
  vector<vector<int>> dp(n+2,vector<int>(n+2,0));
  
  for(int i=n-1;i>=0;i--)
  {
    for(int j=i+2;j<n;j++)
    {
      int ans = INT16_MAX;
      for(int k=i+1;k<j;k++)
      {
        ans = min(ans,(values[i]*values[j]*values[k]+dp[i][k]+dp[k][j]));
      }
      dp[i][j]=ans;
    }
  }
  return dp[0][n-1];
}

// Gap Strategy 
int MinScore_triangulation_GapStrategy(vector<int>& values)
{
  int n = values.size();
  vector<vector<int>> dp(n,vector<int>(n,0));

  for(int gap=2;gap<n;gap++)
  {
    for(int i=0,j=gap;j<n;i++,j++)
    {
      int ans=INT16_MAX;
      for(int k=i+1;k<j;k++)
      {
        ans = min(ans, values[i]*values[j]*values[k]+dp[i][k]+dp[k][j]);
      }
      dp[i][j]=ans;
    }
  }
  return dp[0][n-1];
}

int main()
{
  vector<int> values={1,3,1,4,1,5};
  int n=values.size();
  vector<vector<int>> dp(n,vector<int>(n,-1));
  // cout<<MinScore_triangulation_GapStrategy(values)<<endl;
  // cout<<MinScore_triangulation(values,0,n-1);
  cout<<Triangulation2(10);
  return 0;
}
