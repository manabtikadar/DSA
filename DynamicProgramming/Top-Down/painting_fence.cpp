#include<iostream>
#include<vector>
using namespace std;

int painting_fence(int n,int k)
{
  if(n==1)
  {
    return k;
  }
  if(n==2)
  {
    return k+k*(k-1);
  }

  int ans = painting_fence(n-1,k)*(k-1)+painting_fence(n-2,k)*(k-1);

  return ans;
}
// Top - Down Approach
int painting_fence_memorization(int n,int k,vector<int>& dp)
{
  if(n==1)
  {
    return k;
  }
  if(n==2)
  {
    return k+k*(k-1);
  }
  if(dp[n]!=-1)
  {
    return dp[n];
  }
  dp[n-1]=painting_fence_memorization(n-1,k,dp);
  dp[n-2]=painting_fence_memorization(n-2,k,dp);

  dp[n] = dp[n-1]*(k-1)+dp[n-2]*(k-1);

  return dp[n];
}

// Bottom-up approach
int painting_fence_tabulation(int n,int k)
{
  vector<int> dp(n+1,0);
  // if(n==1)
  // {
  //   return k;
  // }
  // if(n==2)
  // {
  //   return k+k*(k-1);
  // }
  dp[1] = k;
  dp[2] = k+(k*(k-1));
  
  for(int i=3; i<=n; i++)
  {
    dp[i] = dp[i-1]*(k-1)+dp[i-2]*(k-1);
  }

  return dp[n];
}

int painting_fence_spaceoptim(int n,int k)
{
  int prev1 = k;
  int prev2 = k+(k*(k-1));
  int current;

  for(int i=3; i<=n; i++)
  {
    current = prev1*(k-1)+prev2*(k-1);
    prev1 = prev2;
    prev2 = current;
  }
  
  return current;
}

int main()
{
  int n;
  int k;
  vector<int> dp(n+1, -1);
  cout<<painting_fence_spaceoptim(4,3);
  return 0;
}