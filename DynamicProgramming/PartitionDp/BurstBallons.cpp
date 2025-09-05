#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int solve(int i, int j, vector<int>& nums)
    {
      if(j<i) return 0;
      int total_coins=INT_MIN;
      for(int k=i; k<=j; k++)
      {
        total_coins=max(total_coins,(nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums)+solve(k+1,j,nums)));
      }
      return total_coins;
    }
    int solveMem(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
    {
      if(j<i) return 0;
      if(dp[i][j]!=-1)
      {
        return dp[i][j];
      }
      int total_coins=INT_MIN;
      for(int k=i; k<=j; k++)
      {
        total_coins=max(total_coins,(nums[i-1]*nums[k]*nums[j+1]+solveMem(i,k-1,nums,dp)+solveMem(k+1,j,nums,dp)));
      }
      return dp[i][j]=total_coins;
    }
    int solveTab(vector<int>& nums)
    {
      int n=nums.size();
      vector<vector<int>> dp(n,vector<int>(n,0));

      for(int i=n-2; i>=1; i--)
      {
        for(int j=i; j<=n-2; j++)
        {
          int total_coins=INT_MIN;
          for(int k=i; k<=j; k++)
          {
            total_coins=max(total_coins,(nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]));
          }
          dp[i][j]=total_coins;
        }
      }

      return dp[1][n-2];
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);

        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        //vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solveMem(1,n-2,nums,dp);
        return solveTab(nums);
    }
};

int main()
{
  int n;
  cout<<"Enter the size of array:"<<endl;
  cin>>n;

  vector<int> nums(n,0);
  cout<<"Enter the elements of array:"<<endl;
  for(int i=0; i<n; i++)
  {
    cin>>nums[i];
  }

  Solution obj;
  int ans = obj.maxCoins(nums);
  cout<<"Maximum coins that can be collected is: "<<ans<<endl;

  return 0;
}