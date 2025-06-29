#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int solve_mem(int index , int diff, vector<int>& nums, unordered_map<int,int> dp[])
{
    // backward check--> the base case is not needed
    if(index<0)
    {
        return 0;
    }
    if(dp[index].count(diff))
    {
        return dp[index][diff];
    }
    int ans=0;
    for(int k=index-1; k>=0; k--)
    {
      if((nums[index]-nums[k])==diff)
      {
        ans = max(ans, 1+solve(k,diff,nums,dp));
      }
    }
    return dp[index][diff]=ans;
}
int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    if(n<=2)
    {
        return n;
    }
    int ans=0;
    unordered_map<int,int> dp[n+1];
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
          ans = max(ans,2 + solve(i,nums[j]-nums[i],nums, dp));
        }
    }
    return ans;
}

int longestArithSeqLength_Tab(vector<int>& nums) {
    int n = nums.size();
    if(n<=2)
    {
        return n;
    }
    int ans = 0;
    unordered_map<int,int> dp[n+1];

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
          int diff = nums[i]-nums[j];
          int count=1; 

          //check if answer already present
          if(dp[j].count(diff))
          {
            count = dp[j][diff];
          }
          dp[i][diff] = 1+count;
          ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}

int main()
{
  vector<int> nums = {1,7,10,13,14,19};
  cout<<longestArithSeqLength(nums);
  return 0;
}