#include<bits/stdc++.h>
using namespace std;

int solve(int cost,vector<int>& coins)
{
  int n=coins.size();
  if(cost==0)
  {
      return 0;
  }
  if(cost<0)
  {
    return INT_MAX;
  }

  int ans=INT_MAX;
  for(int i=0; i<n; i++)
  {
    int p=solve(cost-coins[i],coins);
    if(p!=INT_MAX)
    {
      ans = min(ans,1+p);
    }
    else
    {
      ans = min(ans,p);
    }
  }

  return ans;
}

int solveMem(int cost,vector<int>&coins,vector<int>& dp)
{
  int n=coins.size();
  if(cost==0)
  {
    return 0;
  }
  if(cost<0)
  {
    return INT_MAX;
  }

  if(dp[cost]!=-1)
  {
    return dp[cost];
  }

  int ans=INT_MAX;
  for(int i=0; i<n; i++)
  {
    int p=solve(cost-coins[i],coins);
    if(p!=INT_MAX)
    {
      ans = min(ans,1+p);
    }
    else
    {
      ans = min(ans,p);
    }
  }
  dp[cost]=ans;
  return ans;
}
int solveTab(int cost,vector<int>& coins)
{
  int n=coins.size();
  vector<int> dp(cost+1,INT_MAX);
  dp[0]=0;

  for(int c=1; c<=cost; c++)
  {
    int ans=INT_MAX;
    for(int i=0; i<n; i++)
    {
      if(c-coins[i]>=0)
      {
        int p=dp[c-coins[i]];
        if(p!=INT_MAX)
        {
          ans = min(ans,1+p);
        }
        else
        {
          ans = min(ans,p);
        }
      }
    }
    dp[c]=ans;
  }
  return dp[cost];
}
int minimizeCoin(int cost,vector<int>& coins)
{
  vector<int> dp(cost+1,-1);
  int sub=solveTab(cost,coins);
  if(sub!=INT_MAX)
  {
    return sub;
  }
  return -1;
}

int main()
{
  int n,m;
  cin>>n>>m;

  vector<int> coins(n);
  for(int i=0; i<n; i++)
  {
    cin>>coins[i];
  }

  cout<<minimizeCoin(m,coins)<<endl;

  return 0;
}