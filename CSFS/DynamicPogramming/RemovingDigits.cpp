#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& dp)
{
  if(n==0)
  {
    return 1;
  }
  if(n<0)
  {
    return INT_MAX;
  }

  if(dp[n]!=-1)
  {
    return dp[n];
  }
  string a=to_string(n);
  int m=a.size();
  
  int ans=INT_MAX;
  for(int i=0; i<m; i++)
  {
    int digit=a[i]-'0';
    if(digit==0) continue;
    int p=solve(n-digit,dp);
    if(p!=INT_MAX)
    {
      ans = min(ans, 1+p);
    }
  }

  return dp[n]=ans;
}

int solveTab(int n)
{
  vector<int> dp(n+1,INT_MAX);
  dp[0]=1;

  for(int x=1; x<=n; x++)
  {
    string a=to_string(x);
    int m=a.size();
    
    int ans=INT_MAX;
    for(int i=0; i<m; i++)
    {
      int digit=a[i]-'0';
      if(digit==0) continue;
      if(x-digit>=0) 
      { 
        int p=dp[x-digit];
        ans = min(ans,1+p);
      }
    }

    dp[x]=ans;
  }

  return dp[n];
}

int RemovingDigits(int n)
{
  //vector<int> dp(n+1,-1);
  int ans=solveTab(n);
  
  if(ans!=INT_MAX)
  {
    return ans-1;
  }

  return -1;
}

int main()
{
  int n;
  cin>>n;

  cout<<RemovingDigits(n)<<endl;

  return 0;
}