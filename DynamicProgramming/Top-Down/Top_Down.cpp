#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int reduce_dishes_bruteforce(vector<int>& sorted_array, int i, int Time)
{
  if(i>=sorted_array.size())
  {
    return 0;
  }

  // include
  int include = (sorted_array[i]*Time) + reduce_dishes_bruteforce(sorted_array, i+1,Time+1);
  int exclude = reduce_dishes_bruteforce(sorted_array,i+1,Time);

  return max(include,exclude);
}

//Top down 
int reduce_dishes_memoization(vector<int>& sorted_array, int i, int Time, vector<vector<int>>& dp)
{
  if(i>=sorted_array.size())
  {
    return 0;
  }
  if(dp[i][Time]!=-1)
  {
    return dp[i][Time];
  }

  // include
  int include = (sorted_array[i]*(Time+1)) + reduce_dishes_memoization(sorted_array, i+1,Time+1,dp);
  int exclude = reduce_dishes_memoization(sorted_array,i+1,Time,dp);

  dp[i][Time]=max(include,exclude);
  return dp[i][Time];
}

int reduce_dishes_tabulation(vector<int>& sorted_array)
{
  int n = sorted_array.size();
  vector<vector<int>> dp(n+1,vector<int>(n+1,0));
  
  for(int index=n-1;index>=0;index--)
  {
    for(int time=index;time>=0;time--)
    {
      int include = (sorted_array[index]*(time+1)) + dp[index+1][time+1];
      int exclude = dp[index+1][time];

      dp[index][time]=max(include,exclude);
    }
  }
  return dp[0][0];
}

int reduce_dishes_space_optim(vector<int>& sorted_array)
{
  int n = sorted_array.size();

  vector<int> curr(n+1,0);
  vector<int> next(n+1,0);
  
  for(int index=n-1;index>=0;index--)
  {
    for(int time=index;time>=0;time--)
    {
      int include = (sorted_array[index]*(time+1)) + next[time+1];
      int exclude = next[time];

      curr[time]=max(include,exclude);
    }
    next = curr;
  }
  return next[0] ;
}

int main()
{
  vector<int> satisfaction = {-1,-8,0,5,-9};
  vector<vector<int>> dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
  int Time=0;
  sort(satisfaction.begin(),satisfaction.end());
  cout<<reduce_dishes_memoization(satisfaction,0,Time,dp)<<endl;
  cout<<reduce_dishes_tabulation(satisfaction)<<endl;
  return 0;
}