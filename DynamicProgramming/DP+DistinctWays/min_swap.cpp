#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int>& nums1 ,vector<int>& nums2, int index, bool swapped)
{
    if(index>=nums1.size())
    {
        return 0;
    }

    int ans=INT32_MAX;
    
    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    if(swapped)
    {
        swap(prev1, prev2);
    }

    //noswap
    if(nums1[index]>prev1 && nums2[index]>prev2)
    {
        ans = min(ans , solve(nums1,nums2,index+1,0));
    }

    //swap
    if(nums1[index]>prev2 && nums2[index]>prev1)
    {
        ans = min(ans ,1+solve(nums1, nums2, index+1,1));
    }
    return ans;
}
int solve_mem(vector<int>& nums1 ,vector<int>& nums2, int index, bool swapped, vector<vector<int>>& dp)
{
    if(index>=nums1.size())
    {
        return 0;
    }

    int ans=INT32_MAX;
    
    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    if(swapped)
    {
        swap(prev1, prev2);
    }

    if(dp[index][swapped]!=-1)
    {
        return dp[index][swapped];
    }

    //noswap
    if(nums1[index]>prev1 && nums2[index]>prev2)
    {
        ans = min(ans , solve_mem(nums1,nums2,index+1,0,dp));
    }

    //swap
    if(nums1[index]>prev2 && nums2[index]>prev1)
    {
        ans = min(ans ,1+solve_mem(nums1, nums2, index+1,1,dp));
    }
    dp[index][swapped]=ans;
    return dp[index][swapped];
}
int solve_Tab(vector<int>& nums1 ,vector<int>& nums2)
{
    int n = nums1.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int index=n-1; index>=1; index--)
    {   
      for(int swapped=1; swapped>=0; swapped--)
      {
        int ans = INT32_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        if(swapped)
        {
          swap(prev1, prev2);
        }
        //noswap
        if(nums1[index]>prev1 && nums2[index]>prev2)
        {
            ans = min(ans , dp[index+1][0]);
        }

        //swap
        if(nums1[index]>prev2 && nums2[index]>prev1)
        {
            ans = min(ans ,1+dp[index+1][1]);
        }

        dp[index][swapped]=ans;
      }
    }
    return dp[1][0];
}
int solve_optim(vector<int>& nums1 ,vector<int>& nums2)
{
    int n = nums1.size();
    //vector<vector<int>> dp(n+1,vector<int>(2,0));
    vector<int> next(2,0);
    vector<int> curr(2,0);
    for(int index=n-1; index>=1; index--)
    {   
      for(int swapped=1; swapped>=0; swapped--)
      {
        int ans = INT32_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        if(swapped)
        {
          swap(prev1, prev2);
        }
        //noswap
        if(nums1[index]>prev1 && nums2[index]>prev2)
        {
            ans = min(ans , next[0]);
        }

        //swap
        if(nums1[index]>prev2 && nums2[index]>prev1)
        {
            ans = min(ans ,1+next[1]);
        }

        curr[swapped]=ans;
      }
      next=curr;
    }
    return next[0];
}
int solve_optim2(vector<int>& nums1 ,vector<int>& nums2)
{
    int n = nums1.size();
    int swap_=0;
    int noswap=0;
    int currswap=0;
    int currnoswap=0;
    for(int index=n-1; index>=1; index--)
    {   
      for(int swapped=1; swapped>=0; swapped--)
      {
        int ans = INT32_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        if(swapped)
        {
            swap(prev1, prev2);
        }
        //noswap
        if(nums1[index]>prev1 && nums2[index]>prev2)
        {
            ans = min(ans , noswap);
        }

        //swap
        if(nums1[index]>prev2 && nums2[index]>prev1)
        {
            ans = min(ans ,1+swap_);
        }

        if(swapped)
        {
          currswap = ans;
        }
        else
        {
            currnoswap = ans;
        }
        
      }
      swap_ = currswap;
      noswap = currnoswap;
    }
    return noswap;
}
int main()
{
  vector<int> nums1={1,3,5,4};
  vector<int> nums2={1,2,3,7};
  bool swapped = 0; // it means that the previous index numbers are swapped or not
  nums1.insert(nums1.begin()+0,-1);
  nums2.insert(nums2.begin()+0,-1);
  
  int n=nums1.size();
  vector<vector<int>> dp(n,vector<int>(2,-1));
  cout<<solve_optim2(nums1, nums2);
  return 0;
}