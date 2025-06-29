#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int min_squre(int num)
{
  int sqrt_num = sqrt(num);
 
  int min_val = num;
  if(num==0)
  {
    return 0;
  }
  // if(num<=0)
  // {
  //   return INT16_MAX;
  // }
  
  int nearest_perfect_sqrt = sqrt_num;  
  for(int i=1;i<=nearest_perfect_sqrt;i++)
  {
    int result = 1+min_squre(num-i*i);
    min_val = min(min_val,result);
  }
  return min_val;
}

int min_squre_memoization(int num, vector<int>& dp)
{
  int sqrt_num = sqrt(num);
 
  int min_val = INT16_MAX;
  if(num==0)
  {
    return 0;
  }
  if(num<=0)
  {
    return INT16_MAX;
  }
  if(dp[num]!=-1)
  {
    return dp[num];
  }
  
  int nearest_perfect_sqrt = sqrt_num;
  for(int i=1;i<=nearest_perfect_sqrt;i++)
  {
    int result = min_squre_memoization(num-i*i,dp);
    min_val = min(min_val,result+1);
  }
  dp[num]=min_val;
  return dp[num];
}

int min_squre_tabulation(int num)
{
  vector<int> dp(num+1,INT16_MAX);

  dp[0]=0;

  for(int j=1;j<=num;j++)
  {
    // int sqrt_num = sqrt(j);
    // if(sqrt_num != 1)
    // {
    //   dp[j]=min((dp[j-1]+1),(dp[j-(sqrt_num*sqrt_num)]+1));
    // }
    // else
    // {
    //   dp[j]=dp[j-1]+1;
    // }
    int sqrt_num = sqrt(j);
    // int min_val = INT16_MAX;
    for(int i=1;i<=sqrt_num;i++)
    {
      int result = dp[j-i*i];
      dp[j] = min(dp[j],result+1);
    }
    // dp[j]=min_val;
  }
  return dp[num];
}

int main()
{
  int num = 25;
  vector<int> dp(num+1,-1);
  cout<<min_squre(num)<<endl;
  // int sqrt_num = sqrt(2);
  // cout<<sqrt_num;
  return 0;
}

