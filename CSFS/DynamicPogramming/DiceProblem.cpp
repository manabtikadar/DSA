#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long solve(int n, vector<long long>& dp)
{
  if(n<0)
  {
    return 0;
  }
  if(n==0)
  {
    return 1;
  }
  if(dp[n]!=-1)
  {
    return dp[n];
  }
  long long ans=0;
  for(int i=1; i<=6; i++)
  {
    ans += solve(n-i, dp)%MOD;
  }
  dp[n]=ans%MOD;
  return (ans%MOD);
}
long long solveTab(int n)
{
  vector<long long> dp(n+1);
  dp[0]=1;

  for(int k=1; k<=n; k++)
  {
    long long ans=0;
    for (int i = 1; i <= 6; i++)   // only dice faces 1..6
    {
        if (k - i >= 0)
            ans = (ans + dp[k - i]) % MOD;
    }
    dp[k]=ans%MOD;
  }

  return dp[n]%MOD;
}
int numWays(int n)
{
  //vector<long long> dp(n+1,-1);
  return solveTab(n);
}

int main()
{
  int n;
  cin>>n;

  cout<<numWays(n)<<endl;

  return 0;
}