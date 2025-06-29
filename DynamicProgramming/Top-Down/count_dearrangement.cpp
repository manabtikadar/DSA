#include<iostream>
#include<vector>
using namespace std;

int count_dearrangement(int n)
{
  //Base Case
  if(n==1)
    return 0;
  if(n==2)
    return 1;
    
  int ans = (n-1)*(count_dearrangement(n-2)+count_dearrangement(n-1));
  return ans;  
}

//Top-Down Approach/ Recursion+Memorization
int count_dearrangement_memorization(int n, vector<int>& dp)
{
  //Base case
  if(n==1)
  {
    return 0;
  }
  if(n==2)
  {
    return 1;
  }

  if(dp[n]!=-1)
  {
    return dp[n];
  }
  
  dp[n]=(n-1)*(count_dearrangement_memorization(n-1,dp)+count_dearrangement_memorization(n-2,dp));

  return dp[n];
}
// Bottom-Up approach/ tabulation
int count_dearrangement_tabulation(int n)
{
  vector<int> dp(n+1,0);
  dp[1]=0;
  dp[2]=1;

  for(int i=3;i<=n;i++)
  {
    dp[i]=(i-1)*(dp[i-2]+dp[i-1]);
  }
  return dp[n];
}
// Space Optimization
int count_dearrangement_spaceoptim(int n)
{
  int prev2 = 0;//n=1
  int prev1 = 1;//n=2
  int current;

  for(int i=3;i<=n;i++)
  {
    current = (i-1)*(prev2+prev1);
    prev2=prev1;
    prev1=current;
  }
  
  return prev1;
}

int main()
{
  int N=4;
  vector<int> dp(N+1,-1);
  cout<<count_dearrangement_spaceoptim(N);
  return 0;
}