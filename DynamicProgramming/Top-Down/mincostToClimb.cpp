#include<iostream>
#include<vector>
using namespace std;

// Top-Down Approach
int calculatecost(vector<int>& cost,int n,vector<int>& dp)
{
  if(n<=1)
  {
    return cost[n];
  }
  if(dp[n]!=-1)
  {
    return dp[n];
  }
  dp[n]= cost[n]+min(calculatecost(cost,n-1,dp),calculatecost(cost, n-2, dp));

  return dp[n];
}
// Bottom-Up approach
int calculatecost_tabulation(vector<int>& cost,int n)
{
  int dp[n+1];
  dp[0]=cost[0];
  dp[1]=cost[1];
  for(int i=2;i<n;i++)
  {
    dp[i] = cost[i]+min(dp[i-1],dp[i-2]);
  }
  dp[n]= min(dp[n-1],dp[n-2]);

  return dp[n];
}

int calculatecost_spaceComplexity(vector<int>& cost,int n)
{
  int prev2=cost[0];
  int prev1=cost[1];
  for(int i=2;i<n;i++)
  {
   int current = cost[i]+min(prev1,prev2);
   prev2=prev1;
   prev1=current;
  }
  int ans = min(prev1,prev2);

  return ans;
}
int main()
{
  vector<int> costarray={10,15,4};
  int nstairs= costarray.size();
  // vector<int> dp(nstairs,-1);
  // int ans=min(calculatecost(costarray, nstairs-1,dp),calculatecost(costarray,nstairs-2,dp));

  cout<<calculatecost_spaceComplexity(costarray,nstairs);
  return 0;
}