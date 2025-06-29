#include<bits/stdc++.h>

using namespace std;

int solve(int n)
{
  if(n<=1)
  {
    return 1;
  }
  if(n==2)
  {
    return 2;
  }
  int ans = 0;
  for(int i=1; i<=n; i++)
  {
    int left = solve(i-1);
    int right = solve(n-i);
    ans += left*right;
  }
  return ans;
}
int solve_mem(int n, vector<int>& dp)
{
  if(n<=1)
  {
    return 1;
  }
  if(n==2)
  {
    return 2;
  }
  if(dp[n]!=-1)
  {
    return dp[n];
  }
  int ans = 0;
  for(int i=1; i<=n; i++)
  {
    int left = solve_mem(i-1,dp);
    int right = solve_mem(n-i,dp);
    ans += left*right;
  }
  dp[n]=ans;
  return dp[n];
}
int solve_tab(int n)
{
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;

    for(int k=2; k<=n; k++)
    {   
        for(int i=1; i<=k; i++)
        {
            int left = dp[i-1];
            int right = dp[k-i];
            dp[k] += left*right;
        }
    }
    return dp[n];
}
int main()
{
  cout<<solve_tab(5);
  return 0;
}