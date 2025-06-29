#include<iostream>
#include<vector>

using namespace std;
int solve(int n, vector<int> array, int curr, int prev)
{
  //Base Case
  if(curr==n)
  {
    return 0;
  }

  //include
  int include=0;
  if(prev==-1||array[curr]>array[prev])
  {
    include = 1 + solve(n,array,curr+1,curr);
  }

  int exclude = solve(n,array,curr+1,prev);

  return max(include,exclude);
}

int solveMem(int n, vector<int> array, int curr, int prev, vector<vector<int>>& dp)
{
  //Base Case
  if(curr==n)
  {
    return 0;
  }
  if(dp[curr][prev+1]!=-1)
  {
    return dp[curr][prev+1];
  }

  //include
  int include=0;
  if(prev==-1||array[curr]>array[prev])
  {
    include = 1 + solveMem(n,array,curr+1,curr,dp);
  }

  int exclude = solveMem(n,array,curr+1,prev,dp);

  dp[curr][prev+1]=max(include,exclude);
  return dp[curr][prev+1];
}
// Bottom Up solution
int solveTab(int n, vector<int> array)
{
  vector<vector<int>> dp(n+1, vector<int> (n+1,0));
  for(int curr=n-1 ; curr>=0; curr--)
  {
    for(int prev=curr-1;prev>=-1;prev--)
    {
      int include=0;
      if(prev==-1||array[curr]>array[prev])
      {
        include = 1 + dp[curr+1][curr+1];
      }

      int exclude = dp[curr+1][prev+1];

      dp[curr][prev+1]=max(include,exclude);
    }
  }
  return dp[0][0];
}

int solveTab_spaceoptim(int n,vector<int> array)
{
  vector<int> current(n+1,0);
  vector<int> next(n+1,0);
  for(int curr=n-1 ; curr>=0; curr--)
  {
    for(int prev=curr-1;prev>=-1;prev--)
    {
      int include=0;
      if(prev==-1||array[curr]>array[prev])
      {
        include = 1 + next[curr+1];
      }

      int exclude = next[prev+1];

      current[prev+1]=max(include,exclude);
    }
    next = current;
  }
  return next[0];
}

int main()
{
  vector<int> array= {3,25,5,4,6,2};
  int n = array.size();
  vector<vector<int>> dp(n, vector<int> (n+1,-1));
  cout<<solveTab(n,array)<<endl;
  cout<<solveTab_spaceoptim(n,array);
  return 0;
}