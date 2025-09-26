#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int solve(int x,vector<int>& coins)
{
  int n=coins.size();
  if(x==0)
  {
    return 1;
  }

  if(x<0)
  {
    return 0;
  }

  int ans=0;
  for(int i=0; i<n; i++)
  {
    ans = ans + solve(x-coins[i],coins);
  }

  return ans;
}

long long solveMem(int x,vector<int>& coins,vector<long long>& dp)
{
  int n=coins.size();
  if(x==0)
  {
    return 1;
  }

  if(x<0)
  {
    return 0;
  }

  if(dp[x]!=-1)
  {
    return dp[x];
  }

  long long ans=0;
  for(int i=0; i<n; i++)
  {
    ans = ans + (solveMem(x-coins[i],coins,dp)%MOD);
  }

  return dp[x]=(ans%MOD);
}

long long numWaystomakeX(int x,vector<int>& coins)
{
  vector<long long> dp(x+1,-1);
  return solveMem(x,coins,dp)%MOD;
}

int main()
{
  int n;
  cin>>n;
  int x;
  cin>>x;
  vector<int> coins(n);
  for(int i=0; i<n; i++)
  {
    cin>>coins[i];
  }

  cout<<numWaystomakeX(x,coins)<<endl;

  return 0;
}