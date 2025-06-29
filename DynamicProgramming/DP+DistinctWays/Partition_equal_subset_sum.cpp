#include<iostream>
#include<vector>

using namespace std;

bool solve(int n, vector<int>& nums, long long int target, int index, long long int sum)
{
    if(sum == target)
    {
        return true;
    }
    if(index<=n && sum>target)
    {
        return false;
    }
    if(index>=n && sum!=target)
    {
        return false;
    }
    // take
    sum = sum+nums[index];
    bool take = solve(n, nums, target, index+1, sum);
    sum = sum-nums[index];
    //non take
    bool non_take = solve(n, nums, target, index+1, sum);
    
    return (take||non_take);
}
int solve_mem(int n, vector<int>& nums, long long int target, int index, long long int sum,vector<vector<int>>& dp)
{
    if(sum == target)
    {
        return 1;
    }
    if(index<=n && sum>=target)
    {
        return 0;
    }
    if(index>=n && sum!=target)
    {
        return 0;
    }
    if(dp[index][sum]!=-1)
    {
        return dp[index][sum];
    }
    // take
    sum = sum+nums[index];
    int take = solve_mem(n, nums, target, index+1, sum,dp);
    sum = sum-nums[index];
    //non take
    int non_take = solve_mem(n, nums, target, index+1, sum,dp);
    
    dp[index][sum]=(take||non_take);
    return dp[index][sum];
}
int solve_tab(int n, vector<int>& nums, long long int target)
{
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[n][0]=1;
    
    for(int i=n-1; i>=0; i--)
    {
      for(int j=0; j<=target; j++)
      {
        int take=0;
        if(j-nums[i]>=0)
        {
            take = dp[i+1][j-nums[i]];
        } 
        int non_take = dp[i+1][j];
        dp[i][j] = max(take,non_take);  
      }
    }
    return dp[0][target];
}
int solve_optim(int n, vector<int>& nums, long long int target)
{
    vector<int> next(target+1,0);
    vector<int> curr(target+1,0);
    next[0]=1;
    
    for(int i=n-1; i>=0; i--)
    {
      for(int j=0; j<=target; j++)
      {
        int take=0;
        if(j-nums[i]>=0)
        {
            take = next[j-nums[i]];
        } 
        int non_take = next[j];
        curr[j] = max(take,non_take);  
      }
      next = curr;
    }
    return next[target];
}
int main()
{
  vector<int> nums={1,5,11,5};
  int n = nums.size();
  long long int target_sum = 0;
        for(int i=0;i<n;i++)
        {
            target_sum += nums[i];
        }
        if((target_sum%2)==0)
        {   
            //int index = 0;
            //long long int sum=0;
            long long int m=target_sum/2;
            //vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
            cout<<(bool) solve_optim(n,nums,target_sum/2);
        }
        else
        {
            cout<<false;
        }
  return 0;
}